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
    double x = y - pow(t,2) + 1;
    return x;
}
double Euler(double w, double t, double h){
    double k = w + h*f(w,t);
    return k;
}
int main(){
    double a,b,h,n,l,w;
    cout << "Time bound a and b respectively:(a<=t<=b)" << endl;
    cin >> a >> b;
    cout << "no. of steps in the interval:" << endl;
    cin >> n;
    cout<<"The value of the function at time = 0:(wo)"<<endl;
    cin>>w;
    h = (b-a)/n;
    double t = a;
    for(int i=0;i<n;i++){
        l = Euler(w,t,h);
        w = l;
        t += h;
        cout<<i+1<<"     "<<l<<endl;
    }
    return 0;
}
