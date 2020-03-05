#include "doughnut.h"

char** Doughnut::init(int rows, int cols){
  char **gen = new char*[rows];
  for(int i = 0; i < rows; ++i) {
      gen[i] = new char[cols];
  }
  return gen;
}

Doughnut::Doughnut(){
  currGen = init(5,5); // how big should we make the default //good question, also shouldnt we dynamically allocate these to memory with pointers right off the bat?
  nextGen = init(5,5);
  m_genCount = 0;
  m_rows = 5;
  m_columns = 5;
}

Doughnut::Doughnut(int rows, int columns){
  currGen = init(rows, columns); //Cannot initialize 2d array pointer like this but I haven't changed it yet
  nextGen = init(rows, columns);
  m_genCount = 0;
  m_rows = rows;
  m_columns = columns;
}

Doughnut::~Doughnut(){
  delete currGen;
  delete nextGen;
}
