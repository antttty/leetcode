int removeElement(int* nums, int numsSize, int val){
    int index1 = 0, index2 = 0;
    while (index2<numsSize)
    {
        while (index2 < numsSize && nums[index2] == val)
            index2++;
        if (index2 == numsSize)
            break;
        nums[index1++] = nums[index2++];
    }
    return index1;

}

int main()
{
    int nums[] = {0,1,2,2,3,0,4,2};
    int ret = removeElement(nums, 8, 2);
    return 0;
}