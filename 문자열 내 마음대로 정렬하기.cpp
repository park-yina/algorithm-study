#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int th;
bool comp(string a,string b){
    if(a[th]==b[th])return a<b;
    else{
        return a[th]<b[th];
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    th=n;
    sort(strings.begin(),strings.end(),comp);
    answer=strings;
    return answer;
}
