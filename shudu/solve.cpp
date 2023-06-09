#include"shudu.h"
using namespace std;


int solve(char* filename) {
    int res = 0;
    fstream infile(filename, ios::in);
    fstream outfile("suduku.txt", ios::out);
    if (!infile.is_open()) {
        cout << "文件打开失败！" << endl;
        return -1;
    }
    cout << "正在求解，请稍候..." << endl;
    int i = 1;
    while (infile.peek() != EOF) {
        sudoku board;
        board.input(infile);
        int result = board.solve();
        if (result == 0) {
            board.output(outfile);
        }
        else {
            cout << "第" << i << "个数独无解！" << endl;
            outfile << "No Solution" << endl << endl;
            res = -1;
        }
    }
    return res;
}



