#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define vs vector<string>
#define vss vector<vs>

#define vi vector<int>
#define vii vector<vi>

#define vc vector<char>
#define vcc vector<vc>

#define vb vector<bool>
#define vbb vector<vb>

//simple.========================================================================

int subsequence(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return 0;
    }

    char ch = str[0];
    str = str.substr(1);

    int count = 0;
    count = 1 + subsequence(str, ch + ans);
    count += subsequence(str, ans);
    return count;
}

int stairs(int n, int steps, string ans)
{
    if (n == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 1; i <= steps && n - i >= 0; i++)
    {
        count += stairs(n - i, steps, ans + to_string(i));
    }
    return count;
}

int keyPad(string str, vs &codes, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }

    char ch = str[0];
    int idx = ch - '0';
    string code = codes[idx];

    int counter = 0;
    for (int i = 0; i < code.length(); i++)
    {
        counter += keyPad(str.substr(1), codes, ans + code[i]);
    }

    return counter;
}

int mazePath(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }

    if (sr > er || sc > ec)
        return 0;

    return mazePath(sr + 1, sc, er, ec, ans + 'V') + mazePath(sr, sc + 1, er, ec, ans + "H") + mazePath(sr + 1, sc + 1, er, ec, ans + "D");
}

int mazePathMulti(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }

    int counter = 0;
    for (int v = 1; v + sr <= er; v++)
        counter += mazePathMulti(sr + v, sc, er, ec, ans + 'V' + to_string(v));
    for (int h = 1; h + sc <= ec; h++)
        counter += mazePathMulti(sr, sc + h, er, ec, ans + "H" + to_string(h));
    for (int d = 1; d + sc <= ec && d + sr <= er; d++)
        counter += mazePathMulti(sr + d, sc + d, er, ec, ans + "D" + to_string(d));

    return counter;
}

int printAllPossibleCode(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }

    char ch = str[0];
    int x = ch - '0';
    int count = 0;

    if (x > 0 && x < 10)
    {
        count += printAllPossibleCode(str.substr(1), ans + (char)(x - 1 + 'a'));

        if (str.length() >= 2 && x < 3 && str[1] < '7')
            count += printAllPossibleCode(str.substr(2), ans + (char)((x * 10 + str[1] - '0') - 1 + 'a'));
    }
    else
    {
        count += printAllPossibleCode(str.substr(1), ans);
    }

    return count;
}

void simple()
{
    // cout << subsequence("abc", "") << endl;

    // vs codes = {".", "abc", "def", "gh", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};
    // cout << keyPad("245", codes, "") << endl;

    // cout << stairs(10, 6, "") << endl;
    // cout << mazePath(0, 0, 3, 3, "");
    // cout << mazePathMulti(0, 0, 3, 3, "");
    // cout << printAllPossibleCode("11000023", "") << endl;
}

// TargetAndEquiSet================================================================================

int targetSum(vi &arr, int vidx, int target, string ans)
{
    if (vidx == arr.size())
    {
        if (target == 0)
        {
            cout << (ans) << endl;
            return 1;
        }
        return 0;
    }

    return targetSum(arr, vidx + 1, target - arr[vidx], ans + to_string(arr[vidx]) + " ") + targetSum(arr, vidx + 1, target, ans);
}

int targetSum01(vi &arr, int vidx, int target, vi &ans)
{
    if (vidx == arr.size())
    {
        if (target == 0)
        {
            for (auto i : ans)
                cout << i << " ";

            cout << endl;
            return 1;
        }

        return 0;
    }

    int count = 0;

    ans.push_back(arr[vidx]);
    count += targetSum01(arr, vidx + 1, target - arr[vidx], ans);
    ans.pop_back();

    count += targetSum01(arr, vidx + 1, target, ans);

    return count;
}

int eqiset(vi &arr, int vidx, int setSum1, string set1, int setSum2, string set2)
{
    if (vidx == arr.size())
    {
        if (setSum1 == setSum2)
        {
            cout << (set1 + " = " + set2) << endl;
            return 1;
        }
        return 0;
    }

    return eqiset(arr, vidx + 1, setSum1 + arr[vidx], set1 + to_string(arr[vidx]) + " ", setSum2, set2) + eqiset(arr, vidx + 1, setSum1, set1, setSum2 + arr[vidx], set2 + to_string(arr[vidx]) + " ");
}

