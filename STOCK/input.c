#include "public.h"
#include "input.h"
/**************************
input.c
COPYRIGHT:	shenlei
FUNCTION:	input username and password
ABSTRACT:
		A.find lost pass
DATE:2020/10/7
****************************/

/*********************************************
FUNCTION:input_name
DESCRIPTION�������û���
INPUT:char* username,int nx,int ny
RETURN:void
***********************************************/

void input_name(char* username,int nx,int ny)//
{
	int i = 0;
	char temp[2] = {'\0','\0'};//����һ�����������outtextһ������ʾ������ַ�
	int ch = 0;//
	while (bioskey(1) != 0)
	{
		getch();
	}//
	while (1)
	{
		ch = bioskey(0);
		if ((username[i] = get_key(ch)) == '\0' && ch != 0xe08)
			break;
		if (ch == 0xe08 && i > 0)//����backspace�˸�
		{
			username[i - 1] = '\0';
			setfillstyle(1, LIGHTGRAY);
			bar(nx + 20 * (i - 1) + 1, ny + 1, nx + 20 * i - 1, ny + 30 - 1);//��������ʾ���ַ�
			i = i - 2;
		}
		else if (ch != 0xe08 && i >= 0)
		{
			setcolor(BLUE);
			temp[0] = username[i];
			settextstyle(1, 0, 1);
			outtextxy(nx+10 + 20 * i, ny+5, temp);//����ַ�
		}
		else
		{
			continue;
		}
		i++;
		if (i > 10)
			break;
	}
}

/*********************************************
FUNCTION:input_name
DESCRIPTION����������
INPUT:char* password,int nx,int ny
RETURN:void
***********************************************/

void input_password(char* password,int nx,int ny)
{
	int i = 0;
	int ch = 0;
	while (bioskey(1) != 0)
	{
		getch();
	}
	while (1)
	{
		ch = bioskey(0);
		if ((password[i] = get_key(ch)) == '\0' && ch != 0xe08)
			break;
		if (ch == 0xe08 && i > 0)//����backspace
		{
			password[i - 1] = '\0';
			setfillstyle(1, LIGHTGRAY);
			bar(nx +20 *(i-1)+2, ny+1, nx + 5 + 20 *i+2, ny + 30-1);//��������ʾ�ַ�
			i = i - 2;
		}
		else if (ch != 0xe08 && i >= 0)
		{
			password[i] = get_key(ch);
			setcolor(WHITE);
			circle(nx + 10 + 20 * i+2, ny + 15, 8);
			setfillstyle(1,BLUE);
			floodfill(nx + 10 + 20*i+2, ny + 15, WHITE);
		}
		else
		{
			continue;
		}
		i++;
		if (i > 10)
			break;
	}
}