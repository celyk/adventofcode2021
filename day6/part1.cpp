#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class LanternFish{
public:
    LanternFish(){}
    LanternFish(int t):timer(t){}

    bool simulate(){
        if(--timer < 0) {
            timer = 6;
            return true;
        }
        return false;
    }
private:
    int timer = 8;
};

int main(){
    std::vector<LanternFish> fish;

    ifstream file("input.txt");
    string str;
    while(getline(file, str)){
        size_t ot = 0;
        size_t t = 0;

        while(t != string::npos){
            t = str.find(",", ot);
            //printf("%s\n", str.substr(ot, t - ot).c_str());
            fish.push_back(LanternFish(stoi( str.substr(ot, t - ot) )));
            ot = t + 1; //skip the comma
        }
    }

    for(int day = 0; day<80; day++){
        size_t fish_size = fish.size();
        for(int i=0; i<fish_size; i++){
            if(fish[i].simulate()) fish.push_back(LanternFish());
        }
    }

    printf("there are %i fish !\n", fish.size());

	return 0;
}