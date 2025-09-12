class Solution {
public:
    string sortVowels(string s) {
        vector<int> vowelIndices;
        vector<char> vowels;

        auto isVowel = [](char ch) {
            ch = tolower(ch);
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                   ch == 'u';
        };

        for (int i = 0; i < s.size(); ++i) {
            if (isVowel(s[i])) {
                vowelIndices.push_back(i);
                vowels.push_back(s[i]);
            }
        }

        sort(vowels.begin(), vowels.end());

        for (int i = 0; i < vowelIndices.size(); ++i) {
            s[vowelIndices[i]] = vowels[i];
        }

        return s;
    }
};