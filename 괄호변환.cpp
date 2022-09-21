#include <string>
#include <vector>
#include <stack>
using namespace std;
int left,right;
bool is_correct(string input){
   stack<char>c;
    for(int i=0;i<(int)input.length();i++){
        if(input[i]=='('){
            c.push('(');
        }
        else{
            if(c.size()==0){return false;
            
        }
        c.pop();
    }
}
if(c.size()>0)
    return false;
return true;
}
string solution(string p) {
    string answer="";
    if(p=="")return "";
    string u,v;
    for(int i=0;i<p.length();i++){
        if(p[i]=='(')left++;
        else if(p[i]==')')right++;
        if(left==right){
            u=p.substr(0,i+1);
            v=p.substr(i+1);
            break;
        }
    }
        if(is_correct(u)){
            v=solution(v);
            answer=u+v;
            return answer;//수행한 결과를 문자열 u에 이어붙이고 반환한다.
    }
        else if(!is_correct(u))//else로 처리해주었어도 되는 부분{
            answer="(";
            answer+=solution(v);
            answer+=")";
            u.erase(0,1);
            u.erase(u.length()-1,1);
            for(int i=0;i<(int)u.length();i++){
                if(u[i]=='(')
                   answer+=')';
                else if(u[i]==')')
                    answer+='(';
                
            }
        return answer;
        }
}
