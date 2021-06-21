/*汉明距离*/
/*先异或等到结果，在计算结果中的1的个数*/
int hammingDistance(int x, int y){
    int sum = x ^ y;
    int cnt = 0;
    while(sum > 0){
        cnt++;
        sum &= (sum - 1);
    }
    return cnt;
}