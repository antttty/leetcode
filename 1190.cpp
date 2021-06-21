#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

string reverseParentheses(string s) {
        stack<char> stk;
        string ret;
        int len = s.length();
        int i = 0;
        while(i < len){
            if (s[i] == ')'){
                string tmp;
                while(!stk.empty() && stk.top()!='('){ //一直出栈
                    tmp.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();//pop '('
                int j = 0;
                while(j < tmp.length()){
                    stk.push(tmp[j++]);   
                }
            }else{
                stk.push(s[i]);
            }
            i++;
        }

        while(!stk.empty() && stk.top()!='('){ //一直出栈
            ret.push_back(stk.top());
            stk.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    int main(){
        string ret = reverseParentheses("u(love)i");
        cout << ret << '\n';
        return 0;
    }