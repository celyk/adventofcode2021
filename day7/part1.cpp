#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> arr;

    ifstream file("input.txt");
    string str;
    while(getline(file, str)){
        size_t ot = 0;
        size_t t = 0;
        while(t != string::npos){
            t = str.find(",", ot);
            arr.push_back( stoi( str.substr(ot, t - ot) ) );
            ot = t + 1; //skip the comma
        }
    }

    sort(arr.begin(), arr.end());

    unsigned long long fuel = 0;
    int median = arr[arr.size()/2];
    for(int i=0; i<arr.size(); i++){
        //printf("%llu\n", arr[i]);
        fuel += abs(arr[i] - median);
    }                             
    //cout<<fuel<<endl;
    printf("arr size: %i\nmedian: %i\nminimum fuel: %llu\n", arr.size(), median, fuel);
    //printf("biggest ull: %llu\n", 18446744073709551615ull);

	return 0;
}