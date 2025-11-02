#include <iostream>

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

bool checkVariable(){
string variable;
cin>> variable;

if(variable.length()==0){
    //cout<<"variable invalid";
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
void isIdentifier() //task 4
{
    string word;
    cin>>word;
    string keywords[]= {"true","false","int", "float","namespace","class","cout","cin","return","main","bool","char","string","virtual","override","if","else","for","while","break","continue","switch","case","private","public"

    };
    int total =sizeof(keywords)/sizeof(keywords[0]);
    for(int i=0; i<total;i++){
        if (word == keywords[i]){
        cout<<"not identifier";
        break;
        }
    }
    if (checkVariable()) {
        cout << "Valid identifier" << endl;
    } else {
        cout << "Not a valid identifier" << endl;
    }
}

void findAverage() //task 5
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    float sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];

    cout << "Average value = " << sum / n << endl;
}

void findMinMax() //task 6
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int min = arr[0], max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < min)
            min = arr[i];
        if(arr[i] > max)
            max = arr[i];
    }

    cout << "Minimum value = " << min << endl;
    cout << "Maximum value = " << max << endl;
}
void concatName() //task 7
{
    string first, last;
    cout << "Enter first name: ";
    cin.ignore();
    getline(cin, first);
    cout << "Enter last name: ";
    getline(cin, last);
    string fullName = first + " " + last;
    cout << "Full name = " << fullName << endl;
}

int main()
{
   int choice;

    do {
        cout << "\n---- Options ----" << endl;
        cout << "1. Determine whether input is numeric or not" << endl;
        cout << "2. Determine whether given input is operator or not" << endl;
        cout << "3. Determine whether the given input is comment or not" << endl;
        cout << "4. Determine whether the given input is identifier" << endl;
        cout << "5. Find Average of Array Elements" << endl;
        cout << "6. Find Min and Max of Array Elements" << endl;
        cout << "7. Concatenate First and Last Name" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice (0-7): ";
        cin >> choice;

        switch (choice) {
            case 1:
                isNumaric();
                break;
            case 2:
                isOperator();
                break;
            case 3:
                checkComment();
                break;
            case 4:
                isIdentifier();
                break;
            case 5:
                findAverage();
                break;
            case 6:
                findMinMax();
                break;
            case 7:
                concatName();
                break;
            case 0:
                cout << "Program ended." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
