#include "fila_de_prioridade.h"
#include <iostream>

struct No{
  string el;
  int prior;

  No* next;
  No* prev;
};

FilaDePrioridade::FilaDePrioridade(){
  this->primeiro_ = nullptr;
  this->tamanho_ = 0;
}

bool FilaDePrioridade::vazia() const{
  return this->primeiro_ == nullptr;
}

string FilaDePrioridade::primeiro() const{
  if(this->primeiro_ != nullptr){
    return this->primeiro_->el;
  }

  return nullptr;
}

No* newNode(int p, string s){
  No* n = (No*)malloc(sizeof(No));
  n->el = s;
  n->prior = p;
  n->next = nullptr;
  n->prev = nullptr;

  return n;
}

void FilaDePrioridade::imprime(){
  No* n = this->primeiro_;
  for (int i = 0; i < this->tamanho(); i++)
  {
    std::cout << n->el << " - ";
    n = n->next;
  }
  
}

void FilaDePrioridade::Inserir(int p, string s){
  if(this->vazia()){
    this->primeiro_ = newNode(p, s);

  }else{
    No* n = this->primeiro_;
    int nao_inserido = 1;

    for (No* n = this->primeiro_; n != nullptr; n = n->next){
      std::cout << "Testa " << n->el << std::endl;

      if(p > n->prior && nao_inserido == 1){

        if(n->el == this->primeiro()){
          No* aux = this->primeiro_;
          this->primeiro_ = newNode(p, s);
          aux->prev = this->primeiro_;
          this->primeiro_->next = aux;
        }else{
          No* aux = n;
          No* novo = newNode(p, s);
          novo->next = aux;
          novo->prev = aux->prev;
          novo->prev->next = novo;
          aux->prev = novo;
        }

        nao_inserido = 0;

      }else if(p == n->prior && nao_inserido == 1){

        std::cout << "Igual" << std::endl;

        if(n->next == nullptr || p > n->next->prior){
          std::cout << "Maior que o proximo" << std::endl;

          if(n->el == this->primeiro()){
            No* novo = newNode(p, s);

            if(this->primeiro_->next != nullptr){
              novo->next = this->primeiro_->next;
            }
            this->primeiro_->next = novo;
            novo->prev = this->primeiro_;
            
          }else{
            No* aux = n;
            No* novo = newNode(p, s);

            if(n->next != nullptr){
              novo->next = aux->next;
              novo->next->prev = novo;
            }

            std::cout << "Insere no ultimo" << std::endl;
            novo->prev = aux;
            aux->next = novo;

          }
          nao_inserido = 0;
        }else{
          std::cout << "Menor" << std::endl;
        }
      }
    }
  }

  this->tamanho_++;

  std::cout << "Fila atual: ";
  imprime();
}

void FilaDePrioridade::RemoverPrimeiro(){
  this->primeiro_ = this->primeiro_->next;
  return;
}

int FilaDePrioridade::tamanho() const{
  return this->tamanho_;
}
