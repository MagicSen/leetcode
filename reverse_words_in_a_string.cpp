#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>

using namespace std;

class Solution{
public:
	void reverseWords(string &s){
		vector<string> 	word;
		string::size_type pos = 0;
		// Delete the last blank(  "  a   " --> "  a")
		while((pos = s.find_last_of(" ")) != string::npos && pos == s.size()-1)
		{
			s.erase(s.begin()+s.size()-1, s.end());	
		}
		// Split the sentence to the single word, and delete the front blank.
		while((pos = s.find_first_of(" ")) != string::npos)
		{
			if(pos == 0){
				s.erase(s.begin(), s.begin()+1);
				continue;
			}
			word.push_back(s.substr(0,pos));	
			s.erase(s.begin(),s.begin() + pos + 1);
		}
		// Recombination all word
		for(int i = word.size()-1; i >= 0; --i)
		{
			s.append(" " + word[i]);
		}
	}
};

int main()
{
	string words;
	Solution solu;
	cout << "Please give me a sentence to reverse: " << endl;
	while(getline(cin, words))
	{
		solu.reverseWords(words);
		cout << words << endl;
	}
	return 0;
}
