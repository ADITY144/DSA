#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> groupCount; // key: sum of digits, value: frequency
        
        // Calculate sum of digits for each number and count the frequency
        for (int i = 1; i <= n; ++i) {
            int sum = 0, num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            groupCount[sum]++;
        }

        int maxSize = 0;
        for (auto& p : groupCount) {
            if (p.second > maxSize)
                maxSize = p.second;
        }
        

        int result = 0;
        for (auto& p : groupCount) {
            if (p.second == maxSize)
                result++;
        }
        
        return result;
    }
};