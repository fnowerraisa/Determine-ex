#include <iostream>
#include <string.h>
using namespace std;

bool isNumaric()    //task 1
{
    string c;
    cin>>c;
    for(int i=0;i<c.length();i++){
        if(c[i]>=48 && c[i]<=57){
            continue;
        }
        else
            return false;
    }
    return true;
}

void isOperator()       //task 2
{
    string input;
    cin>>input;
    int count = 0;

    for(int i=0; i<input.length();i++){
        char c = input[i];
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '='){
            count++;
            cout<<"Operator "<<count<<": "<<c<<endl;
        }
    }
    if(count == 0)
        cout<<"No Operator"<<endl;
}
void checkComment()         //task 3
{

    string str;
    cin.ignore();
    getline(cin, str);
    if (str.size() >= 2 && str[0] == '/' && str[1] == '/') {
        cout << "It is a single-line comment." << endl;
    }
    else if (str.size() >= 4 && str[0] == '/' && str[1] == '*' && str[str.size() - 2] == '*' && str[str.size() - 1] == '/') {
        cout << "It is a multi-line comment." << endl;
    }
    else {
        cout << "It is not a comment." << endl;
    }
}

int main()
{
    cout<<"Enter Input to check numeric: "<<isNumaric()<<endl;

    cout<<"Enter a Input to check operators :";
    isOperator();

    cout << "Enter a string to check note type: ";
    checkComment();

    return 0;
}
