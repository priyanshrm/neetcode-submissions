class Solution {
public:
    int mySqrt(int x) {
        int i = 0, j = x;
        while(i<=j){
            int mid = i + (j-i)/2;
            long long square = 1LL * mid * mid;
            if(mid > x || square > x){
                j = mid - 1;
            } else if(square < x){
                i = mid + 1;
            } else {
                return mid;
            }
        }
        return min(i,j);
    }
};