int eqisetAvoidReflection(vi &arr, int vidx, int setSum1, string set1, int setSum2, string set2)
{
    if (vidx == arr.size())
    {
        if (setSum1 == setSum2)
        {
            cout << (set1 + " = " + set2) << endl;
            return 1;
        }
        return 0;
    }

    return eqiset(arr, vidx + 1, setSum1 + arr[vidx], set1 + to_string(arr[vidx]) + " ", setSum2, set2) + eqiset(arr, vidx + 1, setSum1, set1, setSum2 + arr[vidx], set2 + to_string(arr[vidx]) + " ");
}

void print(vi &arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
}

int eqiset01(vi &arr, int vidx, int setSum1, vector<int> set1, int setSum2,
             vector<int> set2)
{
    if (vidx == arr.size())
    {
        if (setSum1 == setSum2)
        {
            print(set1);
            cout << (" = ");
            print(set2);
            cout << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;

    set1.push_back(arr[vidx]);
    count += eqiset01(arr, vidx + 1, setSum1 + arr[vidx], set1, setSum2, set2);
    set1.pop_back();

    set2.push_back(arr[vidx]);
    count += eqiset01(arr, vidx + 1, setSum1, set1, setSum2 + arr[vidx], set2);
    set2.pop_back();

    return count;
}

void TargetAndEquiSet()
{
    vi arr = {10, 20, 30, 40, 50, 60, 70};
    // cout << targetSum(arr, 0, 100, "");
    // vi ans;
    // cout << targetSum01(arr, 0, 100, ans);
    cout << eqiset(arr, 0, 0, "", 0, "") << endl;
    cout << eqisetAvoidReflection(arr, 0, 0, "", 0, "") << endl;
    vi set1, set2;
    cout << eqiset01(arr, 0, 0, set1, 0, set2) << endl;
}

// coinChangeVariation=============================================================================================

int coinChangePermutation(vi &arr, int vidx, int target, string ans)
{
    if (target == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < arr.size() && target - arr[i] >= 0; i++)
    {
        count += coinChangePermutation(arr, i, target - arr[i], ans + to_string(arr[i]) + " ");
    }

    return count;
}

int coinChangeCombination(vi &arr, int vidx, int target, string ans) //coinChoice
{
    if (target == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = vidx; i < arr.size() && target - arr[i] >= 0; i++)
    {
        count += coinChangeCombination(arr, i, target - arr[i], ans + to_string(arr[i]) + " ");
    }

    return count;
}

int coinChangeCombinationTargetChoice(vi &arr, int vidx, int target, string ans)
{

    if (target <= 0 || arr.size() == vidx)
    {
        if (target == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    count += coinChangeCombinationTargetChoice(arr, vidx, target - arr[vidx], ans + to_string(arr[vidx]) + " "); // targetAcceptedCoine
    count += coinChangeCombinationTargetChoice(arr, vidx + 1, target, ans);                                      // targetDidn'tAcceptedCoine

    return count;
}

void coinChangeVariation()
{
    vi arr = {2, 3, 5};
    cout << coinChangePermutation(arr, 0, 20, "") << endl;
    cout << coinChangeCombination(arr, 0, 20, "") << endl;
    cout << coinChangeCombinationTargetChoice(arr, 0, 20, "") << endl;
}

//floodFill.=============================================================================================

bool isValid(int sr, int sc, vii &matrix, vii &isdone)
{
    if (sr >= matrix.size() || sc >= matrix[0].size() || sr < 0 || sc < 0 || matrix[sr][sc] || isdone[sr][sc])
        return false;

    return true;
}

int floodfill(int sr, int sc, vii &matrix, vii &isdone, vii &direction, vc &dir, string ans)
{
    if (sr == matrix.size() - 1 && sc == matrix[0].size() - 1)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = 0; i < direction.size(); i++)
    {
        int x = sr + direction[i][0];
        int y = sc + direction[i][1];
        if (isValid(x, y, matrix, isdone))
        {
            isdone[sr][sc] = 1;
            count += floodfill(x, y, matrix, isdone, direction, dir, ans + dir[i]);
            isdone[sr][sc] = 0;
        }
    }

    return count;
}

void floodfillProblem()
{
    vii matrix = {
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0},
    };

    vii isdone(matrix.size(), vi(matrix[0].size(), 0));
    vii direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vc dir = {'d', 'r', 'u', 'l'};

    cout << floodfill(0, 0, matrix, isdone, direction, dir, "") << endl;
}

// CombinationAndPermutation================================================================================

int nQueenPermutation(vector<bool> &boxes, int tnq, int qpsf, string ans)
{
    if (tnq == qpsf)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < boxes.size(); i++)
    {
        if (!boxes[i])
        {
            boxes[i] = true;
            count += nQueenPermutation(boxes, tnq, qpsf + 1, ans + "q" + to_string(qpsf) + "b" + to_string(i));
            boxes[i] = false;
        }
    }

    return count;
}

int nQueenPermutationBitMasking(int boxes, int n, int tnq, int qpsf, string ans)
{
    if (tnq == qpsf)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int mask = 1 << i;
        if ((boxes & mask) == 0)
        {
            boxes |= mask;
            count += nQueenPermutationBitMasking(boxes, n, tnq, qpsf + 1, ans + "q" + to_string(qpsf) + "b" + to_string(i));
            boxes &= ~mask;
        }
    }

    return count;
}

