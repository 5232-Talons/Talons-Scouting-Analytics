
/**************************************************************************************
TSA - TALONS SCOUTING ANALYTICS

lars + slim
***************************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include "./util/csv.hpp"
#include <algorithm>

using namespace std;

void csv_to_matrix(const string &, vector<vector<int>> &);
bool endsWithCsv(const string&);
bool hasEmptyRows(const string&);
bool isFirstRowNumeric(const string&);
void findNonNumericData(const string&, vector<pair<int, int>>&);


int main(){
#pragma region // Analytic Setup & computations
    vector<pair<int, int>> nonNumericLocations;
    int as{}, aa{}, ts{}, ta{}, tt{}, p{}, l{}, c{};
    char ch_has_header{'n'};
    bool header = false;

    string filename1 = "robot_scores.csv"; // Provide the path to your CSV file -- This will serve as a default name as well.
    string filename2;

    cout << "****************************************" << endl;
    cout << "  Welcome to 5232's Scouting Analytics" << endl;
    cout << "****************************************" << endl;
    cout << "Enter main filename to load: ";
    cin >> filename1;
    cout << '\n';

//**** Bad Data Checks **** 

    if(!(endsWithCsv(filename1))){
        cout << endl << "ERROR - your match data is not a .csv" << endl;
        return 1;
    }
    if(hasEmptyRows(filename1)){
        cout << endl << "ERROR - this file has empty rows" << endl;
        return 1;
    }

    findNonNumericData(filename1, nonNumericLocations);
    if (!nonNumericLocations.empty()){
        for (const auto& location : nonNumericLocations){
            if(location.first != 1){
            cout << " NOT NUMERIC @ Row: " << location.first << ", Column: " << location.second << endl;
            }
        }
    } 
    nonNumericLocations.clear();

//**** Feed CSV data to matrix ****

    auto result1 = CSVReader(filename1).ParseCSV(isFirstRowNumeric(filename1) ? false : true).GetResults();

    vector<vector<int>> matrix1{};
    for (const auto &[key, value] : result1){
        for (const auto &row : value)
            matrix1.push_back(row);
    }

//**** Accept User Input for columns ****

        cout << "What column is auto notes in speaker?" << endl;
        cin >> as;
        as--;

        cout << "What column is auto notes in amp?" << endl;
        cin >> aa;
        aa--;

        cout << "What column is telop notes in speaker?" << endl;
        cin >> ts;
        ts--;

        cout << "What column is telop notes in amp?" << endl;
        cin >> ta;
        ta--;

        cout << "What column is telop notes in trap?" << endl;
        cin >> tt;
        tt--;

        cout << "What column is leave in auto(mobility)?" << endl;
        cin >> l;
        l--;

        cout << "What column is park?" << endl;
        cin >> p;
        p--;

        cout << "What column is climb?" << endl;
        cin >> c;
        c--;


        cout << endl << endl;


// Populate vector team numbers
    vector<int> team_numbers = {
        159, 568, 662, 1011, 1108, 1138, 1303, 1339, 1410, 1619, 1799, 1822, 1868,
        1977, 2036, 2083, 2240, 2259, 2261, 2945, 2996, 3006, 3200, 3374, 3648, 3729,
        3807, 4009, 4010, 4068, 4293, 4388, 4418, 4499, 4550, 4593, 4944, 5232, 5493,
        5690, 7243, 7479, 7485, 7737, 8334, 9068, 9112, 9552, 9586
    };


// Initialize vectors
    vector<double> avg_score(team_numbers.size(), 0);
    vector<double> notes_avg_score(team_numbers.size(), 0);
    vector<double> match_score(matrix1.size(), 0);
    vector<double> stdev(team_numbers.size(), 0);
    vector<double> climbing_score(team_numbers.size(), 0);
    vector<double> match_count(team_numbers.size(), 0);
    vector<double> NPM(team_numbers.size(), 0);

// Calculate scores
    for (size_t i = 0; i < team_numbers.size(); ++i){
        size_t team_number = team_numbers[i];
        int count = 0;

        for (size_t j = 0; j < matrix1.size(); ++j){
            if (matrix1[j][0] == team_number){
                match_score[j] = matrix1[j][aa] * 2 + matrix1[j][as] * 5 + matrix1[j][ta] + 2 * matrix1[j][ts] + matrix1[j][tt] * 5 + matrix1[j][l] * 2 + matrix1[j][p] + matrix1[j][c] * 3; 
                avg_score[i] += match_score[j];
                notes_avg_score[i] += match_score[j];
                count++;
                NPM[i] += matrix1[j][aa] + matrix1[j][as] + matrix1[j][ta] + matrix1[j][ts] + matrix1[j][tt]; 
            }
        }

        if (count != 0){
            avg_score[i] /= count;
            notes_avg_score[i] /= count;
            match_count[i] = count;
            NPM[i] /= count;
        }
    }

// Calculate standard deviation
    for (size_t i = 0; i < team_numbers.size(); ++i){
        size_t team_number = team_numbers[i];
        int count = 0;

        for (size_t j = 0; j < matrix1.size(); ++j){
            if (matrix1[j][0] == team_number){
                stdev[i] += pow(avg_score[i] - match_score[j], 2);
                count++;
            }
        }
        if (count != 0){
            stdev[i] = sqrt(stdev[i] / count);
        }
    }
#pragma endregion

    int choice{};
    const int exit_prog = 8;
//**** MAIN MENU ****
    while (choice != exit_prog){
        int team{}, blue1{}, blue2{}, blue3{}, red1{}, red2{}, red3{}, bluetot{}, redtot{}, blue1_score{}, blue2_score{}, blue3_score{}, red1_score{}, red2_score{}, red3_score{};

        cout << "               Main Menu    " << endl;
        cout << "****************************************" << endl;
        cout << "1. View a team's data" << endl;
        cout << "2. Print a CSV of all team's data" << endl;
        cout << "3. Simulate a match" << endl;
        cout << "4. Save Data to CSV" << endl;
        cout << "5. Print list of teams" << endl;
        cout << "6. Print list of teams based off of best score avg" << endl;
        cout << "7. Playoffs simulation " << endl;
        cout << "8. Exit program" << endl;
        cin >> choice;

        switch (choice){

        case 1:
            cout << "Please Enter the team's data you want: ";
            cin >> team;
            cout << endl;
            for (size_t y = 0; y < team_numbers.size(); ++y){

                if (team_numbers[y] == team)
                {
                    cout << "Team Number:         " << team_numbers[y] << endl;
                    cout << "Average Score:       " << avg_score[y] << endl;
                    cout << "Stdev of Avg Score:  " << stdev[y] << endl;
                    cout << "Notes Avg Score:     " << notes_avg_score[y] << endl;
                    cout << "Notes Per Match:     " << NPM[y] << endl;
                    cout << "Match Count:         " << match_count[y] << endl << endl;
                }
            }
            break;
        case 2:
            cout << "Team Number,Average Score,Notes Average Score, stdev, NPM, match_count" << endl;
            for (size_t y = 0; y < avg_score.size(); ++y){

                cout << team_numbers[y] << "," << avg_score[y] << "," << notes_avg_score[y] << "," << stdev[y] << "," << NPM[y] << "," << match_count[y] << endl;
                cout << endl
                     << endl;
            }
            break;
        case 3:
            cout << "Welcome to the match simulator." << endl;
            cout << "Blue 1: ";
            cin >> blue1;
            cout << "Blue 2: ";
            cin >> blue2;
            cout << "Blue 3: ";
            cin >> blue3;
            cout << "Red 1: ";
            cin >> red1;
            cout << "Red 2: ";
            cin >> red2;
            cout << "Red 3: ";
            cin >> red3;

            for (size_t y = 0; y < avg_score.size(); ++y){

                if (team_numbers[y] == blue1)
                    blue1_score = avg_score[y];
                else if (team_numbers[y] == blue2)
                    blue2_score = avg_score[y];
                else if (team_numbers[y] == blue3)
                    blue3_score = avg_score[y];
                else if (team_numbers[y] == red1)
                    red1_score = avg_score[y];
                else if (team_numbers[y] == red2)
                    red2_score = avg_score[y];
                else if (team_numbers[y] == red3)
                    red3_score = avg_score[y];
            }

            bluetot = blue1_score + blue2_score + blue3_score;
            redtot = red1_score + red2_score + red3_score;
            cout << "Blue alliance          Red Alliance" << endl;
            cout << blue1 << ": " << fixed << setprecision(2) << blue1_score << "           " << red1 << ": " << fixed << setprecision(2) << red1_score << endl;
            cout << blue2 << ": " << fixed << setprecision(2) << blue2_score << "           " << red2 << ": " << fixed << setprecision(2) << red2_score << endl;
            cout << blue3 << ": " << fixed << setprecision(2) << blue3_score << "           " << red3 << ": " << fixed << setprecision(2) << red3_score << endl;
            cout << endl;
            cout << "Red: " << redtot << endl;
            cout << "Blue: " << bluetot << endl;

            if (redtot != bluetot)
                cout << (redtot > bluetot ? "Red Alliance is the projected winner." : "Blue Alliance is the projected winner.") << endl;
            else
                cout << "It's a tie!";

            cout << endl
                 << "End of Match Simulation" << endl
                 << endl;
            break;
   
        case 4:
        {
            vector<vector<double>> rows{};
            vector<double> row{};
            string filename{"tmp.csv"};

            for (size_t y = 0; y < avg_score.size(); ++y){

                row.clear();
                row.push_back(team_numbers[y]);
                row.push_back(avg_score[y]);
                row.push_back(notes_avg_score[y]);
                row.push_back(stdev[y]);
                row.push_back(NPM[y]);
                row.push_back(match_count[y]);
                row.push_back(match_count[y]);
                rows.push_back(row);
            }

            cout << "Enter filename to save stats to: ";
            cin >> filename;
            cout << '\n';
            CSVWriter(filename).WriteCSV(rows);

            break;
        }
        case 5:
        {
            for (size_t y = 0; y < avg_score.size(); ++y)
            {
                cout << team_numbers[y] << endl;
            }
            break;
        }
        case 6:
        {
            vector<tuple<int, double, double>> teams_info;

            for (size_t i = 0; i < team_numbers.size(); ++i)
                teams_info.emplace_back(team_numbers[i], avg_score[i], stdev[i]);

            // Sort the vector of tuples based on the average score
            sort(teams_info.begin(), teams_info.end(), [](const auto &a, const auto &b)
                 { return get<1>(a) > get<1>(b); });

            // Print the sorted teams along with their average scores and standard deviations
            cout << "Teams sorted by average score:" << endl;
            for (const auto &[team, avg, dev] : teams_info)
                cout << "Team " << team << ": Avg Score: " << fixed << setprecision(2) << avg << ", Stdev: " << dev << endl;

            break;
        }
        case 7: 
        {
            // Sort teams based on average score
            vector<pair<int, double>> sorted_teams;
            for (size_t i = 0; i < team_numbers.size(); ++i){
                sorted_teams.push_back({team_numbers[i], avg_score[i]});
            }
            sort(sorted_teams.begin(), sorted_teams.end(), [](const auto &a, const auto &b)
                 { return a.second > b.second; });

            // Divide teams into 8 alliances in a snake draft format
            vector<vector<int>> alliances(8, vector<int>(3));
            for (int i = 0; i < 8; ++i){
                alliances[i][0] = sorted_teams[i * 3].first;      // First pick
                alliances[i][1] = sorted_teams[i * 3 + 1].first;  // Second pick
                alliances[i][2] = sorted_teams[23 - i * 3].first; // Third pick (reverse order)
            }

            // Calculate total score for each alliance
            cout << "---------------------------------" << endl;
            cout << "Alliances and their total scores:" << endl;
            cout << "---------------------------------" << endl;
            for (int i = 0; i < 8; ++i){
                double total_score = 0;
                cout << "Alliance " << i + 1 << ": ";
                for (size_t j = 0; j < alliances[i].size(); ++j){
                    cout << alliances[i][j];
                    if (j < alliances[i].size() - 1)
                        cout << " - ";
                    else
                        cout << endl;

                    // Calculate total score for the alliance
                    for (size_t k = 0; k < team_numbers.size(); ++k){
                        if (team_numbers[k] == alliances[i][j]){
                            total_score += avg_score[k];
                            break;
                        }
                    }
                }
                cout << "Total Score: " << total_score << endl;
                cout << endl;
            }
            break;
        }

        default:
            if (choice != exit_prog){
                cout << "Please enter a valid choice (1, 2, 3, 4, 5, 6, 7, 8)" << endl;
            }
            break;
        }
        cin.ignore();
    }
    cout << "Ending Program" << endl;
    return 0;
}


//**** FUNCTIONS ****

// Converts 5232 Google Sheet to a Matrix that supports quick data manipulation.
void csv_to_matrix(const string &filename1, vector<vector<int>> &score_matrix){
    ifstream file(filename1);

    if (!file.is_open()){
        cerr << "Error: Unable to open the file." << filename1 << '\n';
        exit(1);
    }

    string line{};
    getline(file, line);
    while (getline(file, line)){
        vector<int> row{};
        stringstream ss(line);
        string cell{};

        while (getline(ss, cell, ',')){
            if (cell.empty()){
                row.push_back(0);
            }
            else{
                row.push_back(stoi(cell));
            }
        }

        score_matrix.push_back(row);
    }

    file.close();
}

// Checks if file ends with .csv
bool endsWithCsv(const string& str){
    if (str.length() >= 4){
        return (str.substr(str.length() - 4) == ".csv");
    }
    return false;
}

// Checks if file has empty rows
bool hasEmptyRows(const string& filename){
    ifstream file(filename);
    string line;

    if (file.is_open()){
        while (getline(file, line)){
            // Check if the line contains only commas or is empty
            if (line.find_first_not_of(',') == string::npos || line.empty()){
                file.close();
                return true;
            }
        }
        file.close();
    } else{
        cerr << "Unable to open file: " << filename << endl;
    }
    return false;
}

// Checks if the first row is a header
bool isFirstRowNumeric(const string& filename){
    ifstream file(filename);
    string line;

    if (file.is_open()){
        if (getline(file, line)){
            stringstream ss(line);
            string cell;

            // Check each cell in the first row
            while (getline(ss, cell, ',')){
                // Check if the cell contains only numeric characters
                for (char c : cell){
                    if (!isdigit(c)){
                        file.close();
                        return false;
                    }
                }
            }
            file.close();
            return true;
        }
    } else{
        cerr << "Unable to open file: " << filename << endl;
    }
    return false;
}

// Function - find non numeric data
void findNonNumericData(const string& filename, vector<pair<int, int>>& nonNumericLocations){
    ifstream file(filename);
    string line;
    int rowNumber = 0;
    bool isFirstRow = true; // Flag to identify the first row

    if (file.is_open()){
        // Read each line of the file
        while (getline(file, line)){
            stringstream ss(line);
            string cell;
            int colNumber = 0;
            rowNumber++;

            // Skip processing the first row if it's all non-numeric
            if (isFirstRow){
                bool allNumeric = true;
                while (getline(ss, cell, ',')){
                    for (char c : cell){
                        if (!isdigit(c) && c != '.' && c != '-'){
                            allNumeric = false;
                            break;
                        }
                    }
                    if (!allNumeric){
                        break; // Break if any non-numeric value found in the first row
                    }
                }
                if (allNumeric){
                    isFirstRow = false; // Update the flag to indicate we've processed the first row
                    continue; // Skip to the next iteration to ignore the first row
                }
            }

            // Split the line into cells and check each cell for non-numeric data
            stringstream ss2(line); // Reset the stringstream
            while (getline(ss2, cell, ',')){
                colNumber++;
                // Check if the cell contains only numeric characters
                bool numeric = true;
                for (char c : cell){
                    if (!isdigit(c) && c != '.'){
                        numeric = false;
                        break;
                    }
                }
                if (!numeric){
                    nonNumericLocations.push_back(make_pair(rowNumber, colNumber));
                }
            }
        }
        file.close();
    } else{
        cerr << "Unable to open file: " << filename << endl;
    }
}