#ifndef CSVReader_HPP
#define CSVReader_HPP

#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <string> // Move string to char[]
#include <fstream>
#include <sstream>

class CSVReader
{
private:

protected:
    const std::string filename_{};
    //std::ifstream& in_file_(){};
    const char delimeter_{','};

    std::map<std::string, std::vector<std::vector<int>>> team_map_{};
    //std::deque<std::vector<int>> row; //Preemptive support for Threads

public:
    CSVReader(const std::string&);
    CSVReader(const std::string &, const char &);
    CSVReader &ReadCSV();
    CSVReader &ParseCSV();

    std::map<std::string, std::vector<std::vector<int>>> &GetResults();

    ~CSVReader(){};
};

#include "CSVReader.cpp"
#endif
