
#ifndef PONTO_H
#define PONTO_H

#include<math.h>

struct Ponto2D {
  double x;
  double y;

  Ponto2D(double x = 0.0, double y = 0.0);

  double calcular_distancia(Ponto2D* p);
};

#endif