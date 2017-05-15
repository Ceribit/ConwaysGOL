#include <iostream>
#include "life.h"

using namespace std;

Life::Life(string filename):gameboard_(0){
  ifstream inFile(filename.c_str());
  string line;
  vector<vector<bool> > board_fill;
  
  while(inFile >> line){
    vector<bool> line_fill;
    for(auto iter = line.begin(); iter != line.end(); iter++){
      if(*iter == '0'){
        line_fill.push_back(false);
      } else{
        line_fill.push_back(true);
      }
    }
    board_fill.push_back(line_fill);
  }
  height = board_fill.size();
  length = board_fill[0].size();
  gameboard_.update(board_fill);
  execute();
}

void Life::execute(){
  newboard_.resize(height, vector<bool>(length, 0));
    while(true){
    gameboard_.print();      
    gameboard_.update(nextGeneration());
    }
}

vector<vector<bool> > Life::nextGeneration(){
  for(int i = 0; i < height; i++){
    for(int j = 0; j < length; j++){
      newboard_[i][j] = applyLife(i,j);
    }
  }
  return newboard_;
}

bool Life::applyLife(int row, int col){
  //Count neightbor cells
  int num_neighbors = 0;
  for(int i = row-1; i < row+2; i++){
    for(int j = col-1; j < col+2; j++){
      if(!(i < 0 || j < 0 || i >= height || j >= length)){
        if(!(i == row && j == col) && gameboard_.at(i,j)){
          num_neighbors++;
        }
      }
    }
  }
  //Apply rules
  if(gameboard_.at(row,col) == true){
    if(num_neighbors < 2){
      return false;
    } else if(num_neighbors < 4){
      return true;
    } else{
      return false;
    }
  } else{
    if(num_neighbors == 3){
      return true;
    } else{
      return false;
    }
  }
  return true;
}