#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool groupBrackets(char o,char c)
{
	if(o == '(' && c == ')')
	{
		return true;
	 } 
	else if(o == '{' && c == '}') {
		return true;
	}
	else if(o == '[' && c == ']'){
		return true;
	} 
	return false;
}
bool bracketBalanced(string str)
{
	stack<char>  s;
	for(int i =0;i<str.length();i++)
	{
		if(str[i] == '(' || str[i] == '{' || str[i] == '[')
			s.push(str[i]);
		else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if(s.empty())
			{
			return false;	
			}
				
				else if(!groupBrackets(s.top(),str[i])){
					return false;
				}
			else
				s.pop();
		}
	}
	if(s.empty()){
		return true;
	}
	return false;
}

int main()
{
	
	string exp;
	cout<<"Enter an expression:  "; 
	cin>>exp;
	if(bracketBalanced(exp))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";
}
