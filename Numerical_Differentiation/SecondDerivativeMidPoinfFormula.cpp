/*
Sanket S.Sarmalkar
Mid Point Formulas for Second Derivatives
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
double MidPointFormula(){
    double x, h;
    cout<<"enter the point at which we should find the first derivative:"<<endl;
    cin>>x;
    cout<<"value of h:"<<endl;
    cin>>h;
    double x1, x2, x3;
    cout<<"Enter the values of the function at the following points:"<<endl;
    cout<<endl<<"f("<<x+h<<") = ";
    cin>>x1;
    cout<<endl<<"f("<<x<<") = ";
    cin>>x2;
    cout<<endl<<"f("<<x-h<<") = ";
    cin>>x3;
    cout<<endl;
    double fder = (1 / pow(h,2)) * (x1 - 2*x2 + x3);
    cout<<"The value of first derivative at Xo = "<<x<<" using h = "<<h<<" is "<<fder<<endl;
}
int main(){
    MidPointFormula();
    return 0;
}