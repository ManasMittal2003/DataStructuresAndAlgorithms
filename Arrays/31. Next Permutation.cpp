class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                idx=i-1;
                break;
            }
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            int maxi=idx+1;
            for(int i=idx+2;i<nums.size();i++){
                if(nums[i]>nums[idx]&&nums[i]<=nums[maxi]){
                    maxi=i;
                }
            }
            swap(nums[idx],nums[maxi]);
            sort(nums.begin()+idx+1,nums.end());
        }
        /*
        Here we tried to maintain a longer prefix match from the
        starting of the number thats why we tried to find the breaking from 
        behined. 
        */
    }
};
