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
data = readmatrix(csv_file, 'NumHeaderLines', 1);

% Extract average scores and NPM
average_scores = data(:, 2);
npm_scores = data(:, 7);

% Plotting histograms
figure;

subplot(1, 2, 1);
histogram(average_scores, 'BinWidth', 1); % Adjust BinWidth as needed
xlabel('Average Score');
ylabel('Frequency');
title('Distribution of Average Scores Across All Teams');

subplot(1, 2, 2);
histogram(npm_scores, 'BinWidth', 1); % Adjust BinWidth as needed
xlabel('NPM (Notes Average Score)');
ylabel('Num Teams');
title('Distribution of NPM Across All Teams');
