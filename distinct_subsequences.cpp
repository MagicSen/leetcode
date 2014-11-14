#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;
class Solution {
	map<pair<string, string>, int> dict;
public:
	int numDistinct(string S, string T) {
		if(S.size() < T.size()){
			return 0;
		}
		
	//	int F[T.size()][S.size()];
		vector<vector<int>> F(T.size(), vector<int>(S.size(), 0));
		
		for(int i = T.size()-1; i >= 0; --i){	
				string T_sub = T.substr(i);
			for(int j = S.size()-1; j >= 0; --j){
				string S_sub = S.substr(j);
				if(T_sub.size() == 1){
					if(S_sub.size() == 1){
						if(S_sub[0] == T_sub[0])
							F[0][0] = 1;
						else
							F[0][0] = 0;
					}else{
						if(S_sub[0] == T_sub[0])
							F[0][S.size()-j-1] = F[T.size()-i-1][S.size()-j-2] + 1;
						else
							F[0][S.size()-j-1] = F[T.size()-i-1][S.size()-j-2];
					}
				}else{
					if(S_sub.size() < T_sub.size())
						F[T.size()-i-1][S.size()-j-1] = 0;
					else{
						if(S_sub[0] == T_sub[0]){
							F[T.size()-i-1][S.size()-j-1] = F[T.size()-i-1][S.size()-j-2] + F[T.size()-i-2][S.size()-j-2];
						}else{
							F[T.size()-i-1][S.size()-j-1] = F[T.size()-i-1][S.size()-j-2];
						}
					}
				}
			}
		}
		return F[T.size()-1][S.size()-1];
	}
	// Time limit
	/*	int numDistinct(string S, string T) {
		if(S.size() < T.size()){
		return 0;
		}
		if(S.size() == 1){
		if(S[0] == T[0])
		return 1;
		else
		return 0;
		}

		if(S[0] == T[0]){
		return numDistinct(S.substr(1), T.substr(1)) + numDistinct(S.substr(1), T);
		}else{
		string S_n1 = S.substr(1);
		return  numDistinct(S_n1, T);
		}
		}
		*/
	// Memory Limit Exceeded.
	/*	int numDistinct(string S, string T) {
		if(S.size() < T.size()){
		return 0;
		}
		if(S.size() == 1){
		if(S[0] == T[0])
		return 1;
		else
		return 0;
		}

		if(S[0] == T[0]){
		string S_n1 = S.substr(1);
		string T_n1 = T.substr(1);
		int f_s_n1_t_n1 = 0;
		int f_s_n1_t_n = 0;
		if(dict.find(pair<string, string>(S_n1, T_n1)) == dict.end()){
		dict[pair<string, string>(S_n1, T_n1)] = numDistinct(S_n1, T_n1);
		}
		f_s_n1_t_n1 = dict[pair<string, string>(S_n1, T_n1)];
		if(dict.find(pair<string, string>(S_n1, T)) == dict.end()){
		dict[pair<string, string>(S_n1, T)] = numDistinct(S_n1, T);
		}
		f_s_n1_t_n = dict[pair<string, string>(S_n1, T)];
		return f_s_n1_t_n1 + f_s_n1_t_n;	
		}else{
		string S_n1 = S.substr(1);
		if(dict.find(pair<string, string>(S_n1, T)) == dict.end()){
		dict[pair<string, string>(S_n1, T)] = numDistinct(S_n1, T);
		}
		return dict[pair<string, string>(S_n1, T)];
		}
		}
		*/
};
int main()
{
	Solution sol;
//	string S("rabbbbit");
//	string T("rabbit");
	string S("ccc");
	string T("c");
	cout << sol.numDistinct(S, T) << endl;
	return 0;
}
