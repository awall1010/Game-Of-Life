#include "GameMode.h"

GameMode::GameMode(){

    int numRows = 0;
    int numColumns = 0;
    double density= 0;
}

GameMode::~GameMode(){

}

//normal mode
void GameMode::normalMode(int numRows, int numColumns, double density){
  ofstream outFS;
  //prompt user
  cout<<"Enter your output choice: "<<endl;
  cout<<"1 form a brief pause between generations"<<endl<<"2 to press the “enter” key" <<endl << "3 if you want to output to a file."<<endl;
  int outputChoice;
  cin>>outputChoice;
  if(outputChoice==3){
    string outFileName;
    cout<<"Enter the file name: "<<endl;
    cin>>outFileName;
    outFS.open(outFileName);
  }


  //create the board
  char **arrGrid = Board::createMap(numRows, numColumns, density);

//create board for next generation
  char** nextGeneration;
  nextGeneration = new char*[numRows];
  for(int p = 0;p < numRows;++p){
    nextGeneration[p]= new char[numColumns];
  }
cout<<"NORMAL MODE "<<endl;
  int genCount = 0;
while( true){
//loop through each simulation
  if(outputChoice==2){
    cout<<"press enter to to produce another generation or control c to exit. "<<endl;
    cin.get();
  }
  else if(outputChoice==1){
    usleep(500000);
  }
  int counter = 0;
//count neigbors
  for(int i =0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      counter = 0;
      if(i!=0 && i!=(numRows-1) && j!= 0 && j!= (numColumns-1)){//middle squares
        if(arrGrid[i-1][j]=='X'){
          counter++;

              }
        if(arrGrid[i-1][j-1]=='X'){


          counter++;

              }
        if(arrGrid[i][j-1]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){
          counter++;
        }
      }
      else if(i==0 && j==0 ){//top left corner
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
      }
      else if(i==0 && j ==(numColumns-1)){ //top right corner

        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
      }
      else if(i ==(numRows-1) && j ==0){//bottom left corner
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
      }
      else if(i ==(numRows-1)&& j ==(numColumns-1)){ //bottom right corner
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
      }
      else if((i == 0) && (j != numColumns-1 && j != 0)){ //top row

        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right diagonal
          counter++;
        }
      }
      else if((i == numRows-1) && (j != numColumns-1 && j != 0)){ //bottom row
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i-1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
      }
      else if((i != 0 && i != numRows-1) && (j == 0)){ // left column
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //right above diagonal
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right below diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
      }
      else if((i != 0 && i != numRows-1) && (j == numColumns-1)){ //far right column
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //left above diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left below diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
      }


      //fill new generation based off counter
      if(counter <=1){
        nextGeneration[i][j]='-';
      }else if(counter == 2){
        nextGeneration[i][j]= arrGrid[i][j];
      }else if(counter ==3){
        nextGeneration[i][j]= 'X';
      }
      else{
        nextGeneration[i][j]= '-';
      }
    } //exit j for loop
  } //exit i for loop

//output new generation
  if(outputChoice!=3){
    cout<<"new generation "<<endl;
    for(int i = 0;i<numRows;++i){
      for(int j = 0;j<numColumns;++j){

        cout<<nextGeneration[i][j];
      }

      cout<<endl;
    }
  }
  else{
    //write new generation to file
    outFS<<"new generation: "<<endl;
    for(int i = 0;i<numRows;++i){
      for(int j = 0;j<numColumns;++j){

        outFS<<nextGeneration[i][j];
      }

      outFS<<endl;
    }
  }

//see if population has stabalized
  bool isEqual = true;
  for(int i = 0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      if(arrGrid[i][j]!=nextGeneration[i][j]){
        isEqual = false;
      }
    }
  }

  if(isEqual==true){
    cout<<"population stabalized. Press enter to break. "<<endl;
    cin.get();
    return;

  }


