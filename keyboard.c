#include"keyboard.h"
#include<stdio.h>
#include<bios.h>

/**************************
keyboard.c
COPYRIGHT:	shenlei
FUNCTION:	judge the rightness of password or phonenum
ABSTRACT:
		A.judge phonenum to find lost pass
		B.judge password to log in
DATE:2020/9/7
****************************/
typedef struct
{
	int value;
	char ch;
}setKeyValue;

/*26个字母,及数字等符号的键值*/
setKeyValue KeyValue[74] = {
	{0x1e61,'a'},{0x3062,'b'},{0x2e63,'c'},{0x2064,'d'},{0x1265,'e'},
	{0x2166,'f'},{0x2267,'g'},{0x2368,'h'},{0x1769,'i'},{0x246a,'j'},
	{0x256b,'k'},{0x266c,'l'},{0x326d,'m'},{0x316e,'n'},{0x186f,'o'},
	{0x1970,'p'},{0x1071,'q'},{0x1372,'r'},{0x1f73,'s'},{0x1474,'t'},
	{0x1675,'u'},{0x2f76,'v'},{0x1177,'w'},{0x2d78,'x'},{0x1579,'y'},
	{0x2c7a,'z'},
	{0x1e41,'A'},{0x3042,'B'},{0x2e43,'C'},{0x2044,'D'},{0x1245,'E'},
	{0x2146,'F'},{0x2247,'G'},{0x2348,'H'},{0x1749,'I'},{0x244a,'J'},
	{0x254b,'K'},{0x264c,'L'},{0x324d,'M'},{0x314e,'N'},{0x184f,'O'},
	{0x1950,'P'},{0x1051,'Q'},{0x1352,'R'},{0x1f53,'S'},{0x1454,'T'},
	{0x1655,'U'},{0x2f56,'V'},{0x1157,'W'},{0x2d58,'X'},{0x1559,'Y'},
	{0x2c5a,'Z'},
	{0x4f31,'1'},{0x5032,'2'},{0x5133,'3'},{0x4b34,'4'},{0x4c35,'5'},
	{0x4d36,'6'},{0x4737,'7'},{0x4838,'8'},{0x4939,'9'},{0x5230,'0'},
	{0x231,'1'},{0x332,'2'},{0x433,'3'},{0x534,'4'},{0x635,'5'},
	{0x736,'6'},{0x837,'7'},{0x938,'8'},{0xa39,'9'},{0xb30,'0'},{0x532e,'.'},
	{0x342e,'.'} };


/*********************************************
FUNCTION:get_key
DESCRIPTION：判断键值并返回相应的字符
INPUT:int value
RETURN:KeyValue[i].ch or '\0'
***********************************************/

char get_key(int value)
{
	int i;
	for (i = 0; i < 74; i++)
	{
		if (value == KeyValue[i].value)
			break;
	}
	if (i < 74)
		return KeyValue[i].ch;
	else return '\0';
}