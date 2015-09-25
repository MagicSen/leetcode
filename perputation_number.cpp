#include <iostream>
#include <vector>
#include <algorithM>

using namespace std;

class Solution {
	public:
		int nFactorial(int n){
			if(n == 1 || n == 0){
				return n;
			}else{
				return n*nFactorial(n-1);
			}
		}
		string getPermutation(int n, int k) {
			if(k > nFactorial(n)){
				return "";
			}
			vector<string> dict={"1", "2", "3", "4", "5", "6", "7", "8", "9"};
			vector<string> vec(dict.begin(), dict.begin() + n);
			return getPermutation(n, k-1, vec);
		}
		string getPermutation(int n, int k, vector<string> &vec){
			if(vec.size() == 0){
				return "";	
			}
			if(vec.size() == 1){
				return vec[0];
			}
			int pos = k/nFactorial(n-1);
			string result = vec[pos];
			vec.erase(vec.begin() + pos);
			return result + getPermutation(n-1, k%nFactorial(n-1), vec);
		}
};

int main()
{
	Solution sol;
	cout << sol.getPermutation(3,1) << endl;
	return 0;
}