int nQueenCombination(vector<bool> &boxes, int tnq, int qpsf, int lqpsf, string ans)
{
    if (tnq == qpsf)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = lqpsf; i < boxes.size(); i++)
    {
        if (!boxes[i])
        {
            boxes[i] = true;
            count += nQueenCombination(boxes, tnq, qpsf + 1, i + 1, ans + "q" + to_string(qpsf) + "b" + to_string(i));
            boxes[i] = false;
        }
    }
    return count;
}

int nQueenCominationBitMasking(int boxes, int n, int tnq, int qpsf, int lqpsf, string ans)
{
    if (tnq == qpsf)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = lqpsf; i < n; i++)
    {
        int mask = 1 << i;
        if ((boxes & mask) == 0)
        {
            boxes |= mask;
            count += nQueenCominationBitMasking(boxes, n, tnq, qpsf + 1, i + 1, ans + "q" + to_string(qpsf) + "b" + to_string(i));
            boxes &= ~mask;
        }
    }

    return count;
}

int nQueenCommbinationSubsequnece(int cboxes, int tboxes, int qpsf, int tqn, string ans)
{
    if (qpsf == tqn)
    {
        cout << ans << endl;
        return 1;
    }

    if (cboxes == tboxes)
    {
        return 0;
    }

    int count = 0;
    count += nQueenCommbinationSubsequnece(cboxes + 1, tboxes, qpsf + 1, tqn, ans + "q" + to_string(qpsf) + "b" + to_string(cboxes)); //queen palced in that box.
    count += nQueenCommbinationSubsequnece(cboxes + 1, tboxes, qpsf, tqn, ans);                                                       //queen refuse to placed in that box.
    return count;
}

void combinationAndPermutation()
{
    vb boxes(5, false);
    cout << nQueenPermutation(boxes, 3, 0, "") << endl;
    cout << nQueenPermutationBitMasking(0, 5, 3, 0, "") << endl;
    cout << nQueenCombination(boxes, 3, 0, 0, "") << endl;
    cout << nQueenCominationBitMasking(0, 5, 3, 0, 0, "") << endl;
    cout << nQueenCommbinationSubsequnece(0, 5, 0, 3, "") << endl;
}

//nQueenProblems.=================================================================================================

bool isQueenSafe(vbb &arr, int r, int c)
{
    vii dir = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1},
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1},
    };

    for (int rad = 1; rad < arr.size(); rad++)
    {
        for (int i = 0; i < dir.size(); i++)
        {
            int x = r + rad * dir[i][0];
            int y = c + rad * dir[i][1];
            if (x >= 0 && y >= 0 && x < arr.size() && y < arr.size() && arr[x][y])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBoardSafe(vbb &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] && !isQueenSafe(arr, i, j))
            {
                return false;
            }
        }
    }
    return true;
}

