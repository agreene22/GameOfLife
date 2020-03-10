#include "Manager.h"
#include "classic.h"
#include "doughnut.h"
#include "mirror.h"

using namespace std;

Manager::Manager(){
  m_mapChoice = 'n';
  m_gameMode = 1;
  m_outOption = 1;
}

Manager::Manager(char mapChoice, int gameMode, int outOption){
  m_mapChoice = mapChoice;
  m_gameMode = gameMode;
  m_outOption = outOption;
}

Manager::~Manager(){
  // idk if we need a destructor
}


char** Manager::SetMap(int& userRows, int& userColumns){
  int lineCount = 0;
  float userDensity = 0.0;
  ifstream inFS;
  string fileName = "";
  string mapRow = "";
  char** gen;

  cout << "Enter the map file name: " << endl;
  cin >> fileName;
  inFS.open(fileName, ifstream::in);

  if(!inFS.is_open()){
    cout << "Error: Could not open file." << endl;
    exit(0);
  }
  cout << "Processing file." << endl;

  while(!inFS.eof()){
    if(lineCount == 0){
      inFS >> userRows;
      if(!inFS.fail()){
        ++lineCount;
        continue;
      }
    }else if(lineCount == 1){
      inFS >> userColumns;
      if(!inFS.fail()){
        ++lineCount;
        continue;
      }
    }else if(lineCount == 2){
      gen = new char*[userRows];
      for(int i = 0; i < userRows; ++i) {
          gen[i] = new char[userColumns];
      }
      inFS >> mapRow;
      if(!inFS.fail()){
        for(int i = 0; i < mapRow.size(); ++i){
          gen[lineCount-2][i] = mapRow[i];
        }
      }
      ++lineCount;
    }else{
      inFS >> mapRow;
      if(!inFS.fail()){
        for(int i = 0; i < mapRow.size(); ++i){
          gen[lineCount-2][i] = mapRow[i];
        }

        ++lineCount;
      }
    }
  }
  inFS.close();
  return gen;
}

int Manager::ChooseBoundary(){
  int gameMode;
  cout << "Choose a boundary mode: (1) classic, (2) doughnut, (3) mirror" << endl;
  cin >> gameMode;
  if(gameMode != 1 && gameMode != 2 && gameMode != 3){
    cout << "Invalid input. Terminating program." << endl;
    exit(0);
  }else{
    m_gameMode = gameMode;
    cout << endl;
    return m_gameMode;
  }
}

int Manager::ChooseOutput(){
  int outOption = 0;
  cout << "Would you like " << endl << "(1) a brief pause between generations" << endl << "(2) press enter to display the next generation " << endl << "(3) output everything to a file" << endl;
  cout << "Enter 1, 2, or 3" << endl;
  cin >> outOption;
  if(outOption != 1 && outOption != 2 && outOption != 3){
    cout << "Invalid input. Terminating program." << endl;
    exit(0);
  }else{
    m_outOption = outOption;
    cout << endl;
    return outOption;
  }
}

int Manager::ChooseCycles(){
  int output = 0;
  cout << "How many iterations would you like?" << endl;
  cin >> output;
  return output;
}


// void Manager::Simulation(Classic *game){
  // while(game->isStable() && game ->isDead()){
  //   game->DisplayGen();
  //   game->Simulate();
  // }
// }

// void Manager::Simulation(Doughnut *game){
  // while(game->isStable() && game ->isDead()){
  //   game->DisplayGen();
  //   game->Simulate();
  // }
// }

// void Manager::Simulation(Mirror *game){
  // while(game->isStable() && game ->isDead()){
  //   game->DisplayGen();
  //   game->Simulate();
  // }
// }
