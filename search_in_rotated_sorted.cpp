#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    	int search(int A[], int n, int target) {
		if(n == 0)
			return -1;
		int min_index = 0;	
        	for(int i = 1; i < n; ++i)
		{
			if(A[i-1] > A[i]){	
				min_index = i;
				break;
			}
		}
		if(target <= A[n-1])
			return search(A, min_index, n-1, target);
		else
			return search(A, 0, min_index-1, target);
    	}

	int search(int A[], int begin, int end, const int &target){
		if(begin > end)
			return -1;
		int mid = (begin + end) / 2;
		if(A[mid] == target)
			return mid;
		else if(A[mid] > target)
			search(A, begin, mid-1, target);
		else
			search(A, mid+1, end, target);
	}
};

int main()
{
//	int A[] = {4,5,6,0,1,2,3};
	int A[] = {};
	Solution sol;
	cout << sol.search(A, 0, 4) << endl;
	return 0;
}
