#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> point;

struct cmp{
    bool operator()(point& x,point& y){
        return x.second > y.second;
    }
};

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    int size = road.size();
    vector<vector<point>> points(N+1);
    int dist[51];
    
    fill(dist,dist+N+1,1e9);
    
    for(int i=0; i<size; i++){
        points[road[i][0]].push_back({road[i][1],road[i][2]});
        points[road[i][1]].push_back({road[i][0],road[i][2]});
    }
    
    priority_queue<point,vector<point>,cmp> pq;
    dist[1]=0;
    pq.push({1,0});
    
    while(!pq.empty()){
        point cur=pq.top();
        pq.pop();
        if(dist[cur.first]<cur.second)
            continue;
        for(const auto& point:points[cur.first]){
            int next=point.first;
            int cost=point.second + cur.second;
            if(cost<dist[next]){
                dist[next]=cost;
                pq.push({next,cost});
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        if(dist[i]<=K)
            answer++;
    }

    return answer;
}