#include"public.h"
#include"judge.h"
#include"user.h"
/**************************
judge.c
COPYRIGHT:	shenlei
FUNCTION:	judge the rightness of password or phonenum
ABSTRACT:
		A.judge phonenum to find lost pass
		B.judge password to log in
DATE:2020/9/10
****************************/

/*********************************************
FUNCTION:judge_login
DESCRIPTION���ж�������û����Ƿ�ƥ��
INPUT:char* name, char* pass
RETURN:1 or 0
***********************************************/

int judge_login(char* name, char* pass)//�ж�������û����Ƿ�ƥ��
{
	user* temp=NULL,*phead=NULL;
	phead = getuser();
	temp = phead->next;
	while(temp!=NULL)//
	{
		//outtextxy(0,200,temp->username);
		//outtextxy(0,200,temp->password);
		if (strcmp(temp->username, name) == 0)
		{
			if (strcmp(temp->password, pass) == 0)
			{
				free(temp);
				return 1;
			}
			else
			{
				free(temp);
				return 0;
			}
		}
		else
		{
			temp = temp->next;
		}
	}
	free(phead);
	free(temp);
	return 0;
}

/*********************************************
FUNCTION:judge_login
DESCRIPTION���ж��ֻ��ź��û����Ƿ�ƥ��
INPUT:char* name, char* pass,char* phone
RETURN:1 or 0
***********************************************/

int judge_forgetpassword(char* name,char* pass,char* phone)
{
	user* temp=NULL,*phead=NULL;
	phead = getuser();
	temp = phead->next;
	while(temp!=NULL)//
	{
		//outtextxy(0,200,temp->username);
		//outtextxy(0,200,temp->password);
		if (strcmp(temp->username, name) == 0)
		{
			if (strcmp(temp->phonenum,phone) == 0)
			{
				strcpy(pass,temp->password);
				free(temp);
				return 1;
			}
			else
			{
				free(temp);
				return 0;
			}
		}
		else
		{
			temp = temp->next;
		}
	}
	free(phead);
	free(temp);
	return 0;
}