#include <iostream>

class Classic{
public:
  Classic();
  Classic(int rows, int columns);
  ~Classic();

  void PopulateFirstGen();

  void DisplayGen(char *currGen);
  void Simulate(char *currGen);
  int findAlive(int currRow, int currColumn);

private:
  char *currGen;
  char *nextGen;
  int m_genCount;
  int m_rows;
  int m_columns;
};
