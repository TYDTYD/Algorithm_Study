#include <string>
#include <vector>
#include <queue>

using namespace std;

void AddOutSide(int x, int y, int height, int width, bool outside[51][51], bool removed[51][51]){
    int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
    queue<pair<int,int>> q;
    bool visited[51][51];
    for(int i=0; i<height; i++)
        fill(visited[i], visited[i]+width, false);
    q.push({x,y});
    visited[x][y]=true;
    
    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = p.first+dx[i];
            int ny = p.second+dy[i];
            if(nx<0 || nx>=height || ny<0 || ny>=width)
                continue;
            if(visited[nx][ny])
                continue;
            outside[nx][ny]=true;
            if(!removed[nx][ny])
                continue;
            visited[nx][ny]=true;
            q.push({nx,ny});
        }
    }
    return;
}

int Count_First(vector<string>& storage, char container, bool outside[51][51], bool removed[51][51]){
    int h = storage.size(), w = storage[0].size();
    int count = 0;
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(removed[i][j])
                continue;
            if(storage[i][j] == container && outside[i][j]){
                removed[i][j]=true;
                count++;
            }
        }
    }
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(outside[i][j] && removed[i][j])
                AddOutSide(i,j,h,w,outside,removed);
        }
    }
    
    return count;
}

int Count_Second(vector<string>& storage, char container, bool outside[51][51], bool removed[51][51]){
    int h = storage.size(), w = storage[0].size();
    int count = 0;
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(removed[i][j])
                continue;
            if(storage[i][j] == container){
                removed[i][j]=true;
                count++;
            }
        }
    }
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(outside[i][j] && removed[i][j])
                AddOutSide(i,j,h,w,outside,removed);
        }
    }
    
    return count;
}

int solution(vector<string> storage, vector<string> requests) {
    int h = storage.size(), w = storage[0].size();
    bool outside[51][51], removed[51][51];
    int answer = h * w;
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            removed[i][j]=false;
            if(i==0 || i==h-1 || j==0 || j==w-1)
                outside[i][j]=true;
            else
                outside[i][j]=false;
        }
    }
    
    for(const auto& r:requests){
        if(r.length()==1)
            answer-=Count_First(storage, r[0], outside, removed);
        else
            answer-=Count_Second(storage, r[0], outside, removed);
    }
    return answer;
}