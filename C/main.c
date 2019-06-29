#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_X 4
#define NUM_OF_Y 5
#define NO_PUZZLE 0
#define HERE 1
#define BLOCK_NUMBER 11



struct block {
  int name;
  int positionX;
  int positionY;
  int prepositionX;
  int prepositionY;
  int lenX;
  int lenY;
};


enum move{
  right,
  left,
  up,
  down
};

enum blockname{
  nothing,
  musume,
  papa,
  mama,
  baba,
  jiji,
  ane,
  imouto,
  ani,
  otouto,
  pochi
};


void setblock(int puzzle[][NUM_OF_X],struct block Block){
  for(int y = 0 ; y < Block.lenY ; y++){
    for(int x = 0 ; x < Block.lenX ; x++ ){
      puzzle[Block.positionY + y][Block.positionX + x] = Block.name;
    }
  }

}


int movecheck(int puzzle[][NUM_OF_X], struct block Block[BLOCK_NUMBER], enum blockname Blockname, enum move direction){
  int checkX = 0;
  int checkY = 0;

  switch(direction){
    case right:
      checkY = Block[Blockname].positionY + (Block[Blockname].lenY - 1);//長さ-1がY軸の一番下
      checkX = Block[Blockname].positionX + Block[Blockname].lenX;

      if(puzzle[Block[Blockname].positionY][checkX] == 0){
        if(puzzle[checkY][checkX]==0){
          return nothing;
        }
        return puzzle[checkY][checkX];
      }
      return puzzle[Block[Blockname].positionY][checkX];
      break;


    case left:
      checkY = Block[Blockname].positionY + (Block[Blockname].lenY - 1);//長さ-1がY軸の一番下
      checkX = Block[Blockname].positionX -1;

      if(puzzle[Block[Blockname].positionY][checkX] == 0){
        if(puzzle[checkY][checkX]==0){
          return nothing;
        }
        return puzzle[checkY][checkX];
      }
      return puzzle[Block[Blockname].positionY][checkX];
      break;


    case up:
      checkY = Block[Blockname].positionY -1;//長さ-1がY軸の一番下
      checkX = Block[Blockname].positionX + (Block[Blockname].lenX -1);

      if(puzzle[checkY][Block[Blockname].positionX] == 0){
        if(puzzle[checkY][checkX]==0){
          return nothing;
        }
        return puzzle[checkY][checkX];
      }
      return puzzle[checkY][Block[Blockname].positionY];
      break;


    case down:
      checkY = Block[Blockname].positionY + Block[Blockname].lenY;//長さ-1がY軸の一番下
      checkX = Block[Blockname].positionX + (Block[Blockname].lenX -1);

      if(puzzle[checkY][Block[Blockname].positionX] == 0){
        if(puzzle[checkY][checkX]==0){
          return nothing;
        }
        return puzzle[checkY][checkX];
      }
      return puzzle[checkY][Block[Blockname].positionX];
      break;
  }
}

struct block moveblock(int puzzle[][NUM_OF_X],struct block Block[BLOCK_NUMBER], enum blockname Blockname, enum move direction){
  int moverightcalcX;
  int moverightcalcY;
  int moveleftcalcX;
  int moveleftcalcY;
  int moveupcalcX;
  int moveupcalcY;
  int movedowncalcX;
  int movedowncalcY;
  int flag;



  flag = movecheck(puzzle,Block,Blockname,direction);

  if(flag == 0){
    switch(direction){
      case right:
        Block[Blockname].positionX += 1;
        break;

      case left:
        Block[Blockname].positionX -= 1;
        break;


      case up:
        Block[Blockname].positionY -= 1;
        break;


     case down:
        Block[Blockname].positionY += 1;
        break;

   }
 //前のブロックの情報を削除
    for(int y = 0 ; y < Block[Blockname].lenY ; y++){
      for(int x = 0 ; x < Block[Blockname].lenX ; x++ ){
        puzzle[Block[Blockname].prepositionY + y][Block[Blockname].prepositionX + x] = nothing;
      }
    }
    setblock(puzzle,Block[Blockname]);
    return Block[Blockname];
  }else{
    moveblock(puzzle,Block,flag,right);
  }
}


