#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <sstream>
#include <set>
#include <iomanip>
using namespace std;

int c[100][100];
int d[100][100];
set<string> setOfLCS;

string Reverse(string str)
{
    int low = 0;
    int high = str.length() - 1;
    while (low < high)
    {
        char temp = str[low];
        str[low] = str[high];
        str[high] = temp;
        ++low;
        --high;
    }
    return str;
}

void LCSLength(int m, int n, char *x, char *y)
{
    int i, j;
    for (i = 1; i <= m; i++)
        c[i][0] = 0;
    for (i = 1; i <= n; i++)
        c[0][i] = 0;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i] == y[j])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                d[i][j] = 1;
            }
            else if (c[i - 1][j] > c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                d[i][j] = 2;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                d[i][j] = 3;
            }
        }
    }
}
void traceBack(int i, int j, char *x, char *y, string lcs_str)
{
    while (i > 0 && j > 0)
    {
        if (x[i] == y[j])
        {
            lcs_str.push_back(x[i]);
            --i;
            --j;
        }
        else
        {
            if (c[i - 1][j] > c[i][j - 1])
                --i;
            else if (c[i - 1][j] < c[i][j - 1])
                --j;
            else
            {
                traceBack(i - 1, j, x, y, lcs_str);
                traceBack(i, j - 1, x, y, lcs_str);
                return;
            }
        }
    }
    setOfLCS.insert(Reverse(lcs_str));
}

void LCS(int i, int j, char *x)
{
    if (i == 0 || j == 0)
        return;
    if (d[i][j] == 1)
    {
        LCS(i - 1, j - 1, x);
        cout << x[i];
    }
    else if (d[i][j] == 2)
        LCS(i - 1, j, x);
    else
        LCS(i, j - 1, x);
}

int main()
{
    int T, m, n, times = 1;
    char s1[100], s2[100];
    cin >> T;

    cout << endl;
    while (T--)
    {
        cout << "case:" << times << endl;
        cin >> m >> n;
        for (int i = 1; i <= m; i++)
            cin >> s1[i];
        for (int i = 1; i <= n; i++)
            cin >> s2[i];
        cout << "Case " << times++ << endl;
        LCSLength(m, n, s1, s2);
        cout << c[m][n] << " ";
        cout << "LCS(X,Y):";
        cout << endl;
        string str;
        setOfLCS.clear();
        traceBack(m, n, s1, s2, str);
        set<string>::iterator beg = setOfLCS.begin();
        for (; beg != setOfLCS.end(); ++beg)
        {
            for (int i = 0; i < (*beg).length(); i++)
            {
                cout << setw(2) << (*beg)[i];
            }
            cout << endl;
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                cout << c[j][i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}