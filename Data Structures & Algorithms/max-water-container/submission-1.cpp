class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0 ;
        int j = heights.size()-1;
        int max=0;
        while(i<j){
            int temp = (j-i)*std::min(heights[i],heights[j]);
            if(heights[i]<heights[j]){
                i++;
            }
            else {
                j--;
            }
            max = std::max(max,temp);
        }
        return max;
    }
};
