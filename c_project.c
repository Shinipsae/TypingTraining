#define _CRT_SECURE_NO_WARNINGS //scanf �������� �޼���
#define word_max 100 //�ܾ��� ����

#include <stdio.h> //ǥ������� ����
#include <stdlib.h> //rand()�Լ� ����
#include <time.h>  //time()�Լ� ����
#include <Windows.h> //system(), sleep()�Լ� ����
#include <conio.h>  //kbhit() �Լ� ����

time_t beginningTime = 0, endingTime = 0;// ���� �ð� ����
int time_gap; //���۽ð��� ������ �ð��� ���̰��� �ִ� �Լ�

void gotoxy(int x, int y) //Ŀ�� ��ġ ���� �Լ�
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void game_help(); //���� ������ ��Ÿ���� �Լ�
void main_screen(); //���� ����ȭ���� ��Ÿ���� �Լ�
void printfword(); //�ܾ ȭ�鿡 ����ϴ� �Լ�
void scanfword(); //�ܾ �Է� �޴� �Լ�
void sc_design(); //���� â �������� �����ϴ� �Լ�
void start_screen(); //���� �ʱ� ȭ���� ��Ÿ���� �Լ�
void view_bestscore(); //�ְ������� �����ִ� �Լ�
void wordlist(); //�ܾ����� ����ϴ� �Լ�
void removeCursor(); //Ŀ���� �����ϴ� �Լ�

char word[256][256] = { "system","out","println" ,"print","sysout","printf","scanf","%d","%s","void","int","double",
"char","String","public","class","private","this","set","get","return","i++","i--","==","if","else","for","do","while",
"static","final","new","Class","Scanner","scan","main","args","extends","implement","boolean","true","false","import",
"util","package","nextInt","nextDouble","equals","break","switch","case","arr","%","&&","||","c","java","python",
"programming","coding","mirim","NULL" }; //2���� �迭 ������ ���ӿ� ��µ� �ܾ� �ʱ�ȭ

int level_option; //���̵��� �����ϴ� �ɼ� ����������
int word_speed; //�ܾ �ߴ� �ӵ��� ���� ���̵� ����
char scan[50]; //�Է¹޴� �ܾ�迭
char re_coordinate[256][4] = { 0 }; //��ǥ ���ġ
int non_rcsvWord[256];// ��� �ߺ���� �����ϴ� �迭
int option; //�ʱ�ȭ�� �ɼ� ����������
int x, y;// gotoxy()�Լ����� �ʿ��� ����
int x_re, y_re; //x, y ���� �ٽ� �ҷ����� ����
int _get; //getch()�Լ� ���� ������ ����
int _kb; //kbhit()�Լ� ���� ������ ����
int wordcolor; //�ܾ��� ����
int wordcolor_2; //�ܾ��� ������ �ٽ� �ҷ����� ����
int score = 0; //�������� �ʱ�ȭ
int bestscore = 0; //�ְ����� �ʱ�ȭ
int arr_num; //�ܾ� �Է��̳� ������ �ʿ��� ����

int main()
{
	srand((unsigned)time(NULL)); //������������ srand() �Լ�
	system("mode con cols = 120 lines = 30"); //�ܼ� â ũ������
	sc_design(); //���� â ������
	gotoxy(60, 9); //��ǥ����
	removeCursor(); //Ŀ���� ���ִ� �Լ� ȣ��
	start_screen(); //����ȭ���� ����ϴ� �Լ� ȣ��

	while (1) { //true

		gotoxy(65, 18); //��ǥ����
		scanf("%d", &option); //�ɼ��� �Է¹���
		gotoxy(65, 18); //��ǥ����

		switch (option) { //�Է¹��� ���ڿɼ�
		case 1: score = 0; //�⺻���� 0���� �ʱ�ȭ
			time_gap = 0; //���۽ð��� ������ �ð��� ��
			beginningTime = clock(); //���۽ð� ����
			main_screen(); break; // 1�� �Է��ϸ� ���ӽ���
		case 2: game_help(); break; // 2�� �Է��ϸ� ���� ����ϴ� �Լ� ȣ��
		case 3: view_bestscore(); break; //3�� �Է��ϸ� ���� ������ Ȯ���� �� �ִ� �Լ� ȣ��
		case 4: wordlist(); break; //4�� �Է��ϸ� �ܾ� ��� �����ֱ�
		case 5: return 0; break; //5�� �Է��ϸ� return 0;
		default: printf("�ùٸ� Ű�� �ƴմϴ�!"); break; //1,2,3,4 �̿��� ���ڸ� �Է��� �� �����޼��� 
		}

	}

}

