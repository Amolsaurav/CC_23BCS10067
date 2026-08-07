class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        while(n>1){
            vector<int>temp(n-1);
            for(int i=0;i<nums.size()-1;i++){
                temp[i]=(nums[i]+nums[i+1])%10;
            }
            nums=temp;
        }
        return nums[0];
    }
};
