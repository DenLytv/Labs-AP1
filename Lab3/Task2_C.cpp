#include <stdio.h>
#include <math.h>

double getX();
double getE();
int faktorial(int k);
double calculateY(double x);
double calculateS(double x, double e);

int main() {


    double x = getX();
    double e = getE();

    double y = calculateY(x);
    double s = calculateS(x, e);

    printf("Y(x) = %lf\nS(x) = %lf\n", y, s);
    printf("|S(x) - Y(x)| = %lf\n", fabs(s - y));

    return 0;
}

double getX() {
    double x = 0.0;
    do {
        printf("Please enter x(0 < x < 1) : ");
        scanf_s("%lf", &x);
    } while (fabs(x) >= 1 || x == 0);
    return x;
}

double getE() {
    double e = 0.0;
    do
    {
        printf("Please enter the error range -- e < 0.0001 : ");
        scanf_s("%lf", &e);
    } while (e >= 0.0001);
    return e;
}

int faktorial(int k) {
    if (k <= 1)
        return 1;
    else
        return (k * faktorial(k - 1));
}

double calculateY(double x) {
    return sin(x);
}

double calculateS(double x, double e) {
    double a = 0.0, b = 0.0;
    int k = 0;
    do {
        b = pow(-1, k) * (pow(x, 2 * k + 1) / faktorial(2 * k + 1));
        a += b;
        k++;
    } while (b <= e);
    return a;
}