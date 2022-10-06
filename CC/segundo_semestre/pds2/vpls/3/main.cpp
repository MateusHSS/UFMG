#include <iostream>

int main(){

    // 1) Declare uma variável do tipo inteiro e atribua o valor '5'.
    int x = 5;

    // 2) Declare um vetor de inteiros e inicialize com valores de 0 a 9.
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 3) Declare um ponteiro para inteiros e inicialize com valor nulo.
    int *y = NULL;

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    std::cout << &x << std::endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    std::cout << x << std::endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    std::cout << &v << std::endl;

    // 7) Imprima o ENDEREÇO da variável declarada em (3)
    std::cout << &y << std::endl;
    
    // 8) Imprima o VALOR da variável declarada em (3)
    std::cout << y << std::endl;

    // 9) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (3)
    y = &x;

    // 10) Imprima o VALOR da variável declarada em (3)
    std::cout << y << std::endl;

    // 11) Imprima o VALOR guardado no ENDEREÇO apontado por (3)
    std::cout << *y << std::endl;

    // 12) Imprima o resultado da comparação do ENDEREÇO de (1) e do VALOR de (3)
    std::cout << (&x == y) << std::endl;

    // 13) Coloque o VALOR '10' no ENDEREÇO apontado por (3)
    *y = 10;

    // 14) Imprima o VALOR da variável declarada em (1)
    std::cout << x << std::endl;

    // 15) Atribua o ENDEREÇO da variável (2) à variável declarada em (3)
    y = v;

    // 16) Imprima o VALOR da variável declarada em (3)
    std::cout << y << std::endl;

    // 17) Imprima o VALOR guardado no ENDEREÇO apontado por (3)
    std::cout << *y << std::endl;

    // 18) Atribua o ENDEREÇO da primeira posição de (2) à variável declarada em (3)
    y = &(v[0]);

    // 19) Imprima o VALOR da variável declarada em (3)
    std::cout << y << std::endl;

    // 20) Imprima o VALOR guardado no ENDEREÇO apontado por (3)
    std::cout << *y << std::endl;

    // 21) Multiplique todos os valores do vetor declarado em (2) por '10', porém manipulando apenas a variável (3)
    *y *= 10;
    *(y+1) *= 10;
    *(y+2) *= 10;
    *(y+3) *= 10;
    *(y+4) *= 10;
    *(y+5) *= 10;
    *(y+6) *= 10;
    *(y+7) *= 10;
    *(y+8) *= 10;
    *(y+9) *= 10;

    // 22) Imprima os elementos de (2) a partir variável do vetor utilizando a notação [] (colchetes)
    std::cout << v[0] << " ";
    std::cout << v[1] << " ";
    std::cout << v[2] << " ";
    std::cout << v[3] << " ";
    std::cout << v[4] << " ";
    std::cout << v[5] << " ";
    std::cout << v[6] << " ";
    std::cout << v[7] << " ";
    std::cout << v[8] << " ";
    std::cout << v[9] << " " << std::endl;

    // 23) Imprima os elementos de (2) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    std::cout << *v << " ";
    std::cout << *(v+1) << " ";
    std::cout << *(v+2) << " ";
    std::cout << *(v+3) << " ";
    std::cout << *(v+4) << " ";
    std::cout << *(v+5) << " ";
    std::cout << *(v+6) << " ";
    std::cout << *(v+7) << " ";
    std::cout << *(v+8) << " ";
    std::cout << *(v+9) << " " << std::endl;

    // 24) Imprima os elementos de (2) manipulando apenas a variável (3)
    std::cout << *y << " ";
    std::cout << *(y+1) << " ";
    std::cout << *(y+2) << " ";
    std::cout << *(y+3) << " ";
    std::cout << *(y+4) << " ";
    std::cout << *(y+5) << " ";
    std::cout << *(y+6) << " ";
    std::cout << *(y+7) << " ";
    std::cout << *(y+8) << " ";
    std::cout << *(y+9) << " " << std::endl;

    // 25) Imprima o resultado da comparação do VALORES armazenado na quinta posição de (2) e no ponteiro (3) incrementado de 4
    std::cout << (v[4] == *(y+4)) << std::endl;

    // 26) Atribua o ENDEREÇO da quinta posição de (2) à variável declarada em (3)
    y = &v[4];

    // 27) Imprima o VALOR guardado no ENDEREÇO apontado por (3)
    std::cout << *y << std::endl;

    // 28) Imprima o VALOR guardado no ENDEREÇO do ponteiro (3) decrementado de 4
    std::cout << *(y-4) << std::endl;

    return 0;
}