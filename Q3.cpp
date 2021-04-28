#include<iostream>
using namespace std; 

int i;

class Queue{
	
	public: 
	
	int front;
	int rear; 
	int arr[7];
	
	Queue()
	{
		front=-1; rear=-1; 
		for(int i=0;i<7;i++)
		{
			arr[i]=0;
		}	
	}
	
	void enqueue(int x)
	{
		if((rear+1)%7 ==front)
		{
			cout<<"Queue Overflowed!"<<endl;
		}
		else 
		{
			if(front==-1)
			{
				front=0;
			}
			rear=(rear+1)%7;
			arr[rear]=x;
		}
	}
	
	int dequeue()
	{
		if(front==-1 && rear==-1)
		{
			cout<<"Queue Underflow!!"<<endl;
		}
		else if (front==rear)
		{
			front=-1;
			rear=-1;
		}
		else 
		{
			front=(front+1)%7;
		}
	}
	
	void display()
	{
	string arr1[7]={"Google Chrome: ","VScode: ","VLC: ","MS-Word: ","PDF: ","Jupyter: ","Pycharm: "};
	if(front==-1 && rear==-1)
	{
	cout<<"Queue Underflow!!"<<endl;
	}
	else
	{
	if(front<=rear)
	{
		for( i=front ; i<= rear ; i++)
		{
		cout<<arr1[i]<<arr[i]<<"\t";
		}
	}
	else
	{
		i=front;
	   	do
	   	{
		   cout<<arr[i]<<" ";
		   i++;
		}while(i<7);
		
	   i=0;
	   while(i<=rear)
	   {
	   cout<<arr1[i]<<arr[i]<<"\t";
	   i++;
	   }
	}
 }cout<<endl;} 

	void wait() 			//Calculate Extra Seconds For MS-Word
	{
		while(arr[0]!=0)
		{
			for(int i=0;i<7;i++)
			{
				arr[i]=arr[i]-2;
			}
		}	
	}
	
	void display1()
	{
	string arr2[2]={"Virtual Box: ","Avast: "};
	if(front==-1 && rear==-1)
	{
	cout<<"Queue Underflow!!"<<endl;
	}
	else
	{
	if(front<=rear)
	{
		for( i=front ; i<= rear ; i++)
		{
		cout<<arr2[i]<<arr[i]<<"\t";
		}
	}
	else
	{
		i=front;
	   	do
	   	{
		   cout<<arr[i]<<" ";
		   i++;
		}while(i<7);
		
	   i=0;
	   while(i<=rear)
	   {
	   cout<<arr2[i]<<arr[i]<<"\t";
	   i++;
	   }
	}
 }cout<<endl;} 
	
	
	

};

int main()
{
	Queue q; 
	int num;
	
	cout<<"Enter the Execution Values: "<<endl; 
	for(int i=0;i<7;i++)
	{
		cin>>num;
		q.enqueue(num); 
	}
	cout<<endl; 
	q.display();cout<<endl;
	q.wait(); 
	q.display();cout<<endl;
	cout<<"Number of Seconds Required for MS-Word for Execution: "<<-q.arr[3]<<endl;cout<<endl;
	for(int i=0;i<7;i++)
	{
		q.dequeue();
	}
	cout<<"Enter Execution time for Virtual Box And Avast: "<<endl;
	for(int i=0;i<2;i++)
	{
		cin>>num;
		q.enqueue(num);
	}
	cout<<endl;
	q.display1();
	cout<<endl;
	cout<<"Number of Seconds Required for Avast And Virtual Box for Execution: "<<q.arr[0]+6<<endl;
	
	
}
