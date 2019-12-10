#include <iostream>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;

void IncreasingDecreasing(string str)
{
    stack<int> st;
    int val = 1;
    string ans = "";

    for (int i = 0; i < str.length(); i++)
    {
        st.push(val++);
        while (str[i] == 'i' && st.size() != 0)
        {
            ans += to_string(st.top());
            st.pop();
        }
    }

    st.push(val);
    while (st.size() != 0)
    {
        ans += to_string(st.top());
        st.pop();
    }

    cout << ans << endl;
}

void nextGreaterForward_1(vector<int> &arr)
{
    vector<int> ans(arr.size(), 0);
    int idx = arr.size() - 1;
    ans[idx] = -1;

    stack<int> st;
    st.push(arr[idx]);

    for (int i = idx - 1; i >= 0; i--)
    {
        while (st.size() > 0 && arr[i] > st.top())
        {
            st.pop();
        }

        ans[i] = st.size() > 0 ? st.top() : -1;
        st.push(arr[i]);
    }
}

vector<int> *nextGreaterElementIdx(vector<int> &arr)
{
    vector<int> *ngeidx = new vector<int>(arr.size(), 0);
    stack<int> st;

    (*ngeidx)[arr.size() - 1] = arr.size();
    st.push(arr.size() - 1);

    for (int i = arr.size() - 2; i >= 0; i--)
    {
        while (st.size() > 0 && arr[i] > arr[st.top()])
        {
            st.pop();
        }
        (*ngeidx)[i] = (st.size() > 0 ? st.top() : arr.size());
    }

    return ngeidx;
}

void slidingWindow(vector<int> &arr, int k)
{

    vector<int> ngeidx = *nextGreaterElementIdx(arr);
    int j = 0;

    vector<int> ans(arr.size() - k + 1, 0);
    for (int i = 0; i < arr.size() - k + 1; i++)
    {
        if (i > j)
            j = i;

        while (ngeidx[j] < i + k)
        {
            j = ngeidx[j];
        }

        ans[i] = ngeidx[j];
    }

    for (int i : ans)
    {
        cout << ans[i] << " ";
    }
}

bool stupidBrackets(string str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch != ')')
        {
            st.push(ch);
        }
        else
        {
            bool flag = false;
            while (st.size() > 0 && st.top() != '(')
            {
                flag = true;
                st.pop();
            }
            if (!flag)
                return false;
            st.pop();
        }
    }

    return true;
}

void set1()
{
    // IncreasingDecreasing("dddiddid");
    cout << (boolalpha) << stupidBrackets("((a+b)*(C+d))");
}

//=================================================================================

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*' || c == '^');
}

int periority(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
    {
        cout << "InvalidOperationException" << endl;
        return -1;
    }
}

int performOperation(stack<int> &value, stack<char> &oper)
{
    int val1 = value.top();
    value.pop();

    int val2 = value.top();
    value.pop();

    char ch = oper.top();
    oper.pop();

    if (ch == '+')
        return val1 + val2;
    else if (ch == '-')
        return val2 - val1;
    else if (ch == '*')
        return val1 * val2;
    else if (ch == '/')
    {
        if (val1 == 0)
        {
            cout << "DivideByZeroException" << endl;
            return -1;
        }
        return val2 / val1;
    }
    else if (ch == '^')
        return (int)pow(val2, val1);
    else
    {
        cout << "InvalidOperationException" << endl;
        return -1;
    }
}

void evalutionOfInfixExpre(string str)
{
    stack<int> value;
    stack<char> oper;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch >= '0' && ch <= '9')
        {
            int num = 0;
            while (ch >= '0' && ch <= '9')
            {
                num = num * 10 + (ch - '0');
                i++;
                if (i < str.size())
                {
                    ch = str[i];
                }
                else
                    break;
            }
            i--;
            value.push(num);
        }
        else if (ch == '(')
            oper.push(ch);
        else if (ch == ')')
        {
            while (oper.top() != '(')
            {
                value.push(performOperation(value, oper));
            }
            oper.pop();
        }
        else if (isOperator(ch))
        {
            while (oper.size() > 0 && oper.top() != '(' && periority(oper.top()) > periority(ch))
            {
                value.push(performOperation(value, oper));
            }
        }
    }

    while (oper.size() != 0)
    {
        value.push(performOperation(value, oper));
    }

    cout << value.top() << endl;
    value.pop();
}

void infixToPostFix(string str)
{
    string ans = "";
    stack<char> oper;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch >= '0' && ch <= '9')
            ans += ch;
        else if (ch == '(')
            oper.push(ch);
        else if (ch == ')')
        {
            while (ch != '(')
            {
                ans += ch;
                oper.pop();
            }
            oper.pop();
        }
        else if (isOperator(ch))
        {
            while (oper.size() > 0 && oper.top() != '(' && periority(oper.top()) > periority(ch))
            {
                ans += oper.top();
                oper.pop();
            }
            ans += ch;
        }
    }
}

void postFix123(string post){
stack<int> eval;
stack<string> infix;
stack<string> pres;


}

void Evalution()
{

    evalutionOfInfixExpre("");
}

//================================================================================

void solve()
{
    set1();
}

int main(int args, char **argc)
{
    solve();
}