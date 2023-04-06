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

  //initialize

  int redcount = 0;
  Loc lstart;

  for(int x = 0; x<image.width(); x++){ //exit failure if multiple reds** -- if any green return exit failure 
    for(int y=0; y<image.height();y++){

      //determine RED location
      if(image(x,y)==RED){
        lstart = {x, y}; 
        frontier.enqueue(lstart);
        redcount++;
      }
      if (redcount > 1){ //if there are more than 1 red pixels return false!!!!!!!
        EXIT_FAILURE;
      }
    }
  }

   //current defines the start location
  Loc current = frontier.peekFront();

  bool expl [image.width()][image.height()]; //setting this to 0 - explored
  bool journey [image.width()][image.height()]; //s

  //initializing arrays to be full of 0
  for(int i = 0; i<image.width(); i++){
      for(int j = 0; j<image.height(); i++){
        expl[i][j] = 0;
        journey[i][j] = 0;
    }
  }

  //if the frontier is empty, return error
    if(frontier.isEmpty()){
      image(current.row, current.col)=GREEN;
       writeToFile(image, output_file);
       exit(-1);
    }

    //if our red is at an exit, color it green and return success
    if(current.row==0 || current.row==image.width()-1 || current.col==0 || current.col==image.height()-1){
      image(current.row, current.col)=GREEN;
      writeToFile(image, output_file);
      EXIT_SUCCESS;
    }


    //for the big purple chunk of if statements, add checks to ensure it isnt trying to move to an edgecase

    //infinite checking loop!!
    while(1){  
    if(frontier.isEmpty()){
      image(current.row, current.col)=GREEN;
       writeToFile(image, output_file);
       exit(-1);
    }
    else{
      expl[current.row][current.col]=1;
      Loc top={current.row-1, current.col};
      Loc bottom={current.row+1, current.col};
      Loc left = {current.row,current.col-1};
      Loc right = {current.row,current.col+1};

    if(current.row==0 || current.row==image.width()-1 || current.col==0 || current.col==image.height()-1){
        image(current.row, current.col)=GREEN;
        writeToFile(image, output_file);
        EXIT_SUCCESS;
      }
    else{
        if(image(current.row+1, current.col)==WHITE && expl[current.row+1][current.col]!=1){
          frontier.enqueue(bottom);
          expl[current.row+1][current.col]=1;
        }
        if(image(current.row-1, current.col)==WHITE && expl[current.row-1][current.col]!=1){
          frontier.enqueue(top);
          expl[current.row-1][current.col]=1;
        }
        if(image(current.row, current.col-1)==WHITE && expl[current.row][current.col-1]!=1){
          frontier.enqueue(left);
          expl[current.row][current.col-1]=1;
        }
        if(image(current.row, current.col+1)==WHITE && expl[current.row+1][current.col+1]!=1){
          frontier.enqueue(right);
          expl[current.row][current.col+1]=1;
        }//end of path exploring
        
        frontier.dequeue(); //popping purposes
      } //end of if else statements that checks the sides
    } //end of checking if frontier is empty

    //checking if we are at an endpoint yet
    if(current.row==0 || current.row==image.width()-1 || current.col==0 || current.col==image.height()-1){
        image(current.row, current.col)=GREEN;
        writeToFile(image, output_file);
        EXIT_SUCCESS;
      }

  }

  if(current.row==0 || current.row==image.width()-1 || current.col==0 || current.col==image.height()-1){
    image(current.row, current.col)=GREEN;
    writeToFile(image, output_file);
    EXIT_SUCCESS;
  }

  std::cout << "doneeee!!!!! >_<";
  // Write solution image to file
  writeToFile(image, output_file);
}
//#################################################################//
