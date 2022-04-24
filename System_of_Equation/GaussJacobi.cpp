/*
Sanket S.Sarmalkar
Gauss Jacobi Method
*/
#include <stdio.h>
#include <iostream>
#include <limits>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
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
    int n;
    double x10 = 0, x20 = 0, x30 = 0, x40 = 0, x11, x21, x31, x41;
    cout << "Enter the no. of variables:" << endl;
    cin >> n;
    double a[n][n];
    cout << "Enter the Equation matrix (A):" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    cout << "Enter the B matrix:" << endl;
    double b[n];
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    double guess[n], g[n];
    cout << "Enter the guess values of the variables respectively:" << endl;
    for (int i = 0; i < n; i++){
        cout << "guess value for variable " << i + 1<<": ";
        cin >> guess[i];
    }
    for (int i = 0; i < n; i++)
    {
        g[i] = 0;
    }
    int c;
    cout << "enter the no. of iterations:" << endl;
    cin >> c;
    for (int i = 0; i < c; i++){
        cout<<i+1<<"   ";
        for (int j = 0; j < n; j++){
            double x = 0;
            for (int k = 0; k < n; k++){
                if (k != j){
                    x += a[j][k] * guess[k];
                }
            }
            g[j] = (b[j] - x) / a[j][j];
            cout << setprecision(10) << g[j] << " ";
        }
        for(int h=0;h<n;h++){
            guess[h]=g[h];
        }
        cout << endl;
    }
    return 0;
}
