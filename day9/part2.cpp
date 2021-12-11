#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct ivec2{
    int x,y;
};

bool outOfBounds(const vector<vector<int>>& arr,int x,int y){
    return !(0<=y && y<arr.size() && 0<=x && x<arr[y].size());
}

int floodCount(vector<vector<int>>& arr, int x, int y){
    if( outOfBounds(arr,x,y) || arr[y][x] == 9 ) return 0;

    arr[y][x] = 9;

    return 1+
    floodCount(arr,x+1,y)+
    floodCount(arr,x-1,y)+
    floodCount(arr,x,y+1)+
    floodCount(arr,x,y-1);
}

int main(){
    vector<vector<int>> arr;

    ifstream file("input.txt");
    string str;
    while(getline(file, str)){
        arr.push_back( vector<int>(str.size()) );
        for(int i=0;i<str.size();i++){
            arr.back()[i] = stoi( str.substr(i,1) );
        }
    }

    int sum = 0;

    vector<ivec2> low_points;

    int arry_size = arr.size();
    for(int y = 0; y<arry_size; y++){
        int arrx_size = arr[y].size();
        for(int x = 0; x<arrx_size; x++){
            int val = arr[y][x];

            bool lower_than_any_neighbours = false;
            bool higher_than_any_neighbours = false;

            for(int i=0;i<4;i++){
                int dx = abs(i-2)-1;
                int dy = 1-abs(i-1);

                if( !outOfBounds(arr,x+dx,y+dy) ){
                    lower_than_any_neighbours = lower_than_any_neighbours || (val < arr[y+dy][x+dx]);
                    higher_than_any_neighbours = higher_than_any_neighbours || (val > arr[y+dy][x+dx]);
                }
            }

            if( lower_than_any_neighbours && !higher_than_any_neighbours ){
                low_points.push_back({x,y});

                printf("low point: %i,%i\n",low_points.back().x,low_points.back().y);
            }
        }
    }
    
    printf("hi:\n");

    vector<int> basin_sizes(low_points.size());
    for(int i=0;i<basin_sizes.size();i++){
        basin_sizes[i] = floodCount(arr,low_points[i].x,low_points[i].y);
        printf("basin size: %i\n",basin_sizes[i]);
    }

    sort(basin_sizes.begin(), basin_sizes.end(), greater<int>());

    unsigned long long answer = basin_sizes[0]*basin_sizes[1]*basin_sizes[2];

    printf("answer: %llu\n", answer);
    //printf("biggest ull: %llu\n", 18446744073709551615ull);

	return 0;
}