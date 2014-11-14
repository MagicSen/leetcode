#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int binary_search(int A[], int hi, int lo, int target, int n){
		if(lo >= n)
			return n;
		if(hi == lo){
			if(A[lo] == target)
				return lo;
			else if(A[lo] > target)
				return lo;
			else{
				return lo+1;
			}
		}
		int mid = (hi + lo)/2;
		if(A[mid] == target)
			return mid;
		else if(A[mid] > target){
			return binary_search(A, mid, lo, target, n);
		}else{
			return binary_search(A, hi, mid+1, target, n);
		}
	}
	int searchInsert(int A[], int n, int target) {
		return binary_search(A, n, 0, target, n);	
	}
};

int main()
{
	Solution sol;
	int A[] = {1};
	cout << sol.searchInsert(A, 1, 111) << endl;
	return 0;
}
