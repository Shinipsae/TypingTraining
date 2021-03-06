#define _CRT_SECURE_NO_WARNINGS //scanf 오류방지 메세지
#define word_max 100 //단어의 개수

#include <stdio.h> //표준입출력 지원
#include <stdlib.h> //rand()함수 지원
#include <time.h>  //time()함수 지원
#include <Windows.h> //system(), sleep()함수 지원
#include <conio.h>  //kbhit() 함수 지원

time_t beginningTime = 0, endingTime = 0;// 게임 시간 제한
int time_gap; //시작시간과 끝내는 시간의 차이값을 넣는 함수

void gotoxy(int x, int y) //커서 위치 조정 함수
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void game_help(); //게임 도움말을 나타내는 함수
void main_screen(); //게임 메인화면을 나타내는 함수
void printfword(); //단어를 화면에 출력하는 함수
void scanfword(); //단어를 입력 받는 함수
void sc_design(); //게임 창 디자인을 구성하는 함수
void start_screen(); //게임 초기 화면을 나타내는 함수
void view_bestscore(); //최고점수를 보여주는 함수
void wordlist(); //단어목록을 출력하는 함수
void removeCursor(); //커서를 제거하는 함수

char word[256][256] = { "system","out","println" ,"print","sysout","printf","scanf","%d","%s","void","int","double",
"char","String","public","class","private","this","set","get","return","i++","i--","==","if","else","for","do","while",
"static","final","new","Class","Scanner","scan","main","args","extends","implement","boolean","true","false","import",
"util","package","nextInt","nextDouble","equals","break","switch","case","arr","%","&&","||","c","java","python",
"programming","coding","mirim","NULL" }; //2차원 배열 선언후 게임에 출력될 단어 초기화

int level_option; //난이도를 조정하는 옵션 정수형변수
int word_speed; //단어가 뜨는 속도에 따른 난이도 조절
char scan[50]; //입력받는 단어배열
char re_coordinate[256][4] = { 0 }; //좌표 재배치
int non_rcsvWord[256];// 딘어 중복출력 방지하는 배열
int option; //초기화면 옵션 정수형변수
int x, y;// gotoxy()함수에서 필요한 변수
int x_re, y_re; //x, y 값을 다시 불러오는 변수
int _get; //getch()함수 사용시 대입할 변수
int _kb; //kbhit()함수 사용시 대입할 변수
int wordcolor; //단어의 색깔
int wordcolor_2; //단어의 색깔을 다시 불러오는 변수
int score = 0; //게임점수 초기화
int bestscore = 0; //최고점수 초기화
int arr_num; //단어 입력이나 삭제시 필요한 변수

int main()
{ 
	srand((unsigned)time(NULL)); //난수생성위한 srand() 함수
	system("mode con cols = 120 lines = 30"); //콘솔 창 크기조절
	sc_design(); //게임 창 디자인
	gotoxy(60, 9); //좌표설정
	removeCursor(); //커서를 없애는 함수 호출
	start_screen(); //시작화면을 출력하는 함수 호출

	while (1) { //true

		gotoxy(65, 18); //좌표설정
		scanf("%d", &option); //옵션을 입력받음
		gotoxy(65, 18); //좌표설정

		switch (option) { //입력받은 숫자옵션
		case 1: score = 0; //기본점수 0으로 초기화
				time_gap = 0; //시작시간과 끝나는 시간의 차
				beginningTime = clock(); //시작시간 저장
				main_screen(); break; // 1을 입력하면 게임시작
		case 2: game_help(); break; // 2를 입력하면 도움말 출력하는 함수 호출
		case 3: view_bestscore(); break; //3을 입력하면 누적 점수를 확인할 수 있는 함수 호출
		case 4: wordlist(); break; //4를 입력하면 단어 목록 보여주기
		case 5: return 0; break; //5를 입력하면 return 0;
		default: printf("올바른 키가 아닙니다!"); break; //1,2,3,4 이외의 숫자를 입력할 때 오류메세지 
		}

	}

}

void sc_design() //게임 디자인을 콘솔에 띄우는 함수
{ 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //진한 흰색

	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("|                                                                             < 미림여자정보과학고등학교 신잎새 개발> |\n");
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
	printf("-----------------------------------------------------------------------------------------------------------------------");
}

