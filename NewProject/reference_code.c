#pragma warning(disable:4996)
#include <stdio.h> //ǥ������� ���� >> ��������� �����غ���
#include <stdlib.h> //���ڿ� ��ȣ���� ������������
#include <time.h>  //�ð����� �Լ� ����
#include <Windows.h> //�ܼ� ����� ����
#include <conio.h>  //������ ����
#define wordmax 103//�ܾ��� ����
#define wordtime 23000//�ܾ �ߴ� �ӵ�

time_t startTime = 0, endTime = 0;// ���� �ð� ����
int gap; //���۽ð��� ������ �ð��� ���̰��� �ִ� �Լ�
void gotoxy(int x, int y)//Ŀ�� ��ġ ���� �Լ�
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void help();// ������ ��Ÿ���� �Լ�
void gamemain();// ���� ����ȭ���� ��Ÿ���� �Լ�
void printword();// �ܾ ȭ�鿡 ����ϴ� �Լ�
void scanword();// �ܾ �Է� �޴� �Լ�
void design();// ���� �������� �ֿܼ� ���� �Լ�
void start();// ���� ���� �ʱ� ȭ���� ��Ÿ���� �Լ�
void bestscore();// �ְ������� �����ϴ� �Լ�
void removeCursor();// printf���� �ܾ �߰��Ҷ� Ŀ���� �����ϴ� �Լ�

char word[256][256] = { "dog", "cat", "bottle", "phone", "robot", "green", "elephant", "include", "sky", "game", "hyomin", "jaemin", "max",//�ܾ� DB

"knife", "glass", "class", "art", "smart", "bell", "carry", "climb", "between", "blow", "album", "ago", "among", "animal", "any", "box",

"and", "board", "body", "child", "classmate", "city", "boy", "bridge", "clean",

"club", "coat", "bright", "coin", "chopstick", "coffee", "cold", "chance", "chalk", "chair", "cheap", "blue",

"before", "bowl", "aunt", "as", "away", "bicycle", "church", "card", "hold",

"chose", "come", "drink", "give", "get", "hurt", "lay","had", "feed", "lend", "met", "wsing", "throw", "wet", "tell",

"set", "wind", "wear", "write", "spend", "stand", "worn", "win", "sweep", "account", "achieve", "across", "accept", "above", "ability", "abuse",

"abnormal", "absurd", "acceptance", "according", "absent", "nation", "past", "value", "though", "person", "machine", "stand", "null" };

int wordi[250];// �ѹ� �� �ܾ���� �ȶ߰� ���ֱ� ���� ��������
int x, y;// gotoxy �� x���� y��
int i;// �ܾ� ��
int j, k;
int a;// �ܾ� �� �� ���� �� ����
int s;// kbhit
int c;// �ݺ����迭
int x2, y2;// x,y���� �ٽ� �ҷ��� �� ����
int g;
int score1 = 0;// ����
int h;//�ʱ�ȭ�鿡�� �Է� ������ ����
int f;// ����
int f2;// ���� ���� �ٽ� �ҷ��ö� ����
int sword;
int level = 1;
int bestsc = 0;
char scan[50];
char remem[256][3] = { 0 };

int main() { // �����Լ�
	srand((unsigned)time(NULL)); // ������ ����
	system("mode con cols=120 lines=30"); //�ܼ� â ũ������
	design();
	Sleep(1500); //�Լ� ȣ�� �ð� ����
	gotoxy(60, 9); // ��ǥ����
	removeCursor(); //Ŀ���� ���ִ� �Լ� ȣ��
	start(); // ����ȭ���� ����ϴ� �Լ� ȣ��

	while (1) { //����������
		gotoxy(60, 15); //��ǥ����
		scanf("%d", &h); //h ���� �Է¹���
		gotoxy(60, 15); //��ǥ����

		switch (h)
		{
		case 1: score1 = 0; startTime = clock(); gamemain(); gap = 0; break; // 1�� �Է��ϸ� ���ӽ���
		case 2: help(); break; // 2�� �Է��ϸ� ���� ����ϴ� �Լ� ȣ��
		case 3: bestscore(); break; //3�� �Է��ϸ� ���� ������ Ȯ���� �� �ִ� �Լ� ȣ��
		case 4: return 0; break; //4�� �Է��ϸ� ���ư���
		default: printf("�ùٸ� Ű�� �ƴմϴ�!"); break; //1,2,3,4 �̿��� ���ڸ� �Է��� �� �����޼��� 
		}
	}
}

void design() { // ���� �������� �ֿܼ� ���� �Լ�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("|---------------------------------------------------------------------------------------------------------------------|\n");
	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|---------------------------------------------------------------------------------------------------------------------|\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|                                                                                                                     |\n");

	printf("|---------------------------------------------------------------------------------------------------------------------|");

}

