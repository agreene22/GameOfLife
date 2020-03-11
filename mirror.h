#include <iostream>
#include <random>
#include <fstream>
#include <string>

using namespace std;

class Mirror{
  public:
    Mirror();
    Mirror(int rows, int columns, float density);
    Mirror(char** grid, int rows, int columns);
    ~Mirror();

    void DisplayGen();
    void PrintGen(string file);
    void Simulate();
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
