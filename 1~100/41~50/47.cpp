//延续上一题的方法
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> set_res;
        backtrack(nums,res,0,set_res);
        return res;
    }
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    void backtrack(vector<int>& nums,vector<vector<int>> &res,int i,set<vector<int>> &set_res){
        if(i==nums.size()&&set_res.find(nums)==set_res.end()){
            res.push_back(nums);
            set_res.insert(nums);
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            backtrack(nums,res,i+1,set_res);
            swap(nums[i],nums[j]);
        }
    }
};
