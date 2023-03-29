#include<iostream>
#include<string>
using namespace std;

bool validate(string n){
    int sum=0;
    bool d_digit=false;
    for(int i=n.length()-1;i>=0;i--){
        int d = n[i]-'0';
        if(d_digit){
            d=d*2;
            if(d>9){
                d=d-9;
            }
        }
        sum = sum+d;
        d_digit = !d_digit;
    }
    return (sum%10 == 0);
}

int main(){
    string number;
    cout<<"Enter your card number : ";
    cin>>number;
    if(validate(number)){
        cout<<"Valid card number"<<endl;
    }
    else{
        cout<<"Invalid card number"<<endl;
    }
    return 0;
}