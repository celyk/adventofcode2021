#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int getNum(string str){
    size_t pos = str.find_first_of("0123456789");
    return stoi(str.substr(pos));
}

int main(){
	ifstream file("input.txt");

    long long aim = 0;
    long long forward = 0;
    long long depth = 0;

    string str;
    while(getline(file, str)){
        int num = getNum(str);
        cout << str << endl;
        cout << num << endl;

        if(str.find("forward") != string::npos){
            forward += num;
            depth += num*aim;
        }
        if(str.find("backward") != string::npos){
            forward -= num;
            depth -= num*aim;
        }
        if(str.find("up") != string::npos){
            aim -= num;
        }
        if(str.find("down") != string::npos){
            aim += num;
        }
    }

    printf("aim: %i\ndepth: %i\nforward: %i\ndepth*forward: %i\n", aim, depth, forward, depth*forward);
	//getchar();
	return 0;
}