#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <string.h>
#include "rapidcsv.h"
#include "CSV.h"

namespace CSV = rapidcsv;

int main(int argc, char *argv[])
{

    if (argc == 1)
    {
        std::cerr << "Usage: " << argv[0] << " <function>\n";
        std::cout << "<function> convert" << std::endl;
        std::cout << "<function> find " << std::endl;
        return 1;
    }

    OperacionesCSV ope;

    char opcion[12];
    strcpy(opcion, argv[1]);

    //convertir el archivo a binario
    if (strcmp(opcion, "convert") == 0)
    {
        ope.convert();
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //IF MAYOR CONTIENE
    if (strcmp(opcion, "find") == 0)
    {
        std::ifstream inFile;
        inFile.open("WHO.bin", std::ios::in | std::ios::binary);

        WHO obj;
        inFile.seekg(0, std::ios::beg);

        //copiar argumento pais
        char pais[50];
        strcpy(pais, argv[2]);

        inFile.read(reinterpret_cast<char *>(&obj), sizeof(WHO));

        if (argc == 3)
        {

            while (!inFile.eof())
            {
                //Busqueda por pais //PRINCIPAL
                if (strcmp(obj.Country, pais) == 0)
                {
                    std::cout << obj.Date_Reported << " ";
                    std::cout << obj.Country_Code << " ";
                    std::cout << obj.Country << " ";
                    std::cout << obj.WHO_region << " ";
                    std::cout << obj.New_cases << " ";
                    std::cout << obj.Cumulative_cases << " ";
                    std::cout << obj.New_deaths << " ";
                    std::cout << obj.Cumulative_deaths << std::endl;
                }
                inFile.read(reinterpret_cast<char *>(&obj), sizeof(WHO));
            }
            return 0;
        }
        else if (argc == 6)
        {
            char NumericType[30];
            strcpy(NumericType, argv[3]);

            char MasMenos[7];
            strcpy(MasMenos, argv[4]);

            double cantidad;
            cantidad = std::stoi(argv[5]);

            //VECTORES PARA LA GRAPH
            std::vector<double> xs;

            while (!inFile.eof())
            {
                //Busqueda por pais y por dato numerico //NEW_CASES
                if (strcmp(obj.Country, pais) == 0 && strcmp(NumericType, "New_Cases") == 0 && strcmp(MasMenos, "mayor") == 0 && obj.New_cases > cantidad)
                {
                    std::cout << obj.Date_Reported << " ";
                    std::cout << obj.Country_Code << " ";
                    std::cout << obj.Country << " ";
                    std::cout << "New Cases: " << obj.New_cases << " ";
                    std::cout << std::endl;

                    xs.push_back(obj.New_cases);
                }
                else if (strcmp(obj.Country, pais) == 0 && strcmp(NumericType, "New_Cases") == 0 && strcmp(MasMenos, "menor") == 0 && obj.New_cases < cantidad)
                {
                    std::cout << obj.Date_Reported << " ";
                    std::cout << obj.Country_Code << " ";
                    std::cout << obj.Country << " ";
                    std::cout << "New Cases: " << obj.New_cases << " ";
                    std::cout << std::endl;
                    xs.push_back(obj.New_cases);
                }
                else if (strcmp(obj.Country, pais) == 0 && strcmp(NumericType, "New_Cases") == 0 && strcmp(MasMenos, "igual") == 0 && obj.New_cases == cantidad)
                {
                    std::cout << obj.Date_Reported << " ";
                    std::cout << obj.Country_Code << " ";
                    std::cout << obj.Country << " ";
                    std::cout << "New Cases: " << obj.New_cases << " ";
                    std::cout << std::endl;
                    xs.push_back(obj.New_cases);
                }

                //Busqueda por pais y por dato numerico //CUMULATIVE_CASES
                if (strcmp(obj.Country, pais) == 0 && strcmp(NumericType, "Cumulative_Cases") == 0 && strcmp(MasMenos, "mayor") == 0 && obj.Cumulative_cases > cantidad)
                {
                    std::cout << obj.Date_Reported << " ";
                    std::cout << obj.Country_Code << " ";
                    std::cout << obj.Country << " ";
                    std::cout << "Cumulative Cases: " << obj.Cumulative_cases << " ";
                    std::cout << std::endl;
                    xs.push_back(obj.Cumulative_cases);
                }
                else if (strcmp(obj.Country, pais) == 0 && strcmp(NumericType, "Cumulative_Cases") == 0 && strcmp(MasMenos, "menor") == 0 && obj.Cumulative_cases < cantidad)
                {
                    std::cout << obj.Date_Reported << " ";
                    std::cout << obj.Country_Code << " ";
                    std::cout << obj.Country << " ";
                    std::cout << "Cumulative Cases: " << obj.Cumulative_cases << " ";
                    std::cout << std::endl;
                    xs.push_back(obj.Cumulative_cases);

                }
                else if (strcmp(obj.Country, pais) == 0 && strcmp(NumericType, "Cumulative_Cases") == 0 && strcmp(MasMenos, "igual") == 0 && obj.Cumulative_cases == cantidad)
                {
                    std::cout << obj.Date_Reported << " ";
                    std::cout << obj.Country_Code << " ";
                    std::cout << obj.Country << " ";
                    std::cout << "Cumulative Cases: " << obj.Cumulative_cases << " ";
                    std::cout << std::endl;
                    xs.push_back(obj.Cumulative_cases);

                }

                //Busqueda por pais y por dato numerico //NEW_DEATHS
                if (strcmp(obj.Country, pais) == 0 && strcmp(NumericType, "New_Deaths") == 0 && strcmp(MasMenos, "mayor") == 0 && obj.New_deaths > cantidad)
                {
                    std::cout << obj.Date_Reported << " ";
                    std::cout << obj.Country_Code << " ";
                    std::cout << obj.Country << " ";
                    std::cout << "New Deaths: " << obj.New_deaths << " ";
                    std::cout << std::endl;
                    xs.push_back(obj.New_deaths);

                }
                else if (strcmp(obj.Country, pais) == 0 && strcmp(NumericType, "New_Deaths") == 0 && strcmp(MasMenos, "menor") == 0 && obj.New_deaths < cantidad)
                {
                    std::cout << obj.Date_Reported << " ";
                    std::cout << obj.Country_Code << " ";
                    std::cout << obj.Country << " ";
                    std::cout << "New Deaths: " << obj.New_deaths << " ";
                    std::cout << std::endl;
                    xs.push_back(obj.New_deaths);

                }
                else if (strcmp(obj.Country, pais) == 0 && strcmp(NumericType, "New_Deaths") == 0 && strcmp(MasMenos, "igual") == 0 && obj.New_deaths == cantidad)
                {
                    std::cout << obj.Date_Reported << " ";
                    std::cout << obj.Country_Code << " ";
                    std::cout << obj.Country << " ";
                    std::cout << "New Deaths: " << obj.New_deaths << " ";
                    std::cout << std::endl;
                    xs.push_back(obj.New_deaths);

                }

                //Busqueda por pais y por dato numerico //CUMULATIVE_DEATHS
                if (strcmp(obj.Country, pais) == 0 && strcmp(NumericType, "Cumulative_Deaths") == 0 && strcmp(MasMenos, "mayor") == 0 && obj.Cumulative_deaths > cantidad)
                {
                    std::cout << obj.Date_Reported << " ";
                    std::cout << obj.Country_Code << " ";
                    std::cout << obj.Country << " ";
                    std::cout << "Cumulative Deaths: " << obj.Cumulative_deaths << " ";
                    std::cout << std::endl;
                    xs.push_back(obj.Cumulative_deaths);


                }
                else if (strcmp(obj.Country, pais) == 0 && strcmp(NumericType, "Cumulative_Deaths") == 0 && strcmp(MasMenos, "menor") == 0 && obj.Cumulative_deaths < cantidad)
                {
                    std::cout << obj.Date_Reported << " ";
                    std::cout << obj.Country_Code << " ";
                    std::cout << obj.Country << " ";
                    std::cout << "Cumulative Deaths: " << obj.Cumulative_deaths << " ";
                    std::cout << std::endl;
                    xs.push_back(obj.Cumulative_deaths);

                }
                else if (strcmp(obj.Country, pais) == 0 && strcmp(NumericType, "Cumulative_Deaths") == 0 && strcmp(MasMenos, "igual") == 0 && obj.Cumulative_deaths == cantidad)
                {
                    std::cout << obj.Date_Reported << " ";
                    std::cout << obj.Country_Code << " ";
                    std::cout << obj.Country << " ";
                    std::cout << "Cumulative Deaths: " << obj.Cumulative_deaths << " ";
                    std::cout << std::endl;
                    xs.push_back(obj.Cumulative_deaths);

                }
                //fin
                inFile.read(reinterpret_cast<char *>(&obj), sizeof(WHO));
            }

            //HACER GRAPH AQUIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            char op[3];
            char NombreGrafica[40];
            std::cout << "******************************************" << std::endl;
            std::cout << "QUIERE GRAFICAR? " << std::endl;
            std::cout << "SI? No?: ";
            std::cin >> op;
            std::cout << "******************************************" << std::endl;
            if (strcmp(op, "si") == 0)
            {
                std::cout << "Ingrese nombre de la grapfica: ";
                std::cin >> NombreGrafica;
                ope.graph(xs, NombreGrafica, cantidad);
                std::cout << "Grafica creada con exito" << std::endl;
            std::cout << "******************************************" << std::endl;
            }
            else
            {
                return 0;
            }
        }

        inFile.close();
    }

    //BUSQUEDAS POR FECHA

    if (strcmp(opcion, "fecha") == 0)
    {

        std::ifstream inFile;
        inFile.open("WHO.bin", std::ios::in | std::ios::binary);

        WHO obj;
        inFile.seekg(0, std::ios::beg);

        char pais[50];
        strcpy(pais, argv[2]);

        char FechaInicial[11];
        strcpy(FechaInicial, argv[3]);

        char FechaFinal[11];
        strcpy(FechaFinal, argv[4]);

        bool key = true;

        int pos;

        inFile.read(reinterpret_cast<char *>(&obj), sizeof(WHO));

        if (argc == 5)
        {

            //Primer While
            while (!inFile.eof() && key)
            {

                if ((strcmp(obj.Country, pais) == 0 && strcmp(obj.Date_Reported, FechaInicial) == 0))
                {
                    std::cout << obj.Date_Reported << " ";
                    std::cout << obj.Country_Code << " ";
                    std::cout << obj.Country << " ";
                    std::cout << obj.WHO_region << " ";
                    std::cout << obj.New_cases << " ";
                    std::cout << obj.Cumulative_cases << " ";
                    std::cout << obj.New_deaths << " ";
                    std::cout << obj.Cumulative_deaths << std::endl;

                    key = false;
                    pos = inFile.tellg();

                    if (strcmp(obj.Date_Reported, FechaFinal) == 0)
                    {
                        return 0;
                    }
                }
                inFile.read(reinterpret_cast<char *>(&obj), sizeof(WHO));
            }

            //Segundo while
            inFile.seekg(pos);

            while (!inFile.eof())
            {

                if (strcmp(obj.Country, pais) == 0)
                {
                    std::cout << obj.Date_Reported << " ";
                    std::cout << obj.Country_Code << " ";
                    std::cout << obj.Country << " ";
                    std::cout << obj.WHO_region << " ";
                    std::cout << obj.New_cases << " ";
                    std::cout << obj.Cumulative_cases << " ";
                    std::cout << obj.New_deaths << " ";
                    std::cout << obj.Cumulative_deaths << std::endl;

                    if (strcmp(obj.Date_Reported, FechaFinal) == 0)
                    {
                        return 0;
                    }
                }
                inFile.read(reinterpret_cast<char *>(&obj), sizeof(WHO));
            }
        } //if de argumento

        inFile.close();
    }
    return 0;
}
