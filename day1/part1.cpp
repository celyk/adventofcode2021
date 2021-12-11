#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	ifstream file("input.txt");
    string str;
    getline(file, str);
    int oldnum;
    int newnum = stoi(str);
    
    int increases = 0;
    int decreases = 0;
    cout << str + " (undefined)\n";
    while(getline(file, str)){
    	oldnum = newnum;
    	newnum = stoi(str);

    	if(newnum==oldnum){}
    	else if(newnum>oldnum) {
    		increases++;
    		cout << str + " (increased)\n";
    	}
    	else{
    		decreases++;
    		cout << str + " (decreased)\n";
    	}
    }

    printf("increases: %i\ndecreases: %i", increases, decreases);
	getchar();
	return 0;
}