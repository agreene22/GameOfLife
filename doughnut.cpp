#include "doughnut.h"

Doughnut::Doughnut(){
  currGen = new char[5][5]; // how big should we make the default //good question, also shouldnt we dynamically allocate these to memory with pointers right off the bat?
  nextGen = new char[5][5];
  m_genCount = 0;
  m_rows = 5;
  m_columns = 5;
}

Doughnut::Doughnut(){
  currGen = new char[rows][columns]; //Cannot initialize 2d array pointer like this but I haven't changed it yet
  nextGen = new char[rows][columns];
  m_genCount = 0;
  m_rows = rows;
  m_columns = columns;
}

Doughnut::~Doughnut(){
  delete currGen;
  delete nextGen;
}
