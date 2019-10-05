class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len = intervals.size();
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(int i=1;i<=len;++i){
            if(res.back()[1]>=intervals[i][0])
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};
