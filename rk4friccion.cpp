// RK4
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// variable constantes globales
const int N = 2;
const double K = 100;
const double M = 2;
const double LAMBDA = 1;
const double DeltaT = 0.01;
const double b=0.6; //coeficiente de fricción

// declaracion de funciones
double f(double t, double y[], int i);
double f0(double t, double y0, double y1); // derivada de y0
double f1(double t, double y0, double y1); // derivada de y1
void rk4(double t, double h, double & y0, double & y1); // metodo de runge kutta 4 orden


int main(void)
{
  ofstream fout("datos-arrayfriccion.txt");
  double x = 1, v = 0;
  double time;
  for(time = 0; time <= 10; time += DeltaT) {
    fout << time << "\t" << x << "\t" << v << endl;
    rk4(time, DeltaT, x, v);
    
  }
fout.close();

  return 0;
}

double f(double t, double y[], int i)
{
  if (0 == i) {
    return y[1];
  }
  else if (1 == i) {
    return (-K/M)*pow(y[0], LAMBDA);
  }
  else {
    std::cerr << "ERROR. Asking unexistent function f, with i = " <<  i << std::endl;
  }
}

double f0(double t, double y0, double y1)
{
  return y1;
}

double f1(double t, double y0, double y1)
{
  return (-K/M)*pow(y0, LAMBDA)+(-b*y1);
}




void rk4(double t, double h, double & y0, double & y1) // metodo de runge kutta 4 orden
{
  double k10, k11, k20, k21, k30, k31, k40, k41;
  k10 = h*f0(t, y0, y1);
  k11 = h*f1(t, y0, y1);
  k20 = h*f0(t+h/2, y0 + k10/2, y1 + k11/2);
  k21 = h*f1(t+h/2, y0 + k10/2, y1 + k11/2);
  k30 = h*f0(t+h/2, y0 + k20/2, y1 + k21/2);
  k31 = h*f1(t+h/2, y0 + k20/2, y1 + k21/2);
  k40 = h*f0(t + h, y0 + k30, y1 + k31);
  k41 = h*f1(t + h, y0 + k30, y1 + k31);

  y0 = y0 + (1.0/6.0)*(k10 + 2*k20 + 2*k30 + k40);
  y1 = y1 + (1.0/6.0)*(k11 + 2*k21 + 2*k31 + k41);
}