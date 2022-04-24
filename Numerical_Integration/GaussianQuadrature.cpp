/*
Sanket S.Sarmalkar
Guassian Quadrature
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
    double y = pow(x,6) - pow(x,2)*sin(2*x);
    return y;
}
double standardF(double x, double a, double b){
    double k = f(((b-a)*x + (b+a))/2) * ((b-a)/2);
    return k;
}
int main(){
    double a, b, n, Fint;
    cout << "value of limits a and b respectively:" << endl;
    cin >> a >> b;
    cout << "no. of spaces in the interval (n = 2 or 3):" << endl;
    cin >> n;
    double h = (b - a) / n;
    if (n==2){
        Fint = standardF(-1/sqrt(3),a,b) + standardF(1/sqrt(3),a,b);
    }
    else if (n==3){
        Fint = 0.55555556*standardF(0.7745966692,a,b) + 0.88888889*standardF(0,a,b) + 0.55555556*standardF(-0.7745966692,a,b);
    }
    cout << "The value of Intergral of the function is = " << Fint << endl;
    return 0;
}