//set new generation to previous generation
  for(int i = 0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      arrGrid[i][j]=nextGeneration[i][j];
    }
  }




}




}
//normal mode with file name as parameter
void GameMode::normalMode(string fName){
  ofstream outFS;
  cout<<"Enter your output choice: "<<endl;
  cout<<"1 form a brief pause between generations"<<endl<<"2 to press the “enter” key" <<endl << "3 if you want to output to a file."<<endl;
  int outputChoice;
  cin>>outputChoice;
  if(outputChoice==3){
    string outFileName;
    cout<<"Enter the file name: "<<endl;
    cin>>outFileName;
    outFS.open(outFileName);
  }

  ifstream inFS;

  inFS.open(fName);
  if(!inFS.is_open()){
    cout<<"couldn't open file. "<<endl;
  }

  inFS >> numRows >> numColumns;
  char **arrGrid = Board::createMap(numRows, numColumns, inFS);





  char** nextGeneration;
  nextGeneration = new char*[numRows];

  for(int p = 0;p < numRows;++p){
    nextGeneration[p]= new char[numColumns];
  }
cout<<"NORMAL MODE "<<endl;
  int genCount = 0;
while( true){
  int counter = 0;

  if(outputChoice==2){
    cout<<"press enter to to produce another generation or control c to exit. "<<endl;
    cin.get();
  }
  else if(outputChoice==1){
    usleep(500000);
  }
  for(int i =0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      counter = 0;
      if(i!=0 && i!=(numRows-1) && j!= 0 && j!= (numColumns-1)){//middle squares
        if(arrGrid[i-1][j]=='X'){
          counter++;

              }
        if(arrGrid[i-1][j-1]=='X'){


          counter++;

              }
        if(arrGrid[i][j-1]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){
          counter++;
        }
      }
      else if(i==0 && j==0 ){//top left corner
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
      }
      else if(i==0 && j ==(numColumns-1)){ //top right corner

        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
      }
      else if(i ==(numRows-1) && j ==0){//bottom left corner
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
      }
      else if(i ==(numRows-1)&& j ==(numColumns-1)){ //bottom right corner
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
      }
      else if((i == 0) && (j != numColumns-1 && j != 0)){ //top row

        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right diagonal
          counter++;
        }
      }
      else if((i == numRows-1) && (j != numColumns-1 && j != 0)){ //bottom row
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i-1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
      }
      else if((i != 0 && i != numRows-1) && (j == 0)){ // left column
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //right above diagonal
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right below diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
      }
      else if((i != 0 && i != numRows-1) && (j == numColumns-1)){ //far right column
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //left above diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left below diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
      }


      //fill new generation based off counter
      if(counter <=1){
        nextGeneration[i][j]='-';
      }else if(counter == 2){
        nextGeneration[i][j]= arrGrid[i][j];
      }else if(counter ==3){
        nextGeneration[i][j]= 'X';
      }
      else{
        nextGeneration[i][j]= '-';
      }
    } //exit j for loop
  } //exit i for loop



    if(outputChoice!=3){
      cout<<"new generation "<<endl;
      for(int i = 0;i<numRows;++i){
        for(int j = 0;j<numColumns;++j){

          cout<<nextGeneration[i][j];
        }

        cout<<endl;
      }
    }
    else{
      outFS<<"new generation: "<<endl;
      for(int i = 0;i<numRows;++i){
        for(int j = 0;j<numColumns;++j){

          outFS<<nextGeneration[i][j];
        }

        outFS<<endl;
      }
    }

  bool isEqual = true;
  for(int i = 0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      if(arrGrid[i][j]!=nextGeneration[i][j]){
        isEqual = false;
      }
    }
  }

  if(isEqual==true){
    cout<<"population stabalized. Press enter to break. "<<endl;
    cin.get();
    return;

  }
  // if(arrGrid)


  for(int i = 0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      arrGrid[i][j]=nextGeneration[i][j];
    }
  }




}




}


