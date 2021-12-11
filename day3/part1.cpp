#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main(){
	ifstream file("input.txt");

    vector<int> cbits(12,0);
    int cnums = 0;

    int gamma = 0;
    int epsilon = 0;

    string str;
    while(getline(file, str)){
        cnums++;

        cout<<"datas: "+str<<endl;
        cout<<"cbits: ";
        for(int i=0;i<12;i++) {
            cbits[i] += stoi(str.substr(i,1));
            cout<<cbits[i]; cout<<" ";
        }
        cout<<endl;
    }
    
    for(int i=11; i>=0; i--) {
        if(cbits[11-i]>cnums/2){
            gamma += (1<<i);
        }
        else{
            epsilon += (1<<i);
        }
    }

    int power = gamma*epsilon;
    printf("gamma: %i\nepsilon: %i\npower aka gamma*epsilon: %i\n", gamma, epsilon, power);
	//getchar();
	return 0;
}