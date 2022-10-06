#include "Triangulo.hpp"

Triangulo::Triangulo(Ponto2D p1, Ponto2D p2, Ponto2D p3){
  this->p1 = Ponto2D(p1.x, p1.y);
  this->p2 = Ponto2D(p2.x, p2.y);
  this->p3 = Ponto2D(p3.x, p3.y);
}

double Triangulo::calcular_perimetro(){
  double a = this->p1.calcular_distancia(&this->p2);
  double b = this->p2.calcular_distancia(&this->p3);
  double c = this->p3.calcular_distancia(&this->p1);

  return a + b + c;
}

double calc_p(Triangulo* t){
  return t->calcular_perimetro() / 2;
}

double Triangulo::calcular_area(){
  double p = calc_p(this);
  return sqrt(p*( p - this->p1.calcular_distancia(&this->p2))*( p - this->p2.calcular_distancia(&this->p3))*( p - this->p3.calcular_distancia(&this->p1)));
}

int Triangulo::comparar_area(Triangulo* t){
  double area_atual = this->calcular_area();
  double area_info = t->calcular_area();

  if(area_atual < area_info){
    return -1;
  }else if(area_atual == area_info){
    return 0;
  }else{
    return 1;
  }
}