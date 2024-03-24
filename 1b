#include <iostream>
#include <boost/math/quadrature/trapezoidal.hpp>
#include <boost/math/quadrature/simpson.hpp>
#include <boost/math/quadrature/gauss_kronrod.hpp>
#include <boost/math/quadrature/adaptive.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/math/tools/roots.hpp>

double f(double x) {
    return boost::math::exp(3.0) * x * boost::math::pow(x + 1, 0.2);
}

double parseInput(const std::string& input) {
    if (input.find("pi") != std::string::npos) {
        size_t pos = input.find("pi");
        double multiplier = 1.0;
        if (pos != 0) {
            multiplier = std::stod(input.substr(0, pos));
        }
        return multiplier * boost::math::constants::pi<double>();
    } else {
        return std::stod(input);
    }
}

int main() {
    std::string lower_bound_input, upper_bound_input;
    int n;
    std::cout << "Enter the lower bound (e.g., 4pi or just 4): ";
    std::cin >> lower_bound_input;
    std::cout << "Enter the upper bound (e.g., 4pi or just 4): ";
    std::cin >> upper_bound_input;
    double a = parseInput(lower_bound_input);
    double b = parseInput(upper_bound_input);
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

    // Numerical integration using different methods
    double result_trapezoidal = boost::math::quadrature::trapezoidal(f, a, b, n);
    double result_simpson = boost::math::quadrature::simpson(f, a, b, n);
    double result_gauss_kronrod = boost::math::quadrature::gauss_kronrod<double, 15>::integrate(f, a, b);
    double result_adaptive = boost::math::quadrature::adaptive(f, a, b, 1e-6);

    // Analytical solution using root finding
    auto analytical_solution_func = [a, b](double x) {
        return (boost::math::exp(3) * boost::math::pow(x + 1, 1.2) * (30 * x - 25)) / 66;
    };
    double analytical_solution = boost::math::tools::toms748_solve(analytical_solution_func, a, b);

    std::cout << "The result of the integration using trapezoidal method is: " << result_trapezoidal << std::endl;
    std::cout << "The result of the integration using Simpson's rule method is: " << result_simpson << std::endl;
    std::cout << "The result of the integration using Gauss-Kronrod method is: " << result_gauss_kronrod << std::endl;
    std::cout << "The result of the integration using adaptive quadrature method is: " << result_adaptive << std::endl;
    std::cout << "The analytical solution of the integration is: " << analytical_solution << std::endl;
    return 0;
}
