#include <iostream>
#include <fstream>
#include <string>
#include "classic.h"
#include "doughnut.h"
#include "mirror.h"

using namespace std;

class Manager{
public:
  Manager();
  Manager(char mapChoice, int gameMode, int outOption);
  ~Manager();

  char** SetMap(int& userRows, int& userColumns);
  int ChooseBoundary();
  int ChooseOutput();
  int ChooseCycles();
  void Simulation1(Classic *game);
  void Simulation1(Doughnut *game);
  void Simulation1(Mirror *game);
  void Simulation2(Classic *game);
  void Simulation2(Doughnut *game);
  void Simulation2(Mirror *game);
  void Simulation3(Classic *game, string file);
  void Simulation3(Doughnut *game, string file);
  void Simulation3(Mirror *game, string file);

  // void Simulation(Classic* game); //Can overload the constructor so that way it runs game of correct type
  // void Simulation(Doughnut *game);
  // void Simulation(Mirror *game);
private:
  char m_mapChoice;
  int m_gameMode;
  int m_outOption;
};
