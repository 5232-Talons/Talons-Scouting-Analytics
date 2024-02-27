function    plotNPMvsOccurrences()
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

    % Get unique team numbers
    unique_teams = unique(data(:, 1));

    % Initialize a cell array to store NPM values for each team
    npm_values_all = data(:, 2); % PPM is column 2
    % Iterate over unique teams
    for i = 1:numel(unique_teams)
        % Plot NPM vs occurrences for the current team
        plotNPMForTeam(data, unique_teams(i));
    end

    % Set labels and title
    xlabel('Number of Occurrences');
    ylabel('NPM (Sum of Rows 2, 3, 4, and 5)');
    title('NPM vs Number of Occurrences for Each Team');
    grid on;

    % Add legend with team numbers
    legend(cellstr(num2str(unique_teams)));
end

function plotNPMForTeam(data, team_number)
    % Find rows for the current team
    team_rows = data(data(:, 1) == team_number, :);

    % Sum rows 2, 3, 4, and 5 for each occurrence of the team
    npm_values = sum(team_rows(:, 2:5), 2);

    % Calculate the number of occurrences
    occurrences = 1:numel(npm_values);

    % Plot NPM values against the number of occurrences for the current team
    plot(occurrences, npm_values, 'o-', 'LineWidth', 1.5);
    hold on; % Hold the plot to overlay plots for different teams
end
