#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct ivec2{
    int x,y;

    ivec2 operator+(ivec2& b){
        return {this->x + b.x,this->y + b.y};
    }
    ivec2 operator-(ivec2& b){
        return {this->x - b.x,this->y - b.y};
    }
};

struct Line{
    ivec2 a;
    ivec2 b;
};

int halfSpace(ivec2 v, ivec2 p){
    return v.x*p.x + v.y*p.y;
}

ivec2 rot90(ivec2 a){return {-a.y,a.x};}

int intersectLinePoint(ivec2 a,ivec2 b, ivec2 p){
    if(halfSpace(rot90(b-a),p-a) == 0 && halfSpace(b-a,p-a)>=0 && halfSpace(a-b,p-b)>=0) return 1;
    return 0;
}

int main(){
    vector<int> arr;

    ifstream file("input.txt");
    string str;
    while(getline(file, str)){
        size_t ot = 0;
        size_t t = 0;
        while(t != string::npos){
            size_t t0 = str.find(",", ot);
            size_t t1 = str.find("->", ot);

            t = (t0<t1)?t0:t1;

            //printf("%i\n", stoi( str.substr(ot, t - ot) ) );
            arr.push_back( stoi( str.substr(ot, t - ot) ) );

            ot = t + ((t0<t1)?1:2); //skip
        }
    }

    vector<Line> ortholines;
    for(int i=0; i<arr.size(); i+=4){
        ortholines.push_back({
            arr[i],
            arr[i+1],
            arr[i+2],
            arr[i+3]
        });
    }

    vector<vector<int>> canvas(1000, vector<int>(1000, 0));

    for(int i=0;i<ortholines.size();i++){
        Line& line = ortholines[i];

        for(int y=0;y<1000;y++)
        for(int x=0;x<1000;x++){
            canvas[y][x] += intersectLinePoint(line.a,line.b,{x,y});
        }
    }

    int count = 0;

    for(int y=0;y<1000;y++)
    for(int x=0;x<1000;x++){
        if(canvas[y][x]>1) count++;
    }

    printf("overlap count: %i\n", count);
    //printf("biggest ull: %llu\n", 18446744073709551615ull);

	return 0;
}