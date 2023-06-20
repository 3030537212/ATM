#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 2
int a,b;//找位置 
void csh();
void dr();
void caidan();
void change();
void qukuan();
void zhuanzhang();
void yuechaxun();
void quit();
struct account
{
	char id[100];
	char mm[100];
	double money;
}s[N],user;
int main()
{
	csh();
	//数据测试 
   	int i;
   	printf("数据库:\n");
	for(i=0;i<N;i++)
	  printf("%s %s %lf\n",s[i].id,s[i].mm,s[i].money);
	s[2].money=111;
    dr();
	return 0;
}
void csh()//初始化功能模块 
{
	FILE *fp;
	fp=fopen("aa.txt","r");
	if(fp==NULL)
	{ 
	   printf("error");
	   exit(0);
	}
	int i;
	for(i=0;i<N;i++)
	  fscanf(fp,"%s%s%lf",s[i].id,s[i].mm,&s[i].money);
	fclose(fp);	
}
void dr()//登录兼并主菜单功能选项功能模块 
{
	printf("请输入账户和密码：\n");
	int i,c=0;
	char id,mm;
    while(1)
    {
	scanf("%s%s",user.id,user.mm);
	for(i=0;i<N;i++)
	  if(strcmp(s[i].id,user.id)==0)
	    if(strcmp(s[i].mm,user.mm)==0)	 
	     {   a=i;
	    	break;
		 }
	if(i>=N)
	 {
		c++;
		printf("账户或密码有误！只能重复登录3次\n");
	 }
	else
	 {  a=i;
		printf("请选择您的操作编号：1是更改密码，2是取款，3是转账，4是余额查询,5是退出\n");//主菜单选项 
		caidan();
		break;
	 }
	if(c==3)
		{
			  printf("您已经重复登录3次，退出使用，欢迎您下次使用！\n");
			  break;
		}
    }
}
void caidan()//菜单功能模块 
    {
    int t;
	scanf("%d",&t);
	switch(t)
	{
		case 1:change();
		break;
		case 2:qukuan();
		break;
		case 3:zhuanzhang();
		break;
		case 4:yuechaxun();
		break;
		case 5:quit();
	}
 }
 void change()//更改密码功能模块 
 {
 	printf("请输入您想更改的密码\n");
 	scanf("%s",s[a].mm);
 	printf("修改成功，请继续您的操作\n");
 	caidan();
 }
 void qukuan()//取款功能模块 
 {  double je;
 	while(1)
 	{
	printf("请输入您想取款的金额:\n");
 	scanf("%lf",&je);
 	 if(je<=s[a].money)
 	 {
 		s[a].money-=je;
 		break;
	 }
	 else
	 printf("余额不足！\n");
	}
 	 printf("取款完成,请继续您的操作\n");
 	 caidan();
 }
 void zhuanzhang()//转账功能模块 
 { 
 int x=0,c=0;
 double qian;
 printf("请您输入想转账的账户:\n");
 scanf("%s",user.id);
 while(1)
 {
 for(x;x<N;x++)
  {
   if(strcmp(s[x].id,user.id)==0)
    {
    b=x;
    break;
    }
  }
  if(x>=N)
	{
		c++;
		printf("账户有误!只能输入3次\n");
	}
  else
  {
 while(1)
    {
	printf("请输入您想转入的金额:\n");
 	scanf("%lf",&qian);
 	 if(qian<=s[a].money)
 	  {  
	    s[a].money-=qian;
 		s[b].money+=qian;
 		break;
	  }
	 else
	 printf("余额不足！请重新输入金额\n");
	}
 	 printf("转账完成,请继续您的操作\n");
 	 caidan();
  }
  if(c==3)
		{
			  printf("您已经输入错误的账号超过3次，退出使用，欢迎您下次使用！\n");
			  break;
		}
 }
 }
 void yuechaxun()//余额查询功能模块
 {
  printf("您的余额为：%lf请继续您的操作\n",s[a].money);
  caidan();
 } 
 void quit()//退出功能模块 
{
	FILE *fp;
	fp=fopen("aa.txt","w");
	if(fp==NULL)
	{ 
	   printf("error");
	   exit(0);
	}
	int i;
	for(i=0;i<N;i++)
	  fprintf(fp,"%s %s %lf\n",s[i].id,s[i].mm,s[i].money);
	fclose(fp);
	exit(0);
}
