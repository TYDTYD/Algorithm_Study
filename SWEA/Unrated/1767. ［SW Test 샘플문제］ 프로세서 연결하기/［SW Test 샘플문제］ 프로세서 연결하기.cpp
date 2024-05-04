#include<iostream>
#include <algorithm>
#define INF 1000000
using namespace std;

pair<int,int> corePos[20];
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}, n, result[20]={}, len=0;
int v[13][13]={};

bool isPass(int dir, int x, int y, int v[13][13]){
    int c=0;
	while(x!=n-1 && y!=n-1 && x!=0 && y!=0){
        x+=dx[dir];
        y+=dy[dir];
        len++;
        c++;
        if(v[x][y]){
            c--;
            len--;
            while(c!=0){
                x-=dx[dir];
                y-=dy[dir];
                len--;
                c--;
                v[x][y]=0;
            }
            return false;
        }
        v[x][y]=1;
    }
    return true;
}

void recur(int num, int count, int size, int v[13][13]){
    result[num]=min(len,result[num]);
    if(count==size)
        return;
    int initLen=len;
    int store[13][13]={};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            store[i][j]=v[i][j];
    }
    for(int i=0; i<5; i++){
        if(i!=4){
            if(isPass(i,corePos[count].first,corePos[count].second,v)){
                recur(num+1,count+1,size,v);
                len=initLen;
            }
            else
                continue;
        }
        else{
            recur(num,count+1,size,v);
        }
        for(int i=0; i<n; i++){
        	for(int j=0; j<n; j++){
            	v[i][j]=store[i][j];
        	}
    	}
        len=initLen;
    }
    return;
}

int main(int argc, char** argv)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        len=0;
        v[13][13]={};
        for(int i=0; i<20; i++){
            corePos[i].first=0;
            corePos[i].second=0;
        }
        fill(result,result+20,INF);
        int posNum=0;
		cin >> n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
            	cin >> v[i][j];
                if(v[i][j]){
                	if(i!=0 && i!=n-1 && j!=0 && j!=n-1)
                    	corePos[posNum++]={i,j};
                }
            }
        }
        recur(0,0,posNum,v);
        int answer=INF;
        for(int i=posNum; i>=0; i--){
            if(result[i]==INF)
                continue;
            else{
                answer=result[i];
                break;
            }
        }
        
        if(answer==INF)
            answer=0;
        cout << '#' << test_case << " " << answer << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}