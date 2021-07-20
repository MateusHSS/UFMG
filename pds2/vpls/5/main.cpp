// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_bst.hpp"

int main() {

    // NÃO ALTERE ESSA LINHA
    avaliacao_basica();

    //
    // Adicione seu código aqui e faça as demais alterações necessárias
    //
    BST bst;
    Aluno aluno;
    int matr_aux;
    string nome_aux;

    while(std::cin >> matr_aux){
        aluno.set_matricula(matr_aux);

        std::cin >> nome_aux;

        aluno.set_nome(nome_aux);

        bst.inserir_aluno(aluno);
    }

    //
    // Ao final faça uma chamada para o método 'imprimir_arvore()'
    //
    bst.imprimir_arvore();
    
    return 0;
}