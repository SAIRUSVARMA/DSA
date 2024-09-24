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

class WordDictionary {
private:
Node* root;

bool searchHelper(string& word, int index, Node* node )
{
    if(index==word.size())
    return node->isEnd();

    char ch=word[index];
    if(ch=='.')
    {
        for(int i=0;i<26;i++)
        {
            if(node->links[i] && searchHelper(word, index+1, node->links[i]))
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        if(!node->isContaining(ch))
        {
           return false;
        }
        return searchHelper(word,index+1,node->get(ch));
    }
}

public:
    WordDictionary()
    {
        root=new Node();
    }
    
    void addWord(string word) 
    {
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
        return searchHelper(word,0,root);
    }
};

//L is the length of the word.
//TC:O(L) [addword-O(L) search-O(L*26)]
//SC:O(L)
//Problem:https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
