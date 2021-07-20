#include "BST.hpp"

NodeT::NodeT(){
  this->data;
  this->esq;
  this->dir;
}

NodeT* createNode(Aluno data){
  NodeT* aux = new NodeT;
  aux->data = data;
  aux->esq = nullptr;
  aux->dir = nullptr;

  return aux;
}

BST::BST(){
  this->root = nullptr;
}

void BST::inserir_aluno(Aluno data){
  if(root != nullptr){
    insertNodeHelper(root, data);
  }else{
    root = createNode(data);
  }
}

void BST::insertNodeHelper(NodeT* n, Aluno data){
  if(data.get_matricula() < n->data.get_matricula()){
    if(n->esq == nullptr){
      n->esq = createNode(data);
    }else{
      insertNodeHelper(n->esq, data);
    }
  }else if(data.get_matricula() > n->data.get_matricula()){
    if(n->dir == nullptr){
      n->dir = createNode(data);
    }else{
      insertNodeHelper(n->dir, data);
    }
  }
}

void inorder(NodeT* n){
  if(n == nullptr){
    return;
  }

  inorder(n->esq);
  n->data.imprimir_dados();
  inorder(n->dir);
}

void BST::imprimir_arvore(){
  inorder(this->root);
}

Aluno* search(NodeT* n, int matricula){
  if(n == nullptr){
    return nullptr;
  }
  
  if(n->data.get_matricula() == matricula){
    return &n->data;
  }

  if(n->data.get_matricula() > matricula){
    return search(n->esq, matricula);
  }else{
    return search(n->dir, matricula);
  }
}

Aluno* BST::procurar_aluno(int matricula){
  return search(this->root, matricula);
}