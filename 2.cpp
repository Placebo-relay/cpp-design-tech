#include <iostream>
#include <cmath>
#include <limits>

// Define the function to find the root
double f(double x) {
    return pow(x, 3) + cos(x / M_PI);
}

// Define the derivative of the function
double f_prime(double x) {
    return 3 * pow(x, 2) - (1 / M_PI) * sin(x / M_PI);
}

// Implement the Newton-Raphson method
double newtonRaphson(double initial_guess, double tolerance, int max_iterations) {
    double x = initial_guess;
    int iterations = 0;

    while (iterations < max_iterations) {
        double x_next = x - f(x) / f_prime(x);
        if (std::abs(x_next - x) < tolerance) {
            return x_next;
        }
        x = x_next;
        iterations++;
    }

    // If max_iterations is reached without meeting the tolerance, return the current approximation
    return x;
}

int main() {
    double initial_guess;
    double tolerance;
    int max_iterations;

    // Input validation for initial guess
    std::cout << "Enter the initial guess: ";
    while (!(std::cin >> initial_guess)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid number for the initial guess: ";
    }

    // Input validation for tolerance
    std::cout << "Enter the tolerance: ";
    while (!(std::cin >> tolerance) || tolerance <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid positive number for the tolerance: ";
    }

    // Input validation for maximum iterations
    std::cout << "Enter the maximum number of iterations: ";
    while (!(std::cin >> max_iterations) || max_iterations <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid positive integer for the maximum number of iterations: ";
    }

    double root = newtonRaphson(initial_guess, tolerance, max_iterations);

    std::cout << "The root of the function is: " << root << std::endl;

    return 0;
}
