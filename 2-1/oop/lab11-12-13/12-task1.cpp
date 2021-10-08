#include <bits/stdc++.h>
using namespace std;

const int MAX = 3;

template <class T>
class Stack
{
private:
    T st[MAX]; 
    int top;   
public:
    class Full {};
    class Empty {};
    Stack() 
    {
        top = -1;
    }
    void push(T var)
    {
        if (top >= MAX - 1) 
            throw Full();   
        st[++top] = var;    
    }
    T pop()
    {
        if (top < 0)       
            throw Empty(); 
        return st[top--];  
    }
    T peek()
    {
        if (top < 0)       
            throw Empty(); 
        return st[0];
    }
};

int main()
{
    // Stack<int> s1;
    // try
    // {
    //     s1.push(10);
    //     s1.push(20);
    //     s1.push(30);
    //     cout << s1.pop() << endl;
    //     cout << s1.peek() << endl;
    //     s1.push(40);
    //     //s1.push(50);
    //     cout << s1.pop() << endl;
    //     cout << s1.pop() << endl;
    //     cout << s1.pop() << endl;
    //     //cout << s1.pop() << endl;
    //     cout << s1.peek() << endl;
    // }
    // catch (Stack<int>::Full)
    // {
    //     cout << "Exception : Stack Full " << endl;
    // }
    // catch (Stack<int>::Empty)
    // {
    //     cout << "Exception : Stack Empty " << endl;
    // }


    Stack<float> s1;
    try
    {
        s1.push(11.5);
        s1.push(22.5);
        s1.push(33.5);
        cout << s1.pop() << endl;
        cout << s1.peek() << endl;
        s1.push(44.5);
        s1.push(55.5);
        // cout << s1.pop() << endl;
        // cout << s1.pop() << endl;
        // cout << s1.pop() << endl;
        // cout << s1.pop() << endl;
        // //cout << s1.peek() << endl;
    }
    catch (Stack<float>::Full)
    {
        cout << "Exception : Stack Full " << endl;
    }
    catch (Stack<float>::Empty)
    {
        cout << "Exception : Stack Empty " << endl;
    }
    return 0;

}
