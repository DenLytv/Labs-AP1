#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#define N 11

void calculation(double step, int num);

int main()
{
    double step = (M_PI / 2 - (-M_PI / 2)) / N;
    calculation(step, 0);
    calculation(step, 1);
    calculation(step, 2);

    return 0;
}

void calculation(double step, int num) {
    int i = 0;
    double sum = 0, x = 0.0, y = 0;
    if (num == 0) {
        for (; i < N; i++) {
            std::cout << "#" << i + 1 << "\t\t";
            std::cout << "x = " << x << "\t\t";
            if (i == 0)
                std::cout << "\t";
            y = acos(cos(x));
            std::cout << "y = " << y << std::endl;
            sum += y;
            x += step;
        }
    }
    else if (num == 1) {
        while (i < N) {
            std::cout << "#" << i + 1 << "\t\t";
            std::cout << "x = " << x << "\t\t";
            if (i == 0)
                std::cout << "\t";
            y = acos(cos(x));
            std::cout << "y = " << y << std::endl;

            sum += y;
            x += step;
            i++;
        }
    }
    else {
        do {
            std::cout << "#" << i + 1 << "\t\t";
            std::cout << "x = " << x << "\t\t";
            if (i == 0)
                std::cout << "\t";
            y = acos(cos(x));
            std::cout << "y = " << y << std::endl;

            sum += y;
            x += step;
            i++;
        } while (i < N);
    }
    std::cout << "\nsum = " << sum << std::endl << std::endl;
}