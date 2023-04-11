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
  //initialize
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
        redcount++;
      }
      
      if (redcount > 1){ //if there are more than 1 red pixels return false!!!!!!!
        return EXIT_FAILURE;
      }
    }
  }

frontier.enqueue(lstart); //before entering the inf while loop, we have a start position in the Q

//we can only proceed if the frontier IS NOT empty
  //check if frontier has a start point - if not return failure
    if(frontier.isEmpty()){
      //image(current.row, current.col)=GREEN;
       //writeToFile(image, output_file);
       return EXIT_FAILURE; ////
    }

  //else, we can begin testing. here, current defines the start location
  Loc current = frontier.peekFront();
  bool expl [image.width()][image.height()]; // 0 = unexplored, 1 = explored
  bool journey [image.width()][image.height()]; //sa,e as expl

  //initializing arrays to be full of 0
  for(int i = 0; i<image.height(); i++){
      for(int j = 0; j<image.width(); j++){
        expl[i][j] = 0;
        journey[i][j] = 0;
    }
  }

  //first init of r and c
    int r = current.row;
    int c = current.col;

    //if our red is at an exit, color it green and return success
  if(current.row==0 || current.row==image.width()-1 || current.col==0 || current.col==image.height()-1){
    //image(current.row, current.col)=GREEN;
    writeToFile(image, output_file);
    return EXIT_SUCCESS;
 }


  //for the big purple chunk of if statements, add checks to ensure it isnt trying to move to an edgecase

    //infinite checking loop!!
  while(1){

    if(frontier.isEmpty()){
      //image(current.row, current.col)=GREEN;
       writeToFile(image, output_file);
       return EXIT_SUCCESS;
    }
    
      current = frontier.peekFront();
      frontier.dequeue();
      journey[r][c]=0;
      r = current.row;
      c = current.col;

      expl[current.row][current.col]=1; //set to one so that you don't stay there?

    if(current.row==0 || current.row==image.width()-1 || current.col==0 || current.col==image.height()-1){
        image(current.row, current.col)=GREEN;
        writeToFile(image, output_file);
        return EXIT_SUCCESS;
      }

        //expl[current.row][current.col]=1;
        if(image(r-1, c)==WHITE && expl[r-1][c]==0 && journey[r-1][c]==0 && r-1 > -1){ // example line
          frontier.enqueue({r-1, c}); // replace w exact ({r-1, c})
          journey[r-1][c]=1;
          //expl[current.row-1][current.col]=1;
        }
        if(image(r+1, c)==WHITE && expl[r+1][c]==0 && journey[r+1][c]==0 && r+1 < image.width()){
          frontier.enqueue({r+1, c});
          journey[r+1][c]=1;
          //expl[current.row+1][current.col]=1;
        }
        if(image(r, c-1)==WHITE && expl[r][c-1]==0 && journey[r][c-1]==0 && c-1 > -1){
          frontier.enqueue({r, c-1});
          journey[r][c-1]=1;
          //expl[current.row][current.col-1]=1;
        }
        if(image(r, c+1)==WHITE && expl[r][c+1]==0 && journey[r][c+1]==0 && c+1 < image.height()){
          frontier.enqueue({r, c+1});
          journey[r][c+1]=1;
          //expl[current.row][current.col+1]=1;
        }//end of path exploring
  }

  writeToFile(image, output_file);
  return EXIT_SUCCESS;
}
//#################################################################//