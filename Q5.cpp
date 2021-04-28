#include<iostream>
#include<fstream>
using namespace std; 

int main()
{
	int n; //size of the array 
	int x; //number of queries
	int left,right,k;
	int num=0;
	int arr[n],arr1[x];
	fstream input;
	try
	{
	input.open("Input_File_Q5.txt",ios::in);
		if(!input)
		{
			throw 1;
		}
		else 
		{
			cout<<"Size of Array:"<<" ";
			input>>n;
			cout<<n<<endl;
			cout<<"Elements in an Array: "<<endl;
			for(int i=0;i<n;i++)
			{
				input>>arr[i];
				cout<<arr[i]<<endl;
			}
			
			cout<<"Number of Queries:"<<" ";
			input>>x;
			cout<<x<<endl;		
			for(int i=0;i<x;i++)
			{
				input>>left; input>>right; input>>k;
				cout<<left<<" "<<right<<" "<<k<<endl;
				for(int j=left;j<=right;j++)
				{
					if(arr[j]>k)
					{
						num++;
					}
				}
				arr1[i]=num;
				num=0;
			}
			input.close();
		}
		
	}
	catch(int x)
	{
		if(x==1)
		{
			cout<<"File Not Opened!"<<endl;
		}	
	}
	
	ofstream output; 
	try
	{
		output.open("Output_File_Q5.txt",ios::out);
		if(!output)
		{
			throw 1;
		}
		else 
		{
			cout<<"Result of Queries:"<<endl;
			for(int i=0;i<x;i++)
			{
				output<<arr1[i]<<endl;
			}
			for(int i=0;i<x;i++)
			{
				cout<<arr1[i]<<endl;
			}
			output.close();
		}
	}
	catch (int x)
	{
		if(x==1)
		{
			cout<<"File Not Opened!"<<endl;
		}
	}

}
