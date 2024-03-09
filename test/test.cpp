#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "..\util\csv.hpp"
#include "..\util\teams\Team.hpp"

using namespace std;

int main()
{
    Team<double> team;
    team.UpdateMetric();
    string filename = "../Data/NLR/nlr1.csv";

    auto c = CSVReader(filename).ParseCSV().GetResults(); // ParseCVS files and return the map.

    CSVWriter writer = CSVWriter().SetFileName("m1.csv"); // Init a csv writer to file name "data2.csv -- defaults to tmp.csv"

    for (const auto &[key, value] : c)
    {
        writer.WriteCSV(value); // Push each <vector<vector<int>>> to the csv file.
    }

    std::cout << writer.GetFileName() << ": " << writer.WriteWasSuccess() << '\n';

    /*

    Example for reading in for Reader and/or writer.
    */
    CSVReader reader = CSVReader();
    CSVWriter writer2 = CSVWriter();

    std::string data_in{};
    std::cout << "Enter data in path\n";
    std::cin >> data_in;
    reader.SetFileName(data_in);
    
    std::cout << '\n';

    std::string data_out{};
    std::cout << "Enter data out path\n";
    std::cin >> data_out;
    writer.SetFileName(data_out);

    return 0;
}