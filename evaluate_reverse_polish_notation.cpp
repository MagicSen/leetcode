#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <string>


using namespace std; 
class Solution {
public:
	bool isNumber(const string &s)	
	{
		string::size_type pos = s.find_first_of("0123456789");		
		if(pos == string::npos)
			return false;
		else
			return true;
	}
    	int evalRPN(vector<string> &tokens) {
		stack<int>  operand;
		for(int i = 0; i < tokens.size(); ++i)
		{
			if(isNumber(tokens[i]))	
			{
				string::size_type sz;	
				operand.push(atoi(tokens[i].c_str()));	

			}else{ 
				if(operand.size() < 2)
					continue;
				int b = operand.top(); 
				operand.pop(); 
				int a = operand.top(); 
				operand.pop();
				if(tokens[i].find_first_of("+") != string::npos){
					operand.push(a+b);
				}else if(tokens[i].find_first_of("-") != string::npos){
					operand.push(a-b);
				}else if(tokens[i].find_first_of("*") != string::npos){
					operand.push(a*b);
				}else{
					operand.push(a/b);
				}
			}
		}
		if(operand.size() != 0)
       			return operand.top(); 
		else
			return -1;
    	}
};

int main()
{
	Solution sol;
//	vector<string> expression{"4", "13", "5", "/", "+"};
	vector<string> expression;
	cout << sol.evalRPN(expression) << endl;
	return 0;
}
