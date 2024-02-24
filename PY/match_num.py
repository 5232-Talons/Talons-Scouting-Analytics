import csv

# Define the number of matches
num_matches = 120

# Define the filename
filename = "matches.csv"

# Open the file in write mode with newline='' to prevent extra newline characters
with open(filename, 'w', newline='') as csvfile:
    # Create a CSV writer object
    writer = csv.writer(csvfile)

    # Write each match
    for i in range(1, num_matches + 1):
        # Write "Match i" followed by seven empty lines
        writer.writerow(["Match " + str(i)])
        for _ in range(7):
            writer.writerow([])  # Write an empty row

print(f"CSV file '{filename}' has been created successfully with {num_matches} matches.")
