// 1. 오목판의 모든 가로, 세로줄에 대하여 흰돌의 개수와 검은돌의 개수를 출력하라.
// 2. 오목판의 모든 가로, 세로줄에 대하여 그 줄에서 가장 많이 연속으로 놓여진 돌의 종류와 개수를 출력하라.
// 3. 오목판의 모든 대각선 줄에 대하여 그 줄에서 가장 많이 연속으로 놓여진 돌의 종류와 개수를 출력하라.
// 4. 2번에서 모든 가로 줄에 대해서는 가장 많이 연속으로 놓여진 돌들의 위치를 좌표(또는 다른 모양)로 표시하라.
#include <iostream>

using namespace std;

#define OMOK_NUM 19

void PrintOmok(char omok[][OMOK_NUM]);
void Menu();
void PutStone(char omok[][OMOK_NUM], int(&RowBlackCnt)[OMOK_NUM], int(&ColBlackCnt)[OMOK_NUM], int(&RowWhiteCnt)[OMOK_NUM], int(&ColWhiteCnt)[OMOK_NUM]);
void RowColStonePrint(char omok[][OMOK_NUM], int(&RowBlackCnt)[OMOK_NUM], int(&ColBlackCnt)[OMOK_NUM], int(&RowWhiteCnt)[OMOK_NUM], int(&ColWhiteCnt)[OMOK_NUM]);
void ColContinueStone(char omok[][OMOK_NUM]);
void RowContinueStone(char omok[][OMOK_NUM]);
void RowColContinueStone(char omok[][OMOK_NUM]);
void RightUpDiagonal1(char omok[][OMOK_NUM]);
void RightUpDiagonal2(char omok[][OMOK_NUM]);
void RightDownDiagonal1(char omok[][OMOK_NUM]);
void RightDownDiagonal2(char omok[][OMOK_NUM]);
void DiagonalContinueStone(char omok[][OMOK_NUM]);
void ColStoneCheck(char omok[][OMOK_NUM]);

int main()
{
	char omok[OMOK_NUM][OMOK_NUM] = {};

	int select;
	int RowBlackStone[OMOK_NUM] = {};
	int ColBlackStone[OMOK_NUM] = {};
	int RowWhiteStone[OMOK_NUM] = {};
	int ColWhiteStone[OMOK_NUM] = {};

	while (true) {
		PrintOmok(omok);
		Menu();
		cout << "번호 입력: ";
		cin >> select;

		switch (select)
		{
		case 1:
			PutStone(omok, RowBlackStone, ColBlackStone, RowWhiteStone, ColWhiteStone);		break;
		case 2:
			RowColStonePrint(omok, RowBlackStone, ColBlackStone, RowWhiteStone, ColWhiteStone); break;
		case 3:
			RowColContinueStone(omok); break;
		case 4:
			DiagonalContinueStone(omok); break;
		case 5:
			ColStoneCheck(omok); break;
		}
	}
}

void PrintOmok(char omok[][OMOK_NUM])
{
	for (int i = 0; i < OMOK_NUM; ++i) {
		for (int j = 0; j < OMOK_NUM; ++j) {
			if (omok[i][j] != 'B' && omok[i][j] != 'W' && omok[i][j] != 'b' && omok[i][j] != 'w') {
				omok[i][j] = '+';
			}
		}
	}

	for (int i = 0; i < OMOK_NUM; ++i) {
		for (int j = 0; j < OMOK_NUM; ++j) {
			cout << omok[i][j] << " ";
		}
		cout << endl;
	}
}

void Menu()
{
	cout << "1.좌표 입력" << endl;
	cout << "2. 모든 가로, 세로줄에 대한 검은돌 흰돌 갯수" << endl;
	cout << "3. 모든 가로, 세로줄에 대한 가장 많이 연속된 돌의 종류와 갯수" << endl;
	cout << "4. 모든 대각선에 대한 가장 많이 연속된 돌의 종류와 갯수" << endl;
	cout << "5. 모든 가로줄에 대한 가장 많이 연속된 돌 표시(화면에 소문자로 나타남)" << endl;
}

