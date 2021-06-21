    #include <vector>
    #include <string>
    using namespace std;
    
    vector<int> maxDepthAfterSplit(string seq) {
        int cur1 = 0, depth1 = 0; 
        int cur2 = 0, depth2 = 0;
        vector<int> ret;
        int i = 0;
        while(i < seq.length()){
            if (seq[i] == '('){ // "("
                if (cur1 < cur2){
                    ret.push_back('0');
                    cur1++;
                }else{
                    ret.push_back('1');
                    cur2++;
                }
            }else{// ")"
                if (cur1 > cur2){
                    ret.push_back('0');
                        cur1--;
                }else{
                    ret.push_back('1');
                    cur2--;
                }
            }
        }
        return ret;
    }

    int main(){

    }