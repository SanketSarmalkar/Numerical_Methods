/*
Sanket S.Sarmalkar
Modified Newton's Method
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
double fderder(double x){
    double h = exp(x);
    return h;
}
double fder(double x){
    double h = exp(x)-1;
    return h;
}
double f(double x){
    double l = exp(x) - x -1;
    return l;
}
double NM(double p){
    double p1 = p - ((f(p)*fder(p)) / (pow(fder(p),2)-f(p)*fderder(p)));
    return p1;
}
int main(){
    cout<<"y = x = e^x -x -1"<<endl;
    int n;
    cout<<"enter the no. of step:"<<endl;
    cin>>n;
    cout<<"enter the no. of decimal digits:"<<endl;
    int d;
    cin>>d;
    cout<<"enter the initial guess:"<<endl;
    double s;
    cin>>s;
    while (n!=0){
        double k = NM(s);
        cout<<setprecision(d+1)<<k<<endl;
        s = k;
        n--;
    }
    return 0;
}
