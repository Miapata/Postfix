#include "pch.h"

#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> ourStack;
int main()
{

	char expression[1000];



	cin.getline(expression, 1000);
	string expressionString = expression;


	for (int i = 0; i < expressionString.length()-1; i++) {
		char theChar = expressionString[i];
		char proceedingChar = expressionString[i + 1];
		cout << theChar << endl;
		cout << proceedingChar << endl;
		if (isdigit(theChar) && isdigit(proceedingChar)) {
			int charValue = (theChar - 0) + (proceedingChar - 0);
			ourStack.push(charValue);
		}
		else if (isdigit(theChar) && isblank(proceedingChar)) {
			int charValue = theChar - 0;
			ourStack.push(charValue);
		}

		int x;
		int y;
		int result;
		switch (theChar)
		{
		case '+':


			x = ourStack.top();
			ourStack.pop();

			y = ourStack.top();
			ourStack.pop();

			result = y + x;
			ourStack.push(result);

			break;

		case'-':
			x = ourStack.top();
			ourStack.pop();

			y = ourStack.top();
			ourStack.pop();

			result = y - x;
			ourStack.push(result);
			break;

		case'*':
			x = ourStack.top();
			ourStack.pop();

			y = ourStack.top();
			ourStack.pop();

			result = y * x;
			ourStack.push(result);
			break;

		default:
			break;
		}

	}
	cout << ourStack.top();
	return 0;
}
