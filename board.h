#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <ctime>
#include <vector>



template <class T>
class Board{
  private:
    std::vector<std::vector<T> > board;
  public:
    // Constructor
    Board(int size){ board.resize(size, std::vector<T>(size, 0)); }
    
    // Update board
    void update(std::vector<std::vector<T> > new_board){board = new_board;}
    // Print
    void wait(){
       std::clock_t startTime = std::clock();
       double secondsPassed;
       double secondsToDelay = 0.01;
       bool flag = true;      
       while(flag == true)
        {
         secondsPassed = (std::clock() - startTime) / (1.0*CLOCKS_PER_SEC);
         if(secondsPassed >= secondsToDelay)
          {
           flag = false;
          }
        }      
    }
    
    void clear(){
      //ANSI Escape Sequence
      printf("\033[2J");
      printf("\033[%d;%dH", 0, 0);       
    }
    
    void print(){
    wait();
    clear();
    for(auto iter1 = board.begin(); iter1 != board.end(); iter1++){
      for(auto iter2 = iter1->begin(); iter2 != iter1->end(); iter2++){
        if(*iter2 == 0){
          std::cout << " ";
        } else 
        std::cout << *iter2;
      }
      std::cout << "\n";
    }
    }
    
    
    T at(int row, int col){
      return board[row][col];
    }
};

#endif