/*
S = "cba"
T = "abcd" T中可以有重复
输出 “cbad” S中没有出现但是T中出现的 一定要是排在后面的
*/
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

string customSortString(string order, string str) {
    int index[26];
    memset(index, 28, sizeof(index));
    int len = order.length();
    for (int i = 0; i < len; i++){
        index[order[i] - 'a'] = i + 1;//记录下每个字母对应的下标
    }
    string ret;
    ret.push_back(str[0]);
    for (int i = 1; i < str.length(); i++){
        ret.push_back(str[i]);
        for (int j = ret.length() - 1; j > 0; j--){                
            if (index[ret[j] - 'a'] < index[ret[j - 1] - 'a']){
                char tmp = ret[j];
                ret[j] = ret[j-1];
                ret[j-1] = tmp;
            }else
                break;
        }
    }
    return ret;
}

int main()
{
    string order = "abc", 
    str = "dcba";
    cout << customSortString(order, str) << '\n';
    return 0;
}