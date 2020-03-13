#include <iostream>
using namespace std;
#include "Board.h"


  Board::Board(){

  }

  Board::~Board(){
  }

//creates a board
char **Board::createMap(int r, int c, float d){
  numRows = r; //declare variables
  numColumns = c;
  density = d;
  double a = 0;
  int counter = 0;

  int maxValue = d*(numRows*numColumns);

  char** myGrid; //create grid
  myGrid = new char*[numRows];
  for(int i = 0;i < numRows;++i){
    myGrid[i]= new char[numColumns];
  }

  for(int i = 0; i < numRows; ++i){ //populate grid
    for(int j = 0; j < numColumns;++j){
      a = ((double) rand() / (RAND_MAX)); //random probability
      // int  r;

      // cout<<"A: "<<a<<endl;

      if(a<d && counter<maxValue){
        myGrid[i][j]='X';
        counter++;
      }
      else{
        myGrid[i][j] = '-';
      }


    }
  }

  for(int i = 0; i < numRows; ++i){
    for(int j = 0; j < numColumns;++j){
      cout <<myGrid[i][j];

    }
    cout<<endl;
  }
  return myGrid;
  // delete myGrid;
}

//creates mao but with an input file
char **Board::createMap(int r, int c, ifstream &inFS){
  numRows = r;
  numColumns = c;

string outputString = "";


char** myGrid;
myGrid = new char*[numRows];
for(int i = 0;i < numRows;++i){
  myGrid[i]= new char[numColumns];
}

// string sMap = stringMap.split(",");
for(int i = 0;i<numRows;++i){
  inFS>>outputString;
  for(int j = 0;j<numColumns;++j){
    myGrid[i][j] = outputString[j];
    // counter++;
  }
}
inFS.close();
for(int i = 0; i < numRows; ++i){
  for(int j = 0; j < numColumns;++j){
    cout <<myGrid[i][j];
  }
  cout<<endl;
}
return myGrid;
// delete myGrid;
}






//
// int main(int argc, char const *argv[]) {
//   Board *b = new Board();
//   b->createMap("input.txt");
//   return 0;
// }
