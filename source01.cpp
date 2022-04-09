// 1. �������� ��� ����, �����ٿ� ���Ͽ� ���� ������ �������� ������ ����϶�.
// 2. �������� ��� ����, �����ٿ� ���Ͽ� �� �ٿ��� ���� ���� �������� ������ ���� ������ ������ ����϶�.
// 3. �������� ��� �밢�� �ٿ� ���Ͽ� �� �ٿ��� ���� ���� �������� ������ ���� ������ ������ ����϶�.
// 4. 2������ ��� ���� �ٿ� ���ؼ��� ���� ���� �������� ������ ������ ��ġ�� ��ǥ(�Ǵ� �ٸ� ���)�� ǥ���϶�.
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
		cout << "��ȣ �Է�: ";
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
	cout << "1.��ǥ �Է�" << endl;
	cout << "2. ��� ����, �����ٿ� ���� ������ �� ����" << endl;
	cout << "3. ��� ����, �����ٿ� ���� ���� ���� ���ӵ� ���� ������ ����" << endl;
	cout << "4. ��� �밢���� ���� ���� ���� ���ӵ� ���� ������ ����" << endl;
	cout << "5. ��� �����ٿ� ���� ���� ���� ���ӵ� �� ǥ��(ȭ�鿡 �ҹ��ڷ� ��Ÿ��)" << endl;
}

void PutStone(char omok[][OMOK_NUM], int(&RowBlackCnt)[OMOK_NUM], int(&ColBlackCnt)[OMOK_NUM], int(&RowWhiteCnt)[OMOK_NUM], int(&ColWhiteCnt)[OMOK_NUM])
{
	int x, y;
	cout << "��ǥ �Է�: ";
	cin >> x >> y;

	static bool isBlack = true;
	if (omok[x][y] == 'B' || omok[x][y] == 'W') {
		cout << "�̹� ���� �����ֽ��ϴ�." << endl;
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
		cout << i + 1 << "��° ���� - B " << ColBlackCnt[i] << ", W " << ColWhiteCnt[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < OMOK_NUM; ++i) {
		cout << i + 1 << "��° ���� - B " << RowBlackCnt[i] << ", W " << RowWhiteCnt[i] << endl;
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
			cout << i + 1 << "��° ������: " << "B " << Bcnt_max << endl;
		} else if (Bcnt_max < Wcnt_max) {
			cout << i + 1 << "��° ������: " << "W " << Wcnt_max << endl;
		} else if (Bcnt_max != 0 && Bcnt_max == Wcnt_max) {
			cout << i + 1 << "��° ������: " << "B, W " << Wcnt_max << endl;
		} else {
			cout << i + 1 << "��° ������: " << "���Ӿ���" << endl;
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
			cout << i + 1 << "��° ������: " << "B " << Bcnt_max << endl;
		} else if (Bcnt_max < Wcnt_max) {
			cout << i + 1 << "��° ������: " << "W " << Wcnt_max << endl;
		} else if (Bcnt_max != 0 && Bcnt_max == Wcnt_max) {
			cout << i + 1 << "��° ������: " << "B, W " << Wcnt_max << endl;
		} else {
			cout << i + 1 << "��° ������: " << "���Ӿ���" << endl;
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
			cout << i + 1 << "��° ����� �밢��: " << "B " << Bcnt_max << endl;
		} else if (Bcnt_max < Wcnt_max) {
			cout << i + 1 << "��° ����� �밢��: " << "W " << Wcnt_max << endl;
		} else if (Bcnt_max != 0 && Bcnt_max == Wcnt_max) {
			cout << i + 1 << "��° ����� �밢��: " << "B, W " << Wcnt_max << endl;
		} else {
			cout << i + 1 << "��° ����� �밢��: " << "���Ӿ���" << endl;
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
			cout << i + 19 << "��° ����� �밢��: " << "B " << Bcnt_max << endl;
		} else if (Bcnt_max < Wcnt_max) {
			cout << i + 19 << "��° ����� �밢��: " << "W " << Wcnt_max << endl;
		} else if (Bcnt_max != 0 && Bcnt_max == Wcnt_max) {
			cout << i + 19 << "��° ����� �밢��: " << "B, W " << Wcnt_max << endl;
		} else {
			cout << i + 19 << "��° ����� �밢��: " << "���Ӿ���" << endl;
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
			cout << 19 - i << "��° ������ �밢��: " << "B " << Bcnt_max << endl;
		} else if (Bcnt_max < Wcnt_max) {
			cout << 19 - i << "��° ������ �밢��: " << "W " << Wcnt_max << endl;
		} else if (Bcnt_max != 0 && Bcnt_max == Wcnt_max) {
			cout << 19 - i << "��° ������ �밢��: " << "B, W " << Wcnt_max << endl;
		} else {
			cout << 19 - i << "��° ������ �밢��: " << "���Ӿ���" << endl;
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
			cout << 19 + i << "��° ������ �밢��: " << "B " << Bcnt_max << endl;
		} else if (Bcnt_max < Wcnt_max) {
			cout << 19 + i << "��° ������ �밢��: " << "W " << Wcnt_max << endl;
		} else if (Bcnt_max != 0 && Bcnt_max == Wcnt_max) {
			cout << 19 + i << "��° ������ �밢��: " << "B, W " << Wcnt_max << endl;
		} else {
			cout << 19 + i << "��° ������ �밢��: " << "���Ӿ���" << endl;
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