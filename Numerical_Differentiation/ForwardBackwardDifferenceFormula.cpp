/*
Sanket S.Sarmalkar
Forward Difference Formula
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
    double y = log(x);
    return y;
}
double ForwardDifferenceFormula(double x, double h){
    double fder = (f(x + h) - f(x)) / h;
    cout<<"The value of first derivative at Xo = "<<x<<" using h = "<<h<<" is "<<fder<<endl;
}
int main(){
    double x,h;
    cout<<"enter the point at which we should find the first derivative:"<<endl;
    cin>>x;
    cout<<"value of h:"<<endl;
    cin>>h;
    ForwardDifferenceFormula(x,h);
    return 0;
}