void sc_design() //���� �������� �ֿܼ� ���� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //���� ���

	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("|                                                                             < �̸������������а���б� ���ٻ� ����> |\n");
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

void game_help() // ������ ��Ÿ���� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //���� ���
	system("cls"); //���� â �ʱ�ȭ
	sc_design(); //���� â ������

	gotoxy(35, 5); //��ǥ����
	printf("***   �ʺ� �����ڸ� ���� Ÿ�ڿ������Դϴ�.  ***\n");
	gotoxy(35, 8);
	printf("1. ���ӽ����� �����ϰ� ���� ���̵��� ����ּ���. \n");
	gotoxy(35, 9);
	printf(" >> ���̵��� ���� �ܾ �ߴ� �ӵ��� �޶����ϴ�.");
	gotoxy(35, 11);
	printf("2. �ܾ �Է��ϰ� enterŰ�� �����ּ���. \n");
	gotoxy(35, 13);
	printf("3. �ܾ� ���򸶴� ���� ������ �ٸ��ϴ�. \n");
	gotoxy(35, 14);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); //�ֿܼ��� �� ���
	printf("�Ķ��� : 150�� ");
	gotoxy(50, 14);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //�ֿܼ��� �� ���
	printf("�ʷϻ� : 200�� ");
	gotoxy(65, 14);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //�ֿܼ��� �� ���
	printf("�ϴû� : 250�� ");
	gotoxy(80, 14);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //�ֿܼ��� �� ���
	printf("������ : 300�� ");
	gotoxy(35, 16);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //���
	printf("4. �߰��߰� �ǹ̰� ���� �ܾ���� �Է��ص� ������ ������ �ʾƿ�. \n");
	gotoxy(35, 17);
	printf(" >> �ܾ� ��Ͽ��� �̸� �ǹ��ִ� �ܾ���� �н��غ��ƿ�!");
	gotoxy(35, 19);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //�ֿܼ��� �� ���
	printf("���ǻ��� : '���ι� ������' ������ �Ժη� �õ����� ������.");
	gotoxy(35, 21);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //���
	printf("Ÿ�ڿ����ϰ� �ʺ� ������ Ż���սô� !! ����� ����� :) \n");
	gotoxy(35, 23);
	printf("*** �ƹ�Ű�� ������ ���� �޴��� ���ư��ϴ�. ***\n");

	_get = getch(); //Ű���� �Է¹޴� �Լ�

	if (_kbhit) { //Ű���尡 ���ȴ��� Ȯ��
		start_screen(); //���� �ʱ� ȭ�� ��Ÿ���� �Լ� ȣ��
	}

}

void view_bestscore() //�ְ������� �����ϴ� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //���� ���
	system("cls"); //���� â �ʱ�ȭ
	sc_design(); //���� ������ â

	if (bestscore < score) { //�� ������ ���� �ְ��������� ������
		bestscore = score; //�ְ������� �� ������ ����
	}

	gotoxy(40, 5);
	printf("*************!!!���� �� �й��ϼ���!!!************\n");
	gotoxy(43, 10);
	printf("�ְ����� :  %d ��", bestscore); //�ְ����� ����
	gotoxy(40, 15);
	printf("*****�ƹ�Ű�� ������ ���� �޴��� ���ư��ϴ�.*****\n");

	_get = getch(); //Ű���� �Է¹޴� �Լ�

	if (_kbhit) { //Ű���尡 ���ȴ��� Ȯ��
		start_screen(); //���� �����ϴ� �Լ� ȣ��
	}

}

