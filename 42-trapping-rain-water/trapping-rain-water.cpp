class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> maxl(n);
        vector<int> maxr(n);

        int max = 0;
        for (int i = 0; i < n; i++) {
            max = std::max(max, height[i]);
            maxl[i] = max;
        }
        max=0;
          for (int i = n-1; i >= 0; i--) {
            max = std::max(max, height[i]);
            maxr[i] = max;
        }

        int res = 0;
        for (int i = 0; i < height.size(); i++) {
           int w= std::min(maxl[i],maxr[i])-height[i];
           res+=w; 
        }
        return res;
    }
};