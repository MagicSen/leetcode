#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
	public:
		char plusThree(char a, char b, char &flag){
			if(a == '1' && b == '1' && flag == '1'){
				flag = '1';
				return '1';
			}else if((a == '1' && b == '1' && flag == '0') || (a == '1' && b == '0' && flag == '1') || (a == '0' && b == '1' && flag == '1')){
				flag = '1';
				return '0';
			}else if(a == '0' && b == '0' && flag == '0'){
				flag = '0';
				return '0';
			}else{
				flag = '0';
				return '1';
			}
		}
		string addBinary(string a, string b) {
			if(a.size() < b.size()){
				string temp = a;
				a = b;
				b = temp;
			}
			string result;
			char flag = '0';
			for(int i = a.size() - 1; i >= 0; --i){
				if(a.size()-i > b.size()){
					result.insert(result.end(), plusThree(a[i],'0',flag));
				}else{
					result.insert(result.end(), plusThree(a[i],b[i-(a.size()-b.size())],flag));
				}
			}
			if(flag == '1'){
				result.insert(result.end(), flag);
			}
			reverse(result.begin(), result.end());
			return result;
			/*
			long long a_i=0;
			long long b_i=0;
			for(int i = 0; i < a.size(); ++i){
				if(a[i] == '1'){
					a_i += 1 << (a.size() - i - 1);
				}
			}
			for(int i = 0; i < b.size(); ++i){
				if(b[i] == '1'){
					b_i += 1 << (b.size() - i - 1);
				}
			}
			long long result = a_i + b_i;
			if(result == 0){
				return "0";
			}
			string result_str = "";
			while(result != 0){
				result_str.insert(result_str.begin(), result%2 + '0');
				result /= 2;
			}
			return result_str;
			*/
		}
};


int main()
{
	Solution sol;
	string s1 = "111";
	string s2 = "1";
	cout << sol.addBinary(s1, s2) << endl;
	return 0;
}
