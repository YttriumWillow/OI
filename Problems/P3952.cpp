#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        cin.ignore();
        string s[103];
        getline(cin,s[0]);
        int ans=0,sum=0;
        stack<char>t;
        bool used[27];
        memset(used,false,sizeof(used));
        bool flag=1;
        for(int i=1;i<=n;i++){
            getline(cin,s[i]);
            if(s[i][0]=='E'){
                if(t.empty()){
                    cout<<"ERR"<<endl;
                    goto it;
                }
                else{
                    used[t.top()]=0;
                    t.pop();
                }
            }
            else{
                if(!used[s[i][2]]){
                    t.push(s[i][2]);
                    used[s[i][2]]=1;
                    if(s[i][4]!='n'){
                        if(s[i][5]==' '){
                            if(s[i][7]==' '&&s[i][4]>s[i][6])flag=0;
                            else if(s[i][6]=='n'&&flag)sum++;
                        }
                        else{
                            if(s[i][7]=='n'&&flag)sum++;
                            else{
                                string b(s[i],4,2);string c(s[i],7,2);
                                if(b>c)flag=0; 
                            }
                        }
                    }
                    else if(s[i][6]!='n')flag=0;
                }
                else{
                    cout<<"ERR"<<endl;
                    goto it;
                }
            }
            if(t.empty()){
                ans=max(ans,sum);
                sum=0;
                flag=1;
            }
        }
        if(!t.empty()){
            cout<<"ERR"<<endl;
            goto it;
        }
        if(ans==0){
            if(s[0][2]!='n')cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else {
            if(ans<10){
            if(ans==s[0][4]-'0')cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            }
            else if(ans/10==s[0][4]-'0'&&ans%10==s[0][5]-'0')cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        it:;
    }
    return 0;
}