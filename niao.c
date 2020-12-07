
#include"qimo.h"
#include<stdio.h>
#include<stdlib.h>           
#include<string.h>
#define N 100


Book a[N];

char name[80] ,pas[80],temp[80];
char textstring[80];
int ok=0;Book a[N];



void regist(){
	FILE *fp=fopen("user.txt","a");/*以写模式("w")打开文件user.txt,如果不存在,会自动创建*/
	printf("请输入账号");
	gets(name);
	printf("请输入密码");
	gets(pas); /*输入名称和密码*/
	fputs(name,fp);
	fputs(pas,fp);/*将名称和密码以字符串形式写入文件*/
	fputs("\n",fp);
	fflush(stdin);//清除缓存
	fclose(fp);/*关闭文件*/
	login();//注册完转到登录界面
}


void menu()										 
{
	books();
	do
	{
		int n;
		printf(" __________________________________\n"); 
		printf("|******---------------------******|\n");
		printf("|      欢迎进入图书管理系统       |\n"); 
		printf("|                                 |\n");
		printf("|                                 |\n");
		printf("|                                 |\n");
		printf("|                                 |\n");
		printf("|                                 |\n");
		printf("|  *       1.图书查询          *  |\n");
		printf("|  *       2.打印全部图书      *  |\n");
		printf("|  *       3.图书数量排序      *  |\n");     
		printf("|  *       4.统计价格          *  |\n");   
		printf("|  *       5.图书修改          *  |\n");
		printf("|  *       6.借阅图书          *  |\n");
		printf("|  *       0.退出              *  |\n");
		printf("|                                 |\n");
		printf("|                                 |\n");
		printf("|                                 |\n");
		printf("|                                 |\n");
		printf("|******---------------------******|\n");
		printf("|_________________________________|\n");
		printf("                 注:输入对应序号!\n"); 
		scanf("%d",&n);
		fflush(stdin);
		switch( n )
		{
			case 1 : refer();   break;
			case 2 : show();    break;
			case 3 : amount();  break;
			case 4 : pr();      break;
			case 5 : alter();   break;
			case 6 : borrow();  break;
			case 0 : over();    break;
			default :break;
		}
	}while(1); 
}
void books()                                     
{
	int n = 0;
	FILE *fr = fopen("C:\JK0627.txt","r+"); 
	if(fr == NULL) {
		printf("打开文件出错。\n");
		return 1;
	}
	//存入第一行
	fscanf(fr,"%s\t%s\t%s\t%s\t%s\t%s\t%s",&a[0].nume,&a[1].nume,&a[2].nume,&a[3].nume,&a[4].nume,&a[5].nume,&a[6].nume);                  
	while(!feof(fr)) {                           //      feof(fr)有两个返回值:   如果遇到文件结束，函数feof（fr）的值为非零值，否则为0
		//存入1~10行       整数类的必须加入地址符，字符串可要可不要 
		fscanf(fr,"%d\t%s\t%s\t%s\t%s\t%d\t%lf\n",&a[n].num,&a[n].type,&a[n].name,&a[n].author,&a[n].press,&a[n].quantity,&a[n].price);
		n++;
	}
	fclose(fr);
}

void refer()                                     
{
	int i,n,m=0,p;
	char nam[30];
	system("cls");
	printf("请输入您要查询的书名：");
	scanf("%s",&nam);
	fflush(stdin);
	for( i=0; i < 10; i++ )
	{
		if( strcmp(nam,a[i].name) == 0 ){              
			m = 1;
			p = i;                 
			break;
		}
	}
	if( m = 1) {
		system("cls");
		printf("*************************************************图书总览***********************************************\n");
		printf("--------------------------------------------------------------------------------------------------------\n");

		printf("%s\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t\t%s\n",a[0].nume,a[1].nume,a[2].nume,a[3].nume,a[4].nume,a[5].nume,a[6].nume);   

		printf("%d\t%-10s\t%s\t%-10s\t%-20s\t%d\t\t%.2lf\n",a[p].num,a[p].type,a[p].name,a[p].author,a[p].press,a[p].quantity,a[p].price);    
		printf("--------------------------------------------------------------------------------------------------------\n");
	}else {
		printf("馆内无此书！");
	}
	printf("\n\n-----------------------\n");
	printf("|   是否继续查询？    |\n");
	printf("| 1.是     2.否   |\n");
	printf("-----------------------\n");
	scanf("%d",&n); 
	if( n==1 ){
		refer();
	}
	else if( n==2 ){
		system("cls");
		menu();
	}
}

