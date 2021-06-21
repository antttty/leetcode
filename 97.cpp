#include <string>
#include <vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
        int     len1 = s1.length(), len2 = s2.length();
        int     len3 = s3.length();
        if (len3 != len1 + len2){
            return false;
        }

        vector<vector<bool>> dp(len1+1, vector<bool>(len2 + 1));
        dp[0][0] = true;
        int  row = 1, col = 1;
        for (; row <= len1; row++){ //第0列
            dp[row][0] = dp[row-1][0] && s1[row-1] == s3[row-1];
        }
        for (; col <= len2; col++){
            dp[0][col] = dp[0][col-1] && s2[col-1] == s3[col-1];
        }

        for (row=1; row <=len1; row++){
            for (col=1; col<=len2; col++){
                    dp[row][col] = (dp[row][col-1] && (s2[col-1]==s3[col+row-1]) ||
                                dp[row-1][col] && (s1[row-1]==s3[col+row-1]));
            }
        }
        return dp[len1][len2];
    }

    int main(){
        string s1("aabcc"), s2("dbbca");
        string s3("aadbbcbcac");
        isInterleave(s1, s2, s3);
        return 0;
    }