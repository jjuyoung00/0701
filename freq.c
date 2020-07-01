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
//���ӱ�Ģ�Ǵ����࿡���Ѽ�������Լ�
void intro_game(void )
{
    printf("������Ŀ���Ÿ�������߿���\n");
    printf("���帹�������Ѽ��ڸ�ã�ƶ�!\n\n");
    printf("���ѽð������Դϴ�.\n\n");
    printf("�ƹ�Ű������������մϴ�.\n");
    _getch();
}
//������ĸ�����γ���������ϴ��Լ�
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
//�󵵼������帹�����ڸ�����ϴ��Լ�
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
//���ӱ�Ģ������ϴ��Լ�
void check_result(int user, int answer, int cnt[])
{
    if(user==answer)
        printf("\n�¾ҽ��ϴ�.\n");
    else
        printf("\nƲ�Ƚ��ϴ�.\n");
        printf("��ȣ: %d, Ƚ��: %d\n", answer, cnt[answer]);

}
//�����󵵰����帹�����ڸ�ã�°����������Լ�
void game_control(void )
{
    int cnt[MAX_NUMBER], answer, user;
    clock_t start, end;
    double pst;
    system("cls");
    print_number(MATRIX_SIZE, cnt);
    answer=find_num(cnt);
    printf("\n\n");
    printf("����Ƚ�������帹�������Է�>");
    start=clock();
    while(!kbhit())
    {
        end=clock();
        pst=(double)(end-start)/CLK_TCK;
        if(TIME_LIMIT<pst)
        {
           printf("\n���ѽð����Ѿ����ϴ�\n");
            exit(0);
        }
    }
    user=_getch()-'0';
    printf("%d", user);
    check_result(user, answer, cnt);
}