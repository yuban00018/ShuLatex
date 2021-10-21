#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int tile;
int board[100][100];

void chessBoard(int tr,int tc,int dr,int dc,int size){
    if(size==1)
        return;
    int t=tile++;
    int s=size/2;
    if(dr<tr+s&&dc<tc+s)
        chessBoard(tr,tc,dr,dc,s);
    else
    {
        board[tr+s-1][tc+s-1]=t;
        chessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }
    if(dr<tr+s&&dc>=tc+s)
        chessBoard(tr,tc+s,dr,dc,s);
    else
    {
        board[tr+s-1][tc+s]=t;
        chessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }
    if(dr>=tr+s&&dc<tc+s)
        chessBoard(tr+s,tc,dr,dc,s);
    else
    {
        board[tr+s][tc+s-1]=t;
        chessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }
    if(dr>=tr+s&&dc>=tc+s)
        chessBoard(tr+s,tc+s,dr,dc,s);
    else
    {
        board[tr+s][tc+s]=t;
        chessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }
}

int main()
{
    int k,n=0;
    int index_x,index_y;
    while(cin>>k>>index_x>>index_y)
    {
        n++;
        tile=1;
        int size=int(pow(2,k));
        chessBoard(0,0,index_x-1,index_y-1,size);
        cout<<"Case "<<n<<": \n"<<"n="<<size<<endl;

        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++){
                k=board[i][j];
                if (k==0){
                    cout<<setw(4)<<"#";
                }else{
                    cout<<setw(4)<<board[i][j];
                }
            }
            cout<<endl;
        }
    }

    return 0;
}