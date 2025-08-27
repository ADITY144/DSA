class Solution {
public:
    
    bool isPalindrome(int x) {
        // Negative number toh kabhi palindrome nahi ho sakta
        if (x < 0) return false;

        int original = x;
        long reversed = 0;

        // Reverse karte hain number ko
        while (x != 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        // Agar reversed == original, toh palindrome hai
        return reversed == original;
    }
};