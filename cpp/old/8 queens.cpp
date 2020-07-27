#include<bits/stdc++.h>
#define numq 8
using namespace std;
bool a[numq][numq]={{0}};
bool danger(bool q[][numq],int row,int col){
	for(int i=0; i<numq; i++){
		if(q[row][i]){
			return 1;
		}
	}
	for(int i=0; i<numq; i++){
		if(q[i][row]){
			return 1;
		}
	}
	for(int i=0; i<numq; i++){
		for(int j=0; j<numq; j++){
			if(i-j==row-col||i+j==row+col){
				return 1;
			}
		}
	}
	return 0;
}
//bool danger(bool arr[numq][numq], int row, int column){
//    if (row == 0){
//        return 0;
//    }
//    int i, j;
//    // ÅÐ¶Ï×ÝÏòÊÇ·ñÓÐ³åÍ»
//    for (i = 0; i < row; ++i){
//        if (arr[i][column]){
//            return 1;
//        }
//    }
//    i = row - 1;
//    j = column - 1;
//    // ÅÐ¶ÏÕýÐ±¶Ô½ÇÏßÊÇ·ñÓÐ³åÍ»
//    while (i >= 0 && j >= 0){
//        if (arr[i][j]){
//            return 1;
//        }
//        --i;
//        --j;
//    }
//    i = row - 1;
//    j = column + 1;
//    // ÅÐ¶Ï¸ºÐ±¶Ô½ÇÏßÊÇ·ñÓÐ³åÍ»
//    while (i >= 0 && j <= numq - 1){
//        if (arr[i][j]){
//            return 1;
//        }
//        --i;
//        ++j;
//    }
//    return 0;
//}
void ans(bool q[][numq]){
	for(int i=0; i<numq; i++){
		for(int j=0; j<numq; j++){
			cout<<q[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}
void place(bool q[][numq],int row){
	for(int i=0; i<numq; i++){
		q[row][i]=1;
		if(!danger(q,row,i)){
			if(i==0) ans(q);
			if(row==numq-1){
				ans(q);
			}else{
				place(q,row+1);
			}
		}else{
			q[row][i]=0;
		}
	}
}
int main(){
//	a[1][7]=1;
//	cout<<danger(a,2,0)<<endl;
	place(a,0);
//	ans(a);
}
