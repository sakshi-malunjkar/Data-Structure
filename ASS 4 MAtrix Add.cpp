#include<iostream>

using namespace std;
class sparce 
{
    private :
                int A[10][3];
                int C[20][3];
                int a,b,c;
    public :
                void read();
                void dis();
                void add(sparce & B);
};

void sparce::read()
{

    cout<<"Enter the no. of rows and column :\n";
    cin>>a>>b;

    cout<<"Enter the no. of non zero elements :\n";
    cin>>c;
    
    A[0][0]=a;
    A[0][1]=b;
    A[0][2]=c;

    cout<<"Enter the matrix in triplet form \n";
    cout<<"Row   Column   non-zero element \n";
    for(int i=1;i<=c;i++)
    {
        cin>>A[i][0]>>A[i][1]>>A[i][2];
    }
        cout<<endl;

}

void sparce::dis()
{
    cout<<"Triplet form matrix is :\n";
    cout<<"Row   Column   non-zero element \n";
    for(int i=0;i<=c;i++)
    {
        cout<<A[i][0]<<"\t"<<A[i][1]<<"\t"<<A[i][2]<<endl;
    }
}

void sparce::add(sparce & B)
{
    int i=0;
    int j=0;
    int k=0;
    int t1=A[0][2];
    int t2=B.A[0][2];

    C[0][0]=A[0][0];
    C[0][1]=A[0][1];
   while(i<=t1  && j<=t2 )
   {
    if(A[i][0]<B.A[j][0])
    {
        C[k][0]=A[i][0];
        C[k][1]=A[i][1];
        C[k][2]=A[i][2];
        k++,i++;
    }

    else if(A[i][0]>B.A[j][0])
    {
        C[k][0]=B.A[j][0];
        C[k][1]=B.A[j][1];
        C[k][2]=B.A[j][2];
        k++,j++;
    }

    else if(A[i][1]<B.A[j][1])
    {
        C[k][0]=A[i][0];
        C[k][1]=A[i][1];
        C[k][2]=A[i][2];
        k++,i++;

    }
    else if(A[i][1]>B.A[j][1])
    {
        C[k][0]=B.A[j][0];
        C[k][1]=B.A[j][1];
        C[k][2]=B.A[j][2];
        k++,j++;
    }
   else
   {
        C[k][0]=A[i][0];
        C[k][1]=A[i][1];
        C[k][2]=A[i][2] + B.A[j][2];
        i++,j++,k++;

   }
   }
  
   while(i<=t1)
   {
        C[k][0]=A[i][0];
        C[k][1]=A[i][1];
        C[k][2]=A[i][2];
        k++;
   }

   while(j<=t2)
   {
        C[k][0]=B.A[j][0];
        C[k][1]=B.A[j][1];
        C[k][2]=B.A[j][2];
        k++;
   }

    C[0][2]=k-1;
    cout<<"Sum of two Sparce Matrix is : \n";
    for(int i=0;i<=C[0][2];i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }


}
int main()
{
    sparce a,b;
    a.read();
    a.dis();
    b.read();
    b.dis();
    cout<<"Addition Matrix :\n";
    a.add(b);


return 0;
}