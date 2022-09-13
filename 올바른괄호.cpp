#include<string>
#include <iostream>
#include <queue>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    queue<char>q;
    for(char&c:s){
        if(c=='(')
            q.push(c);
        else{
            if(q.empty())return false;
            else
                q.pop();
        }
        if(q.empty())answer=true;
        else
            answer=false;
    }

    return answer;
}
