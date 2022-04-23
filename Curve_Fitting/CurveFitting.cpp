/*
Sanket S.Sarmalkar
Curve Fitting
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

int main()
{
   int n;
   cout<<"enter the no. of cases:"<<endl;
   cin>>n;
   double x[n];
   double sumx=0, squaresumx=0,cubesumx=0, mixedsumxy=0,forthsumx=0;
   cout<<"enter the x coordinates:"<<endl;
   for(int i=0;i<n;i++){
      cin>>x[i];
      sumx+=x[i];
      squaresumx += pow(x[i],2);
      cubesumx += pow(x[i],3);
      forthsumx += pow(x[i],4);

   }
   double y[n];
   double sumy = 0, squaresumy = 0, cubesumy = 0,forthsumy=0, mixedsumx2y=0;
   cout<<"enter the y coordinates:"<<endl;
   for(int i=0;i<n;i++){
      cin>>y[i];
      sumy += y[i];
      squaresumy += pow(y[i], 2);
      cubesumy += pow(y[i], 3);
      mixedsumxy += x[i]*y[i];
      forthsumy += pow(y[i],4);
      mixedsumx2y += pow(x[i],2)*y[i];
   }
   cout<<"sumx = "<<setprecision(5)<<sumx<<endl;
   cout << "squaresumx = " << setprecision(5) << squaresumx << endl;
   cout << "cubesumx = " << setprecision(5) << cubesumx << endl;
   cout << "sumy = " << setprecision(5) << sumy << endl;
   cout << "squaresumy = " << setprecision(5) << squaresumy << endl;
   cout << "cubesumy = " << setprecision(5) << cubesumy << endl;
   cout << "mixedsumxy = " << setprecision(5) << mixedsumxy << endl;
   cout << "mixedsumx2y = " << setprecision(5) << mixedsumx2y << endl;
   cout << "forthsumx = " << setprecision(5) << forthsumx << endl;
   cout << "forthsumy = " << setprecision(5) << forthsumy << endl;
   return 0;
}
