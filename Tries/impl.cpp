#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode ** children;
    bool isterminal;

    TrieNode(char ch)
    {
        data = ch;
       children = new TrieNode*[26];
       for(int i = 0 ;i<26;i++) 
        children[i] = NULL;
        isterminal = false;
    }
};

class Trie{
   
    TrieNode * root;
    public:
    Trie()
    {
        root = new TrieNode('$');
    }

    void insertword(TrieNode * r, string word, int idx)
    {
        if(idx == word.length())
        {
            r->isterminal = true;
            return ;
        }

        int mappedi = word[idx] - 'a';

        if(r->children[mappedi] != NULL)
        {
            insertword(r->children[mappedi] , word , idx+1);
        }
        else
        {
            r->children[mappedi] = new TrieNode(word[idx]);
            insertword(r->children[mappedi] , word , idx+1);
        } 
    }
    void print(TrieNode * root)
    {
        cout<<root->data<<" -> ";
        if(root->isterminal) cout<<"isterm ";
        for(int i = 0  ; i < 26;i++)
        {
            if(root->children[i])
            {
                cout<< (char) (i +  'a');
            }
        }
        cout<<endl;
        for(int i = 0  ; i < 26;i++)
        {
            if(root->children[i])
            {
                print(root->children[i]);
            }
        }
    }
    bool deleteword(TrieNode * r, string word, int idx)
    {
        if(idx == word.length())
        {
            r->isterminal = false;
            return true;
        }   
        int midx = word[idx] - 'a';
        TrieNode * child = r->children[midx];
        if(child == NULL) return false;
        
        bool x = deleteword(r->children[midx], word, idx+1);
        
        if(x && child->isterminal == false) 
        {
            for(int i = 0 ; i  < 26;i++)
            {
                if(child->children[i] != NULL) return x;
            }
            delete child->children[midx];
            r->children[midx] = NULL;
            return true;
        }
        else{
            return false;
        }
    }
    bool searchword(TrieNode * r , string word, int idx)
    {
        if(idx == word.length())
        {
            if(r->isterminal)
                return true;
            else
                return false;
        }

        int midx = word[idx] - 'a';
        if(r->children[midx] == NULL)
            return false;
        
        return searchword(r->children[midx] , word, idx + 1);
    }
    void print()
    {
        print(root);
    }
    void insert(string x)
    {
        insertword(root, x ,0);
    }
    bool search(string x)
    {
        return searchword(root, x,0);
    }
    void delete_(string x)
    {
        deleteword(root,x,0);
    }
};
int main()
{
    Trie t;

    t.insert("be");
    t.insert("bed");
    t.insert("beside");
    t.print();
    cout<<endl;
    cout << t.search("bes") << " " << t.search("bed");

    t.delete_("beside");
    t.delete_("be");
    cout<<"deleted"<<endl;
   t.print();
}