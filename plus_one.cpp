#include <iostream>
#include <vector>

using namespace std;
class Solution {
	public:
		vector<int> plusOne(vector<int>& digits) {
			vector<int> result;
			int flag = 0;
			for(int i = digits.size()-1; i >= 0; --i){
				if(result.size() == 0){
					result.push_back((digits[i] + 1)%10);
					flag = (digits[i] + 1)/10;
				}else{
					result.insert(result.begin(), (digits[i] + flag)%10);
					flag = (digits[i] + flag)/10;
				}
			}
			if(flag != 0){
				result.insert(result.begin(), flag);
			}
			return result;
		}

		void show(vector<int> num){
			for(int i=0; i<num.size(); i++){
				cout << num[i];
			}
			cout << endl;
		}
};

int main(){
	Solution sol;
	vector<int> num={1,9,9,9};	
	sol.show(num);
	num = sol.plusOne(num);
	sol.show(num);
	return 0;
}
