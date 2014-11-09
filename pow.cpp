#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
class Solution {
	map<int, double> temp_result;
public:
	double pow(double x, int n) {
		if(x == 0){
			return 0;
		}
		if(n < 0){
			n = -n;
			x = 1/x;
		}
		double result = 1;
		for(double temp=x; n > 0; n  = n >> 1){
			if( n % 2 == 1){
				result *= temp;
			}
			temp = temp * temp;
		}
		return result;
	}
	// My own method
	/*
	double pow(double x, int n) {
		if(x == 0)
			return 0;
		if(n == 0)
			return 1;
		if(n == 1)
			return x;
		if(n < 0){
			x = 1/x;
			n = -n;
		}
		if(temp_result.find(n/2) == temp_result.end()){
			temp_result[n/2] = pow(x, n/2);
		}
		return temp_result[n/2] * temp_result[n/2] * pow(x, n%2);
	}
	*/
};

int main()
{
	Solution sol;
	cout<< sol.pow(2, -3) << endl;
	return 0;
}
