#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include <conio.h>
#include<windows.h>
#include <vector>
#include <string>

using namespace std;

class User
{
public:
	User(){};
	User(char *name, char *passwd, bool flag)
	{
		this->name = name;
		this->passwd = passwd;
		this->flag = flag;
	}
	string name;
	string passwd;
	bool flag;//0-�û�  ����Ա-1		
};

vector<User > user;

class livers//livers��
{ 
public:
char name[20];//����
	char sex;
	char room_num[10];
	char parking[10];
char ID_num[20];
	char phone_num[20];
public:
	livers() {}
livers(char n[20],char s,char room[10],char park[10],char phone[20],char ID[20])
{
strcpy(name,n);
   sex = s;
   strcpy(room_num,room);
   strcpy(parking,park);
   strcpy(phone_num,phone);
   strcpy(ID_num,ID);
}
friend void menu();//��Ԫ����
};

class name:public livers
{
public:
	name() {};
	void key();
	void menu();
};

void name:: key()
{
start:
	char mima[20], key[20]; char yu_mima[20] = "12345";
	int flag=0; int p; char w; int i = 0;
	ifstream in;
	char str[20] = { '\0' };
	ofstream out;
	fstream f;//�����������
	
	do {
	
		flag = 0;
		string a;
		char ch;

		in.clear();
		in.open("������.dat", ios::in);

		
		if (in.fail())//�״ε�¼
		{
			
			cout << endl << "��ӭ�״ε�¼������Ԥ������Ϊ12345:" << endl << endl;
			cout << "������:";
			cin >> mima;
			cout << endl;
			if (strcmp(yu_mima, mima) == 0)
			{
				flag = 1;
				cout << "������ȷ!��������һ��ָ��:" << endl << endl;
			}
		}
		

		if (!in.fail())//���״ε�½
		{
			
			in >> key;
			while (1)
			{
				ch = '0';
				if (kbhit())
				{
					ch = getch();
					if (ch == 8 && i>0)
					{
						mima[i - 1] = '\0';
						str[i - 1] = '\0';
						i--;
						continue;
					}
					if (ch == 13&&i>0&&i<19)
					{
						mima[i] = '\0';
						break;
					}
					if (ch != 32 && ch != 13 && i < 19)
					{
						mima[i] = ch;
						str[i] = '*';
						ch = '0';
						i++;
					}
				}
				system("cls");//���
				cout << "******************************************" << endl;
				cout << "��ӭ��¼С����ҵ����ϵͳ" << endl;
				cout << "******************************************" << endl << endl;
				cout << "���������Ա��Կ:" << endl;
				for (int k = 0; k<i; k++)
				{
					cout << str[k];
				}
				Sleep(50);
			}
			if (strcmp(key, mima) == 0)
			{
				flag = 1;
				cout << "������ȷ!��������һ��ָ��:" << endl << endl;
			}
			else
			{
				cout <<endl<< "�����������������..." << endl;
				system("pause");
				goto start;
			}
		}
		in.close();
		if (flag == 0)
			cout << "������������������" << endl << endl;
	} while (flag == 0);
	cout << "         *******         " << endl;
	cout << "*************************" << endl;
	cout << "**0���޸�����*" << endl;
	cout << "**1������ϵͳ*" << endl;
	cout << "**2���˳�ϵͳ*" << endl;
	cout << "*************************" << endl;
	cout << "         *******         " << endl;
	do {
		do
		{
			cout << "����������ָ��(0~2):" << endl;
			cin >> p;
			switch (p)
			{
			case 0://�޸�����
				{
				cout << "������������:" << endl;
				cin >> key;
				out.open("������.dat", ios::out);
				out.clear();
				out << key;
				out.close(); }break;
			case 1:menu(); break;//����ϵͳ
			case 2://�˳�ϵͳ
			{cout << "ллʹ�ã�С����ҵ����ϵͳ!" << endl << endl << "Bye-bye!Seeyounexttime!" << endl << endl;
			exit(0); }break;
			default:cout << "����ָ����������������:" << endl << endl; break;
			}
		} while (p < 0 || p>2);
		cout << "���������������������y/n:" << endl << "";
		do {
			cin >> w;
			cout << endl;
			if (w == 'n')exit(0);
			if (w != 'y' && w != 'n')
				cout << "ָ��������������룡" << endl;
		} while (flag == 0);
		if (w == 'y')
		{
			cout << "�������������:0�޸�����" << endl;
			cout << "1����ϵͳ" << endl;
			cout << "2�˳�ϵͳ" << endl;
		}
	} while (w == 'y');
}

