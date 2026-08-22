class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x >= 0 && x < 10) return true;
        long int reversed = 0;
        int temp = x;  
        while (temp > 0) {
            int digit = temp % 10;     
            temp /= 10;                 
            reversed = reversed * 10 + digit; 
        }
        return x == reversed;
    }
};