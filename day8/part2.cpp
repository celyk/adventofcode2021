#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;



int main(){
    vector<vector<string>> data;

    ifstream file("input.txt");
    string str;
    while(getline(file, str)){
        data.push_back(vector<string>());

        size_t ot = 0;
        size_t t = 0;

        for(int i=0;i<10;i++){
            t = str.find(" ", ot);
            data.back().push_back( str.substr(ot, t - ot) );
            //printf("!%s!", str.substr(ot, t - ot).c_str());
            ot = t + 1;
        }

        ot += 2;

        //printf("|");
        for(int i=0;i<4;i++){
            t = str.find(" ", ot);
            data.back().push_back( str.substr(ot, t - ot) );
            //printf("!%s!", str.substr(ot, t - ot).c_str());
            ot = t + 1;
        }

        //printf("\n");
    }

    int count[9] = {0};
    
    for(int j=0; j<data.size(); j++){
        for(int i=0; i<4; i++){
            switch(data[j][10+i].size()){
            case 2: count[1]++;break;//1
            case 4: count[4]++;break;//4
            case 3: count[7]++;break;//7
            case 7: count[8]++;break;//8
            }
        }
    }

    int sum = count[1] + count[4] + count[7] + count[8];
    printf("1: %i, 4: %i, 7: %i, 8: %i, sum: %i", count[1], count[4], count[7], count[8], sum);
    //printf("biggest ull: %llu\n", 18446744073709551615ull);

	return 0;
}