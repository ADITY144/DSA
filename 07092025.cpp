class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        for (int i = 1; i <= n / 2; ++i) {
            result.push_back(i);
            result.push_back(-i);
        }
        if (n % 2 != 0) {
            result.push_back(0); // Agar n odd hai toh 0 bhi daalna padega
        }
        return result;
    }
};