#include "csv.hpp"

CSVReader::CSVReader(const std::string &fN_) : filename_{fN_} {};
CSVReader::CSVReader(const std::string &fN_, const char &dL_) : filename_{fN_}, delimeter_{dL_} {}; // Default CTOR, initialize our reader with a path.

CSVReader &CSVReader::ParseCSV()
{
    std::ifstream in_file_(this->filename_);
    if (!in_file_.is_open())
    {
        std::cerr << "Error: Unable to open the file: " << this->filename_ << '\n';
        exit(1);
    }

    std::string line{};
    while (getline(in_file_, line) && !in_file_.eof())
    {
        std::vector<int> row{};
        std::stringstream str_strm(line);
        std::string cell{};

        while (getline(str_strm, cell, ','))
        {
            row.push_back(std::stoi(cell)); // stoi == string to int.
        }

        std::string key = std::to_string(row[0]);
        if (!this->team_map_.contains(key))
        {
            team_map_[key] = std::vector<std::vector<int>>{}; // Need to create a empty <vector<vector> to support the expected matrix.
        }
        team_map_.find(key)->second.push_back(row);
    }

    return *this; // Returning a refrence to this class, allows for hot syntatic suga.
}

CSVReader &CSVReader::ParseCSV(bool has_header)
{
    std::ifstream in_file_(this->filename_);
    if (!in_file_.is_open())
    {
        std::cerr << "Error: Unable to open the file: " << this->filename_ << '\n';
        exit(1);
    }

    std::string line{};
    if(has_header)
        getline(in_file_, line);

    while (getline(in_file_, line) && !in_file_.eof())
    {
        std::vector<int> row{};
        std::stringstream str_strm(line);
        std::string cell{};

        while (getline(str_strm, cell, ','))
        {
            row.push_back(std::stoi(cell)); // stoi == string to int.
        }

        std::string key = std::to_string(row[0]);
        if (!this->team_map_.contains(key))
        {
            team_map_[key] = std::vector<std::vector<int>>{}; // Need to create a empty <vector<vector> to support the expected matrix.
        }
        team_map_.find(key)->second.push_back(row);
    }

    return *this; // Returning a refrence to this class, allows for hot syntatic suga.
}


std::map<std::string, std::vector<std::vector<int>>> &CSVReader::GetResults()
{
    return this->team_map_;
}

CSVReader &CSVReader::SetFileName(std::string &fN_)
{
    this->filename_ = fN_;
    return *this;
}