#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 2
int a,b;//��λ�� 
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
	//���ݲ��� 
   	int i;
   	printf("���ݿ�:\n");
	for(i=0;i<N;i++)
	  printf("%s %s %lf\n",s[i].id,s[i].mm,s[i].money);
	s[2].money=111;
    dr();
	return 0;
}
void csh()//��ʼ������ģ�� 
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
void dr()//��¼�沢���˵�����ѡ���ģ�� 
{
	printf("�������˻������룺\n");
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
		printf("�˻�����������ֻ���ظ���¼3��\n");
	 }
	else
	 {  a=i;
		printf("��ѡ�����Ĳ�����ţ�1�Ǹ������룬2��ȡ�3��ת�ˣ�4������ѯ,5���˳�\n");//���˵�ѡ�� 
		caidan();
		break;
	 }
	if(c==3)
		{
			  printf("���Ѿ��ظ���¼3�Σ��˳�ʹ�ã���ӭ���´�ʹ�ã�\n");
			  break;
		}
    }
}
void caidan()//�˵�����ģ�� 
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
 void change()//�������빦��ģ�� 
 {
 	printf("������������ĵ�����\n");
 	scanf("%s",s[a].mm);
 	printf("�޸ĳɹ�����������Ĳ���\n");
 	caidan();
 }
 void qukuan()//ȡ���ģ�� 
 {  double je;
 	while(1)
 	{
	printf("����������ȡ��Ľ��:\n");
 	scanf("%lf",&je);
 	 if(je<=s[a].money)
 	 {
 		s[a].money-=je;
 		break;
	 }
	 else
	 printf("���㣡\n");
	}
 	 printf("ȡ�����,��������Ĳ���\n");
 	 caidan();
 }
 void zhuanzhang()//ת�˹���ģ�� 
 { 
 int x=0,c=0;
 double qian;
 printf("����������ת�˵��˻�:\n");
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
		printf("�˻�����!ֻ������3��\n");
	}
  else
  {
 while(1)
    {
	printf("����������ת��Ľ��:\n");
 	scanf("%lf",&qian);
 	 if(qian<=s[a].money)
 	  {  
	    s[a].money-=qian;
 		s[b].money+=qian;
 		break;
	  }
	 else
	 printf("���㣡������������\n");
	}
 	 printf("ת�����,��������Ĳ���\n");
 	 caidan();
  }
  if(c==3)
		{
			  printf("���Ѿ����������˺ų���3�Σ��˳�ʹ�ã���ӭ���´�ʹ�ã�\n");
			  break;
		}
 }
 }
 void yuechaxun()//����ѯ����ģ��
 {
  printf("�������Ϊ��%lf��������Ĳ���\n",s[a].money);
  caidan();
 } 
 void quit()//�˳�����ģ�� 
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
