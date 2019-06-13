#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define vs vector<string>
#define vss vector<vs>

#define vi vector<int>
#define vii vector<vi>

vs subsequence(string str, int idx)
{
    if (str.length() == idx)
    {
        vs base(1, "");
        return base;
    }

    char ch = str[idx];
    vs recAns = subsequence(str, idx + 1);

    vs myAns;
    for (auto s : recAns)
    {
        myAns.push_back(s);
        myAns.push_back(ch + s);
    }

    return myAns;
}

vs keypad(string str, int idx, string *code)
{

    if (idx == str.length())
    {
        vs base(1, "");
        return base;
    }

    char ch = str[idx];
    vs recAns = keypad(str, idx + 1, code);

    vs myAns;
    string s = code[(ch - '0')];

    for (string child : recAns)
    {
        for (int i = 0; i < s.length(); i++)
        {
            myAns.push_back(s[i] + child);
        }
    }

    return myAns;
}

vs stairs(int num, int steps)
{
    if (num == 0)
    {
        vs base(1, "");
        return base;
    }

    vs
        myRes;
    for (int st = 1; st <= steps && num - st >= 0; st++)
    {
        vs recRes = stairs(num - st, steps);
        for (auto s : recRes)
        {
            myRes.push_back(s + to_string(st));
        }
    }

    return myRes;
}

vs mazePath(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        vs base(1, "");
        return base;
    }

    vs myRes;
    if (sr + 1 <= er)
    {
        vs recRes = mazePath(sr + 1, sc, er, ec);
        for (auto str : recRes)
        {
            myRes.push_back(str + "V");
        }
    }

    if (sc + 1 <= ec)
    {
        vs recRes = mazePath(sr, sc + 1, er, ec);
        for (auto str : recRes)
        {
            myRes.push_back(str + "H");
        }
    }

    if (sr + 1 <= er && sc + 1 <= ec)
    {
        vs recRes = mazePath(sr + 1, sc + 1, er, ec);
        for (auto str : recRes)
        {
            myRes.push_back(str + "D");
        }
    }

    return myRes;
}

vs multiMazePath(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        vs base(1, "");
        return base;
    }

    vs myRes;
    for (int v = 1; sr + v <= er; v++)
    {
        vs recRes = multiMazePath(sr + v, sc, er, ec);
        for (auto str : recRes)
        {
            myRes.push_back(str + "V" + to_string(v));
        }
    }

    for (int h = 1; sc + h <= ec; h++)
    {
        vs recRes = multiMazePath(sr, sc + h, er, ec);
        for (auto str : recRes)
        {
            myRes.push_back(str + "H" + to_string(h));
        }
    }

    for (int d = 1; sr + d <= er && sc + d <= ec; d++)
    {
        vs recRes = multiMazePath(sr + d, sc + d, er, ec);
        for (auto str : recRes)
        {
            myRes.push_back(str + "D" + to_string(d));
        }
    }

    return myRes;
}

vii *targetSum(vi &arr, int idx, int target)
{
    if (idx == arr.size())
    {
        vii *base = new vii();
        if (target == 0)
        {
            vi smallBase;
            (*base).push_back(smallBase);
        }
        return base;
    }

    vii *myAns = new vii();

    vii *coming = targetSum(arr, idx + 1, target - arr[idx]);
    for (auto child = coming->begin(); child != coming->end(); child++)
    {
        vi smallAns(1, arr[idx]);
        for (auto ch = child->begin(); ch != child->end(); ch++)
        {
            smallAns.push_back(*ch);
        }
        myAns->push_back(smallAns);
    }

    vii *notComing = targetSum(arr, idx + 1, target);
    for (auto child = notComing->begin(); child != notComing->end(); child++)
    {
        vi smallAns;
        for (auto ch = child->begin(); ch != child->end(); ch++)
        {
            smallAns.push_back(*ch);
        }
        myAns->push_back(smallAns);
    }

    delete coming;
    delete notComing;
    return myAns;
}

void targetSum01(vi &arr, int idx, int target, vi &smallAns, vii *ans)
{

    if (idx == arr.size())
    {
        if (target == 0)
        {
            vi base;
            for (auto i : smallAns)
            {
                base.push_back(i);
            }
            ans->push_back(base);
        }
        return;
    }

    smallAns.push_back(arr[idx]);
    targetSum01(arr, idx + 1, target - arr[idx], smallAns, ans);
    smallAns.pop_back();

    targetSum01(arr, idx + 1, target, smallAns, ans);
}

vs printAllPossibbleCodes(string str, int vidx)
{
    if (str.length() == vidx)
    {
        vs base(1, "");
        return base;
    }

    char ch = str[vidx];
    int x = ch - '0';
    vs myRes;

    vs oneLen = printAllPossibbleCodes(str, vidx + 1);
    if (x != 0)
    {
        for (auto s : oneLen)
        {
            myRes.push_back((char)(x + 'a' - 1) + s);
        }
    }
    else
        return oneLen;

    if (vidx + 2 <= str.length())
    {
        string ss(str, vidx, 2);
        stringstream sub(ss);
        int y;
        sub >> y;

        if (y > 9 && y <= 26)
        {
            vs twoLen = printAllPossibbleCodes(str, vidx + 2);
            for (auto s : twoLen)
            {
                myRes.push_back((char)(y + 'a' - 1) + s);
            }
        }
    }

    return myRes;
}

vii *coinChangeCombination(vi &arr, int vidx, int target)
{
    if (target == 0)
    {
        vii *base = new vii();
        vi ba;
        base->push_back(ba);
        return base;
    }

    vii *myAns = new vii();
    for (int i = vidx; i < arr.size() && target - arr[i] >= 0; i++)
    {
        vii *recAns = coinChangeCombination(arr, i, target - arr[i]);
        
        for (auto child : *recAns)
        {
            vi smallAns(child);
            smallAns.push_back(arr[i]);
            myAns->push_back(smallAns);
        }

        // delete recAns;
    }

    return myAns;
}

//================================================================================

void solve()
{

    // vs ans = subsequence("abc", 0);

    // string arr[] = {".", "abc", "def", "gh", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};
    // vs ans = keypad("234", 0, arr);

    // vs ans = stairs(7, 3);
    // vs ans = mazePath(0, 0, 1, 1);
    // vs ans = multiMazePath(0, 0, 3, 3);
    // vs ans = printAllPossibbleCodes("14550021", 0);

    // for (auto s : ans)
    //     cout << s << endl;

    vii *ans = new vii();

    // vi arr = {10, 60, 40, 20, 50, 30};
    // ans = targetSum(arr, 0, 100);

    // vi smallAns;
    // targetSum01(arr, 0, 100, smallAns, ans);

    vi arr = {2, 3, 5};
    ans = coinChangeCombination(arr, 0, 7);

    for (auto child : *ans)
    {
        for (auto ch : child)
            cout << ch << " ";
        cout << endl;
    }
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}