#include <iostream>
#include <vector>
#include <cmath>

// Define the dataset
std::vector<std::pair<double, double>> dataset = {{1.2, -2.7}, {1.6, -1.5}, {2.1, -0.7}, {2.3, -0.1}, {2.9, 0.9}};

// Linear curve fitting using the method of least squares
void linearCurveFitting() {
    double sum_x = 0.0, sum_y = 0.0, sum_x_squared = 0.0, sum_xy = 0.0;
    for (const auto& point : dataset) {
        double x = point.first;
        double y = point.second;
        sum_x += x;
        sum_y += y;
        sum_x_squared += x * x;
        sum_xy += x * y;
    }

    double N = static_cast<double>(dataset.size());
    double a = (sum_y * sum_x_squared - sum_x * sum_xy) / (N * sum_x_squared - sum_x * sum_x);
    double b = (N * sum_xy - sum_x * sum_y) / (N * sum_x_squared - sum_x * sum_x);

    // Calculate error
    double error = 0.0;
    for (const auto& point : dataset) {
        double x = point.first;
        double y = point.second;
        double predicted_y = a + b * x;
        error += pow(predicted_y - y, 2);
    }

    std::cout << "Linear curve fitting: y = " << a << " + " << b << "x, Error: " << error << "\n";
}

// Exponential curve fitting using the method of least squares
void exponentialCurveFitting() {
    double sum_x = 0.0, sum_y = 0.0, sum_x_squared = 0.0, sum_xy = 0.0, sum_y_log_y = 0.0;
    for (const auto& point : dataset) {
        double x = point.first;
        double y = point.second;
        sum_x += x;
        sum_y += y;
        sum_x_squared += x * x;
        sum_xy += x * y;
        sum_y_log_y += y * log(y);
    }

    double N = static_cast<double>(dataset.size());
    double c = (N * sum_xy - sum_x * sum_y) / (N * sum_x_squared - sum_x * sum_x);
    double b = exp((sum_y_log_y - sum_y * log(sum_y)) / (N * sum_y - sum_y));
    double a = (sum_y / N) - b * exp(c * (sum_x / N));

    // Calculate error
    double error = 0.0;
    for (const auto& point : dataset) {
        double x = point.first;
        double y = point.second;
        double predicted_y = a + b * exp(c * x);
        error += pow(predicted_y - y, 2);
    }

    std::cout << "Exponential curve fitting: y = " << a << " + " << b << " * exp(" << c << "x), Error: " << error << "\n";
}

int main() {
    linearCurveFitting();
    exponentialCurveFitting();

    return 0;
}
