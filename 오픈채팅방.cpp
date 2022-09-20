#include <string>
#include <vector>
#include <unordered_map>
#include<sstream>
using namespace std;
unordered_map<string,string>user_nick;
vector<pair<string,string>>result;
vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(int i=0;i<record.size();i++){
        string input,id,nick_name;
        stringstream sstream;
        sstream.str(record[i]);
        sstream>>input>>id>>nick_name;
        if(input=="Enter"){
            user_nick[id]=nick_name;
            result.push_back(make_pair(id,"들어왔습니다."));
        }
        else if(input=="Leave")
            result.push_back(make_pair(id,"나갔습니다."));
       else if(input=="Change")
           user_nick[id]=nick_name;
    }
        for(int i=0;i<result.size();i++){
            answer.push_back(user_nick[result[i].first]+"님이 "+result[i].second);
        }
    return answer;
}
