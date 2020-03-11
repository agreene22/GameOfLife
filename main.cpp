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
  Doughnut* doughnut1;
  Doughnut* doughnut2;
  Mirror* mirror1;
  Mirror* mirror2;


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
  int out = m->ChooseOutput();
  if(b == 1 && mapChoice != 'y'){
    Classic* classic1 = new Classic(userRows,userColumns,userDensity);
    if(out == 1){//brief pause

    }else if(out == 2){//press enter

    }else if(out == 3){//print to file
      string outFile = "";
      cout << "What would you like the name of your output file to be?" << endl;
      cin >> outFile;
      m->Simulation3(classic1, outFile);
    }
  }else if (b == 1 && mapChoice == 'y'){
    Classic* classic2 = new Classic(map, userRows, userColumns);
    if(out == 1){//brief pause

    }else if(out == 2){//press enter

    }else if(out == 3){//printing to a file
      string outFile = "";
      cout << "What would you like the name of your output file to be?" << endl;
      cin >> outFile;
      m->Simulation3(classic2, outFile);
    }
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






  return 0;
}
