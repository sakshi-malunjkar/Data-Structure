#include<iostream>
using namespace std;

class sparse_matrix
{

 private:
 int mat1[20][20];
 int mat2[20][20];
 //int sparse[20][20];
 int p[20][20];
 int i,j,k,m,n,t,s;
 int t1,t2;
	
 public:
 void read();
 void dis();
 void add(sparse_matrix &s);
 void simple_trans();
};

void sparse_matrix::read()
{
	
 cout<<"Enter the no. of rows and colunm:";
 cin>>m>>n;
 cout<<"Enter the non zero value:";
 cin>>t;
	
 cout<<"Enter the triplet form matrix:\n";
 for(i=1;i<=t;i++)
 {
  cin>>mat1[i][0]>>mat1[i][1]>>mat1[i][2];
 }
	
 mat1[0][0]=m;
 mat1[0][1]=n;
 mat1[0][2]=t;
}
void sparse_matrix::dis()
{
 cout<<"Triplet Matrix\n";
 cout<<"Row:" << m << "column:" << n << "value:" << t <<endl;
 for(int i=0;i<=mat1[0][2];i++)
 {
  
  cout<<mat1[i][0]<<"\t\t"<<mat1[i][1]<<"\t\t"<<mat1[i][2]<<"\t\t"<<endl;
  
 }
	
}
int main()
{
 sparse_matrix s1,s2;
 s1.read();
 s1.dis();
 //s2.read();
 //s2.dis();
 //s1.add(s2);
 s1.simple_trans();
}
void sparse_matrix::add(sparse_matrix &s)
{
 t1=mat1[0][2];
 t2=s.mat1[0][2];
 i=j=k=0;
 mat2[0][0]=mat1[0][0];
 mat2[0][1]=mat1[0][1];
 while(i<=t1 && i<=t2)
 {
  if(mat1[i][0]<s.mat1[j][0])
  {
      
      mat2[k][0]=mat1[i][0];
      mat2[k][1]=mat1[i][1];
      mat2[k][2]=mat1[i][2];
      k++;
      i++;
      
  }
  else if(mat1[i][0]>s.mat1[j][0])
     {
         mat2[k][0]=s.mat1[j][0];
      mat2[k][1]=s.mat1[j][1];
      mat2[k][2]=s.mat1[j][2];
      k++;
      j++;
     }
      else if(mat1[i][1]<s.mat1[j][1])
  {
      
      mat2[k][0]=mat1[i][0];
      mat2[k][1]=mat1[i][1];
      mat2[k][2]=mat1[i][2];
      k++;
      i++;
  }  
  else if(mat1[i][1]>s.mat1[j][1])
     {
         mat2[k][0]=s.mat1[j][0];
      mat2[k][1]=s.mat1[j][1];
      mat2[k][2]=s.mat1[j][2];
      k++;
      j++;
     }
     else
     {
         mat2[k][0]=mat1[i][0];
      mat2[k][1]=mat1[i][1];
      mat2[k][2]=mat1[i][2]+s.mat1[j][2];
      k++;
      i++;
      j++;
     }
 }
 for( ; i<=t1; i++)
 {
         mat2[k][0]=mat1[i][0];
      mat2[k][1]=mat1[i][1];
      mat2[k][2]=mat1[i][2];
      k++;
 }
    for( ; j<=t2; j++)
    {
            mat2[k][0]=s.mat1[j][0];
      mat2[k][1]=s.mat1[j][1];
      mat2[k][2]=s.mat1[j][2];
      k++;
    }
    mat2[0][2]=k-1;
    cout<<"sum of two sparse matrix are=\n";
    for(i=0;i<=mat2[0][2];i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<mat2[i][j]<<" ";
        }
        cout<<endl;
    }
}
void sparse_matrix::simple_trans()
{
    int k=1;
    int z=0;
    int s=0;
    for(s=0;s<mat1[0][1];s++)
    {
        for(i=0;i<=mat1[0][2];i++)
        {
            if(mat1[i][1]==z)
            {
                p[k][0]=mat1[i][0];
                p[k][1]=mat1[i][1];
                p[k][2]=mat1[i][2];
                k++;
            }
        }
    }   
        
                p[0][0]=mat1[0][1];
                p[0][1]=mat1[0][0];
                p[0][2]=mat1[0][2];
                
    cout<<"transpose of matrix are:\n";
    for(i=0;i<=mat1[0][2];i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<p[i][j]<<" ";
        }
    }cout<<endl;
}
