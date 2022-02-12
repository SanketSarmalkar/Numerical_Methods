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
double f(double x)
{
    double m = pow(x,3) - 2*x -5;
        return m;
}
int main()
{
    cout<<" y = cos(x) - x"<<endl;
    int n;
    cout<<"enter the no. of step:"<<endl;
    cin>>n;
    cout<<"enter the no. of decimal digits:"<<endl;
    int d;
    cin>>d;
    cout<<"enter the values of two points"<<endl;
    double s1,s2;
    cin>>s1>>s2;
    while (n!=0){
        double p = (s1*f(s2) - s2*f(s1)) / (f(s2)-f(s1));
        double m1 = f(s1);
        double m2 = f(s2);
        double l = f(p);
        cout<<setprecision(d)<<p<<endl;
        if (m1*l > 0){
            s1 = p;
        }
        else if (m2*l > 0){
            s2 = p;
        }
        else if (l==0){
            cout << p << endl;
            break;
        }
        n--;
    }
    return 0;
}
