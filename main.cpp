#include <cmath>
#include <iostream>
using namespace std;
#include "trapezoidal.hpp"

typedef double (*pfn) (double);


double C(double x, double a, double b){return x * ( x - ( (a+b-abs(a-b)) / 2 ) ) *( x - ( (a+b+abs(a-b)) / 2 ) ) ;};
double A(double x, double a, double b){return -a*b*x*x;};
double integrall(pfn f, double x0, double xbar){return trapezoidal(x0,xbar,f,100000);};

double V(double t0, double x0, double tf, double xbar, double a, double b, pfn f)
{
  return exp(-t0) * (A(x0,a,b) - exp(t0-tf)*A(xbar,a,b) + trapezoidal(x0,xbar,f,100000));
};
double C1(double x) {return x*(x-2)*(x-3);};
double C2(double x) {return x*(x-1)*(x-4);};
double C3(double x) {return x*(x-2)*(x-5);};
// double square (double x){return x*x;};

int main()
{
  double xbar; // Racine
  double t0; // Temps Initial
  double x0; // Valeur Initiale
  double tf; // Temps Final
  double a,b; // Valeurs numériques pour les trois cas
  double integral; // Valeur Trapezoidal de notre fonction donnée en entrée

  cout << "**** **** **** ****" << endl;
  cout << "Cas (a,b) = (2,3)" << endl;
  a = 2;
  b = 3;
  t0=0.0 ; x0 = -0.5 ; xbar = 1 ; tf = 2;
  integral = integrall(C1, x0, xbar);
  cout << "Le cas 1 pour la racine " << xbar << " est " << V(t0, x0, tf, xbar, a, b, C1)<<endl;
  t0=0.0 ; x0 = -0.5; xbar = 2; tf = 4;
  integral = integrall(C1, x0, xbar);
  cout << "Le cas 2 pour la racine " << xbar << " est " << V(t0, x0, tf, xbar, a,  b, C1)<<endl;
  t0=0.0 ; x0 = -0.5; xbar = 3; tf = 5;
  integral = integrall(C1, x0, xbar);
  cout << "Le cas 3 pour la racine " << xbar << " est " << V(t0, x0, tf, xbar, a,  b, C1)<<endl;
  getchar();

  cout << "**** **** **** ****" << endl;
  cout << "Cas (a,b) = (1,4)" << endl;
  a = 1;
  b = 4;
  integral = integrall(C2, x0, xbar);
  t0=0.0 ; x0 = -0.5; xbar = 0; tf = 4;
  cout << "Le cas 1 pour la racine " << xbar << " est " << V(t0, x0, tf, xbar, a, b, C2)<<endl;
  t0=0.0 ; x0 = -0.5; xbar = 1; tf = 4;
  cout << "Le cas 2 pour la racine " << xbar << " est " << V(t0, x0, tf, xbar, a,  b, C2)<<endl;
  t0=0.0 ; x0 = -0.5; xbar = 4; tf = 4;
  cout << "Le cas 3 pour la racine " << xbar << " est " << V(t0, x0, tf, xbar, a,  b, C2)<<endl;
  getchar();

  cout << "**** **** **** ****" << endl;
  cout << "Cas (a,b) = (2,5)" << endl;
  a = 2;
  b = 5;
  integral = integrall(C3, x0, xbar);
  t0=0.0 ; x0 = -0.5; xbar = 0; tf = 4;
  cout << "Le cas 1 pour la racine " << xbar << " est " << V(t0, x0, tf, xbar, a, b, C3)<<endl;
  t0=0.0 ; x0 = -0.5; xbar = 2; tf = 4;
  cout << "Le cas 2 pour la racine " << xbar << " est " << V(t0, x0, tf, xbar, a,  b, C3)<<endl;
  t0=0.0 ; x0 = -0.5; xbar = 5; tf = 4;
  cout << "Le cas 3 pour la racine " << xbar << " est " << V(t0, x0, tf, xbar, a,  b, C3)<<endl;
  getchar();

return 0;
}
