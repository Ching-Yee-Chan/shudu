#include"shudu.h"
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

inline void outputG(fstream& f, int* line, int* offset, int* mask, int spaces) {
    //0代表不挖空， n代表在第几列挖空
    int colMask[9] = { 0 };

    for (int i = 0; i < spaces; i++) {
        do {
            int s = rand() % 9;
            if (mask[s]) {
                colMask[i] = s;
                break;
            }
        } while (1);
    }


    for (int i = 0; i < 9; i++) {
        int start = offset[i];
        if (mask[start])
            f << line[start];
        else
            f << '$';
        for (int j = start + 1; j < start + 9; j++) {
            if (mask[j % 9] && (colMask[i] != j % 9 || !colMask[i]))
                f << " " << line[j % 9];
            else
                f << " " << '$';
        }
        f << endl;
    }
    f << endl;
}

void getFinal(int num) {
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


/**
* 根据输入难度生成数独游戏（-m -n）
*/
void getGameByLevel(int num, int level) {
    if (num < 1 || num>1e4) {
        cout << "生成失败！数独游戏数量须在1~10000之间！" << endl;
        return;
    }
    cout << "开始生成" << num << "个数独游戏！" << endl;
    //Initialize prgress bar
    milliseconds interval(1000);
    ProgressBar bar((unsigned int)num, interval);
    bar.show();

    //Open output file
    fstream outfile("game.txt", ios::out);
    if (!outfile.is_open()) {
        cout << "文件打开失败！" << endl;
        return;
    }
    int spaces = 20;
    if (level == 2) {
        spaces = 30;
    }
    else if (level == 3) {
        spaces = 45;
    }
    int mask[9];
    for (int i = 0; i < 9; i++)
    {
        mask[i] = 1;
    }
    //让挖空均匀分布到每行中，剩余空再另找地方挖
    int lineSpace = spaces / 9;
    int restSpace = spaces % 9;
    //挖每行固定空
    do {
        int r = rand() % 9;
        if (mask[r]) {
            mask[r] = 0;
            lineSpace--;
        }
        else
            continue;
    } while (lineSpace);

    int head[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int offset[9] = { 0, 3, 6, 1, 4, 7, 2, 5, 8 };
    while (true) {
        //change the order of line 3-5, 6 arrangements
        for (int i = 0; i < 6; i++) {
            //change the order of line 6-8, 6 arrangements
            for (int j = 0; j < 6; j++) {
                outputG(outfile, head, offset, mask, restSpace);
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

/**
* 根据空格数来生成数独游戏
*/
void getGameBySpace(int num, int spaces) {
    if (num < 1 || num>1e4) {
        cout << "生成失败！数独游戏数量须在1~10000之间！" << endl;
        return;
    }
    cout << "开始生成" << num << "个数独游戏！" << endl;

    //Initialize prgress bar
    milliseconds interval(1000);
    ProgressBar bar((unsigned int)num, interval);
    bar.show();

    //Open output file
    fstream outfile("game.txt", ios::out);
    if (!outfile.is_open()) {
        cout << "文件打开失败！" << endl;
        return;
    }

    int mask[9];
    for (int i = 0; i < 9; i++)
    {
        mask[i] = 1;
    }
    //让挖空均匀分布到每行中，剩余空再另找地方挖
    int lineSpace = spaces / 9;
    int restSpace = spaces % 9;
    //挖每行固定空
    do {
        int r = rand() % 9;
        if (mask[r]) {
            mask[r] = 0;
            lineSpace--;
        }
        else
            continue;
    } while (lineSpace);

    int head[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int offset[9] = { 0, 3, 6, 1, 4, 7, 2, 5, 8 };
    while (true) {
        //change the order of line 3-5, 6 arrangements
        for (int i = 0; i < 6; i++) {
            //change the order of line 6-8, 6 arrangements
            for (int j = 0; j < 6; j++) {
                outputG(outfile, head, offset, mask, restSpace);
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

