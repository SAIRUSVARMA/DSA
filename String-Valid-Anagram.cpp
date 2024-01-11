 bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        return 0;
       /* return 0;
        map<char, int>ms;
        map<char, int>mt;


        for(int i=0;i<s.size();i++)
        {
            ms[s[i]]++;
            mt[t[i]]++;
        }

        for(auto c:s)
        if(ms[c]!=mt[c])
        return 0;
        return 1;*/

        
        vector<int>v(26,0);
        for(int i=0;i<s.size();i++)
        {
            v[s[i]-'a']++;
            v[t[i]-'a']--;
        }
        for(auto c:v)
        if(c!=0)
        return 0;
        return 1;
    }

//TC:O(N) SC:O(1)[Vector of only 26 size]
//Problem:https://leetcode.com/problems/valid-anagram/
