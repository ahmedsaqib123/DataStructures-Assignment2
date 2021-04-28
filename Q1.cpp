#include<iostream>
#include<cstring>
using namespace std; 

char print_board(char board[4][4],int i,int j) 		//prints the values..
{
	cout<<board[i][j]<<" ";
	cout<<"("<<i<<","<<j<<")"<<endl;
}

bool func2(char board[4][4],int i,int j)		//checks for the word TOUGH..
{
	
	if((board[i][j]=='T')||(board[i][j]=='O')||(board[i][j]=='U')||(board[i][j]=='G')||(board[i][j]=='H'))  
	{
	return true;
	}
	else 
	return false;
}

bool BoundaryCondition(int i, int j)    //checks the Boundary Condition..
{      
   if(i>=0 && i<4 && j>=0 && j<4)
   {
   		return true;
   } 
   return false;
}

bool func1(char board[4][4],int row,int col)   
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(BoundaryCondition(i,j)==true) 		// sends the value of i and j to be checked.
			{
				if(func2(board,i,j)==true)
				{
					print_board(board,i,j);
				}
				else 
				continue;					
			}
					
		}	
	}	
	return false; 
}
		
int main()
{
	char board[4][4]= { 	//4x4 Board
	{'T', 'Q', 'P', 'V'}, 
	{'S', 'O', 'J', 'K'}, 
	{'R', 'U', 'G', 'D'}, 
	{'A', 'C', 'B', 'H'} 
	};
	
	cout<<"- Board -"<<endl;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	cout<<"- Co-ordinates: -"<<endl;
	func1(board,4,4);
	
	return 0;
}
