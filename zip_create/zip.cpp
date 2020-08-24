#include "zip.h"
#include <iostream>

ZIP::ZIP(){}

void ZIP::leerArchivo(std::string filename)
{
	ZipFile.open(filename, std::ifstream::in | std::ifstream::binary);
}


int ZIP::checkSignature() {
	uint8_t pos = 0;

	while (1) {
		ZipFile.read(reinterpret_cast<char*> (&pos), 1);
		if (pos == 80) {
			ZipFile.read(reinterpret_cast<char*> (&pos), 1);
			if (pos == 75) {
				ZipFile.read(reinterpret_cast<char*> (&pos), 1);
				if (pos == 3||pos==1||pos==5||pos==7) {
					ZipFile.read(reinterpret_cast<char*> (&pos), 1);
					if (pos == 4||pos==2||pos==6|| pos==8) {
						
						return pos;
					}
				}

			}

		}
	}
}

void ZIP::LocalHeader(){

    ZipFile.read(reinterpret_cast<char*>(&local.signature), 4);
		uint32_t sig = 67324752;
		while (local.signature == sig) {
			ZipFile.read(reinterpret_cast<char*>(&local.version), 2);
			ZipFile.read(reinterpret_cast<char*>(&local.flags), 2);
			ZipFile.read(reinterpret_cast<char*>(&local.comp_method), 2);
			ZipFile.read(reinterpret_cast<char*>(&local.mtime), 2);
			ZipFile.read(reinterpret_cast<char*>(&local.mdate), 2);
			ZipFile.read(reinterpret_cast<char*>(&local.crc32), 4);
			ZipFile.read(reinterpret_cast<char*>(&local.comp_file_size), 4);
			ZipFile.read(reinterpret_cast<char*>(&local.orig_file_size), 4);
			ZipFile.read(reinterpret_cast<char*>(&local.name_len), 2);


            int pos = ZipFile.tellg();
            //siguiente
            ZipFile.seekg(pos - 4, std::ios::beg);
				ZipFile.read(reinterpret_cast<char*>(&local.signature), 4);
				if (local.signature == 33639248) {//0x04034b50
					CentralD();
					return;
				}

        }

}

void ZIP::CentralD(){
    int pos = ZipFile.tellg();
	ZipFile.seekg(pos-4, std::ios::beg);
		ZipFile.read(reinterpret_cast<char*>(&central.signature), 4);
		uint32_t sig = 33639248;

        while(central.signature == sig){
            ZipFile.read(reinterpret_cast<char*>(&central.version_made), 2);
            ZipFile.read(reinterpret_cast<char*>(&central.version_extract), 2);
            ZipFile.read(reinterpret_cast<char*>(&central.flags), 2);
            ZipFile.read(reinterpret_cast<char*>(&central.comp_method), 2);
            ZipFile.read(reinterpret_cast<char*>(&central.mtime), 2);
            ZipFile.read(reinterpret_cast<char*>(&central.mdate), 2);
            ZipFile.read(reinterpret_cast<char*>(&central.crc32), 4);
            ZipFile.read(reinterpret_cast<char*>(&central.comp_file_size), 4);
            ZipFile.read(reinterpret_cast<char*>(&central.orig_file_size), 4);
            ZipFile.read(reinterpret_cast<char*>(&central.name_len), 2);
            ZipFile.read(reinterpret_cast<char*>(&central.extra_len), 2);
            ZipFile.read(reinterpret_cast<char*>(&central.file_comment_len), 2);
            ZipFile.read(reinterpret_cast<char*>(&central.disk_number), 2);
            ZipFile.read(reinterpret_cast<char*>(&central.file_attrs1), 2);
            ZipFile.read(reinterpret_cast<char*>(&central.file_attrs2), 4);
            ZipFile.read(reinterpret_cast<char*>(&central.file_offset), 4);

                checkSignature();
            int posA = ZipFile.tellg();
            ZipFile.seekg(posA - 4, std::ios::beg);
            ZipFile.read(reinterpret_cast<char*>(&central.signature), 4);
            
            if (central.signature == 101010256) {
                EndCentralDirectory();
            }
        }
}


void ZIP::EndCentralDirectory(){
    int pos = ZipFile.tellg();
	ZipFile.seekg(pos - 4, std::ios::beg);
	ZipFile.read(reinterpret_cast<char*>(&End.signature), 4);
	ZipFile.read(reinterpret_cast<char*>(&End.disk_number), 2);
	ZipFile.read(reinterpret_cast<char*>(&End.disk_start), 2);
	ZipFile.read(reinterpret_cast<char*>(&End.cd_records1), 2);
	ZipFile.read(reinterpret_cast<char*>(&End.cd_records2), 2);
	ZipFile.read(reinterpret_cast<char*>(&End.size_of_cd), 4);
	ZipFile.read(reinterpret_cast<char*>(&End.offset_of_cd), 4);
}



///nuevoooo
int ZIP::ExtratTam(char* n){
	std::ifstream file;

	file.open((char*)n, std::ifstream::in | std::ifstream::binary);
	file.seekg(0,std::ios::end);

	std::cout << file.tellg() << std::endl;
	int tamano = file.tellg();
	file.close();
	return tamano;
}


void ZIP::CreaZIP(char* nm){



}

void ZIP::LeerArch( char* m,char* nm){
	int tamano = ExtratTam(m);
	char * buffer =  new char[tamano];
	std::ifstream arch;
    arch.open((char*)m, std::ifstream::in | std::ifstream::binary);
	arch.read(buffer,tamano);
	std::cout << buffer << std::endl;

//
  std::ofstream ArchivoZIp(nm);
  ArchivoZIp.write ((char*)0x04034b50,4);
 ArchivoZIp.write ((char*)0x14,2);
 ArchivoZIp.write ((char*)makeTime(5,5,5),2);
 ArchivoZIp.write ((char*)makeDate(5,5,5),2);
  ArchivoZIp.write ((char*)tamano,4);
  ArchivoZIp.write ((char*)tamano,4);
  ArchivoZIp.write ((char*)strlen(m),2);

//central directory
ArchivoZIp.write ((char*)0x02014b50,4);
 ArchivoZIp.write ((char*)0x14,2);
 ArchivoZIp.write ((char*)0x14,2);
 ArchivoZIp.write ((char*)makeTime(5,5,5),2);
 ArchivoZIp.write ((char*)makeDate(5,5,5),2);
  ArchivoZIp.write ((char*)tamano,4);
  ArchivoZIp.write ((char*)tamano,4);
  ArchivoZIp.write ((char*)strlen(m),2);

  //end of central directory
  ArchivoZIp.write ((char*)0x06054b50,4);
  ArchivoZIp.write ((char*) 3,2);
  ArchivoZIp.write ((char*) 3,2);

}
