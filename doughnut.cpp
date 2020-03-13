/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 2 - Game of Life
  Implementing methods for a game in Doughnut mode
 */
#include "doughnut.h"

using namespace std;
// Initilizes 2d array grid using population density and number of rows and column
char** Doughnut::init(int rows, int cols, float density){
  char **gen = new char*[rows]; // declaring 2d array pointer
  for(int i = 0; i < rows; ++i) { //iterating through to fill the array
      gen[i] = new char[cols];
  }

  for(int i = 0; i < rows; ++i){// nested for loop to fill the aray randomly with X and -
    for(int j = 0; j < cols; ++j){
      float random = rand() / (float)RAND_MAX; //generating a random float between 0 and 1 for population density
      if(random <= density){
        gen[i][j] = 'X'; //filling element with an X
      }else{
        gen[i][j] = '-'; //filling element with a -
      }
    }
  }
  return gen;
}


Doughnut::Doughnut(){ //default constructor
  currGen = init(5,5, 0.7); //initializing the current generation with 5 rows, 5 columns, and a pop. density of 0.7
  nextGen = init(5,5, 0.0); //initializing the next generation with 5 rows, 5 columns, and a pop. density of 0.0
  m_genCount = 0; //initlizing the generation count to 0
  m_rows = 5;//initlizing the rows to match init()
  m_columns = 5;//initlizing the columns to match init()
}

Doughnut::Doughnut(int rows, int columns, float density){ //overloaded constructor
  currGen = init(rows, columns, density);//initliazing currGen with the parameters passed
  nextGen = init(rows, columns, 0.0);//initliazing nextGen with the parameters passed
  m_genCount = 0;
  m_rows = rows;
  m_columns = columns;
}

Doughnut::Doughnut(char** map, int rows, int columns){//constructor where we will pass in a 2d array that is read in from a txt file
  currGen = map;//assigning currgen to match the grid that was read in
  nextGen = init(rows, columns, 0.0);//initliazing nextGen with the parameters passed and pop. density 0.0
  m_genCount = 0;
  m_rows = rows;
  m_columns = columns;
}


Doughnut::~Doughnut(){//destructor
  delete currGen;
  delete nextGen;
}


bool Doughnut::isEmpty(){//isEmpty() function to check if the 2d array is empty
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; j < m_columns; ++j){
      if(currGen[i][j] == 'X'){//if there is a single X in the array the function will return false
        return false;
      }else{
        continue;
      }
    }
  }
  return true;//if we reached this point there are no 'X' in the array and we can return true
}

bool Doughnut::isStable(){//isStable() funtion will return true if the currGen is ever equal to nextGen(unless it is empty)
  return m_stable;
}

void Doughnut::DisplayGen(){//DisplayGen() funtion will print all elements of the 2d array to the console
  cout << "Generation " << m_genCount << endl;//printing which generation you are seeing in the console
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; j < m_columns; ++j){
      cout << currGen[i][j];
    }
    cout << endl;
  }
}

void Doughnut::PrintGen(string file){//printing the generation to a text file
  ofstream fout;//initializing an ofstream
  fout.open(file, ios::app);//opening the output stream
  fout << "Generation " << m_genCount << endl;//printing which generation you are seeing
  for(int i = 0; i < m_rows; ++i){//iterating
    for(int j = 0; j < m_columns; ++j){
      fout << currGen[i][j];
    }
    fout << endl;
  }
}

void Doughnut::Simulate(){//simulate function generates the next generation based on the current generation
  for(int i = 0; i < m_rows; ++i){
    for(int j = 0; j < m_columns; ++j){
      int neighbors = findAlive(i,j);//finding the number of alive neighbors for each cell
      if(neighbors <= 1){
        nextGen[i][j] = '-';//if there are 1 or less neighbors the cell dies of loneliness
      }else if(neighbors == 2){
        if(currGen[i][j] == 'X'){//if there are two neighbors the cell remains stable
          nextGen[i][j] = 'X';
        }else{
          nextGen[i][j] = '-';//if there are two neighbors and the cell is not filled it remains empty
        }
      }else if(neighbors == 3){
        if(currGen[i][j] == 'X'){
          nextGen[i][j] = 'X';//for an occupied cell with three neighbors it remains stable
        }else{
          nextGen[i][j] = 'X';//for an unoccupied cell with three neighbors a new cell is born
        }
      }else{
        nextGen[i][j] = '-';//if there are four or more neighbors the cell dies of overcrowding
      }
    }
  }
  bool loop = true;//boolean to help control the double for loop
  for(int i = 0; i < m_rows && loop; ++i){//notice the second part of the boolean statement
    for(int j = 0; j < m_columns && loop; ++j){
      if(currGen[i][j] == nextGen[i][j]){//if the current generation is the same as the next it is stable
        m_stable = true;
      }else{//as soon as there is a difference in the generations we set stable to false and break from both for loops
        m_stable = false;
        loop = false;
      }
    }
  }
  currGen = nextGen;//reassigning current to next
  nextGen = init(m_rows, m_columns, 0.0);//setting next to an empty grid
  m_genCount++;//incrementing
}


int Doughnut::findAlive(int currRow, int currColumn){//this function is used to find the number of living neighbors for each element in the array
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
