import sys
import os

# Get the parent directory of the current directory
parent_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))

# Get the parent directory of the parent directory
grandparent_dir = os.path.abspath(os.path.join(parent_dir, ".."))

# Add both parent and grandparent directories to sys.path
sys.path.append(parent_dir)
sys.path.append(grandparent_dir)


import statbotics

# List of team numbers
teams = [
    1714, 1716, 1792, 1806, 2039, 2062, 2129, 2169, 2175, 2227,
    2264, 2472, 2491, 2501, 2512, 2574, 2846, 2855, 2987, 3023,
    3082, 3100, 3130, 3206, 3212, 3297, 3418, 3883, 4166, 4182,
    4229, 4230, 4623, 4703, 4786, 5232, 5271, 5275, 5339, 5720,
    5913, 6044, 6045, 6047, 6132, 6147, 6419, 6574, 6758, 7273,
    7530, 7619, 8122, 8700, 8803
]

# Create a Statbotics object
sb = statbotics.Statbotics()

# Dictionary to store team EPA
team_epa = {}

# Iterate through teams to get EPA
for team in teams:
    team_data = sb.get_team(team)
    team_epa[team] = team_data['norm_epa']

# Sort teams by EPA
sorted_teams = sorted(team_epa.items(), key=lambda x: x[1], reverse=True)

# Print teams and their EPA
for team, epa in sorted_teams:
    print(f"Team {team}: EPA {epa}")

# Count the number of teams
print(f"Total number of teams: {len(sorted_teams)}")
