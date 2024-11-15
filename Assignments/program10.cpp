#include<iostream>
using namespace std;
class sparce_matrix
{
    private :
            int A[10][10],B[10][10];
            int i,j,k,l,m;
    public : 
            void read();
            void dis();
            void add(sparce_matrix & B);
};
int main()
{
    sparce_matrix obj1,obj2;
    
    cout<<"Enter Matrix1 : \n";
    obj1.read();
    
    cout<<"Enter Matrix2 : \n";
    obj2.read();
    
    cout<<"Matrix1 :\n";
    obj1.dis();
    
    cout<<"Matrix2 :\n";
    obj2.dis();
    
    cout<<"Addition Matrix :\n";
    obj1.add(obj2);
    return 0;
    
}
void sparce_matrix::read()
{
    cout<<"Enter the No. of rows and column for matrix:\n";
    cin>>i>>j;
    cout<<"Enter the number of non-zero elements : \n";
    cin>>m;
    A[0][0]=i;
    A[0][1]=j;
    A[0][2]=m;
    cout<<"Enter the matrix in Triplet form \n";
    for(int i=1;i<=m;i++)
    {
        cin>>A[i][0]>>A[i][1]>>A[i][2];
     }
  cout<<endl;
}
void sparce_matrix::dis()
{
  cout << "Matrix in Triplet form:\n";
 cout<<"Rows:"<<i<< "     Columns:"<<j<< "        Value:" <<m<< endl;
     for(int i=1;i<=m;i++)
    {
      cout <<A[i][0]<<"\t\t"<<A[i][1]<<"\t\t"<<A[i][2]<< endl;
    }
}

void sparce_matrix::add(sparce_matrix & B)
{
    int C[20][20];
    int i,t1,t2,j,k;
    t1 = A[0][2];
    t2 = B.A[0][2];
    i=j=k=1;
    C[0][0]=A[0][0];
    C[0][1]=A[0][1];
    while(i<=t1 && i<=t2)
    {
        if(A[i][0]<B.A[j][0])
        {
            C[k][0]=A[i][0];
            C[k][1]=A[i][1];
            C[k][2]=A[i][2];
        k++;
        i++;
        }
        else if(A[i][0]>B.A[j][0])
        {
            C[k][0]=B.A[j][0];
            C[k][1]=B.A[j][1];
            C[k][2]=B.A[j][2];
        k++;
        j++;
        }
        else if(A[i][1]<B.A[j][1])
        {
            C[k][0]=A[i][0];
            C[k][1]=A[i][1];
            C[k][2]=A[i][2];
        k++;
        i++;
        }
        else if(A[i][1]>B.A[j][1])
        {
          C[k][0]=B.A[i][0];
          C[k][1]=B.A[i][1];
          C[k][2]=B.A[i][2];
        k++;
        j++;
        }
        else
        {
            C[k][0]=A[i][0];
            C[k][1]=A[i][1];
            C[k][2]=A[i][2]+B.A[i][2];
            k++;
            j++;
            i++;
        }
    }
        
for(;i<=t1;i++)
{
    C[k][0]=A[i][0];
    C[k][1]=A[i][1];
    C[k][2]=A[i][2];
    k++;
}
for(;j<=t2;j++)
{
  C[k][0]=B.A[j][0];
  C[k][1]=B.A[j][1];
  C[k][2]=B.A[j][2];
  k++;
}
    C[0][2]=k-1;
    cout<<"Sum of two Sparce Matrix is : \n";
    for(i=0;i<=C[0][2];i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
}


