#include"shudu.h"
using namespace std;



void solve(char* filename) {
    fstream infile(filename, ios::in);
    fstream outfile("suduku.txt", ios::out);
    if (!infile.is_open()) {
        cout << "�ļ���ʧ�ܣ�" << endl;
        return;
    }
    cout << "������⣬���Ժ�..." << endl;
    int i = 1;
    while (infile.peek()!=EOF) {
        sudoku board;
        board.input(infile);
        int result = board.solve();
        if (result == 0) {
            board.output(outfile);
        }
        else {
            cout << "��"<< i <<"�������޽⣡" << endl;
            outfile << "No Solution" << endl <<endl;
        }
    }
}