#include<iostream>
#include<fstream>
using namespace std;

char maze[4][5] =
{ 
	{'*','*','*','*','*'},
	{'*','*','*','*','*'},
	{'*','*','*','*','*'},
	{'*','*','*','*','*'},
};

char sol[4][5];
int n,m;
	
class Maze{
	
	public:
		int row,col;
		char **arr=NULL;
		
		Maze(int row,int col)
		{
			this->row=row;
			this->col=col;
			
			arr=new char*[row];
			for(int i=0;i<row;i++)
			{
				arr[i]=new char[col];
			}
		}
	
		void maze_board()
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					arr[i][j]='*';
				}
			}
			
			fstream input;
			input.open("Input_File_Q4.txt",ios::in);
			input>>n>>m;
			
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					input>>arr[i][j];
				}
			}
		
		input.close();
		}

bool BoundaryCondtion(int i,int j)
{
	if (i<0 || j<0 || i>n || j>m )
	return false;
	else
	return true;
}	
	
	
bool solve_maze(int i,int j)
{
	
	if(i==n-1&&j==m-1)
	{
		sol[i][j]='-';
		return true;
	}
 
	else 
	{
		if(BoundaryCondtion(i,j)==true)
		{
			if(arr[i][j]=='-')
			{
			maze[i][j]='-'; 
			
			if (solve_maze(i+1,j))
			{
				sol[i][j]='-';
				return true;
			}
			else if(solve_maze(i-1,j))
			{
				sol[i][j]='-';
				return true;
			}
			else if(solve_maze(i,j+1))
			{
				sol[i][j]='-';
				return true;	
			}
			else if(solve_maze(i,j-1))
			{
				sol[i][j]='-';
				return true;
			}
			maze[i][j]='*';
			}	
		}	
	}
	return false;	
}
	void print_maze()
	{
		try{
		fstream output;
		output.open("Output_File_Q4.txt",ios::out);
		if(!output)
		{
			throw 1;
		}
		else
		{
			cout<<"Co-Ordinates: "<<endl;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++) 
				{
					if(sol[i][j]=='-')
					{
						output<<"("<<i<<","<<j<<")"<<endl;
						cout<<"("<<i<<","<<j<<")"<<endl;
					}
				}
			}	
			output.close();
		}
	}	
	
	catch(int x)
	{
		if(x==1)
		{
			cout<<"File Not Opened!!"<<endl;
		}
	}
}

};

int main()
{
	try{
		ifstream input;
		input.open("Input_File_Q4.txt",ios::in);
		if(!input)
		{
			throw 1;
		}
		else 
		{
			input>>n>>m;
			cout<<"Row: "<<n<<" "<<"Column: "<<m<<endl<<endl;
			cout<<"Maze:"<<endl;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					input>>maze[i][j];
					cout<<maze[i][j]<<" ";
				}
				cout<<endl;
			}
			input.close();
			cout<<endl;
		}
	}
	
	catch(int x)
	{
		if(x==1)
		cout<<"File Not Opened!!"<<endl;
	}
	
	int i=0,j=0; 
	Maze M(n,m);
	M.maze_board();
	M.solve_maze(i,j);
	
	cout<<"Path of the Maze: "<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<sol[i][j]<<" ";
		}
	cout<<endl;
	}
	cout<<endl;
	M.print_maze();
}
