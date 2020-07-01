#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#define MATRIX_SIZE 5
#define MAX_NUMBER 5
#define TIME_LIMIT 5

void intro_game(void);
void game_control(void);
void print_number(int n, int cnt[]);
int find_num(int cnt[]);
void check_result(int user, int answer, int cnt[]);
int main(void)
{
	srand(time(NULL));
	intro_game();
	game_control();
	return 0;
}
//게임규칙또는진행에대한설명출력함수
void intro_game(void )
{
    printf("정방행렬에나타난숫자중에서\n");
    printf("가장많이출현한숫자를찾아라!\n\n");
    printf("제한시간은초입니다.\n\n");
    printf("아무키나누르면시작합니다.\n");
    _getch();
}
//정방행렬모양으로난수를출력하는함수
void print_number(int n, int cnt[])
{
    int i, j, r_num;
    for(i=0;i<n;i++)
        cnt[i]=0;
    for(i=1;i<=n;i+=1)
    {
        for(j=1;j<=n;j+=1)
        {
           r_num=rand()%MAX_NUMBER;
           cnt[r_num]+=1;
           printf("%d ", r_num);
        }
        printf("\n");
    }
}
//빈도수가가장많은숫자를계산하는함수
int find_num(int cnt[])
{
    int i, check, max_num=0;
    for(i=0;i<MATRIX_SIZE;i++)
    {
        if(max_num<=cnt[i])
        {
            max_num=cnt[i];
            check=i;
        }
    }
    return check;
}
//게임규칙을출력하는함수
void check_result(int user, int answer, int cnt[])
{
    if(user==answer)
        printf("\n맞았습니다.\n");
    else
        printf("\n틀렸습니다.\n");
        printf("번호: %d, 횟수: %d\n", answer, cnt[answer]);

}
//출현빈도가가장많은숫자를찾는게임의제어함수
void game_control(void )
{
    int cnt[MAX_NUMBER], answer, user;
    clock_t start, end;
    double pst;
    system("cls");
    print_number(MATRIX_SIZE, cnt);
    answer=find_num(cnt);
    printf("\n\n");
    printf("출현횟수가가장많은숫자입력>");
    start=clock();
    while(!kbhit())
    {
        end=clock();
        pst=(double)(end-start)/CLK_TCK;
        if(TIME_LIMIT<pst)
        {
           printf("\n제한시간을넘었습니다\n");
            exit(0);
        }
    }
    user=_getch()-'0';
    printf("%d", user);
    check_result(user, answer, cnt);
}
