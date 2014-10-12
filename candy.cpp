#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <string>

using namespace std;

class Solution {
	public:
		// Time out
		int candy(vector<int> &ratings) {
			int min_candy = 0;

			if(ratings.size() == 0)
				return min_candy;
			if(ratings.size() == 1)
				return 1;

			vector<int> each_candys;
			for(int i = 0; i < ratings.size(); ++i)
				each_candys.push_back(0);
			
			int current_candy = 1;

			for(int i = 0; i < ratings.size(); ++i)
			{
				// positive traverse, if equal then copy, else if bigger then reverse add, else just add.
				if(ratings[i] == ratings[i+1]){
					each_candys[i] = current_candy;
				}else if(ratings[i] > ratings[i+1]){
					if(current_candy == 1){
						each_candys[i] = 2;
						for(int j = i-1; j >= 0; --j)
						{
							if(ratings[j] > ratings[j+1]){
								each_candys[j]++;
							}else if(ratings[j] == ratings[j+1])
								each_candys[j] = each_candys[j+1];
							else
								break;
						}

					}else{
						each_candys[i] = current_candy;
					}
					current_candy = 1;
				}else{
					each_candys[i] = current_candy;
					current_candy++;
				}
			}
			
			// get the total candys
			for(int i = 0; i < ratings.size(); ++i)
				min_candy += each_candys[i];
			return min_candy;
		}
		/*
		// Times out
		void get_candys(vector<int> &ratings, vector<int> &each_candys, int lo, int hi)
		{
			if(lo > hi)	
				return;
			int min_index = find_min_index(ratings, lo, hi);
			if(min_index == 0){
				if(ratings[min_index] != ratings[1]){
					if(each_candys[1] == 0)	
						each_candys[min_index] = 1;
					else{
						each_candys[min_index] = each_candys[1] + 1;
					}
				}else{
					if(each_candys[1] != 0)
						each_candys[min_index] = each_candys[1];
					else
						each_candys[min_index] = 1;
				}
				get_candys(ratings,each_candys, min_index+1, hi);
			}else if(min_index == ratings.size()-1){
				if(ratings[min_index] != ratings[ratings.size()-2]){
					if(each_candys[ratings.size()-2] == 0)
						each_candys[min_index] = 1;
					else{
						each_candys[min_index] = each_candys[ratings.size()-2] + 1;
					}
				}else{
					if(each_candys[ratings.size()-2] == 0)
						each_candys[min_index] = 1;
					else{
						each_candys[min_index] = each_candys[ratings.size()-2];
					}
				}
				get_candys(ratings,each_candys, lo, min_index-1);	
			}else{
				if(each_candys[min_index-1]==0 && each_candys[min_index+1] == 0){
					each_candys[min_index] = 1;
				}else if(each_candys[min_index-1]!=0 && each_candys[min_index+1] == 0){
					if(ratings[min_index] == ratings[min_index-1])
						each_candys[min_index] = each_candys[min_index-1];
					else
						each_candys[min_index] = each_candys[min_index-1] + 1;
				}else if(each_candys[min_index-1]==0 && each_candys[min_index+1] != 0){
					if(ratings[min_index] == ratings[min_index+1])
						each_candys[min_index] = each_candys[min_index+1];
					else
						each_candys[min_index] = each_candys[min_index+1] + 1;
				}else{
					int max_candys = ((each_candys[min_index-1] > each_candys[min_index+1]) ? each_candys[min_index-1] : each_candys[min_index+1]);
					if(ratings[min_index] == ratings[min_index-1] || ratings[min_index] == ratings[min_index+1]){
						if(ratings[min_index] == ratings[min_index-1] && ratings[min_index] == ratings[min_index+1]){
							each_candys[min_index+1] = max_candys;
							each_candys[min_index] = max_candys;
							each_candys[min_index-1] = max_candys;
						}else if(ratings[min_index] == ratings[min_index-1] && each_candys[min_index-1] <= each_candys[min_index+1]){
							each_candys[min_index-1] = max_candys + 1;
							each_candys[min_index] = max_candys + 1;
						}else if(ratings[min_index] == ratings[min_index+1] && each_candys[min_index-1] >= each_candys[min_index+1]){
							each_candys[min_index+1] = max_candys + 1;
							each_candys[min_index] = max_candys + 1;
						}else{
							each_candys[min_index] = max_candys;
						}
					}else{
						each_candys[min_index] = max_candys + 1;
					}
				}
				get_candys(ratings,each_candys, lo, min_index-1);	
				get_candys(ratings,each_candys, min_index+1, hi);
			}

		}

		int find_min_index(vector<int> &ratings, int lo, int hi)
		{
			if(lo == hi){
				return lo;
			}
			int min_index = lo;	
			int min_rates = ratings[lo];
			for(int i = lo+1; i <= hi; ++i)
			{
				if(ratings[i] < min_rates){
					min_rates = ratings[i];
					min_index = i;
				}
			}
			return min_index;
		}
		int candy(vector<int> &ratings) {
			int min_candy = 0;

			if(ratings.size() == 0)
				return min_candy;
			if(ratings.size() == 1)
				return 1;

			vector<int> each_candys;
			for(int i = 0; i < ratings.size(); ++i)
				each_candys.push_back(0);

			get_candys(ratings,each_candys, 0, ratings.size()-1);	

			for(int i = 0; i < ratings.size(); ++i)
				min_candy += each_candys[i];
			return min_candy;
		}
		*/
		/*
		// Wrong idea
		private:
		int min_candy;
		public:
		int candy(vector<int> &ratings) {
		if(ratings.size() == 1)
		return 1;
		vector<int> temp(ratings.begin(), ratings.end());
		min_candy = 0;	
		for(int sz = 1; sz < ratings.size(); sz = sz + sz )
		{
		for(int lo = 0; lo < ratings.size()-sz ; lo = lo + sz + sz)
		{
		int hi = (ratings.size()-1 < lo + sz + sz-1) ? ratings.size()-1 : lo + sz + sz -1;	
		for(int i = lo; i <= hi; ++i)
		temp[i] = ratings[i];
		int i = lo;
		int mid = lo + sz -1;
		if(temp[mid] < temp[mid+1]){
		continue;
		}
		int j = mid+1;
		int k = lo;
		bool fig_bigger = false;
		while(k <= hi)
		{
		if( i > mid)	
		ratings[k++] = temp[j++];
		else if(j > hi){
		ratings[k++] = temp[i++];
		if(!fig_bigger)
		fig_bigger = true;
		else
		min_candy = min_candy + hi - mid;
		}else if(temp[i] > temp[j]){
		ratings[k++] = temp[j++];
		min_candy++;
		}else{
		ratings[k++] = temp[i++];
		}
		}
		}
		}
		min_candy = min_candy + ratings.size();
		return min_candy;
		}
		*/
};

int show(vector<int> vec)
{
	for(auto i : vec)
		cout << i << " ";
	cout << endl;
}
int main()
{
	vector<int> ratings{1,2,3};
	Solution sol;
	cout << sol.candy(ratings) << endl;
	show(ratings);
	return 0;
}
