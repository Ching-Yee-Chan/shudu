#include<iostream>
#include"getopt.h"
#include"shudu.h"
using namespace std;

int main(int argc, char* argv[]) {
    int opt = 0;
    int num_games = -999;
    int level = -1;
    int space = -1;
    while ((opt = getopt(argc, argv, "c:s:n:m:r:u")) != -1) {
        switch (opt) {
        case 'c':
            int num;
            num = atoi(optarg);
            getFinal(num);
            break;
        case 's':
            solve(optarg);
            break;
        case 'n':
            num_games = atoi(optarg);
            continue;
        case 'm':
            level = atoi(optarg);
            if (num_games < 0) {
                cout<< "please input the number of games!"<<endl;
                break;
            }
            if (level < 1 || level > 3) {
                cout<< "the level of game should be restricted in 1-3"<<endl;
                break;
            }
            getGameByLevel(num_games, level);
            break;
        case 'r':
            space = atoi(optarg);
            if (num_games < 0) {
                cout<< "please input the number of games!"<<endl;
                break;
            }
            if (space < 20 || space > 55) {
                cout<<"the space of game should be restricted in 20-55"<<endl;
                break;
            }
            getGameBySpace(num_games, space);
            break;
        case 'u':
            break;
        default:
            cout << "参数错误！不存在参数" << (char)opt << "!" << endl;
        }
        return 0;
    }
}