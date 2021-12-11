#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main(){
	vector<int> arr;

	ifstream file("input.txt");
    string str;
    while(getline(file, str)){
    	arr.push_back(stoi(str));
    }

    int increases = 0;
    cout<<arr.size()<<endl;
    for(int i=0; i<arr.size()-3; i++){
    	if(arr[i] < arr[i+3]){
    		increases++;
    	}
    }

    printf("increases: %i\n", increases);
	//getchar();
	return 0;
}