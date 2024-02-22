#include "csv.hpp"

#pragma region CTOR
CSVWriter::CSVWriter(){};
CSVWriter::CSVWriter(const std::string &fN_) : filename_{fN_} {};
CSVWriter::CSVWriter(const std::string &fN_, const char &dL_) : filename_{fN_}, delimeter_{dL_} {};

#pragma endregion

#pragma region Writer
CSVWriter &CSVWriter::WriteCSV()
{

    std::ofstream out_file(this->filename_, std::ios::app); // Open file in append mode so we don't overwrite previous values.
    if (!out_file.is_open())
    {
        std::cerr << "Error: Unable to open the file: " << this->filename_ << '\n';
        std::exit(1);
    }

    // Iter through vector<vector<vector>>> to handle map of key, vector<vector<T>>
    for (size_t i = 0; i < this->write_content_.size(); i++)
    {
        for (size_t j = 0; j < this->write_content_[i].size(); j++)
        {
            for (const auto &cell : write_content_[i][j])
                out_file << std::to_string(cell) << this->delimeter_;
            out_file << '\n';
        }
    }

    this->wasSuccess = true;
    return *this;
}

CSVWriter &CSVWriter::WriteCSV(const std::vector<std::vector<int>> &write_content)
{

    std::ofstream out_file(this->filename_, std::ios::app); // Open file in append mode so we don't overwrite previous values.
    if (!out_file.is_open())
    {
        std::cerr << "Error: Unable to open the file: " << this->filename_ << '\n';
        std::exit(1);
    }

    for (size_t i = 0; i < write_content.size(); i++) // Iterate through vector and write to file.
    {
        for (const auto &cell : write_content[i])
            out_file << std::to_string(cell) << this->delimeter_;
        out_file << '\n';
    }
    out_file.close();
    this->wasSuccess = true; // Set our state to success.
    return *this;
}
#pragma endregion

#pragma region Helpers
CSVWriter &CSVWriter::SetFileName(const std::string &fN_)
{
    this->filename_ = fN_;
    return *this;
}

std::string &CSVWriter::GetFileName()
{
    return this->filename_;
}

bool CSVWriter::FileNameIsValid()
{
    // TODO: More logic should be done here!
    return true;
}

bool CSVWriter::WriteWasSuccess()
{
    return this->wasSuccess;
}
#pragma endregion