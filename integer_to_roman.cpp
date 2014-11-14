#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		char dict[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
			      // 1    5    10   50   100  500  1000
		string roman;
		int digital = 1000;
		int i = 6;
		while(digital > 0){
			int temp = num / digital;
			if(temp >=1 && temp <= 3){
				while(temp--)
					roman.push_back(dict[i]);
			}else if(temp == 4){
				roman.push_back(dict[i]);
				roman.push_back(dict[i+1]);
			}else if(temp >=5 && temp <= 8){
				temp = temp-5;
				roman.push_back(dict[i+1]);
				while(temp--)
					roman.push_back(dict[i]);
			}else if(temp == 9){
				roman.push_back(dict[i]);
				roman.push_back(dict[i+2]);
			}
			num = num % digital;
			digital /= 10;
			i -= 2;
		}
		return roman;	
	}
};

int main()
{
	Solution sol;
//	string result = sol.intToRoman(3999);
//	string result = sol.intToRoman(1984);
	string result = sol.intToRoman(4);
	cout << result << endl;
	return 0;
}
