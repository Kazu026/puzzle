#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_X 2
#define NUM_OF_Y 2
#define NO_PUZZLE 0
#define HERE 1

int initialize();
void Write_puzzle(int,int,int);

struct block {
  int name;
  int positionX;
  int positionY;
  int lenX;
  int lenY;
};

enum blockname{
  nothing,
  musume,
  papa,
  mama,
  ane,
  imouto,
  ani,
  atouto,
  pochi
};



int main(int argc, char const *argv[]) {
  /* code */
  int puzzle[NUM_OF_Y][NUM_OF_X];
  enum blockname daughterblock;
  daughterblock = musume;
  struct block daughter;
  daughter.name = daughterblock;
  daughter.positionX = 0;
  daughter.positionY = 0;
  daughter.lenX = 2;
  daughter.lenY =1;

  for(int y = 0 ; y < daughter.lenY ; y++){
    for(int x = 0 ; x < daughter.lenX ; x++ ){
      puzzle[daughter.positionY + y][daughter.positionX + x] = daughter.name;
    }
  }

  for(int y = 0; y < NUM_OF_Y; y++){
    for(int x = 0; x < NUM_OF_X; x++ ){
      if(puzzle[y][x] != daughter.name){
        puzzle[y][x] = initialize();
      }

      Write_puzzle(puzzle[y][x],x,y);

    }
  }
}

int initialize(){ //初期化

  int puzzle_info =0;
  puzzle_info = NO_PUZZLE;

  return puzzle_info ;

}

void Write_puzzle(int _puzzle,int _x, int _y){//表示

      if(_puzzle == NO_PUZZLE){//パズルがない場合
        printf("____|");
      }else if (_puzzle == musume){//パズルがある場合
        printf(" 娘 |");
      }

    if(_x == NUM_OF_X - 1){//次の列に移る
    printf("\n");
  }

}
