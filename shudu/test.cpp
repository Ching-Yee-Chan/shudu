#include "pch.h"


TEST(TestFinal, testFinalNeg1) {
	char* argv1[10] = { "test", "-c", "-1" };
	EXPECT_EQ(exec_sudoku(3, argv1), -1);
}
TEST(TestFinal, testFinalNeg2) {
	char* argv2[10] = { "test", "-c", "1000001" };
	EXPECT_EQ(exec_sudoku(3, argv2), -1);
}

TEST(TestFinal, testFinalNeg3) {
	char* argv3[10] = { "test", "-c", "-1000" };
	EXPECT_EQ(exec_sudoku(3, argv3), -1);
}

TEST(TestGame, testGameLevelPos1) {
	char* argv2[10] = { "test", "-n", "10000", "-m","1" };
	EXPECT_EQ(exec_sudoku(5, argv2), 0);
}

TEST(TestGame, testGameLevelPos2) {
	char* argv3[10] = { "test", "-n", "1", "-m", "2" };
	EXPECT_EQ(exec_sudoku(5, argv3), 0);
}

TEST(TestGame, testGameLevelPos3) {
	char* argv4[10] = { "test", "-n", "10000", "-m", "3" };
	EXPECT_EQ(exec_sudoku(5, argv4), 0);
}
TEST(TestGame, testGameLevelNeg1) {
	char* argv1[10] = { "test", "-n", "1", "-m", "-1" };
	EXPECT_EQ(exec_sudoku(5, argv1), -1);
}

TEST(TestGame, testGameLevelNeg2) {
	char* argv2[10] = { "test", "-n", "1", "-m", "4" };
	EXPECT_EQ(exec_sudoku(5, argv2), -1);
}

TEST(TestGame, testGameLevelNeg3) {
	char* argv3[10] = { "test", "-n", "-1", "-m", "1" };
	EXPECT_EQ(exec_sudoku(5, argv3), -1);
}

TEST(TestGame, testGameLevelNeg4) {
	char* argv4[10] = { "test", "-n", "10001", "-m", "1" };
	EXPECT_EQ(exec_sudoku(5, argv4), -1);
}



TEST(TestGame, testGameSpacePos) {
	char* argv1[10] = { "test", "-n", "1", "-r", "55" };
	EXPECT_EQ(exec_sudoku(5, argv1), 0);
}

TEST(TestGame, testGameSpaceNeg1) {
	char* argv1[10] = { "test", "-n", "1", "-m", "19" };
	EXPECT_EQ(exec_sudoku(5, argv1), -1);
}

TEST(TestGame, testGameSpaceNeg2) {
	char* argv2[10] = { "test", "-n", "1", "-m", "56" };
	EXPECT_EQ(exec_sudoku(5, argv2), -1);
}

TEST(TestGame, testGameSpaceNeg3) {
	char* argv3[10] = { "test", "-n", "-1", "-m", "23" };
	EXPECT_EQ(exec_sudoku(5, argv3), -1);
}

TEST(TestGame, testGameSpaceNeg4) {
	char* argv4[10] = { "test", "-n", "10001", "-m", "24" };
	EXPECT_EQ(exec_sudoku(5, argv4), -1);
}




TEST(TestGame, testGameUniquePos) {
	char* argv4[10] = { "test", "-n", "1000", "-u"};
	EXPECT_EQ(exec_sudoku(4, argv4), 0);
}

TEST(TestGame, testGameUniqueNeg1) {
	char* argv1[10] = { "test", "-n", "-1", "-u" };
	EXPECT_EQ(exec_sudoku(4, argv1), -1);
}

TEST(TestGame, testGameUniqueNeg2) {
	char* argv2[10] = { "test", "-n", "10001", "-u" };
	EXPECT_EQ(exec_sudoku(4, argv2), -1);
}

TEST(TestSolve, testSolvePos) {
	char* argv1[10] = { "test", "-s", "game.txt"};
	EXPECT_EQ(exec_sudoku(3, argv1), 0);
}


TEST(TestSolve, testSolveNeg2) {
	char* argv2[] = { "test", "-s", "NotExistingFile.txt" };
	EXPECT_EQ(exec_sudoku(3, argv2), -1);
}


TEST(TestArg, testArgNeg) {
	char* argv1[10] = { "test", "-wrong", "gameNeg.txt" };
	EXPECT_EQ(exec_sudoku(3, argv1), -1);
}


