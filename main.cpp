#include "classic.h"
#include "doughnut.h"
#include "mirror.h"
#include "manager.h"

using namespace std;

int main(int argc, char **argv){

  int userRows = 0;
  int userColumns = 0;
  float userDensity = 0.0;
  Manager* m = new Manager();

  char mapChoice = '\0';
  cout << "Would you like to provide a map file? (y/n)" << endl;
  cin >> mapChoice;
  mapChoice = tolower(mapChoice);
  if(mapChoice == 'y'){
    m->SetMap();
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
    Classic mine = Classic(userRows,userColumns,userDensity);
  }else if (b == 1 && mapChoice == 'y'){
    //Classic mine = Classic(); // We want classic game mode but with their map they passed
  }else if(b == 2){
    //Doughnut mine = Doughnut(userRows,userColumns,userDensity);
  }else if (b == 2 && mapChoice == 'y'){
    //Doughnut mine = Doughnut(); // We want doughnut game mode but with their map they passed
  }else if(b == 3){
    //Mirror mine = Mirror(userRows,userColumns,userDensity);
  }else if (b == 3 && mapChoice == 'y'){
    //Mirror mine = Mirror(); // We want classic game mode but with their map they passed
  }else{
    cout << "Invalid input.";
    return 1;
  }

  m->ChooseOutput();


  Classic mine = Classic(5,5,0.6);
  mine.DisplayGen();
  mine.Simulate();
  mine.DisplayGen();
  // mine.~Classic(); // This is the line causing the double free or corruption error


  return 0;
}