void game_help() // 도움말을 나타내는 함수
{ 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //진한 흰색
	system("cls"); //현재 창 초기화
	sc_design(); //게임 창 디자인

	gotoxy(35, 5); //좌표설정
	printf("***   초보 개발자를 위한 타자연습기입니다.  ***\n");
	gotoxy(35, 8);
	printf("1. 게임시작을 선택하고 게임 난이도를 골라주세요. \n");
	gotoxy(35, 9);
	printf(" >> 난이도에 따라서 단어가 뜨는 속도가 달라집니다.");
	gotoxy(35, 11);
	printf("2. 단어를 입력하고 enter키를 눌러주세요. \n");
	gotoxy(35, 13);
	printf("3. 단어 색깔마다 점수 배점이 다릅니다. \n");
	gotoxy(35, 14);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); //콘솔에서 색 출력
	printf("파란색 : 150점 ");
	gotoxy(50, 14);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //콘솔에서 색 출력
	printf("초록색 : 200점 ");
	gotoxy(65, 14);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //콘솔에서 색 출력
	printf("하늘색 : 250점 ");
	gotoxy(80, 14);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //콘솔에서 색 출력
	printf("빨간색 : 300점 ");
	gotoxy(35, 16);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //흰색
	printf("4. 중간중간 의미가 없는 단어들은 입력해도 점수가 오르지 않아요. \n");
	gotoxy(35, 17);
	printf(" >> 단어 목록에서 미리 의미있는 단어들을 학습해보아요!");	
	gotoxy(35, 19);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //콘솔에서 색 출력
	printf("주의사항 : '고인물 개발자' 레벨을 함부로 시도하지 마세요.");
	gotoxy(35, 21);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //흰색
	printf("타자연습하고 초보 개발자 탈출합시다 !! 행운을 빌어요 :) \n");
	gotoxy(35, 23);
	printf("*** 아무키나 누르면 메인 메뉴로 돌아갑니다. ***\n");

	_get = getch(); //키보드 입력받는 함수

	if (_kbhit) { //키보드가 눌렸는지 확인
		start_screen(); //게임 초기 화면 나타내는 함수 호출
	}

}

void view_bestscore() //최고점수를 갱신하는 함수
{ 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //진한 흰색
	system("cls"); //현재 창 초기화
	sc_design(); //게임 디자인 창

	if (bestscore < score) { //현 점수가 기존 최고점수보다 높으면
		bestscore = score; //최고점수에 현 점수를 갱신
	}

	gotoxy(40, 5);
	printf("*************!!!조금 더 분발하세요!!!************\n");
	gotoxy(43, 10);
	printf("최고점수 :  %d 점", bestscore); //최고점수 대입
	gotoxy(40, 15);
	printf("*****아무키나 누르면 메인 메뉴로 돌아갑니다.*****\n");

	_get = getch(); //키보드 입력받는 함수

	if (_kbhit) { //키보드가 눌렸는지 확인
		start_screen(); //게임 시작하는 함수 호출
	}

}

void main_screen() // 게임 메인화면을 나타내는 함수
{ 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //진한 흰색
	system("cls"); //현재 창 초기화
	sc_design(); //게임 디자인 창

	gotoxy(50, 5);
	printf("게임 난이도를 선택하세요!");
	gotoxy(50, 8);
	printf("1. 초초초보 개발자");
	gotoxy(50, 10);
	printf("2. 초초보 개발자");
	gotoxy(50, 12);
	printf("3. 초보 개발자");
	gotoxy(50, 14);
	printf("4. 고인물 개발자");
	gotoxy(55, 17); //좌표설정
	scanf("%d", &level_option); //게임 난이도 옵션을 입력받음
	gotoxy(55, 17); //좌표설정

	switch (level_option) { //입력받은 옵션
		case 1: word_speed = 25000; break; //1을 입력하면 단어속도 2.5초까지 랜덤
		case 2: word_speed = 20000; break; //2를 입력하면 단어속도 2초까지 랜덤
		case 3: word_speed = 15000; break; //3을 입력하면 단어속도 1.5초까지 랜덤
		case 4: word_speed = 5000; break; //4를 입력하면 단어속도 0.5초까지 랜덤
		default: break;
	}

	system("cls");
	sc_design(); //게임 디자인 창

	gotoxy(45, 6);
	printf("게임은 45초동안 진행됩니다!!");
	gotoxy(55, 9);
	printf(" 3초 후 시작 !!");
	Sleep(1000); //함수 호출 시간 1초 지연
	system("cls");
	sc_design();
	gotoxy(50, 6);
	printf("게임은 45초동안 진행됩니다!!");
	gotoxy(55, 9);
	printf(" 2초 후 시작 !!");
	Sleep(1000); //함수 호출 시간 1초 지연
	system("cls");
	sc_design();
	gotoxy(55, 6);
	printf("게임은 45초동안 진행됩니다!!");
	gotoxy(55, 9);
	printf(" 1초 후 시작 !!");

	Sleep(1000); //함수 호출 시간 1초 지연
	system("cls"); //현재 창 초기화
	sc_design(); //게임 디자인 창

	while (1) { //true
		printfword(); //단어를 출력하는 함수 호출
		scanfword(); // 단어를 입력받는 함수 호출
	}

}

