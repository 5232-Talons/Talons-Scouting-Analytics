% Open UI to select CSV file
[filename, filepath] = uigetfile('*.csv', 'Select CSV File');

% Check if user cancels selection
if isequal(filename, 0)
    disp('User cancelled the operation. Script terminated.');
    return;
end

% Construct full file path
csv_file = fullfile(filepath, filename);

% Read data from CSV file
data = readmatrix(csv_file);

% Find rows where team number is 5232
team_5232_rows = data(data(:, 1) == 5232, :);

% Sum rows 2, 3, 4, and 5 for each occurrence of team 5232
% Sum columns 2, 3, 4, and 5 for each occurrence of team 5232
npm_values = sum(team_5232_rows(:, 2:5), 2);


% Calculate the number of occurrences
occurrences = 1:numel(npm_values);

% Plot NPM values against the number of occurrences
plot(occurrences, npm_values, 'o-', 'LineWidth', 1);
xlabel('Matches');
ylabel('NPM');
title('NPM vs Matches for Team 5232');
grid on;

% Set X and Y ticks to intervals of one
xticks(1:max(occurrences));
yticks(0:max(npm_values));
