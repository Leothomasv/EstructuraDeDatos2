#include <iostream>
#include <fstream>
#include "bmp.h"






int main(int argc, char *argv[])
{

 if(argc !=2 ){
      std::cerr << "Usage: "<< argv[0]<< "<input file>\n";
      return 1;
    }

    std::ifstream Bmp1(argv[1]);
    std::ifstream Bmp2(argv[2]);

    

    if(!Bmp1.is_open()){
      std::cerr<<"Cannot open file " << argv[1] <<"\n";
      return 2;
    }

    if(!Bmp2.is_open()){
      std::cerr<<"Cannot open file " << argv[2] <<"\n";
      return 2;
    }
    
    //Convertir 8 bit a 24 bit
    BitmapFileHeader BmpHf;
    Bmp1.read(reinterpret_cast<char*>(&BmpHf), sizeof (BitmapFileHeader));

    Bmp2.open(argv[2], std::fstream::out);
    












    //BMP de salida
    Bmp2.read(reinterpret_cast<char*>(&BmpHf), sizeof (BitmapFileHeader));

    if(BmpHf.id[0] == 'B' && BmpHf.id[1] == 'M'){
      std::cout << "Valid BMP" << std::endl;
      std::cout << "File Size: " << BmpHf.file_size << "\n";
      std::cout << "Offset: "<< BmpHf.offset << "\n";
      std::cout << "Size: " << BmpHf.header_size << "\n";
      std::cout << "Width: " << BmpHf.bmp_width << "\n";
      std::cout << "Height: " << BmpHf.bmp_height << "\n";
      std::cout << "Planes: " << BmpHf.bmp_planes << "\n";
      std::cout << "Bits: " << BmpHf.bmp_bpp << "\n";
      std::cout << "Compresion: " << BmpHf.bmp_comp << "\n";
      std::cout << "Image Size: " << BmpHf.bmp_img_size << "\n";
      std::cout << "Horizontal Resolution: " << BmpHf.bmp_horiz_res << "\n";
      std::cout << "Vertical Resolution: " << BmpHf.bmp_vert_res << "\n";
      std::cout << "Color Pallete: " << BmpHf.bmp_pal_colors << "\n";
      std::cout << "Important Colors: " << BmpHf.bmp_imp_colors << "\n";
      std::cout << "Extra: " << BmpHf.extra << "\n";
    }else{
      std::cout << "Invalid BMP" << std::endl;
    }




    return 0;
}
