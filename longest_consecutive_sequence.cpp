#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
	public:
	// 60ms
		int longestConsecutive(vector<int> &num) {
			if(num.size() == 0)
				return 0;
			unordered_map<int, int> seq;
			int long_consecutive = 1;
			for(int i = 0; i < num.size(); ++i)
			{
				if(seq.count(num[i])) continue;	
				int low = num[i], upp = num[i];

				if(seq.count(num[i] - 1))
					low = seq[num[i]-1];
				if(seq.count(num[i] + 1))
					upp = seq[num[i]+1];
				long_consecutive = long_consecutive > upp - low + 1 ? long_consecutive : upp - low + 1;
				seq[num[i]] = num[i];
				seq[low] = upp;
				seq[upp] = low;
			}
			return long_consecutive;
		}
	/*
		int longestConsecutive(vector<int> &num) {
			if(num.size() == 0)
				return 0;
			map<int, int> range;
			for(int i = 0; i < num.size(); ++i)
			{
				if(range.count(num[i])) continue;
				range[num[i]] = num[i];

				if(range.count(num[i]-1)){
					range[num[i]] = range[num[i]-1];
					range[range[num[i]]] = num[i];
				}

				if(range.count(num[i]+1)){
					int last = range[num[i]+1];
					range[last] = range[num[i]]; 
					range[range[last]] = last;
				}
			}

			int long_cosecutive = 1;
			for(auto i = range.begin(); i != range.end(); ++i)
				if(i->second - i->first > long_cosecutive)
					long_cosecutive = i->second - i->first + 1;
			return long_cosecutive;
		}
		*/
	/*
	// 1148ms
		int partition(vector<int> &num, int lo, int hi)
		{
			int i = lo;
			int j = hi+1;
			while(1){
				while(num[lo] < num[--j])
					if(j == lo)
						break;
				while(num[lo] > num[++i])
					if(i == hi)
						break;
				if(j <= i)
					break;
				swap(*(num.begin() + i), *(num.begin() + j));
			}
			swap(*(num.begin() + j), *(num.begin() + lo));
			return j;
		}
		void quick_sort(vector<int> &num, int lo, int hi)
		{
			if(lo >= hi)	
				return;
			int j = partition(num, lo, hi);
			quick_sort(num, lo, j-1);
			quick_sort(num, j+1, hi);
		}
		int longestConsecutive(vector<int> &num) {
			if(num.size() == 0)
				return 0;
			else if(num.size() == 1)
				return 1;
			else{
				show(num);
			//	sort(num, 0, num.size()-1);
				sort(num.begin(), num.end());
				show(num);
				int max_consecutive = 1;
				int total = 1;
				for(int i = 1; i < num.size(); ++i)
				{
					if(num[i] == num[i-1] + 1){
						++total;	
					}else if(num[i] == num[i-1])
						continue;
					else{
						if(total > max_consecutive)
							max_consecutive = total;
						total = 1;
					}
				}
				return max_consecutive > total ? max_consecutive : total;
			}
		}
		void show(vector<int> &num)
		{
			for(int i = 0; i < num.size(); ++i)	
				cout << num[i] << " ";
			cout << endl;
		}
*/
};

int main()
{
//	vector<int> temp = {0,1,4,5,0,12,11,10,9,6,3,2,0};
	vector<int> temp = {1,2,0,1};
	Solution sol;
	cout << sol.longestConsecutive(temp) << endl;
	return 0;
}
