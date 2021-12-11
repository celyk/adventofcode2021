#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>::iterator algo(std::vector<int>& sorted_arr, bool most_common){
    vector<int>::iterator low = sorted_arr.begin();
    vector<int>::iterator up = sorted_arr.end() - 1;

    int n = 1<<11;
    int bound = n;
    while(*low != *up){
        vector<int>::iterator tmp = std::lower_bound(low, up, bound);

        n = n>>1;
        if((tmp - low > up - tmp + 1) == most_common){
            up = tmp - 1;
            bound -= n;
        }
        else{
            low = tmp;
            bound += n;
        }
    }
    return low;
}

int main(){
    vector<int> arr;

    ifstream file("input.txt");
    string str;
    while(getline(file, str)){
        int value = 0;
        for(int i=0;i<12;i++){
            if(str[11-i]=='1'){
                value += (1<<i);
            }
        }
        arr.push_back(value);
    }

    sort(arr.begin(), arr.end());

    int oxygen = *algo(arr, true);
    int scrubber = *algo(arr, false);

    int life = oxygen*scrubber;
    printf("oxygen: %i\nscrubber: %i\npower aka oxygen*scrubber: %i\n", oxygen, scrubber, life);
	//getchar();

	return 0;
}