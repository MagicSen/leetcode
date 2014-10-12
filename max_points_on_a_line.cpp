#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


struct Point {
     	int x;
	int y;
 	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
 
class Solution {
public:
	const int max_iteration = 20;
	// y = ax + b
	void get_a_b(const Point &p1, const Point &p2, double &a, double &b){
		if(p1.x == p2.x)
		{
			a = 1000000;	
			b = p1.x;
			return;
		}
		a = ((double)(p1.y - p2.y))/(p1.x - p2.x);
		b = ((double)(p1.x*p2.y -p2.x*p1.y))/(p1.x-p2.x);
	}
	bool is_in_line(const Point p, const double &a, const double &b){
		// Vertical line
		if(a == 1000000 && p.x == b)
			return true;
		if(abs(p.y - (a * p.x + b)) < 1e-1)
			return true;
		else
			return false;
	}
	int maxPoints(vector<Point> &points) {
		if(points.size() == 2)
			return 2;
		else if(points.size() == 1)
			return 1;
		else if(points.size() == 0)
			return 0;
		else{
			int max_points = 2;

			for(int i = 0; i < points.size()-1; ++i)	
			{
				int index_1 = i;
				int index_2 = (i+2)%points.size();
				double a = 0;
				double b = 0;
				get_a_b(points[index_1], points[index_2], a, b);
				int inner_points = 0;
				for(auto j : points)
				{
					if(is_in_line(j, a, b))	
						inner_points++;
				}
				if(inner_points > max_points)
					max_points = inner_points;	
			}
			return max_points;
		}
	}
};

int main()
{
	Solution sol;
	vector<Point> points{Point(4,0),Point(4,-1),Point(4,5)};
	cout << sol.maxPoints(points) << endl;
	return 0;
}
