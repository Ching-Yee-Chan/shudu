#include"shudu.h"
using namespace std;

int exec_sudoku(int argc, char* argv[]) {
    int opt = 0;
    int num_games = -999;
    int level = -1;
    int space = -1;
    int result = 0;
    while ((opt = getopt(argc, argv, "c:s:n:m:r:u")) != -1&&result !=-1) {
        switch (opt) {
        case 'c':
            int num;
            num = atoi(optarg);
            if (num < 1 || num>1e6) {
                cout << "生成失败！数独终盘数量须在1~1000000之间！" << endl;
                return -1;
            }
            getFinal(num);
            break;
        case 's':
            result = solve(optarg);
            break;
        case 'n':
            num_games = atoi(optarg);
            continue;
        case 'm':
            level = atoi(optarg);
            if (num_games < 0) {
                cout << "please input the number of games!" << endl;
                result = -1;
                break;
            }
            if (level < 1 || level > 3) {
                cout << "the level of game should be restricted in 1-3" << endl;
                result = -1;
                break;
            }
            getGameByLevel(num_games, level);
            break;
        case 'r':
            space = atoi(optarg);
            if (num_games < 0) {
                result = -1;
                cout << "please input the number of games!" << endl;
                break;
            }
            if (space < 20 || space > 55) {
                result = -1;
                cout << "the space of game should be restricted in 20-55" << endl;
                break;
            }
            getGameBySpace(num_games, space);
            break;
        case 'u':
            if (num_games < 0) {
                result = -1;
                cout << "please input the number of games!" << endl;
                break;
            }
            getGameUnique(num_games);
            break;

        default:
            result = -1;
            cout << "参数错误！不存在参数" << (char)opt << "!" << endl;
            break;
        }
    }
    return result;
}


int main(int argc, char* argv[]) {
    int res = exec_sudoku(argc, argv);
    cout <<"result" << res << endl;
    return 0;
}