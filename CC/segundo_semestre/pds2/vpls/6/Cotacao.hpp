#ifndef COTACAO_H
#define COTACAO_H

#include <iostream>
#include <string>

struct Cotacao{
  std::string data;
  double valor;

  Cotacao(std::string data = "", double valor = 0.0);

  void set_data(std::string data);
  std::string get_data();
  void set_valor(double valor);
  double get_valor();
};

#endif