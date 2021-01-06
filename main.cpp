#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include <conio.h>
#include<windows.h>
#include <vector>
#include <string>
#include <stdio.h>

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
	bool flag;//0-用户  管理员-1		
};

vector<User > user;

class livers//livers类
{ 
public:
char name[20];//姓名
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
friend void menu();//友元函数
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
	fstream f;//输入输出对象
	
	do {
	
		flag = 0;
		string a;
		char ch;

		in.clear();
		in.open("啦啦啦.dat", ios::in);

		
		if (in.fail())//首次登录
		{
			
			cout << endl << "欢迎首次登录，您的预设密码为12345:" << endl << endl;
			cout << "请输入:";
			cin >> mima;
			cout << endl;
			if (strcmp(yu_mima, mima) == 0)
			{
				flag = 1;
				cout << "密码正确!请输入下一步指令:" << endl << endl;
			}
		}
		

		if (!in.fail())//非首次登陆
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
				system("cls");//清空
				cout << "******************************************" << endl;
				cout << "欢迎登录小区物业管理系统" << endl;
				cout << "******************************************" << endl << endl;
				cout << "请输入管理员密钥:" << endl;
				for (int k = 0; k<i; k++)
				{
					cout << str[k];
				}
				Sleep(50);
			}
			if (strcmp(key, mima) == 0)
			{
				flag = 1;
				cout << "密码正确!请输入下一步指令:" << endl << endl;
			}
			else
			{
				cout <<endl<< "密码错误，请重新输入..." << endl;
				system("pause");
				goto start;
			}
		}
		in.close();
		if (flag == 0)
			cout << "密码有误，请重新输入" << endl << endl;
	} while (flag == 0);
	cout << "         *******         " << endl;
	cout << "*************************" << endl;
	cout << "**0、修改密码*" << endl;
	cout << "**1、进入系统*" << endl;
	cout << "**2、退出系统*" << endl;
	cout << "*************************" << endl;
	cout << "         *******         " << endl;
	do {
		do
		{
			cout << "请输入您的指令(0~2):" << endl;
			cin >> p;
			switch (p)
			{
			case 0://修改密码
				{
				cout << "请输入新密码:" << endl;
				cin >> key;
				out.open("啦啦啦.dat", ios::out);
				out.clear();
				out << key;
				out.close(); }break;
			case 1:menu(); break;//进入系统
			case 2://退出系统
			{cout << "谢谢使用，小区物业管理系统!" << endl << endl << "Bye-bye!Seeyounexttime!" << endl << endl;
			exit(0); }break;
			default:cout << "输入指令有误，请重新输入:" << endl << endl; break;
			}
		} while (p < 0 || p>2);
		cout << "您想继续进行其他操作吗？y/n:" << endl << "";
		do {
			cin >> w;
			cout << endl;
			if (w == 'n')exit(0);
			if (w != 'y' && w != 'n')
				cout << "指令错误！请重新输入！" << endl;
		} while (flag == 0);
		if (w == 'y')
		{
			cout << "请输入操作代码:0修改密码" << endl;
			cout << "1进入系统" << endl;
			cout << "2退出系统" << endl;
		}
	} while (w == 'y');
}

