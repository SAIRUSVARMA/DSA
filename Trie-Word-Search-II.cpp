struct Node
{
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
   void duplicateEnd()
   {
      flag=false;
   }
;

class Trie{
public:
Node* root;

Trie()
{
    root=new Node();
}

void insert(string word)
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

bool search(string word)
{
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

bool startsWith(string prefix)
{
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

class Solution {
private:
    vector<string> result;
    int rows, cols;
    Trie* trie;

    void dfs(int row, int col, vector<vector<char>>& board, Node* node, string& path)
    {
        if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] == '#')
        return;

        char currentChar = board[row][col];
        if (!node->isContaining(currentChar)) 
        return;

        node = node->get(currentChar);
        path.push_back(currentChar);

        if (node->isEnd())
        {
            result.push_back(path);
            node->duplicateEnd();  // To avoid duplicate results
        }

        board[row][col] = '#';  // Mark as visited

        // Explore in all 4 directions
        dfs(row + 1, col, board, node, path);
        dfs(row - 1, col, board, node, path);
        dfs(row, col + 1, board, node, path);
        dfs(row, col - 1, board, node, path);

        // Backtrack
        board[row][col] = currentChar;
        path.pop_back();
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        trie = new Trie();
        rows = board.size();
        cols = board[0].size();

        // Insert all words into the Trie
        for (string& word : words) 
        {
            trie->insert(word);
        }
        /* or simply
        for (int i=0;i<words.size();i++)
        {
            string word=words[i];
            trie->insert(word);
        }*/

        // Start DFS from each cell on the board
        string path;
        for (int row = 0; row < rows; ++row)
         {
            for (int col = 0; col < cols; ++col)
            {
                dfs(row, col, board, trie->root, path);
            }
        }

        return result;
    }
};
//TC:O(L + M * N * 4^W)
/*
Trie Insertion: O(L), where L is the total number of characters in all words.
DFS: O(M * N * 4^W), where M is the number of rows, N is the number of columns, and W is the length of the longest word.
*/
//SC:O(L*n+M*N+W)
/*
Trie: O(n*L) for storing the words.[here n is no of words, L is average length of words]
DFS Stack: O(M * N) for storing recursion state and visited cells.
Recursion Stack: O(W) [During the DFS search, the maximum depth of the recursion stack can go
as deep as the length of the longest word (W).]
*/
//Problem:https://leetcode.com/problems/word-search-ii/description/
