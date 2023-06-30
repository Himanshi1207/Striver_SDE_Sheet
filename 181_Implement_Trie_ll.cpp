#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
struct Node
{
    Node *links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void inreaseEnd()
    {
        cntEndWith++;
    }
    void increasePrefix()
    {
        cntPrefix++;
    }
    void deleteEnd()
    {
        cntEndWith--;
    }
    void deletePrefix()
    {
        cntPrefix--;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    int getEnd()
    {
        return cntEndWith;
    }
    int getPrefixEnd()
    {
        return cntPrefix;
    }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        // Write your code here.
        root = new Node();
    }

    void insert(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                node->put(word[i], new Node());
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->inreaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }
        return node->cntEndWith;
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }
        return node->cntPrefix;
    }

    void erase(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->deletePrefix();
            }
            else
                return;
        }
        node->deleteEnd();
    }
};
