#ifndef BST_H
#define BST_H

#include <iostream>
#include "Aluno.hpp"

using namespace std;

struct NodeT {
  Aluno data;
  NodeT* esq;
  NodeT* dir;

  NodeT();
};

struct BST{
  NodeT* root;

  BST();

  void insertNodeHelper(NodeT* root, Aluno data);

  void inserir_aluno(Aluno aluno);
  void imprimir_arvore();
  Aluno* procurar_aluno(int matricula);
};


#endif