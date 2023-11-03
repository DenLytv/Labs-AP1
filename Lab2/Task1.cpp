#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool isValidInput(double x, double y, double z);
void input(double& x, double& y, double& z);
double calculation(double x, double y, double z);

int main()
{
    double x = 0, y = 0, z = 0;
    input(x, y, z);
    while (isValidInput(x, y, z))
        input(x, y, z);
    /*x = 14.26;
    y = -1.22;
    z = 3.5 * pow(10, -2);*/
    printf("t = %lf", calculation(x, y, z));

    return 0;
}

bool isValidInput(double x, double y, double z)
{
    return (3 - pow(z, 2) / 5) != 0;
}


void input(double& x, double& y, double& z)
{
    char input[10];
    printf("Enter x: ");
    fgets(input, sizeof(input), stdin);
    x = strtod(input, NULL);
    printf("Enter y: ");
    fgets(input, sizeof(input), stdin);
    y = strtod(input, NULL);
    printf("Enter z: ");
    fgets(input, sizeof(input), stdin);
    z = strtod(input, NULL);
    if (isValidInput(x, y, z))
        printf("Error: 3 - z^2 / 5 = 0. Please make corrections.\n");
}

double calculation(double x, double y, double z)
{
    double t1 = 2 * cos(x - M_PI / 6), 
        t2 = (0.5 + pow(sin(y), 2)), 
        t3 = (1 + pow(z, 2) / (3 - pow(z, 2) / 5));
    return t1 / t2 * t3;
}