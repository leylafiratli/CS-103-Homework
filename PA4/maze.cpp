/* 
maze.cpp

Author:

Short description of this file:
*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

int fillMaze(Location,Location**,char**maze, int);
// main function to read, solve maze, and print result
int main() {
   int rows, cols, result;
   char** mymaze;
   cin >> rows >> cols;
   
   mymaze = read_maze(&rows,&cols);
   
   if (mymaze == NULL) {
      cout << "Error, input format incorrect" << endl;
      return 1;
   }

   // when working on Checkpoint 3, you will call maze_search here.
   // here. but for Checkpoint 1, just assume we found the path.
   result = maze_search(mymaze,rows,cols); // TO BE CHANGED

   // examine value returned by maze_search and print appropriate output
   if (result == 1) { // path found!
      cout << rows << " " << cols << endl;
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0) { // no path :(
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

   // ADD CODE HERE to delete all memory 
   // that read_maze allocated
   for(int i=0; i< rows;i++) {
      delete [] mymaze[i];
   }
   delete [] mymaze;


   return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char** maze, int rows, int cols) {

   Location start;
   Location finish;

   bool isStart = false;
   bool isFinish = false;
// Loop to check if maze is valid and find the beginning and finishing locations
   for(int i =0; i < rows; i++) {
      for(int j=0;j<cols;j++) {
         if(maze[i][j] == 'S'){
            start.row = i;
            start.col = j;
            isStart = true;
         }
         else if(maze[i][j] == 'F') {
            finish.row = i;
            finish.col = j;
            isFinish = true;
         }
      }
   }

   //Setup queue
   if(!isStart || !isFinish) {
      return -1;
   }

   Queue q = Queue(rows*cols);
   Location** predecessor = new Location*[rows];
   for(int i = 0; i<rows;i++) {
     predecessor[i] = new Location[cols];
   }

   bool** isVisited = new bool*[rows];
   for(int i =0; i<rows;i++) {
      isVisited[i] = new bool[cols];
   }

   for(int i = 0; i<rows;i++) {
      for(int j = 0; j<cols;j++) {
         isVisited[i][j] = false;
      }
   }

   //Begin BFS
   q.add_to_back(start);
   bool foundPath = false;
   while(!q.is_empty() && !foundPath) {
      Location loc = q.remove_from_front();

      Location up;
      up.col = loc.col - 1;
      up.row = loc.row;

      Location down;
      down.col = loc.col+1;
      down.row = loc.row;

      Location left;
      left.row = loc.row-1;
      left.col = loc.col;

      Location right;
      right.row = loc.row+1;
      right.col = loc.col;

      Location neighbors[4] = {up,down,right,left};

      for(int i = 0;i<4;i++) {
         if(neighbors[i].row >= 0 && neighbors[i].row < rows && neighbors[i].col >= 0 && neighbors[i].col < cols) {
            if(maze[neighbors[i].row][neighbors[i].col] == '.' && isVisited[neighbors[i].row][neighbors[i].col] == false) {
               q.add_to_back(neighbors[i]);
               isVisited[neighbors[i].row][neighbors[i].col] = true;
               predecessor[neighbors[i].row][neighbors[i].col] = loc;
            }
            else if(maze[neighbors[i].row][neighbors[i].col] == 'F') {
               isVisited[neighbors[i].row][neighbors[i].col] = true;
               predecessor[neighbors[i].row][neighbors[i].col] = loc;
               foundPath = true;
               break;

            }
         }
      }

   }

   if(foundPath) {
      fillMaze(predecessor[finish.row][finish.col],predecessor,maze,rows);
   }

   for(int i = 0; i < rows; i++) {
      delete [] isVisited[i];
      delete [] predecessor[i];
   }
   delete [] isVisited;
   delete [] predecessor;

   
   return foundPath;
   //if(predecessor[finish.row][finish.col] == NULL) {
   //   return 0;
  // 
}

int fillMaze(Location loc, Location** predecessor, char** maze,int rows) {
   if(maze[loc.row][loc.col] == 'S') {
      return 1;
   }
   else {
      maze[loc.row][loc.col] = '*';
      return fillMaze(predecessor[loc.row][loc.col],predecessor,maze,rows);
   }
}
