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
            ot = t + 1;
        }

        ot += 2;

        for(int i=0;i<4;i++){
            t = str.find(" ", ot);
            data.back().push_back( str.substr(ot, t - ot) );
            //printf("!%s!", str.substr(ot, t - ot).c_str());
            ot = t + 1;
        }
    }


    vector<string> stuff = {"abcefg", "cf", "acdeg", "acdfg", "bcdf", "abdfg", "abdefg", "acf", "abcdefg", "abcdfg"};



    unsigned long long answer = 0;

    for(size_t z = 0;z<data.size();z++){

        string map = "abcdefg";    
        for(size_t j=0;j<5040;j++){
            string final = " ";
            for(int i=0;i<10;i++){
                string tmp = data[z][i];
                for(int q=0;q<tmp.size();q++){
                    tmp[q] = map[ tmp[q]-97 ];
                }

                sort(tmp.begin(),tmp.end());

                final += tmp;
            }

            bool found = true;
            for(string& s: stuff){
                found = found && final.find(s) != string::npos;
            }
            if(found) {
                printf("yay\n");
                break;
            }

            next_permutation(map.begin(), map.end());
        }
        /*
        for(int i=0;i<10;i++){
            string tmp = data[z][i];
            for(int q=0;q<tmp.size();q++){
                tmp[q] = map[ tmp[q]-97 ];
            }
            sort(tmp.begin(),tmp.end());

            printf("%i: %s ", i, tmp.c_str());
        }
        printf("\n");*/

        int dec = 1;
        for(int i=0;i<4;i++){
            string tmp = data[z][13-i];
            for(int q=0;q<tmp.size();q++){
                tmp[q] = map[ tmp[q]-97 ];
            }
            sort(tmp.begin(),tmp.end());

            answer += dec*distance(stuff.begin(),find(stuff.begin(), stuff.end(), tmp));
            dec*=10;
        }
    }
    printf("answer: %llu\n",answer);
    //printf("biggest ull: %llu\n", 18446744073709551615ull);

	return 0;
}