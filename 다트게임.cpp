#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int pre=0,score=0;
    for(int i=0;i<dartResult.size();i++){
        if(isdigit(dartResult[i])){
            pre=score;
            if(dartResult[i+1]=='0'){
           
            score=10;
            i++;
            }
            else
                score=dartResult[i]-'0';
        }
        else if(dartResult[i]=='T'||dartResult[i]=='D'||dartResult[i]=='S'){
            if(dartResult[i]=='T')
                score=pow(score,3);
            else if(dartResult[i]=='D')
                score=pow(score,2);
            else if(dartResult[i]=='S')
                score=pow(score,1);
       if(dartResult[i+1]=='*'){
            answer-=pre;
            pre*=2;
            score*=2;
            i++;
            answer+=pre;
        }
        else if(dartResult[i+1]=='#'){
            score*=-1;
            i++;
        }
        answer+=score;
    }
    }
    return answer;
}
