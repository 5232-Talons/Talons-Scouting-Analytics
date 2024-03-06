% Given points
points = [
    4.29, 29.666;
    4.21, 31;
    3.15, 31.2;
    4.69, 28.5
];

% Filter points within the range 0 < x < 3.5
filtered_points = points(points(:, 1) > 0 & points(:, 1) < 4.5, :);

% Extract x and y values from filtered points
x_values = filtered_points(:, 1);
y_values = filtered_points(:, 2);

% Degree of the polynomial
degree = 1; % You can change the degree as needed

% Perform polynomial fitting
coefficients = polyfit(x_values, y_values, degree);

% Display the coefficients of the polynomial
disp('Coefficients of the polynomial fit:');
disp(coefficients);
% Plot original points and fitted polynomial
x_range = linspace(0, 3.5, 100); % Range for plotting
fitted_curve = polyval(coefficients, x_range);

% Plot original points
scatter(x_values, y_values, 'filled');
hold on;

% Plot fitted polynomial
plot(x_range, fitted_curve, 'r');

% Add labels and title
xlabel('X');
ylabel('Y');
title('Polynomial Fitting');

% Add legend
legend('Original Points', 'Fitted Polynomial');

% Show grid
grid on;

% Release hold on the plot
hold off;
