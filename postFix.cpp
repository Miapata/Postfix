// POSTFIX.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// C++ program to evaluate value of a postfix expression  
#include <iostream>  
#include <string.h>  
#include <stack>
#include <string>
using namespace std;


stack<int> ourStack;

// The main function that returns value of a given postfix expression  
int evaluatePostfix(string exp)
{

	// Scan all characters one by one  
	for (int i = 0; i < exp.length(); ++i)
	{
		//We check if the character is a digit
		if (isdigit(exp[i])) {
			
			//If it is a digit, check the next character to see if it is a digit
			if (isdigit(exp[i + 1])) {
				string digit;
				digit += exp[i];
				//place
				int index = i + 1;

				//While the next index is a digit, add it to the digit string
				//When it is done, push the integer to the stack
				while (isdigit(exp[index]))
				{
					digit += exp[index];
					index++;
				}
				i = index;
				int number = stoi(digit);
				ourStack.push(number);

			}

			//If the next index is not a digit, push our current index to the stack
			else
			{
				ourStack.push(exp[i] - '0');
			}
		}
		//If it is a space, do nothing
		else if (isspace(exp[i])) {

		}


		// If the scanned character is an operator, pop two  
		// elements from stack apply the operator  
		else
		{

			int val1 = ourStack.top();
			ourStack.pop();

			int val2 = ourStack.top();
			ourStack.pop();

			//Here we are able to do the operations
			switch (exp[i])
			{
			case '+': ourStack.push(val2 + val1); cout << "Used values: " << val2 << " & " << val1 << endl; break;
			case '-': ourStack.push(val2 - val1); cout << "Used values: " << val2 << " & " << val1 << endl; break;
			case '*': ourStack.push(val2 * val1); cout << "Used values: " << val2 << " & " << val1 << endl; break;
			case '/': ourStack.push(val2 / val1); cout << "Used values: " << val2 << " & " << val1 << endl; break;
			case ' ': break;

			default: break;
			}
		}

	}

	// If the scanned character is an operand (number here),  
	// push it to the stack.  


	return ourStack.top();
}

// Main program to test above functions  
int main()
{
	char exprChar[1000];
	cin.getline(exprChar, 1000);
	string exp = exprChar;

	cout << "postfix evaluation: " << evaluatePostfix(exp) << endl;
	system("pause");
	return 0;

}
