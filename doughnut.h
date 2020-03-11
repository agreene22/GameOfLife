#include <iostream>
#include <random>
#include <fstream>

class Doughnut{
  public:
    Doughnut();
    Doughnut(int rows, int columns, float density);
    Doughnut(char** grid, int rows, int columns);
    ~Doughnut();

    void DisplayGen(); //no need for parameters on these functions
    void PrintGen(ofstream out);
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