int nQueenBoardSafe(vbb &arr, int vidx, int qpsf, string ans)
{
    if (qpsf == arr.size())
    {
        if (isBoardSafe(arr))
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    for (int i = vidx; i < arr.size() * arr[0].size(); i++)
    {
        int x = i / arr[0].size();
        int y = i % arr[0].size();
        if (!arr[x][y])
        {
            arr[x][y] = true;
            count += nQueenBoardSafe(arr, i + 1, qpsf + 1, ans + "(" + to_string(x) + ", " + to_string(y) + ") ");
            arr[x][y] = false;
        }
    }

    return count;
}

int nQueenSubSequence(vbb &arr, int vidx, int qpsf, string ans)
{

    if (vidx == arr.size() * arr[0].size())
    {
        if (qpsf == arr.size())
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;

    count += nQueenSubSequence(arr, vidx + 1, qpsf, ans);

    int x = vidx / arr[0].size();
    int y = vidx % arr[0].size();
    if (!arr[x][y] && isQueenSafe(arr, x, y))
    {
        arr[x][y] = true;
        count += nQueenSubSequence(arr, vidx + 1, qpsf + 1, ans + "(" + to_string(x) + ", " + to_string(y) + ") ");
        arr[x][y] = false;
    }

    return count;
}

int nQueenSimple(vbb &arr, int vidx, int qpsf, string ans)
{
    if (qpsf == arr.size())
    {
        if (isBoardSafe(arr))
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    for (int i = vidx; i < arr.size() * arr[0].size(); i++)
    {
        int x = i / arr[0].size();
        int y = i % arr[0].size();
        if (!arr[x][y] && isQueenSafe(arr, x, y))
        {
            arr[x][y] = true;
            count += nQueenSimple(arr, i + 1, qpsf + 1, ans + "(" + to_string(x) + ", " + to_string(y) + ") ");
            arr[x][y] = false;
        }
    }

    return count;
}

void nQueenProblems()
{

    vbb arr(4, vb(4, false));
    cout << nQueenBoardSafe(arr, 0, 0, "Queen: ") << endl;
    cout << nQueenSubSequence(arr, 0, 0, "Queen: ") << endl;
    cout << nQueenSimple(arr, 0, 0, "Queen: ") << endl;
}

// nKnigth.================================================================================================

bool isKnightSafe(vbb &arr, int r, int c)
{
    vii dirc = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

    for (int i = 0; i < dirc.size(); i++)
    {
        int x = r + dirc[i][0];
        int y = c + dirc[i][1];

        if (x >= 0 && y >= 0 && x < arr.size() && y < arr[0].size() && arr[x][y])
        {
            return false;
        }
    }

    return true;
}

int nKnightSimple(vbb &arr, int vidx, int nkpsf, string ans)
{
    if (vidx == arr.size() * arr[0].size())
    {
        if (nkpsf == 2 * arr.size())
        {
            for (auto ar : arr)
            {
                for (bool i : ar)
                {
                    cout << i << " ";
                }
                cout << endl;
            }

            cout << (ans) << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    for (int i = vidx; i < arr.size() * arr[0].size(); i++)
    {

        int r = i / arr[0].size();
        int c = i % arr[0].size();

        if (!arr[r][c] && isKnightSafe(arr, r, c))
        {

            arr[r][c] = true;
            count += nKnightSimple(arr, i + 1, nkpsf + 1, ans + "(" + to_string(r) + ", " + to_string(c) + ") ");
            arr[r][c] = false;
        }
    }

    return count;
}

int nKnightSubsequnece(vbb &arr, int bno, int nkpsf, string ans)
{
    if (bno == arr.size() * arr[0].size())
    {
        if (nkpsf == 2 * arr.size())
        {
            for (auto ar : arr)
            {
                for (bool i : ar)
                {
                    cout << i << " ";
                }
                cout << endl;
            }

            cout << (ans) << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;

    int r = bno / arr[0].size();
    int c = bno % arr[0].size();

    count += nKnightSubsequnece(arr, bno + 1, nkpsf, ans);

    if (!arr[r][c] && isKnightSafe(arr, r, c))
    {
        arr[r][c] = true;
        count += nKnightSubsequnece(arr, bno + 1, nkpsf + 1, ans + "(" + to_string(r) + ", " + to_string(c) + ") ");
        arr[r][c] = false;
    }

    return count;
}

void nKnight()
{
    vbb arr(4, vb(4, 0));
    cout << nKnightSimple(arr, 0, 0, "") << endl;
    // cout << nKnightSubsequnece(arr, 0, 0, "") << endl;
}

void solve()
{
    //    simple();
    //   TargetAndEquiSet();
    coinChangeVariation();
    // combinationAndPermutation();
    // nQueenProblems();
    // nKnight();
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}