#include <iostream>

class Classic{
public:
  Classic();
  Classic(int rows, int columns);
  ~Classic();

  // void PopulateFirstGen(int popDensity); // Should we create two methods? One for if they provide a file and one for if they don't
  // void PopulateFirstGen(ifstream inFS); // idk if this is the right way to do it but we could read in their file here and populate the array

  void DisplayGen(char** currGen);
  void Simulate(char** currGen);
  int findAlive(int currRow, int currColumn);
  char** init(int rows, int cols);

private:
  char** currGen;
  char** nextGen;
  int m_genCount;
  int m_rows;
  int m_columns;
};
