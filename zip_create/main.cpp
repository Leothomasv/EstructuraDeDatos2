#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include "zip.h"


ZIP z;


int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        std::cerr << "Usage: " << argv[0] << " <input file 1>  <input file 2>  <input file 3>  <zip file>\n";
        return 1;
    }


    // argv[1] -> input file
    // argv[2] -> input file
    // argv[3] -> input file

    // argv[4] -> output zip file

    //primer archivo
	z.leerArchivo(argv[1]);
	z.LocalHeader();

    //segundo archivo
    z.leerArchivo(argv[2]);
	z.LocalHeader();

    //tercero archivo
    z.leerArchivo(argv[3]);
	z.LocalHeader();


 


}
