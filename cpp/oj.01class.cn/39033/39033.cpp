#include<bits/stdc++.h>
using namespace std;
int main(){
    int p1,p2,p3;
    cin>>p1>>p2>>p3;
    string s;
    cin>>s;
    for(int i=1; i+1<s.size(); i++){
        if(s[i]=='-'){
            if(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a'||s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'){
                // cout<<s[i-1]<<' '<<s[i+1]<<endl;
                if(s[i-1]<s[i+1]){
                    string output="";
                    // cout<<s[i-1]<<' '<<s[i+1]<<endl;
                    for(char j=s[i-1]+1; j<s[i+1]; j++){
                        for(int k=0; k<p2; k++){
                            if(p1==1||s[i-1]=='2'){
                                p3==1?output+=j:output=j+output;
                            }else if(p1==2){
                                p3==1?output+=(char)(j+'A'-'a'):output=(char)(j+'A'-'a')+output;
                            }else{
                                output+='*';
                            }
                        }
                    }
                    // if(s[i-1]=='2'&&s[i+1]=='4') cout<<output<<endl;
                    s.replace(i,1,output);
                }
                // cout<<"-----"<<endl;
            }
        }
    }
    cout<<s<<endl;
}