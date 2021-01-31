#include<bits/stdc++.h>
using namespace std;
void version(){
    cout<<"version 1.0"<<endl;
}
void help(){
    version();
    cout<<"usage: ./scores < help | init | add <name> [value] | mod <name> <value> >"<<endl;
}
int main(int argc,char* argv[]){
    if(argc<2){
        cout<<"no arguments"<<endl;
        return 0;
    }
    if(strcmp(argv[1],"help")==0){
        help();
        return 0;
    }
    if(strcmp(argv[1],"version")==0){
        version();
        return 0;
    }
    if(strcmp(argv[1],"init")==0){
        string sure="";
        cout<<"Init Confirmation (INIT or cancel): All existing data will be lost!"<<endl;
        while(sure!="INIT"&&sure!="cancel") cin>>sure;
        if(sure=="INIT") freopen(".scores","w",stdout);
        return 0;
    }
    if(strcmp(argv[1],"add")==0){
        if(argc<3){
            cout<<"error"<<endl;
            return 0;
        }
        ifstream file(".scores");
        if(!file.good()){
            cout<<"please use './score init' first"<<endl;
            return 0;
        }
        char word[256];
        bool name=1,remove=0;
        for(int i=0; file>>word; i++){
            if(remove){
                ofstream outfile(".tmp",ios_base::app);
                string t;
                for(int j=0; file>>t; j++){
                    if(j==i){
                        if(argc<4) outfile<<0<<endl;
                        else outfile<<argv[3]<<endl;
                    }else if(j%2==0) outfile<<t<<' ';
                    else outfile<<t<<endl;
                }
                ::remove(".scores");
                ::rename(".tmp",".scores");
                outfile.close();
                remove=0;
            }
            if(name){
                if(strcmp(word,argv[2])==0){
                    string option="\0";
                    cout<<"name already in file (replace? y or n)"<<endl;
                    while(option[0]!='y'&&option[0]!='n') cin>>option;
                    if(option[0]=='y'){
                        remove=1;
                    }else return 0;
                }
            }
            name=!name;
        }
        ofstream out(".scores",ios_base::app);
        if(argc<4) out<<argv[2]<<' '<<0<<endl;
        else out<<argv[2]<<' '<<argv[3]<<endl;
        file.close();
        out.close();
        return 0;
    }
    if(strcmp(argv[1],"mod")==0){
        if(argc<4){
            cout<<"error"<<endl;
            return 0;
        }
        ifstream file(".scores");
        if(!file.good()){
            cout<<"please use './score init' first"<<endl;
            return 0;
        }
        char word[256];
        bool name=1,modify=0;
        for(int i=0; file>>word; i++){
            if(modify){
                long double Score=stold(string(word));
                string output=to_string(Score+stold(argv[3])),t;
                ofstream put(".tmp");
                ifstream _file(".scores");
                // cout<<output<<endl;
                for(int j=0; _file>>t; j++){
                    // cout<<j<<endl;
                    if(j==i){
                        put<<output<<endl;
                    }else put<<t<<' ';
                }
                put.close();
                _file.close();
                ::remove(".scores");
                ::rename(".tmp",".scores");
                return 0;
            }
            if(name){
                if(strcmp(word,argv[2])==0){
                    modify=1;
                }
            }
            name=!name;
        }
        file.close();
        return 0;
    }
}