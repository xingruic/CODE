#include<bits/stdc++.h>
using namespace std;
/**
 * µÚ7×éÎ´¹ý
 */
int n;// number of pastures
pair<int,int> past[155];// (x,y) coordinates of pastures;
bool path[155][155];// whether two pastures are connected or not
double a[155][155];// the calculated distance between two pastures
double dist(int i,int j);
double findmax(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                if(a[i][j]+a[i][k]<a[j][k]){
                    a[j][k]=a[i][j]+a[i][k];
                    // cout<<a[i][j]<<' '<<a[i][k]<<endl;
                }
    double _min=0x7fffffff;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i][j]==100001){
                a[i][j]=a[j][i]=dist(i,j);
                double _max=0;
                for(int k=0; k<n; k++){
                    if(k==j) continue;
                    if(a[k][i]==100001) continue;
                    for(int l=0; l<n; l++){
                        if(l==i) continue;
                        if(a[l][j]==100001) continue;
                        if(a[i][k]+a[i][j]+a[j][l]>_max){
                            _max=a[i][k]+a[i][j]+a[j][l];
                            // cout<<i<<' '<<k<<' '<<j<<' '<<l<<' ';
                            // printf("%f \n",_max);
                            // for(int i=0; i<n; i++){
                            //     for(int j=0; j<n; j++) printf("%f   ",a[i][j]);
                            //     cout<<endl;
                            // }
                            // cout<<endl;
                        }
                    }
                }
                _min=min(_min,_max);
                a[i][j]=a[j][i]=100001;
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++) printf("%f   ",a[i][j]);
    //     cout<<endl;
    // }
    return _min;
}
double dist(int i,int j){
    return sqrt(
        (double)(
            (past[i].first-past[j].first)*(past[i].first-past[j].first)
            +(past[i].second-past[j].second)*(past[i].second-past[j].second)
        )
    );
}
int main(){
    memset(path,0,sizeof(path));
    for(int i=0; i<155; i++) for(int j=0; j<155; j++) a[i][j]=100001;
    for(int i=0; i<155; i++) a[i][i]=0,past[i].first=0,past[i].second=0;
    cin>>n;
    for(int i=0; i<n; i++) cin>>past[i].first>>past[i].second;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++){
        char t=getchar();
        if(t=='\n') t=getchar();
        if(t=='0') path[i][j]=0;
        else path[i][j]=1;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(!path[i][j]){
                continue;
            }
            a[j][i]=a[i][j]=dist(i,j);
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++) cout<<a[i][j]<<'\t';
    //     cout<<endl;
    // }
    double t=findmax();
    printf("%.6f",t);
}