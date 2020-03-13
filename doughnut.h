/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 2 - Game of Life
 */
#include <iostream>
#include <random>
#include <fstream>
#include <string>

using namespace std;

class Doughnut{
  public:
    Doughnut(); // default constructor
    Doughnut(int rows, int columns, float density; //overloaded constructor for random generation
    Doughnut(char** grid, int rows, int columns); //overloaded constructor if map file is provided
    ~Doughnut(); // destructor

    void DisplayGen(); // prints generation to the console
    void PrintGen(string file); // writes output to file
    void Simulate(); // generates next gen
    int findAlive(int currRow, int currColumn); // counts neighbors for specific cell
    char** init(int rows, int cols, float density); // initialize 2d array grid
    bool isStable(); // checks if the generations stabilize
    bool isEmpty(); // checks if all the cells die

  private:
    char** currGen; // pointer to 2d array of current generation
    char** nextGen; // pointer to 2d array of next generation
    int m_genCount; // integer for generation count
    int m_rows; // integer for number of rows in grid
    int m_columns; // integer for number of columns in grid
    bool m_stable = false; // boolean representing if the generations have stabilized
};
