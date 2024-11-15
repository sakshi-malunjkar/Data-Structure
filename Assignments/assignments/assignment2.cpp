/*
Name: Prachi Mehetre
Class: SE-B2
Roll no.: 47
PROBLEM STATEMENT :
Random walk: A (drunken) cockroach is placed on a given square in the 
middle of a tile floor in a rectangular room of size n x m tiles. The bug 
wanders (possibly in search of an aspirin) randomly from tile to tile 
throughout the room. Assuming that it may move from his present tile to any 
of the eight tiles surrounding it (unless it is against a wall) with equal 
probability, how long will it take him to touch every tile on the floor at least 
once?
Write a C++ program to graphically show a random walk of a (drunken) 
cockroach and find the no of moves made.
*/



#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int row=50;
const int col=50;
int Tile[row][col];


void display_tiles(int x,int y)
{

	int m=x,n=y,i=0,j=0;

	cout<<"\n\nTiles to walk are-\n\n\n";
	
	for(i=0;i<m;i++)
	{
		for(int k=0;k<n;k++)
		{		
			cout<<" ___";
		}
		cout<<endl;
		for( j=0;j<n;j++)
		{	
			cout<<"| "<<i<<j;
		}
		
		cout<<"|"<<endl;
	}
	for(int k=0;k<n;k++)
	{		
		cout<<" ___";
	}
	cout<<endl<<endl;
	
}


int checker(int M,int N)
{
				
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(Tile[i][j]==0)
				{
					return 1;
				}
				
				
			}
		}
		
		return 0;

}




int main()
{
	srand(time(0));
	int moves=0,M,N,x,y;

	cout<<"Enter tiles dimension(MXN): ";
	cin>>M>>N;
	cout<<"Enter initial(x,y): ";
	cin>>x>>y;
	
	display_tiles(M,N);
	
	cout<<endl<<"("<<x<<","<<y<<")";
	
	int a=x,b=y;
	for(int i=0;i<50;i++)
	{
		for(int j=0;j<50;j++)
		{
			Tile[i][j]=0;
		}
	}
	
	Tile[x][y]=1;
	
	int flag=0;
	int random_var;
	bool final_check=true;
	while(final_check==true)
	{
		random_var=rand()%8;
		switch(random_var)
		{
			case 0:
			{	
				a++;
				break;
			}
			case 1:
			{
				b++;
				break;
			}
			case 2:
			{	
				a++;
				b++;
				break;
			}
			case 3:
			{	
				a++;
				b--;
				break;
			}
			case 4:
			{	
				a--;
				b++;
				break;
			}
			case 5:
			{	
				a--;
				
				break;
			}
			case 6:
			{
				b--;
				break;
			}
			case 7:
			{
				a--;
				b--;
				break;
			}
			default:
			{
				break;
			}
				
		}
		
		if(a >=0 && a<M && b>=0 && b<N)
		{
			cout<<endl<<"("<<a<<","<<b<<")";
			Tile[a][b]++;
			x=a;
			y=b;
			moves++;
		}
		
		a=x;
		b=y;
				
		
		flag=checker(M,N);
		if(flag!=1)
		{
			final_check=false;
		}
		else
		{
			final_check=true;
		}
		
	}
	
	cout<<"\n\n\nTotal moves covered are : "<<moves<<endl;
	
	return 0;
}
/*
OUTPUT :
Enter tiles dimension(MXN): 3
4
Enter initial(x,y): 3
1


Tiles to walk are-


 ___ ___ ___ ___
| 00| 01| 02| 03|
 ___ ___ ___ ___
| 10| 11| 12| 13|
 ___ ___ ___ ___
| 20| 21| 22| 23|
 ___ ___ ___ ___


(3,1)
(2,2)
(1,2)
(0,2)
(1,2)
(1,3)
(2,2)
(2,3)
(2,2)
(1,2)
(0,2)
(1,2)
(0,1)
(1,2)
(2,2)
(1,3)
(2,2)
(2,3)
(2,2)
(2,3)
(2,2)
(1,1)
(0,2)
(1,3)
(0,2)
(0,3)
(1,3)
(2,3)
(1,3)
(0,2)
(1,1)
(0,1)
(1,0)
(2,0)
(2,1)
(1,1)
(2,2)
(1,1)
(0,2)
(1,2)
(1,1)
(2,0)
(2,1)
(2,0)
(2,1)
(1,0)
(2,0)
(1,1)
(1,0)
(1,1)
(1,2)
(1,1)
(1,2)
(0,2)
(0,1)
(1,2)
(0,3)
(0,2)
(0,3)
(1,2)
(1,3)
(1,2)
(0,1)
(1,0)
(0,0)


Total moves covered are : 64

--------------------------------
Process exited after 10.64 seconds with return value 0
Press any key to continue . . .*/
