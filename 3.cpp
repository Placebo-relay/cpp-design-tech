#include <iostream>
#include <cmath>
#include <limits>

double f(double x, double y) {
    return pow(y, 2) - pow(x, 2);
}

void modifiedEulerMethod(double x0, double y0, double h, double xn) {
    double x = x0;
    double y = y0;
    while (x < xn) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h, y + k1);
        y = y + 0.5 * (k1 + k2);
        x = x + h;
    }
    std::cout << "The approximate solution at x = " << xn << " is y = " << y << std::endl;
}

int main() {
    double x0, y0, h, xn;
    std::cout << "Enter the initial value of x (x0): ";
    while (!(std::cin >> x0)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid number for x0: ";
    }

    std::cout << "Enter the initial value of y (y0): ";
    while (!(std::cin >> y0)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid number for y0: ";
    }

    std::cout << "Enter the step size (h): ";
    while (!(std::cin >> h) || h <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid positive number for h: ";
    }

    std::cout << "Enter the value of x at which y is to be estimated (xn): ";
    while (!(std::cin >> xn)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid number for xn: ";
    }

    modifiedEulerMethod(x0, y0, h, xn);

    return 0;
}
