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
double d(double p0,double p1,double p2){
    double p = p0 - (pow(p1-p0,2))/(p2 -2*p1 +p0);
    return p;
}
double f(double x){
    double l = 10 / (4 + x);
    double m = sqrt(l);
    return m;
}
int main(){
    cout<<"y = x = (10/(4+x))^(1/2)"<<endl;
    int n;
    cout<<"enter the no. of step:"<<endl;
    cin>>n;
    cout<<"enter the no. of decimal digits:"<<endl;
    int t;
    cin>>t;
    cout<<"enter the guessed value:"<<endl;
    double p0;
    cin>>p0;
    while (n!=0){
        double p1 = f(p0);
        double p2 = f(p1);
        double s = d(p0,p1,p2);
        cout<<setprecision(t+1)<<s<<endl;
        p0=s;
        n--;
    }
    return 0;
}
