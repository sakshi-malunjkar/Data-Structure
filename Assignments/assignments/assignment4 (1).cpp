#include<iostream>
using namespace std;
class sparse
{
   public :
         int a[10][10],b[10][10],c[10][10],i=1,j=1,k=1,r=0,q=0,p=3,m=0,n=0;
         
   public :
         void getdata()
         { 
               cout<<"Enter the no. of rows for matrix "<<endl;
               cin>>r;
               cout<<"Enter the elements of sparse matrix  :"<<endl;
               for(i=0;i<r;i++)
               {
                  for(j=0;j<p;j++)
                  {
                       cin>>a[i][j];
                  }
               }
          }
          void display()
          {
                cout<<"Display matrix  :"<<endl;
               for(i=0;i<r;i++)
               {
                  for(j=0;j<p;j++)
                  {
                       cout<<a[i][j]<<"\t";
                  }
                  cout<<"\n";
               }    
          }
          sparse addition(sparse objb,sparse objc)
          {
               m=a[0][2];
               n=objb.a[0][2];
               objc.a[0][0]=a[0][0];
               objc.a[0][1]=a[0][1];
               while(i<=m && j<=n)
               {
                  if(a[i][0]==objb.a[j][0])
                  {
                      if(a[i][1]==objb.a[j][1])
                      {
                            objc.a[k][0]=a[i][0];
                            objc.a[k][1]=a[i][1];
                            objc.a[k][2]=a[i][2] + objb.a[j][2];
                            i++,j++,k++;
                      }
                      else if(a[i][1]<objb.a[j][1])
                      {
                            objc.a[k][0]=a[i][0];
                            objc.a[k][1]=a[i][1];
                            objc.a[k][2]=a[i][2];
                            i++,k++;
                      }
                      else
                      {
                            objc.a[k][0]=objb.a[i][0];
                            objc.a[k][1]=objb.a[i][1];
                            objc.a[k][2]=objb.a[i][2];
                            j++,k++;
                      }
                  }
                  else if(a[i][0] < objb.a[j][0])
                  {
                       objc.a[k][0]=a[i][0];
                       objc.a[k][1]=a[i][1];
                       objc.a[k][2]=a[i][2];
                       i++,k++;
                  }
                  else
                  {
                        objc.a[k][0]=objb.a[i][0];
                        objc.a[k][1]=objb.a[i][1];
                        objc.a[k][2]=objb.a[i][2];
                        j++,k++;
                   }
               }
               while(i<=m)
               {
               	    objc.a[k][0]=a[i][0];
                    objc.a[k][1]=a[i][1];
                    objc.a[k][2]=a[i][2];
                    i++,k++;
			   }
			   while(j<=n)
               {
               	    objc.a[k][0]=objb.a[j][0];
                    objc.a[k][1]=objb.a[j][1];
                    objc.a[k][2]=objb.a[j][2];
                    i++,j++;
			   }
               objc.a[0][2]=k-1;
              /* cout<<"Addition of Matrices :"<<endl;
               for(i=0;i<objc.a[0][2];i++)
               {
                     for(j=0;j<3 ;j++)
                     {
                          cout<<objc.a[i][j]<<"\t";
                     }
                     cout<<endl;   
               }
            }    */
			return objc;  
            
};

int main()
{     
   int option,ch;
   sparse obja,objb,objc,addition;
   
   do{
        cout<<"1.Read the matrices,"<<endl<<"2.Display the Matrices"<<endl<<"3.Addition"<<endl;
        cout<<"Enter your choice :"<<endl;
        cin>>ch;
        switch(ch)
        {
              case 1 :
                        obja.getdata();
                        objb.getdata();
                        break;
           
               case 2 :
                         obja.display();
                         objb.display();
                         break;  
                        
               case 3 :
                         addition = objc.addition(obja,objb);
                         addition.display();
                         break;
              default :
                      cout<<"Enter Valid Choice"<<endl;
                      break;
         }
         cout<<"Do you want to continue(1-Yes & 2-No)"<<endl;
         cin>>option;
   }
   while(option==1);
   return 0;
}


