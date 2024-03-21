#include <iostream>
#include <vector>
#include <cmath>

// Define the dataset
std::vector<std::pair<double, double>> dataset = {{1.2, -2.7}, {1.6, -1.5}, {2.1, -0.7}, {2.3, -0.1}, {2.9, 0.9}};

// Nearest neighbor interpolation method
double nearestNeighborInterpolation(double x) {
    double minDist = std::abs(x - dataset[0].first);
    double result = dataset[0].second;
    for (const auto& point : dataset) {
        double dist = std::abs(x - point.first);
        if (dist < minDist) {
            minDist = dist;
            result = point.second;
        }
    }
    return result;
}

// Lagrange polynomial interpolation method
double lagrangeInterpolation(double x) {
    double result = 0.0;
    for (size_t i = 0; i < dataset.size(); ++i) {
        double term = dataset[i].second;
        for (size_t j = 0; j < dataset.size(); ++j) {
            if (j != i) {
                term *= (x - dataset[j].first) / (dataset[i].first - dataset[j].first);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    // Calculate the step
    size_t N = dataset.size();
    double min_x = dataset[0].first;
    double max_x = dataset[N - 1].first;
    double step = (max_x - min_x) / (N - 1);

    // Interpolate and print the data points
    std::cout << "x\tNearest Neighbor\tLagrange Polynomial\n";
    for (double x = min_x; x <= max_x; x += step) {
        double nn_result = nearestNeighborInterpolation(x);
        double lagrange_result = lagrangeInterpolation(x);
        std::cout << x << "\t" << nn_result << "\t\t" << lagrange_result << "\n";
    }

    return 0;
}
