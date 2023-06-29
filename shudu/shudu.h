
#pragma once
#include"getopt.h"
#include"progress.h"
#include<iostream>
#include<fstream>
#include<algorithm>
#include<stack>
#include<assert.h>
using namespace std;

//gen_final.cpp
void getFinal(int num);
void getGameByLevel(int num, int level);
void getGameBySpace(int num, int space);
void getGameUnique(int num);
//solve.cpp
int solve(char* filename);
//shudu.cpp
int exec_sudoku(int argc, char* argv[]);

struct sudoku {
    int matrix[9][9] = { 0 };
    stack<pair<int, int>> blank;    //blank coordinates
    //use 9-bit binary numbers to stand for numbers used in each row/col/patch
    int row[9] = { 0 };
    int col[9] = { 0 };
    int patch[9] = { 0 };

    void insert(int i, int j, int num) {
        matrix[i][j] = num;
        if (num == '$') {
            blank.push(make_pair(i, j));
        }
        else {
            row[i] |= (1 << num);
            col[j] |= (1 << num);
            patch[(i / 3) * 3 + j / 3] |= (1 << num);
        }
    }

    void remove(int i, int j) {
        int num = matrix[i][j];
        if (num != '$') {
            matrix[i][j] = (int)'$';
            row[i] ^= (1 << num);
            col[j] ^= (1 << num);
            patch[(i / 3) * 3 + j / 3] ^= (1 << num);
        }
        blank.push(make_pair(i, j));
    }

    void replace(int i, int j, int newNum) {
        int oldNum = matrix[i][j];
        if (oldNum == '$') {
            insert(i, j, newNum);
        }
        else {
            matrix[i][j] = newNum;
            int mask = (1 << oldNum) | (1 << newNum);
            row[i] ^= mask;
            col[j] ^= mask;
            patch[(i / 3) * 3 + j / 3] ^= mask;
        }
    }

    int getMask(int i, int j) {
        int mask = 0;
        mask |= row[i];
        mask |= col[j];
        mask |= patch[(i / 3) * 3 + j / 3];
        return mask;
    }

    void input(fstream& f) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char val;
                f >> val;
                int num = val;
                if (val != '$') {
                    val -= '0';
                }
                insert(i, j, val);
            }
        }
        // remove empty line
        f.get();
        f.get();
    }


    void output(fstream& f) {
        for (int i = 0; i < 9; i++) {
            if(matrix[i][0] != '$')
                f << matrix[i][0];
            else
                f << '$';
            for (int j = 1; j < 9; j++) {
                if (matrix[i][j] != '$')
                    f << ' ' << matrix[i][j];
                else
                    f << " $";
            }
            f << endl;
        }
        f << endl;
    }

    int solve() {
        if (blank.empty()) {
            // No blank positions, success
            return 0;
        }
        pair<int, int> coord = blank.top();
        blank.pop();
        int mask = getMask(coord.first, coord.second);
        for (int i = 1; i <= 9; i++) {
            if ((mask & (1 << i)) == 0) {
                //Not used, search down
                replace(coord.first, coord.second, i);
                int result = solve();
                if (result == 0) {
                    return 0;
                }
            }
        }
        //coords pushed back here
        //test
        remove(coord.first, coord.second);
        return -1;
    }

    int solve_unique() {
        if (blank.empty()) {
            // No blank positions, success
            return 0;
        }
        pair<int, int> coord = blank.top();
        blank.pop();
        int result = -1;
        bool unique = true;
        int mask = getMask(coord.first, coord.second);
        for (int i = 1; i <= 9; i++) {
            if ((mask & (1 << i)) == 0) {
                //Not used, search down
                replace(coord.first, coord.second, i);
                result = solve_unique();
                if (result == 0 && unique) {
                    unique = false;
                }else if (result == 0 && !unique) {
                    return -1;
                }
            }
        }
        //coords pushed back here
        //test
        if (result == 0) {
            return 0;
        }
        remove(coord.first, coord.second);
        return -1;
    }

    void genUnique() {
        for (int i = 0; i < 3; i++) {
            int r = rand() % 9;
            int c = rand() % 9;
            if (matrix[r][c] != '$'){
                remove(r, c);
            } else {
                i--;
                continue;
            }
        }
        int maxTestNum = 81;
        for (int i = 0; i < 15; i++) {
            if (maxTestNum < 0) {
                break;
            }
            int r = rand() % 9;
            int c = rand() % 9;
            int origin = matrix[r][c];
            if (matrix[r][c] != '$') {
                remove(r, c);
            }
            else {
                i--;
                continue;
            }


            sudoku copy;
            for (int ii = 0; ii < 9; ii++) {
                memcpy_s(copy.matrix[ii], 9, matrix[ii], 9);
            }
            copy.blank = blank;
            memcpy_s(copy.row, 9, row, 9);
            memcpy_s(copy.col, 9, col, 9);
            memcpy_s(copy.patch, 9, patch, 9);
            
            if (copy.solve_unique() < 0) {
                insert(r, c, origin);
                blank.pop();
                i--;
                maxTestNum--;
                continue;
            }
        }
    }
};






