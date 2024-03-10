Talons Scouting Analytics

Requirements
Visual Studio Code (Optional): Download and install Visual Studio Code (VSCode) for a more convenient coding experience.

Download the Software:

Obtain the software files from the GitHub repository, request a zip file from a developer, or download the executable file from the Discord server.
Download Scouting Data:

Access both Matrix tabs of 5232's Scouting Google Sheet.

Download the data as a CSV file. You must do this for each file individually, ensuring that:

Column 1 represents the team number.
The remaining columns contain scoring elements.
The dataset must not have empty rows, non-integers, or strings anywhere besides row 1.
Use the following equation to import the scoutless data into the Google Sheet:

=IMPORTRANGE("https://docs.google.com/spreadsheets/d/1GTyxu_eYq9FKaqx0LkNrmuTAbh2AKvh4GwuM3ht5pgM/edit", "teamData!A:J")
Place CSV Files:

Ensure the downloaded CSV files are in the same directory (folder) as run.exe.
Run the Program:

Execute the run.exe file by double-clicking on it.
Follow the prompts to input the necessary CSV files and data.
Configuration:

Configure the scoutless sheet with the event code.
Ensure that the scoutless data is in the following format:
yaml
Copy code
Team    Auto Leave    Endgame    Auto - Leave    Endgame    
1714    Yes,Yes,Yes,Yes,Yes,Yes,Yes,Yes,None,StageLeft,Parked,Parked,Parked,StageLeft,Parked,CenterStage    8
1716    No,No,,No,No,No,No,,No,No    StageLeft,Parked,,StageRight,Parked,CenterStage,StageRight,,Parked,None    0
...
Sum of Stage Left, Center, and Stage Right:

Add a column in your scoutless data sheet to calculate the sum of Stage Left, Center, and Stage Right for each row.
Usage Notes:

The run.exe should be in the same directory (folder) as the CSV files.
The software attempts to check for bad data (e.g., non-numeric values, empty lines), but manual inspection might be required.
Create a new Google Sheet from the scouting master sheet
Examples of matrix1 and matrix 2 are in main directory of this github page
