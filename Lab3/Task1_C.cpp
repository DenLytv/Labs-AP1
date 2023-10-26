#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
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
            printf("#%d\t\t", i + 1);
            printf("x = %lf\t\t", x);
            y = acos(cos(x));
            printf("y = %lf\n", y);
            sum += y;
            x += step;
        }
    }
    else if (num == 1) {
        while (i < N) {
            printf("#%d\t\t", i + 1);
            printf("x = %lf\t\t", x);
            y = acos(cos(x));
            printf("y = %lf\n", y);

            sum += y;
            x += step;
            i++;
        }
    }
    else {
        do {
            printf("#%d\t\t", i + 1);
            printf("x = %lf\t\t", x);
            y = acos(cos(x));
            printf("y = %lf\n", y);

            sum += y;
            x += step;
            i++;
        } while (i < N);
    }
    printf("\nsum = %lf\n\n", sum);
}