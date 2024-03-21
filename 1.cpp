#include <iostream>
#include <cmath>

double f(double x) {
    return exp(3.0) * x * pow(x + 1, 0.2);
}

double midpointRectangles(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double x_mid = a + (i + 0.5) * h;
        sum += f(x_mid);
    }
    return h * sum;
}

double simpsonsRule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i += 2) {
        double x = a + i * h;
        sum += 4 * f(x);
    }
    for (int i = 2; i < n - 1; i += 2) {
        double x = a + i * h;
        sum += 2 * f(x);
    }
    return h * sum / 3;
}

int main() {
    double a, b;
    int n;
    std::cout << "Enter the lower bound (a): ";
    std::cin >> a;
    std::cout << "Enter the upper bound (b): ";
    std::cin >> b;
    if (a >= b) {
        std::cout << "Error: Lower bound must be less than upper bound." << std::endl;
        return 1;
    }
    std::cout << "Enter the number of subintervals (n): ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Error: Number of subintervals must be positive." << std::endl;
        return 1;
    }
    if (std::isnan(a) || std::isnan(b) || std::isnan(n)) {
        std::cout << "Error: Input must be a valid number." << std::endl;
        return 1;
    }
    if (std::isinf(a) || std::isinf(b) || std::isinf(n)) {
        std::cout << "Error: Input must not be infinity." << std::endl;
        return 1;
    }
    double result_midpoint = midpointRectangles(a, b, n);
    double result_simpson = simpsonsRule(a, b, n);
    double analytical_solution = (exp(3) * pow(b + 1, 1.2) * (30 * b - 25) - exp(3) * pow(a + 1, 1.2) * (30 * a - 25)) / 66;
    std::cout << "The result of the integration using midpoint rectangles method is: " << result_midpoint << std::endl;
    std::cout << "The result of the integration using Simpson's rule method is: " << result_simpson << std::endl;
    std::cout << "The analytical solution of the integration is: " << analytical_solution << std::endl;
    return 0;
}
