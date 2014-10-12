class Solution {
public:
               int partition(int A[], int lo, int hi) 
                {
                        int i = lo; 
                        int j = hi+1;
                        while(1){
                                while(A[lo] < A[--j])
                                        if(j == lo) 
                                                break;
                                while(A[lo] > A[++i])
                                        if(i == hi) 
                                                break;
                                if(i >= j)
                                        break;
                                swap(A[i], A[j]);
                        }
                        swap(A[j], A[lo]);
                        return j;
                }
                void quick_sort(int A[],int lo, int hi) 
                {
                        if(lo >= hi)    
                                return;
                        int j = partition(A, lo, hi);
                        quick_sort(A, lo, j-1);
                        quick_sort(A, j+1, hi);
                }
                int firstMissingPositive(int A[], int n) {
                        if(n == 0)
                                return 1;
                        quick_sort(A, 0, n-1);
                        int i = 1;
                        int flg = -1;
                        for(int i = 0; i < n-1; ++i)
                        {
                                if(A[i] > 0){
                                        if(flg == -1){
                                                flg = 1;
                                                if(A[i] != 1)
                                                        return 1;
                                        }
                                        if(A[i] == A[i+1]){
                                                if(i == n-2)
                                                        return A[i+1] + 1;
                                                continue;
                                        }
                                        else{
                                                if(A[i] + 1 != A[i+1])
                                                        return A[i] + 1;
                                                else{
                                                        if(i == n-2)
                                                                return A[i+1] + 1;
                                                }
                                        }
                                }
                        }
                        if(A[n-1] == 1)
                            return 2;
                        return 1;
                }
}



