#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
	public:
		int partition(vector<int> &numbers, int lo, int hi)
		{
			int i = lo;
			int j = hi + 1;
			while(1){
				while(numbers[lo] <= numbers[--j])
					if( j == lo)
						break;
				while(numbers[lo] > numbers[++i])
					if(i == hi)
						break;
				if(i >= j)
					break;
				swap(*(numbers.begin() + i), *(numbers.begin() + j));
			}
			swap(*(numbers.begin() + lo), *(numbers.begin() + j));
			return j;
		}
		void quick_sort(vector<int> &numbers, int lo, int hi)
		{
			if(hi <= lo)
				return;
			int j = partition(numbers, lo, hi);	
			quick_sort(numbers, lo, j-1);
			quick_sort(numbers, j+1, hi);
		}
		// Time too long
		vector<int> twoSum(vector<int> &numbers, int target) {
			vector<int> result;
			if(numbers.size() == 0)
				return result;
			vector<int> sorted_numbers(numbers.begin(), numbers.end());
			quick_sort(sorted_numbers, 0, sorted_numbers.size()-1);	
			show(numbers);
			show(sorted_numbers);
			int i = 0;
			int j = sorted_numbers.size()-1;
			while(i <= j)
			{
				if(sorted_numbers[i] + sorted_numbers[j] > target){
					--j;
				}else if(sorted_numbers[i] + sorted_numbers[j] < target){
					++i;
				}else{
					int m = -1, n = -1;
					for(int k = 0; k < numbers.size(); ++k)
						if(m == -1 && numbers[k] == sorted_numbers[i]){
							m = k + 1;
						}else if(n == -1 && numbers[k] == sorted_numbers[j]){
							n = k + 1;
						}else{
							if(m != -1 && n != -1)
								break;
						}
					result.push_back(m < n ? m : n);	
					result.push_back(n > m ? n : m);	
					break;
				}
			}
			return result;
		}
		void show(vector<int> numbers){
			for(int i = 0; i < numbers.size(); ++i)
				cout << numbers[i] << " ";
			cout << endl;
		}

};
int main()
{
	vector<int> temp={0, 4, 3, 0};
	Solution sol;
	vector<int> result = sol.twoSum(temp, 0);
	for(int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;	
	}
	return 0;
}
