#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool isValidInput(double x);

int main()
{
    char input[10];
    double x = 0.0, z = 0.0;
    printf("Please enter a value for 'z': ");
    fgets(input, sizeof(input), stdin);
    z = strtod(input, NULL);

    if (z < 1)
        x = pow(z, 2);
    else
        x = z + 1;

    if (isValidInput(x)) {
        double y1 = log(1 + pow(x, 1.0 / 5.0)),
            y2 = pow(cos(x + 1), 2);
        printf("y = %lf", y1 + y2);
    }
    else
        printf("Invalid input!");

    return 0;
}


bool isValidInput(double x)
{
    return (1 + pow(x, 1.0 / 5.0)) > 0;
}