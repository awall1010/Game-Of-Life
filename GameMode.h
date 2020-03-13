#include "Board.h"
#include <iostream>
#include <unistd.h>

using namespace std;

class GameMode : public Board{
public:
  GameMode();
  // GameMode()
  ~GameMode();
  int numRows;
  int numColumns;
  double density;
  // void normalMode(char **myGrid);
  // void doughnutMode(char **myGrid);
  // void mirrorMode(char **myGrid);

  void normalMode(int numRows, int numColumns, double density);
  void doughnutMode(int numRows, int numColumns, double density);
  void mirrorMode(int numRows, int numColumns, double density);


  void normalMode(string fName);
  void doughnutMode(string fName);
  void mirrorMode(string fName);


};
