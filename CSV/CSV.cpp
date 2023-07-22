// CSV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CSVWriter.hpp"

int main()
{
    std::cout << "Hello World!\n";

    auto log = CSVWriter<double, float, double, bool>("test.csv", 3);
    //log.WriteHeader(std::string("time"), std::string("magnitude"), std::string("isOn"));
    log.WriteHeader("time", "magnitude", "space", "isOn");
    log.WriteEntry(0.0, 1.4444, 10000.1, false);

}