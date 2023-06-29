#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<int> st1, st2;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			st1.push(num);
			if(st2.empty() || st2.top() >= num)
				st2.push(num);
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			int num = -1;
			if(!st1.empty())
			{
				num = st1.top();
				st1.pop();
				if(st2.top() == num)
					st2.pop();
			}
			return num;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(st1.empty())
				return -1;
			return st1.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(st2.empty())
				return -1;
			return st2.top();
		}
};