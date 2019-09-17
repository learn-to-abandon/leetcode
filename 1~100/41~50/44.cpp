/*class Solution {
public:
    //ȥ�������"*"��Ϊ"*"��"**"��һ����
    string remove(string p){
        string t;
        for(int i=0;i<p.size();++i){
            if(p[i] != '*'){
                t += p[i];
            }else{
                if(t.empty() || t.back() != '*') t += p[i];
            }
        }
        return t;
    }

    bool is(string s, string p) {
         if (p.size()==0) return !s.size();
         if (s.size()==0) {
             if (p[0]=='*') return is(s,p.substr(1,p.size()-1));
             else return false;
         }

         if (p[0]==s[0] || p[0]=='?')
             return is(s.substr(1,s.size()-1), p.substr(1,p.size()-1));
         if (p[0]=='*') {
             if (p.size()==1) return true;
             for (int i = 0; i<=s.size(); ++i){
                  if (p[1]==s[1] && is(s.substr(i,s.size()-i),p.substr(1,p.size()-1)))
                      return true;
             }
         }
        return false;
    }

    bool isMatch(string s, string p) {
         p=remove(p);
         return is(s,p);
    }
};*/

class Solution
{
public:
    bool isMatch(string s, string p) {
        int j=0;
	    for (int star=0,i=0, last=0; i<s.length();) {
               //s[i]��p[j]ƥ�䣬ǰ��
		       if (j < p.size() && (s[i]==p[j] || p[j]=='?')) {
			      ++i;
			      ++j;
               }
               //last ��¼����*ʱs������λ�ã�star ��¼*��һ��λ��
		       else if (j<p.size() && p[j]=='*'){
			              last=i;
			              star=++j;
               }
              //������'*'
		       else if (star!=0){
			              i=++last;
			              j=star;
               }
		       else return 0;
		}
		for(; j<p.size() && p[j]=='*'; ++j);
		return j==p.size();
  }
};
