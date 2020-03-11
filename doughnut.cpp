#include "doughnut.h"

using namespace std;

char** Doughnut::init(int rows, int cols, float density){
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


Doughnut::Doughnut(){
  currGen = init(5,5, 0.7);
  nextGen = init(5,5, 0.0);
  m_genCount = 0;
  m_rows = 5;
  m_columns = 5;
}

Doughnut::Doughnut(int rows, int columns, float density){
  currGen = init(rows, columns, density);
  nextGen = init(rows, columns, 0.0);
  m_genCount = 0;
  m_rows = rows;
  m_columns = columns;
}

Doughnut::Doughnut(char** map, int rows, int columns){
  currGen = map;
  nextGen = init(rows, columns, 0.0);
  m_genCount = 0;
  m_rows = rows;
  m_columns = columns;
}


Doughnut::~Doughnut(){
  delete currGen;
  delete nextGen;
}


bool Doughnut::isEmpty(){
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

bool Doughnut::isStable(){
  return m_stable;

}

void Doughnut::DisplayGen(){
  cout << "Generation " << m_genCount << endl;
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; j < m_columns; ++j){
      cout << currGen[i][j];
    }
    cout << endl;
  }
}

void Doughnut::PrintGen(ofstream& out){
  cout << "Generation " << m_genCount << endl;
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; j < m_columns; ++j){
      out << currGen[i][j];
    }
    out << endl;
  }
}

void Doughnut::Simulate(){
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


int Doughnut::findAlive(int currRow, int currColumn){
  int count = 0;

  if(currRow == 0 && currColumn == 0){ // Check top left corner
    if(currGen[currRow+1][currColumn] == 'X'){//1
      count++;
    }if(currGen[currRow+1][currColumn+1] == 'X'){//2
      count++;
    }if(currGen[currRow][currColumn+1] == 'X'){//3
      count++;
    }if(currGen[currRow][m_columns - 1] == 'X'){//4
      count++;
    }if(currGen[currRow+1][m_columns - 1] == 'X'){//5
      count++;
    }if(currGen[m_rows-1][m_columns - 1] == 'X'){//6
      count++;
    }if(currGen[m_rows - 1][currColumn] == 'X'){//7
      count++;
    }if(currGen[m_rows - 1][currColumn+1] == 'X'){//8
      count++;
    }

  }else if (currRow == (m_rows-1) && currColumn == 0){ // Check bottom left corner
    if(currGen[currRow-1][currColumn] == 'X'){//1
      count++;
    }if(currGen[currRow-1][currColumn+1] == 'X'){//2
      count++;
    }if(currGen[currRow][currColumn+1] == 'X'){//3
      count++;
    }if(currGen[0][currColumn] == 'X'){//4
      count++;
    }if(currGen[0][currColumn+1] == 'X'){//5
      count++;
    }if(currGen[0][m_columns - 1] == 'X'){//6
      count++;
    }if(currGen[currRow][m_columns - 1] == 'X'){//7
      count++;
    }if(currGen[currRow-1][m_columns - 1] == 'X'){//8
      count++;
    }

  }else if (currRow == 0 && currColumn == (m_columns - 1)){ // Check top right corner
    if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn-1] == 'X'){
      count++;
    }if(currGen[m_rows-1][currColumn] == 'X'){
      count++; // SAME AS LAST TWO
    }if(currGen[m_rows-1][currColumn-1] == 'X'){
      count++; //SAME
    }if(currGen[m_rows-1][0] == 'X'){
      count++;
    }if(currGen[currRow][0] == 'X'){
      count++;
    }if(currGen[currRow+1][0] == 'X'){
      count++;
    }
  }else if (currRow == (m_rows - 1) && currColumn == (m_columns - 1)){ // Check bottom right corner
    if(currGen[currRow][currColumn-1] == 'X'){//1
      count++;
    }if(currGen[currRow-1][currColumn-1] == 'X'){//2
      count++;
    }if(currGen[currRow-1][currColumn] == 'X'){//3
      count++;
    }if(currGen[currRow-1][0] == 'X'){//4
      count++;
    }if(currGen[currRow][0] == 'X'){//5
      count++;
    }if(currGen[0][0] == 'X'){//6
      count++;
    }if(currGen[0][currColumn] == 'X'){//7
      count++;
    }if(currGen[0][currColumn-1] == 'X'){//8
      count++;
    }

  }else if(currRow == 0 && (currColumn != 0 && currColumn != (m_columns - 1))){ // Checks top row
    if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn+1] == 'X'){
      count++;
    }if(currGen[currRow][currColumn+1] == 'X'){
      count++;
    }if(currGen[m_rows - 1][currColumn+1] == 'X'){
      count++;
    }if(currGen[m_rows - 1][currColumn] == 'X'){
      count++;
    }if(currGen[m_rows - 1][currColumn-1] == 'X'){
      count++;
    }

  }else if (currRow == (m_rows - 1) && (currColumn != 0 && currColumn != (m_columns - 1))){ //Checks bottom row
    if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn+1] == 'X'){
      count++;
    }if(currGen[currRow][currColumn+1] == 'X'){
      count++;
    }if(currGen[0][currColumn+1] == 'X'){
      count++;
    }if(currGen[0][currColumn] == 'X'){
      count++;
    }if(currGen[0][currColumn-1] == 'X'){
      count++;
    }

  }else if (currColumn == 0 && (currRow != 0 && currRow != (m_rows - 1))){ // Checks left column
    if(currGen[currRow-1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn+1] == 'X'){
      count++;
    }if(currGen[currRow][currColumn+1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn+1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow+1][m_columns - 1] == 'X'){
      count++;
    }if(currGen[currRow][m_columns - 1] == 'X'){
      count++;
    }if(currGen[currRow-1][m_columns - 1] == 'X'){
      count++;
    }

  }else if (currColumn == (m_columns -1) && (currRow!= 0 && currRow != (m_rows-1))){ // Checks right column
    if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow-1][0] == 'X'){
      count++;
    }if(currGen[currRow][0] == 'X'){
      count++;
    }if(currGen[currRow+1][0] == 'X'){
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
    }
  }

  return count;
}