//donut mode
void GameMode::doughnutMode(int numRows, int numColumns, double density){
  ofstream outFS;
  cout<<"Enter your output choice: "<<endl;
  cout<<"1 form a brief pause between generations"<<endl<<"2 to press the “enter” key" <<endl << "3 if you want to output to a file."<<endl;
  int outputChoice;
  cin>>outputChoice;
  if(outputChoice==3){
    string outFileName;
    cout<<"Enter the file name: "<<endl;
    cin>>outFileName;
    outFS.open(outFileName);
  }


  char **arrGrid = Board::createMap(numRows, numColumns, density);

  char** nextGeneration;
  nextGeneration = new char*[numRows];
  for(int p = 0;p < numRows;++p){
    nextGeneration[p]= new char[numColumns];
  }


int genCount = 0;
while(true){
  if(outputChoice==2){
    cout<<"press enter to to produce another generation or control c to exit. "<<endl;
    cin.get();
  }
  else if(outputChoice==1){
    usleep(500000);
  }
  //check for neighbors
  for(int i =0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      int counter = 0;
      if(i!=0 && i!=(numRows-1) && j!= 0 && j!= (numColumns-1)){//middle squares
        if(arrGrid[i-1][j]=='X'){
          counter++;

              }
        if(arrGrid[i-1][j-1]=='X'){


          counter+1;
          // cout<<"counter after entering: "<<counter<<endl;
              }
        if(arrGrid[i][j-1]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){
          counter++;
        }
      }

      else if(i==0 && j==0 ){ //top left corner
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right bottom diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
        if(arrGrid[0][0]){
          counter++;
        }

      }

      else if(i==0 && j ==(numColumns-1)){ //top right corner
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left bottom diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
        if(arrGrid[numRows-1][j]=='X'){
          counter++;
        }
        if(arrGrid[numRows-1][j-1]=='X'){
          counter++;
        }
        if(arrGrid[numRows-1][0]=='X'){
          counter++;
        }
        if(arrGrid[i+1][0]=='X'){
          counter++;
        }
        if(arrGrid[0][0]=='X'){
          counter++;
        }

      }

      else if(i ==(numRows-1) && j ==0){//bottom left corner
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i][numColumns-1]=='X'){
          counter++;
        }
        if(arrGrid[i-1][numColumns-1]=='X'){
          counter++;
        }
        if(arrGrid[0][numColumns-1]=='X'){
          counter++;
        }
        if(arrGrid[0][j+1]=='X'){
          counter++;
        }
        if(arrGrid[0][j]=='X'){
          counter++;
        }

      }

      else if(i ==(numRows-1)&& j ==(numColumns-1)){ //bottom right corner
        //
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[0][0]=='X'){
          counter++;
        }
        if(arrGrid[0][j]=='X'){
          counter++;
        }
        if(arrGrid[i][0]){
          counter++;
        }
        if(arrGrid[i-1][0]=='X'){
          counter++;
        }
        if(arrGrid[0][j-1]){
          counter++;
        }


      }

      else if((i == 0) && (j != numColumns-1 && j != 0)){ // top row

        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[numRows-1][j-1]=='X'){
          counter++;
        }
        if(arrGrid[numRows-1][j]=='X'){
          counter++;
        }
        if(arrGrid[numRows-1][j+1]=='X'){
          counter++;
        }


      }

      else if((i == numRows-1) && (j != numColumns - 1 && j != 0)){ // bottom row
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i][j+1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[i-1][j]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[0][j+1]=='X'){
          counter++;
        }
        if(arrGrid[0][j]=='X'){
          counter++;
        }
        if(arrGrid[0][j-1]=='X'){
          counter++;
        }
      }

      else if((i != 0 && i != numRows-1) && (j == 0)){ //left side
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //right above diagonal
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right below diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
        if(arrGrid[i][numColumns-1]=='X'){ //below
          counter++;
        }
        if(arrGrid[i-1][numColumns-1]=='X'){ //below
          counter++;
        }
        if(arrGrid[i+1][numColumns-1]=='X'){ //below
          counter++;
        }
      }

      else if((i != 0 && i != numRows-1) && (j == numColumns-1)){ //right side
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //left above diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left below diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
        if(arrGrid[i-1][0]=='X'){
          counter++;
        }
        if(arrGrid[i][0]=='X'){
          counter++;
        }
        if(arrGrid[i+1][0]=='X'){
          counter++;
        }
      }



      //fill new generation based off counter
      if(counter <=1){
        nextGeneration[i][j]='-';
      }else if(counter == 2){
        nextGeneration[i][j]= arrGrid[i][j];
      }else if(counter ==3){
        nextGeneration[i][j]= 'X';
      }
      else{
        nextGeneration[i][j]= '-';
      }
    } //exit j for loop
  } //exit i for loop




  if(outputChoice!=3){
    cout<<"new generation "<<endl;
    for(int i = 0;i<numRows;++i){
      for(int j = 0;j<numColumns;++j){

        cout<<nextGeneration[i][j];
      }

      cout<<endl;
    }
  }
  else{
    outFS<<"new generation: "<<endl;
    for(int i = 0;i<numRows;++i){
      for(int j = 0;j<numColumns;++j){

        outFS<<nextGeneration[i][j];
      }

      outFS<<endl;
    }
  }


  bool isEqual = true;
  for(int i = 0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      if(arrGrid[i][j]!=nextGeneration[i][j]){
        isEqual = false;
      }
    }
  }

  if(isEqual==true){
    cout<<"population stabalized. Press enter to break. "<<endl;
    cin.get();
    return;

  }

  for(int i = 0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      arrGrid[i][j]=nextGeneration[i][j];
    }
  }

}



}

