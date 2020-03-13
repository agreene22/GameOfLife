/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 2 - Game of Life
  Method implementation for a game in classic mode
 */
#include "classic.h"

using namespace std;

// Initilizes 2d array grid using population density and number of rows and column
char** Classic::init(int rows, int cols, float density){
  char** gen = new char*[rows]; // declaring 2d array pointer
  for(int i = 0; i < rows; ++i) {
      gen[i] = new char[cols];
  }

  for(int i = 0; i < rows; ++i){ // nested for loop to fill the aray randomly with X and -
    for(int j = 0; j < cols; ++j){
      float random = rand() / (float)RAND_MAX; // generates random number for filling based on density
      if(random <= density){
        gen[i][j] = 'X'; // filling array with X for occupied
      }else{
        gen[i][j] = '-'; // filling array with - for empty
      }
    }
  }
  return gen; // returns 2d array pointer
}

// overloaded constructor if file map is provided, taking in pointer, integer for rows, integer for columns
Classic::Classic(char** map, int rows, int columns){
  currGen = map; // setting current generation to match the map file
  nextGen = init(rows, columns, 0.0); // initlizing empty next generation
  m_genCount = 0; // setting generation count to 0
  m_rows = rows; // setting m_rows to userRows
  m_columns = columns; // setting m_columns to userColumns
}

// overloaded constructor for random generation taking in integer for rows, integer for columns, float for population density
Classic::Classic(int rows, int columns, float density){
  currGen = init(rows, columns, density); // initializing current generation with user rows, columns, and initial density
  nextGen = init(rows, columns, 0.0); //initializing empty next generation
  m_genCount = 0; // setting generation count to 0
  m_rows = rows; // setting m_rows to user Rows
  m_columns = columns; // setting m_columns to user columns
}

// destructor to delete pointers
Classic::~Classic(){
  delete currGen;
  delete nextGen;
}

// Checks if the generation has all died and returns a boolean
bool Classic::isEmpty(){
  for(int i = 0; i < m_rows; ++i){ // nested for loop to check the array for an occupied cell
    for(int j = 0; j < m_columns; ++j){
      if(currGen[i][j] == 'X'){ // if a cell is occupied return false
        return false;
      }else{ // else continue checking the rest of the array
        continue;
      }
    }
  }
  return true; // if no occupied cell is found return true
}

// Checks if the generations stabilized
bool Classic::isStable(){
  return m_stable; // returns boolean if the generations have stabilized
}

// Prints generation to the console
void Classic::DisplayGen(){
  cout << "Generation " << m_genCount << endl; // Displaying generation count
  for(int i = 0; i < m_rows; ++i){ // nested for loop to print each element of the array
    for(int j = 0; j < m_columns; ++j){
      cout << currGen[i][j];
    }
    cout << endl; // print line break after each row
  }
}

// Writes generation to the output file
void Classic::PrintGen(string file){
  ofstream fout; // declaring file output stream
  fout.open(file, ios::app); // opening output stream
  fout << "Generation " << m_genCount << endl; // Writing generation count
  for(int i = 0; i < m_rows; ++i){ // nested for loop to write each element of the array
    for(int j = 0; j < m_columns; ++j){
      fout << currGen[i][j];
    }
    fout << endl; // writing a line break after each row
  }
}

// Generates next generation based on current generation
void Classic::Simulate(){
  for(int i = 0; i < m_rows; ++i){ // nested for loop to go through the current array and check neighbors
    for(int j = 0; j < m_columns; ++j){
      int neighbors = findAlive(i,j); // Calls find alive method and returns number of neighbors
      if(neighbors <= 1){ // If less than one neighbor the cell dies
        nextGen[i][j] = '-';
      }else if(neighbors == 2){ // If there are 2 neighbors the cell stays stable
        if(currGen[i][j] == 'X'){ // If occupied it remains occupied
          nextGen[i][j] = 'X';
        }else{
          nextGen[i][j] = '-'; // If dead it remains dead
        }
      }else if(neighbors == 3){ // If there are 3 neighbors the cell is alive
        if(currGen[i][j] == 'X'){ // If occupied it remains occupied
          nextGen[i][j] = 'X';
        }else{ // If empty a new cell populates
          nextGen[i][j] = 'X';
        }
      }else{ // Else cell dies from overcrowding
        nextGen[i][j] = '-';
      }
    }
  }
  bool loop = true; // boolean to represent continuation of the loop
  for(int i = 0; i < m_rows && loop; ++i){ // nested for loop to check if current generation is the same as next generation
    for(int j = 0; j < m_columns && loop; ++j){
      if(currGen[i][j] == nextGen[i][j]){
        m_stable = true; // if they are the same they are true
      }else{ // if any cell differs it remains false
        m_stable = false;
        loop = false;
      }
    }
  }
  currGen = nextGen; // setting current generation pointer to next generation
  nextGen = init(m_rows, m_columns, 0.0); // nulling next generation pointer
  m_genCount++; // increasing generation count
}


// Finds number of alive neighbors for a cell based on current position and returns count
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
  }else if (currRow == 0 && currColumn == (m_columns - 1)){ // Check top right corner
    if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow+1][currColumn] == 'X'){
      count++;
    }
  }else if (currRow == (m_rows - 1) && currColumn == (m_columns - 1)){ // Check bottom right corner
    if(currGen[currRow-1][currColumn-1] == 'X'){
      count++;
    }if(currGen[currRow-1][currColumn] == 'X'){
      count++;
    }if(currGen[currRow][currColumn-1] == 'X'){
      count++;
    }
  }else if(currRow == 0 && (currColumn != 0 && currColumn != (m_columns - 1))){ // Checks top row
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
  }else if (currRow == (m_rows - 1) && (currColumn != 0 && currColumn != (m_columns - 1))){ //Checks bottom row
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
  }else if (currColumn == 0 && (currRow != 0 && currRow != (m_rows - 1))){ // Checks left column
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
  }else if (currColumn == (m_columns -1) && (currRow!= 0 && currRow != (m_rows-1))){ // Checks right column
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
    }
  }
  return count;
}
