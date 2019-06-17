#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_X 2
#define NUM_OF_Y 2
#define NO_PUZZLE 0
#define HERE 1

int initialize();
void Write_puzzle(int,int,int);

int main(int argc, char const *argv[]) {
  /* code */
  printf("日本語\n");

  int puzzle[NUM_OF_Y][NUM_OF_X];

  for(int y = 0; y < NUM_OF_Y; y++){
    for(int x = 0; x < NUM_OF_X; x++ ){

      puzzle[y][x] = initialize(x,y);
      Write_puzzle(puzzle[y][x],x,y);
    }
  }

}

int initialize(int _x,int _y){ //初期化
  int puzzle_info =0;
  if(_x == 0 && _y == 0){
    puzzle_info = HERE;
  }else{
    puzzle_info = NO_PUZZLE;
  }
  return puzzle_info ;
}

void Write_puzzle(int _puzzle,int _x, int _y){//表示

      if(_puzzle == NO_PUZZLE){//パズルがない場合
        printf("____|");
      }else{//パズルがある場合
        printf(" 娘 |");
      }


    if(_x == NUM_OF_X - 1){//次の列に移る
    printf("\n");
  }

}
