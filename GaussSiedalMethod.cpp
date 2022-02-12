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
int main(){
    cout<<"enter the no. of variables:"<<endl;
    int n;
    cin>>n;
    double a[n][n];
    double b[n];
    cout<<"enter the elements in matrix A:"<<endl;
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           cin>>a[i][j];
       }
    }
    cout<<"enter the elements in matrix B:"<<endl;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    double g[n];
    cout<<"enter the guessed value for all variables:"<<endl;
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    cout<<"enter the no. of times we must simulate:"<<endl;
    int c;
    cin>>c;
    for(int i=0;i<c;i++){
        for(int j=0;j<n;j++){
            double x=0;
            for(int k=0;k<n;k++){
                if(k!=j){
                   x += a[j][k]*g[k];
                }
            }
            g[j]=(b[j]-x)/a[j][j];
            cout<<setprecision(10)<<g[j]<<" ";
        }
        cout<<endl;
    }
}