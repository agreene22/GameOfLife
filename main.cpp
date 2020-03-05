#include <iostream>
#include <fstream>
#include "classic.h"
#include "doughnut.h"
#include "mirror.h"

using namespace std;

int main(int argc, char **argv){
//   // Classic c = new Classic(3,3);
//   char map;
//   int userRows = 0;
//   int userColumns = 0;
//   float userDensity = 0.0;
//   ifstream inFS;
//   string fileName = "";
//   string mapRow = "";
//   string gameMode = "";
//   int outOption = 0;
//
//   cout << "Would you like to provide a map file? (y/n)" << endl;
//   cin >> map;
//   map = tolower(map);
//
//   if(map == 'n'){
//     cout << "Enter the dimmensions of the world (separated by returns): " << endl;
//     cin >> userRows;
//     cin >> userColumns;
//     cout << "Enter a decimal value for population density: " << endl;
//     cin >> userDensity;
//   } else{
//     cout << "Enter the map file name: " << endl;
//     cin >> fileName;
//     inFS.open(fileName);
//
//     if(!inFS.is_open()){
//       cout << "Error: Could not open file." << endl;
//       return 1;
//     }
//     cout << "Processing file." << endl;
//   }
//
//   while(!inFS.eof()){
//     inFS >> userRows;
//     inFS >> userColumns;
//
//     inFS >> mapRow;
//     for(int i = 0; i < mapRow.size(); ++i){
//       mapRow[i]; // NEED TO put the letter into the array to fill the grid
//     }
//   }
//
//   cout << "Choose a boundary mode: classic, doughnut, mirror" << endl;
//   cin >> gameMode; // Should we tolower this
//   cout << endl;
//   cout << "Would you like " << endl << "(1) a brief pause between generations" << endl << "(2) press enter to display the next generation " << endl << "(3) output everything to a file" << endl;
//   cout << "Enter 1, 2, or 3" << endl;
//   cin >> outOption;
  // IMPLEMENT BASED ON CHOICE HERE
  Classic mine = Classic(5,5,0.8);
  mine.DisplayGen();

  return 0;
}
