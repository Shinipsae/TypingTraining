#pragma warning(disable:4996)
#include <stdio.h> //표준입출력 지원 >> 파일입출력 구현해보기
#include <stdlib.h> //문자열 변호나과 난수생성지원
#include <time.h>  //시간관련 함수 지원
#include <Windows.h> //콘솔 입출력 지원
#include <conio.h>  //윈도우 지원
#define wordmax 103//단어의 개수
#define wordtime 23000//단어가 뜨는 속도

time_t startTime = 0, endTime = 0;// 게임 시간 제한
int gap; //시작시간과 끝내는 시간의 차이값을 넣는 함수
void gotoxy(int x, int y)//커서 위치 조정 함수
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void help();// 도움말을 나타내는 함수
void gamemain();// 게임 메인화면을 나타내는 함수
void printword();// 단어를 화면에 출력하는 함수
void scanword();// 단어를 입력 받는 함수
void design();// 게임 디자인을 콘솔에 띄우는 함수
void start();// 게임 시작 초기 화면을 나타내는 함수
void bestscore();// 최고점수를 갱신하는 함수
void removeCursor();// printf에서 단어를 뜨게할때 커서를 제거하는 함수

char word[256][256] = { "dog", "cat", "bottle", "phone", "robot", "green", "elephant", "include", "sky", "game", "hyomin", "jaemin", "max",//단어 DB

"knife", "glass", "class", "art", "smart", "bell", "carry", "climb", "between", "blow", "album", "ago", "among", "animal", "any", "box",

"and", "board", "body", "child", "classmate", "city", "boy", "bridge", "clean",

"club", "coat", "bright", "coin", "chopstick", "coffee", "cold", "chance", "chalk", "chair", "cheap", "blue",

"before", "bowl", "aunt", "as", "away", "bicycle", "church", "card", "hold",

"chose", "come", "drink", "give", "get", "hurt", "lay","had", "feed", "lend", "met", "wsing", "throw", "wet", "tell",

"set", "wind", "wear", "write", "spend", "stand", "worn", "win", "sweep", "account", "achieve", "across", "accept", "above", "ability", "abuse",

"abnormal", "absurd", "acceptance", "according", "absent", "nation", "past", "value", "though", "person", "machine", "stand", "null" };

int wordi[250];// 한번 뜬 단어들은 안뜨게 해주기 위해 만들어놓음
int x, y;// gotoxy 의 x값과 y값
int i;// 단어 수
int j, k;
int a;// 단어 수 와 같은 수 변수
int s;// kbhit
int c;// 반복문배열
int x2, y2;// x,y값을 다시 불러올 때 변수
int g;
int score1 = 0;// 점수
int h;//초기화면에서 입력 받을때 변수
int f;// 색깔
int f2;// 색깔 값을 다시 불러올때 변수
int sword;
int level = 1;
int bestsc = 0;
char scan[50];
char remem[256][3] = { 0 };

int main() { // 메인함수
	srand((unsigned)time(NULL)); // 랜덤값 지정
	system("mode con cols=120 lines=30"); //콘솔 창 크기조절
	design();
	Sleep(1500); //함수 호출 시간 지연
	gotoxy(60, 9); // 좌표설정
	removeCursor(); //커서를 없애는 함수 호출
	start(); // 시작화면을 출력하는 함수 호출

	while (1) { //연속적으로
		gotoxy(60, 15); //좌표설정
		scanf("%d", &h); //h 값을 입력받음
		gotoxy(60, 15); //좌표설정

		switch (h)
		{
		case 1: score1 = 0; startTime = clock(); gamemain(); gap = 0; break; // 1을 입력하면 게임시작
		case 2: help(); break; // 2를 입력하면 도움말 출력하는 함수 호출
		case 3: bestscore(); break; //3을 입력하면 누적 점수를 확인할 수 있는 함수 호출
		case 4: return 0; break; //4를 입력하면 돌아가기
		default: printf("올바른 키가 아닙니다!"); break; //1,2,3,4 이외의 숫자를 입력할 때 오류메세지 
		}
	}
}

