#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <sstream>
using namespace std;
const int N = 100;
int m[N][N], s[N][N];
void PrintAnswer(int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        PrintAnswer(i, s[i][j]);
        PrintAnswer(s[i][j] + 1, j);
        cout << ")";
    }
}
void Matrix_Multi(int *p, int length)

{
    int n = length - 1;
    int l, i, j, k, q = 0;
    //m[i][i]只有一个矩阵，相乘次数为零，所以m[i][i]=0
    for (i = 1; i < length; i++)
    {
        m[i][j] = 0;
    }
    for (l = 2; l <= n; l++) //宽度从2到n
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1; //以i为起始位，j为末位，长度为l
            m[i][j] = 0x7fffffff;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void inPut()
{
    int t;
    int i = 1;
    while (cin>>t)
    {
        int x[t+1];
        for(int k=0;k<=t;k++)
        {
            cin>>x[k];
        }
        Matrix_Multi(x, t + 1);
        cout << "Case " << i << endl;
        i++;
        cout << m[1][t] << " ";
        PrintAnswer(1, t);
        cout << endl;
    }
}
int main()
{
    inPut();
    return 0;
}