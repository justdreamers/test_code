#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
#include<pthread.h>
#include<time.h>
//���������ִ���ͷ 
typedef struct account_number_x {// 
	char name[30];
	int  account_number;//�˺� 
	int  password;//���� 
	account_number_x* next;
}account_number_X;
typedef struct tyre_information {//ѧ�� 
	char curriculum[30];//�γ�
	char Teacher[30];//�ο���ʦ����
	char class_x[30];//�༶
	int  quantity;//ʣ��ѡ������ 
	tyre_information* next;
}informatioN;
typedef struct name1 {
	char name[30];//����
	int  account_number;//�˺� 
	int  password;//���� 
	name1* next;
}Name;
void student_x(informatioN* pt, Name* pi);
void str_x(informatioN* pt, Name* pi);
void my_curriculum(informatioN* pt, Name* po);
void preservation_(informatioN* pt);
int judge_NO_repeat(int account_number1);
int judge_z_m(int account_number, int password) {//�ж��˺������Ƿ���ȷ (��ȷ����Ա����2)(ѧ������1)(���󷵻�0)
	system("cls");
	FILE* pi = fopen("ѧ��.txt", "r");
	int n = 0;
	char ch[30];
	int account_number1 = 0, password1 = 0;
	if (pi != NULL) {
		while (n == 0) {
			fscanf(pi, "%s%d%d", &ch, &account_number1, &password1);
			if (account_number == account_number1 && password == password1) {
				fclose(pi);
				return 1;//������ȷ 
			}
			n = feof(pi);
		}fclose(pi);
	}
	FILE* pu = fopen("����.txt", "r");
	if (pu != NULL) {
		n = 0;
		while (n == 0) {
			fscanf(pi, "%s%d%d", &ch, &account_number1, &password1);
			if (account_number == account_number1 && password == password1) {
				fclose(pu);
				return 2;//������ȷ //����Ա() 
			}
			n = feof(pu);
		}fclose(pu);
	}
	FILE* pd = fopen("��ʦ.txt", "r");
	if (pd != NULL) {
		n = 0;
		while (n == 0) {
			fscanf(pi, "%s%d%d", &ch, &account_number1, &password1);
			if (account_number == account_number1 && password == password1) {
				fclose(pd);
				return 3;//������ȷ //����Ա() 
			}
			n = feof(pd);
		}fclose(pd);
	}
}
void temporary_x(int n, account_number_X* pt) {//��ʱ����
	account_number_X* pi = pt;
	while (pi->next != NULL) {
		pi = pi->next;
	}
	switch (n) {
	case 1: {//��ͨѧ�� 
		FILE* pu = fopen("ѧ��.txt", "r");
		if (pu != NULL) {
			int x = 0;
			fscanf(pu, "%d", &x);
			x = feof(pu);
			if (x == 0) {
				fclose(pu);
				pu = fopen("ѧ��.txt", "r");
				while (x == 0) {
					pi = pi->next = (account_number_X*)malloc(sizeof(account_number_X));
					fscanf(pu, "%s%d%d", &pi->name, &pi->account_number, &pi->password);
					x = feof(pu);
				}pi->next = NULL;
			}
		}
		break;
	}
	case 2: {//����Ա
		FILE* pu = fopen("����.txt", "r");
		if (pu != NULL) {
			int x = 0;
			fscanf(pu, "%d", &x);
			x = feof(pu);
			if (x == 0) {
				fclose(pu);
				pu = fopen("����.txt", "r");
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
		FILE* pu = fopen("��ʦ.txt", "r");
		if (pu != NULL) {
			int x = 0;
			fscanf(pu, "%d", &x);
			x = feof(pu);
			if (x == 0) {
				fclose(pu);
				pu = fopen("��ʦ.txt", "r");
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
void delete_ss(account_number_X* pt, int account_number) {//ɾ���ڵ�(�����˺�ɾ��) 
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
void Read_in_z_x(account_number_X* pt, int n) {//(1ɾ����ͨѧ��)(2ɾ������) 
	switch (n) {
	case 1: {
		FILE* ua = fopen("ѧ��.txt", "w");
		account_number_X* pi = pt->next;
		while (pi != NULL) {
			fprintf(ua, " %s %d %d ", pi->name, pi->account_number, pi->password);
			pi = pi->next;
		}fclose(ua);
		break;
	}
	case 2: {
		FILE* ua = fopen("����.txt", "w");
		account_number_X* pi = pt->next;
		while (pi != NULL) {
			fprintf(ua, " %s %d %d ", pi->name, pi->account_number, pi->password);
			pi = pi->next;
		}fclose(ua);
		break;
	}
	case 3: {
		FILE* ua = fopen("��ʦ.txt", "w");
		account_number_X* pi = pt->next;
		while (pi != NULL) {
			fprintf(ua, " %s %d %d ", pi->name, pi->account_number, pi->password);
			pi = pi->next;
		}fclose(ua);
		break;
	}
	}


}
void cancellation() {//ע���˺� 
	system("cls");
	int  account_number = 0;//�˺� 
	int  password = 0;//���� 
	int y = 0;
	printf("%50c����Ҫע�����˺�:", ' ');
	scanf("%d", &account_number);
	printf("%50c����Ҫע��������:", ' ');
	scanf("%d", &password);
	int n = 0;
	n = judge_z_m(account_number, password);
	if (n == 1) {//�������ͨѧ�� 
		account_number_X* px = (account_number_X*)malloc(sizeof(account_number_X)); px->next = NULL;
		temporary_x(1, px);
		//Ȼ��ɾ���ڵ�//�ٶ����ļ�
		delete_ss(px, account_number);
		//�������ļ�
		Read_in_z_x(px, 1);
		y++;
		printf("ע���ɹ�!\n");
		system("pause");
	}
	if (n == 2) {//����Աע��
		account_number_X* px = (account_number_X*)malloc(sizeof(account_number_X)); px->next = NULL;
		temporary_x(2, px);
		//Ȼ��ɾ���ڵ�//�ٶ����ļ�
		delete_ss(px, account_number);
		//�������ļ�
		Read_in_z_x(px, 2);
		printf("ע���ɹ�!\n");
		y++;
		system("pause");
	}if (y == 3) {//ע����ʦ���˺� 
		account_number_X* px = (account_number_X*)malloc(sizeof(account_number_X)); px->next = NULL;
		temporary_x(3, px);
		//Ȼ��ɾ���ڵ�//�ٶ����ļ�
		delete_ss(px, account_number);
		//�������ļ�
		Read_in_z_x(px, 3);
		printf("ע���ɹ�!\n");
		y++;
		system("pause");
	}
	if (y == 0) {
		printf("ע��ʧ��û�и��˺�!\n");
		system("pause");
	}


}


void administrators_x() {//����Աע�� 
	system("cls");
	int account_number = 0, account_number1 = 0;//�˺�
	int password = 0, password1 = 0, invitation = 0;//���� 
	char name[30];
	printf("�������˺�:");
	scanf("%d", &account_number);
	printf("����������:");
	scanf("%d", &password);
	printf("��������:");
	scanf("%s", &name);
	printf("������������:");
	scanf("%d", &invitation);
	if (invitation == 12345) {
		int y = 0;
		y = judge_NO_repeat(account_number);//�ж��˺��Ƿ���ͬ
		if (y == 0) {
			FILE* pu = fopen("����.txt", "a");
			if (pu != NULL) {
				fprintf(pu, " %s %d %d ", name, account_number, password);
				fclose(pu);
			}
			else {
				fclose(pu);
				pu = fopen("����.txt", "w");
				fprintf(pu, " %s %d %d ", name, account_number, password);
				fclose(pu);
			}
		}
		else {
			printf("�˺��ظ��뻻һ����!\n");
			system("pause");
			return;
		}
		printf("ע��ɹ�! \n");
		system("pause");
	}
	else {
		printf("��Ǹ���������Ŷ!\n");
		system("pause");
	}
}
void user_x() {//ѧ��ע�� 
	int account_number = 0, account_number1 = 0;//�˺�
	int password = 0, password1 = 0;//���� 
	char name[30];
	printf("�������˺�:");
	scanf("%d", &account_number);
	printf("����������:");
	scanf("%d", &password);
	printf("����������:");
	scanf("%s", &name);
	int y = 0;
	y = judge_NO_repeat(account_number);//�ж��˺��Ƿ���ͬ
	if (y == 0) {
		FILE* pu = fopen("ѧ��.txt", "a");
		if (pu != NULL) {
			fprintf(pu, " %s %d %d", name, account_number, password);
			fclose(pu);
		}
		else {
			fclose(pu);
			pu = fopen("ѧ��.txt", "w");
			fprintf(pu, " %s %d %d", name, account_number, password);
			fclose(pu);
		}
	}
	else {
		printf("�˺��ظ��뻻һ����!\n");
		system("pause");
		return;
	}
	printf("ע��ɹ�! \n");
	system("pause");

}
void teacher_x() {//��ʦע�� 
	system("cls");
	int account_number = 0, account_number1 = 0;//�˺�
	int password = 0, password1 = 0, invitation = 0;//���� 
	char name[30];
	printf("�������˺�:");
	scanf("%d", &account_number);
	printf("����������:");
	scanf("%d", &password);
	printf("����������:");
	scanf("%s", &name);
	printf("�����������:");
	scanf("%d", &invitation);
	if (invitation == 12345) {
		int y = 0;
		y = judge_NO_repeat(account_number);//�ж��˺��Ƿ���ͬ
		if (y == 0) {
			FILE* pu = fopen("��ʦ.txt", "a");
			if (pu != NULL) {
				fprintf(pu, " %s %d %d", name, account_number, password);
				fclose(pu);
			}
			else {
				fclose(pu);
				pu = fopen("��ʦ.txt", "w");
				fprintf(pu, " %s %d %d", name, account_number, password);
				fclose(pu);
			}
		}
		else {
			printf("�˺��ظ��뻻һ����!\n");
			system("pause");
			return;
		}
		printf("ע��ɹ�! \n");
		system("pause");
	}
	else {
		printf("��Ǹ���������Ŷ!\n");
		system("pause");
	}
}
int judge_NO_repeat(int account_number1) {//�ж��ļ����Ƿ����ظ����˺�//û�з���0//�з���1 
//���˺Ź��� 
	FILE* pi = fopen("ѧ��.txt", "r");
	int account_number = 0, password = 0;//�˺����� 
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
	FILE* pu = fopen("����.txt", "r");
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

void register_s_s() {//ע�� //ע��ʱע���ж��Ƿ����˺��ظ� 
	system("cls");
	printf("%30c------------------------------------------\n", ' ');
	printf("%30c|              �����¼ϵͳ                  |\n", ' ');
	printf("%30c|                                         |\n", ' ');
	printf("%30c| [1]ѧ��ע��        [2]����Աע��        |\n", ' ');
	printf("%30c| [3]��ʦע��        [4]exit              |\n", ' ');
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
int  Sign_in_x(Name* pt) {//��¼�ɹ�����1��Ա����2//ѧ������1//������󷵻�0 
	system("cls");
	FILE* pi = fopen("ѧ��.txt", "r");
	int account_number = 0, account_number1 = 0;//�˺�
	int n = 0;
	int password = 0, password1 = 0;//���� 
	printf("%50c�����˺�:", ' ');
	scanf("%d", &account_number);
	printf("%50c��������:", ' ');
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
				return 1;//������ȷ 
			}
			n = feof(pi);
		}fclose(pi);
	}
	FILE* pu = fopen("����.txt", "r");
	if (pu != NULL) {
		n = 0;
		while (n == 0) {
			fscanf(pi, "%s%d%d", &ch, &account_number1, &password1);
			if (account_number == account_number1 && password == password1) {
				fclose(pu);
				pt->account_number = account_number;
				pt->password = password;
				strcpy(pt->name, ch);
				return 2;//������ȷ //����Ա() 
			}
			n = feof(pu);
		}fclose(pu);
	}
	FILE* pd = fopen("��ʦ.txt", "r");
	if (pd != NULL) {
		n = 0;
		while (n == 0) {
			fscanf(pd, "%s%d%d", &ch, &account_number1, &password1);
			if (account_number == account_number1 && password == password1) {
				fclose(pd);
				pt->account_number = account_number;
				pt->password = password;
				strcpy(pt->name, ch);
				return 3;//������ȷ //����Ա() 
			}
			n = feof(pd);
		}fclose(pd);
	}
}
int Login_interface(Name* pt) {//��¼����/����Ա����2//ѧ������1//������󷵻�0 
	printf("%50c��ӭʹ��......", ' ');
	Sleep(300);
	while (1) {
		system("cls");
		printf("%30c----------------------------------------------\n", ' ');
		printf("%30c|              �����¼ϵͳ                  |\n", ' ');
		printf("%30c|                                            |\n", ' ');
		printf("%30c| [1]��¼   [2]ע���˺�   [3]ע��   [4]exit  |\n", ' ');
		printf("%30c|                                            |\n", ' ');
		printf("%30c----------------------------------------------\n", ' ');
		int n = 0;
		printf("%30cѡ����ѡ��:", ' ');
		scanf("%d", &n);
		switch (n) {
		case 1: {
			int p = 0;
			p = Sign_in_x(pt);
			if (p == 1) {//��ͨѧ�� 
				system("cls");
				printf("%50c��ӭѧ����¼!", ' ');
				system("pause");
				return 1;
			}
			else {//���� 
				if (p == 2) {//����Ա 
					system("cls");
					printf("%50c��ӭ�����¼!\n", ' ');
					system("pause");
					return 2;
				}
				if (p == 3) {
					system("cls");
					printf("%50c��ӭ��ʦ��¼!\n", ' ');
					system("pause");
					return 3;
				}
			}
			printf("�˺��������!\n");
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