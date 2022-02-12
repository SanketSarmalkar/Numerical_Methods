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
    double l = 3*x - cos(x) - 1;
    return l;
}
double SM(double p0,double p1){
    double d = p1 - ((f(p1)*(p1-p0))/(f(p1)-f(p0)));
    return d;
}
int main(){
    cout<<"3x = cos(x) + 1"<<endl;
    int n;
    cout<<"enter the no. of step:"<<endl;
    cin >> n;
    cout<<"enter the no. of decimal digits:"<<endl;
    int d;
    cin>>d;
    cout<<"enter the first guess(P_o) :"<<endl;
    double p0;
    cin>>p0;
    cout<<"enter the second guess(P_1)"<<endl;
    double p1;
    cin>>p1;
    while (n!=0){
        double k = SM(p0,p1);
        cout<<setprecision(d+1)<<k<<endl;
        p0 = p1;
        p1 = k;
        n--;
    }
    return 0;
}
