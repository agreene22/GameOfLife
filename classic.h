#include <iostream>
#include <random>

class Classic{
public:
  Classic();
  Classic(int rows, int columns, float density);
  Classic(char** grid);
  ~Classic();

  // void PopulateFirstGen(int popDensity); // Should we create two methods? One for if they provide a file and one for if they don't // the overloaded constructor will be used if they dont provide a file
  // void PopulateFirstGen(ifstream inFS); // idk if this is the right way to do it but we could read in their file here and populate the array

  void DisplayGen();
  void Simulate();
  int findAlive(int currRow, int currColumn);
  char** init(int rows, int cols, float density);


private:
  char** currGen;
  char** nextGen;
  int m_genCount;
  int m_rows;
  int m_columns;
};
