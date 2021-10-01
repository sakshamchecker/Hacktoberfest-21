#include<iostream>
#define MAX 50
using namespace std;

class Stack
{
	int top;
	public:
	int a[MAX];
	Stack()
	{
		top=0;
	}
	bool push(int x);
	int pop();
	bool isEmpty();	
	int peek();
	void display();
};


bool Stack::push(int x)
{
	if(top>=MAX)
	{
		cout<<"\n\nSTACK OVERFLOW!";
		return 0;
	}
	else
	{
		a[top++]=x;
		cout<<"\n\nSuccessfully Pushed : "<<x;
		return 1;
	}
}

int Stack::pop()
{
	if(top<=0)
	{
		cout<<"\n\nSTACK UNDERFLOW!";
		return 0;
	}
	else
	{
		//cout<<"\n\nSuccessfully Pop : "<<a[top-1];
		int x=a[top-1];
		--top;
		return x;
	}
}

bool Stack::isEmpty()
{
	return(!top);
}

int Stack::peek()
{
	if(top==0)
	{
		cout<<"\n\nSTACK IS EMPTY! ";
		return -1;
	}
	else
	{
		return(a[top-1]);
	}
}

void Stack::display()
{
	if(top<=0)
	{
		cout<<"\n\nSTACK IS EMPTY! ";
	}
	else
	{
		cout<<"\n\nCurrent Stack : ";
		for(int i=0;i<top;++i)
		cout<<a[i]<<" ";
	}
	
}

int main()
{
	Stack s;
	int ch=1;
	cout<<"1 to push\n\n2 to pop\n\n3 to display\n\n4 to get top element\n\n5 to check if stack empty\n\n";
	while(choice)
	{
		cout<<"\n\nEnter choice: ";
		cin>>ch;
	if(ch==1)
	{
		int ele;
		cout<<"\nEnter element to push: ";
		cin>>ele;
		s.push(ele);
	}
	else if(ch==2)
	{
		cout<<"\n";
		cout<<s.pop()<<" is popped from stack";
	}
	else if(ch==3)
	{
		s.display();
	}
	else if(ch==4)
	{
		cout<<"\n";
		if(s.peek()!=-1)
		cout<<s.peek()<<" is on top";
	}
	else if(ch==5)
	{
		s.isEmpty()?cout<<"\nStack is empty!":cout<<"\nStack is not empty!";
	}
}
}