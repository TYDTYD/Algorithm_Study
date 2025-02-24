#include <string>
#include <vector>

using namespace std;

int timeChange(int time){
    return 60*(time/100)+time%100;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int num=schedules.size();
    bool success[1001];
    
    for(int i=0; i<num; i++)
        success[i]=true;
    
    int start=startday;
    
    for(int i=0; i<num; i++){
        for(int j=0; j<7; j++){
            if(start%7==6 || start%7==0){
                start++;
                continue;
            }
            if(timeChange(timelogs[i][j])>timeChange(schedules[i])+10)
                success[i]=false;
            start++;
        }
        start=startday;
    }
    
    for(int i=0; i<num; i++){
        if(success[i])
            answer++;
    }
    
    return answer;
}