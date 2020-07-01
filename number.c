#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

void intro_game(void);

void game_control(void);

int computer_number(int i, int com_array[]);

int user_number(int i, int user_array[]);

void number_display(int i, int com_array[], int user_array[], int sum);

void conclusion(int win);

void gotoxy(int x, int y);

void press_any_key(void);


int visit[10] = { 0, };


int main(void)
{
        srand((unsigned)time(NULL));
        intro_game();
        game_control();
        return 0;
}
 
/*
게임 규칙 또는 진행에 대한 설명 출력 함수
*/
void intro_game(void)
{
        system("cls");
        printf("50을 넘어라 게임\n\n");
        printf("컴퓨터와 사용자가 번갈아가며\n");
        printf("숫자를 입력하되 1~10 사이의 \n");
        printf("중복되지 않는 숫자를 입력하여 \n\n");
        printf("최초로 50을 넘기면 승자가 됩니다. \n\n");
        printf("컴퓨터가 먼저 시작합니다. \n");
        printf("아무키나 누르면 시작합니다.");

        getch();

}

 

void gotoxy(int x, int y)
{
        COORD Pos = { x - 1, y - 1 };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
/*
컴퓨터가 제시하는 난수를 생성하는 함수
*/
int computer_number(int i, int com_array[])
{
        int again = 0, random;
        while (!again)
        {
               random = rand() % 10 + 1;
               if (visit[random-1])
                       again = 0;
               else
               {
                       again = 1;
                       visit[random-1] = 1;
               }
        }
        com_array[i] = random;
        return com_array[i];
}
/*
사용자가 제시하는 숫자의 입력과 처리 함수
*/
int user_number(int i, int user_array[])
{
        int number, again = 0;
        while (!again)
        {
               gotoxy(1, 7);
               printf("사용자 숫자 입력후 Enter>");
               scanf("%d", &number);
               if (visit[number-1])
               {
                       again = 0;
                       gotoxy(1, 7);
                       printf("                                                 "); //글자를 지운다
               }
               else
               {
                       again = 1;
                       visit[number-1] = 1;
               }
        }
        user_array[i] = number;
        return user_array[i];
}
/*
컴퓨터와 사용자가 제시한 숫자를 화면에 출력하는 함수
*/
void number_display(int i, int com_array[], int user_array[], int sum)
{
        int j;
        gotoxy(1, 2);
        printf("컴퓨터 숫자: ");
        for (j = 0; j <= i; j++)
               printf("%2d ", com_array[j]);
        gotoxy(1, 3);
        printf("사용자 숫자: ");
        for (j = 0; j <= i; j++)
               if (user_array[j] == 0)
                       continue;
               else
                       printf("%2d ", user_array[j]);
        gotoxy(1, 5);
        printf("현재 합계: %3d\n", sum);
}
/*
게임의 결과(승패)를 출력하는 함수
*/
void conclusion(int check)
{
        if (check == 1)
               printf("컴퓨터가 이겼습니다. \n");
        else
               printf("사용자가 이겼습니다. \n");
}
/*
프로그램의 진행을 멈추게 하는 함수
*/
void press_any_key(void)
{
        gotoxy(1, 10);
        printf("아무키나 누르시오..");
        getch();
}
/*
100을 넘어라 게임을 제어하는 함수
*/
void game_control(void)
{
        int max = 50;
        int com_array[10] = { 0 }, user_array[10] = { 0 }, number;
        int i, sum = 0, win;
        for (i = 0; i < 10; i++)
        {
               system("cls");
               number = computer_number(i, com_array);
               sum += number;
               number_display(i, com_array, user_array, sum);
               if (max < sum)
               {
                       win = 1;
                       break;
               }
               number = user_number(i, user_array);
               sum += number;
               number_display(i, com_array, user_array, sum);
               if (max < sum)
               {
                       win = 2;
                       break;
               }
               press_any_key();
        }
        conclusion(win);
}
