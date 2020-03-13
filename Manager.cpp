/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 2 - Game of Life
  Manager class which handles IO and simulations
 */
#include "Manager.h"


using namespace std;

Manager::Manager(){//default constructor
  m_mapChoice = 'n';
  m_gameMode = 1;
  m_outOption = 1;
}

Manager::Manager(char mapChoice, int gameMode, int outOption){//overloaded constructor
  m_mapChoice = mapChoice;
  m_gameMode = gameMode;
  m_outOption = outOption;
}


char** Manager::SetMap(int& userRows, int& userColumns){//this function reads in from the text file and assigns each element of the 2d array to the matvhing element in the text file
  //initializing
  int lineCount = 0;
  float userDensity = 0.0;
  ifstream inFS;
  string fileName = "";
  string mapRow = "";
  char** gen;

  cout << "Enter the map file name: " << endl;//prompting the user for the file name
  cin >> fileName;
  inFS.open(fileName, ifstream::in);//opening the file stream

  if(!inFS.is_open()){//if the file could not be opened there is an error and the program quits
    cout << "Error: Could not open file." << endl;
    exit(0);
  }
  cout << "Processing file." << endl;

  while(!inFS.eof()){
    if(lineCount == 0){//the first line of the text file will be read in and that is the number of rows in the grid
      inFS >> userRows;
      if(!inFS.fail()){
        ++lineCount;
        continue;
      }
    }else if(lineCount == 1){//the second line of the text file will be read in and that is the number of columns in the grid
      inFS >> userColumns;
      if(!inFS.fail()){
        ++lineCount;
        continue;
      }
    }else if(lineCount == 2){//initializing the 2d array with the number of rows and columns that were specified by the text file
      gen = new char*[userRows];
      for(int i = 0; i < userRows; ++i) {
          gen[i] = new char[userColumns];
      }
      inFS >> mapRow;//reading in from the text file's grid
      if(!inFS.fail()){
        for(int i = 0; i < mapRow.size(); ++i){//iterating through each line of the text file
          gen[lineCount-2][i] = mapRow[i];//passing in the text file and assigning elements to the array
        }
      }
      ++lineCount;
    }else{//any line other than the first three where we are reading in from the file normally
      inFS >> mapRow;//reading in from the text file
      if(!inFS.fail()){
        for(int i = 0; i < mapRow.size(); ++i){//iterating through each line of the text file
          gen[lineCount-2][i] = mapRow[i];//passing in the text file and assigning elements to the array
        }

        ++lineCount;
      }
    }
  }
  inFS.close();
  return gen;
}

int Manager::ChooseBoundary(){//this function prompts the user for what kind of game mode they would like to have
  int gameMode;
  cout << "Choose a boundary mode: (1) classic, (2) doughnut, (3) mirror" << endl;//prompting
  cin >> gameMode;//allowing for user input
  if(gameMode != 1 && gameMode != 2 && gameMode != 3){//invalid input
    cout << "Invalid input. Terminating program." << endl;
    exit(0);
  }else{//assiging the gamemode option
    m_gameMode = gameMode;
    cout << endl;
    return m_gameMode;
  }
}

int Manager::ChooseOutput(){//this function asks what kind of output the user would like
  int outOption = 0;
  cout << "Would you like " << endl << "(1) a brief pause between generations" << endl << "(2) press enter to display the next generation " << endl << "(3) output everything to a file" << endl;//prompting
  cout << "Enter 1, 2, or 3" << endl;
  cin >> outOption;//allowing for user input
  if(outOption != 1 && outOption != 2 && outOption != 3){//invalid input
    cout << "Invalid input. Terminating program." << endl;
    exit(0);
  }else{//assigning the output option
    m_outOption = outOption;
    cout << endl;
    return outOption;
  }
}

int Manager::ChooseCycles(){//choosing the number of iterations
  int output = 0;
  cout << "How many iterations would you like?" << endl;
  cin >> output;
  return output;
}


