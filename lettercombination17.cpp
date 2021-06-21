#include <vector>
#include <string>
using namespace std;

vector<string>  strs;
void  initMap(){
    strs.clear();
    strs.push_back("abc"); strs.push_back("def"); strs.push_back("ghi");
    strs.push_back("jkl"); strs.push_back("mno"); strs.push_back("pqrs");
    strs.push_back("tuv"); strs.push_back("wxyz");
    }

void combination(int index, int endindex, string& str, vector<string>& rets, string &digits){
    int pos = (int)(digits[index] - '2');
    
    if (index == endindex){ //最后一位
        for (int i = 0; i < strs[pos].size(); i++){
            str.push_back(strs[pos][i]);
            rets.push_back(str);
            str.pop_back();
        }
        return ;
    } else {
        for (int i = 0; i < strs[pos].size(); i++){
            str.push_back(strs[pos][i]);
            combination(index+1, endindex, str, rets, digits);
            str.pop_back();//Erases the last character of the string, effectively reducing its length by one.
        }
    }

}
vector<string> letterCombinations(string digits) {
    initMap();
    string str;
    vector<string> rets;
    combination(0, digits.size()-1, str, rets, digits);
    return rets;
}

int main(){
    string str = "22";
    vector<string> rets = letterCombinations(str);

    return 0;
}