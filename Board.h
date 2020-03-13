#include <iostream>
#include <fstream>
using namespace std;

class Board{
  public:
    Board();
    ~Board();
    int numRows;
    int numColumns;
    float density = 0;
    string map;

    char **createMap(int r, int c, float d);
    char **createMap(int r, int c, ifstream &inFS);

};
