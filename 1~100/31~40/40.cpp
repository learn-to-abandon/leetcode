class Solution {
private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    //深度优先回溯，从第start个数开始寻找和为target的数组
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start;
             i < candidates.size() && target - candidates[i] >= 0; i++) {
                 //去除前后一样的数导致的重复情况
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            path.push_back(candidates[i]);
            //不能选择同一个数字
            DFS(i+1, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);

        return res;
    }

};
