// CPP program for implementing
// Newton divided difference formula
#include <bits/stdc++.h>
using namespace std;

// Function to find the product term
double proterm(int i, double value, double x[])
{
    float pro = 1;
    for (int j = 0; j < i; j++)
    {
        pro = pro * (value - x[j]);
    }
    return pro;
}

// Function for calculating
// divided difference table
void dividedDiffTable(double x[], double y[][10], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = (y[j][i - 1] - y[j + 1]
                                      [i - 1]) /
                      (x[j] - x[i + j]);
        }
    }
}

// Function for applying Newton's
// divided difference formula
double applyFormula(double value, double x[],
                   double y[][10], int n)
{
    double sum = y[0][0];

    for (int i = 1; i < n; i++)
    {
        sum = sum + (proterm(i, value, x) * y[0][i]);
    }
    return sum;
}

// Function for displaying
// divided difference table
void printDiffTable(double y[][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << setprecision(10) << y[i][j] << "\t ";
        }
        cout << "\n";
    }
}

// Driver Function
int main()
{
    // number of inputs given
    int n = 5;
    double value, sum, y[10][10];
    double x[] = {1, 1.3, 1.6, 1.9, 2.2};

    // y[][] is used for divided difference
    // table where y[][0] is used for input
    y[0][0] = 0.7651977;
    y[1][0] = 0.620086;
    y[2][0] = 0.4554022;
    y[3][0] = 0.2818186;
    y[4][0] = 0.1103623;

    // calculating divided difference table
    dividedDiffTable(x, y, n);

    // displaying divided difference table
    printDiffTable(y, n);

    // value to be interpolated
    value = 7;

    // printing the value
    cout << "\nValue at " << value << " is "
         << applyFormula(value, x, y, n) << endl;
    return 0;
}