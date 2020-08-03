#include <iostream>
#include <fstream>


struct BMPFileHeader
{
  char id[2];
   uint32_t BmpSize;
	uint16_t Reservado1;
   uint16_t Reservado2;
	uint32_t offset;
	uint32_t Tamano_Header;
	uint32_t width;     
	uint32_t height;    
}__attribute__((packed));

int main(int argc, char *argv[])
{
    if(argc !=2 ){
      std::cerr << "Usage: "<< argv[0]<< "<input file>\n";
      return 1;
    }


    std::ifstream in(argv[1]); 

    //verificar si la operacion de tuvo extio

    if(!in.is_open()){
      std::cerr<<"Cannot open file " << argv[1] <<"\n";
      return 2;

    }
    
    BMPFileHeader bmphf;

    in.read(reinterpret_cast<char*>(&bmphf), sizeof (BMPFileHeader));

  
    if(bmphf.id[0] == 'B' && bmphf.id[1] == 'M'){
      std::cout << "Valid BMP" << std::endl;
      std::cout << "Size: " << bmphf.BmpSize << "\n";
      std::cout << "Offset: "<< bmphf.offset << "\n";
      std::cout << "Size: " << bmphf.Tamano_Header << "\n";
      std::cout << "Width: " << bmphf.width << "\n";
      std::cout << "Height: " << bmphf.height << "\n";
    }else{
      std::cout << "Invalid BMP" << std::endl;
    }

    in.close();

    return 0;
}