#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool IsLoggedIn(){
    string user,pass,u,p;

    cout<<"Enter username : "; cin>>user;
    cout<<"Enter password : "; cin>>pass;

    ifstream read(user + ".txt");
    getline(read, u);
    getline(read, p);

    if(u==user && p==pass){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    int choice,t=3;
    cout<<"1.Register\n2.Login\nEnter your choice : "; cin>>choice;
    if(choice==1){
        string user,pass;
        cout<<"Enter username : "; cin>>user;
        cout<<"Enter password : "; cin>>pass;

        ofstream file;
        file.open(user +".txt");
        file << user << endl << pass;
        file.close();

        main();
    }
    else if(choice==2){
        int c=0;
        j:
        if(c==3){
            cout<<"Maximum tries reached"<<endl;
            system("PAUSE");
            return -1;
        }
        bool status = IsLoggedIn();
        for(int i=0;i<3;i++){
            if(!status){
                cout<<"False Login"<<endl;
                c++;
                goto j;
            }
            else{
                cout<<"Successful Login!"<<endl;
                return 1;
            }
        }
    }
    else{
        cout<<"Enter correct choice"<<endl;
        main();
    }
}