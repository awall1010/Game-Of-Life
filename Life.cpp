#include <iostream>
#include <fstream>

#include "GameMode.h"
// #include "GameMode.h"
using namespace std;

int main(int argc, char const *argv[]) {
  int fileChoice;
  int modeChoice;
  cout<<"Would you like to import a grid from a file or create a random one? "<<endl;
  cout<<"Enter 1 to import a file or 2 for random: "<<endl;
  cin>>fileChoice;

  if(fileChoice==1){ //still errors here
    string fileName;
    cout<< "Enter the file name: "<<endl;
    cin>>fileName;
    cout<<"Normal Mode, Mirror Mode, or Doughnut Mode? "<<endl;
    cout<< "Enter 1 for normal, 2 for mirror, or 3 for donut. "<<endl;
    cin>>modeChoice;

    if(modeChoice==1){
      GameMode *g = new GameMode;
      g->normalMode(fileName);

    }
    else if(modeChoice==2){
      GameMode *g = new GameMode;
      g->mirrorMode(fileName);
    }
    else if(modeChoice ==3){
      GameMode *g = new GameMode;
      g->doughnutMode(fileName);
    }
    else{
      cout<<"INVALID CHOICE. "<<endl;
    }


  }
  else if(fileChoice==2){
    int rows,columns;
    int inModeChoice;
    double density;
    cout<<"Normal Mode, Mirror Mode, or Doughnut Mode? "<<endl;
    cout<< "Enter 1 for normal, 2 for mirror, or 3 for donut. "<<endl;
    cin>>inModeChoice;


    cout<<"enter number of rows: "<<endl;
    cin>>rows;
    cout<<"enter number of columns: "<<endl;
    cin>>columns;
    cout<<"enter density: "<<endl;
    cin>>density;


    if(inModeChoice==1){
      GameMode *g = new GameMode;
      g->normalMode(rows, columns,density);

    }
    else if(inModeChoice==2){
      GameMode *g = new GameMode;
      g->mirrorMode(rows, columns,density);
    }
    else if(inModeChoice ==3){
      GameMode *g = new GameMode;
      g->doughnutMode(rows, columns,density);
    }
    else{
      cout<<"INVALID CHOICE. "<<endl;
    }


  }
  else{
    cout<<"INVALID CHOICE. "<<endl;
  }



  return 0;
}
