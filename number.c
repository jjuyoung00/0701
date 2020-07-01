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
���� ��Ģ �Ǵ� ���࿡ ���� ���� ��� �Լ�
*/
void intro_game(void)
{
        system("cls");
        printf("50�� �Ѿ�� ����\n\n");
        printf("��ǻ�Ϳ� ����ڰ� �����ư���\n");
        printf("���ڸ� �Է��ϵ� 1~10 ������ \n");
        printf("�ߺ����� �ʴ� ���ڸ� �Է��Ͽ� \n\n");
        printf("���ʷ� 50�� �ѱ�� ���ڰ� �˴ϴ�. \n\n");
        printf("��ǻ�Ͱ� ���� �����մϴ�. \n");
        printf("�ƹ�Ű�� ������ �����մϴ�.");

        getch();

}

 

void gotoxy(int x, int y)
{
        COORD Pos = { x - 1, y - 1 };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
/*
��ǻ�Ͱ� �����ϴ� ������ �����ϴ� �Լ�
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
����ڰ� �����ϴ� ������ �Է°� ó�� �Լ�
*/
int user_number(int i, int user_array[])
{
        int number, again = 0;
        while (!again)
        {
               gotoxy(1, 7);
               printf("����� ���� �Է��� Enter>");
               scanf("%d", &number);
               if (visit[number-1])
               {
                       again = 0;
                       gotoxy(1, 7);
                       printf("                                                 "); //���ڸ� �����
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
��ǻ�Ϳ� ����ڰ� ������ ���ڸ� ȭ�鿡 ����ϴ� �Լ�
*/
void number_display(int i, int com_array[], int user_array[], int sum)
{
        int j;
        gotoxy(1, 2);
        printf("��ǻ�� ����: ");
        for (j = 0; j <= i; j++)
               printf("%2d ", com_array[j]);
        gotoxy(1, 3);
        printf("����� ����: ");
        for (j = 0; j <= i; j++)
               if (user_array[j] == 0)
                       continue;
               else
                       printf("%2d ", user_array[j]);
        gotoxy(1, 5);
        printf("���� �հ�: %3d\n", sum);
}
/*
������ ���(����)�� ����ϴ� �Լ�
*/
void conclusion(int check)
{
        if (check == 1)
               printf("��ǻ�Ͱ� �̰���ϴ�. \n");
        else
               printf("����ڰ� �̰���ϴ�. \n");
}
/*
���α׷��� ������ ���߰� �ϴ� �Լ�
*/
void press_any_key(void)
{
        gotoxy(1, 10);
        printf("�ƹ�Ű�� �����ÿ�..");
        getch();
}
/*
100�� �Ѿ�� ������ �����ϴ� �Լ�
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
