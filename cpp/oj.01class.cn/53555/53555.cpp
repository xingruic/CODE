#include<bits/stdc++.h>
using namespace std;
int _hash(char s[],int len){
   unsigned int seed = 131;
   unsigned int hash = 0;
   unsigned int i    = 0;
   for (i = 0; i < len; i++){
      hash = (hash * seed) + (s[i]);
   }
   return hash%1000000007;
}
int main(){
    // cout<<"dkdkkdkdkd"<<endl;
    freopen("53555.in","r",stdin);
    // cout<<"dkdkkdkdkd"<<endl;
    int num,len,poss;
    cin>>num>>len>>poss;
    char a[num][len];
    for(int i=0; i<num; i++) scanf("%s",a[i]);
    int hashf[num];
    for(int i=0; i<num; i++) hashf[i]=_hash(a[i],len);
    int hashx[num][len];
    for(int i=0; i<num; i++){
        for(int j=0; j<len; j++){
            char t[len-1];
            int temp=0;
            for(int k=0; k<len; k++) if(k!=j) t[temp++]=a[i][k];
            hashx[i][j]=_hash(t,len);
        }
    }
    int ans=0;
    for(int i=0; i<num; i++){
        for(int j=i+1; j<num; j++){
            for(int k=0; k<len; k++){
                if(hashx[i][k]==hashx[j][k]){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
//   string a[num];
//   for(int i=0; i<num; i++) cin>>a[i];
// //   cout<<"dkdkkdkdkd"<<endl;
//   int hashf[num];
//   for(int i=0; i<num; i++) hashf[i]=_hash(a[i]);
// //   cout<<"dkdkkdkdkd"<<endl;
//   int hashx[num][len];
//   for(int i=0; i<num; i++){
//     for(int j=0; j<len; j++){
//       string t="";
//       for(int k=0; k<len; k++) if(k!=j) t+=a[i][k];
//       hashx[i][j]=_hash(t);
//     }
//   }
// //   cout<<"dkdkkdkdkd"<<endl;
//   for(int i=0; i<num; i++){
//     for(int j=i+1; j<num; j++){
//       for(int k=0; k<len; k++){
//         if(hashx[i][k]==hashx[j][k]){
//           ans++;
//           break;
//         }
//       }
//     }
//   }
// //   cout<<"dkdkkdkdkd"<<endl;
//   cout<<ans<<endl;
}