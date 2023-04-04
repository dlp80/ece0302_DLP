#include <cstdlib>
#include <iostream>
#include "lib/image.h"
#include "list.hpp"
#include "queue.hpp"

struct Loc{
  int row;
  int col;
};


int main(int argc, char *argv[])
{
  // get input/output file names from command line arguments
  if (argc != 3) {
    std::cout << "Usage: pathfinder "
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  // Read input image from file
  Image<Pixel> image = readFromFile(input_file); //where readin happens

///////////////todo
typedef Queue<Loc, List<Loc>> QueueType; //first item = location second item = "list" telling it to use linkedl
  QueueType frontier;

  //point coords
//ints i and j
  int i=0;
  int j=0;

  for(int x = 0; x<image.width(); x++){ //exit failure if multiple reds** -- if any green return exit failure 
  ///may need to be changed -- not allowed to loop thru entire image
    for(int y=0; y<image.height();y++){

      //determine RED location
      if(image(x,y)==RED){
        Loc lstart = {x, y}; 
        frontier.enqueue(lstart);
        break;
      }
    }
  }

  Loc current = frontier.peekFront();

  frontier.enqueue({i-1, j});
  frontier.enqueue({i+1, j});
  frontier.enqueue({i, j-1});
  frontier.enqueue({i, j+1});

  Image<Pixel> result=image;
  int expl [image.width()][image.height()]; //readjust how expl is being used -- this is e\where the SF happens
  //Loc expl [image.width()][image.height()]; 
  //infinite loop to find all possible exits

  while(1){
    std::cout<<"while ";
    if(frontier.isEmpty()){
       std::cout<<current.row<<" "<<current.col;

       result(14,0)=GREEN;
       std::cout<< "no solution";
       writeToFile(result, output_file);
       exit(-1);
    }
    else{
      expl[current.row][current.col]=1; //*****
      Loc top={current.row-1, current.col};
      Loc bottom={current.row+1, current.col};
      Loc left = {current.row,current.col-1};
      Loc right = {current.row,current.col+1};

      if(current.row==0 || current.row==image.width()-1 || current.col==0 || current.col==image.height()-1){
        result(current.row, current.col)=GREEN;
        writeToFile(result, output_file);
        std::cout<< "solution found";
        EXIT_SUCCESS;
      }

      else{
        if(image(current.row+1, current.col)==WHITE && expl[current.row+1][current.col]==0){
          frontier.enqueue(bottom);
          expl[current.row+1][current.col]=1;
        }
        if(image(current.row-1, current.col)==WHITE && expl[current.row][current.col+1]==0){
          frontier.enqueue(top);
          expl[current.row][current.col-1]=1;
        }
        if(image(current.row, current.col-1)==WHITE && expl[current.row][current.col-1]==0){
          frontier.enqueue(left);
          expl[current.row][current.col-1]=1;
        }
        if(image(current.row, current.col+1)==WHITE && expl[current.row][current.col+1]==0){
          frontier.enqueue(right);
          expl[current.row][current.col+1]=1;
        }
      } //end of if else statements that checks the sides
    } //end of checking if frontier is empty

    if(current.row==0 || current.row==image.width()-1 || current.col==0 || current.col==image.height()-1){
      result(current.row, current.col)=GREEN;
      writeToFile(result, output_file);
      std::cout << "exit solution found";
      EXIT_SUCCESS;
    }
  }
  if(current.row==0 || current.row==image.width()-1 || current.col==0 || current.col==image.height()-1){
    result(current.row, current.col)=GREEN;
    writeToFile(result, output_file);
    std::cout<<"exit solution found";
    EXIT_SUCCESS;
  }


///////////////

//final statement
std::cout << "doneeee!!!!! >_<";
  // Write solution image to file
  writeToFile(image, output_file);
  
}
