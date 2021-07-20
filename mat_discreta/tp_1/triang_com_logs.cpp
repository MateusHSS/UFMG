#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Dir{
  char letter;
  Dir* next;
}Dir;

int main(){

  Dir cima, baixo, direita;
  cima.letter = 'c';
  baixo.letter = 'b';
  direita.letter = 'd';
  cima.next = &baixo;
  baixo.next = &direita;
  direita.next = &cima; 

  int x = 0, y = 0;
  int n;
  int var = 1;
  int var_atual = 0;
  Dir dir_atual = direita;
  int init = 1;
  int teste = 0;
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    printf("\n-------Ponto(%d)-----------\n", i);
    printf("X: %d\tY: %d\n", x, y);
    printf("Variacao: %d\n", var);
    printf("Variacao atual: %d\n", var_atual);
    switch (dir_atual.letter){
      case 'c':
        y++;
        x--;
        var_atual++;
        break;
      case 'b':
        y--;
        x--;
        var_atual++;
        break;
      case 'd':
        x++;
        var_atual++;
        break;
      default:
        break;
    }
    teste++;
    if(var_atual == var){
      if(dir_atual.letter == 'c'){
        var++;
      }else if(dir_atual.letter == 'b'){
        var = (var * 2) + 1;
      }else if(dir_atual.letter == 'd'){
        var -= floor(var/2);
        init = 0;
      }

      dir_atual = *dir_atual.next;
      var_atual = 0;
      printf("Direcao alterada para '%c'", dir_atual.letter);
    }
  }

  printf("(%d,%d)", x,y);
  printf("O(%d)", teste);
  return 0;
}