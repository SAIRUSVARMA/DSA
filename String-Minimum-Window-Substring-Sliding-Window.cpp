 string minWindow(string s, string t) {

       unordered_map<char, int>m;
       for(auto c:t)
       m[c]++; 

       int start=0;int end=0;int min_start=0; int min_length=INT_MAX;
       int counter=t.size();

       while(end<s.size())
       {
           if(m[s[end]]>0)
           counter--;
           m[s[end]]--;
           end++;

           while(counter==0)
           {
               if(end-start<min_length)
               {
                  min_length=end-start;
                  min_start=start;
               }

               m[s[start]]++;
               if(m[s[start]]>0)
               counter++;
               start++;

           }
       }

     if(min_length!=INT_MAX)
     return s.substr(min_start, min_length);
     return "";

 }

//TC:O(N) or O(T+S)( T and S are size of respective strings , O(T) for map, O(S) for while loop )
//sc:O(N) or O(T)(for using hashmap)
//Problem: https://leetcode.com/problems/minimum-window-substring/
