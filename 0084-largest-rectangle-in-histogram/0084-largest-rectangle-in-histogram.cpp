#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> st; // Stores indices
        int max_area = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i) {
            // Append a height 0 bar at index n to pop all remaining bars
            int current_height = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > current_height) {
                int h = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : (i - st.top() - 1);
                max_area = std::max(max_area, h * width);
            }
            st.push(i);
        }

        return max_area;
    }
};