void main_screen() // ���� ����ȭ���� ��Ÿ���� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //���� ���
	system("cls"); //���� â �ʱ�ȭ
	sc_design(); //���� ������ â

	gotoxy(50, 5);
	printf("���� ���̵��� �����ϼ���!");
	gotoxy(50, 8);
	printf("1. �����ʺ� ������");
	gotoxy(50, 10);
	printf("2. ���ʺ� ������");
	gotoxy(50, 12);
	printf("3. �ʺ� ������");
	gotoxy(50, 14);
	printf("4. ���ι� ������");
	gotoxy(55, 17); //��ǥ����
	scanf("%d", &level_option); //���� ���̵� �ɼ��� �Է¹���
	gotoxy(55, 17); //��ǥ����

	switch (level_option) { //�Է¹��� �ɼ�
	case 1: word_speed = 25000; break; //1�� �Է��ϸ� �ܾ�ӵ� 2.5�ʱ��� ����
	case 2: word_speed = 20000; break; //2�� �Է��ϸ� �ܾ�ӵ� 2�ʱ��� ����
	case 3: word_speed = 15000; break; //3�� �Է��ϸ� �ܾ�ӵ� 1.5�ʱ��� ����
	case 4: word_speed = 5000; break; //4�� �Է��ϸ� �ܾ�ӵ� 0.5�ʱ��� ����
	default: break;
	}

	system("cls");
	sc_design(); //���� ������ â

	gotoxy(45, 6);
	printf("������ 45�ʵ��� ����˴ϴ�!!");
	gotoxy(55, 9);
	printf(" 3�� �� ���� !!");
	Sleep(1000); //�Լ� ȣ�� �ð� 1�� ����
	system("cls");
	sc_design();
	gotoxy(50, 6);
	printf("������ 45�ʵ��� ����˴ϴ�!!");
	gotoxy(55, 9);
	printf(" 2�� �� ���� !!");
	Sleep(1000); //�Լ� ȣ�� �ð� 1�� ����
	system("cls");
	sc_design();
	gotoxy(55, 6);
	printf("������ 45�ʵ��� ����˴ϴ�!!");
	gotoxy(55, 9);
	printf(" 1�� �� ���� !!");

	Sleep(1000); //�Լ� ȣ�� �ð� 1�� ����
	system("cls"); //���� â �ʱ�ȭ
	sc_design(); //���� ������ â

	while (1) { //true
		printfword(); //�ܾ ����ϴ� �Լ� ȣ��
		scanfword(); // �ܾ �Է¹޴� �Լ� ȣ��
	}

}

void printfword() // �ܾ ȭ�鿡 ����ϴ� �Լ�
{
	static int check = word_max; //�������� ����

	x = rand() % 105 + 5; //x��ǥ ���� ����
	y = rand() % 19 + 3; //y��ǥ ���� ����
	int i = rand() % word_max; //word_max ���� ����
	wordcolor = rand() % 4 + 1; //���� ���� ����

	if (non_rcsvWord[i] != 1) { //�ܾ� ����� �ϳ��� ���� �ʾ�����

		non_rcsvWord[i] = 1; //�ܾ� �ϳ� ���
		check--; // word_max���� ����
		gotoxy(x, y); //�� ��ǥ��

		for (int j = 0; j < 3; j++) { //0���� 4����

			if (j == 0) { //ó������
				re_coordinate[i][j] = x; //x�� ��ǥ�� re_coordinate �迭�� ����
			}

			else if (j == 1) { //�״�������
				re_coordinate[i][j] = y; //y�� ��ǥ�� re_coordinate �迭�� ����
			}

			else if (j == 2) { //�״�������
				re_coordinate[i][j] = wordcolor; //������ re_coordinate�迭�� ����
			}

		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wordcolor); //���� ���
		printf("%s ", word[i]); //�ܾ� ���
	}

}

