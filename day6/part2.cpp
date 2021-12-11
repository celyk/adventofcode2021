#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<unsigned long long> num_fish_by_timer(9,0);

    ifstream file("input.txt");
    string str;
    while(getline(file, str)){
        size_t ot = 0;
        size_t t = 0;

        while(t != string::npos){
            t = str.find(",", ot);
            //printf("%s\n", str.substr(ot, t - ot).c_str());
            num_fish_by_timer[ stoi( str.substr(ot, t - ot) ) ] += 1;
            ot = t + 1; //skip the comma
        }
    }


    //simulate
    const int num_days = 256;
    for(int day = 0; day<num_days; day++){
        //for(int i=0;i<9;i++) printf("%i: %llu ", i, num_fish_by_timer[i]);
        //printf("\n");
        std::rotate(num_fish_by_timer.begin(), num_fish_by_timer.begin()+1, num_fish_by_timer.end());
        num_fish_by_timer[6] += num_fish_by_timer[8];
    }

    unsigned long long total_fish = 0;
    for(int i=0;i<9;i++) total_fish += num_fish_by_timer[i];

    printf("there are %llu fish by day %i !\n", total_fish, num_days);
    //printf("biggest ull: %llu\n", 18446744073709551615ull);

	return 0;
}