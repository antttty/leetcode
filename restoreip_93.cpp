#include <string>
#include <vector>
#include <iostream>
using namespace std;

void dfs(int index, int pos, int len, string& str, string& s, vector<string>& ret){
        if (index == 4 && pos == len){
            ret.push_back(str);
            return ;
        }

        string tmp = str;
        for (int i = 1; i <=3; i++){
            string strtmp = s.substr(pos, i);
            if (stoi(strtmp,nullptr,0) > 255)
                return ;
            str += strtmp;//i 取 1 2 3
            if (index != 3)
                str += ".";
            if (len - pos - i >= (3 - index) && len - pos - i <= 3*(3 - index))
                dfs(index + 1, pos + i, len, str, s, ret);
            str = tmp;//str还原 回溯
            if (s[pos] == '0')//当前位为0
                return;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        vector<string> ret;
        string str;
        dfs(0, 0, len, str, s, ret);
        for(auto &elem:ret){
            cout << elem << '\n';
        }
        return ret;
    }

    int main(){
        string ip = "101023";
        restoreIpAddresses(ip);
        return 0;
    }