struct block setInfo(int name,int positionX,int positionY,int lenX,int lenY){

 struct block Block;

  Block.name = name;
  Block.positionX = positionX;
  Block.positionY = positionY;
  Block.prepositionX = positionX;
  Block.prepositionY = positionY;
  Block.lenX = lenX;
  Block.lenY = lenY;

  return Block;
}


void Write_puzzle(int puzzle[][NUM_OF_X]){//表示
  enum blockname Blockname;
  for(int y = 0; y < NUM_OF_Y; y++){
    for(int x = 0; x < NUM_OF_X; x++ ){
      Blockname = puzzle[y][x];
      switch (Blockname) {
        case nothing:
          printf("|__| ");
          break;

        case musume://パズルがある場合
          printf(" 娘  ");
          break;

        case papa:
          printf(" 父  ");
          break;

        case mama:
          printf(" 母  ");
          break;

        case baba:
          printf(" ば  ");
          break;

        case jiji:
          printf(" じ  ");
          break;

        case ane:
          printf(" 姉  ");
          break;

        case imouto:
          printf(" 妹  ");
          break;

        case ani:
          printf(" 兄  ");
          break;

        case otouto:
          printf(" 弟  ");
          break;

        case pochi:
          printf(" 犬  ");
          break;

      }

      if(x == NUM_OF_X - 1){//次の列に移る
        printf("\n");
      }

    }
  }
  printf("\n");
}



int main(int argc, char const *argv[]) {
  /* code */
  int puzzle[NUM_OF_Y][NUM_OF_X];
  int flag;
  struct block daughter;
  struct block father;
  struct block mother;
  struct block granma;
  struct block granpa;
  struct block bigsister;
  struct block smallsister;
  struct block bigbrother;
  struct block smallbrother;
  struct block dog;
  struct block Blockmanager[BLOCK_NUMBER];

  daughter = setInfo(musume,1,0,2,2);
  Blockmanager[musume] = daughter;

  father = setInfo(papa,0,0,1,2);
  Blockmanager[papa] = father;

  mother = setInfo(mama,3,0,1,2);
  Blockmanager[mama] = mother;

  granma = setInfo(baba,0,2,1,2);
  Blockmanager[baba] = granma;

  granpa = setInfo(jiji,3,2,1,2);
  Blockmanager[jiji] = granpa;

  bigsister = setInfo(ane,1,3,1,1);
  Blockmanager[ane] = bigsister;

  smallsister = setInfo(imouto,0,4,1,1);
  Blockmanager[imouto] = smallsister;

  bigbrother = setInfo(ani,2,3,1,1);
  Blockmanager[ani] = bigbrother;

  smallbrother = setInfo(otouto,3,4,1,1);
  Blockmanager[otouto] = smallbrother;

  dog = setInfo(pochi,1,2,2,1);
  Blockmanager[pochi] = dog;



  //初期化ルーチン
  for(int y = 0; y < NUM_OF_Y; y++){
    for(int x = 0; x < NUM_OF_X; x++ ){
        puzzle[y][x] = nothing;
    }
  }

  //ブロック配置
  setblock(puzzle,daughter);
  setblock(puzzle,father);
  setblock(puzzle,mother);
  //setblock(puzzle,granpa);
  //setblock(puzzle,granma);
  setblock(puzzle,bigsister);
  setblock(puzzle,smallsister);
  setblock(puzzle,bigbrother);
  setblock(puzzle,smallbrother);
//  setblock(puzzle,dog);



  //パズル表示
  Write_puzzle(puzzle);


//ルーチン
  for(int i = 0;i<6;i++){
    moveblock(puzzle,Blockmanager,musume,down);
    Write_puzzle(puzzle);
  }


}
