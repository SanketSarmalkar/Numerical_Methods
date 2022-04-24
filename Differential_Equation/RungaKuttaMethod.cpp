/*
Sanket S.Sarmalkar
Euler's Method
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
double k(double t,double h,double w){
    double x = h*(w-pow(t,2)+1);
    return x;
}
double Euler(double w, double t, double h, double o){
    double r;
    if (o == 2){
        double d1 = k(t,h,w);
        double d2 = k(t+h,h,w+d1);
        r = w + (0.5)*(d1 + d2);
    }
    if(o == 4){
        double d1 = k(t,h,w);
        double d2 = k(t+h/2,h,w+d1/2);
        double d3 = k(t+h/2,h,w+d2/2);
        double d4 = k(t+h,h,w+d3);
        r = w + (0.166666666667)*(d1 + 2*d2 + 2*d3 + d4);
    }
    return r;
}
int main(){
    double a, b, h, n, l, w, o;
    cout << "Time bound a and b respectively:(a<=t<=b)" << endl;
    cin >> a >> b;
    cout << "no. of steps in the interval:" << endl;
    cin >> n;
    cout << "The value of the (wo)function at time = 0:" << endl;
    cin >> w;
    cout << "Enter the order (2 or 4):" << endl;
    cin >> o;
    h = (b - a) / n;
    double t = a;
    for (int i = 0; i < n; i++){
        l = Euler(w, t, h, o);
        w = l;
        t += h;
        cout<<t<<"     "<<l<<endl;
    }
    return 0;
}