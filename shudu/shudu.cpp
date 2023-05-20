#include<iostream>
#include<fstream>
#include<algorithm>
#include"getopt.h"
#include"progress.h"
using namespace std;

inline void output(fstream& f, int* line, int* offset) {
    for (int i = 0; i < 9; i++) {
        int start = offset[i];
        f << line[start];
        for (int j = start + 1; j < start + 9; j++) {
            f << " " << line[j % 9];
        }
        f << endl;
    }
    f << endl;
}

void getFinal(int num) {
    if (num < 1 || num>1e6) {
        cout << "生成失败！数独终盘数量须在1~1000000之间！" << endl;
        return;
    }
    cout << "开始生成" << num << "个数独终盘！" << endl;

    //Initialize prgress bar
    milliseconds interval(1000);
    ProgressBar bar((unsigned int)num, interval);
    bar.show();

    //Open output file
    fstream outfile("final.txt", ios::out);
    if (!outfile.is_open()) {
        cout << "文件打开失败！" << endl;
        return;
    }

    int head[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int offset[9] = { 0, 3, 6, 1, 4, 7, 2, 5, 8 };
    while (true) {
        //change the order of line 3-5, 6 arrangements
        for (int i = 0; i < 6; i++) {
            //change the order of line 6-8, 6 arrangements
            for (int j = 0; j < 6; j++) {
                output(outfile, head, offset);
                bar.update();
                if ((--num) <= 0) {
                    outfile.close();
                    bar.show();
                    cout << "生成完成！" << endl;
                    return;
                }
                next_permutation(offset + 6, offset + 9);
            }
            next_permutation(offset + 3, offset + 6);
        }
        next_permutation(head, head + 9);
        if (num % 100 == 0) {
            bar.show();
        }
    }
}

int main(int argc, char* argv[]) {
    int opt = 0;
    while ((opt = getopt(argc, argv, "c:s:n:m:r:u")) != -1) {
        switch (opt) {
        case 'c':
            int num;
            num = atoi(optarg);
            getFinal(num);
            break;
        case 's':
            break;
        case 'n':
            break;
        case 'm':
            break;
        case 'r':
            break;
        case 'u':
            break;
        default:
            cout << "参数错误！不存在参数" << (char)opt << "!" << endl;
        }
        return 0;
    }
}