void help() { // ������ ��Ÿ���� �Լ�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("cls");
	design();
	gotoxy(40, 7); //��ǥ����
	printf("-�������ͳݰ���б� 10319 ��ȿ�� ����\n");
	gotoxy(40, 9); //��ǥ����
	printf("-����ȹ� �ߴ� �ܾ���� ���� �Է��Ͽ� �����ּ���!\n");
	gotoxy(40, 11); //��ǥ����
	printf("-������ ���� ������ �ٸ��ϴ�!");
	gotoxy(40, 12); //��ǥ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); //�ֿܼ��� �� ����ϴ� ��
	printf("�� �� : 150�� ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //�ֿܼ��� �� ����ϴ� ��
	printf("�� �� : 200�� ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //�ֿܼ��� �� ����ϴ� ��
	printf("�� �� : 250�� ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //�ֿܼ��� �� ����ϴ� ��
	printf("�� �� : 300�� ");
	gotoxy(40, 14);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //�ֿܼ��� �� ����ϴ� ��
	printf("-30�� ���� ������ ����˴ϴ�!! ������ �ڵ����� ����˴ϴ�.");
	gotoxy(40, 15);
	printf("-�ְ������� ����˴ϴ�. ���θ޴� 3. �������⿡�� Ȯ�� �����մϴ�.\n");
	gotoxy(40, 16);
	printf("-�ƹ�Ű�� ������ ���� �޴��� ���ư��ϴ�.\n");
	g = getch();
	if (_kbhit)
	{
		start(); // ������ �����ϴ� �Լ� ȣ��
	}
}

void bestscore() { // �ְ������� �����ϴ� �Լ�
	system("cls");
	design(); //ȭ�� �������� ����ϴ� �Լ� ���
	if (bestsc < score1) //�� ������ ���� �ְ��������� ������
	{
		bestsc = score1; ///�ְ������� �� ������ ����
	}
	gotoxy(50, 7); //��ǥ ����
	printf("�ְ����� : %d", bestsc); //�ְ����� ���
	gotoxy(40, 13); //��ǥ ����
	printf("�ƹ�Ű�� ������ ���� �޴��� ���ư��ϴ�.\n");
	g = getch();
	if (_kbhit)
	{
		start(); // �ٽý���
	}

}

void gamemain() { // ���� ����ȭ���� ��Ÿ���� �Լ�
	system("cls");
	design();
	gotoxy(50, 9);
	printf(" 3�� �� ���� !!");
	Sleep(1000); //�Լ� ȣ�� �ð� ����
	system("cls");
	design();
	gotoxy(50, 9); 
	printf(" 2�� �� ���� !!");
	Sleep(1000); //�Լ� ȣ�� �ð� ����
	system("cls");
	design();
	gotoxy(50, 9);
	printf(" 1�� �� ���� !!");
	Sleep(1000); //�Լ� ȣ�� �ð� ����
	system("cls");
	design();
	while (1) { //����
		printword(); //�ܾ ����ϴ� �Լ� ȣ��
		scanword(); // �ܾ �Է¹޴� �Լ� ȣ��
	}
}

void printword() { // �ܾ ȭ�鿡 ����ϴ� �Լ�
	static int check = wordmax;
	x = rand() % 105 + 5;
	y = rand() % 19 + 3;
	i = rand() % wordmax;
	f = rand() % 4 + 1;
	if (wordi[i] != 1) {
		wordi[i] = 1;
		check--;
		gotoxy(x, y);
		for (j = 0; j < 3; j++)
		{
			if (j == 0) {
				remem[i][j] = x;
			}
			else if (j == 1) {
				remem[i][j] = y;
			}
			else if (j == 2) {
				remem[i][j] = f;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), f);
		printf("%s ", word[i]); //�ܾ� ���
	}
}

void scanword() { //���ڸ� �Է¹޴� �Լ�
	int p = 0;
	while (p < wordtime) {
		p++;
		i = 0;
		int scanc;
		endTime = clock();
		gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC); //�ð��� �ʰ��Ǹ�
		if (gap > 30) { //�������ӽð� 30s
			system("cls");
			design();
			gotoxy(50, 11);
			printf("---�� �� �� ��---"); //���� �޼��� ���
			Sleep(2000); //�Լ� ȣ�� �ð� ����
			main(); //�����Լ� ȣ��
		}
		if (_kbhit()) {
			scanc = getch();
			if (scanc != 8 && scanc != 13) {
				gotoxy(5, 25);
				scan[sword++] = scanc;
				printf("                 ");
				gotoxy(5, 25);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("%s", scan);
			}
			else if (scanc == 8) {
				gotoxy(1, 25);
				printf("|                                                                                                                     |\n");
				gotoxy(5, 25);
				scan[--sword] = scanc;
				if (sword == -1)
					sword = 0;
				printf("%s", scan);
			}
			else if (scanc == 13) {
				sword = 0;
				gotoxy(1, 25);
				printf("|                                                                                                                     |\n");
				for (i = 0; i <= wordmax; i++)
				{
					if (!strcmp(scan, word[i]))
					{
						x2 = remem[i][0];
						y2 = remem[i][1];
						f2 = remem[i][2];
						gotoxy(x2, y2);
						printf("          ");
						gotoxy(1, 25);
						printf("|                                                                                                                     |\n");

						switch (f2) {
						case 1: score1 += 150; break; //150�� ����
						case 2: score1 += 200; break; //200�� ����
						case 3: score1 += 250; break; //250�� ����
						case 4: score1 += 300; break; //300�� ����
						default: break;
						}
						gotoxy(3, 2);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						printf("�������� :%d", score1); //�������� ���
					}
				}
				for (i = 0; i < 50; i++) {
					scan[i] = NULL;
				}

			}

		}

	}

}

void start() { // ���� ȭ���� ���� �Լ�

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("cls");
	design();
	gotoxy(50, 7);
	printf(" ȿ��Ÿ�ڿ����� V1.0                        \n");
	gotoxy(50, 8);
	printf("-������ ��ȿ��           \n");
	gotoxy(50, 9);
	printf(" 1. ���ӽ���                  \n");
	gotoxy(50, 10);
	printf(" 2. ����                  \n");
	gotoxy(50, 11);
	printf(" 3. ���� ����                \n");
	gotoxy(50, 12);
	printf(" 4. ���� ����                  \n");
	gotoxy(50, 14);
	printf("  Ű�� ��������                       \n");
}

void removeCursor() // printf���� �ܾ �߰��Ҷ� Ŀ���� �����ϴ� �Լ�

{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0; //Ŀ���� ������ �ʰ� ��
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}