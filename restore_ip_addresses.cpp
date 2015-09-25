#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
class Solution {
		map<int, vector<string>> result_dict;
	public:
		bool isBigger255(string str){
			if(str.size() > 3 || str.size() == 0){
				return false;
			}else if(str.size() < 3){
				return true;
			}else{
				if(str[0] == '1' || str[0] == '0'){
					return true;
				}else if(str[0] == '2' && str[1] <= '4' && str[1] >= '0'){
					return true;
				}else if(str[0] == '2' && str[1] == '5' && str[2] >= '0' && str[2] == '5'){
					return true;
				}else{
					return false;
				}
			}
		}
		vector<string> restoreIpAddresses(string s) {
			vector<string> result;
			if(s.size() < 4){
				return result;
			}
			result = restoreResult(s, 0, 3);
			for(auto i = result_dict.begin(); i != result_dict.end(); ++i){
				for(int j = 0; j < (*i).second.size(); ++j){
					cout << (*i).second[j] << endl;
				}
			}
			return result;
		}
		
		vector<string> restoreResult(string s, int begin, int cuts){
			vector<string> result;
			if(cuts == 0){
				if(result_dict.find(begin) == result_dict.end()){
					result.push_back(s.substr(begin));
					result_dict[begin] = result;
				}else{
					result = result_dict[begin];
				}
				return result;
			}
			if(result_dict.find(begin) != result_dict.end()){
				return result_dict[begin];
			}
			for(int i = begin+1; i < (begin + 4 > s.size() ? s.size() : begin + 4); ++i){
				if(!isBigger255(s.substr(begin,i-begin)) || s.size()-i > 3*cuts ){
			//		cout << s.substr(begin, i-begin) << " "<< s.substr(i) << " " <<  begin << " " << cuts <<  endl;
					continue;
				}
			//	cout << "$$$$$" << s.substr(begin, i-begin) << " "<< s.substr(i) << " " <<  begin << " " << cuts <<  endl;
				vector<string> tmp;
				if(result_dict.find(i) != result_dict.end()){
					tmp = result_dict[i];
				}else{
					tmp = restoreResult(s, i, cuts-1);
				}
				if(tmp.size() == 0){
					continue;
				}
				for(int j = 0; j < tmp.size(); ++j){
					string ss = s.substr(begin, i-begin) + ".";
					ss = ss + tmp[j];
					result.push_back(ss);
				}
			}
			if(result_dict.find(begin) == result_dict.end()){
				result_dict[begin] = result;
			}
			return result;
		}


		bool isAvailable(string &str_s, vector<int> &cols, int row){
			string str = "";
			if(row == 0){
				return  str_s.size()-cols[row]+1 <= 12 && isBigger255(str_s.substr(0, cols[row]));
			}else if(row == 1){
				return str_s.size()-cols[row]+1 <= 9 && isBigger255(str_s.substr(cols[row-1], cols[row])) ;
			}else if(row == 2){
				return str_s.size()-cols[row]+1 <= 6 && isBigger255(str_s.substr(cols[row-1], cols[row])) ;
			}else{
				return str_s.size()-cols[row]+1 <= 3 && isBigger255(str_s.substr(cols[row-1], cols[row])) &&  isBigger255(str_s.substr(cols[row], str_s.size())) ;
			}
		}
		vector<string> restoreIpAddresses2(string s) {
			vector<string> result;
			vector<int> cols(3,0);
			int row = 0;
			while(row >= 0){
				cout << cols[0] << " " << cols[1] << " " << cols[2] << endl;
				if(row == 4){
					string temp = "";
					int begin = 0;
					for(int i = 0; i < 3; ++i){
						temp = temp + s.substr(begin, cols[i]);
						temp = temp + ".";
						begin = cols[i];	
					}
					temp = temp + s.substr(begin, s.size());
					result.push_back(temp);
					row--;
					cols[row]++;
				}else if(isAvailable(s, cols, row)){
					cols[row+1] = cols[row];
					row++;
					cols[row]++;
				}else{
					cout << "!!" << " " << row << " " << s.size() << endl;
					cols[row]++;
					if(cols[row] == s.size() || (row == 0 && cols[row] > 2) || (cols[row]-cols[row-1]+1 > 3) || (row == 3 && s.size()-cols[row]+1 > 3)){
						row--;
						if(row == -1)
							break;
						cols[row]++;
					}
				}
			}
			return result;
		}
};

int main()
{
	Solution sol;
//	string s = "25525511135";
	string s = "2535";
//	cout <<sol.isBigger255("265") << endl;
//	cout <<sol.isBigger255("125") << endl;
//	cout <<sol.isBigger255("1205") << endl;
	vector<string> result = sol.restoreIpAddresses(s);
	cout << "***************************" << endl;
	for(int i = 0; i < result.size(); ++i){
		cout << result[i] << endl;
	}
	return 0;
}
