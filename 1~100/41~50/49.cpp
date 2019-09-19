/*class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
              int len = strs.size();
              vector<vector<string>> ans;
              vector<string> t;
              if (len==0) return ans;
              int s = 0;
              for (int i = 0; i<len; ++i) {
                    if (ans.empty()) {

                         string tem = strs[0];
                         vector<string> q;
                         q.push_back(tem);
                         ans.push_back(q);
                         sort(strs[0].begin(),strs[0].end());
                         t.push_back(strs[0]);
                         ++s;

                    }
                  else {
                    bool f = 0;
                    string tem = strs[i];
                    sort(strs[i].begin(),strs[i].end());
                    for (int j = 0; j < s; ++j) {
                           if (t[j]==strs[i]) {
                               ans[j].push_back(tem);
                               f=1;
                               break;
                           }
                    }
                    if (!f) {
                        vector<string> q;
                        q.push_back(tem);
                        t.push_back(strs[i]);
                        ans.push_back(q);
                        ++s;
                    }
                  }
              }
              return ans;
    }
};*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        for(auto s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            hashmap[temp].push_back(s);
        }
        int len = hashmap.size();
        vector<vector<string>> ans(len);
        int index = 0;
        for(auto i : hashmap){
            ans[index] = i.second;
            ++ index;
        }
        return ans;
    }
};
