#include <iostream>
#include <random>
#include <fstream>
#include <string>

using namespace std;

class Doughnut{
  public:
    Doughnut();
    Doughnut(int rows, int columns, float density);
    Doughnut(char** grid, int rows, int columns);
    ~Doughnut();

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
