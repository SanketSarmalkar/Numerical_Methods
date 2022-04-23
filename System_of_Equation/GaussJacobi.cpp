#include <iostream>
#include <iomanip>
#include <math.h>

#define f1(x1,x2,x3,x4) (6 + x2 -2*x3) / 10
#define f2(x1,x2,x3,x4) (25 +x1 +x3 - 3 * x4) / 11
#define f3(x1,x2,x3,x4) (-11 -2*x1 + x2 + x4) / 10
#define f4(x1, x2, x3, x4) (15 - 3 * x2 + x3) / 8

using namespace std;

/* Main function */
int main()
{
    double x10 = 0, x20 = 0, x30 = 0,x40=0, x11, x21, x31, x41;
    int step = 1;

    /* Setting precision and writing floating point values in fixed-point notation. */
    cout << setprecision(6) << fixed;

    /* Input */
    /* Reading tolerable error */
    int n;
    cout<<"enter the no. of iterations"<<endl;
    cin>>n;

    cout << endl
         << "Count\tx1\t\tx2\t\tx3\t\tx4" << endl;
    do
    {
        /* Calculation */
        x11 = f1(x10, x20, x30, x40);
        x21 = f2(x10, x20, x30, x40);
        x31 = f3(x10, x20, x30, x40);
        x41 = f4(x10, x20, x30, x40);
        cout << step << "\t" << x11 << "\t" << x21 << "\t" << x31 <<"\t"<<x41<< endl;

        
        step++;

        /* Set value for next iteration */
        x10 = x11;
        x20 = x21;
        x30 = x31;
        x40 = x41;
    } while (step!=n+1);

    cout << endl
         << "Solution: x = " << x11 << ", y = " << x21 << " and z = " << x31;
    return 0;
}
