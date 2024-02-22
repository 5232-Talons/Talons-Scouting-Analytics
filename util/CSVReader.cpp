#include "CSVReader.hpp"

CSVReader::CSVReader(const std::string& fN_) : filename_{fN_}{};
CSVReader::CSVReader(const std::string& fN_, const char& dL_) : filename_{fN_}, delimeter_{dL_} {}; //Default CTOR, initialize our reader with a path. 

CSVReader& CSVReader::ReadCSV(){
    std::ifstream in_file_(this->filename_);
    if(!in_file_.is_open()) {
        std::cerr << "Error: Unable to open the file: " << this->filename_ << '\n'; 
        exit(1);
    }

    std::string line{};
    while(getline(in_file_, line) && !in_file_.eof()){
        std::vector<int> row{};
        std::stringstream str_strm(line);
        std::string cell{};

        while(getline(str_strm, cell, ',')) {
            row.push_back(std::stoi(cell));
        }

        std::string key = std::to_string(row[0]);
        if(!this->team_map_.contains(key)) {
            team_map_[key] = std::vector<std::vector<int>>{};
        }

        team_map_.find(key)->second.push_back(row);
    

    }


    return *this; // Returning a refrence to this class, allows for hot syntatic suga.
}

CSVReader& CSVReader::ParseCSV(){

    return *this;
}

std::map<std::string, std::vector<std::vector<int>>>& CSVReader::GetResults(){
    return this->team_map_;
}