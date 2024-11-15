/*
Name : Prachi Mehetre
Class : SE B2
Roll no.:47

PROBLEM STATEMENT :
Polynomial operations: Write a menu driven C++ program with class for 
single variable polynomial and write functions to perform following 
polynomial operations using arrays 
1. Read polynomial
2. Display polynomial
3. Add two polynomials 
You can try above polynomial operation using Linked list*/
#include <iostream>
#include<math.h>
using namespace std;

typedef struct
{
    float coefficient;
    int exponent;
}polynomial_term;

class polynomial
{
     private :
             polynomial_term poly[100];
             int total_terms;
     public :
             polynomial()
             {
                  total_terms=0;
             }
             void read_poly();
             void dis_poly();
             double evaluate(double value);
             polynomial add_poly(polynomial B);
};
//read poly

void polynomial::read_poly()
{
     int i;
     cout<<"\nEnter the total no. of terms : ";
     cin>>total_terms;
     for(i=0;i<total_terms;i++)
     {
          cout<<"Enter exponent of "<<i+1<<" term :";
          cin>> poly[i].exponent;
         
          cout<<"Enter co-efficient of "<<i+1<<" term :";
          cin>> poly[i].coefficient;
     }
}
void polynomial::dis_poly()
{
     int i;
     for(i=0;i<total_terms;i++)
     {
          cout<<poly[i].coefficient<<"x^";
          cout<<poly[i].exponent;
          cout<<"  +"<<"\t";
     }
     cout<<endl;
}
double polynomial::evaluate(double value)
{
     int i;
     double result=0;
     while(i<=total_terms)
     {
           result+=poly[i].coefficient * pow(value,poly[i].exponent);
           i++;
     }
     return result;
}
polynomial polynomial::add_poly(polynomial B)
{
      int i=0,j=0,k=0;
      polynomial C;
      while(i<total_terms && j<B.total_terms)
      {
          if(poly[i].exponent==B.poly[j].exponent)
          {
                C.poly[k].coefficient=poly[i].coefficient + B.poly[j].coefficient;
                C.poly[k].exponent=poly[i].exponent;
                i++,j++,k++;
          }
          else if(poly[i].exponent > B.poly[j].exponent)  
          {
                C.poly[k].coefficient=poly[i].coefficient;
                C.poly[k].exponent=poly[i].exponent;
                i++,k++;
          }
          else
          {
                C.poly[k].coefficient=B.poly[j].coefficient;
                C.poly[k].exponent=B.poly[j].exponent;
                j++,k++;
          }
     }
     while(i<total_terms)
     {
           C.poly[k].coefficient=poly[i].coefficient;
           C.poly[k].exponent=poly[i].exponent;
           i++,k++;
     }
     while(j<B.total_terms)
     {
           C.poly[k].coefficient=B.poly[j].coefficient;
           C.poly[k].exponent=B.poly[j].exponent;
           j++,k++;
     }
     C.total_terms=k;
     return C;
}
               
int main()
{  
      polynomial obj1,obj2,addition;
      int option,ch;
      do{
     
        cout<<"1.To read the polynomial "<<"\n""2.To display polynomial "<<"\n""3.Addition of polynomials"<<"\n""4.Evaluate the polynomial "<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ch;
        switch(ch)
        {
              case 1 :
                       obj1.read_poly();
                       obj2.read_poly();
                       break;
                       
              case 2 :
                       obj1.dis_poly();
                       obj2.dis_poly();
                       break;
                       
              case 3 :
                      addition=obj1.add_poly(obj2);
                      addition.dis_poly();
                      break;
                       
              case 4 :
                      double ans=obj1.evaluate(2);
                      cout<<"Answer after evaluating a polynomial 1  is :"<<ans<<endl;
                      break;
                 
         }
         cout<<"Do you want to continue(1-Yes & 2-No)"<<endl;
         cin>>option;
      }while(option==1);
      return 0;
}
/*OUTPUT
/tmp/DjJpSCjkSm.o
1.To read the polynomial 
2.To display polynomial 
3.Addition of polynomials
4.Evaluate the polynomial 
Enter your choice
1
Enter the total no. of terms : 3
Enter exponent of 1 term :4
Enter co-efficient of 1 term :3
Enter exponent of 2 term :2
Enter co-efficient of 2 term :6
Enter exponent of 3 term :0
Enter co-efficient of 3 term :9
Enter the total no. of terms : 6
Enter exponent of 1 term :6
Enter co-efficient of 1 term :5
Enter exponent of 2 term :5
Enter co-efficient of 2 term :3
Enter exponent of 3 term :4
Enter co-efficient of 3 term :2
Enter exponent of 4 term :1
Enter co-efficient of 4 term :5
Enter exponent of 5 term :6
Enter co-efficient of 5 term :3
Enter exponent of 6 term :0
Enter co-efficient of 6 term :9
Do you want to continue(1-Yes & 2-No)
1
1.To read the polynomial 
2.To display polynomial 
3.Addition of polynomials
4.Evaluate the polynomial 
Enter your choice
2
3x^4  +	6x^2  +	9x^0  +	
5x^6  +	3x^5  +	2x^4  +	5x^1  +	3x^6  +	9x^0  +	
Do you want to continue(1-Yes & 2-No)
1
1.To read the polynomial 
2.To display polynomial 
3.Addition of polynomials
4.Evaluate the polynomial 
Enter your choice
4
Answer after evaluating a polynomial 1  is :81
Do you want to continue(1-Yes & 2-No)
1
1.To read the polynomial 
2.To display polynomial 
3.Addition of polynomials
4.Evaluate the polynomial 
Enter your choice
3
5x^6  +	3x^5  +	5x^4  +	6x^2  +	5x^1  +	3x^6  +	18x^0  +	
Do you want to continue(1-Yes & 2-No)
2
*/
