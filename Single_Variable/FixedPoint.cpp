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
    double l = 10 / (4 + x);
    double m = sqrt(l);
    return m;
}
int main(){
    cout<<" y = x = (10/(4+x))^(1/2)"<<endl;
    int n;
    cout<<"enter the no. of step:"<<endl;
    cin>>n;
    cout<<"enter the no. of decimal digits:"<<endl;
    int d;
    cin>>d;
    cout<<"enter the guessed value:"<<endl;
    double s;
    cin>>s;
    while(n!=0){
        double k = f(s);
        cout<<setprecision(d+1)<<k<<endl;
        if(k==s){
            break;
        }
        s = k;
        n--;
    }
    return 0;
}
