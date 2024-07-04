class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        int n = height.size();
        vector<int> lmax(n, INT_MIN);
        vector<int> rmax(n, INT_MIN);
        lmax[0] = height[0];
        rmax[n - 1] = height[n - 1];
        int lmaxele = height[0];
        int rmaxele = height[n - 1];
        for (int i = 1; i < n; i++) {
            lmax[i] = max(height[i], lmaxele);
            lmaxele = max(lmaxele, height[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            rmax[i] = max(height[i], rmaxele);
            rmaxele = max(rmaxele, height[i]);
        }
        int i = 0;
        while (i < n) {
            int store = min(lmax[i], rmax[i]) - height[i];
            total += store;
            i++;
        }
        return total;
    }
};
