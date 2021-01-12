// This code is written to calculate the magnitude of magnetic field in the vicinity of the square Helmholtz coil
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cstdio>
#include "TGraph.h"
#include <iostream>
#include<math.h>
#include "TH2.h"
#include "TMath.h"
using namespace std;

void Graph(){

  double  x, dx;
  double y, dy;
  double constant,z,L;
  constant=1;
  dx=0.1;
  dy=0.1;
  z=10;
  L=1;
  vector<double>myvector;
  vector<double>myxposition;
  vector<double>myyposition;
  for (x=0.01; x<0.4; x+=dx){
    myxposition.push_back(x);}
  for (y=0.01; y<0.4; y+=dy){
    myyposition.push_back(y);}
  for(x=0.1; x<0.4; x+=dx){
    for(y=0.1;y<0.4; y+=dy){
      double   k=constant*(x*y);
      myvector.push_back(k);
    
      
    }

  }



  
  int n=myvector.size();
  double B[n];
  double P[n];
  double T[n];
  TH2D* h = new TH2D("MagnetPlot","The magnitude of the magnetic feild produced by the coils ; X;Y",50,0,50,50,0,50);
  for(int i=0; i<myxposition.size();i++){P[i]=myxposition.at(i);}
  for(int i=0;i<myyposition.size();i++){T[i]=myyposition.at(i);}
  for (int i=0;i<myvector.size();i++){
    B[i]=myvector.at(i);
    cout<<B[i]<<endl;
  }
  // Calculation of the magnetic field caused by a wire
  double_t B1,B2,B3,B4,B_total;
  double I=1;
  double l=50;
  double Pi=3.14;
  int N=100;
  double mu_0=1.25663743*pow(10,-6);
  for(int x=1;x<50; x++){
 
    for(int y=1; y<50; y++){
    
      B1=(mu_0*I*N/4*Pi*sqrt(pow(y,2)+pow(z,2)))*(sin(atan(sqrt(pow(x,2)+pow(y,2))/z))+sin(atan(sqrt(pow((l-x),2)+pow(y,2))/z)));
      B2=(mu_0*I*N/4*Pi*sqrt(pow((l-x),2)+pow(z,2)))*(sin(atan(sqrt(pow(y,2)+pow((l-x),2)))/z)+sin(atan(sqrt(pow((l-y),2)+pow((l-x),2))/z)));
      B3=(mu_0*I*N/4*Pi*sqrt(pow((l-y),2)+pow(z,2)))*(sin(atan(sqrt(pow((l-x),2)+pow((l-y),2))/z))+sin(atan(sqrt(pow(x,2)+pow((l-y),2))/z)));
      B4=(mu_0*I*N/4*Pi*sqrt(pow(x,2)+pow(z,2)))*(sin(atan(sqrt(pow((l-y),2)+pow(x,2)))/z)+sin(atan(sqrt(pow(y,2)+pow(x,2))/z)));
      B_total=B1+B2+B3+B4;
 
	  h->Fill(x,y,B_total);
	  }
    }
    h->Draw("colz");
  }