void printfword() // 단어를 화면에 출력하는 함수
{ 
	static int check = word_max; //정적변수 선언

	x = rand() % 105 + 5; //x좌표 난수 생성
	y = rand() % 19 + 3; //y좌표 난수 생성
	int i = rand() % word_max; //word_max 난수 생성
	wordcolor = rand() % 4 + 1; //색깔 랜덤 생성

	if (non_rcsvWord[i] != 1) { //단어 출력이 하나도 되지 않았으면

		non_rcsvWord[i] = 1; //단어 하나 출력
		check--; // word_max값을 감소
		gotoxy(x, y); //이 좌표에

		for (int j = 0; j < 3; j++) { //0부터 4까지

			if (j == 0) { //처음에는
				re_coordinate[i][j] = x; //x의 좌표를 re_coordinate 배열에 대입
			}

			else if (j == 1) { //그다음에는
				re_coordinate[i][j] = y; //y의 좌표를 re_coordinate 배열에 대입
			}

			else if (j == 2) { //그다음에는
				re_coordinate[i][j] = wordcolor; //색깔을 re_coordinate배열에 대입
			}

		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wordcolor); //색깔 출력
		printf("%s ", word[i]); //단어 출력
	}

}

void scanfword() //문자를 입력받는 함수
{
	int sec = 0; //0으로 초기화
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //진한 흰색

	while (sec < word_speed) { //sec가 word_speed(15000)이 되기 전까지

		sec++; //sec에 계속 +1
		endingTime = clock(); // 끝난 시간 저장
		time_gap = (float)(endingTime - beginningTime) / (CLOCKS_PER_SEC); //time_gap = 끝난시간 - 시작시간 (SEC = 초단위)

		if (time_gap > 45) { //끝난시간과 시작시간의 차가 60 이상이면(60초 경과 이상이면)

			system("cls"); // 현재 창 초기화
			sc_design(); //게임 디자인 창
			gotoxy(50, 11); //좌표설정
			printf("---게 임 종 료---");
			Sleep(2000); //함수 호출 시간 2초 지연
			main(); //메인함수 호출

		}

		if (_kbhit()) { //임의의 키가 눌렸으면

			_kb = getch(); //눌린 값을 _kb 변수에 대입

			if (_kb != 8 && _kb != 13) { //backspace나 enter키가 아니면 (아스키코드)

				gotoxy(5, 25); //이 좌표에
				scan[arr_num++] = _kb; //배열 scan[1,2,3..]에 _kb에서 누른 값을 대입하고
				printf("                 "); //공백을 출력 (입력 칸 안으로 들어가기 위함)
				gotoxy(5, 25); //같은 좌표에
				printf("%s", scan); //눌린 값을 출력

			}

			else if (_kb == 8) { //backspace를 눌렀을경우

				gotoxy(1, 25); //이 좌표에
				printf("|                                                                                                                     |\n"); //출력
				gotoxy(5, 25); //이 좌표에
				scan[--arr_num] = _kb; //배열 scan[...3, 2, 1]에 _kb에서 누른 값을 삭제

				if (arr_num == -1) {//scan[-1]이 될 경우
					arr_num = 0; //더이상 지워지지않음
					printf("%s", scan); // _kb에서 backspace를 누른만큼 삭제 후 출력
				}

			}

			else if (_kb == 13) { //enter키를 눌렀을경우

				arr_num = 0; // arr_num를 0으로 초기화
				gotoxy(1, 25); // 이 좌표에
				printf("|                                                                                                                     |\n"); //출력

				for (int i = 0; i <= word_max; i++) { //0부터 100까지

					if (!strcmp(scan, word[i])) { //눌린 키보드 값과 word[0, 1 ... ]의 값이 다르면

						x_re = re_coordinate[i][0]; //x_re에 출력된 단어의 x좌표 대입
						y_re = re_coordinate[i][1]; //y_re에 출력된 단어의 y좌표대입
						wordcolor_2 = re_coordinate[i][2]; //f2에 출력된 단어의 색깔 대입
						gotoxy(x_re, y_re); //(0,0) 좌표에
						printf("          "); //출력
						gotoxy(1, 25); //이좌표에
						printf("|                                                                                                                     |\n"); //출력

						switch (wordcolor_2) { //색깔이
						case 1: score += 150; break; //1번색깔이면 150점 누적
						case 2: score += 200; break; //2번색깔이면 200점 누적
						case 3: score += 250; break; //3번색깔이면 250점 누적
						case 4: score += 300; break; //4번색깔이면 300점 누적
						default: break;
						}

						gotoxy(3, 2);//이 좌표에
						printf("현재점수 :%d", score); //현재점수 출력
					}

					else { 
						score += 0; //틀렸으면 점수가 누적되지 않음
					}
				}

				for (int i = 0; i < 50; i++) { 
					scan[i] = NULL; //scan배열 NULL 초기화
				}

			}

		}

	}

}

