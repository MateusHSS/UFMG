#include "ContadorDePalavras.hpp"
#include <iostream>

ContadorDePalavras::ContadorDePalavras() : _lista_de_palavras(){}

void ContadorDePalavras::Adicionar(string s){
  for(auto it = this->_lista_de_palavras.begin(); it != this->_lista_de_palavras.end(); it++){
    if(it->palavra() == s){
      it->Incrementar();
      return;
    }
  }

  Palavra p = Palavra(s);
  this->_lista_de_palavras.insert(this->_lista_de_palavras.end(), p);
  this->_lista_de_palavras.sort();
  return;
}

void ContadorDePalavras::ImprimirOrdenado(){
  for(auto it = this->_lista_de_palavras.begin(); it != this->_lista_de_palavras.end(); it++){
    std::cout << it->palavra() << " " << it->ocorrencias() << std::endl;
  }
}