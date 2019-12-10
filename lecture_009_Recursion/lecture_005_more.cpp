#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

#define vc vector<char>
#define vcc vector<vc>

#define vb vector<bool>

#define vs vector<string>

#define ll long long int

//===============================================================================

bool isSafeToPlaceNumber(vii &board, int r, int c, int num)
{

    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][c] == num)
            return false;
    }

    for (int i = 0; i < board.size(); i++)
    {
        if (board[r][i] == num)
            return false;
    }

    int cr = (r / 3) * 3;
    int cc = (c / 3) * 3;
    for (int i = cr; i < cr + 3; i++)
    {
        for (int j = cc; j < cc + 3; j++)
        {
            if (board[i][j] == num)
                return false;
        }
    }
}

bool sudoku(vii &board, int bno)
{
    if (bno == board.size() * board[0].size())
    {
        for (auto i : board)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    int r = bno / board[0].size();
    int c = bno % board[0].size();

    bool res = false;

    if (board[r][c] == 0)
    {
        for (int num = 1; num <= 9; num++)
        {
            if (isSafeToPlaceNumber(board, r, c, num))
            {
                board[r][c] = num;
                res = res || sudoku(board, bno + 1);
                board[r][c] = 0;
            }
        }
    }
    else
    {
        res = res || sudoku(board, bno + 1);
    }

    return res;
}

bool isSafeToPlaceNumBit(vi &row, vi &col, vii &mat, int r, int c, int num)
{
    int mask = 1 << num;
    return (((row[r] & mask) == 0) && ((col[c] & mask) == 0) && ((mat[r / mat.size()][c / mat.size()] & mask) == 0));
}

bool sudokuBit(vii &board, int bno, vi &row, vi &col, vii &mat)
{
    if (bno == board.size() * board[0].size())
    {
        for (auto i : board)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    int r = bno / board[0].size();
    int c = bno % board[0].size();

    bool res = false;

    if (board[r][c] == 0)
    {
        for (int num = 1; num <= 9; num++)
        {
            if (isSafeToPlaceNumber(board, r, c, num))
            {
                int mask = 1 << num;
                board[r][c] = num;

                row[r] |= mask;
                col[c] |= mask;
                mat[r / mat.size()][c / mat.size()] |= mask;

                res = res || sudoku(board, bno + 1);

                board[r][c] = 0;

                row[r] ^= mask;
                col[c] ^= mask;
                mat[r / mat.size()][c / mat.size()] ^= mask;
            }
        }
    }
    else
    {
        res = res || sudoku(board, bno + 1);
    }

    return res;
}

int sudoku_02(vector<vector<int>> &boxe, vector<pair<int, int>> zeros, int bno)
{
    if (bno == zeros.size())
    {
        display(boxe);
        return 1;
    }

    int count = 0;
    for (int num = 1; num <= 9; num++)
    {
        int r = zeros[bno].first;
        int c = zeros[bno].second;

        if (isValidToPlaceNumber(boxe, num, r, c))
        {
            boxe[r][c] = num;
            count += sudoku_02(boxe, zeros, bno + 1);
            boxe[r][c] = 0;
        }
    }

    return count;
}

int sudoku_03(vector<vector<int>> &boxe, vector<pair<int, int>> zeros, int num, int bno)
{
    if (bno == zeros.size())
    {
        display(boxe);
        return 1;
    }

    if (num > 9)
        return 0;

    int count = 0;
    int r = zeros[bno].first;
    int c = zeros[bno].second;

    if (isValidToPlaceNumber(boxe, num, r, c))
    {
        boxe[r][c] = num;
        count += sudoku_03(boxe, zeros, 1, bno + 1);
        boxe[r][c] = 0;
    }
    
        count += sudoku_03(boxe, zeros, num + 1, bno);

    return count;
}


void sudokuProblem()
{
    vii board = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                 {5, 2, 0, 0, 0, 0, 0, 0, 0},
                 {0, 8, 7, 0, 0, 0, 0, 3, 1},
                 {0, 0, 3, 0, 1, 0, 0, 8, 0},
                 {9, 0, 0, 8, 6, 3, 0, 0, 5},
                 {0, 5, 0, 0, 9, 0, 6, 0, 0},
                 {1, 3, 0, 0, 0, 0, 2, 5, 0},
                 {0, 0, 0, 0, 0, 0, 0, 7, 4},
                 {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    sudoku(board, 0);

    vi row(board.size(), 0), col(board.size(), 0);
    vii mat(board.size() / 3, vi(board.size() / 3, 0));

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (j != 0)
            {
                int mask = 1 << board[i][j];

                row[i] ^= mask;
                col[j] ^= mask;
                mat[i / mat.size()][j / mat.size()] ^= mask;
            }
        }
    }

    sudokuBit(board, 0, row, col, mat);


    vector<pair<int, int>> zeros;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (boxe[i][j] == 0)
            {
                zeros.push_back({i, j});
            }
        }
    }

    // cout << sudoku_02(boxe, zeros, 0)<<endl;
    // cout << sudoku_03(boxe, zeros, 1, 0) << endl;

}

//===============================================================================

