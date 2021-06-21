#include <vector>
#include <queue>
#include <limits.h>
#include <iostream>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (nums.size() == 0)
            return ret;

        queue<int> que;
        que.push(nums[0]);
        int left = 0;
        for (int i = 1; i < k; i++)
        {
            if (nums[i] > que.front()){
                queue<int> tmp;
                que.swap(tmp);
                que.push(nums[i]);
                left = i;
            }else{
                que.push(nums[i]);
            }
        }
        
        ret.push_back(que.front());
        for (int i = k; i < nums.size(); i++)
        {
            if (i - k >= left){//弹出超出窗口范围的 还要弹出找到窗口中的最大值
                que.pop();
                left = left + 1; 
                int max = INT_MIN;
                int j = 0, tmpleft = 0 ;
                for ( j = left; j <= i; j++){
                    if (nums[j] > max){
                        max = nums[j];
                        tmpleft = j;
                    }
                }
                int span = tmpleft - left;
                left = (tmpleft>0)?tmpleft:left;
                while(span> 0){
                    que.pop();
                    span--;
                }
            }    
            if (nums[i] >= que.front()){
                queue<int> tmp;
                que.swap(tmp);
                left = i;
            }
            que.push(nums[i]);
            ret.push_back(que.front());
        }

        return ret;
    }

    int main(){
        int nums[] = {1,3,-1,-3,5,3,6,7};
        vector<int> vecs(nums, nums + sizeof(nums)/sizeof(int));
        vector<int>  ret = maxSlidingWindow(vecs, 3);
        for (auto &elem:ret){
            std::cout << elem << "  ";
        }
        std::cout << '\n';
        return 0;
    }