//donut mode with file as parameter
void GameMode::doughnutMode(string fName){
  ofstream outFS;
  cout<<"Enter your output choice: "<<endl;
  cout<<"1 form a brief pause between generations"<<endl<<"2 to press the “enter” key" <<endl << "3 if you want to output to a file."<<endl;
  int outputChoice;
  cin>>outputChoice;
  if(outputChoice==3){
    string outFileName;
    cout<<"Enter the file name: "<<endl;
    cin>>outFileName;
    outFS.open(outFileName);
  }
  ifstream inFS;

  inFS.open(fName);
  if(!inFS.is_open()){
    cout<<"couldn't open file. "<<endl;
  }

  inFS >> numRows >> numColumns;
  char **arrGrid = Board::createMap(numRows, numColumns, inFS);


  char** nextGeneration;
  nextGeneration = new char*[numRows];
  for(int p = 0;p < numRows;++p){
    nextGeneration[p]= new char[numColumns];
  }


int genCount = 0;
while(true){
  if(outputChoice==2){
    cout<<"press enter to to produce another generation or control c to exit. "<<endl;
    cin.get();
  }
  else if(outputChoice==1){
    usleep(500000);
  }



  //check for neighbors
  for(int i =0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      int counter = 0;
      if(i!=0 && i!=(numRows-1) && j!= 0 && j!= (numColumns-1)){//middle squares
        if(arrGrid[i-1][j]=='X'){
          counter++;


              }
        if(arrGrid[i-1][j-1]=='X'){


          counter+1;
          // cout<<"counter after entering: "<<counter<<endl;
              }
        if(arrGrid[i][j-1]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){
          counter++;
        }
      }

      else if(i==0 && j==0 ){ //top left corner
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right bottom diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
        if(arrGrid[0][0]){
          counter++;
        }

      }

      else if(i==0 && j ==(numColumns-1)){ //top right corner
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left bottom diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
        if(arrGrid[numRows-1][j]=='X'){
          counter++;
        }
        if(arrGrid[numRows-1][j-1]=='X'){
          counter++;
        }
        if(arrGrid[numRows-1][0]=='X'){
          counter++;
        }
        if(arrGrid[i+1][0]=='X'){
          counter++;
        }
        if(arrGrid[0][0]=='X'){
          counter++;
        }

      }

      else if(i ==(numRows-1) && j ==0){//bottom left corner
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i][numColumns-1]=='X'){
          counter++;
        }
        if(arrGrid[i-1][numColumns-1]=='X'){
          counter++;
        }
        if(arrGrid[0][numColumns-1]=='X'){
          counter++;
        }
        if(arrGrid[0][j+1]=='X'){
          counter++;
        }
        if(arrGrid[0][j]=='X'){
          counter++;
        }

      }

      else if(i ==(numRows-1)&& j ==(numColumns-1)){ //bottom right corner
        //
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[0][0]=='X'){
          counter++;
        }
        if(arrGrid[0][j]=='X'){
          counter++;
        }
        if(arrGrid[i][0]){
          counter++;
        }
        if(arrGrid[i-1][0]=='X'){
          counter++;
        }
        if(arrGrid[0][j-1]){
          counter++;
        }


      }

      else if((i == 0) && (j != numColumns-1 && j != 0)){ // top row

        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[numRows-1][j-1]=='X'){
          counter++;
        }
        if(arrGrid[numRows-1][j]=='X'){
          counter++;
        }
        if(arrGrid[numRows-1][j+1]=='X'){
          counter++;
        }


      }

      else if((i == numRows-1) && (j != numColumns - 1 && j != 0)){ // bottom row
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i][j+1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[i-1][j]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[0][j+1]=='X'){
          counter++;
        }
        if(arrGrid[0][j]=='X'){
          counter++;
        }
        if(arrGrid[0][j-1]=='X'){
          counter++;
        }
      }

      else if((i != 0 && i != numRows-1) && (j == 0)){ //left side
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //right above diagonal
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right below diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
        if(arrGrid[i][numColumns-1]=='X'){ //below
          counter++;
        }
        if(arrGrid[i-1][numColumns-1]=='X'){ //below
          counter++;
        }
        if(arrGrid[i+1][numColumns-1]=='X'){ //below
          counter++;
        }
      }

      else if((i != 0 && i != numRows-1) && (j == numColumns-1)){ //right side
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //left above diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left below diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
        if(arrGrid[i-1][0]=='X'){
          counter++;
        }
        if(arrGrid[i][0]=='X'){
          counter++;
        }
        if(arrGrid[i+1][0]=='X'){
          counter++;
        }
      }



      //fill new generation based off counter
      if(counter <=1){
        nextGeneration[i][j]='-';
      }else if(counter == 2){
        nextGeneration[i][j]= arrGrid[i][j];
      }else if(counter ==3){
        nextGeneration[i][j]= 'X';
      }
      else{
        nextGeneration[i][j]= '-';
      }
    } //exit j for loop
  } //exit i for loop





  if(outputChoice!=3){
    cout<<"new generation "<<endl;
    for(int i = 0;i<numRows;++i){
      for(int j = 0;j<numColumns;++j){

        cout<<nextGeneration[i][j];
      }

      cout<<endl;
    }
  }
  else{
    outFS<<"new generation: "<<endl;
    for(int i = 0;i<numRows;++i){
      for(int j = 0;j<numColumns;++j){

        outFS<<nextGeneration[i][j];
      }

      outFS<<endl;
    }
  }

  bool isEqual = true;
  for(int i = 0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      if(arrGrid[i][j]!=nextGeneration[i][j]){
        isEqual = false;
      }
    }
  }

  if(isEqual==true){
    cout<<"population stabalized. Press enter to break. "<<endl;
    cin.get();
    return;

  }

  for(int i = 0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      arrGrid[i][j]=nextGeneration[i][j];
    }
  }

}



}


