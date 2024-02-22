/*
Implementation of a basic routine to caluclate teams overall avg score & avg note score.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

void csv_to_matrix(const string &, vector<vector<int>> &);

int main()
{
    string filename = "data.csv"; // Provide the path to your CSV file

    vector<vector<int>> matrix{};
    csv_to_matrix(filename, matrix); // This works because refrences are OP, it should be done this way to avoid one less copy/move.

    // TODO: Move this to a Map (ordered or unorderd doesn't matter)
    const vector<int> team_numbers = {
        1714, 1716, 1792, 1806, 2039, 2062, 2129, 2169, 2175, 2227,
        2264, 2472, 2491, 2501, 2512, 2574, 2846, 2855, 2987, 3023,
        3082, 3100, 3130, 3206, 3212, 3297, 3418, 3883, 4166, 4182,
        4229, 4230, 4623, 4703, 4786, 5232, 5271, 5275, 5339, 5720,
        5913, 6044, 6045, 6047, 6132, 6147, 6419, 6574, 6758, 7273,
        7530, 7619, 8122, 8700, 8803};

    vector<double> avg_score(team_numbers.size(), 0);       // Initialize avg score vector, filled with zeroes
    vector<double> notes_avg_score(team_numbers.size(), 0); // Initialize notes avg score vector, filled with zeroes
    vector<double> match_score(matrix.size(), 0);

    size_t team_number{}, count{};

    // TOOD: These scores should be moved to a struct or class, this would also support qualitative data as well then.
    for (size_t i = 0; i < team_numbers.size(); ++i)
    {
        team_number = team_numbers[i];
        for (size_t j = 0; j < matrix.size(); ++j)
        {
            if (matrix[j][0] == team_number)
            {
                match_score[j] = matrix[j][1] + matrix[j][3] + 2 * matrix[j][4] + matrix[j][5] * 3 + matrix[j][6] * 5;
                avg_score[i] += match_score[j];
                notes_avg_score[i] += matrix[j][1] + matrix[j][3] + 2 * matrix[j][4];
                count++;
            }
        }
        // Calculate average score after all matches of the team are accumulated
        if (count != 0)
        {
            avg_score[i] = avg_score[i] / count;
            notes_avg_score[i] = notes_avg_score[i] / count;
        }
        // Reset count for the next team
        count = 0;
        
    }

    
vector<double> stdev(team_numbers.size(), 0); // Initialize notes avg score vector, filled with zeroes
    for (size_t i = 0; i < team_numbers.size(); ++i)
    {
        team_number = team_numbers[i];
        for (size_t j = 0; j < matrix.size(); ++j)
        {
            if (matrix[j][0] == team_number)
            {
                stdev[i] += pow(avg_score[i] - match_score[j], 2);
                count++;
            }
        }
        stdev[i] = sqrt(stdev[i] / count);
        // Calculate average score after all matches of the team are accumulated
        if (count != 0)
        {
            avg_score[i] = avg_score[i] / count;
            notes_avg_score[i] = notes_avg_score[i] / count;
        }
        // Reset count for the next team
        count = 0;
        
    }
 
    cout << endl << endl;
    cout << "Team Number,Average Score,Notes Average Score, stdev" << endl;

    for(size_t y = 0; y < avg_score.size(); ++y){
    cout << team_numbers[y] << "," << avg_score[y] << "," << notes_avg_score[y] << "," << stdev[y] << endl; 
    }

    return 0;
}

// Converts 5232 Google Sheet to a Matrix that supports quick data maniuplation.
void csv_to_matrix(const string &filename, vector<vector<int>> &score_matrix)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Error: Unable to open the file." << filename << '\n';
        exit(1);
    }

    string line{};
    while (getline(file, line))
    {
        vector<int> row{};
        stringstream ss(line);
        string cell{};

        while (getline(ss, cell, ','))
        {
            row.push_back(stoi(cell));
        }

        score_matrix.push_back(row);
    }

    file.close();
}
