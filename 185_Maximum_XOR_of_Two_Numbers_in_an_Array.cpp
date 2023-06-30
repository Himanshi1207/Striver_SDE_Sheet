#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[2];
    bool containskey(int bit)
    {
        return (links[bit] != NULL);
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
    Node *get(int bit)
    {
        return links[bit];
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containskey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containskey(!bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        Trie trie;
        int maxi = 0;
        for (auto it : nums)
        {
            trie.insert(it);
        }
        for (auto it : nums)
        {
            maxi = max(maxi, trie.getMax(it));
        }
        return maxi;
    }
};