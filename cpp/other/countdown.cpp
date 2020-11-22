#include<iostream>
#include<windows.h>
using namespace std;
void countdown(int num){
	if(num==1){
		cout<<num<<endl;
		Sleep(1000);
		return;
	}
	countdown(num-1);
	cout<<num<<endl;
	Sleep(1000);
	return;
}
int main(){
	countdown(10);
	return 0;
}
/***********
{
    {
    	{
    		{
    			{
    				cout<<6<<endl;
    				Sleep(1000);
    				return;
    			}
    			cout<<7<<endl;
    			return;
    			Sleep(1000);
    		}
    		cout<<8<<endl;
    		Sleep(1000);
    		return;
    	}
    	cout<<9<<endl;
    	Sleep(1000);
    	return;
    }
	cout<<10<<endl;
	Sleep(1000);
	return;
}
******/
