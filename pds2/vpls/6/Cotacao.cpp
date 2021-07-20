#include "Cotacao.hpp"

Cotacao::Cotacao(std::string data, double valor){
  this->set_data(data);
  this->set_valor(valor);
}

void Cotacao::set_data(std::string data){
  this->data = data;
}

std::string Cotacao::get_data(){
  return this->data;
}

void Cotacao::set_valor(double valor){
  this->valor = valor;
}

double Cotacao::get_valor(){
  return this->valor;
}
