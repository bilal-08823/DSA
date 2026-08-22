class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return 0;

        int ans=0,rem;
        int num=x;

        while(x!=0){
            rem = x%10;

            if(ans>INT_MAX/10 || ans<INT_MIN/10)
            return 0;

            ans = ans*10 + rem;
            x=x/10;
        }
        if(num==ans)
        return 1;
        else
        return 0;
    }
};