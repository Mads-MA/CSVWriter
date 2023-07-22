#pragma once
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>

template<class... Ts>
class CSVWriter
{
public:

    CSVWriter(std::string path, int floatingPointPrecision = 6)
    {
        fs = std::ofstream(path);
        precision = floatingPointPrecision;
    }

    CSVWriter(const CSVWriter& copy)
    {
        fs = copy.fs;
        precision = copy.precision;
    }

    ~CSVWriter()
    {
        if (fs.is_open())
        {
            fs.close();
        }
    }


    template<class... Hs>
    void WriteHeader(Hs ...args)
    {
        std::stringstream ss;

        WriteHeader(ss, args...);
        ss << std::endl;

        fs << ss.str();
    }

    void WriteEntry(Ts ...args)
    {
        std::stringstream ss;

        WriteEntry(ss, args...);
        ss << std::endl;

        fs << ss.str();
    }


private:
    void WriteHeader(std::stringstream& ss, const char* arg)
    {
        ss << arg << ",";
    }

    template<class... Hs>
    void WriteHeader(std::stringstream& ss, const char* arg, Hs ...args)
    {
        ss << arg << ",";
        WriteHeader(ss, args...);
    }

    template<class T>
    void WriteEntry(std::stringstream& ss, const T& arg)
    {
        ss << arg << ",";
    }

    template<class T, class... Ts>
    void WriteEntry(std::stringstream& ss, const T& arg, Ts ...args)
    {
        ss << arg << ",";
        WriteEntry(ss, args...);
    }

    //Template specialization for floating point numbers
    template<>
    void WriteEntry(std::stringstream& ss, const double& arg)
    {
        ss << std::setprecision(precision) << arg << ",";
    }

    template<class... Ts>
    void WriteEntry(std::stringstream& ss, const double& arg, Ts ...args)
    {
        ss << std::setprecision(precision) << arg << ",";
        WriteEntry(ss, args...);
    }

    template<>
    void WriteEntry(std::stringstream& ss, const float& arg)
    {
        ss << std::setprecision(precision) << arg << ",";
    }

    template<class... Ts>
    void WriteEntry(std::stringstream& ss, const float& arg, Ts ...args)
    {
        ss << std::setprecision(precision) << arg << ",";
        WriteEntry(ss, args...);
    }

private:
    std::ofstream fs;
    int precision;

};