void design() { // 게임 디자인을 콘솔에 띄우는 함수
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

void help() { // 도움말을 나타내는 함수
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("cls");
	design();
	gotoxy(40, 7); //좌표설정
	printf("-선린인터넷고등학교 10319 이효민 제작\n");
	gotoxy(40, 9); //좌표설정
	printf("-사방팔방 뜨는 단어들을 빨리 입력하여 없애주세요!\n");
	gotoxy(40, 11); //좌표설정
	printf("-색마다 점수 배점이 다릅니다!");
	gotoxy(40, 12); //좌표설정
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); //콘솔에서 색 출력하는 법
	printf("이 색 : 150점 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //콘솔에서 색 출력하는 법
	printf("이 색 : 200점 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //콘솔에서 색 출력하는 법
	printf("이 색 : 250점 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //콘솔에서 색 출력하는 법
	printf("이 색 : 300점 ");
	gotoxy(40, 14);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //콘솔에서 색 출력하는 법
	printf("-30초 동안 게임이 진행됩니다!! 끝나면 자동으로 종료됩니다.");
	gotoxy(40, 15);
	printf("-최고점수가 저장됩니다. 메인메뉴 3. 점수보기에서 확인 가능합니다.\n");
	gotoxy(40, 16);
	printf("-아무키나 누르면 메인 메뉴로 돌아갑니다.\n");
	g = getch();
	if (_kbhit)
	{
		start(); // 게임을 시작하는 함수 호출
	}
}

void bestscore() { // 최고점수를 갱신하는 함수
	system("cls");
	design(); //화면 디자인을 출력하는 함수 출력
	if (bestsc < score1) //현 점수가 기존 최고점수보다 높으면
	{
		bestsc = score1; ///최고점수에 현 점수를 갱신
	}
	gotoxy(50, 7); //좌표 설정
	printf("최고점수 : %d", bestsc); //최고점수 출력
	gotoxy(40, 13); //좌표 설정
	printf("아무키나 누르면 메인 메뉴로 돌아갑니다.\n");
	g = getch();
	if (_kbhit)
	{
		start(); // 다시시작
	}

}

void gamemain() { // 게임 메인화면을 나타내는 함수
	system("cls");
	design();
	gotoxy(50, 9);
	printf(" 3초 후 시작 !!");
	Sleep(1000); //함수 호출 시간 지연
	system("cls");
	design();
	gotoxy(50, 9); 
	printf(" 2초 후 시작 !!");
	Sleep(1000); //함수 호출 시간 지연
	system("cls");
	design();
	gotoxy(50, 9);
	printf(" 1초 후 시작 !!");
	Sleep(1000); //함수 호출 시간 지연
	system("cls");
	design();
	while (1) { //연속
		printword(); //단어를 출력하는 함수 호출
		scanword(); // 단어를 입력받는 함수 호출
	}
}

void printword() { // 단어를 화면에 출력하는 함수
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
		printf("%s ", word[i]); //단어 출력
	}
}

void scanword() { //문자를 입력받는 함수
	int p = 0;
	while (p < wordtime) {
		p++;
		i = 0;
		int scanc;
		endTime = clock();
		gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC); //시간이 초과되면
		if (gap > 30) { //게임지속시간 30s
			system("cls");
			design();
			gotoxy(50, 11);
			printf("---게 임 종 료---"); //종료 메세지 출력
			Sleep(2000); //함수 호출 시간 지연
			main(); //메인함수 호출
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
						case 1: score1 += 150; break; //150점 누적
						case 2: score1 += 200; break; //200점 누적
						case 3: score1 += 250; break; //250점 누적
						case 4: score1 += 300; break; //300점 누적
						default: break;
						}
						gotoxy(3, 2);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						printf("현재점수 :%d", score1); //현재점수 출력
					}
				}
				for (i = 0; i < 50; i++) {
					scan[i] = NULL;
				}

			}

		}

	}

}

void start() { // 시작 화면을 띄우는 함수

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("cls");
	design();
	gotoxy(50, 7);
	printf(" 효민타자연습기 V1.0                        \n");
	gotoxy(50, 8);
	printf("-제작자 이효민           \n");
	gotoxy(50, 9);
	printf(" 1. 게임시작                  \n");
	gotoxy(50, 10);
	printf(" 2. 도움말                  \n");
	gotoxy(50, 11);
	printf(" 3. 점수 보기                \n");
	gotoxy(50, 12);
	printf(" 4. 게임 종료                  \n");
	gotoxy(50, 14);
	printf("  키를 누르세요                       \n");
}

void removeCursor() // printf에서 단어를 뜨게할때 커서를 제거하는 함수

{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0; //커서를 보이지 않게 함
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}