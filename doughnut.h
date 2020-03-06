#include <iostream>

class Doughnut{
public:
  Doughnut();
  Doughnut(int rows, int columns, float density);
  ~Doughnut();

  void DisplayGen(char** currGen);
  void Simulate(char** currGen);
  int findAlive(int currRow, int currColumn);
  char** init(int rows, int cols, float density);

private:
  char** currGen;
  char** nextGen;
  int m_genCount;
  int m_rows;
  int m_columns;
};
