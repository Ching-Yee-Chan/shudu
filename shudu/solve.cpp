#include<iostream>
#include<fstream>
#include<algorithm>
#include"shudu.h"
using namespace std;

inline void input(fstream& f, int matrix[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            f >> matrix[i][j];
        }
    }
    // remove empty line
    f.get();
    f.get();
}

inline void output(fstream& f, int matrix[][9]) {
    for (int i = 0; i < 9; i++) {
        f << matrix[i][0];
        for (int j = 1; j < 9; j++) {
            f << ' ' <<matrix[i][j];
        }
        f << endl;
    }
    f << endl;
}

void solve(char* filename) {
    int matrix[9][9] = { 0 };
    fstream infile(filename, ios::in);
    fstream outfile("suduku.txt", ios::out);
    if (!infile.is_open()) {
        cout << "文件打开失败！" << endl;
        return;
    }
    int i = 0;
    while (infile.peek()!=EOF) {
        input(infile, matrix);
        cout << ++i;
        output(outfile, matrix);
    }
}