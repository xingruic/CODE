#include<bits/stdc++.h>
using namespace std;
int main(){
    string t="DENNISNELLEDNALEONNEDRAANITAROLFNORAALICECAROLLEOJANEREEDDENADALEBASILRAEPENNYLANADAVEDENNYLENAIDABERNADETTEBENRAYLILANINAJOIRAMARASARAMARIOJANINALILYARNEBETTEDANREBADIANELYNNEDEVADANALYNNEPEARLISABELADANEDDEERENAJOELLORACECILAARONFLORATINAARDENNOELANDELLENSINNED";
    string s="#";
    for(int i=0; i<t.size(); i++){
        s+=t[i];
        s+='#';
    }
    int ans=0;
    for(int i=0; i<s.size(); i++){
        for(int j=0; i+j<s.size()&&i-j>=0; j++){
            if(i+j==i-j) ans=max(ans,2*j+1);
        }
    }
    cout<<ans<<endl;
}