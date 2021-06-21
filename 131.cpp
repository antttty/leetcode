#include <string>
#include <vector>
using namespace std;

bool isPal(int l, int r, string &s){
        while(l <= r){
            if (s[l] != s[r])
                return false;
            else{
                l++;
                r--;
            }
        }
        return true;
    }

    void dfs(int l, int r, string& s, vector<string> & tmp,vector<vector<string>> &ret){
        if (l > r){
            ret.push_back(tmp);
            return;
        }
            
        
        for (int index = l; index <= r; index++){
            if (isPal(l, index, s)){//前面为回文串 l--index
                string str(s, l, index+1-l);
                tmp.push_back(str);
                dfs(index+1, r, s, tmp, ret);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>      ret;
        vector<string>              tmp;
        int                         l = 0, r = s.length()-1;
        dfs(l, r, s, tmp, ret);
        return ret;
    }

    int main(){
        string s = "aab";
        vector<vector<string>> ret = partition(s);
        return 0;
    }