#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
#include<pthread.h>
#include<time.h>
//整体链表保持代表头 
typedef struct account_number_x {// 
	char name[30];
	int  account_number;//账号 
	int  password;//密码 
	account_number_x* next;
}account_number_X;
typedef struct tyre_information {//学生 
	char curriculum[30];//课程
	char Teacher[30];//任课老师名字
	char class_x[30];//班级
	int  quantity;//剩余选课数量 
	tyre_information* next;
}informatioN;
typedef struct name1 {
	char name[30];//名字
	int  account_number;//账号 
	int  password;//密码 
	name1* next;
}Name;
void student_x(informatioN* pt, Name* pi);
void str_x(informatioN* pt, Name* pi);
void my_curriculum(informatioN* pt, Name* po);
void preservation_(informatioN* pt);
int judge_NO_repeat(int account_number1);
int judge_z_m(int account_number, int password) {//判断账号密码是否正确 (正确管理员返回2)(学生返回1)(错误返回0)
	system("cls");
	FILE* pi = fopen("学生.txt", "r");
	int n = 0;
	char ch[30];
	int account_number1 = 0, password1 = 0;
	if (pi != NULL) {
		while (n == 0) {
			fscanf(pi, "%s%d%d", &ch, &account_number1, &password1);
			if (account_number == account_number1 && password == password1) {
				fclose(pi);
				return 1;//密码正确 
			}
			n = feof(pi);
		}fclose(pi);
	}
	FILE* pu = fopen("管理.txt", "r");
	if (pu != NULL) {
		n = 0;
		while (n == 0) {
			fscanf(pi, "%s%d%d", &ch, &account_number1, &password1);
			if (account_number == account_number1 && password == password1) {
				fclose(pu);
				return 2;//密码正确 //管理员() 
			}
			n = feof(pu);
		}fclose(pu);
	}
	FILE* pd = fopen("老师.txt", "r");
	if (pd != NULL) {
		n = 0;
		while (n == 0) {
			fscanf(pi, "%s%d%d", &ch, &account_number1, &password1);
			if (account_number == account_number1 && password == password1) {
				fclose(pd);
				return 3;//密码正确 //管理员() 
			}
			n = feof(pd);
		}fclose(pd);
	}
}
void temporary_x(int n, account_number_X* pt) {//临时储存
	account_number_X* pi = pt;
	while (pi->next != NULL) {
		pi = pi->next;
	}
	switch (n) {
	case 1: {//普通学生 
		FILE* pu = fopen("学生.txt", "r");
		if (pu != NULL) {
			int x = 0;
			fscanf(pu, "%d", &x);
			x = feof(pu);
			if (x == 0) {
				fclose(pu);
				pu = fopen("学生.txt", "r");
				while (x == 0) {
					pi = pi->next = (account_number_X*)malloc(sizeof(account_number_X));
					fscanf(pu, "%s%d%d", &pi->name, &pi->account_number, &pi->password);
					x = feof(pu);
				}pi->next = NULL;
			}
		}
		break;
	}
	case 2: {//管理员
		FILE* pu = fopen("管理.txt", "r");
		if (pu != NULL) {
			int x = 0;
			fscanf(pu, "%d", &x);
			x = feof(pu);
			if (x == 0) {
				fclose(pu);
				pu = fopen("管理.txt", "r");
				while (x == 0) {
					pi = pi->next = (account_number_X*)malloc(sizeof(account_number_X));
					fscanf(pu, "%s%d%d", &pi->name, &pi->account_number, &pi->password);
					x = feof(pu);
				}pi->next = NULL;
			}
		}

		break;
	}
	case 3: {
		FILE* pu = fopen("老师.txt", "r");
		if (pu != NULL) {
			int x = 0;
			fscanf(pu, "%d", &x);
			x = feof(pu);
			if (x == 0) {
				fclose(pu);
				pu = fopen("老师.txt", "r");
				while (x == 0) {
					pi = pi->next = (account_number_X*)malloc(sizeof(account_number_X));
					fscanf(pu, "%s%d%d", &pi->name, &pi->account_number, &pi->password);
					x = feof(pu);
				}pi->next = NULL;
			}
		}
		break;
	}
	}

}
void delete_ss(account_number_X* pt, int account_number) {//删除节点(根据账号删除) 
	account_number_X* pi = pt;
	int x = 0;
	while (pi != NULL) {
		if (pi->next->account_number == account_number) {
			pi->next = pi->next->next;
			break;
		}
		pi = pi->next;
	}
}
void Read_in_z_x(account_number_X* pt, int n) {//(1删除普通学生)(2删除管理) 
	switch (n) {
	case 1: {
		FILE* ua = fopen("学生.txt", "w");
		account_number_X* pi = pt->next;
		while (pi != NULL) {
			fprintf(ua, " %s %d %d ", pi->name, pi->account_number, pi->password);
			pi = pi->next;
		}fclose(ua);
		break;
	}
	case 2: {
		FILE* ua = fopen("管理.txt", "w");
		account_number_X* pi = pt->next;
		while (pi != NULL) {
			fprintf(ua, " %s %d %d ", pi->name, pi->account_number, pi->password);
			pi = pi->next;
		}fclose(ua);
		break;
	}
	case 3: {
		FILE* ua = fopen("老师.txt", "w");
		account_number_X* pi = pt->next;
		while (pi != NULL) {
			fprintf(ua, " %s %d %d ", pi->name, pi->account_number, pi->password);
			pi = pi->next;
		}fclose(ua);
		break;
	}
	}


}
void cancellation() {//注销账号 
	system("cls");
	int  account_number = 0;//账号 
	int  password = 0;//密码 
	int y = 0;
	printf("%50c输入要注销的账号:", ' ');
	scanf("%d", &account_number);
	printf("%50c输入要注销的密码:", ' ');
	scanf("%d", &password);
	int n = 0;
	n = judge_z_m(account_number, password);
	if (n == 1) {//如果是普通学生 
		account_number_X* px = (account_number_X*)malloc(sizeof(account_number_X)); px->next = NULL;
		temporary_x(1, px);
		//然后删除节点//再读入文件
		delete_ss(px, account_number);
		//最后读入文件
		Read_in_z_x(px, 1);
		y++;
		printf("注销成功!\n");
		system("pause");
	}
	if (n == 2) {//管理员注销
		account_number_X* px = (account_number_X*)malloc(sizeof(account_number_X)); px->next = NULL;
		temporary_x(2, px);
		//然后删除节点//再读入文件
		delete_ss(px, account_number);
		//最后读入文件
		Read_in_z_x(px, 2);
		printf("注销成功!\n");
		y++;
		system("pause");
	}if (y == 3) {//注销老师的账号 
		account_number_X* px = (account_number_X*)malloc(sizeof(account_number_X)); px->next = NULL;
		temporary_x(3, px);
		//然后删除节点//再读入文件
		delete_ss(px, account_number);
		//最后读入文件
		Read_in_z_x(px, 3);
		printf("注销成功!\n");
		y++;
		system("pause");
	}
	if (y == 0) {
		printf("注销失败没有该账号!\n");
		system("pause");
	}


}


