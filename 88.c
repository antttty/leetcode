void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int index = m + n - 1;
    
    while(index >= 0){
        if (m>=0 && n>=0){
            if (nums1[m-1] > nums2[n-1]){
                nums1[index] = nums1[m-1];
                m--;
            }else{
                nums1[index] = nums2[n-1];
                n--;
            }
        }else if(n < 0){
            break;
        }else{
            nums1[index] = nums2[n-1];
            n--;
        }
        index--;
    }
    return ;
}

int main(){
    int nums1[6] = {1,2,3};
    int nums2[3] = {2,5,6};
    merge(nums1, 6, 3, nums2, 3, 3);
    return 0;
}