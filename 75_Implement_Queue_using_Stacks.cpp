#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
public:
    stack<int> in, out;
    MyQueue()
    {
    }

    void push(int x)
    {
        in.push(x);
    }

    int pop()
    {
        int x;
        if (!out.empty())
        {
            x = out.top();
            out.pop();
            return x;
        }
        else
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
            x = out.top();
            out.pop();
            return x;
        }
    }

    int peek()
    {
        if (!out.empty())
            return out.top();
        else
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
            return out.top();
        }
    }

    bool empty()
    {
        return out.empty() and in.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */