/*
Sanket S.Sarmalkar
Simpson's Rule
*/
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
double f(double x){
    double y = sin(x);
    return y;
}

int main(){
    double a, b, n, Fint;
    cout << "value of limits a and b respectively:" << endl;
    cin >> a >> b;
    cout << "no. of spaces in the interval (n = 2 or 3) :" << endl;
    cin >> n;
    double h = (b - a) / n;
    if(n==2){   // Simpson's 1/3 rule
       Fint = (h/3)*(f(a) + 4*f(a+h) + f(a+2*h));
    }
    else if(n==3){   // Simpson's 3/8 rule
        Fint = (3*h/8)*(f(a) + 3*f(a+h) + 3*f(a+2*h) + f(a+3*h));
    }
    cout << "The value of Intergral of the function is = " << Fint << endl;
    return 0;
}
