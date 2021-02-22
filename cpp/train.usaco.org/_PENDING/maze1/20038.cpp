/*
ID:xingrui1
LANG:C++
TASK:maze1
*/
#include<bits/stdc++.h>
using namespace std;

char m[222][88];
int hi[101][40];

int fx( int x ){ return (x<<1)-1; }
int fy( int y ){ return (y<<1)-1; }
int min( int a,int b ){ return a<b?a:b; }
 
int main(){
	freopen("maze1.in","r",stdin);
	freopen("maze1.out","w",stdout);
 	int w,h;
 	scanf( "%d %d",&w,&h );
 	char c;
 	scanf( "%c",&c );
 	for( int i=0;i<2*h+1;i++ )
 	{
 		 for( int j=0;j<2*w+1;j++ )
 		 	  scanf( "%c",&m[i][j] );
	 	 scanf( "%c",&c );
}
    	int out[2][2];
	int cnt=0;
	
	for( int i=0;i<2*h+1;i++ )
	{
		 if( m[i][0]==' ' )
 	     {
		  	 out[cnt][0]=i/2+1;
		  	 out[cnt][1]=1;
		  	 cnt++;
	     }
	     if( m[i][2*w]==' ' )
 	     {
		  	 out[cnt][0]=i/2+1;
		  	 out[cnt][1]=w;
		  	 cnt++;
	     }
    }
    
for( int j=0;j<2*w+1;j++ ){
	 	 if( m[0][j]==' ' ){ 	 
 			 out[cnt][0]=1;
		  	 out[cnt][1]=j/2+1;
		  	 cnt++;
		 }
	 	 if( m[2*h][j]==' ' ){ 	 
 			 out[cnt][0]=h;
		  	 out[cnt][1]=j/2+1;
		  	 cnt++;
		 }
 	}
 	
 	for( int i=0;i<=h;i++ )
 	for( int j=0;j<=w;j++ )
 		 hi[i][j]=111111;
	
 	for( int i=0;i<cnt;i++ )
 		 hi[out[i][0]][out[i][1]]=1;
 	
	bool flag=true;
	while( flag ){ 	 
		 flag=false;
 		 for( int i=1;i<=h;i++ )
 		 for( int j=1;j<=w;j++ ){
		  	  if( m[fx(i)][fy(j)-1]==' ' && hi[i][j]>hi[i][j-1]+1 )
		  	  	  hi[i][j]=hi[i][j-1]+1,flag=true;
		  	  if( m[fx(i)][fy(j)+1]==' ' && hi[i][j]>hi[i][j+1]+1 )
		  	  	  hi[i][j]=hi[i][j+1]+1,flag=true;
		  	  if( m[fx(i)-1][fy(j)]==' ' && hi[i][j]>hi[i-1][j]+1 )
		  	  	  hi[i][j]=hi[i-1][j]+1,flag=true;
		  	  if( m[fx(i)+1][fy(j)]==' ' && hi[i][j]>hi[i+1][j]+1 )
		  	  	  hi[i][j]=hi[i+1][j]+1,flag=true;
 	     }
	}
	int max=0;
	for( int i=1;i<=h;i++ )
	for( int j=1;j<=w;j++ )
		 if( max<hi[i][j] )
		 	 max=hi[i][j];
 	 printf( "%d\n",max );
	 
 	return 0;
}