struct Node{
    Node* links[26];
    bool flag=false;
    bool isContaining(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void put(char ch, Node* node)
    {
       links[ch-'a']=node;
    }

    Node* get(char ch)
    {
        return links[ch-'a'];
    }

    void setEnd()
    {
        flag=true;
    }

    bool isEnd()
    {
        return flag;
    }
};


class Trie {
private:
Node* root;

public:

    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->isContaining(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
             if(!node->isContaining(word[i]))
             {
                return false;
             }
             node=node->get(word[i]);
        }
        return node->isEnd();

    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.length();i++)
        {
             if(!node->isContaining(prefix[i]))
             {
                return false;
             }
             node=node->get(prefix[i]);
        }
        return true;

    }
};

//TC:O(N)[ Insertion, Search and Prefix Search all O(N) ]
//SC:O(N)[  where N is the total number of characters across all unique words inserted into the Trie.]
//Problem:https://leetcode.com/problems/implement-trie-prefix-tree/
