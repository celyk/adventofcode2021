#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct ivec2{
    int x,y;
};

struct Line{
    ivec2 a;
    ivec2 b;
    bool vertical;
    int length;
};

template<typename T>
void swap(T& a, T& b){T c=a;a=b;b=c;}

int intersectLinePoint(Line X, ivec2 p){
    if(Line.vertical){ 
        if(p.x == X.a.x && (X.a.y <= p.y && p.y <= X.b.y)) return true;
    }
    else{

    }
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
        if(arr[i] == arr[i+2] || arr[i+1] == arr[i+3]) {
             ortholines.push_back({
                arr[i],
                arr[i+1],
                arr[i+2],
                arr[i+3],
                arr[i] == arr[i+2],
                0};

            Line& line = ortholines.back();
            if(line.vertical){
                if(line.a.y > line.b.y) swap(line.a.y, line.b.y);
                line.length = line.b.y - line.a.y;
            }
            else{
                if(line.a.x > line.b.x) swap(line.a.x, line.b.x);
                line.length = line.b.x - line.a.x;
            }
        }
    }

    vector<vector<int>> canvas(1000, vector<bool>(1000, false));

    for(int i=0;i<ortholines.size();i++){
        Line& line = ortholines[i];
        for(int j=0;j<line.size;j++){
            canvas[line.a.x][line.a.y]
            //intersectLinePoint(line,);
        }
    }

    //sort(arr.begin(), arr.end());

    printf("overlap count: %i\n", ortholines.size());
    //printf("biggest ull: %llu\n", 18446744073709551615ull);

	return 0;
}