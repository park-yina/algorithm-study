#include <string>
#include <vector>
#include <stack>
using namespace std;
bool is_correct(string input){
    stack<char>c;
    for(int i=0;i<(int)input.length();i++){
        if(input[i]=='('){
            c.push('(');
        }
        else{
            if(c.size()==0){
                return false;
            }
            c.pop();
        }
    }
    if(c.size()>0){
        return false;
    }
    return true;
}
string solution(string p) {
    string answer = "";
    if(p=="")
        return "";
    string u,v;
    int right=0,left=0;
    for(int i=0;i<(int)p.length();i++){
        if(p[i]=='(')left++;
        else if(p[i]==')')right++;
        
        if(left==right){
            u=p.substr(0,i+1);
            v=p.substr(i+1);
            break;//u와 v 분리까지 완료
        }
    }
    if(is_correct(u)){
        v=solution(v);
        answer=u+v;//u에 이어붙여 반환하기 위함
        return answer;
    }
    else{
        answer="(";
        answer=answer+solution(v);//v에 대해 1단계부터 재귀적 수행 결과 붙이기
        answer=answer+')';
        u.erase(0,1);
        u.erase(u.length()-1,1);
        for(int i=0;i<(int)u.length();i++){
        if(u[i]=='(')
            answer=answer+')';
        else if(u[i]==')')
            answer=answer+'(';
    }
    return answer;
    }
}
