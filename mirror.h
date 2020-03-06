#include <iostream>
#include <random>

class Mirror{
  public:
    Mirror();
    Mirror(int rows, int columns, float density);
    Mirror(char** grid);
    ~Mirror();

    void DisplayGen(); //no need for parameters on these functions
    void Simulate(); //no need for parameters on these functions
    int findAlive(int currRow, int currColumn);
    char** init(int rows, int cols, float density);

  private:
    char** currGen;
    char** nextGen;
    int m_genCount;
    int m_rows;
    int m_columns;
};
