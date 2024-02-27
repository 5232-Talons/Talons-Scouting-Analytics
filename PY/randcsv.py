import csv
import random

# Define team numbers
teams = [
    1574, 1576, 1577, 1580, 1690, 1942, 2230, 2630, 2679, 3065,
    3083, 3211, 3316, 3339, 4319, 4320, 4338, 5135, 5654, 5715,
    5951, 5990, 6230, 6738, 6740, 7067, 7177, 8175, 9303, 9738, 9740
]
# Create and shuffle teams list
team_list = teams * 12
random.shuffle(team_list)

# Open CSV file for writing
with open('ISR1RAND.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    
    # Write header row
    writer.writerow([
        'Team #', 'AUTONOTESA', 'AUTONOTESS', 'TeleopNOTESA',
        'TeleopNOTESS', 'TeleopNOTESTrap', 'DriverRating',
        'HumanPlayerRating', 'CoopertitionButton', 'BotRating',
    ])
    
    # Write data for each team
    for team in team_list:
        auto_notes_s = random.randint(0,3)
        auto_notes_a = random.randint(0,3)
        teleop_notes_s = random.randint(0, 5)
        teleop_notes_a = random.randint(0, 5)
        teleop_notes_trap = random.randint(0, 1)
        driver_rating = random.randint(0, 5)
        human_player_rating = random.randint(0, 5)
        coopertition_button = random.randint(0, 1)
        bot_rating = random.randint(0, 5)


        
        # Write row for the team
        writer.writerow([
            team, auto_notes_s, auto_notes_a , teleop_notes_a,
            teleop_notes_s, teleop_notes_trap,
            driver_rating, human_player_rating,
            coopertition_button, bot_rating
        ])
