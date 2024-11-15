// Online C++ compiler to run C++ program online
/*
Name : Prachi Mehetre
Class : SE B2
Roll no.: 47
PROBLEM STATEMENT :
String operations: A palindrome is a string of characters that's identical 
when read in forward and backward direction. Typically, punctuation, 
capitalization, and spaces are ignored. For example, “1.Poor Dan is in a 
droop!!” is a palindrome, as can be seen by examining the characters 
“poordanisinadroop” and observing that they are identical when read 
forward and backward directions. One way to check for a palindrome is to 
reverse the characters in the string and compare them with the original-in a 
palindrome, the sequence will be identical. 
Write C++ program with functions using Standard Template Library (STL) 
stack1. To print original string followed by reversed string using stack
2. To check whether given string is palindrome or not*/
#include <iostream>
#include <string>
using namespace std;

class stack1 {
public:
    char arr_stack[100];
    int top;

public:
    void push(char value);
    void pop();
    int is_full();
    int is_empty();

    stack1() 
	{
        top = -1;
    }
};

bool isAlphabetic(char ch);

class functions 
{
private:
    string originalString;

public:
    void getdata();
    void removeNonAlphanumeric();
    void reverse(stack1& s);
    void display();
    bool isPalindrome(stack1& s);
};

void stack1::push(char value) 
{
    if (!is_full()) 
	{
        top++;
        arr_stack[top] = value;
    } else {
        cout << "Stack is full.\n";
    }
}

void stack1::pop() 
{
    if (!is_empty()) 
	{
        top--;
    } else {
        cout << "Stack is empty.\n";
    }
}

int stack1::is_full() 
{
    return top == 99;
}

int stack1::is_empty() 
{
    return top == -1;
}

void functions::getdata() 
{
    cout << "Enter a string: ";
    getline(cin, originalString);
}

void functions::removeNonAlphanumeric()
{
    string cleanedString;
    for (int i = 0; i < originalString.length(); ++i)
    {
        if (isAlphabetic(originalString[i])) 
		{
            cleanedString += tolower(originalString[i]);
        }
    }
    originalString = cleanedString;
}

void functions::reverse(stack1& s) 
{
    for (int i = 0; i < originalString.length(); ++i) 
	{
        if (isAlphabetic(originalString[i])) 
		{
            s.push(originalString[i]);
        }
    }
}

void functions::display() 
{
    cout << "Original String: " << originalString << endl;
}

bool functions::isPalindrome(stack1& s) 
{
    string reversedString;

    for (int i = 0; i < originalString.length(); ++i) 
	{
        if (isAlphabetic(originalString[i])) 
		{
            reversedString += s.arr_stack[s.top];
            s.pop();
        }
    }

    cout << "Reversed String: " << reversedString << endl;

    if (originalString == reversedString) 
	{
         cout << "The entered string is a palindrome.\n";
    } 
	else 
	{
         cout << "The entered string is not a palindrome.\n";
    }
}


bool isAlphabetic(char ch) {
	
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
    	return true;
	}
	else
	{
		return false;
	}
}

int main() {
    stack1 s;
    functions f;

    f.getdata();
    f.removeNonAlphanumeric();
    f.reverse(s);
    f.display();

    f.isPalindrome(s);

    return 0;
}
/*OUTPUT :
Enter a string: 1.Poor Dan is in a droop!!!
Original String: poordanisinadroop
Reversed String: poordanisinadroop
The entered string is a palindrome.
*/
