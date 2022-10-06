#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Dir{
  char letter;
  Dir* next;
}Dir;

int main(){

  Dir cima, esquerda, baixo, direita;
  cima.letter = 'c';
  esquerda.letter = 'e';
  baixo.letter = 'b';
  direita.letter = 'd';
  cima.next = &esquerda;
  esquerda.next = &baixo;
  baixo.next = &direita;
  direita.next = &cima; 

  int x = 0, y = 0;
  int n;
  int var = 1;
  int var_atual = 0;
  Dir dir_atual = cima;

  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    switch (dir_atual.letter){
      case 'c':
        y++;
        var_atual++;
        break;
      case 'e':
        x--;
        var_atual++;
        break;
      case 'b':
        y--;
        var_atual++;
        break;
      case 'd':
        x++;
        var_atual++;
        break;
      default:
        break;
    }

    if(var_atual == var){
      if(dir_atual.letter == 'e' || dir_atual.letter == 'd'){
        var++;
      }

      dir_atual = *dir_atual.next;
      var_atual = 0;
    }
  }

  printf("(%d,%d)\n", x, y);

  return 0;
}