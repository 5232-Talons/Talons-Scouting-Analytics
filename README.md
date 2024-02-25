Talons Scouting Analytics

Installation and Execution:
 
1. Install Visual Studio Code (Optional): Download and install Visual Studio Code (VSCode) for a more convenient coding experience.
          https://code.visualstudio.com/docs/languages/cpp

2. Install `g++`: Follow the system-specific tutorial to install the GNU Compiler Collection (GCC), including `g++`.
      How to install g++ also here: https://code.visualstudio.com/docs/languages/cpp

3. Download the Software: Obtain the software files from the github repository or request zip file from a dev.

4. Download Scouting Data:
   - Access the Matrix tab of 5232's Scouting Google Sheet.
   - Download the data as a CSV file.

5. Place CSV File:
   - Ensure the downloaded CSV file is in the same directory as `scout.cpp`.

6. Navigate to the Directory: Access the directory containing the software using your prefered terminal or command prompt or terminal within VScode.

7. Compile the Program:
   g++ -std=c++20 scout.cpp -o run

8. Run the Program:
   ./'run'

Program Features:

Welcome to 5232's Scouting Analytics!

1. View a team's data: Enter a team number to view its average score, standard deviation, driver score, climbing score, human score, notes per match, and match count.

2. Print a CSV of all teams' data: Print all teams' data, including team number, average score, notes average score, standard deviation, driver score, climbing score, human score, notes per match, and match count.

3. Simulate a match: Simulate a match by entering team numbers for the Blue and Red alliances. The program calculates and displays the projected winner based on total scores.

4. Load New CSV Dataset: Load a new CSV dataset to update the scouting data.

5. Save Data to CSV: Save the updated scouting data to a CSV file. This file can then be copy pasted into a CompPS sheet, like the one on the 5232 NLR Scouting 2024 sheet. This will compute pick scores, although manual review is still required.

6. Print list of teams: Print a list of all team numbers.

7. Print list of teams based off of best score avg: Print a list of teams sorted by average score in descending order, along with their standard deviations.

8. Playoffs simulation: Simulate playoffs by creating alliances based on team average scores. The program displays each alliance's total score and projected winner.

Conclusion:

Thank you for using 5232's Scouting Analytics. Please reach out to devs for feature requests!
