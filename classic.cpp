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
  currGen = new char[rows][columns];
  nextGen = new char[rows][columns];
  m_genCount = 0;
  m_rows = rows;
  m_columns = columns;
}
