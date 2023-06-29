#include <stack>
int largestRectangle(vector < int > & heights) {
  // Write your code here.
  stack<int> st;
  int ans = 0;
  heights.push_back(-1);
  st.push(-1);
  for(int i = 0; i < heights.size(); i++)
  {
    while(st.size() > 1 && heights[st.top()] > heights[i])
    {
      int height = heights[st.top()];
      st.pop();
      int width = i - st.top() - 1;
      ans = max(ans, height * width);
    }
    st.push(i);
  }
  return ans;
}