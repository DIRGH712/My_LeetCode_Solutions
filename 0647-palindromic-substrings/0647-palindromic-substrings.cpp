class Solution {
public:
    int countSubstrings(string s) {
    if(s.empty()) return 0;
    
    int result = 1;
        
    for (int i = 0; i < s.size() - 1; i++) {
        middleOut(s, i, i, result);
        middleOut(s, i, i + 1, result);
    }
        
    return result;
    
    }

    void middleOut(string s, int i, int j, int& result) {
        while (i >= 0 && j <= s.size() - 1 && s[i] == s[j]) {
            i--;
            j++;
            result++;
        }
    }

};

