#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
	int max(const int &a, const int &b){
		return a > b ? a : b;
	}
	// Basic idea is that runningsum = max(A[i]+runningsum, runningsum)
	int maxSubArray(int A[], int n) {
		if(n == 1)
			return A[0];
		int sum_max = A[0];
		int runningsum = A[0];
		for(int i = 1; i < n; ++i){
			runningsum = max(A[i] + runningsum, A[i]);
			sum_max = max(runningsum, sum_max);
		}
		return sum_max;
	}

	// force method log(n^2), time limited
/*	int maxSubArray(int A[], int n) {
		if(n == 1)        
			return A[0];
		int total = 0;
		for(int i = 0; i < n; ++i){
			int sum = A[i];
			for(int j = i+1; j < n; ++j){
				sum += A[j];
				if(sum > total){
					total = sum;
				}
			}
		}
		return total;
	}
	*/
};

int main()
{
	int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	Solution sol;
	cout << sol.maxSubArray(A, 9) << endl;
	return 0;
}
