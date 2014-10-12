#include <iostream>
#include <cmath>

using namespace std;

class Solution {
	public:
		// other people's method, long long required.
		int sqrt(int x) {
			if(x == 0)
				return x;
			unsigned long ans = 0;
			// Change a top bit to 1
			unsigned long bit = 1l << 15;
			while(bit > 0){
				// like 111000 to get the result
				ans |= bit;
				cout << ans << " ---" << endl;
				if(ans * ans > x){
					// if bigger, then xor to delete the last operate.
					ans ^= bit;
				}
				bit >>= 1;
			}
			return ans;
		}
		/*
		int sqrt(int x) {
			if(x == 0 || x == 1)
				return x;
			if(x < 0)
				return -1;

			long min_num = 2;
			long min_length = x / min_num;
			while(1){
				if( min_length < abs(x/(min_num * 2) - (min_num * 2))){
					min_num *= 2;
					min_length = abs(x/min_num - min_num);	
				}else{
					break;
				}
			}
			long upper_limit = x/min_num > min_num ? x/min_num : min_num;
			long lower_limit = x/min_num < min_num ? x/min_num : min_num;
			for(int i = lower_limit; i <= upper_limit; ++i)
			{
				if(i * i > x){
					if(i * i - x > x - (i-1) * (i-1))
						return i-1;
					else
						return i;
				}	
			}
		}
		*/
};

int main()
{
	Solution sol;
	cout << sol.sqrt(2147483647) << endl;
	cout << sol.sqrt(1) << endl;
//	cout << sol.sqrt(10000) << endl;
//	cout << sol.sqrt(1) << endl;
	cout << "int: " << sizeof(int)*8 << "bits" << ", long: " << sizeof(long)*8 << "bits" << ", char:" << sizeof(char)*8 << "bits" << endl;
	cout << "unsigned long: " << sizeof(unsigned long)*8 << "bits" << ", long long: " << sizeof(long long)*8 << "bits" << ", unsigned:" << sizeof(unsigned)*8 << "bits" << endl;
	return 0;
}
