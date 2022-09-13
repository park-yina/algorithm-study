#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int i;
    for(i = 0; i < s.size(); i++) {
        if(!(isdigit(s[i]))||s.size()!=4&&s.size()!=6)answer=false;
    }
    return answer;
}
