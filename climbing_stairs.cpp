#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
	map<int, int> dictionary;
public:
    // 4ms
    int climbStairs(int n) {
       	if(n == 1) 
		return 1;
	if(n == 2)
		return 2;

	int a = 1;
	int b = 2;
	for(int i = 3; i < n; i = i + 2)
	{
		a = a + b;
		b = a + b;	
	}
	if(n % 2 == 1)
		return a+b;
	else
		return b;
    }
   /* int climbStairs(int n) {
       	if(n == 1) 
		return 1;
	if(n == 2)
		return 2;
	if(n == 3)
		return 3;
	int total = 0;
	if(!dictionary.count(n-1))
		dictionary[n-1] = climbStairs(n-1);

	if(!dictionary.count(n-2))
		dictionary[n-2] = climbStairs(n-2);

	return dictionary[n-1] + dictionary[n-2];
    }
    */
};

int main()
{
	Solution sol;
	cout << sol.climbStairs(6) << endl;
	return 0;
}
