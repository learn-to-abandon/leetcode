//最简单的遍历
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> re;
        if (s.size()==0 || words.size()==0) return re;
        int slen=words.at(0).size();

        int len1=s.size();
        int len2=words.size()*slen;
        if(len1<len2) return re;
        vector<string> vs;
        //排序
        sort(words.begin(),words.end());

        for (int i=0; i<=len1-len2; i++) {
               for(int j=0; j<words.size(); j++)
                     vs.push_back(s.substr(i+slen*j,slen));
               //排序
               sort(vs.begin(),vs.end());
               if (words==vs) re.push_back(i);
               vs.clear();
        }
        return re;
    }
};
