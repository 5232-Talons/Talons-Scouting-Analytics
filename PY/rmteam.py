# Define the name of your input and output files
input_file = "PY\matrix     prac.csv"
output_file = "matrixprac.csv"

# Read lines from the input file and filter out lines without team numbers
with open(input_file, 'r') as f:
    lines = f.readlines()

# Filter lines that contain team numbers
filtered_lines = [line for line in lines if any(char.isdigit() for char in line)]

# Write the filtered lines to the output file
with open(output_file, 'w') as f:
    f.writelines(filtered_lines)

print("Lines without team numbers have been removed.")