void wordlist() //단어목록을 출력하는 함수
{
	system("cls");
	gotoxy(5, 1);
	printf("*****게임에서 출력되는 단어목록입니다.******");
	gotoxy(3, 3);
	printf("System.out.println : java에서 문자를 출력할때 쓰이는 문법이다. (줄바꿈 O) ");
	gotoxy(3, 4);
	printf("System.out.print : java에서 문자를 출력할때 쓰이는 문법이다. (줄바꿈 X) ");
	gotoxy(3, 5);
	printf("sysout : sysout + ctrl + spacebar = System.out.println 이 자동출력된다.");
	gotoxy(3, 6);
	printf("printf : c에서 문자를 출력할때 쓰이는 문법이다.");
	gotoxy(3, 7);
	printf("scanf : c에서 문자를 입력받을때 쓰이는 문법이다.");
	gotoxy(3, 8);
	printf("void : c나 java에서 리턴타입을 가지지않는 반환형이다.");
	gotoxy(3, 9);
	printf("int : c나 java에서 정수변수를 선언할때 필요한 변수타입이다.");
	gotoxy(3, 10);
	printf("double : c나 java에서 실수변수를 선언할때 필요한 변수타입이다.");
	gotoxy(3, 11);
	printf("char : c나 java에서 문자를 선언할때 필요한 변수타입이다.");
	gotoxy(3, 12);
	printf("String : java에서 문자열을 선언할때 필요한 변수타입이다.");
	gotoxy(3, 13);
	printf("public : 접근지정자라 불리고 모든 범위에서 쓰일 수 있다는 의미를 가지고 있다.");
	gotoxy(3, 14);
	printf("private : 접근지정자라 불리고 특정 범위에서 쓰일 수 있다는 의미를 가지고 있다.");
	gotoxy(3, 15);
	printf("class : java JVM에서 실행할 수 있는 코드를 포함하는 파일의 단위이다.");
	gotoxy(3, 16);
	printf("this : java에서 객체를 나타내는 키워드이다.");
	gotoxy(3, 17);
	printf("set, get : java에서 setter, getter메서드를 만들때 사용된다.");
	gotoxy(3, 18);
	printf("return : c나 java에서 반환형이 void가 아닌 메서드에서 쓰인다.");
	gotoxy(3, 19);
	printf("i++, i-- : 주로 반복문에서 i라는 변수에 1씩 더하거나 뺀다는 의미로 쓰인다.");
	gotoxy(3, 20);
	printf("if - else, for, do, do- while, switch -case : c나 java에서 쓰이는 반복문의 일종이다.");
	gotoxy(3, 21);
	printf("static : c나 java에서 정적변수를 할당할때 쓰이는 키워드이다.");
	gotoxy(3, 22);
	printf("new : java에서 객체를 생성할때 쓰이는 키워드이다.");
	gotoxy(3, 23);
	printf("Scanner scan = new Scanner(System.in) : java에서 입력을 받을때 쓰이는 문법이다.");
	gotoxy(3, 24);
	printf("main() : c나 java에서 가장 기본이 되는 함수이다.");
	gotoxy(3, 25);
	printf("extends : java에서 상속 사용시 쓰이는 문법이다.");
	gotoxy(3, 26);
	printf("implement : java에서 인터페이스 사용시 쓰이는 문법이다.");
	gotoxy(3, 27);
	printf("&&, ||, %, == : 프로그래밍 언어에서 사용되는 연산자의 일종이다.");
	gotoxy(3, 28);
	printf("NULL : 데이터의 값이 존재하지 않는다는 것을 의미하는 문자이다.");
	gotoxy(5, 30);
	printf("*****아무키나 누르면 메인 메뉴로 돌아갑니다.*****");

	_get = getch(); //키보드 입력받는 함수

	if (_kbhit) { //키보드가 눌렸는지 확인
		start_screen(); //게임 시작하는 함수 호출
	}
}

void start_screen() // 시작 화면을 띄우는 함수
{ 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //진한 흰색
	system("cls"); //현재 창 초기화
	sc_design(); // 게임 창 디자인

	gotoxy(43, 5);
	printf("**** 초보 개발자를 위한 타자연습 프로그램 ****");
	gotoxy(43, 8);
	printf("1. 시작하기");
	gotoxy(43, 10);
	printf("2. 도움말");
	gotoxy(43, 12);
	printf("3. 최고점수");
	gotoxy(43, 14);
	printf("4. 단어목록");
	gotoxy(43, 16);
	printf("5. 종료하기");
	gotoxy(53, 20);
	printf("**** 번호를 입력하세요 ****");
}

void removeCursor() // printf에서 단어를 뜨게할때 커서를 제거하는 함수
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0; //커서를 보이지 않게 함
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}