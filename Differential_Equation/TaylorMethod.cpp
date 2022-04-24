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
double f(double y, double t){
    double x = y - pow(t, 2) + 1;
    return x;
}
double fder(double y, double t){
    double x = y - pow(t, 2) + 1 - 2*t;
    return x;
}
double fderder(double y, double t){
    double x = y - pow(t, 2) - 1 - 2*t;
    return x;
}
double fderderder(double y, double t){
    double x = y - pow(t, 2) - 1 - 2*t;
    return x;
}
double Euler(double w, double t, double h, double o){
    double k;
    if(o==2){
        k = w + h*f(w,t) + (pow(h,2)/2)*fder(w,t);
    }
    else if(o==4){
        k = w + h*f(w,t) + (pow(h,2)/2)*fder(w,t) + (pow(h,3)/6)*fderder(w,t) + (pow(h,4)/24)*fderderder(w,t);
    }
    return k;
}
int main(){
    double a, b, h, n, l, w,o;
    cout << "Time bound a and b respectively:(a<=t<=b)" << endl;
    cin >> a >> b;
    cout << "no. of steps in the interval:" << endl;
    cin >> n;
    cout << "The value of the function at time = 0:(wo)" << endl;
    cin >> w;
    cout<<"Enter the order (2 or 4):"<<endl;
    cin>>o;
    h = (b - a) / n;
    double t = a;
    for (int i = 0; i < n; i++){
        l = Euler(w, t, h,o);
        w = l;
        t += h;
        cout<<t<<"     "<<setprecision(8)<<l<<endl;
    }
    return 0;
}