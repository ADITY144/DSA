class Solution {
public:
    int reverse(int x) {
        long long rev = 0; // long long use karte hain overflow check ke liye
        while (x != 0) {
            int digit = x % 10;  // last digit nikalna
            rev = rev * 10 + digit; // reverse number banate jana
            x /= 10; // last digit hata dena
        }
        // 32-bit signed integer range check
        if (rev < INT_MIN || rev > INT_MAX) return 0;
        return (int)rev;
    }
};