void administrators_x() {//管理员注册 
	system("cls");
	int account_number = 0, account_number1 = 0;//账号
	int password = 0, password1 = 0, invitation = 0;//密码 
	char name[30];
	printf("请输入账号:");
	scanf("%d", &account_number);
	printf("请输入密码:");
	scanf("%d", &password);
	printf("输入姓名:");
	scanf("%s", &name);
	printf("请输入邀请码:");
	scanf("%d", &invitation);
	if (invitation == 12345) {
		int y = 0;
		y = judge_NO_repeat(account_number);//判断账号是否相同
		if (y == 0) {
			FILE* pu = fopen("管理.txt", "a");
			if (pu != NULL) {
				fprintf(pu, " %s %d %d ", name, account_number, password);
				fclose(pu);
			}
			else {
				fclose(pu);
				pu = fopen("管理.txt", "w");
				fprintf(pu, " %s %d %d ", name, account_number, password);
				fclose(pu);
			}
		}
		else {
			printf("账号重复请换一个吧!\n");
			system("pause");
			return;
		}
		printf("注册成功! \n");
		system("pause");
	}
	else {
		printf("抱歉邀请码错误哦!\n");
		system("pause");
	}
}
void user_x() {//学生注册 
	int account_number = 0, account_number1 = 0;//账号
	int password = 0, password1 = 0;//密码 
	char name[30];
	printf("请输入账号:");
	scanf("%d", &account_number);
	printf("请输入密码:");
	scanf("%d", &password);
	printf("请输入姓名:");
	scanf("%s", &name);
	int y = 0;
	y = judge_NO_repeat(account_number);//判断账号是否相同
	if (y == 0) {
		FILE* pu = fopen("学生.txt", "a");
		if (pu != NULL) {
			fprintf(pu, " %s %d %d", name, account_number, password);
			fclose(pu);
		}
		else {
			fclose(pu);
			pu = fopen("学生.txt", "w");
			fprintf(pu, " %s %d %d", name, account_number, password);
			fclose(pu);
		}
	}
	else {
		printf("账号重复请换一个吧!\n");
		system("pause");
		return;
	}
	printf("注册成功! \n");
	system("pause");

}
void teacher_x() {//老师注册 
	system("cls");
	int account_number = 0, account_number1 = 0;//账号
	int password = 0, password1 = 0, invitation = 0;//密码 
	char name[30];
	printf("请输入账号:");
	scanf("%d", &account_number);
	printf("请输入密码:");
	scanf("%d", &password);
	printf("请输入姓名:");
	scanf("%s", &name);
	printf("请输入管理码:");
	scanf("%d", &invitation);
	if (invitation == 12345) {
		int y = 0;
		y = judge_NO_repeat(account_number);//判断账号是否相同
		if (y == 0) {
			FILE* pu = fopen("老师.txt", "a");
			if (pu != NULL) {
				fprintf(pu, " %s %d %d", name, account_number, password);
				fclose(pu);
			}
			else {
				fclose(pu);
				pu = fopen("老师.txt", "w");
				fprintf(pu, " %s %d %d", name, account_number, password);
				fclose(pu);
			}
		}
		else {
			printf("账号重复请换一个吧!\n");
			system("pause");
			return;
		}
		printf("注册成功! \n");
		system("pause");
	}
	else {
		printf("抱歉邀请码错误哦!\n");
		system("pause");
	}
}
int judge_NO_repeat(int account_number1) {//判断文件中是否有重复的账号//没有返回0//有返回1 
//传账号过来 
	FILE* pi = fopen("学生.txt", "r");
	int account_number = 0, password = 0;//账号密码 
	int ch[30];
	if (pi != NULL) {
		int n = 0;
		while (n == 0) {
			fscanf(pi, "%s%d%d", &ch, &account_number, &password);
			if (account_number1 == account_number) {
				fclose(pi);
				return 1;
			}
			n = feof(pi);
		}
	}
	FILE* pu = fopen("管理.txt", "r");
	if (pu != NULL) {
		int n = 0;
		while (n == 0) {
			fscanf(pu, "%s%d%d", &ch, &account_number, &password);
			if (account_number1 == account_number) {
				fclose(pu);
				return 1;
			}
			n = feof(pu);
		}
	}
	return 0;
}