void show()                                  
{
	system("cls");
	int i;
	char n;
	printf("*************************************************图书总览***********************************************\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("%s\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t\t%s\n",a[0].nume,a[1].nume,a[2].nume,a[3].nume,a[4].nume,a[5].nume,a[6].nume);
	for( i=0; i<10; i++ )
	{
		printf("%d\t%-10s\t%s\t%-10s\t%-20s\t%d\t\t%.2lf\n",a[i].num,a[i].type,a[i].name,a[i].author,a[i].press,a[i].quantity,a[i].price);
	}
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("\n按任意字符回车返回主菜单！\n");
	fflush(stdin);
	n=getchar();
	system("cls");
	menu();
}

void amount()                                    
{
	int i,j;
	char n;
	for( i=0; i<10-1; i++ )
	{
		for( j=0; j<10-1-i; j++ )
		{
			if( a[j].quantity > a[j+1].quantity )                                 
			{
				int m;
				double p;
				char b[30];
				m = a[j].quantity; a[j].quantity = a[j+1].quantity; a[j+1].quantity = m;
				m = a[j].num; a[j].num = a[j+1].num; a[j+1].num = m;
				p = a[j].price; a[j].price = a[j+1].price; a[j+1].price = p;
				strcpy(b,a[j].type); strcpy(a[j].type,a[j+1].type); strcpy(a[j+1].type,b);
				strcpy(b,a[j].name); strcpy(a[j].name,a[j+1].name); strcpy(a[j+1].name,b);
				strcpy(b,a[j].author); strcpy(a[j].author,a[j+1].author); strcpy(a[j+1].author,b);
				strcpy(b,a[j].press); strcpy(a[j].press,a[j+1].press); strcpy(a[j+1].press,b);
			}
		}
	}
	system("cls");								//将重新排序的结果打印 
	printf("*************************************************图书总览***********************************************\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("%s\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t\t%s\n",a[0].nume,a[1].nume,a[2].nume,a[3].nume,a[4].nume,a[5].nume,a[6].nume);
	for( i=0; i<10; i++ )
	{
		printf("%d\t%-10s\t%s\t%-10s\t%-20s\t%d\t\t%.2lf\n",a[i].num,a[i].type,a[i].name,a[i].author,a[i].press,a[i].quantity,a[i].price);
	}
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("\n按任意字符回车返回主菜单！\n");
	fflush(stdin);
	n=getchar();
	system("cls");
	menu();
}

void pr()                                       
{
	int i;
	char n;
	double b[10],sum=0.0;
	for( i=0; i<10; i++ )
	{
		b[i] = a[i].price*a[i].quantity;                       
		sum = sum + b[i];
	}
	FILE *fp = fopen("D:\ZJ0627.txt","w");                                
	fprintf(fp,"%s\t%s\t%s\t\t%s\t\t%s\t\t\t%s\t%s\t%s\n",a[0].nume,a[1].nume,a[2].nume,a[3].nume,a[4].nume,a[5].nume,a[6].nume,"总价");
	for( i=0; i<10; i++ ){

		fprintf(fp,"%d\t%s\t%-20s\t%s\t\t%-30s\t%d\t%.2lf\t%.2lf\n",a[i].num,a[i].type,a[i].name,a[i].author,a[i].press,a[i].quantity,a[i].price,b[i]);
	}
	fprintf(fp,"\t\t\t\t\t\t\t\t\t\t%s\t%.2lf","总价",sum);        
	if( fp != NULL )
	{
		system("cls");
		printf("恭喜你，存入文件夹成功！\n");
	}
	fclose(fp);
	printf("\n按任意字符回车返回主菜单！\n");
	fflush(stdin);
	n=getchar();
	system("cls");
	menu();
}

void alter()                                     
{
	system("cls");
	char b[20],c[20];
	int i,n,m;
	double p;
	printf("输入你要修改的图书名或作家名：");
	fflush(stdin);
	scanf("%s",&b);
	for( i=0; i<10; i++ )
	{
		if( strcmp( b , a[i].name ) == 0 || strcmp( b , a[i].author) == 0 )
		{
			system("cls"); 
			printf("*************************************************图书总览***********************************************\n");
			printf("--------------------------------------------------------------------------------------------------------\n");
			//         打印第一行
			printf("%s\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t\t%s\n",a[0].nume,a[1].nume,a[2].nume,a[3].nume,a[4].nume,a[5].nume,a[6].nume);   
			//         打印1~10行 
			printf("%d\t%-10s\t%s\t%-10s\t%-20s\t%d\t\t%.2lf\n",a[i].num,a[i].type,a[i].name,a[i].author,a[i].press,a[i].quantity,a[i].price);    
			printf("--------------------------------------------------------------------------------------------------------\n");
			printf("\n注：编号(0),分类(1),书名(2),作者(3),出版社(4),数量(5),单价(6)\n输入您要修改的选项的序号:");
			fflush(stdin);
			scanf("%d",&n);
			switch( n )
			{
				system("cls");
				case 0:printf("输入你要修改后的[%s]：",a[0].nume);fflush(stdin);scanf("%d",&m);a[i].num = m;     
				       if( a[i].num == m ){	printf("修改成功！\n");	}	break;
				case 1:printf("输入你要修改后的[%s]：",a[1].nume);fflush(stdin);scanf("%s",&c);strcpy(a[i].type,c);  
				       if( strcmp(a[i].type,c) == 0 ){	printf("修改成功！\n");	}	break;
				case 2:printf("输入你要修改后的[%s]：",a[2].nume);fflush(stdin);scanf("%s",&c);strcpy(a[i].name,c);
				       if( strcmp(a[i].name,c) == 0 ){	printf("修改成功！\n");}	break;
				case 3:printf("输入你要修改后的[%s]：",a[3].nume);fflush(stdin);scanf("%s",&c);strcpy(a[i].author,c);
				       if( strcmp(a[i].author,c) == 0 ){	printf("修改成功！\n");}	break;
				case 4:printf("输入你要修改后的[%s]：",a[4].nume);fflush(stdin);scanf("%s",&c);strcpy(a[i].press,c);
				       if( strcmp(a[i].press,c) == 0 ){	printf("修改成功！\n");}	break;
				case 5:printf("输入你要修改后的[%s]：",a[5].nume);fflush(stdin);scanf("%d",&m);a[i].quantity = m;
				       if( a[i].quantity == m ){	printf("修改成功！\n");} 	break;
				case 6:printf("输入你要修改后的[%s]：",a[6].nume);fflush(stdin);scanf("%lf",&p);a[i].price = p;
				       if( a[i].price==p  ){	printf("修改成功！\n");}	break;
				default :printf("修改失败！\n");	break;
			}
			FILE *f = fopen("D:\JK0627.txt","w");                  
			fprintf(f,"%s\t%s\t%s\t\t%s\t\t%s\t\t\t%s\t%s\n",a[0].nume,a[1].nume,a[2].nume,a[3].nume,a[4].nume,a[5].nume,a[6].nume);
			for( i=0; i<10; i++ )
			{
				fprintf(f,"%d\t%s\t%-20s\t%s\t\t%-30s\t%d\t%.2lf\n",a[i].num,a[i].type,a[i].name,a[i].author,a[i].press,a[i].quantity,a[i].price);
			}
			if( f != NULL )
			{
				printf("存入文件夹成功！\n");
			}
			else
			{
				printf("存入文件夹失败！\n");
			}
			fclose(f);
			printf("-----------------------\n");
			printf("|      继续修改？     |\n");
			printf("| 1.确定     2.取消   |\n");
			printf("-----------------------\n");
			fflush(stdin);
			scanf("%d",&n);
			if( n==1 ){
				alter();
			}else{
				system("cls");
				menu();
			}
		}else if( i == 9){
			printf("你所要修改的图书不在书库中，请重新输入！\n");
			printf("-----------------------\n");
			printf("|      继续修改？     |\n");
			printf("| 1.确定     2.取消   |\n");
			printf("-----------------------\n");
			fflush(stdin);
			scanf("%d",&n);
			if( n==1 ){
				alter();
			}else{
				system("cls");
				menu();
			}
		}
	}
}

void borrow()                                
{
	system("cls");
	int i,n;
	char b[20];
	printf("输入你要借阅的书籍：");
	scanf("%s",&b);
	for( i=0; i<10; i++ )
	{
		if( strcmp( b , a[i].name ) == 0  )        
		{
			if( a[i].quantity > 0 )
			{
				a[i].quantity = a[i].quantity - 1;           
				printf("\n\n借出成功！");
				FILE *f = fopen("D:\JK0627.txt","w");                  
				fprintf(f,"%s\t%s\t%s\t\t%s\t\t%s\t\t\t%s\t%s\n",a[0].nume,a[1].nume,a[2].nume,a[3].nume,a[4].nume,a[5].nume,a[6].nume);
				for( i=0; i<10; i++ )
				{
					fprintf(f,"%d\t%s\t%-20s\t%s\t\t%-30s\t%d\t%.2lf\n",a[i].num,a[i].type,a[i].name,a[i].author,a[i].press,a[i].quantity,a[i].price);
				}
				if( f != NULL )
				{
					printf("存入文件夹成功！\n");
				}
				else
				{
					printf("存入文件夹失败！");
				}
				fclose(f);
				printf("-----------------------\n");
				printf("|      继续借阅？     |\n");
				printf("| 1.确定     2.取消   |\n");
				printf("-----------------------\n");
				fflush(stdin);
				scanf("%d",&n);
				if( n==1 ){
					borrow();
				}else{
					system("cls");
					menu();
				}
			}else{
				printf("次书库存不足！\n");
				printf("-----------------------\n");
				printf("|      继续借阅？     |\n");
				printf("| 1.确定     2.取消   |\n");
				printf("-----------------------\n");
				fflush(stdin);
				scanf("%d",&n);
				if( n==1 ){
					borrow();
				}else{
					system("cls");
					menu();
				}
			}
		}else if( i == 9 ){
			printf("书库中无此书！\n");
			printf("-----------------------\n");
			printf("|      继续借阅？     |\n");
			printf("| 1.确定     2.取消   |\n");
			printf("-----------------------\n");
			fflush(stdin);
			scanf("%d",&n);
			if( n==1 ){
				borrow();
			}else{
				system("cls");
				menu();
			}
		}
	}
}

void over()                                
{
	int n;
	system("cls");
	printf("-----------------------\n");
	printf("|   您确定要退出吗？  |\n");
	printf("| 1.确定     2.取消   |\n");
	printf("-----------------------\n");
	scanf("%d",&n);
	if( n==1 ){
		exit(0);                  //结束程序 
	}
	else if( n==2 ){
		system("cls");
		menu();               // 返回菜单 
	}
} 

