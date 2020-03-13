/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 2 - Game of Life
 */

#include <iostream>
#include <random>
#include <fstream>
#include <string>

using namespace std;

class Classic{
  public:
    Classic();
    Classic(int rows, int columns, float density);
    Classic(char** grid, int rows, int columns);
    ~Classic();

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
