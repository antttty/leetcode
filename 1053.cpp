#include <vector>
using namespace std;

vector<int> prevPermOpt1(vector<int>& arr) {
        vector<int> ret(arr.begin(), arr.end());
        int min = 10001, max = -1, maxindex = -1;
        int i = 0;
        for (i = arr.size() - 1 ; i >= 0; i--){//从后向前遍历
            if (arr[i] <= min){
                min = arr[i];
            }else{
                if (ret[i] <= ret[maxindex]){
                    int j = i + 1;
                    int tmpmax = -1, tmpindex = maxindex;
                    while(j <= tmpindex){
                        if (ret[j] >= ret[i]){
                            j++;
                            continue;
                        }
                        if (ret[j] > tmpmax){
                            tmpmax = ret[j];
                            maxindex = j;
                        }
                        j++;
                    }
                }
                //将i与其后的最大值交换
                int tmp = ret[i];
                ret[i] = ret[maxindex];
                ret[maxindex] = tmp;
                break;
            }
            if (arr[i] > max){
                max = arr[i];
                maxindex = i;
            }
        }

        return ret;
    }

    int main(){
        vector<int> vecs = {60,39,90,27,11,36,57,87};
        prevPermOpt1(vecs);
        return 0;
    }