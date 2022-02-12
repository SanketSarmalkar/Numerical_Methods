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
double f(double x,double a,double b,double c,double d){
    double m = a*pow(x,3) + b*pow(x,2) + c*x + d;
    return m;
}
int main(){
    cout<<" y = ax^3 + bx^2 + cx + d"<<endl;
    int n;
    cout<<"enter the no. of step:"<<endl;
    cin>>n;
    double a,b,c,d,x,y,s1,s2;
    cout<<"enter the values of a,b,c,d respectively:"<<endl;
    cin>>a>>b>>c>>d;
    cout<<"enter the values of two points"<<endl;
    cin>>s1>>s2;    
    while(n!=0){
        double p = (s1 + s2) / 2;
        double m1 = f(s1, a, b, c, d);
        double m2 = f(s2, a, b, c, d);
        double l = f(p, a, b, c, d);
        cout<<p<<"  "<<l<<endl;
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
