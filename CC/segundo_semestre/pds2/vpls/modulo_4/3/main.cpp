#include <iostream>

#include "RingArray.h"

void fer_assert(const bool expr, const char* msg) {
  if (!expr) {
    std::cout << msg << std::endl;
    exit(1);
  }
}

template <class T, unsigned N>
void RingArray<T, N>::add(T value) {
  if(!this->isFull()){
    std::cout << "Inserindo em " << this->_last << std::endl;
    this->buf[this->_last] = value;
    this->_last++;
  }else{
    fer_assert(!this->isFull(), "Erro: anel cheio.");
  }
}

template <class T, unsigned N>
T RingArray<T, N>::get() {

  if(this->isEmpty()){
    fer_assert(this->isEmpty(), "Erro: anel vazio.");
  }
  std::cout << "Removendo em " << this->_first << std::endl;
  T aux = this->buf[this->_first];
  this->_first++;
  return aux; 
}

template <class T, unsigned N>
bool RingArray<T, N>::isFull() const {
  if((this->_last + 1) % N == this->_first){
    return true;
  }

  return false;
}

template <class T, unsigned N>
bool RingArray<T, N>::isEmpty() const {
  if(this->_first == 0 && this->_last == 0){
    return true;
  }

  return false;
}

template <class T>
void test_add_then_get() {
  RingArray<T, 8> r;
  T value;
  while (std::cin >> value) {
    r.add(value);
  }
  while (!r.isEmpty()) {
    std::cout << r.get() << std::endl;
  }
}

template <class T>
void test_add_or_get() { 
  RingArray<T, 8> r;
  T value;
  char c;
  while (std::cin >> c) {
    if (c == '+') {
      std::cin >> value;
      r.add(value);
    } else if (c == '-') {
      std::cout << r.get() << std::endl;
    } else {
      std::cout << "Invalid operation\n";
    }
  }
}

int main () {
  char data;
  while (std::cin >> data) {
    switch (data) {
      case 'd': test_add_then_get<double>();
                break;
      case 's': test_add_then_get<std::string>();
                break;
      case 'D': test_add_or_get<double>();
                break;
      case 'S': test_add_or_get<std::string>();
                break;
      default: std::cout << "Invalid type\n";
    }
  }
  return 0;
}