    #include <vector>
    #include <string>
    using namespace std;
    
    void dfs(int span, int i, vector<int>& nums, vector<int> &tmp, vector<vector<int>> &ret){
        if (span == 0){
            ret.push_back(tmp);
            return ;
        }

        for (int j = i; j < nums.size(); j++){
            if (j + span > nums.size()){
                return;
            }
            tmp.push_back(nums[j]);
            dfs(span-1, j+1, nums, tmp, ret);
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        tmp.clear();
        ret.push_back(tmp);

        int span = 1;
        for (;span <= nums.size(); span++){
            dfs(span, 0, nums, tmp, ret);
        }
        return ret;
    }

    int main(){
        vector<int> nums{1,2,3,4};
        vector<vector<int>> ret = subsets(nums);
        return 0;
    }