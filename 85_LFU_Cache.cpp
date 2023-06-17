#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key, value, cnt;
    Node *next, *prev;
    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        cnt = 1;
    }
};
struct List
{
    int size;
    Node *head;
    Node *tail;
    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }
    void removeNode(Node *delnode)
    {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};
class LFUCache
{
    map<int, Node *> keyNode;
    map<int, List *> freqlistmap;
    int maxsizecache;
    int minfreq;
    int cursize;

public:
    LFUCache(int capacity)
    {
        maxsizecache = capacity;
        minfreq = 0;
        cursize = 0;
    }
    void updatefreqlistmap(Node *node)
    {
        keyNode.erase(node->key);
        freqlistmap[node->cnt]->removeNode(node);
        if (node->cnt == minfreq and freqlistmap[node->cnt]->size == 0)
        {
            minfreq++;
        }
        List *nexthigherfreqlist = new List();
        if (freqlistmap.find(node->cnt + 1) != freqlistmap.end())
        {
            nexthigherfreqlist = freqlistmap[node->cnt + 1];
        }
        node->cnt += 1;
        nexthigherfreqlist->addFront(node);
        freqlistmap[node->cnt] = nexthigherfreqlist;
        keyNode[node->key] = node;
    }
    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->value;
            updatefreqlistmap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxsizecache == 0)
        {
            return;
        }
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->value = value;
            updatefreqlistmap(node);
        }
        else
        {
            if (cursize == maxsizecache)
            {
                List *list = freqlistmap[minfreq];
                keyNode.erase(list->tail->prev->key);
                freqlistmap[minfreq]->removeNode(list->tail->prev);
                cursize--;
            }
            cursize++;
            minfreq = 1;
            List *listfreq = new List();
            if (freqlistmap.find(minfreq) != freqlistmap.end())
            {
                listfreq = freqlistmap[minfreq];
            }
            Node *node = new Node(key, value);
            listfreq->addFront(node);
            keyNode[key] = node;
            freqlistmap[minfreq] = listfreq;
        }
    }
};
