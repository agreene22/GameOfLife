#include "Manager.h"

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
  //
}


char** Manager::SetMap(int& userRows, int& userColumns){
  int lineCount = 0;
  float userDensity = 0.0;
  ifstream inFS;
  string fileName = "";
  string mapRow = "";

  cout << "Enter the map file name: " << endl;
  cin >> fileName;
  inFS.open(fileName);

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
    }else{
      inFS >> mapRow;
      if(!inFS.fail()){
        ++lineCount;
        char** gen = new char*[userRows];
        for(int i = 0; i < userRows; ++i) {
            gen[i] = new char[userColumns];
        }

        for(int i = 0; i < userRows; ++i){
          for(int j = 0; j < userColumns; ++j){
            for(int k = 0; k < mapRow.size(); ++k){
              gen[i][j] = mapRow[k];
            }
          }
        }
        return gen;
      }
    }
  }
}

int Manager::ChooseBoundary(){
  int gameMode;
  cout << "Choose a boundary mode: (1) classic, (2) doughnut, (3) mirror" << endl;
  cin >> gameMode;
  m_gameMode = gameMode;
  cout << endl;
  return m_gameMode;
}

int Manager::ChooseOutput(){
  int outOption = 0;
  cout << "Would you like " << endl << "(1) a brief pause between generations" << endl << "(2) press enter to display the next generation " << endl << "(3) output everything to a file" << endl;
  cout << "Enter 1, 2, or 3" << endl;
  cin >> outOption;
  m_outOption = outOption;
  cout << endl;
  return outOption;
}
