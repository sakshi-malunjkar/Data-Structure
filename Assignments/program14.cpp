#include<iostream>
using namespace std;
class stack1
{
  private:
		int stack[50];
		int maxcapacity;
		int top;
		
  public:
  		stack1()
  		{
                   maxcapacity=50;
                   top=-1;
                   currentsize = 0;
                 }
                  
                 int getTop();
                 int pop();
                 void push(int Element);
                 int Empty();
                 int currentsize();
                 int Isfull();
                 
};

int stack1::Empty()
{
  if(top==-1)
   {  
      cout<<"Stack is empty";
      return 1;
   }
   
  else 
      return 0;
}

int stack1::Isfull()
{
  if(top==maxcapacity-1)
    cout<<"Stack is full";
    return 1;
   
  else 
       return 0;
 }
 
void stack1::pop()
{
   if(!Empty)
   return(stack[top--]);
   }
   
void stack1::push(int Element)
{
  if(!Isfull())
  stack(++top)=Element;
 }
 
int stack1::getTop()
{
   if(!Empty())
   return(stack(stack(top));
   }
   
int stack1::currentsize()
{
   return(top+1);
}

void main()
{
  stack1 s;
  
  s.pop();
  s.Isfull();
  s.Empty();
  s.getTop();
  s.currentsize();
}
  
  
