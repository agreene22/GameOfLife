#include "classic.h"
using namespace std;

Classic::Classic(){
  currGen = new char[5][5]; // how big should we make the default
  nextGen = new char[5][5];
  m_genCount = 0;
  m_rows = 5;
  m_columns = 5;
}

Classic::Classic(int rows, int columns){
  currGen = new char[rows][columns]; //Cannot initialize 2d array pointer like this but I haven't changed it yet
  nextGen = new char[rows][columns];
  m_genCount = 0;
  m_rows = rows;
  m_columns = columns;
}

Classic::~Classic(){
  delete currGen;
  delete nextGen;
}

void Classic::DisplayGen(char *currGen){
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; j < m_columns; ++j){
      cout << currGen[i][j];
    }
    cout << endl;
  }
}

void Classic::Simulate(char *currGen){
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; i < m_columns; ++j){
      int count = findAlive(i,j);
      if(count <= 1){
        nextGen[i][j] = '-';
      } else if(count == 2){
        if(currGen[i][j] == 'X'){
          nextGen[i][j] == 'X';
        } else{
          nextGen[i][j] == '-';
        }
      } else if(count == 3){
        nextGen[i][j] == 'X';
      } else{
        nextGen[i][j] == '-';
      }
    }
  }
  currGen = nextGen; // idk if this is right or if I should dereference nextGen
  m_genCount++;
}

int Classic::findAlive(int currRow, int currColumn){
  int count;
  if(currGen[currRow][currColumn] == 'X'){
    count = -1;
  }else{
    count = 0;
  }

  if(currRow == 0 && currColumn == 0){ // Check top left corner
    if(currGen[currRow][currColumn+1] == 'X'){
      count++;
    }
    if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }
    if(currGen[currRow+1][currColumn+1] == 'X'){
      count++;
    }
  } else if (currRow == (m_rows-1) && currColumn == 0){ // Check bottom left corner
    if(currGen[currRow][currColumn+1] == 'X'){
      count++;
    }
    if(currGen[currRow-1][currColumn] == 'X'){
      count++;
    }
    if(currGen[currRow-1][currColumn+1] == 'X'){
      count++;
    }
  } else if (currRow == 0 && currColumn == (m_columns-1)){ // Check top right corner
    if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }
    if(currGen[currRow+1][currColumn-1] == 'X'){
      count++;
    }
    if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }
  } else if (currRow == (m_rows-1) && currColumn == (m_columns-1)){ // Check bottom right corner
    if(currGen[currRow-1][currColumn-1] == 'X'){
      count++;
    }
    if(currGen[currRow-1][currColumn] == 'X'){
      count++;
    }
    if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }
  }

  else if(currRow == 0 && currColumn != 0){ // Checks top row
    if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }
    if(currGen[currRow][currColumn+1] == 'X'){
      count++;
    }
    if(currGen[currRow+1][currColumn-1] == 'X'){
      count++;
    }
    if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }
    if(currGen[currRow+1][currColumn+1] == 'X'){
      count++;
    }
  }else if (currRow == (m_rows-1) && currColumn != (m_columns -1)){ //Checks bottom row
    if(currGen[currRow-1][currColumn-1] == 'X'){
      count++;
    }
    if(currGen[currRow-1][currColumn] == 'X'){
      count++;
    }
    if(currGen[currRow-1][currColumn+1] == 'X'){
      count++;
    }
    if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }
    if(currGen[currRow][currColumn+1] == 'X'){
      count++;
    }
  } else if (currColumn == 0 && currRow != 0){ // Checks left column
    if(currGen[currRow-1][currColumn] == 'X'){
      count++;
    }
    if(currGen[currRow-1][currColumn+1] == 'X'){
      count++;
    }
    if(currGen[currRow][currColumn+1] == 'X'){
      count++;
    }
    if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }
    if(currGen[currRow+1][currColumn+1] == 'X'){
      count++;
    }
  } else if (currColumn == (m_columns -1) && currRow != (m_rows-1)){ // Checks right column
    if(currGen[currRow-1][currColumn-1] == 'X'){
      count++;
    }
    if(currGen[currRow-1][currColumn] == 'X'){
      count++;
    }
    if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }
    if(currGen[currRow+1][currColumn-1] == 'X'){
      count++;
    }
    if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }
  }
  else{ // Checks for all cells not on boundary
    if(currGen[currRow-1][currColumn-1] == 'X'){
      count++;
    }
    if(currGen[currRow-1][currColumn] == 'X'){
      count++;
    }
    if(currGen[currRow-1][currColumn+1] == 'X'){
      count++;
    }
    if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }
    if(currGen[currRow][currColumn+1] == 'X'){
      count++;
    }
    if(currGen[currRow+1][currColumn-1] == 'X'){
      count++;
    }
    if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }
    if(currGen[currRow+1][currColumn+1] == 'X'){
      count++;
    }
  }

  return count;
}
