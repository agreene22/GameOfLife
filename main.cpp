/* Anna Greene - 2314663
  Brandon Kleinman - 2291703
  Assignment 2 - Game of Life
 */
#include "manager.h"

using namespace std;

int main(int argc, char **argv){
  //initializing
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
  cout << "Would you like to provide a map file? (y/n)" << endl; //asking is they want to use an existing grid
  cin >> mapChoice;
  mapChoice = tolower(mapChoice);
  if(mapChoice == 'y'){
    map = m->SetMap(userRows, userColumns);
  }else{//prompting for the dimensions and population density of the grid
    cout << "Enter the number of rows you would like in the grid: " << endl;
    cin >> userRows;
    cout << "Enter the number of columns you would like in the grid: " << endl;
    cin >> userColumns;
    cout << "Enter a decimal value for population density: " << endl;
    cin >> userDensity;
  }

  int b = m->ChooseBoundary();//invoking the chooseboundary function from the manager class
  int out = m->ChooseOutput();//invoking the chooseOutput function from the manager class
  if(b == 1 && mapChoice != 'y'){//if the user wants classic and doesnt want to use a map
    Classic* classic1 = new Classic(userRows,userColumns,userDensity);//initializing classic
    if(out == 1){//brief pause
      m->Simulation1(classic1);//simulating with a brief pause
    }else if(out == 2){//press enter
      m->Simulation2(classic1);//simulating where the user has to press a key+enter
    }else if(out == 3){//print to file
      string outFile = "";
      cout << "What would you like the name of your output file to be?" << endl;
      cin >> outFile;
      m->Simulation3(classic1, outFile);//simulating and printing to a file
    }
  }else if (b == 1 && mapChoice == 'y'){//if the user wants classic and passes in a map file
    Classic* classic2 = new Classic(map, userRows, userColumns);
    if(out == 1){//brief pause
      m->Simulation1(classic2);//simulating with a brief pause
    }else if(out == 2){//press enter
      m->Simulation2(classic2);//simulating where the user has to press a key+enter
    }else if(out == 3){//printing to a file
      string outFile = "";
      cout << "What would you like the name of your output file to be?" << endl;
      cin >> outFile;
      m->Simulation3(classic2, outFile);//simulating and printing to a file
    }
  }else if(b == 2 && mapChoice != 'y'){//if the user wants doughnut but does not want to pass a file
    Doughnut* doughnut1 = new Doughnut(userRows,userColumns,userDensity);
    if(out == 1){//brief pause
      m->Simulation1(doughnut1);//simulating with a brief pause
    }else if(out == 2){//press enter
      m->Simulation2(doughnut1);//simulating where the user has to press a key+enter
    }else if(out == 3){//print to file
      string outFile = "";
      cout << "What would you like the name of your output file to be?" << endl;
      cin >> outFile;
      m->Simulation3(doughnut1, outFile);//simulating and printing to a file
    }
  }else if (b == 2 && mapChoice == 'y'){//if the user wants doughnut and does want to pass a file
    Doughnut* doughnut2 = new Doughnut(map,userRows,userColumns);
    if(out == 1){//brief pause
      m->Simulation1(doughnut2);//simulating with a brief pause
    }else if(out == 2){//press enter
      m->Simulation2(doughnut2);//simulating where the user has to press a key+enter
    }else if(out == 3){//print to file
      string outFile = "";
      cout << "What would you like the name of your output file to be?" << endl;
      cin >> outFile;
      m->Simulation3(doughnut2, outFile);//simulating and printing to a file
    }
  }else if(b == 3 && mapChoice != 'y'){//if the user wants mirror but does not want to pass a file
    Mirror* mirror1 = new Mirror(userRows,userColumns,userDensity);
    if(out == 1){//brief pause
      m->Simulation1(mirror1);//simulating with a brief pause
    }else if(out == 2){//press enter
      m->Simulation2(mirror1);//simulating where the user has to press a key+enter
    }else if(out == 3){//print to file
      string outFile = "";
      cout << "What would you like the name of your output file to be?" << endl;
      cin >> outFile;
      m->Simulation3(mirror1, outFile);//simulating and printing to a file
    }
  }else if (b == 3 && mapChoice == 'y'){//if the user wants mirror and does want to pass a file
    Mirror* mirror2 = new Mirror(map,userRows,userColumns);
    if(out == 1){//brief pause
      m->Simulation1(mirror2);//simulating with a brief pause
    }else if(out == 2){//press enter
      m->Simulation2(mirror2);//simulating where the user has to press a key+enter
    }else if(out == 3){//print to file
      string outFile = "";
      cout << "What would you like the name of your output file to be?" << endl;
      cin >> outFile;
      m->Simulation3(mirror2, outFile);//simulating and printing to a file
    }
  }else{
    cout << "Invalid input.";
    return 1;
  }
  delete m;

  return 0;
}
