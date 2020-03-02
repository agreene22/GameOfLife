#include "classic.h"
using namespace std;
//i think throughout the code whenever we use the name currGen or nextGen we might have to put the dereference operator because we are referencing the pointer
Classic::Classic(){
  currGen = new char[5][5]; // how big should we make the default //good question, also shouldnt we dynamically allocate these to memory with pointers right off the bat?
  nextGen = new char[5][5];
  m_genCount = 0;
  m_rows = 5;
  m_columns = 5;
  char* current = &currGen; //or do we need this because we already declared them as pointers in the header file?
  char* next = &nextGen;
}

Classic::Classic(int rows, int columns){
  currGen = new char[rows][columns]; //Cannot initialize 2d array pointer like this but I haven't changed it yet
  nextGen = new char[rows][columns];
  m_genCount = 0;
  m_rows = rows;
  m_columns = columns;
  char* current = &currGen;
  char* next = &nextGen;
}

Classic::~Classic(){
  delete currGen;
  delete nextGen;
}

void Classic::DisplayGen(char* currGen){ //rename parameters
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; j < m_columns; ++j){
      cout << currGen[i][j];
    }
    cout << endl;
  }
}

void Classic::Simulate(char* currGen){  //i think our parameters should be named something else so we dont confuse it with the member variable
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; i < m_columns; ++j){
      int neighbors = findAlive(i,j);
      if(neighbors <= 1){
        nextGen[i][j] = '-';
      }else if(neighbors == 2){
        if(currGen[i][j] == 'X'){
          nextGen[i][j] = 'X';
        }else{
          nextGen[i][j] = '-';
        }
      }else if(neighbors == 3){
        if(currGen[i][j] == 'X'){
          nextGen[i][j] = 'X';
        }else{
          nextGen[i][j] = 'X';
        }
      }else{
        nextGen[i][j] = '-';
      }
    }
  }
  currGen = nextGen; //i think this is good since theyre already pointers
  m_genCount++;
}



int Classic::findAlive(int currRow, int currColumn){
  int count = 0;

  if(currRow == 0 && currColumn == 0){ // Check top left corner
    if(currGen[currRow][currColumn+1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn+1] == 'X'){
      count++;
    }
  }else if (currRow == (m_rows-1) && currColumn == 0){ // Check bottom left corner
    if(currGen[currRow][currColumn+1] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn+1] == 'X'){
      count++;
    }
  }else if (currRow == 0 && currColumn == (m_columns-1)){ // Check top right corner
    if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }
  }else if (currRow == (m_rows-1) && currColumn == (m_columns-1)){ // Check bottom right corner
    if(currGen[currRow-1][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }
  }else if(currRow == 0 && (currColumn != 0 || currColumn != (m_columns - 1))){ // Checks top row
    if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow][currColumn+1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn+1] == 'X'){
      count++;
    }
  }else if (currRow == (m_rows-1) && (currColumn != 0 || currColumn != (m_columns -1))){ //Checks bottom row
    if(currGen[currRow-1][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn+1] == 'X'){
      count++;
    }if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow][currColumn+1] == 'X'){
      count++;
    }
  } else if (currColumn == 0 && (currRow != 0 || currRow != (m_rows - 1))){ // Checks left column
    if(currGen[currRow-1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn+1] == 'X'){
      count++;
    }if(currGen[currRow][currColumn+1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn+1] == 'X'){
      count++;
    }
  }else if (currColumn == (m_columns -1) && (currRow!= 0 || currRow != (m_rows-1))){ // Checks right column
    if(currGen[currRow-1][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }
  }
  else{ // Checks for all cells not on boundary
    if(currGen[currRow-1][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn+1] == 'X'){
      count++;
    }if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow][currColumn+1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn+1] == 'X'){
      count++;
    } //nice
  }

  return count;
}
