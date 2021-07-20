#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
#include <string>

using namespace std;

struct Aluno
{
  int matricula;
  string nome;

  Aluno(int matricula = 0, string nome = " ");

  void set_matricula(int matricula);
  int get_matricula();
  void set_nome(string nome);
  string get_nome();
  void imprimir_dados();
};



#endif