void scanfword() //���ڸ� �Է¹޴� �Լ�
{
	int sec = 0; //0���� �ʱ�ȭ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //���� ���

	while (sec < word_speed) { //sec�� word_speed(15000)�� �Ǳ� ������

		sec++; //sec�� ��� +1
		endingTime = clock(); // ���� �ð� ����
		time_gap = (float)(endingTime - beginningTime) / (CLOCKS_PER_SEC); //time_gap = �����ð� - ���۽ð� (SEC = �ʴ���)

		if (time_gap > 45) { //�����ð��� ���۽ð��� ���� 60 �̻��̸�(60�� ��� �̻��̸�)

			system("cls"); // ���� â �ʱ�ȭ
			sc_design(); //���� ������ â
			gotoxy(50, 11); //��ǥ����
			printf("---�� �� �� ��---");
			Sleep(2000); //�Լ� ȣ�� �ð� 2�� ����
			main(); //�����Լ� ȣ��

		}

		if (_kbhit()) { //������ Ű�� ��������

			_kb = getch(); //���� ���� _kb ������ ����

			if (_kb != 8 && _kb != 13) { //backspace�� enterŰ�� �ƴϸ� (�ƽ�Ű�ڵ�)

				gotoxy(5, 25); //�� ��ǥ��
				scan[arr_num++] = _kb; //�迭 scan[1,2,3..]�� _kb���� ���� ���� �����ϰ�
				printf("                 "); //������ ��� (�Է� ĭ ������ ���� ����)
				gotoxy(5, 25); //���� ��ǥ��
				printf("%s", scan); //���� ���� ���

			}

			else if (_kb == 8) { //backspace�� ���������

				gotoxy(1, 25); //�� ��ǥ��
				printf("|                                                                                                                     |\n"); //���
				gotoxy(5, 25); //�� ��ǥ��
				scan[--arr_num] = _kb; //�迭 scan[...3, 2, 1]�� _kb���� ���� ���� ����

				if (arr_num == -1) {//scan[-1]�� �� ���
					arr_num = 0; //���̻� ������������
					printf("%s", scan); // _kb���� backspace�� ������ŭ ���� �� ���
				}

			}

			else if (_kb == 13) { //enterŰ�� ������ ���

				arr_num = 0; // arr_num�� 0���� �ʱ�ȭ
				gotoxy(1, 25); // �� ��ǥ��
				printf("|                                                                                                                     |\n"); //���

				for (int i = 0; i <= word_max; i++) { //0���� 100����

					if (!strcmp(scan, word[i])) { //���� Ű���� ���� word[0, 1 ... ]�� ���� �ٸ���

						x_re = re_coordinate[i][0]; //x_re�� ��µ� �ܾ��� x��ǥ ����
						y_re = re_coordinate[i][1]; //y_re�� ��µ� �ܾ��� y��ǥ����
						wordcolor_2 = re_coordinate[i][2]; //f2�� ��µ� �ܾ��� ���� ����
						gotoxy(x_re, y_re); //(0,0) ��ǥ��
						printf("          "); //���
						gotoxy(1, 25); //����ǥ��
						printf("|                                                                                                                     |\n"); //���

						switch (wordcolor_2) { //������
						case 1: score += 150; break; //1�������̸� 150�� ����
						case 2: score += 200; break; //2�������̸� 200�� ����
						case 3: score += 250; break; //3�������̸� 250�� ����
						case 4: score += 300; break; //4�������̸� 300�� ����
						default: break;
						}

						gotoxy(3, 2);//�� ��ǥ��
						printf("�������� :%d", score); //�������� ���
					}

					else {
						score += 0; //Ʋ������ ������ �������� ����
					}
				}

				for (int i = 0; i < 50; i++) {
					scan[i] = NULL; //scan�迭 NULL �ʱ�ȭ
				}

			}

		}

	}

}

