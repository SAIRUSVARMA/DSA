  bool isValid(string s) {
        stack<char>st;
        for(auto i:s)
        {
            if(i=='('||i=='{'||i=='[')
                st.push(i);
            else
            {
                if(st.empty())
                    return false;
                else if(st.top()=='(' && i!=')')
                    return false;
                 else if(st.top()=='[' && i!=']')
                    return false;
                 else if(st.top()=='{' && i!='}')
                    return false;
                st.pop();
                
            }
        }
        return st.empty();
        
    }

//TC:O(N)[N is the length of the string]
//S(C):O(N)[In worst case the stack stores all the elements of the string].
//Problem:https://leetcode.com/problems/valid-parentheses/description/