//密钥函数
void name::menu()
{
	cout << "******************************************" << endl;
	cout << "小区物业管理系统" << endl;
	cout << "******************************************" << endl;
	cout << "**************************" << endl;
	cout << "*主菜单命令如下所示：*" << endl;
	cout << "*1、输入数据*" << endl;
	cout << "*2、增加数据*" << endl;
	cout << "*3、修改数据*" << endl;
	cout << "*4、信息查询*" << endl;
	cout << "*5、信息浏览*" << endl;
	cout << "*6、信息删除*" << endl;
	cout << "*7、退出系统*" << endl;
	cout << "**************************" << endl;
	cout << "请输入您的指令数字（1~7）" << endl << "";
	char p; char w;
	livers liv[50];
	livers* s[50];
	ifstream in;
	ofstream out;
	fstream f;//输入输出对象
	int i = 0;
	int j = 0;
	int flag = 0;
	do//flag判断输入是否有效
	{
		cin >> p;
		if (p >= '1' && p <= '7')
			flag = 1;
		else
			cout << "指令错误！请重新输入：" << endl;
	} while (flag == 0);
	do {//最外层循环
		switch (p)//接收功能选项
		{
		case'1'://信息输入
		{char name[20], sex, room_num[10], parking[10], phone_num[20], ID_num[20], c;
		out.open("数据.dat", ios::out);
		do {
			cout << "请输入住户姓名:";
			cin >> name;
			cout << endl << "请输入住户性别:";
			cin >> sex;
			cout << endl << "请输入其房间号:";
			cin >> room_num;
			cout << endl << "请输入其车库号:";
			cin >> parking;
			cout << endl << "请输入联系电话:";
			cin >> phone_num;
			cout << endl << "请输入身份证号:";
			cin >> ID_num;
			cout << endl;
			out << setw(20) << name << setw(5) << sex << setw(10) << room_num << setw(10) << parking << setw(20) << phone_num << setw(20) << ID_num;//文件输入
			cout << "数据输入成功，想继续输入吗？y/n:" << endl << "";
			cin >> c;
			cout << endl;
			do
			{
				if (c != 'y' && c != 'n')
				{
					cout << "指令错误！请重新输入！" << endl << "";
					char c;
					cin >> c;
				}
				else flag = 1;
			} while (flag == 0);
		} while (c == 'y');
		out.close();
		break;
		}
		case '2'://增加数据
		{char name[20], sex, room_num[10], parking[10], phone_num[20], ID_num[20], c;
		out.open("数据.dat", ios::app);
		do
		{
			cout << "请输入您要增加的住户的姓名:" << endl;
			cin >> name;
			cout << endl << "请输入住户性别:";
			cin >> sex;
			cout << endl << "请输入其房间号:";
			cin >> room_num;
			cout << endl << "请输入其车库号:";
			cin >> parking;
			cout << endl << "请输入联系电话:";
			cin >> phone_num;
			cout << endl << "请输入身份证号:";
			cin >> ID_num;
			cout << endl;
			out << setw(20) << name << setw(5) << sex << setw(10) << room_num << setw(10) << parking << setw(20) << phone_num << setw(20) << ID_num;//文件输入
			cout << "数据添加成功，想继续添加吗？y/n:" << endl;
			cin >> c;
			cout << endl;
			if (c == 'n')break;
			if (c != 'y' && c != 'n')
			{
				cout << "指令错误！请重新输入！" << endl << "";
				cin >> c;
			}
		} while (c == 'y');
		out.close();
		break;
		}
		case'3'://修改数据
		{char name[20], sex, room_num[10], parking[10], phone_num[20], ID_num[20], c;
		char na[20], s, room[10], park[10], phone[20], ID[20];
		do
		{
			int flag = 0;
			cout << "请输入您要修改的住户的姓名:" << endl;
			cin >> na;
			cout << endl;
			f.open("数据.dat", ios::in | ios::out);
			f.seekg(0, ios::beg);
			f.clear();
			while (!f.eof())
			{
				f >> name;
				if (strcmp(name, na) == 0)
				{
					flag = 1;
					cout << "请输入您要修改的住户的姓名:" << endl;
					cin >> na;
					cout << "请输入新房间号:";
					cin >> room;
					cout << endl << "请输入住户性别:";
					cin >> s;
					cout << endl << "请输入其房间号:";
					cin >> room;
					cout << endl << "请输入其车库号:";
					cin >> park;
					cout << endl << "请输入联系电话:";
					cin >> phone;
					cout << endl << "请输入身份证号:";
					cin >> ID;
					cout << endl;
					sex = s;
					strcpy(room_num, room);
					strcpy(parking, park);
					strcpy(ID_num, ID);
					strcpy(phone_num, phone);
					f.seekp(-20l, ios::cur);
					f << setw(20) << na << setw(5) << s << setw(10) << room << setw(10) << park << setw(20) << phone << setw(20) << ID;//文件输入
					cout << "修改成功!" << endl << endl; break;
				}
			}
			f.close();
			if (flag == 0)
				cout << "您要修改的住户不存在！" << endl << endl;
			cout << "您想继续修改吗？y/n:" << endl;
			cin >> c;
			cout << endl;
			if (c == 'n')break;
			if (c != 'y' && c != 'n')
			{
				cout << "指令错误！请重新输入！" << endl << "";
				cin >> c;
			}
		} while (c == 'y');
		break;
		}
		case'4'://信息查询
        {
            char name[20], sex, room_num[10], room[10], parking[10], phone_num[20], ID_num[20];
		cout << "请选择您要进行查询的方式：" << endl << endl << "1.按住户名查询" << endl << endl << "2.按房间号查询" << endl << endl;
		int k;
		cin >> k;
		switch (k)
			case 1://按住户名查询
		{char na[20]; char c;
		do {
			in.open("数据.dat", ios::in);
			in.seekg(0, ios::beg);
			in.clear();
			int flag = 0;
			cout << "请输入你要查询的住户姓名:" << endl;
			cin >> na;
			cout << endl;
			while (!in.eof())
			{
				in >> name >> sex >> room_num >> parking >> phone_num >> ID_num;
				if (strcmp(name, na) == 0)
				{
					flag = 1;
					cout << "您要查询的住户:" << name << "的信息是:" << endl << endl;
					cout << "姓名--性别-----门牌号----车库号----------电话号码----------身份证号"  << endl;
					cout << setw(2) << name << setw(5) << sex << setw(10) << room_num << setw(10) << parking << setw(20) << phone_num << setw(20) << ID_num << endl;
				}
			}
			in.close();
			if (flag == 0)
				cout << "对不起!您要查询的住户不存在!" << endl << endl;
			cout << "您想继续查询吗？y/n:";
			cin >> c;
			cout << endl;
			if (c == 'n')break;
			if (c != 'y' && c != 'n')
			{
				cout << "指令错误！请重新输入！" << endl;
				cin >> c;
			}
		} while (c == 'y');
		break;
	case 2://按房间号查询
		{
			do {
				int flag = 0;
				cout << "请输入你要查询的房间号:" << endl;
				cin >> room;
				cout << endl;
				in.open("数据.dat", ios::in);
				in.seekg(0, ios::beg);
				in.clear();
				while (!in.eof())
				{
					in >> name >> sex >> room_num >> parking >> phone_num >> ID_num;
					if (strcmp(room_num, room) == 0)
					{
						flag = 1;
						cout << "您要查询的住户:" << name << "的信息是:" << endl << endl;
						cout << "姓名--性别-----门牌号----车库号----------电话号码----------身份证号"  << endl;
						cout << setw(2) << name << setw(5) << sex << setw(10) << room_num << setw(10) << parking << setw(20) << phone_num << setw(20) << ID_num << endl;
					}
				}
				in.close();
				if (flag == 0)
					cout << "对不起!您要查询的住户不存在!" << endl;
				cout << "您想继续查询吗？y/n:";
				char c;
				cin >> c;
				cout << endl;
				if (c == 'n')break;
				if (c != 'y' && c != 'n')
				{
					cout << "指令错误！请重新输入！" << endl;
					cin >> c;
				}
			} while (c == 'y');
			break;
		default:cout << "对不起，您输入的指令有误："; }break;
		}break;
		case'5'://信息浏览
		{char name[20], sex, room_num[10], parking[10], phone_num[20], ID_num[20];
		in.open("数据.dat", ios::in);
		in.seekg(0, ios::beg);
		in.clear();
		if (in.get() == EOF) { cout << "文件中已无数据" << endl << endl; in.close(); break; }
		cout << "本系统所有住户数据如下：" << endl << endl;
		cout << "姓名--性别-----门牌号----车库号----------电话号码----------身份证号" << endl;
		while (!in.eof())
		{
			in >> name >> sex >> room_num >> parking >> phone_num >> ID_num;
			cout << setw(2) << name << setw(5) << sex << setw(10) << room_num << setw(10) << parking << setw(20) << phone_num << setw(20) << ID_num << endl;
		}
		in.close();
		break;
		}
		case'6'://信息删除
		{char name[20], na[20], sex, room_num[10], parking[10], phone_num[20], ID_num[20], c;
		int k;
		do
		{
			int n = 0; int flag = 0;
			cout << "请输入您要删除的住户的姓名:" << endl;
			cin >> na;
			cout << endl;
			in.clear();
			in.open("数据.dat", ios::in);
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
				out.open("数据.dat", ios::out);
				out.seekp(0, ios::beg);
				if (n > 1)
				{
					for (i = 0; i < k; i++)
						out << setw(2) << liv[i].name << setw(5) << liv[i].sex << setw(10) << liv[i].room_num << setw(10) << liv[i].parking << setw(20) << liv[i].phone_num << setw(20) << liv[i].ID_num;
					for (i = k + 1; i < n; i++)
						out << setw(2) << liv[i].name << setw(5) << liv[i].sex << setw(10) << liv[i].room_num << setw(10) << liv[i].parking << setw(20) << liv[i].phone_num << setw(20) << liv[i].ID_num;
					cout << "信息删除成功" << endl << endl;
				}
				if (n = 1) {}
				out.close();
			}
			else
				cout << "您要删除的住户不存在！" << endl << endl;
			cout << "您想继续删除吗？y/n:" << endl;
			cin >> c;
			cout << endl;
			if (c == 'n')break;
			if (c != 'y' && c != 'n')
			{
				cout << "指令错误！请重新输入！" << endl << "";
				cin >> c;
			}
		} while (c == 'y');
		break;
		}
		case'7'://退出
		{cout << "Byebye!See*you*next*time." << endl << endl;
		cout << "biubiu~" << endl << endl << endl; exit(0); }break; }
		}//以上为menu菜单中switch控制语句
		cout << "您想继续进行其他操作吗？y/n:" << endl << "";//以下控制循环语句
		int flag = 0;
		do {
			cin >> w;
			cout << endl;
			if (w == 'n')exit(0);
			if (w != 'y' && w != 'n')
				cout << "指令错误！请重新输入！" << endl;
			else
				flag = 1;
		} while (flag == 0);
		if (w == 'y')
		{
			cout << "请输入操作代码:1输入数据" << endl;
			cout << "2增加数据" << endl;
			cout << "3修改数据" << endl;
			cout << "4信息查询" << endl;
			cout << "5信息浏览" << endl;
			cout << "6信息删除" << endl;
			cout << "7退出系统" << endl;
		}
		cin >> p;
	} while (w == 'y');//最外层的do-while循环
}//menu函数结束
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
		cout << "* 1、用户注册   *" << endl;
		cout << "* 2、用户登录   *" << endl;
		cout << "* 3、管理员登陆 *" << endl;
		cout << "*****************" << endl;
		
		memset(m_name, 0, sizeof(m_name));
		memset(passwd, 0, sizeof(passwd));
		
		cin >> chose;
		switch(chose)
		{
			case 1:
			{
				cout << "name:";
				cin >> m_name;
                cout  << "6位密码:";
				for(int i=0; i<6; i++)
				{
                    passwd[i] = getch();
					printf("*");
				}
                cin.ignore();

				cout << endl;

                user.push_back(User(m_name, passwd, 0));
				break;
			}
            case 2:
            {
                cout << "name:";
                cin >> m_name;
                cout  << "6位密码:";
                for(int i=0; i<6; i++)
                {
                    passwd[i] = getch();
                    printf("*");
                }
                cin.ignore();
                cout << endl;

                for(int i=0; i<user.size(); i++)
                {
                    if(m_name == user.at(i).name && passwd == user.at(i).passwd && user.at(i).flag==0)
                    {
                        cout << "login success" << endl;

                    }
                    cout << "login fail" << endl;
                }
                break;
            }
            case 3:
            {
                n.key();
                return 0;
            }
		}
		
	}

	return 0;
}
