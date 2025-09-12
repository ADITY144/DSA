class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int maxVal = num, minVal = num;

        for (char d = '0'; d <= '9'; ++d) {
            for (char r = '0'; r <= '9'; ++r) {
                string temp = s;
                for (char& c : temp) {
                    if (c == d) c = r;
                }
                int remapped = stoi(temp);
                maxVal = max(maxVal, remapped);
                minVal = min(minVal, remapped);
            }
        }

        return maxVal - minVal;
    }
};