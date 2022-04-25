/*
Sanket S.Sarmalkar
Point Formulas for first Derivatives
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
void ThreePointEndPointFormula(){
    double x, h;
    cout<<"enter the point at which we should find the first derivative:"<<endl;
    cin>>x;
    cout<<"value of h:"<<endl;
    cin>>h;
    double x1,x2,x3;
    cout<<"Enter the values of the function at the following points:"<<endl;
    cout<<"f("<<x<<") = ";
    cin>>x1;
    cout<<endl<<"f("<<x+h<<") = ";
    cin>>x2;
    cout<<endl<<"f("<<x+2*h<<") = ";
    cin>>x3;
    cout<<endl;
    double fder = (1/(2*h))*(-3*x1 + 4*x2 - x3);
    cout<<"The value of first derivative at Xo = "<<x<<" using h = "<<h<<" is "<<fder<<endl;
}
void ThreePointMidPointFormula(){
    double x, h;
    cout<<"enter the point at which we should find the first derivative:" << endl;
    cin>>x;
    cout<<"value of h:" << endl;
    cin>>h;
    double x1, x2;
    cout<<"Enter the values of the function at the following points:" << endl;
    cout<<endl<< "f(" << x + h << ") = ";
    cin>>x1;
    cout<<endl<< "f(" << x - h << ") = ";
    cin>>x2;
    cout<<endl;
    double fder = (1/(2*h))*(x1 - x2);
    cout<<"The value of first derivative at Xo = "<<x<<" using h = "<<h<<" is "<<fder<<endl;
}
void FivePointMidPointFormula(){
    double x, h;
    cout << "enter the point at which we should find the first derivative:" << endl;
    cin >> x;
    cout << "value of h:" << endl;
    cin >> h;
    double x1, x2 ,x3 ,x4;
    cout<<"Enter the values of the function at the following points:" << endl;
    cout<<endl<< "f("<<x + 2*h<<") = ";
    cin>>x1;
    cout<<endl<<"f("<<x + h<<") = ";
    cin>>x2;
    cout<<endl<< "f("<<x - h<<") = ";
    cin>>x3;
    cout<<endl<< "f("<<x-2*h<<") = ";
    cin>>x4;
    cout<<endl;
    double fder = (1/(12*h))*(x4-8*x3+8*x2-x1);
    cout<<"The value of first derivative at Xo = " << x << " using h = " << h << " is " <<setprecision(7)<< fder << endl;
}
void FivePointEndPointFormula(){
    double x, h;
    cout<<"enter the point at which we should find the first derivative:"<<endl;
    cin>>x;
    cout<<"value of h:"<<endl;
    cin>>h;
    double x1, x2, x3, x4, x5;
    cout<<"Enter the values of the function at the following points:"<<endl;
    cout<<endl<< "f("<<x<<") = ";
    cin>>x1;
    cout<<endl<< "f("<< x + h <<") = ";
    cin>>x2;
    cout<<endl<< "f("<< x + 2*h<<") = ";
    cin>>x3;
    cout<<endl<< "f("<< x + 3 * h <<") = ";
    cin>>x4;
    cout<<endl<< "f("<< x + 4 * h <<") = ";
    cin>>x5;
    cout<<endl;
    double fder = (1/(12*h))*(-25*x1 + 48*x2 - 36*x3 + 16*x4 -3*x5);
    cout<<"The value of first derivative at Xo = "<<x<<" using h = "<<h<<" is "<<fder<<endl;
}
int main(){
    cout<<"Choose a Formula to find the Value of a perticular point:"<<endl;
    cout<<"Three - Point Endpoint Formula:             1"<<endl;
    cout<<"Three - Point Midpoint Formula:             2"<<endl;
    cout<<"Five - Point Endpoint Formula:              3"<<endl;
    cout<<"Five - Point Midpoint Formula:              4"<<endl;
    int choice;
    cin>>choice;
    if(choice==1){
        ThreePointEndPointFormula();
    }
    if(choice==2){
        ThreePointMidPointFormula();
    }
    if(choice==3){
        FivePointEndPointFormula();
    }
    if(choice==4){
        FivePointMidPointFormula();
    }
    return 0;
}