void register_s_s() {//注册 //注册时注意判断是否有账号重复 
	system("cls");
	printf("%30c------------------------------------------\n", ' ');
	printf("%30c|              龙哥登录系统                  |\n", ' ');
	printf("%30c|                                         |\n", ' ');
	printf("%30c| [1]学生注册        [2]管理员注册        |\n", ' ');
	printf("%30c| [3]老师注册        [4]exit              |\n", ' ');
	printf("%30c|                                         |\n", ' ');
	printf("%30c------------------------------------------\n", ' ');
	int n = 0;
	scanf("%d", &n);
	switch (n) {
	case 1: {
		user_x();
		break;
	}
	case 2: {
		administrators_x();
		break;
	}
	case 3: {
		teacher_x();
		break;
	}
	case 4: {
		return;
		break;
	}
	}
}
int  Sign_in_x(Name* pt) {//登录成功返回1理员返回2//学生返回1//密码错误返回0 
	system("cls");
	FILE* pi = fopen("学生.txt", "r");
	int account_number = 0, account_number1 = 0;//账号
	int n = 0;
	int password = 0, password1 = 0;//密码 
	printf("%50c输入账号:", ' ');
	scanf("%d", &account_number);
	printf("%50c输入密码:", ' ');
	scanf("%d", &password);
	char ch[30];
	if (pi != NULL) {
		while (n == 0) {
			fscanf(pi, "%s%d%d", &ch, &account_number1, &password1);
			if (account_number == account_number1 && password == password1) {
				fclose(pi);
				pt->account_number = account_number;
				pt->password = password;
				strcpy(pt->name, ch);
				return 1;//密码正确 
			}
			n = feof(pi);
		}fclose(pi);
	}
	FILE* pu = fopen("管理.txt", "r");
	if (pu != NULL) {
		n = 0;
		while (n == 0) {
			fscanf(pi, "%s%d%d", &ch, &account_number1, &password1);
			if (account_number == account_number1 && password == password1) {
				fclose(pu);
				pt->account_number = account_number;
				pt->password = password;
				strcpy(pt->name, ch);
				return 2;//密码正确 //管理员() 
			}
			n = feof(pu);
		}fclose(pu);
	}
	FILE* pd = fopen("老师.txt", "r");
	if (pd != NULL) {
		n = 0;
		while (n == 0) {
			fscanf(pd, "%s%d%d", &ch, &account_number1, &password1);
			if (account_number == account_number1 && password == password1) {
				fclose(pd);
				pt->account_number = account_number;
				pt->password = password;
				strcpy(pt->name, ch);
				return 3;//密码正确 //管理员() 
			}
			n = feof(pd);
		}fclose(pd);
	}
}
int Login_interface(Name* pt) {//登录界面/管理员返回2//学生返回1//密码错误返回0 
	printf("%50c欢迎使用......", ' ');
	Sleep(300);
	while (1) {
		system("cls");
		printf("%30c----------------------------------------------\n", ' ');
		printf("%30c|              龙哥登录系统                  |\n", ' ');
		printf("%30c|                                            |\n", ' ');
		printf("%30c| [1]登录   [2]注销账号   [3]注册   [4]exit  |\n", ' ');
		printf("%30c|                                            |\n", ' ');
		printf("%30c----------------------------------------------\n", ' ');
		int n = 0;
		printf("%30c选择功能选项:", ' ');
		scanf("%d", &n);
		switch (n) {
		case 1: {
			int p = 0;
			p = Sign_in_x(pt);
			if (p == 1) {//普通学生 
				system("cls");
				printf("%50c欢迎学生登录!", ' ');
				system("pause");
				return 1;
			}
			else {//否则 
				if (p == 2) {//管理员 
					system("cls");
					printf("%50c欢迎管理登录!\n", ' ');
					system("pause");
					return 2;
				}
				if (p == 3) {
					system("cls");
					printf("%50c欢迎老师登录!\n", ' ');
					system("pause");
					return 3;
				}
			}
			printf("账号密码错误!\n");
			system("pause");
			break;
		}
		case 2: {
			cancellation();
			break;
		}
		case 3: {
			register_s_s();
			break;
		}
		case 4: {
			return 0;
			break;
		}
		}
	}
}
int main(void) {
	Name* pt = (Name*)malloc(sizeof(Name));
	pt->next = NULL;
	Login_interface(pt);
}