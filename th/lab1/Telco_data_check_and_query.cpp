#include<bits/stdc++.h>
using namespace std;
bool check(string str){
    for(auto c:str){
        if(isdigit(c)==0)return false;
    }
    return true;
}
int cal(string a,string b){
    int ha=stoi(a.substr(0,2));
    int ma=stoi(a.substr(3,2));
    int sa=stoi(a.substr(6,2));
    int hb=stoi(b.substr(0,2));
    int mb=stoi(b.substr(3,2));
    int sb=stoi(b.substr(6,2));
    return -1*(ha*3600+ma*60+sa-hb*3600-mb*60-sb);

}
int main(){
    freopen("d:\\DT\\Learn\\20251\\ThuatToanUngDung\\on_tap_ttud\\input.txt", "r", stdin);
    int chck=1;
    map<string,pair<int,int>>m;
    string cmd,fn,tn,d,ft,et;
    int cnt=0;
    while(true){
        cin>>cmd;
        if(cmd=="#")break;
        cin>>fn>>tn>>d>>ft>>et;
        if(check(fn)==0||check(tn)==0)chck=0;
        else cnt++;

        if(m.find(fn)!=m.end()){
            m[fn].first+=1;
            m[fn].second+=cal(ft,et);
        }else{
            m[fn].first=1;
            m[fn].second=cal(ft,et);
        }
    }
    string tmp;
    while(true){
        cin>>cmd;
        if(cmd=="#")break;
        if(cmd=="?check_phone_number")cout<<chck<<endl;
        else if(cmd=="?number_calls_from"){
            cin>>tmp;
            cout<<m[tmp].first<<endl;
        }
        else if(cmd=="?number_total_calls")cout<<cnt<<endl;
        else {
            cin>>tmp;
            cout<<m[tmp].second<<endl;
        }
    }
}