#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
	// Dijkstra_quick_sort
	public:
		void swap_int(int A[], int a, int b)
		{
			int temp = A[a];	
			A[a] = A[b];
			A[b] = temp;
		}
		int less_equal_bigger(int A[], int lo, int hi)	
		{
			if(lo == hi)
				return A[lo];
			int lt = lo;
			int gt = hi;
			int temp = A[lo];
			int i = lo;
			while(i <= gt){
				if(A[i] < temp){
					swap_int(A, i, lt);
					lt++;
					i++;
				}else if(A[i] > temp){
					swap_int(A, i, gt);
					gt--;
				}else{
					i++;	
				}
			}
			// [lo lt-1] [lt gt] [gt+1, hi]
			if(gt == lt)
				return A[lt];
			else if((lt-lo) % 3 != 0)
				return less_equal_bigger(A, lo, lt-1);
			else
				return less_equal_bigger(A, gt+1, hi);
		}
		int singleNumber(int A[], int n) {
			return less_equal_bigger(A, 0, n-1);
		}
};
int main()
{
	int A[] = {1,1,1,2,2,2,3,4,4,4,5,5,5,44,44,44};
	Solution sol;
	cout << sol.singleNumber(A, 16) << endl;
	return 0;
}
