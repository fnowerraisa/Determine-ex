#include <iostream>
#include<fstream>


using namespace std;

bool checkVariable(string variable){

if(variable.length()==0){

    return false;
}

char first = variable[0];

if(!((first>=97 && first <=122)||(first >=65 && first<=90)||(first ==95))){
        //cout<<"variable invalid";
        return false;
    }

for(int i=1; i<variable.length();i++){
    char c = variable[i];

    if(!((c >=97&& c<=122)||(c >=65 && c<=90)||(c ==95)||(c>=47 && c<=58))){
        //cout<<"variable invalid"<<endl;
        return false;
    }

}
return true;

}
void isIdentifier(string word)
{

    string keywords[]= {"true","false","int", "float","namespace","class","cout","cin","return","main","bool","char","string","virtual","override","if","else","for","while","break","continue","switch","case","private","public"

    };
    int total =sizeof(keywords)/sizeof(keywords[0]);
    for(int i=0; i<total;i++){
        if (word == keywords[i]){
        cout<<word<<" :not identifier(keyword)"<<endl;
        return;
        }
    }
    if (checkVariable(word)) {
        cout <<word<<" :Valid identifier" << endl;
    } else {
        cout <<word<<" :Not a valid identifier" << endl;
    }

}
int main(){

    ifstream fin("identifier.txt");
    string line;

    while(getline(fin, line)){
          if(line.empty()){
            continue;
          }

        isIdentifier(line);
    }

return 0;
}

