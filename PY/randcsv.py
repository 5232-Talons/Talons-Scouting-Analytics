import csv
import random

# Define team numbers
teams = [
    1714, 1716, 1792, 1806, 2039, 2062, 2129, 2169, 2175, 2227,
    2264, 2472, 2491, 2501, 2512, 2574, 2846, 2855, 2987, 3023,
    3082, 3100, 3130, 3206, 3212, 3297, 3418, 3883, 4166, 4182,
    4229, 4230, 4623, 4703, 4786, 5232, 5271, 5275, 5339, 5720,
    5913, 6044, 6045, 6047, 6132, 6147, 6419, 6574, 6758, 7273,
    7530, 7619, 8122, 8700, 8803
]

# Create and shuffle teams list
team_list = teams * 6
random.shuffle(team_list)

# Open CSV file for writing
with open('robot_scores.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    
    # Write header row
    writer.writerow([
        'Team #', 'PointsinAUTO', 'Amp/Speaker', 'TeleopNOTESA',
        'TeleopNOTESS', 'Climb', 'TeleopNOTESTrap', 'DriverRating',
        'HumanPlayerRating', 'CoopertitionButton', 'BotRating, Mobility, Park '
    ])
    
    # Write data for each team
    for team in team_list:
        points_in_auto = random.choice([2, 5, 7, 10])
        teleop_notes_s = random.randint(0, 10)
        teleop_notes_a = random.randint(0, 10 - teleop_notes_s)
        climb = random.randint(0, 1)
        teleop_notes_trap = random.randint(0, 1)
        driver_rating = random.randint(0, 5)
        human_player_rating = random.randint(0, 5)
        coopertition_button = random.randint(0, 1)
        bot_rating = random.randint(0, 5)
        mobility = random.randint(0,1)
        park = random.randint(0,1)

        
        # Write row for the team
        writer.writerow([
            team, points_in_auto, 0, teleop_notes_a,
            teleop_notes_s, climb, teleop_notes_trap,
            driver_rating, human_player_rating,
            coopertition_button, bot_rating, mobility, park
        ])
