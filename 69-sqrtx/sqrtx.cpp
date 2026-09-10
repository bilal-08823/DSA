class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        long long start = 1, end = x / 2;
        
        while (start <= end) {
            long long mid = start + (end - start) / 2;

            if (mid * mid == x)
                return mid;

            if (mid * mid < x)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return end;
    }
};