#include "mirror.h"

using namespace std;

char** Mirror::init(int rows, int cols, float density){
  char **gen = new char*[rows];
  for(int i = 0; i < rows; ++i) {
      gen[i] = new char[cols];
  }

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      float random = rand() / (float)RAND_MAX;
      if(random <= density){
        gen[i][j] = 'X';
      }else{
        gen[i][j] = '-';
      }
    }
  }
  return gen;
}


Mirror::Mirror(){
  currGen = init(5,5, 0.7);
  nextGen = init(5,5, 0.0);
  m_genCount = 0;
  m_rows = 5;
  m_columns = 5;
}

Mirror::Mirror(int rows, int columns, float density){
  currGen = init(rows, columns, density);
  nextGen = init(rows, columns, 0.0);
  m_genCount = 0;
  m_rows = rows;
  m_columns = columns;
}

Mirror::Mirror(char** map, int rows, int columns){
  currGen = map;
  nextGen = init(rows, columns, 0.0);
  m_genCount = 0;
  m_rows = rows;
  m_columns = columns;
}

Mirror::~Mirror(){
  delete currGen;
  delete nextGen;
}

bool Mirror::isEmpty(){
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; j < m_columns; ++j){
      if(currGen[i][j] == 'X'){
        return false;
      }else{
        continue;
      }
    }
  }
  return true;
}

bool Mirror::isStable(){
  return m_stable;
}

void Mirror::DisplayGen(){
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; j < m_columns; ++j){
      cout << currGen[i][j];
    }
    cout << endl;
  }
}

void Mirror::PrintGen(string file){
  ofstream fout;
  fout.open(file, ios::app);
  fout << "Generation " << m_genCount << endl;
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; j < m_columns; ++j){
      fout << currGen[i][j];
    }
    fout << endl;
  }
}

void Mirror::Simulate(){
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; j < m_columns; ++j){
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
  bool loop = true;
  for(int i = 0; i < m_rows && loop; ++i){
    for(int j = 0; j < m_columns && loop; ++j){
      if(currGen[i][j] == nextGen[i][j]){
        m_stable = true;
      }else{
        m_stable = false;
        loop = false;
      }
    }
  }
  currGen = nextGen;
  nextGen = init(m_rows, m_columns, 0.0);
  m_genCount++;
}



int Mirror::findAlive(int currRow, int currColumn){
  int count = 0;
  if(currRow == 0 && currColumn == 0){ // check top left corner
    if(currGen[currRow][currColumn] == 'X'){
      count += 3;
    }if(currGen[currRow][currColumn+1] == 'X'){
      count += 2;
    }if(currGen[currRow+1][currColumn] == 'X'){
      count += 2;
    }if(currGen[currRow+1][currColumn+1] == 'X'){
      count++;
    }
  }else if(currRow = (m_rows-1) && currColumn == 0){ // check bottom left corner
    if(currGen[currRow][currColumn] == 'X'){
      count += 3;
    }if(currGen[currRow-1][currColumn] == 'X'){
      count += 2;
    }if(currGen[currRow][currColumn+1]){
      count += 2;
    }if(currGen[currRow-1][currColumn-1]){
      count++;
    }
  }else if(currRow == 0 && currColumn == (m_columns - 1)){ // Check top right corner
    if(currGen[currRow][currColumn] == 'X'){
      count += 3;
    }if(currGen[currRow][currColumn-1] == 'X'){
      count += 2;
    }if(currGen[currRow+1][currColumn] == 'X'){
      count += 2;
    }if(currGen[currRow+1][currColumn-1] == 'X'){
      count++;
    }
  } else if(currRow == (m_rows -1)  && currColumn == (m_columns -1)){ // Check bottom right corner
    if(currGen[currRow][currColumn] == 'X'){
      count += 3;
    }if(currGen[currRow-1][currColumn] == 'X'){
      count += 2;
    }if(currGen[currRow][currColumn-1] == 'X'){
      count += 2;
    }if(currGen[currRow-1][currColumn-1] == 'X'){
      count++;
    }
  } else if(currRow == 0 && (currColumn != 0 && currColumn != (m_columns - 1))){ // checks top row
    if(currGen[currRow][currColumn] == 'X'){
      count++;
    }if(currGen[currRow][currColumn-1] == 'X'){
      count += 2;
    }if(currGen[currRow][currColumn+1] == 'X'){
      count += 2;
    }if(currGen[currRow+1][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn+1] == 'X'){
      count++;
    }
  } else if(currRow == (m_rows - 1) && (currColumn != 0 && currColumn != (m_columns - 1))){ // check bottom row
    if(currGen[currRow][currColumn] == 'X'){
      count++;
    }if(currGen[currRow][currColumn-1] == 'X'){
      count += 2;
    }if(currGen[currRow][currColumn+1] == 'X'){
      count += 2;
    }if(currGen[currRow-1][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn+1] == 'X'){
      count++;
    }
  } else if(currColumn == 0 && (currRow != 0 && currRow != (m_rows - 1))){ // check left column
    if(currGen[currRow][currColumn] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn] == 'X'){
      count += 2;
    }if(currGen[currRow-1][currColumn] == 'X'){
      count += 2;
    }if(currGen[currRow][currColumn+1] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn+1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn+1] == 'X'){
      count++;
    }
  } else if(currColumn == (m_columns -1) && (currRow!= 0 && currRow != (m_rows-1))){ // check right column
    if(currGen[currRow][currColumn] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn] == 'X'){
      count += 2;
    }if(currGen[currRow-1][currColumn] == 'X'){
      count += 2;
    }if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn-1] == 'X'){
      count++;
    }
  }else{ // Checks for all cells not on boundary
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
    }
  }

  return count;
}
