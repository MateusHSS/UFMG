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
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
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
    }
  }

  printf("(%d,%d)", x,y);

  return 0;
}