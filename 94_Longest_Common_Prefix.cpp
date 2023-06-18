#include <bits/stdc++.h>
using namespace std;
struct trie
{
    trie *links[26];
    bool isword = false;

    bool isset(char c)
    {
        return links[c - 'a'];
    }
    void put(char c)
    {
        links[c - 'a'] = new trie();
    }
    trie *getnext(char c)
    {
        return links[c - 'a'];
    }
    void setend()
    {
        isword = true;
    }
};
class Solution
{
public:
    string addword(trie *t, string &word, string longestprefix)
    {
        for (char ch : word)
        {
            if (t->isset(ch))
                longestprefix += ch;
            if (!t->isset(ch))
                t->put(ch);
            t = t->getnext(ch);
        }
        t->setend();
        return longestprefix;
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        trie *head = new trie();
        string res = strs[0];
        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            trie *t = head;
            string longestprefix = addword(t, s, "");
            if (i > 0)
                res = res.size() < longestprefix.size() ? res : longestprefix;
        }
        return res;
    }
};