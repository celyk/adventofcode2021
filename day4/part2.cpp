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


int floodCount(vector<vector<int>>& arr, int x, int y, bool vertical){
    if( outOfBounds(arr,x,y) ) return 0;
    if( arr[y][x] != -1 ) return 0;

    if(vertical){
        return 1 + floodCount(arr,x,y+1,true);
    }
    else{
        return 1 + floodCount(arr,x+1,y,false);
    }
}


bool mark(vector<vector<int>>& board,int x,int y){
    board[y][x] = -1;

    printf("count x: %i\n", floodCount(board,0,y,false));
    printf("count y: %i\n", floodCount(board,x,0,true));

    if(floodCount(board,0,y,false) >= 5) return true;
    if(floodCount(board,x,0,true) >= 5) return true;
    return false;
}

int main(){
    vector<int> numbers;

    ifstream file("input.txt");
    string str;
    
    if(getline(file, str)){
        size_t ot = 0;
        size_t t = 0;
        while(t != string::npos){
            t = str.find(",", ot);
            numbers.push_back( stoi( str.substr(ot, t - ot) ) );
            ot = t + 1;
        }
    }

    vector<vector<vector<int>>> boards;
    while(getline(file, str)){
        boards.push_back( vector<vector<int>>(5,vector<int>(5)) );
        for(int y=0; y<5&&getline(file, str);y++){
            for(int x=0; x<5; x++){
                int val = stoi( str.substr(x*3,2) );
                //printf("val: %i\n", val);

                boards.back()[y][x] = val;
            }
        }
    }

    int z;
    int board_id;
    unordered_map<int,bool> board_won;
    for(z=0;z<numbers.size();z++){
        for(board_id=0;board_id<boards.size();board_id++){
            for(int y=0;y<5;y++){
                for(int x=0;x<5;x++){
                    //printf("number: %i, number val: %i, board: %i y: %i x: %i val: %i\n", z, numbers[z], board_id, y, x, boards[board_id][y][x]);
                    
                    if(boards[board_id][y][x] == numbers[z]) {
                        printf("HEY: number: %i, number val: %i, board: %i, y: %i, x: %i, val: %i\n", z, numbers[z], board_id, y, x, boards[board_id][y][x]);
                    
                        bool win = mark(boards[board_id],x,y);
                        if(win && board_won.find(board_id) == board_won.end()) {
                            printf("we have a winner: %i\n",board_id);

                            board_won[board_id] = true;

                            if(board_won.size() == boards.size()) goto winner;
                        }
                    }
                }
            }
        }
        
    }
    board_id--;
    z--;
winner:
    printf("END: number: %i, number val: %i, board: %i\n", z, numbers[z], board_id);

    unsigned long long sum = 0;
    for(int y=0;y<5;y++){
        for(int x=0;x<5;x++){
            if(boards[board_id][y][x] != -1) sum += boards[board_id][y][x];
        }
    }
    unsigned long long answer = sum*numbers[z];
    printf("answer: %llu\n", answer);
    //printf("biggest ull: %llu\n", 18446744073709551615ull);

    return 0;
}