void wordlist() //�ܾ����� ����ϴ� �Լ�
{
	system("cls");
	gotoxy(5, 1);
	printf("*****���ӿ��� ��µǴ� �ܾ����Դϴ�.******");
	gotoxy(3, 3);
	printf("System.out.println : java���� ���ڸ� ����Ҷ� ���̴� �����̴�. (�ٹٲ� O) ");
	gotoxy(3, 4);
	printf("System.out.print : java���� ���ڸ� ����Ҷ� ���̴� �����̴�. (�ٹٲ� X) ");
	gotoxy(3, 5);
	printf("sysout : sysout + ctrl + spacebar = System.out.println �� �ڵ���µȴ�.");
	gotoxy(3, 6);
	printf("printf : c���� ���ڸ� ����Ҷ� ���̴� �����̴�.");
	gotoxy(3, 7);
	printf("scanf : c���� ���ڸ� �Է¹����� ���̴� �����̴�.");
	gotoxy(3, 8);
	printf("void : c�� java���� ����Ÿ���� �������ʴ� ��ȯ���̴�.");
	gotoxy(3, 9);
	printf("int : c�� java���� ���������� �����Ҷ� �ʿ��� ����Ÿ���̴�.");
	gotoxy(3, 10);
	printf("double : c�� java���� �Ǽ������� �����Ҷ� �ʿ��� ����Ÿ���̴�.");
	gotoxy(3, 11);
	printf("char : c�� java���� ���ڸ� �����Ҷ� �ʿ��� ����Ÿ���̴�.");
	gotoxy(3, 12);
	printf("String : java���� ���ڿ��� �����Ҷ� �ʿ��� ����Ÿ���̴�.");
	gotoxy(3, 13);
	printf("public : ���������ڶ� �Ҹ��� ��� �������� ���� �� �ִٴ� �ǹ̸� ������ �ִ�.");
	gotoxy(3, 14);
	printf("private : ���������ڶ� �Ҹ��� Ư�� �������� ���� �� �ִٴ� �ǹ̸� ������ �ִ�.");
	gotoxy(3, 15);
	printf("class : java JVM���� ������ �� �ִ� �ڵ带 �����ϴ� ������ �����̴�.");
	gotoxy(3, 16);
	printf("this : java���� ��ü�� ��Ÿ���� Ű�����̴�.");
	gotoxy(3, 17);
	printf("set, get : java���� setter, getter�޼��带 ���鶧 ���ȴ�.");
	gotoxy(3, 18);
	printf("return : c�� java���� ��ȯ���� void�� �ƴ� �޼��忡�� ���δ�.");
	gotoxy(3, 19);
	printf("i++, i-- : �ַ� �ݺ������� i��� ������ 1�� ���ϰų� ���ٴ� �ǹ̷� ���δ�.");
	gotoxy(3, 20);
	printf("if - else, for, do, do- while, switch -case : c�� java���� ���̴� �ݺ����� �����̴�.");
	gotoxy(3, 21);
	printf("static : c�� java���� ���������� �Ҵ��Ҷ� ���̴� Ű�����̴�.");
	gotoxy(3, 22);
	printf("new : java���� ��ü�� �����Ҷ� ���̴� Ű�����̴�.");
	gotoxy(3, 23);
	printf("Scanner scan = new Scanner(System.in) : java���� �Է��� ������ ���̴� �����̴�.");
	gotoxy(3, 24);
	printf("main() : c�� java���� ���� �⺻�� �Ǵ� �Լ��̴�.");
	gotoxy(3, 25);
	printf("extends : java���� ��� ���� ���̴� �����̴�.");
	gotoxy(3, 26);
	printf("implement : java���� �������̽� ���� ���̴� �����̴�.");
	gotoxy(3, 27);
	printf("&&, ||, %, == : ���α׷��� ���� ���Ǵ� �������� �����̴�.");
	gotoxy(3, 28);
	printf("NULL : �������� ���� �������� �ʴ´ٴ� ���� �ǹ��ϴ� �����̴�.");
	gotoxy(5, 30);
	printf("*****�ƹ�Ű�� ������ ���� �޴��� ���ư��ϴ�.*****");

	_get = getch(); //Ű���� �Է¹޴� �Լ�

	if (_kbhit) { //Ű���尡 ���ȴ��� Ȯ��
		start_screen(); //���� �����ϴ� �Լ� ȣ��
	}
}

void start_screen() // ���� ȭ���� ���� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //���� ���
	system("cls"); //���� â �ʱ�ȭ
	sc_design(); // ���� â ������

	gotoxy(43, 5);
	printf("**** �ʺ� �����ڸ� ���� Ÿ�ڿ��� ���α׷� ****");
	gotoxy(43, 8);
	printf("1. �����ϱ�");
	gotoxy(43, 10);
	printf("2. ����");
	gotoxy(43, 12);
	printf("3. �ְ�����");
	gotoxy(43, 14);
	printf("4. �ܾ���");
	gotoxy(43, 16);
	printf("5. �����ϱ�");
	gotoxy(53, 20);
	printf("**** ��ȣ�� �Է��ϼ��� ****");
}

void removeCursor() // printf���� �ܾ �߰��Ҷ� Ŀ���� �����ϴ� �Լ�
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0; //Ŀ���� ������ �ʰ� ��
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}