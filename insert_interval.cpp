#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
	public:
		vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
			vector<Interval> result;
			if(intervals.size() == 0){
				result.push_back(newInterval);
				return result;
			}
			bool fig = false;	
			int i = 0;
			for(; i < intervals.size(); ++i)
			{
				if(newInterval.end < intervals[i].start){
					result.push_back(newInterval);
					fig = true;
					break;
				}else if(newInterval.start > intervals[i].end){
					result.push_back(intervals[i]);
				}else if(newInterval.start < intervals[i].start && (newInterval.end >= intervals[i].start && newInterval.end < intervals[i].end)){
					newInterval.end = intervals[i].end;
				}else if(newInterval.start >= intervals[i].start && newInterval.end <= intervals[i].end){
					fig = true;
					break;
				}else if(newInterval.start > intervals[i].start && newInterval.start <= intervals[i].end && newInterval.end > intervals[i].end ){
					newInterval.start = intervals[i].start;
				}
			}
			if(!fig)	
				result.push_back(newInterval);
			for(; i < intervals.size(); ++i){
				result.push_back(intervals[i]);
			}
			return result;
		}
};

int main()
{
	vector<Interval> test;
	Interval temp1(1,5);
	Interval temp2(6,8);
	test.push_back(temp1);
//	test.push_back(temp2);
	Solution sol;
	Interval newInterval(0,0);
	vector<Interval> result = sol.insert(test, newInterval); 
	for(int i = 0; i < result.size(); ++i)
	{
		cout << result[i].start << " " << result[i].end << endl;	
	}
	return 0;
}
