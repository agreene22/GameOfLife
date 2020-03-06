#include <iostream>
#include <fstream>
#include <string>

class Manager{
public:
  Manager();
  Manager(char mapChoice, int gameMode, int outOption);
  ~Manager();

  char** SetMap();
  int ChooseBoundary();
  int ChooseOutput();
private:
  char m_mapChoice; // Should these be member variables
  int m_gameMode;
  int m_outOption;
};
