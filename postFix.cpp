#include "pch.h"

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
	// Create a stack of capacity equal to expression size  

	int i;

	// See if stack was created successfully  


	// Scan all characters one by one  
	for (i = 0; exp[i]; ++i)
	{
		char charWeAreEvaluating = exp[i];
		// If the scanned character is an operand (number here),  
		// push it to the stack.  
		if (isdigit(exp[i]) && (isblank(exp[i + 1]) || exp[i + 1] == NULL)) {
			ourStack.push(exp[i] - '0');
		}



		else if (isdigit(exp[i]) && isdigit(exp[i + 1])) {
			ourStack.push((exp[i] - '0') + (exp[i + 1] - '0'));
			i++;

		}
		else if (isblank(exp[i]))
			break;
		// If the scanned character is an operator, pop two  
		// elements from stack apply the operator  
		else
		{
			int val1 = ourStack.top();
			ourStack.pop();
			int val2 = ourStack.top();
			ourStack.pop();
			switch (exp[i])
			{
			case '+': ourStack.push(val2 + val1); break;
			case '-': ourStack.push(val2 - val1); break;
			case '*': ourStack.push(val2 * val1); break;
			case '/': ourStack.push(val2 / val1); break;
			}
		}
	}
	return ourStack.top();
}

// Driver program to test above functions  
int main()
{
	char exprChar[1000];
	cin.getline(exprChar, 1000);
	string exp = exprChar;

	cout << "postfix evaluation: " << evaluatePostfix(exp);
	return 0;
}
