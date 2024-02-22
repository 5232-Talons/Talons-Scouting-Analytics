#ifndef csv_hpp
#define csv_hpp

#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <string> // Move string to char[]
#include <fstream>
#include <sstream>

/*
CSV Reader and Writer should be derived from class CSV.
*/

class CSVReader
{
private:

protected:
    std::string filename_{};
    //std::ifstream& in_file_(){};
    char delimeter_{','};

    std::map<std::string, std::vector<std::vector<int>>> team_map_{};
    //std::deque<std::vector<int>> row; //Preemptive support for Threads

public:
    CSVReader() : filename_{"data.csv"}, delimeter_{','} {};
    CSVReader(const std::string&);
    CSVReader(const std::string &, const char &);
    CSVReader &ReadCSV();
    CSVReader &ParseCSV();

    std::map<std::string, std::vector<std::vector<int>>> &GetResults();
    CSVReader &SetFileName(std::string&);

    ~CSVReader(){};
};

class CSVWriter
{
    private:
    protected:
        std::string filename_{"tmp.csv"};
        char delimeter_{','};
        bool wasSuccess{false};
        std::vector<std::vector<std::vector<int>>> write_content_{};


    public:
        /*
        CTOR
        Will use default filname (tmp.csv) and default delimeter (,);
        */
        CSVWriter(); 
        CSVWriter(const std::string&); //Take a ref to filename/location
        CSVWriter(const std::string&, const char &); //Take a ref to a filename and a delimeter.

    
    /*Core*/
        CSVWriter &WriteCSV(const std::vector<std::vector<int>>&); //Write to file given a vector of rows.
        CSVWriter &WriteCSV(); // Write to the given file.

    /*Helper(s)*/
        std::string &GetFileName();  //Get filename currently being used
        CSVWriter &SetFileName(const std::string&); //Set filename
        bool FileNameIsValid();

        bool WriteWasSuccess();

        ~CSVWriter(){};

};


#include "CSVReader.cpp"
#include "CSVWriter.cpp"
#endif
