/*Searching: Write a C++ program to store roll numbers of students in an 
array who attended online lectures in random order. Write function for 
searching, whether a particular student attended lecture or not using 
1. Linear search 
2. Binary search 
3. Jump search 
compare the searching methods based on complexities of an algorithm
Provide choice to user to take input from user or using random numbers
Use Visual C++ compiler to compile and execute the program.
Name : Prachi Sachin Mehetre
Class : SY-B2
Roll No. : 47
*/
#include <iostream>
using namespace std;

const int MAX = 100;

// Array to store roll numbers
int rollNums[MAX];  

// Number of students attended 
int n;

// Function to get student roll numbers
void getRollNums() {
  cout << "Enter number of students attended: ";
  cin >> n;
  
  cout << "Enter roll numbers: ";
  for(int i = 0; i < n; i++) {
    cin >> rollNums[i]; 
  }
}

// Linear search
int linearSearch(int key) {
  for(int i = 0; i < n; i++) {
    if(rollNums[i] == key)
      return i; 
  }
  return -1;
}

// Binary search 
int binarySearch(int key) {
  int low = 0;
  int high = n - 1; 
  
  while(low <= high) {
    int mid = (low + high)/2;
    if(rollNums[mid] == key)
      return mid;
    else if(rollNums[mid] < key)
      low = mid + 1;
    else 
      high = mid - 1;  
  }
  
  return -1; 
}

// Jump Search
/*int jumpSearch(int key) {
  
  int blockSize = sqrt(n);
  
  int start = 0;
  int next = blockSize;
  
  while(start < n && rollNums[next-1] < key) {
    start = next;     
    next += blockSize; 
    
    if(next > n)  
      next = n;
  }
  
  for(int i = start; i<next; i++) {
    if(rollNums[i] == key)
      return i; 
  }
  
  return -1;  
}
*/
int main() {
  
  getRollNums();
  
  int roll;  
  cout << "\nEnter roll number to search: ";
  cin >> roll;

  int index = linearSearch(roll);
  if(index != -1) 
    cout << "Found at index " << index << " by Linear Search" << endl;
  else
    cout << "Not found by Linear Search" << endl; 
  
  index = binarySearch(roll);  
  if(index != -1)
    cout << "Found at index " << index << " by Binary Search" << endl;
  else  
    cout << "Not found by Binary Search" << endl;
    
 /* index = jumpSearch(roll);
  if(index != -1)
    cout << "Found at index " << index << " by Jump Search" << endl; 
  else
    cout << "Not found by Jump Search" << endl;  
*/
  return 0;
}
