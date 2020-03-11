#include <iostream>
#include <random>
#include <fstream>

class Mirror{
  public:
    Mirror();
    Mirror(int rows, int columns, float density);
    Mirror(char** grid, int rows, int columns);
    ~Mirror();

    void DisplayGen(); //no need for parameters on these functions
    void PrintGen(std::ofstream out);
    void Simulate(); //no need for parameters on these functions
    int findAlive(int currRow, int currColumn);
    char** init(int rows, int cols, float density);
    bool isStable();
    bool isEmpty();

  private:
    char** currGen;
    char** nextGen;
    int m_genCount;
    int m_rows;
    int m_columns;
    bool m_stable = false;
};
