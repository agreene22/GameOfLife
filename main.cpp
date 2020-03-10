#include "classic.h"
#include "doughnut.h"
#include "mirror.h"
#include "manager.h"

using namespace std;

int main(int argc, char **argv){

  int userRows = 0;
  int userColumns = 0;
  float userDensity = 0.0;
  char** map;
  Manager* m = new Manager();
  Classic* classic1;
  Classic* classic2;

  char mapChoice = '\0';
  cout << "Would you like to provide a map file? (y/n)" << endl;
  cin >> mapChoice;
  mapChoice = tolower(mapChoice);
  if(mapChoice == 'y'){
    map = m->SetMap(userRows, userColumns);
  }else{
    cout << "Enter the number of rows you would like in the grid: " << endl;
    cin >> userRows;
    cout << "Enter the number of columns you would like in the grid: " << endl;
    cin >> userColumns;
    cout << "Enter a decimal value for population density: " << endl;
    cin >> userDensity;
  }

  int b = m->ChooseBoundary();
  if(b == 1 && mapChoice != 'y'){
    Classic* classic1 = new Classic(userRows,userColumns,userDensity);
    // m->Simulation(classic1); // I know this method isn't functional yet
  }else if (b == 1 && mapChoice == 'y'){
    // Classic* classic2 = new Classic(map, userRows, userColumns);
    // m->Simulation(classic2);
  }else if(b == 2 && mapChoice != 'y'){
    // Doughnut* doughnut1 = new Doughnut(userRows,userColumns,userDensity);
    // m->Simulation(doughnut1);
  }else if (b == 2 && mapChoice == 'y'){
    // Doughnut* doughnut2 = new Doughnut(map, userRows, userColumns);
    // m->Simulation(doughnut2);
  }else if(b == 3 && mapChoice != 'y'){
    // mirror* mirror1 = new Mirror(userRows,userColumns,userDensity);
    // m->Simulation(mirror1);
  }else if (b == 3 && mapChoice == 'y'){
    // Mirror* mirror2 = new Mirror(map, userRows, userColumns);
    // m->Simulation(mirror2);
  }else{
    cout << "Invalid input.";
    return 1;
  }

  int out = m->ChooseOutput();

  Mirror* mine = new Mirror(map, userRows, userColumns); // Error when declaring within if statement because then out of scope for method calls later

  if (out == 1){
    // sleep(3000); // do this to create 3 second pause
  } else if (out == 2){
    // PRESS ENTER
  } else{
    ofstream outFS;
    outFS.open("generationOutput.txt");
    // outFS << mine.DisplayGen(); // can't write to file like this because it doesn't return anything
    outFS.close();
  }

  mine->DisplayGen(); // getting segmentation fault but not sure why
  mine->Simulate();
  mine->DisplayGen();
  mine->Simulate();
  mine->DisplayGen();

  return 0;
}
