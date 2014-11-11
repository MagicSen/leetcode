#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
	// Other person's method
	int getKth(int A[], int m, int B[], int n, int k){
		if(m == 0)
			return B[k-1];
		if(m > n)
			return getKth(B, n, A, m, k);
		if( k == 1){
			return A[0] < B[0] ? A[0] : B[0];
		}
		int pa = k / 2  > m ? m : k / 2 ;
		int pb = k - pa ; 
		// If A[pa-1] < B[pb-1], then the kth number must not in the A[1...pa-1], change the A's index, reverse is also true.
		if(A[pa - 1] < B[pb - 1])
			return getKth(A+pa, m-pa, B, n, k-pa);
		else if(A[pa-1] > B[pb-1])
			return getKth(A, m, B+pb, n-pb, k-pb);
		else
			// if equal return.
			return A[pa-1];

	}
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if((m+n) % 2)
			return getKth(A, m, B, n, (m+n)/2+1);
		else{
			return (getKth(A, m, B, n, (m+n)/2) + getKth(A, m, B, n, (m+n)/2+1))/2.0;
		}
	}
};

int main()
{
	int A[]={1,3,5};
	int B[]={2,4,6};
	Solution sol;
	cout << sol.findMedianSortedArrays(A, 3, B, 3) << endl;
	return 0;
}
