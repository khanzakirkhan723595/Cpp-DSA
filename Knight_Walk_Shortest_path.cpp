#include<bits/stdc++.h>
using namespace std;

int row[8]={2,2,-2,-2,1,-1,1,-1};
    int col[8]={1,-1,1,-1,2,2,-2,-2};
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
        // Code here
        queue<pair<int,int>> q;
        vector<vector<bool>> chess(N,vector<bool>(N,false));
        KnightPos[0]--;
        KnightPos[1]--;
        TargetPos[0]--;
        TargetPos[1]--;
        if(TargetPos[0]==KnightPos[0] && TargetPos[1]==KnightPos[1] )
        {
            return 0;
        }
        q.push({KnightPos[0],KnightPos[1]});
        chess[KnightPos[0]][KnightPos[1]]=true;
        int step=0;
        while(!q.empty())
        {
            int qsize=q.size();
            while(qsize--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<8;k++)
                {
                    int ni=i+row[k];
                    int nj=j+col[k];
                    if(ni>=0 && nj>=0 && ni<N && nj<N && !chess[ni][nj])
                    {
                        if(ni==TargetPos[0] && nj==TargetPos[1])
                        {
                            return step+1;
                        }
                        
                        chess[ni][nj]=true;
                        q.push({ni,nj});
                    }
                }
            }
            step++;
        }
        return -1;
        
    }

    int main()
    {
        int N=8;
        vector<vector<int>> A(N,vector<int>(N,0));
        vector<int> KnightPos={7,7};
        vector<int> TargetPos={1,5};
        cout<<"No. of steps: "<<minStepToReachTarget(KnightPos,TargetPos,N)<<endl; 
    }