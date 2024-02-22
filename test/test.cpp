#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "..\util\CSVReader.hpp"

using namespace std;

int main(){
    string filename = "data.csv";

    auto c = CSVReader(filename).ReadCSV().GetResults();

    for (const auto& [key, val] : c){
        std::cout << key << ": " << val[0][1] << std::endl;
    }
    



    return 0;
}