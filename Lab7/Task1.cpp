#include <iostream>
#include <cmath>
#include <string>
#include <exception>
#include "Task1.h"

int main() {
    double precision = 0.0;
    getPrecision(precision);
    double result = bisectionMethod(1, 3, precision);

    if (result != 0.0) {
        std::cout << "The root of the equation: " << result << std::endl;
    }

    return 0;
}

void getPrecision(double& precision) {
    do
    {
        std::cout << "Please enter the error range (<= 0.01): ";
        std::cin >> precision;
    } while (precision > 0.01);
}

double equation(double x) {
    return pow(2,x) - x - 2;
}

double bisectionMethod(double a, double b, double precision) {
    if (equation(a) * equation(b) >= 0) {
        std::cout << "There is no root on this interval." << std::endl;
        return 0.0;
    }
    double c = 0.0;
    while ((b - a) / 2 > precision) {
        c = (a + b) / 2;
        if (equation(c) == 0)
            return c;
        else if (equation(c) * equation(a) < 0)
            b = c;
        else
            a = c;
    }
    return (a + b) / 2;
}