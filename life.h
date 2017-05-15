#ifndef LIFE_H
#define LIFE_H

#include <fstream>
#include <string>
#include "board.h"

class Life{
  private:
   Board<bool> gameboard_;
   std::vector<std::vector<bool> > newboard_;
   int height;
   int length;
  public:
   Life(std::string);
   std::vector<std::vector<bool> > nextGeneration();
   bool applyLife(int row, int col);
   void execute();
   
  
};
#endif