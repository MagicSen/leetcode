#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int minThree(const int &a, const int &b, const int &c){
			int temp = (a > b ? b : a);
			return temp > c ? c : temp;
	}
	int minDistance(string word1, string word2) {
			if(word1.size() == 0)
					return word2.size();
			if(word2.size() == 0)
					return word1.size();

			vector<vector<int>> dict(word2.size(), vector<int>(word1.size(), 0));
			if(word1[0] != word2[0])
					dict[0][0] = 1;
			// First rows
			for(int i = 1; i < word1.size(); ++i)
			{
				if(word1[i] == word2[0] || dict[0][i-1] == i-1){
					dict[0][i] = i; 
				}else{
					dict[0][i] = i + 1;
				}
			}
			// First column
			for(int j = 1; j < word2.size(); ++j)
			{
				if(word1[0] == word2[j] || dict[j-1][0] == j-1){
					dict[j][0] = j;
				}else{
					dict[j][0] = j + 1;
				}
			}
			// update the black
			for(int i = 1; i < word1.size(); ++i)
					for(int j = 1; j < word2.size(); ++j){
						if(word1[i] == word2[j]){
								dict[j][i] = dict[j-1][i-1];
						}else{
								dict[j][i] = minThree(dict[j-1][i-1], dict[j-1][i], dict[j][i-1]) + 1;
						}
					}
			return dict[word2.size()-1][word1.size()-1];
	}
};

int main()
{
	Solution sol;
	cout << sol.minDistance("abc", "c") << endl;
	return 0;
}