//��Կ����
void name::menu()
{
	cout << "******************************************" << endl;
	cout << "С����ҵ����ϵͳ" << endl;
	cout << "******************************************" << endl;
	cout << "**************************" << endl;
	cout << "*���˵�����������ʾ��*" << endl;
	cout << "*1����������*" << endl;
	cout << "*2����������*" << endl;
	cout << "*3���޸�����*" << endl;
	cout << "*4����Ϣ��ѯ*" << endl;
	cout << "*5����Ϣ���*" << endl;
	cout << "*6����Ϣɾ��*" << endl;
	cout << "*7���˳�ϵͳ*" << endl;
	cout << "**************************" << endl;
	cout << "����������ָ�����֣�1~7��" << endl << "";
	char p; char w;
	livers liv[50];
	livers* s[50];
	ifstream in;
	ofstream out;
	fstream f;//�����������
	int i = 0;
	int j = 0;
	int flag = 0;
	do//flag�ж������Ƿ���Ч
	{
		cin >> p;
		if (p >= '1' && p <= '7')
			flag = 1;
		else
			cout << "ָ��������������룺" << endl;
	} while (flag == 0);
	do {//�����ѭ��
		switch (p)//���չ���ѡ��
		{
		case'1'://��Ϣ����
		{char name[20], sex, room_num[10], parking[10], phone_num[20], ID_num[20], c;
		out.open("����.dat", ios::out);
		do {
			cout << "������ס������:";
			cin >> name;
			cout << endl << "������ס���Ա�:";
			cin >> sex;
			cout << endl << "�������䷿���:";
			cin >> room_num;
			cout << endl << "�������䳵���:";
			cin >> parking;
			cout << endl << "��������ϵ�绰:";
			cin >> phone_num;
			cout << endl << "���������֤��:";
			cin >> ID_num;
			cout << endl;
			out << setw(20) << name << setw(5) << sex << setw(10) << room_num << setw(10) << parking << setw(20) << phone_num << setw(20) << ID_num;//�ļ�����
			cout << "��������ɹ��������������y/n:" << endl << "";
			cin >> c;
			cout << endl;
			do
			{
				if (c != 'y' && c != 'n')
				{
					cout << "ָ��������������룡" << endl << "";
					char c;
					cin >> c;
				}
				else flag = 1;
			} while (flag == 0);
		} while (c == 'y');
		out.close();
		break;
		}
		case '2'://��������
		{char name[20], sex, room_num[10], parking[10], phone_num[20], ID_num[20], c;
		out.open("����.dat", ios::app);
		do
		{
			cout << "��������Ҫ���ӵ�ס��������:" << endl;
			cin >> name;
			cout << endl << "������ס���Ա�:";
			cin >> sex;
			cout << endl << "�������䷿���:";
			cin >> room_num;
			cout << endl << "�������䳵���:";
			cin >> parking;
			cout << endl << "��������ϵ�绰:";
			cin >> phone_num;
			cout << endl << "���������֤��:";
			cin >> ID_num;
			cout << endl;
			out << setw(20) << name << setw(5) << sex << setw(10) << room_num << setw(10) << parking << setw(20) << phone_num << setw(20) << ID_num;//�ļ�����
			cout << "������ӳɹ�������������y/n:" << endl;
			cin >> c;
			cout << endl;
			if (c == 'n')break;
			if (c != 'y' && c != 'n')
			{
				cout << "ָ��������������룡" << endl << "";
				cin >> c;
			}
		} while (c == 'y');
		out.close();
		break;
		}
		case'3'://�޸�����
		{char name[20], sex, room_num[10], parking[10], phone_num[20], ID_num[20], c;
		char na[20], s, room[10], park[10], phone[20], ID[20];
		do
		{
			int flag = 0;
			cout << "��������Ҫ�޸ĵ�ס��������:" << endl;
			cin >> na;
			cout << endl;
			f.open("����.dat", ios::in | ios::out);
			f.seekg(0, ios::beg);
			f.clear();
			while (!f.eof())
			{
				f >> name;
				if (strcmp(name, na) == 0)
				{
					flag = 1;
					cout << "��������Ҫ�޸ĵ�ס��������:" << endl;
					cin >> na;
					cout << "�������·����:";
					cin >> room;
					cout << endl << "������ס���Ա�:";
					cin >> s;
					cout << endl << "�������䷿���:";
					cin >> room;
					cout << endl << "�������䳵���:";
					cin >> park;
					cout << endl << "��������ϵ�绰:";
					cin >> phone;
					cout << endl << "���������֤��:";
					cin >> ID;
					cout << endl;
					sex = s;
					strcpy(room_num, room);
					strcpy(parking, park);
					strcpy(ID_num, ID);
					strcpy(phone_num, phone);
					f.seekp(-20l, ios::cur);
					f << setw(20) << na << setw(5) << s << setw(10) << room << setw(10) << park << setw(20) << phone << setw(20) << ID;//�ļ�����
					cout << "�޸ĳɹ�!" << endl << endl; break;
				}
			}
			f.close();
			if (flag == 0)
				cout << "��Ҫ�޸ĵ�ס�������ڣ�" << endl << endl;
			cout << "��������޸���y/n:" << endl;
			cin >> c;
			cout << endl;
			if (c == 'n')break;
			if (c != 'y' && c != 'n')
			{
				cout << "ָ��������������룡" << endl << "";
				cin >> c;
			}
		} while (c == 'y');
		break;
		}
		case'4'://��Ϣ��ѯ
		{char name[20], sex, room_num[10], room[10], parking[10], phone_num[20], ID_num[20];
		cout << "��ѡ����Ҫ���в�ѯ�ķ�ʽ��" << endl << endl << "1.��ס������ѯ" << endl << endl << "2.������Ų�ѯ" << endl << endl;
		int k;
		cin >> k;
		switch (k)
			case 1://��ס������ѯ
		{char na[20]; char c;
		do {
			in.open("����.dat", ios::in);
			in.seekg(0, ios::beg);
			in.clear();
			int flag = 0;
			cout << "��������Ҫ��ѯ��ס������:" << endl;
			cin >> na;
			cout << endl;
			while (!in.eof())
			{
				in >> name >> sex >> room_num >> parking >> phone_num >> ID_num;
				if (strcmp(name, na) == 0)
				{
					flag = 1;
					cout << "��Ҫ��ѯ��ס��:" << name << "����Ϣ��:" << endl << endl;
					cout << "����--�Ա�-----���ƺ�----�����----------�绰����----------���֤��"  << endl;
					cout << setw(2) << name << setw(5) << sex << setw(10) << room_num << setw(10) << parking << setw(20) << phone_num << setw(20) << ID_num << endl;
				}
			}
			in.close();
			if (flag == 0)
				cout << "�Բ���!��Ҫ��ѯ��ס��������!" << endl << endl;
			cout << "���������ѯ��y/n:";
			cin >> c;
			cout << endl;
			if (c == 'n')break;
			if (c != 'y' && c != 'n')
			{
				cout << "ָ��������������룡" << endl;
				cin >> c;
			}
		} while (c == 'y');
		break;
	case 2://������Ų�ѯ
		{
			do {
				int flag = 0;
				cout << "��������Ҫ��ѯ�ķ����:" << endl;
				cin >> room;
				cout << endl;
				in.open("����.dat", ios::in);
				in.seekg(0, ios::beg);
				in.clear();
				while (!in.eof())
				{
					in >> name >> sex >> room_num >> parking >> phone_num >> ID_num;
					if (strcmp(room_num, room) == 0)
					{
						flag = 1;
						cout << "��Ҫ��ѯ��ס��:" << name << "����Ϣ��:" << endl << endl;
						cout << "����--�Ա�-----���ƺ�----�����----------�绰����----------���֤��"  << endl;
						cout << setw(2) << name << setw(5) << sex << setw(10) << room_num << setw(10) << parking << setw(20) << phone_num << setw(20) << ID_num << endl;
					}
				}
				in.close();
				if (flag == 0)
					cout << "�Բ���!��Ҫ��ѯ��ס��������!" << endl;
				cout << "���������ѯ��y/n:";
				char c;
				cin >> c;
				cout << endl;
				if (c == 'n')break;
				if (c != 'y' && c != 'n')
				{
					cout << "ָ��������������룡" << endl;
					cin >> c;
				}
			} while (c == 'y');
			break;
		default:cout << "�Բ����������ָ������"; }break;
		}break;
		case'5'://��Ϣ���
		{char name[20], sex, room_num[10], parking[10], phone_num[20], ID_num[20];
		in.open("����.dat", ios::in);
		in.seekg(0, ios::beg);
		in.clear();
		if (in.get() == EOF) { cout << "�ļ�����������" << endl << endl; in.close(); break; }
		cout << "��ϵͳ����ס���������£�" << endl << endl;
		cout << "����--�Ա�-----���ƺ�----�����----------�绰����----------���֤��" << endl;
		while (!in.eof())
		{
			in >> name >> sex >> room_num >> parking >> phone_num >> ID_num;
			cout << setw(2) << name << setw(5) << sex << setw(10) << room_num << setw(10) << parking << setw(20) << phone_num << setw(20) << ID_num << endl;
		}
		in.close();
		break;
		}
		case'6'://��Ϣɾ��
		{char name[20], na[20], sex, room_num[10], parking[10], phone_num[20], ID_num[20], c;
		int k;
		do
		{
			int n = 0; int flag = 0;
			cout << "��������Ҫɾ����ס��������:" << endl;
			cin >> na;
			cout << endl;
			in.clear();
			in.open("����.dat", ios::in);
			in.seekg(0, ios::beg);
			while (!in.eof())
			{
				in >> name >> sex >> room_num >> parking >> phone_num >> ID_num;
				s[n] = new livers(name, sex, room_num, parking, phone_num, ID_num);
				liv[n] = *s[n];
				delete s[n];
				n++;
			}
			in.close();
			for (i = 0; i < n; i++)
			{
				if (strcmp(liv[i].name, na) == 0)
				{
					flag = 1; k = i;
				}
			}
			if (flag == 1)
			{
				out.open("����.dat", ios::out);
				out.seekp(0, ios::beg);
				if (n > 1)
				{
					for (i = 0; i < k; i++)
						out << setw(2) << liv[i].name << setw(5) << liv[i].sex << setw(10) << liv[i].room_num << setw(10) << liv[i].parking << setw(20) << liv[i].phone_num << setw(20) << liv[i].ID_num;
					for (i = k + 1; i < n; i++)
						out << setw(2) << liv[i].name << setw(5) << liv[i].sex << setw(10) << liv[i].room_num << setw(10) << liv[i].parking << setw(20) << liv[i].phone_num << setw(20) << liv[i].ID_num;
					cout << "��Ϣɾ���ɹ�" << endl << endl;
				}
				if (n = 1) {}
				out.close();
			}
			else
				cout << "��Ҫɾ����ס�������ڣ�" << endl << endl;
			cout << "�������ɾ����y/n:" << endl;
			cin >> c;
			cout << endl;
			if (c == 'n')break;
			if (c != 'y' && c != 'n')
			{
				cout << "ָ��������������룡" << endl << "";
				cin >> c;
			}
		} while (c == 'y');
		break;
		}
		case'7'://�˳�
		{cout << "Byebye!See*you*next*time." << endl << endl;
		cout << "biubiu~" << endl << endl << endl; exit(0); }break; }
		}//����Ϊmenu�˵���switch�������
		cout << "���������������������y/n:" << endl << "";//���¿���ѭ�����
		int flag = 0;
		do {
			cin >> w;
			cout << endl;
			if (w == 'n')exit(0);
			if (w != 'y' && w != 'n')
				cout << "ָ��������������룡" << endl;
			else
				flag = 1;
		} while (flag == 0);
		if (w == 'y')
		{
			cout << "�������������:1��������" << endl;
			cout << "2��������" << endl;
			cout << "3�޸�����" << endl;
			cout << "4��Ϣ��ѯ" << endl;
			cout << "5��Ϣ���" << endl;
			cout << "6��Ϣɾ��" << endl;
			cout << "7�˳�ϵͳ" << endl;
		}
		cin >> p;
	} while (w == 'y');//������do-whileѭ��
}//menu��������
int main()
{
	char m_name[20], passwd[7];
	bool flag;
	name n;
	int chose;
	
	
	FILE * fp = fopen ("1.txt", "r");
	if(fp != NULL)
	{
		while(!feof(fp))
		{
			memset(m_name, 0, sizeof(m_name));
			memset(passwd, 0, sizeof(passwd));		
			fscanf(fp, "%s %s %d", m_name, passwd, &flag);		
			if(string(passwd).empty() || string(m_name).empty()) continue;
			user.push_back(User(m_name, passwd, flag));
			cout << m_name << "  " << passwd << "  " << flag << endl;
		}	
		fclose(fp);
	}
	
	while(1)
	{
		cout << "*****************" << endl;
		cout << "* 1���û�ע��   *" << endl;
		cout << "* 2���û���¼   *" << endl;
		cout << "* 3������Ա��½ *" << endl;
		cout << "*****************" << endl;
		
		cin >> chose;
		switch(chose)
		{
			
		}
		
	}
	
	
	
	n.key();
	return 0;
}