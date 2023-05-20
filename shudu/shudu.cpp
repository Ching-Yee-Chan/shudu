#include<iostream>
#include"getopt.h"
using namespace std;

int main(int argc, char* argv[]) {
    int opt = 0;
    while ((opt = getopt(argc, argv, "c:s:n:m:r:u")) != -1) {
        switch (opt) {
        case 'c':
            int num;
            num = atoi(optarg);
            cout << "C! With" << num <<endl;
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