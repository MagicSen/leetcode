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
			if(lt == gt)
				return A[lt];
			else if((lt-lo) % 2 == 1)
				return less_equal_bigger(A, lo, lt-1);
			else
				return less_equal_bigger(A, gt+1, hi);
		}

		int singleNumber(int A[], int n) {
			return less_equal_bigger(A, 0, n-1);
		}
/*
	// A Xor A = 0
	public:
		int singleNumber(int A[], int n) {
			int result = 0;
			for(int i = 0; i < n ; ++i)
			{
				result ^= A[i];	
			}
			return result;
		}
		*/
/*
 	// Myself solution using extra memory
	private:
		set<int> a_table;
	public:
		int singleNumber(int A[], int n) {
			for(int i = 0; i < n; ++i)
			{
				if(a_table.find(A[i]) == a_table.end()){
					a_table.insert(A[i]);
				}else{
					a_table.erase(A[i]);
				}
			}
			return *(a_table.begin());
		}
		*/

};
int main()
{
	int A[] = {1,1,2,2,3,3,44,5,5,4,44,4,13};
	Solution sol;
	cout << sol.singleNumber(A, 13) << endl;
	return 0;
}