//mirror mode
void GameMode::mirrorMode(int numRows, int numColumns, double density){
  ofstream outFS;
  cout<<"Enter your output choice: "<<endl;
  cout<<"1 form a brief pause between generations"<<endl<<"2 to press the “enter” key" <<endl << "3 if you want to output to a file."<<endl;
  int outputChoice;
  cin>>outputChoice;
  if(outputChoice==3){
    string outFileName;
    cout<<"Enter the file name: "<<endl;
    cin>>outFileName;
    outFS.open(outFileName);
  }


  char **arrGrid = Board::createMap(numRows, numColumns, density);

  char** nextGeneration;
  nextGeneration = new char*[numRows];
  for(int p = 0;p < numRows;++p){
    nextGeneration[p]= new char[numColumns];
  }

  //check for neighbors
  cout<<"MIRROR MODE "<<endl;
  int counter = 0;
  int genCount=0;
  while(true){
    if(outputChoice==2){
      cout<<"press enter to to produce another generation or control c to exit. "<<endl;
      cin.get();
    }
    else if(outputChoice==1){
      usleep(500000);
    }
  for(int i =0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){


        counter = 0;
        if(i!=0 && i!=(numRows-1) && j!= 0 && j!= (numColumns-1)){//middle squares
          if(arrGrid[i-1][j]=='X'){
            counter++;

                }
          if(arrGrid[i-1][j-1]=='X'){


            counter++;

                }
          if(arrGrid[i][j-1]=='X'){
            counter++;
          }
          if(arrGrid[i+1][j-1]=='X'){
            counter++;
          }
          if(arrGrid[i+1][j]=='X'){
            counter++;
          }
          if(arrGrid[i+1][j+1]=='X'){
            counter++;
          }
          if(arrGrid[i][j+1]=='X'){
            counter++;
          }
          if(arrGrid[i-1][j+1]=='X'){
            counter++;
          }
        }

        else if(i==0 && j==0 ){//top left corner
          // if(arrGrid[i][j]=='X'){
          //   counter+=3;
          // }
          if(arrGrid[i][j+1]=='X'){ //to the right
            counter++;
          }
          if(arrGrid[i+1][j+1]=='X'){ //right diagonal
            counter++;
          }
          if(arrGrid[i+1][j]=='X'){ //below
            counter++;
          }
          if(arrGrid[numRows-1][numColumns-1]=='X'){
            counter++;
          }
          if(arrGrid[i][numColumns-1]=='X'){
            counter++;
          }
          if(arrGrid[i+1][numColumns-1]=='X'){
            counter++;
          }
          if(arrGrid[numRows-1][j]=='X'){
            counter++;
          }
          if(arrGrid[numRows-1][j+1]=='X'){
            counter++;
          }

        }

        else if(i==0 && j ==(numColumns-1)){ //top right corner
          if(arrGrid[i][j]=='X'){
            counter+=3;
          }
          if(arrGrid[i][j-1]=='X'){ //to the left
            counter++;
          }
          if(arrGrid[i+1][j-1]=='X'){ //left diagonal
            counter++;
          }
          if(arrGrid[i+1][j]=='X'){ //below
            counter++;
          }
        }

        else if(i ==(numRows-1) && j ==0){//bottom left corner
          if(arrGrid[i][j]=='X'){
            counter+=3;
          }
          if(arrGrid[i-1][j]=='X'){ //above
            counter++;
          }
          if(arrGrid[i-1][j+1]=='X'){ //right diagonal
            counter++;
          }
          if(arrGrid[i][j+1]=='X'){ //to the right
            counter++;
          }
        }

        else if(i ==(numRows-1)&& j ==(numColumns-1)){ //bottom right corner
          if(arrGrid[i][j]=='X'){
            counter+=3;
          }
          if(arrGrid[i-1][j]=='X'){ //above
            counter++;
          }
          if(arrGrid[i-1][j-1]=='X'){ //left diagonal
            counter++;
          }
          if(arrGrid[i][j-1]=='X'){ //to the left
            counter++;
          }
        }
        else if((i == 0) && (j != numColumns-1 && j != 0)){ //top row
          if(arrGrid[i][j]=='X'){
            counter++;
          }
          if(arrGrid[i][j-1]=='X'){ //to the left
            counter++;
          }
          if(arrGrid[i][j+1]=='X'){ //to the right
            counter++;
          }
          if(arrGrid[i+1][j-1]=='X'){ //left diagonal
            counter++;
          }
          if(arrGrid[i+1][j]=='X'){ //below
            counter++;
          }
          if(arrGrid[i+1][j+1]=='X'){ //right diagonal
            counter++;
          }
        }
        else if((i == numRows-1) && (j != numColumns-1 && j != 0)){ //bottom row
          if(arrGrid[i][j]=='X'){
            counter++;
          }
          if(arrGrid[i-1][j-1]=='X'){ //left diagonal
            counter++;
          }
          if(arrGrid[i-1][j]=='X'){ //above
            counter++;
          }
          if(arrGrid[i-1][j+1]=='X'){ //right diagonal
            counter++;
          }
          if(arrGrid[i][j-1]=='X'){ //to the left
            counter++;
          }
          if(arrGrid[i][j+1]=='X'){ //to the right
            counter++;
          }
        }
        else if((i != 0 && i != numRows-1) && (j == 0)){ // left column
          if(arrGrid[i][j]=='X'){
            counter++;
          }
          if(arrGrid[i-1][j]=='X'){ //above
            counter++;
          }
          if(arrGrid[i-1][j+1]=='X'){ //right above diagonal
            counter++;
          }
          if(arrGrid[i][j+1]=='X'){ //to the right
            counter++;
          }
          if(arrGrid[i+1][j+1]=='X'){ //right below diagonal
            counter++;
          }
          if(arrGrid[i+1][j]=='X'){ //below
            counter++;
          }
        }
        else if((i != 0 && i != numRows-1) && (j == numColumns-1)){ //far right column
          if(arrGrid[i][j]=='X'){
            counter++;
          }
          if(arrGrid[i-1][j]=='X'){ //above
            counter++;
          }
          if(arrGrid[i-1][j-1]=='X'){ //left above diagonal
            counter++;
          }
          if(arrGrid[i][j-1]=='X'){ //to the left
            counter++;
          }
          if(arrGrid[i+1][j-1]=='X'){ //left below diagonal
            counter++;
          }
          if(arrGrid[i+1][j]=='X'){ //below
            counter++;
          }
        }



        //fill new generation based off counter
        if(counter <=1){
          nextGeneration[i][j]='-';
        }else if(counter == 2){
          nextGeneration[i][j]= arrGrid[i][j];
        }else if(counter ==3){
          nextGeneration[i][j]= 'X';
        }
        else{
          nextGeneration[i][j]= '-';
        }
      } //exit j for loop
    } //exit i for loop
    if(outputChoice!=3){
      cout<<"new generation "<<endl;
      for(int i = 0;i<numRows;++i){
        for(int j = 0;j<numColumns;++j){

          cout<<nextGeneration[i][j];
        }

        cout<<endl;
      }
    }
    else{
      outFS<<"new generation: "<<endl;
      for(int i = 0;i<numRows;++i){
        for(int j = 0;j<numColumns;++j){

          outFS<<nextGeneration[i][j];
        }

        outFS<<endl;
      }
    }


    bool isEqual = true;
    for(int i = 0;i<numRows;++i){
      for(int j = 0;j<numColumns;++j){
        if(arrGrid[i][j]!=nextGeneration[i][j]){
          isEqual = false;
        }
      }
    }

    if(isEqual==true){
      cout<<"population stabalized. Press enter to break. "<<endl;
      cin.get();
      return;

    }
    // if(arrGrid)


    for(int i = 0;i<numRows;++i){
      for(int j = 0;j<numColumns;++j){
        arrGrid[i][j]=nextGeneration[i][j];
      }
    }


  }


}