void PutStone(char omok[][OMOK_NUM], int(&RowBlackCnt)[OMOK_NUM], int(&ColBlackCnt)[OMOK_NUM], int(&RowWhiteCnt)[OMOK_NUM], int(&ColWhiteCnt)[OMOK_NUM])
{
	int x, y;
	cout << "좌표 입력: ";
	cin >> x >> y;

	static bool isBlack = true;
	if (omok[x][y] == 'B' || omok[x][y] == 'W') {
		cout << "이미 돌이 놓여있습니다." << endl;
	} else {
		if (isBlack) {
			omok[x][y] = 'B';
			++RowBlackCnt[y];
			++ColBlackCnt[x];
			isBlack = false;
		} else {
			omok[x][y] = 'W';
			++RowWhiteCnt[y];
			++ColWhiteCnt[x];
			isBlack = true;
		}
	}
}

void RowColStonePrint(char omok[][OMOK_NUM], int(&RowBlackCnt)[OMOK_NUM], int(&ColBlackCnt)[OMOK_NUM], int(&RowWhiteCnt)[OMOK_NUM], int(&ColWhiteCnt)[OMOK_NUM])
{
	for (int i = 0; i < OMOK_NUM; ++i) {
		cout << i + 1 << "번째 가로 - B " << ColBlackCnt[i] << ", W " << ColWhiteCnt[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < OMOK_NUM; ++i) {
		cout << i + 1 << "번째 세로 - B " << RowBlackCnt[i] << ", W " << RowWhiteCnt[i] << endl;
	}
}

void ColContinueStone(char omok[][OMOK_NUM])
{
	for (int i = 0; i < OMOK_NUM; ++i) {
		int Bcnt_col = 0;
		int Wcnt_col = 0;
		int Bcnt_max = 0;
		int Wcnt_max = 0;
		for (int j = 0; j < OMOK_NUM - 1; ++j) {
			if (omok[i][j] == 'B') {
				++Bcnt_col;
				Wcnt_col = 0;
			} else if (omok[i][j] == 'W') {
				++Wcnt_col;
				Bcnt_col = 0;
			} else {
				Bcnt_col = 0;
				Wcnt_col = 0;
			}

			if (Bcnt_col > Bcnt_max) {
				Bcnt_max = Bcnt_col;
			}
			if (Wcnt_col > Wcnt_max) {
				Wcnt_max = Wcnt_col;
			}

		}

		if (Bcnt_max > Wcnt_max) {
			cout << i + 1 << "번째 가로줄: " << "B " << Bcnt_max << endl;
		} else if (Bcnt_max < Wcnt_max) {
			cout << i + 1 << "번째 가로줄: " << "W " << Wcnt_max << endl;
		} else if (Bcnt_max != 0 && Bcnt_max == Wcnt_max) {
			cout << i + 1 << "번째 가로줄: " << "B, W " << Wcnt_max << endl;
		} else {
			cout << i + 1 << "번째 가로줄: " << "연속없음" << endl;
		}
	}
}

void RowContinueStone(char omok[][OMOK_NUM])
{
	for (int i = 0; i < OMOK_NUM; ++i) {
		int Bcnt_row = 0;
		int Wcnt_row = 0;
		int Bcnt_max = 0;
		int Wcnt_max = 0;
		for (int j = 0; j < OMOK_NUM; ++j) {
			if (omok[j][i] == 'B') {
				++Bcnt_row;
				Wcnt_row = 0;
			} else if (omok[j][i] == 'W') {
				++Wcnt_row;
				Bcnt_row = 0;
			} else {
				Bcnt_row = 0;
				Wcnt_row = 0;
			}

			if (Bcnt_row > Bcnt_max) {
				Bcnt_max = Bcnt_row;
			}
			if (Wcnt_row > Wcnt_max) {
				Wcnt_max = Wcnt_row;
			}

		}

		if (Bcnt_max > Wcnt_max) {
			cout << i + 1 << "번째 세로줄: " << "B " << Bcnt_max << endl;
		} else if (Bcnt_max < Wcnt_max) {
			cout << i + 1 << "번째 세로줄: " << "W " << Wcnt_max << endl;
		} else if (Bcnt_max != 0 && Bcnt_max == Wcnt_max) {
			cout << i + 1 << "번째 세로줄: " << "B, W " << Wcnt_max << endl;
		} else {
			cout << i + 1 << "번째 세로줄: " << "연속없음" << endl;
		}
	}
}

void RowColContinueStone(char omok[][OMOK_NUM])
{
	ColContinueStone(omok);
	cout << endl;
	RowContinueStone(omok);
}

void RightUpDiagonal1(char omok[][OMOK_NUM])
{
	for (int i = 0; i < 18; ++i) {
		int row = i;
		int col = 0;
		int Bcnt = 0;
		int Wcnt = 0;
		int Bcnt_max = 0;
		int Wcnt_max = 0;
		while (row >= 0) {
			if (omok[row][col] == 'B') {
				++Bcnt;
				Wcnt = 0;
			} else if (omok[row][col] == 'W') {
				++Wcnt;
				Bcnt = 0;
			} else {
				Bcnt = 0;
				Wcnt = 0;
			}

			if (Bcnt > Bcnt_max) {
				Bcnt_max = Bcnt;
			}
			if (Wcnt > Wcnt_max) {
				Wcnt_max = Wcnt;
			}

			--row;
			++col;
		}

		if (Bcnt_max > Wcnt_max) {
			cout << i + 1 << "번째 우상향 대각선: " << "B " << Bcnt_max << endl;
		} else if (Bcnt_max < Wcnt_max) {
			cout << i + 1 << "번째 우상향 대각선: " << "W " << Wcnt_max << endl;
		} else if (Bcnt_max != 0 && Bcnt_max == Wcnt_max) {
			cout << i + 1 << "번째 우상향 대각선: " << "B, W " << Wcnt_max << endl;
		} else {
			cout << i + 1 << "번째 우상향 대각선: " << "연속없음" << endl;
		}
	}
}

void RightUpDiagonal2(char omok[][OMOK_NUM])
{
	for (int i = 0; i <= 18; ++i) {
		int row = 18;
		int col = i;
		int Bcnt = 0;
		int Wcnt = 0;
		int Bcnt_max = 0;
		int Wcnt_max = 0;
		while (col <= 18)
		{
			if (omok[row][col] == 'B') {
				++Bcnt;
				Wcnt = 0;
			} else if (omok[row][col] == 'W') {
				++Wcnt;
				Bcnt = 0;
			} else {
				Bcnt = 0;
				Wcnt = 0;
			}

			if (Bcnt > Bcnt_max) {
				Bcnt_max = Bcnt;
			}
			if (Wcnt > Wcnt_max) {
				Wcnt_max = Wcnt;
			}

			--row;
			++col;
		}

		if (Bcnt_max > Wcnt_max) {
			cout << i + 19 << "번째 우상향 대각선: " << "B " << Bcnt_max << endl;
		} else if (Bcnt_max < Wcnt_max) {
			cout << i + 19 << "번째 우상향 대각선: " << "W " << Wcnt_max << endl;
		} else if (Bcnt_max != 0 && Bcnt_max == Wcnt_max) {
			cout << i + 19 << "번째 우상향 대각선: " << "B, W " << Wcnt_max << endl;
		} else {
			cout << i + 19 << "번째 우상향 대각선: " << "연속없음" << endl;
		}
	}
}

void RightDownDiagonal1(char omok[][OMOK_NUM])
{
	for (int i = 18; i >= 0; --i) {
		int row = i;
		int col = 0;
		int Bcnt = 0;
		int Wcnt = 0;
		int Bcnt_max = 0;
		int Wcnt_max = 0;
		while (row <= 18) {
			if (omok[row][col] == 'B') {
				++Bcnt;
				Wcnt = 0;
			} else if (omok[row][col] == 'W') {
				++Wcnt;
				Bcnt = 0;
			} else {
				Bcnt = 0;
				Wcnt = 0;
			}

			if (Bcnt > Bcnt_max) {
				Bcnt_max = Bcnt;
			}
			if (Wcnt > Wcnt_max) {
				Wcnt_max = Wcnt;
			}

			++row;
			++col;
		}

		if (Bcnt_max > Wcnt_max) {
			cout << 19 - i << "번째 우하향 대각선: " << "B " << Bcnt_max << endl;
		} else if (Bcnt_max < Wcnt_max) {
			cout << 19 - i << "번째 우하향 대각선: " << "W " << Wcnt_max << endl;
		} else if (Bcnt_max != 0 && Bcnt_max == Wcnt_max) {
			cout << 19 - i << "번째 우하향 대각선: " << "B, W " << Wcnt_max << endl;
		} else {
			cout << 19 - i << "번째 우하향 대각선: " << "연속없음" << endl;
		}
	}
}

void RightDownDiagonal2(char omok[][OMOK_NUM])
{
	for (int i = 1; i <= 18; ++i) {
		int row = 0;
		int col = i;
		int Bcnt = 0;
		int Wcnt = 0;
		int Bcnt_max = 0;
		int Wcnt_max = 0;
		while (col <= 18) {
			if (omok[row][col] == 'B') {
				++Bcnt;
				Wcnt = 0;
			} else if (omok[row][col] == 'W') {
				++Wcnt;
				Bcnt = 0;
			} else {
				Bcnt = 0;
				Wcnt = 0;
			}

			if (Bcnt > Bcnt_max) {
				Bcnt_max = Bcnt;
			}
			if (Wcnt > Wcnt_max) {
				Wcnt_max = Wcnt;
			}

			++row;
			++col;
		}

		if (Bcnt_max > Wcnt_max) {
			cout << 19 + i << "번째 우하향 대각선: " << "B " << Bcnt_max << endl;
		} else if (Bcnt_max < Wcnt_max) {
			cout << 19 + i << "번째 우하향 대각선: " << "W " << Wcnt_max << endl;
		} else if (Bcnt_max != 0 && Bcnt_max == Wcnt_max) {
			cout << 19 + i << "번째 우하향 대각선: " << "B, W " << Wcnt_max << endl;
		} else {
			cout << 19 + i << "번째 우하향 대각선: " << "연속없음" << endl;
		}
	}
}

void DiagonalContinueStone(char omok[][OMOK_NUM])
{
	RightUpDiagonal1(omok);
	RightUpDiagonal2(omok);
	cout << endl;
	RightDownDiagonal1(omok);
	RightDownDiagonal2(omok);
}

void ColStoneCheck(char omok[][OMOK_NUM])
{
	for (int i = 0; i < OMOK_NUM; ++i) {
		int Bcnt_col = 0;
		int Wcnt_col = 0;
		int Bcnt_max = 0;
		int Wcnt_max = 0;
		char ColStone[OMOK_NUM] = {};
		for (int j = 0; j < OMOK_NUM - 1; ++j) {
			if (omok[i][j] == 'B') {
				ColStone[j] = 'B';
				++Bcnt_col;
				Wcnt_col = 0;
			} else if (omok[i][j] == 'W') {
				ColStone[j] = 'W';
				++Wcnt_col;
				Bcnt_col = 0;
			} else {
				ColStone[j] = 0;
				Bcnt_col = 0;
				Wcnt_col = 0;
			}

			if (Bcnt_col > Bcnt_max) {
				Bcnt_max = Bcnt_col;
			}
			if (Wcnt_col > Wcnt_max) {
				Wcnt_max = Wcnt_col;
			}

		}

		int cnt_b = 0;
		int cnt_w = 0;
		if (Bcnt_max > Wcnt_max) {
			for (int j = 0; j < OMOK_NUM; ++j) {
				if (ColStone[j] == 'B') {
					++cnt_b;
				} else {
					cnt_b = 0;
				}

				if (cnt_b == Bcnt_max) {
					for (int k = j - cnt_b + 1; k < j + 1; ++k) {
						omok[i][k] = 'b';
					}
					cnt_b = 0;
				}
			}
		} else if (Bcnt_max < Wcnt_max) {
			for (int j = 0; j < OMOK_NUM; ++j) {
				if (ColStone[j] == 'W') {
					++cnt_w;
				} else {
					cnt_w = 0;
				}

				if (cnt_w == Wcnt_max) {
					for (int k = j - cnt_w + 1; k < j + 1; ++k) {
						omok[i][k] = 'w';
					}
					cnt_w = 0;
				}
			}
		} else if (Bcnt_max != 0 && Bcnt_max == Wcnt_max) {
			for (int j = 0; j < OMOK_NUM; ++j) {
				if (ColStone[j] == 'W') {
					++cnt_w;
				} else {
					cnt_w = 0;
				}

				if (cnt_w == Wcnt_max) {
					for (int k = j - cnt_w + 1; k < j + 1; ++k) {
						omok[i][k] = 'w';
					}
					cnt_w = 0;
				}
			}

			for (int j = 0; j < OMOK_NUM; ++j) {
				if (ColStone[j] == 'B') {
					++cnt_b;
				} else {
					cnt_b = 0;
				}

				if (cnt_b == Bcnt_max) {
					for (int k = j - cnt_b + 1; k < j + 1; ++k) {
						omok[i][k] = 'b';
					}
					cnt_b = 0;
				}
			}
		}
	}
}