void Manager::Simulation1(Classic *game){//simulation with a brief pause for classic
  int loopCount = 0;
  char choice = '\0';
  cout << "Would you like a certain number of iterations? Enter (y/n)" << endl;//asking the user if they would like a certain number of iterations
  cin >> choice;
  choice = tolower(choice);
  if(choice == 'y'){
    int cycles = ChooseCycles();//asking for the number of cycles
    while(true){
      std::this_thread::sleep_for(std::chrono::milliseconds(1750));//sleep for 1.75 seconds
      game->DisplayGen();//displaying the current generation
      game->Simulate();//simulating to generate the next generation
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount >= cycles){//if we have iterated through the while loop more times than the user specified we break
        break;
      }
      loopCount++;//incrementing the loop count
    }
  }else if(choice == 'n'){
    while(true){
      std::this_thread::sleep_for(std::chrono::milliseconds(1750));//sleep for 1.75 seconds
      game->DisplayGen();
      game->Simulate();
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount > 2000){//we included this check to avoid an infinite loop
        break;
      }
    }
  }else{
    cout << "Invalid input." << endl;
    exit(0);
  }
}

void Manager::Simulation2(Classic *game){
  int loopCount = 0;
  char choice = '\0';
  cout << "Would you like a certain number of iterations? Enter (y/n)" << endl;
  cin >> choice;
  choice = tolower(choice);
  if(choice == 'y'){
    int cycles = ChooseCycles();
    while(true){
      string passGo = "";
      cout << "Hit any key to see the next generation" << endl;
      cin >> passGo;
      game->DisplayGen();
      game->Simulate();
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount >= cycles){//if we have iterated through the while loop more times than the user specified we break
        break;
      }
      loopCount++;
    }
  }else if(choice == 'n'){
    while(true){
      string passGo = "";
      cout << "Hit any key to see the next generation" << endl;
      cin >> passGo;
      game->DisplayGen();
      game->Simulate();
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount > 2000){//we included this check to avoid an infinite loop
        break;
      }
    }
  }else{
    cout << "Invalid input." << endl;
    exit(0);
  }
}

void Manager::Simulation3(Classic *game, string file){
  int loopCount = 0;
  char choice = '\0';
  cout << "Would you like a certain number of iterations? Enter (y/n)" << endl;
  cin >> choice;
  choice = tolower(choice);
  if(choice == 'y'){
    int cycles = ChooseCycles();
    while(true){
      game->PrintGen(file);
      game->Simulate();
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount >= cycles){//if we have iterated through the while loop more times than the user specified we break
        break;
      }
      loopCount++;
    }
  }else if(choice == 'n'){
    while(true){
      game->PrintGen(file);
      game->Simulate();
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount > 2000){//we included this check to avoid an infinite loop
        break;
      }
    }
  }else{
    cout << "Invalid input." << endl;
    exit(0);
  }
}

void Manager::Simulation1(Mirror *game){//simulation with a brief pause for mirro
  int loopCount = 0;
  char choice = '\0';
  cout << "Would you like a certain number of iterations? Enter (y/n)" << endl;
  cin >> choice;
  choice = tolower(choice);
  if(choice == 'y'){
    int cycles = ChooseCycles();
    while(true){
      std::this_thread::sleep_for(std::chrono::milliseconds(1750));//sleep for 1.75 seconds
      game->DisplayGen();
      game->Simulate();
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount >= cycles){//if we have iterated through the while loop more times than the user specified we break
        break;
      }
      loopCount++;
    }
  }else if(choice == 'n'){
    while(true){
      std::this_thread::sleep_for(std::chrono::milliseconds(1750));//sleep for 1.75 seconds
      game->DisplayGen();
      game->Simulate();
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount > 2000){//we included this check to avoid an infinite loop
        break;
      }
    }
  }else{
    cout << "Invalid input." << endl;
    exit(0);
  }
}

void Manager::Simulation2(Mirror *game){//press enter
  int loopCount = 0;
  char choice = '\0';
  cout << "Would you like a certain number of iterations? Enter (y/n)" << endl;
  cin >> choice;
  choice = tolower(choice);
  if(choice == 'y'){
    int cycles = ChooseCycles();
    while(true){
      string passGo = "";
      cout << "Hit any key to see the next generation" << endl;
      cin >> passGo;
      game->DisplayGen();
      game->Simulate();
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount >= cycles){//if we have iterated through the while loop more times than the user specified we break
        break;
      }
      loopCount++;
    }
  }else if(choice == 'n'){
    while(true){
      string passGo = "";
      cout << "Hit any key to see the next generation" << endl;
      cin >> passGo;
      game->DisplayGen();
      game->Simulate();
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount > 2000){//we included this check to avoid an infinite loop
        break;
      }
    }
  }else{
    cout << "Invalid input." << endl;
    exit(0);
  }
}

