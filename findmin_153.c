//binary search
//遍历一遍 肯定能找到 只是应该考察的是更优的解法
//充分利用题目给出的条件 有序 数据唯一 --> 二分查找

int findMin(int* nums, int numsSize){
    int low = 0, high = numsSize-1;
    int mid = low + (high - low)/2;

    while(low < high){
        if (nums[mid] > nums[high])
            low = mid + 1;
        else
            high = mid; //mid可能是最小值 所以下一次的查找区间 应该包含mid
        mid = low + (high - low)/2;
    }
    return nums[low];
}