/*没有重复的数组的全排列*/
/*回溯法*/
#include <vector>
#include <algorithm>
using namespace std;

typedef vector< vector<int> > vectorret ;
    void help(int i, int j, vector<int>& nums, vector< vector<int> > &ret){
        if (i == j){
            ret.push_back(nums);
            return ;
        }

        for (int k = i; k < j; i++){
            swap(nums[i], nums[k]);
            help(++k,  j, nums, ret);
            swap(nums[i], nums[--k]);
        }
        return ;
    }
    
    vector< vector<int> > permute(vector<int>& nums) {
        vector< vector<int> > ret;
        int len = nums.size();
        help(0, len-1, nums,  ret);
        return ret;
    }

int main()
{
    int tmp[] = {1, 2, 3};
    vector<int> nums(tmp, tmp + sizeof(tmp)/ sizeof(int));
    vector< vector<int> > ret = permute(nums);
    return 0;
}