bool canPlaceHorizontally(vcc &board, string word, int r, int c)
{

    if (c + word.length() > board[0].size())
        return false;

    for (int i = 0; i < word.length(); i++)
    {
        if ((board[r][c + i] != '-') && (board[r][c + i] != word[i]))
        {
            return false;
        }
    }
    return true;
}

int placeHorizontally(vcc &board, string word, int r, int c)
{
    int reset = 0;
    for (int i = 0; i < word.length(); i++)
    {
        if (board[r][c + i] == '-')
        {
            reset |= 1 << i;
            board[r][c + i] = word[i];
        }
    }

    return reset;
}

void unPlaceHorizontally(vcc &board, string word, int r, int c, int reset)
{
    for (int i = 0; i < word.length(); i++)
    {
        if ((reset & (1 << i)) == (1 << i))
            board[r][c + i] = '-';
    }
}

bool canPlaceVertically(vcc &board, string word, int r, int c)
{
    if (r + word.length() > board.size())
        return false;

    for (int i = 0; i < word.length(); i++)
    {
        if ((board[r + i][c] != '-') && (board[r + i][c] != word[i]))
        {
            return false;
        }
    }
    return true;
}

int placeVertically(vcc &board, string word, int r, int c)
{
    int reset = 0;
    for (int i = 0; i < word.length(); i++)
    {
        if (board[r + i][c] == '-')
        {
            reset |= 1 << i;
            board[r + i][c] = word[i];
        }
    }

    return reset;
}

void unPlaceVertically(vcc &board, string word, int r, int c, int reset)
{
    for (int i = 0; i < word.length(); i++)
        if ((reset & (1 << i)) == (1 << i))
            board[r + i][c] = '-';
}

bool crossWord(vcc &board, vs &words, int widx)
{
    if (widx == words.size())
    {
        for (auto i : board)
        {
            for (auto j : i)
                cout << j << " ";
            cout << endl;
        }
        cout << endl;

        return true;
    }

    bool res = false;
    string word = words[widx];
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '-' || board[i][j] == word[0])
            {
                if (canPlaceHorizontally(board, word, i, j))
                {

                    int reset = placeHorizontally(board, word, i, j);
                    res = res || crossWord(board, words, widx + 1);
                    unPlaceHorizontally(board, word, i, j, reset);
                }

                if (canPlaceVertically(board, word, i, j))
                {
                    int reset = placeVertically(board, word, i, j);
                    res = res || crossWord(board, words, widx + 1);
                    unPlaceVertically(board, word, i, j, reset);
                }
            }
        }
    }

    return res;
}

void crossWordProblem()
{

    vcc boards = {
        {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
        {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
        {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
        {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
        {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
        {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
        {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
        {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
        {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
        {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};

    vs words = {"agra", "norway", "england", "gwalior"};
    crossWord(boards, words, 0);
}

//Crypto==========================================================================================

int getNumberAgainstString(string &str, vi &freqMap)
{
    int ans = 0;
    int pow = 1;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        ans += freqMap[str[i] - 'a'] * pow;
        pow *= 10;
    }
    return ans;
}

bool cryptoCheck(string &str1, string &str2, string &str3, vi &freqMap)
{

    int one = getNumberAgainstString(str1, freqMap);
    int two = getNumberAgainstString(str2, freqMap);
    int three = getNumberAgainstString(str3, freqMap);

    int start1 = freqMap[str1[0] - 'a'];
    int start2 = freqMap[str2[0] - 'a'];
    int start3 = freqMap[str3[0] - 'a'];

    if ((one + two == three) && start1 != 0 && start2 != 0 && start3 != 0)
    {
        cout << " " + to_string(one) + "\n+" + to_string(two) + "\n";
        for (int i = 0; i < str3.length(); i++)
            cout << "-";

        cout << "\n" + to_string(three) + "\n"
             << endl;
        return true;
    }

    return false;
}

int crypto(string &str1, string &str2, string &str3, string ques, int bitmask, vi &freqMap)
{

    if (ques.length() == 0)
    {
        if (cryptoCheck(str1, str2, str3, freqMap))
            return 1;

        return 0;
    }

    int count = 0;
    for (int bit = 9; bit >= 0; bit--)
    {
        if (((bitmask & (1 << bit)) == 0))
        {
            char ch = ques[0];
            bitmask |= 1 << bit;
            freqMap[ch - 'a'] = bit;
            count += crypto(str1, str2, str3, ques.substr(1), bitmask, freqMap);
            bitmask ^= 1 << bit;
            freqMap[ch - 'a'] = 0;
        }
    }

    return count;
}

void CryptoProblem()
{
    string str1 = "send";
    string str2 = "more";
    string str3 = "money";

    int freqMap[26] = {0};

    for (int i = 0; i < str3.length(); i++)
    {
        if (i < str1.length())
            freqMap[str1[i] - 'a']++;

        if (i < str2.length())
            freqMap[str2[i] - 'a']++;

        freqMap[str3[i] - 'a']++;
    }
    string sb;
    for (int i = 0; i < 26; i++)
    {
        if (freqMap[i] > 0)
            sb.push_back((char)(i + 'a'));
    }
    // cout << sb << endl;

    vi freqmap(26, 0);
    int bitMask = 0;
    cout << crypto(str1, str2, str3, sb, bitMask, freqmap);
}



void solve()
{

    // sudokuProblem();
    // crossWordProblem();
    CryptoProblem();
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}
