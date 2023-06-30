#include"shudu.h"
using namespace std;


void getGameUnique(int num) {
    getFinal(num);
    fstream infile("final.txt", ios::in);
    fstream outfile("uniqueGames.txt", ios::out);
    if (!infile.is_open()) {
        cout << "�ļ���ʧ�ܣ�" << endl;
        return;
    }
    int i = 1;
    while (infile.peek() != EOF) {
        sudoku board;
        board.input(infile);
        board.genUnique();
        board.output(outfile);
    }
}

