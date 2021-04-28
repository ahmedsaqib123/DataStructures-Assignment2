//Implementation of Queue using Circular Array..
#include<iostream>
using namespace std; 

int i;

class Queue{
	
	public: 
	
	int front;
	int rear; 
	int arr[5];
	
	Queue()
	{
		front=-1; rear=-1; 
		for(int i=0;i<5;i++)
		{
			arr[i]=0;
		}	
	}
	
	void enqueue(int x)
	{
		if((rear+1)%5 ==front)
		{
			cout<<"Queue Overflowed!"<<endl;
		}
		else 
		{
			if(front==-1)
			{
				front=0;
			}
			rear=(rear+1)%5;
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
			front=(front+1)%5;
		}
	}
	
	void display()
	{
	cout<<"Values in Queue:"<<endl;
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
		cout<<arr[i]<<" ";
		}
	}
	else
	{
		i=front;
	   	do
	   	{
		   cout<<arr[i]<<" ";
		   i++;
		}while(i<5);
		
	   i=0;
	   while(i<=rear)
	   {
	   cout<<arr[i]<<" ";
	   i++;
	   }
	}
 }}
};

int main()
{
	Queue q; 
	int num;
	
	cout<<"Enter the values in Queue: "<<endl; 
	for(int i=0;i<5;i++)
	{
		cin>>num;
		q.enqueue(num); 
	}
	cout<<endl; 
	q.display();cout<<endl;
	
	cout<<"Dequeued Value: "<<endl;
	cout<<q.dequeue()<<" ";
	cout<<q.dequeue()<<endl;
	q.display();cout<<endl;
	
	q.enqueue(6);
	q.enqueue(8);
	q.display();
}
