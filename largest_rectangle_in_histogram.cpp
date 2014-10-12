#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class Solution {
	public:
		int largestRectangleArea(vector<int> &height) {
			// Create an empty stack. The stack holds indexes of height[] array
			// The bars stored in stack are always in increasing order of their
			// heights.
			stack<int> s;

			int max_area = 0; // Initalize max area
			int tp;  // To store top of stack
			int area_with_top; // To store area with top bar as the smallest bar

			// Run through all bars of given heightogram
			int i = 0;
			while (i < height.size())
			{
				// If this bar is higher than the bar on top stack, push it to stack
				if (s.empty() || height[s.top()] <= height[i])
					s.push(i++);

				// If this bar is lower than top of stack, then calculate area of rectangle 
				// with stack top as the smallest (or minimum height) bar. 'i' is 
				// 'right index' for the top and element before top in stack is 'left index'
				else
				{
					tp = s.top();  // store the top index
					s.pop();  // pop the top

					// Calculate the area with height[tp] stack as smallest bar
					area_with_top = height[tp] * (s.empty() ? i : i - s.top() - 1);

					// update max area, if needed
					if (max_area < area_with_top)
						max_area = area_with_top;
				}
			}

			// Now pop the remaining bars from stack and calculate area with every
			// popped bar as the smallest bar
			while (s.empty() == false)
			{
				tp = s.top();
				s.pop();
				area_with_top = height[tp] * (s.empty() ? i : i - s.top() - 1);

				if (max_area < area_with_top)
					max_area = area_with_top;
			}

			return max_area;
		}
    /*
                int largestRectangleArea(vector<int> &height) {
                        if(height.size() == 0)
                                return 0;
                        if(height.size() == 1)
                                return height[0];
                        int max_num = height[0];
                        int largestRect = 0;
                        for(int begin_index = 0; begin_index < height.size(); ++begin_index)
                        {
                                int min_height = height[begin_index];
                                for(int i = begin_index + 1; i < height.size(); ++i){
                                        if(min_height > height[i]){
                                                int temp_height = min_height * (i - begin_index);
                                                if(temp_height > height[i] * (i - begin_index + 1)){
                                                        if(temp_height > largestRect)
                                                                largestRect = temp_height;
                                                        break;
                                                }else{
                                                        min_height = height[i];
                                                }
                                        }
                                }
                        }
                        if(largestRect < height[height.size()-1])
                                return height[height.size()-1];
                        return largestRect;

                }
	*/
};

int main()
{
	vector<int> height = {6, 2, 5, 4, 5, 1, 6};
	Solution sol;
	cout << "Maximum area is " << sol.largestRectangleArea(height);
	return 0;
}
