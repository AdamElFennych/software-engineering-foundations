#include <iostream>
using namespace std;
int main()
{
    float PI = 3.14159265;
    // Precision Specification
    printf("Precision Specification of %.*f \n", 1, PI);
    printf("Precision Specification of %.*f \n", 2, PI);
    printf("Precision Specification of %.*f \n", 3, PI);
    printf("Precision Specification of %.*f \n", 4, PI);

    float x = 7.0439, y = 9.0;
    printf("\n The float division is %.3f/%.3f = %.3f \n\n", x, y, x / y);

    double d = 12.45;
    printf("The double value is %.3f \n", d);
    printf("The double value is %.4f \n", d);
}
