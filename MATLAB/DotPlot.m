function plotClimbingVsPPM()
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

    % Get climbing score (column 6) and points per match (PPM)
    driver_score = data(:, 5);
    ppm = data(:, 2); % PPM is column 2

    % Plot dot plot
    scatter(ppm, driver_score, 'o', 'MarkerEdgeColor', 'b', 'MarkerFaceColor', 'b');
    
    % Set labels and title
    xlabel('Points Per Match (PPM)');
    ylabel('Climbing Score');
    title('Climbing Score vs Points Per Match');
    grid on;
    
    % Add team labels
    team_numbers = data(:, 1); % Team numbers from column 1
    for i = 1:length(team_numbers)
        text(ppm(i), driver_score(i), num2str(team_numbers(i)), 'VerticalAlignment', 'bottom', 'HorizontalAlignment', 'right');
    end
end


