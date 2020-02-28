#include <iostream>

class Classic{
public:
  Classic();

  void DisplayGen(char currGen[][]);
  void Simulate(char currGen[][]);
  int findAlive(int currRow, int currColumn);

private:
  char m_currGen;
  char *m_nextGen;
  int m_genCount;
  int mrows;
  int m_columns;
};
