#include "Manager.h"

Manager::Manager(){
  m_mapChoice = 'n';
  m_gameMode = 1;
  m_outOption = 1;
}

Manager::~Manager(char mapChoice, int gameMode, int outOption){
  m_mapChoice = mapChoice;
  m_gameMode = gameMode;
  m_outOption = outOption;
}

char** Manager::ChooseMap(){ // I'm not sure if I can return like this
  int userRows = 0;
  int userColumns = 0;
  float userDensity = 0.0;
  ifstream inFS;
  string fileName = "";
  string mapRow = "";

  cout << "Would you like to provide a map file? (y/n)" << endl;
  cin >> mapChoice;
  mapChoice = tolower(mapChoice);

  if(mapChoice == 'n'){
    cout << "Enter the dimmensions of the world (separated by returns): " << endl;
    cin >> userRows;
    cin >> userColumns;
    cout << "Enter a decimal value for population density: " << endl;
    cin >> userDensity;

    return SOMETHING; // I think it needs to return the three values here but that's different from if they provide a map
  } else{
    cout << "Enter the map file name: " << endl;
    cin >> fileName;
    inFS.open(fileName);

    if(!inFS.is_open()){
      cout << "Error: Could not open file." << endl;
      return 1;
    }
    cout << "Processing file." << endl;
  }

  while(!inFS.eof()){
    inFS >> userRows;
    inFS >> userColumns;

    inFS >> mapRow;
    for(int i = 0; i < mapRow.size(); ++i){
      mapRow[i]; // NEED TO put the letter into the array to fill the grid
    }
  }
}

int Manager::ChooseBoundary(){
  cout << "Choose a boundary mode: (1) classic, (2) doughnut, (3) mirror" << endl;
  cin >> gameMode;
  m_gameMode = gameMode;
  cout << endl;
  return m_gameMode;
}

int Manager::ChooseOutput(){
  cout << "Would you like " << endl << "(1) a brief pause between generations" << endl << "(2) press enter to display the next generation " << endl << "(3) output everything to a file" << endl;
  cout << "Enter 1, 2, or 3" << endl;
  cin >> outOption;
  m_outOption = outOption;
  cout << endl;
  return outOption;
}