//mirror mode with file name as parameter
void GameMode::mirrorMode(string fName){
    ofstream outFS;
    cout<<"Enter your output choice: "<<endl;
    cout<<"1 form a brief pause between generations"<<endl<<"2 to press the “enter” key" <<endl << "3 if you want to output to a file."<<endl;
    int outputChoice;
    cin>>outputChoice;
    if(outputChoice==3){
      string outFileName;
      cout<<"Enter the file name: "<<endl;
      cin>>outFileName;
      outFS.open(outFileName);
    }

    ifstream inFS;

    inFS.open(fName);
    if(!inFS.is_open()){
      cout<<"couldn't open file. "<<endl;
    }

    inFS >> numRows >> numColumns;
    char **arrGrid = Board::createMap(numRows, numColumns, inFS);





  char** nextGeneration;
  nextGeneration = new char*[numRows];
  for(int p = 0;p < numRows;++p){
    nextGeneration[p]= new char[numColumns];
  }

  //check for neighbors
  cout<<"MIRROR MODE "<<endl;
  int counter = 0;
  int genCount=0;
  while(true){
    if(outputChoice==2){
      cout<<"press enter to to produce another generation or control c to exit. "<<endl;
      cin.get();
    }
    else if(outputChoice==1){
      usleep(500000);
    }
  for(int i =0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){


        counter = 0;
        if(i!=0 && i!=(numRows-1) && j!= 0 && j!= (numColumns-1)){//middle squares
          if(arrGrid[i-1][j]=='X'){
            counter++;

                }
          if(arrGrid[i-1][j-1]=='X'){


            counter++;

                }
          if(arrGrid[i][j-1]=='X'){
            counter++;
          }
          if(arrGrid[i+1][j-1]=='X'){
            counter++;
          }
          if(arrGrid[i+1][j]=='X'){
            counter++;
          }
          if(arrGrid[i+1][j+1]=='X'){
            counter++;
          }
          if(arrGrid[i][j+1]=='X'){
            counter++;
          }
          if(arrGrid[i-1][j+1]=='X'){
            counter++;
          }
        }

        else if(i==0 && j==0 ){//top left corner
          // if(arrGrid[i][j]=='X'){
          //   counter+=3;
          // }
          if(arrGrid[i][j+1]=='X'){ //to the right
            counter++;
          }
          if(arrGrid[i+1][j+1]=='X'){ //right diagonal
            counter++;
          }
          if(arrGrid[i+1][j]=='X'){ //below
            counter++;
          }
          if(arrGrid[numRows-1][numColumns-1]=='X'){
            counter++;
          }
          if(arrGrid[i][numColumns-1]=='X'){
            counter++;
          }
          if(arrGrid[i+1][numColumns-1]=='X'){
            counter++;
          }
          if(arrGrid[numRows-1][j]=='X'){
            counter++;
          }
          if(arrGrid[numRows-1][j+1]=='X'){
            counter++;
          }

        }

        else if(i==0 && j ==(numColumns-1)){ //top right corner
          if(arrGrid[i][j]=='X'){
            counter+=3;
          }
          if(arrGrid[i][j-1]=='X'){ //to the left
            counter++;
          }
          if(arrGrid[i+1][j-1]=='X'){ //left diagonal
            counter++;
          }
          if(arrGrid[i+1][j]=='X'){ //below
            counter++;
          }
        }

        else if(i ==(numRows-1) && j ==0){//bottom left corner
          if(arrGrid[i][j]=='X'){
            counter+=3;
          }
          if(arrGrid[i-1][j]=='X'){ //above
            counter++;
          }
          if(arrGrid[i-1][j+1]=='X'){ //right diagonal
            counter++;
          }
          if(arrGrid[i][j+1]=='X'){ //to the right
            counter++;
          }
        }

        else if(i ==(numRows-1)&& j ==(numColumns-1)){ //bottom right corner
          if(arrGrid[i][j]=='X'){
            counter+=3;
          }
          if(arrGrid[i-1][j]=='X'){ //above
            counter++;
          }
          if(arrGrid[i-1][j-1]=='X'){ //left diagonal
            counter++;
          }
          if(arrGrid[i][j-1]=='X'){ //to the left
            counter++;
          }
        }
        else if((i == 0) && (j != numColumns-1 && j != 0)){ //top row
          if(arrGrid[i][j]=='X'){
            counter++;
          }
          if(arrGrid[i][j-1]=='X'){ //to the left
            counter++;
          }
          if(arrGrid[i][j+1]=='X'){ //to the right
            counter++;
          }
          if(arrGrid[i+1][j-1]=='X'){ //left diagonal
            counter++;
          }
          if(arrGrid[i+1][j]=='X'){ //below
            counter++;
          }
          if(arrGrid[i+1][j+1]=='X'){ //right diagonal
            counter++;
          }
        }
        else if((i == numRows-1) && (j != numColumns-1 && j != 0)){ //bottom row
          if(arrGrid[i][j]=='X'){
            counter++;
          }
          if(arrGrid[i-1][j-1]=='X'){ //left diagonal
            counter++;
          }
          if(arrGrid[i-1][j]=='X'){ //above
            counter++;
          }
          if(arrGrid[i-1][j+1]=='X'){ //right diagonal
            counter++;
          }
          if(arrGrid[i][j-1]=='X'){ //to the left
            counter++;
          }
          if(arrGrid[i][j+1]=='X'){ //to the right
            counter++;
          }
        }
        else if((i != 0 && i != numRows-1) && (j == 0)){ // left column
          if(arrGrid[i][j]=='X'){
            counter++;
          }
          if(arrGrid[i-1][j]=='X'){ //above
            counter++;
          }
          if(arrGrid[i-1][j+1]=='X'){ //right above diagonal
            counter++;
          }
          if(arrGrid[i][j+1]=='X'){ //to the right
            counter++;
          }
          if(arrGrid[i+1][j+1]=='X'){ //right below diagonal
            counter++;
          }
          if(arrGrid[i+1][j]=='X'){ //below
            counter++;
          }
        }
        else if((i != 0 && i != numRows-1) && (j == numColumns-1)){ //far right column
          if(arrGrid[i][j]=='X'){
            counter++;
          }
          if(arrGrid[i-1][j]=='X'){ //above
            counter++;
          }
          if(arrGrid[i-1][j-1]=='X'){ //left above diagonal
            counter++;
          }
          if(arrGrid[i][j-1]=='X'){ //to the left
            counter++;
          }
          if(arrGrid[i+1][j-1]=='X'){ //left below diagonal
            counter++;
          }
          if(arrGrid[i+1][j]=='X'){ //below
            counter++;
          }
        }


        //fill new generation based off counter
        if(counter <=1){
          nextGeneration[i][j]='-';
        }else if(counter == 2){
          nextGeneration[i][j]= arrGrid[i][j];
        }else if(counter ==3){
          nextGeneration[i][j]= 'X';
        }
        else{
          nextGeneration[i][j]= '-';
        }
      } //exit j for loop
    } //exit i for loop


    if(outputChoice!=3){
      cout<<"new generation "<<endl;
      for(int i = 0;i<numRows;++i){
        for(int j = 0;j<numColumns;++j){

          cout<<nextGeneration[i][j];
        }

        cout<<endl;
      }
    }
    else{
      outFS<<"new generation: "<<endl;
      for(int i = 0;i<numRows;++i){
        for(int j = 0;j<numColumns;++j){

          outFS<<nextGeneration[i][j];
        }

        outFS<<endl;
      }
    }

    bool isEqual = true;
    for(int i = 0;i<numRows;++i){
      for(int j = 0;j<numColumns;++j){
        if(arrGrid[i][j]!=nextGeneration[i][j]){
          isEqual = false;
        }
      }
    }

    if(isEqual==true){
      cout<<"population stabalized. Press enter to break. "<<endl;
      cin.get();
      return;

    }
    // if(arrGrid)


    for(int i = 0;i<numRows;++i){
      for(int j = 0;j<numColumns;++j){
        arrGrid[i][j]=nextGeneration[i][j];
      }
    }


  }




}
