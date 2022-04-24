/*
Sanket S.Sarmalkar
Trapezoidal Rule n=1
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
    double a, b, n;
    cout<<"value of limits a and b respectively:"<<endl;
    cin>>a>>b;
    cout<<"no. of spaces in the interval (n = 1) :"<<endl;
    cin>>n;
    double h = (b-a)/n;
    double Fint = (h/2)*(f(a) + f(a+h));
    cout<<"The value of Intergral of the function is = "<<Fint<<endl;
    return 0;
}
