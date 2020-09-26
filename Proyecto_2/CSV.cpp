#include "CSV.h"
#include <fstream>
#include <iostream>
#include "rapidcsv.h"
#include <cstring>
#include <stdio.h>
#include "crc.h"



namespace CSV = rapidcsv;


std::ifstream archivo("WHO-COVID-19-global-data.csv"); 
CSV::Document doc(archivo);

void OperacionesCSV::convert(){
    std::ofstream fileWHO("WHO.bin", std::ios::out | std::ios::binary); 
    size_t index = 0;

    WHO w;
    std::string date;
    std::string Code;
    std::string Country;
    std::string region;

    w.setSignature("ESTR");
    w.setName("Estructura de Datos II");
    w.size = 0xdeadbeef;
    w.crc = CRC::Calculate(reinterpret_cast<char*>(&w), sizeof(WHO) - sizeof(uint32_t), CRC::CRC_32());

    for(int i = 0; i < doc.GetRowCount(); i++){
           
                //std::cout << doc.GetCell<std::string>(j, i) << " ";


                date = doc.GetCell<std::string>(0, index);
                const char* ConvDate = date.c_str();
                std::strcpy(w.Date_Reported, ConvDate);

                Code = doc.GetCell<std::string>(1, index);
                const char* ConvCode = Code.c_str();
                std::strcpy(w.Country_Code, ConvCode);

                Country = doc.GetCell<std::string>(2, index);
                const char* ConvCountry = Country.c_str();
                std::strcpy(w.Country, ConvCountry);

                region = doc.GetCell<std::string>(3, index);
                const char* ConvRegion = region.c_str();
                std::strcpy(w.WHO_region, ConvRegion);

              //std::memcpy(w.Date_Reported, date, sizeof(w.Date_Reported)*sizeof(date));
    

                w.New_cases = doc.GetCell<double>(4, index);
                w.Cumulative_cases = doc.GetCell<double>(5, index);
                w.New_deaths = doc.GetCell<double>(6, index);
                w.Cumulative_deaths = doc.GetCell<double>(7, index);

            fileWHO.write(reinterpret_cast<const char*>(&w), sizeof(WHO));
            index++;
    }
    std::cout << "ARCHIVO CREADO EXITOSAMENTE!!!" << std::endl;
    fileWHO.close();
    
}

void OperacionesCSV::display(std::string file){

    std::ifstream inFile;
    inFile.open(file, std::ios::binary | std::ios::in);

    WHO obj;
    inFile.seekg(0, std::ios::beg);
    
    while(inFile.read(reinterpret_cast<char *>(&obj), sizeof(WHO)))
    {
        std::cout << obj.Date_Reported << " "
        << obj.Country_Code << " "
        << obj.Country << " "
        << obj.WHO_region << " "
        << obj.New_cases << " "
        << obj.Cumulative_cases << " "
        << obj.New_deaths << " "
        << obj.Cumulative_deaths << " "
        << std::endl;
    }        
    
    inFile.close();
}

void OperacionesCSV::graph(std::vector<double> xs, const char* name ,int cantidad){
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();

	vector<double> ys;

     for (double i = 0; i < xs.size(); i++)
    {
        ys.push_back(i + cantidad);
    }
    

	DrawScatterPlot(imageReference, 1000, 800, &ys, &xs);

	vector<double> *pngdata = ConvertToPNG(imageReference->image);
	WriteToFile(pngdata, name);
	DeleteImage(imageReference->image);
}

