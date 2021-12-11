#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int clamp(int i,int e0,int e1){
    return (((e0>i)?e0:i)>e1)?e1:i;
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

    vector<int> neighbours;
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

                if( 0<=(y+dy) && (y+dy)<arry_size && 0<=(x+dx) && (x+dx)<arrx_size ){
                    lower_than_any_neighbours = lower_than_any_neighbours || (val < arr[y+dy][x+dx]);
                    higher_than_any_neighbours = higher_than_any_neighbours || (val > arr[y+dy][x+dx]);

                    //neighbours.push_back( arr[y+dy][x+dx] );
                }
            }



            if( lower_than_any_neighbours && !higher_than_any_neighbours ){
                sum += val + 1;
                //printf("sum of minima: %i\n", sum);
            }

            neighbours.clear();
        }
    }
    
    printf("hi: %i\n", sum);
    printf("sum of minima: %i\n", sum);
    //printf("biggest ull: %llu\n", 18446744073709551615ull);

	return 0;
}