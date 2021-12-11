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


    unsigned long long fuel = 0, last_fuel = 0;
    int pos=0;
    for(;pos<arr.size();pos++){
        fuel = 0;
        for(int i=0; i<arr.size(); i++){
            int k = abs(arr[i] - arr[pos]);
            fuel += (k*(k+1))/2;
        }

        if(pos>0) if(fuel > last_fuel) break;

        last_fuel = fuel;
    }

    printf("arr size: %i\nminimum fuel: %llu\n", arr.size(), last_fuel);
    
    /* //WHY DIDN'T THIS WORK
    long long a = 0;
    for(int i=0; i<arr.size(); i++){
        a+=arr[i];
    }   

    long long n = arr.size();

    int id = 0;
    for(; id<arr.size(); id++){
        printf("%i\n", int(2*(n*arr[id] - a + (id+1)) - n) );//float(arr[id])-float(a+(id+1))/n-float(n)/2
        if( 2*(n*arr[id] - a + (id+1)) - n >= 0 ) break;
    }   

    unsigned long long fuel = 0;
    int pos = arr[id];
    for(int i=0; i<arr.size(); i++){
        int k = abs(arr[i] - pos);
        fuel += (k*(k+1))/2;
    }                             
    //cout<<fuel<<endl;
    printf("arr size: %i\npos: %i\nminimum fuel: %llu\n", arr.size(), pos, fuel);
    //printf("biggest ull: %llu\n", 18446744073709551615ull);
    */

	return 0;
}