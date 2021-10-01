Sudoku Solver
Send Feedback
Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.
Input Format:
There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.
Output Format:
The first and only line of output contains boolean value, either true or false, as described in problem statement.
Constraints:
The cell values lie in the range: [0, 9]
Time Limit: 1 second 
Note:
Input are given in a way that backtracking solution will work in the provided time limit.
Sample Input 1:
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output 1:
true
  
  
  
  
  
  
  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  
  
  #include <bits/stdc++.h>
using namespace std;
#define N 9

bool isemptyLocation(int grid[][N], int& row, int& col)
{
   for(int i=0; i<N; i++)
   {
      for(int j=0; j<N; j++)
      {
         if(grid[i][j] == 0)
         {
            row = i;
            col = j;

            return true;
         }
      }
   }
   return false;
}

bool inGrid(int grid[][N], int row, int col, int num)
{
   int rf = row - (row%3);
   int cf = col - (col%3);

   for(int i=0; i<3; i++)
   {
      for(int j=0; j<3; j++)
      {
         if(grid[i+rf][j+cf] == num)
            return false;
      }
   }
   return true;
}


bool inCol(int grid[][N], int col, int num)
{
   for(int i=0; i<N; i++)
   {
      if(grid[i][col] == num)
      {
         return false;
      }
   }
   return true;
}



bool  inRow(int grid[][N], int row, int num)
{
   for(int i=0; i<N; i++)
   {
      if(grid[row][i] == num)
      {
         return false;
      }
   }
   return true;
}
bool isSafe(int grid[][N], int row, int col, int num)
{
   return inRow(grid,row,num) && inCol(grid,col,num) && inGrid(grid, row, col, num);
}
bool solvesudoku(int grid[N][N])
{
   int row,col;
   if(!isemptyLocation(grid,row,col))
      return true ;
   
   for(int i=1; i<=N; i++)
   {
      if(isSafe(grid,row,col,i))
      {
         grid[row][col] = i;
         if(solvesudoku(grid))
         {
            return true;
         }
         grid[row][col] = 0;
      }
   }
   return false;
}

int main() {
    // your code goes here
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     int grid[N][N];
     for(int i=0; i<N; i++)
     {/*
      string s;
      cin>>s;
		*/
         for(int j=0; j<N; j++)
         {
             
            //grid[i][j] = s[j]-'0';
             cin>>grid[i][j];
         }
     }

     if(solvesudoku(grid))
         cout<<"true";
    else
        cout<<"false";
    /*
     for(int i=0; i<N; i++)
     {
         for(int j=0; j<N; j++)
         {
            cout<<grid[i][j];
         }
         cout<<endl;
     }
*/

    return 0;
}
