/*
Sanket S.Sarmalkar
Bisection method
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
    double m = pow(x,3) -1*x -1;
    return m;
}
int main(){
    cout<<" y = ax^3 + bx^2 + cx + d"<<endl;
    int n;
    cout<<"enter the no. of step:"<<endl;
    cin>>n;
    int z = n;
    double s1,s2;
    cout<<"enter the values of two points"<<endl;
    cin>>s1>>s2;    
    while(n!=0){
        double p = (s1 + s2) / 2;
        double m1 = f(s1);
        double m2 = f(s2);
        double l = f(p);
        cout<<"n    a         b          f(a)           f(b)            p              f(p)"<<endl;
        cout<<z+1-n<<"    "<<s1<<"    "<<s2<<"    "<<m1<<"    "<<m2<<"    "<<p<<"    "<<l<<endl;
        if (m1 * l > 0){
            s1 = p;
        }
        else if(m2*l>0){
            s2 = p;
        }
        else if(l==0){
            cout<<p<<endl;
            break;
        }
        n--;
    }
    return 0;
}
