#ifndef CSV_h
#define CSV_h

#include <iostream>
#include <fstream>

#include "pbPlots.hpp"
#include "supportLib.hpp"



struct WHO
{

    WHO()
    :size(0), crc(0)
    {
        std::fill(signature, signature + 4, 0);
        std::fill(name, name + 4, 0);
    }

    void setSignature(const char* sign){
        std::copy(sign, sign+4, signature);
    }

    void setName(const std::string& sname){
        std::copy(sname.begin(), sname.end(), name);
    }

    char signature[4];
    char name[64];
    uint32_t size;
    uint32_t crc;

    char Date_Reported [11];
    char Country_Code [3];
    char Country [50];
    char WHO_region [5];

    double New_cases;
    double Cumulative_cases;
    double New_deaths;
    double Cumulative_deaths;

}__attribute((packed));


class OperacionesCSV{
    public:
    void convert();
    void display(std::string file);
    void graph(std::vector<double> xs, const char* nameGraph, int cantidad);
};

#endif