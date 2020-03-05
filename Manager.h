#include <iostream>

class Manager{
public:
  Manager();
  Manager(char mapChoice, int gameMode, int outOption);
  // ~Manager();

  char** ChooseMap();
  int ChooseBoundary();
  int ChooseOutput();
private:
  char m_mapChoice; // Should these be member variables
  int m_gameMode;
  int m_outOption;
};
