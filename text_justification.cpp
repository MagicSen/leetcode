#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
	public:
		vector<string> fullJustify(vector<string> &words, int L) {
			vector<string> result;        
			if(words.size() == 0)
				return result;
			string blank_sample;
			for(int i = 0; i < L; ++i)
				blank_sample.append(" ");

			int text_length = 0;
			vector<string> temp_text;
			int blanks_step = 1;
			for(int i = 0; i < words.size(); ++i)
			{
				if(temp_text.size() == 0){
					temp_text.push_back(words[i]);
					text_length = words[i].size();
					continue;
				}
				if(text_length + temp_text.size()*blanks_step + words[i].size() <= L){
					temp_text.push_back(words[i]);
					text_length += words[i].size();
				}else{
					string str = "";	
					if(temp_text.size() == 1){
						str = temp_text[0];	
					}else{
						blanks_step = (L - text_length) / (temp_text.size()-1);

						for(int j = 0; j < temp_text.size() - 1; ++j)
						{
							str.append(temp_text[j]);	
							if((L-text_length) % (temp_text.size()-1) != 0 && j < (L-text_length) % (temp_text.size()-1))
								str.append(blank_sample, 0, blanks_step + 1);
							else
								str.append(blank_sample, 0, blanks_step);
						}
						str.append(temp_text[temp_text.size()-1]);	
					}
					if(str.size() < L){
						str.append(blank_sample, 0, L-str.size());
					}
					result.push_back(str);
					temp_text.clear();
					text_length = 0;
					blanks_step = 1;
					temp_text.push_back(words[i]);
					text_length = words[i].size();
				}

			}
			if(temp_text.size() != 0){
				string str = "";	
				if(temp_text.size() == 1){
					str = temp_text[0];	
				}else{
				//	blanks_step = (L - text_length) / (temp_text.size()-1);
					blanks_step = 1;
					for(int j = 0; j < temp_text.size() - 1; ++j)
					{
						str.append(temp_text[j]);	
						str.append(blank_sample, 0, blanks_step);
					}
					str.append(temp_text[temp_text.size()-1]);	
				}
				if(str.size() < L){
					str.append(blank_sample, 0, L-str.size());
				}
				result.push_back(str);
			}
			return result;
		}
};

int main()
{
	/*	string str1 = "1234";
		cout << str1 << endl;
		string blank_sample;
		for(int i = 0; i < 5; ++i)
		blank_sample.append(" ");
		str1.append(blank_sample, 0, blank_sample.size());
		cout << str1 << "s " <<  blank_sample.size() << endl;
		*/
//	vector<string> test = {"This", "is", "an", "example", "off", "a", "text", "justification."};
//	vector<string> test = {"What","must","be","shall","be."};
	vector<string> test = {"Don't","go","around","saying","the","world","owes","you","a","living;","the","world","owes","you","nothing;","it","was","here","first."};
	Solution sol;
	vector<string> result = sol.fullJustify(test, 30);
	cout << result.size() << endl;
	for(int i = 0; i < result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
