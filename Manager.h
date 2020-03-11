#include <iostream>
#include <fstream>
#include <string>
// #include "classic.h"
// #include "doughnut.h"
// #include "mirror.h"

class Manager{
public:
  Manager();
  Manager(char mapChoice, int gameMode, int outOption);
  ~Manager();

  char** SetMap(int& userRows, int& userColumns);
  int ChooseBoundary();
  int ChooseOutput();
  int ChooseCycles();

  // void Simulation(Classic* game); //Can overload the constructor so that way it runs game of correct type
  // void Simulation(Doughnut *game);
  // void Simulation(Mirror *game);
private:
  char m_mapChoice;
  int m_gameMode;
  int m_outOption;
};
