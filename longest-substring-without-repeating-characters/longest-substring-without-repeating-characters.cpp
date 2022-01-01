class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = 0;
        
        if(s.length() == 0)
            return 0; 
        if(s.length() == 1)
            return 1;
        
        for(int i=0; i<s.length()-1; i++) {
            map<char, int> m;
            ++m[s[i]];
            int length = 1;
        
            for(int j=i+1; j<s.length(); j++) {    
                ++m[s[j]];
                ++length;
                
                if(m[s[j]] > 1) {
                    --length;
                    if(length > maxlength)
                        maxlength = length;
                    break;
                }
                
                if(length > maxlength)
                    maxlength = length;
            }
        }
        
        return maxlength;
    }
};