void Manager::Simulation3(Mirror *game, string file){
  int loopCount = 0;
  char choice = '\0';
  cout << "Would you like a certain number of iterations? Enter (y/n)" << endl;
  cin >> choice;
  choice = tolower(choice);
  if(choice == 'y'){
    int cycles = ChooseCycles();
    while(true){
      game->PrintGen(file);
      game->Simulate();
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount >= cycles){//if we have iterated through the while loop more times than the user specified we break
        break;
      }
      loopCount++;
    }
  }else if(choice == 'n'){
    while(true){
      game->PrintGen(file);
      game->Simulate();
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount > 2000){//we included this check to avoid an infinite loop
        break;
      }
    }
  }else{
    cout << "Invalid input." << endl;
    exit(0);
  }
}

void Manager::Simulation1(Doughnut *game){//simulation with a brief pause for doughnut
  int loopCount = 0;
  char choice = '\0';
  cout << "Would you like a certain number of iterations? Enter (y/n)" << endl;
  cin >> choice;
  choice = tolower(choice);
  if(choice == 'y'){
    int cycles = ChooseCycles();
    while(true){
      std::this_thread::sleep_for(std::chrono::milliseconds(1750));//sleep for 1.75 seconds
      game->DisplayGen();
      game->Simulate();
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount >= cycles){//if we have iterated through the while loop more times than the user specified we break
        break;
      }
      loopCount++;
    }
  }else if(choice == 'n'){
    while(true){
      std::this_thread::sleep_for(std::chrono::milliseconds(1750));//sleep for 1.75 seconds
      game->DisplayGen();
      game->Simulate();
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount > 2000){//we included this check to avoid an infinite loop
        break;
      }
    }
  }else{
    cout << "Invalid input." << endl;
    exit(0);
  }
}

void Manager::Simulation2(Doughnut *game){//press enter
  int loopCount = 0;
  char choice = '\0';
  cout << "Would you like a certain number of iterations? Enter (y/n)" << endl;
  cin >> choice;
  choice = tolower(choice);
  if(choice == 'y'){
    int cycles = ChooseCycles();
    while(true){
      string passGo = "";
      cout << "Hit any key to see the next generation" << endl;
      cin >> passGo;
      game->DisplayGen();
      game->Simulate();
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount >= cycles){//if we have iterated through the while loop more times than the user specified we break
        break;
      }
      loopCount++;
    }
  }else if(choice == 'n'){
    while(true){
      string passGo = "";
      cout << "Hit any key to see the next generation" << endl;
      cin >> passGo;
      game->DisplayGen();
      game->Simulate();
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount > 2000){//we included this check to avoid an infinite loop
        break;
      }
    }
  }else{
    cout << "Invalid input." << endl;
    exit(0);
  }
}

void Manager::Simulation3(Doughnut *game, string file){//print to file
  int loopCount = 0;
  char choice = '\0';
  cout << "Would you like a certain number of iterations? Enter (y/n)" << endl;
  cin >> choice;
  choice = tolower(choice);
  if(choice == 'y'){
    int cycles = ChooseCycles();
    while(true){
      game->PrintGen(file);
      game->Simulate();
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount >= cycles){//if we have iterated through the while loop more times than the user specified we break
        break;
      }
      loopCount++;
    }
  }else if(choice == 'n'){
    while(true){
      game->PrintGen(file);
      game->Simulate();
      if(game->isStable()){//if the grid is stable we break from the while loop
        cout << "Stable" << endl;
        break;
      }if(game->isEmpty()){//if the grid is empty we break from the while loop
        cout << "Empty" << endl;
        break;
      }if(loopCount > 2000){//we included this check to avoid an infinite loop
        break;
      }
    }
  }else{
    cout << "Invalid input." << endl;
    exit(0);
  }
}
