/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 2 - Game of Life
 */
#include "classic.h"
#include "doughnut.h"
#include "mirror.h"
#include <chrono>
#include <thread>

using namespace std;

class Manager{
public:
  Manager();//default constructor
  Manager(char mapChoice, int gameMode, int outOption);//overloaded constructor

  char** SetMap(int& userRows, int& userColumns);//creating a map by reading it in from a text file
  int ChooseBoundary();//prompting the user for what game mode they would like
  int ChooseOutput();//prompting the user for what kind of output they would like
  int ChooseCycles();//prompting the user for how many iterations they would like
  void Simulation1(Classic *game);//simulation with a brief pause for classic
  void Simulation1(Doughnut *game);//simulation with a brief pause for doughnut
  void Simulation1(Mirror *game);//simulation with a brief pause for mirror
  void Simulation2(Classic *game);//simulation where the user presses a key in between generations for classic
  void Simulation2(Doughnut *game);//simulation where the user presses a key in between generations for doughnut
  void Simulation2(Mirror *game);//simulation where the user presses a key in between generations for mirror
  void Simulation3(Classic *game, string file);//simulation where the output is written to a text file for classic
  void Simulation3(Doughnut *game, string file);//simulation where the output is written to a text file for doughnut
  void Simulation3(Mirror *game, string file);//simulation where the output is written to a text file for mirror

private:
  char m_mapChoice;//choice of map for the user
  int m_gameMode;//game mode choice
  int m_outOption;//output option choice
};
