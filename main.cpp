#include <iostream>
#include <fstream>
#include "classic.h"
#include "doughnut.h"
#include "mirror.h"
#include "manager.h"

using namespace std;

int main(int argc, char **argv){
  Manager* m = new Manager();
  m->ChooseMap();

  int b = m->ChooseBoundary();
  if(b == 1){
    Classic mine = Classic();
  }else if(b == 2){
    Doughnut mine = Doughnut();
  }else if(b == 3){
    //Mirror mine = Mirror();
  }else{
    cout << "Invalid input.";
    return 1;
  }

  m->ChooseOutput();


  Classic mine = Classic(5,5,0.6);
  mine.DisplayGen();
  mine.Simulate();
  cout << "New Gen" << endl;
  mine.DisplayGen();
  mine.~Classic();

  return 0;
}
