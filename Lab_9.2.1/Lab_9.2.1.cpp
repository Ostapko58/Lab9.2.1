#include<iostream>
#include<windows.h>
#include<iomanip>
#include<string>
using namespace std;


enum Specialnists
{
	computer_science,
	informatics,
	math_a_economics,
	physics_and_informatics,
	labor_education
};

struct Student
{
	string prizv;
	int kyrs;
	Specialnists specialst;
	int math_grade;
	int physics_grade;
	union
	{
		int programing_grade;
		int chisel_metod_grade;
		int pedagogic_grade;
	};

};



void Create(Student* stud, const int N)
{
	int specialst;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get(); cin.sync();
		cout << " �������: "; getline(cin, stud[i].prizv);
		do
		{
			if (stud[i].prizv.find_first_of("0 123456789", 0) != -1)
			{
				stud[i].prizv.erase(0, -1);
				cout << "�� ����� ������ �������, ���������� �����: " << endl;
				cout << " �������: "; getline(cin, stud[i].prizv);
			}
		} while (stud[i].prizv.find_first_of("0 123456789", 0) != -1);
		/*cout << " �������: "; getline(cin, stud[i].prizv);
		if (stud[i].prizv.find_first_not_of("0 123456789",0)==-1)
		{
			stud[i].prizv.erase(0, -1);
			cout << stud[i].prizv.empty() << endl;
			cout << "�� ����� ������ �������, ���������� �����: " << endl;
		}*/
		cout << " ����: "; cin >> stud[i].kyrs;
		if (cin.fail()||stud[i].kyrs<1||stud[i].kyrs>5)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ������ ����, ���������� �����: " << endl;
				cout << " ����: "; cin >> stud[i].kyrs;
			} while (cin.fail() || stud[i].kyrs < 1 || stud[i].kyrs>5);
		}
		cout << " ������������� (0 - ���������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
		cin >> specialst;
		if (cin.fail()||specialst<0||specialst>4)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ������ �����, ���������� �����: " << endl;
				cout << " �������������(0 - ���������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������) : ";
				cin >> specialst;
			} while (cin.fail() || specialst < 0 || specialst>4);
		}
		stud[i].specialst = (Specialnists)specialst;
		cout << " ������ � ����������: "; cin >> stud[i].math_grade;
		if (cin.fail()||stud[i].math_grade<1||stud[i].math_grade>5)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ������ ����, ���������� �����: " << endl;
				cout << " ������ � ����������: "; cin >> stud[i].math_grade;
			} while (cin.fail() || stud[i].math_grade < 1 || stud[i].math_grade>5);
		}
		cout << " ������ � ������: "; cin >> stud[i].physics_grade;

		if (cin.fail() || stud[i].physics_grade < 1 || stud[i].physics_grade>5)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ������ ����, ���������� �����: " << endl;
				cout << " ������ � ������: "; cin >> stud[i].physics_grade;
			} while (cin.fail() || stud[i].physics_grade < 1 || stud[i].physics_grade>5);
		}

		switch (stud[i].specialst)
		{
		case computer_science:
			cout << " ������ � ������������� : "; cin >> stud[i].programing_grade;
			if (cin.fail() || stud[i].programing_grade < 1 || stud[i].programing_grade>5)
			{
				do
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "�� ����� ������ ����, ���������� �����: " << endl;
					cout << " ������ � ������������� : "; cin >> stud[i].programing_grade;
				} while (cin.fail() || stud[i].programing_grade < 1 || stud[i].programing_grade>5);
			}
			break;
		case informatics:
			cout << " ������ � ��������� ������ : "; cin >> stud[i].chisel_metod_grade;
			if (cin.fail() || stud[i].chisel_metod_grade < 1 || stud[i].chisel_metod_grade>5)
			{
				do
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "�� ����� ������ ����, ���������� �����: " << endl;
					cout << " ������ � ��������� ������ : "; cin >> stud[i].chisel_metod_grade;
				} while (cin.fail() || stud[i].chisel_metod_grade < 1 || stud[i].chisel_metod_grade>5);
			}
			break;
		default:
			cout << " ������ � ��������� ��������� : "; cin >> stud[i].pedagogic_grade;
			if (cin.fail() || stud[i].pedagogic_grade < 1 || stud[i].pedagogic_grade>5)
			{
				do
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "�� ����� ������ ����, ���������� �����: " << endl;
					cout << " ������ � ��������� ��������� : "; cin >> stud[i].pedagogic_grade;
				} while (cin.fail() || stud[i].pedagogic_grade < 1 || stud[i].pedagogic_grade>5);
			}
			break;
		}
		cout << endl;
	}
}

void Print(Student* stud, const int N, string* List)
{
	cout << "======================================================================================================================================================================================="
		<< endl;
	cout << "| � |     �������     | ���� |      �������������      | ������ � ���������� | ������ � ������ | ������ � ������������� | ������ � ��������� ������ | ������ � ��������� ��������� |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(17) << left << stud[i].prizv
			<< "| " << setw(4) << right << stud[i].kyrs << " "
			<< "| " << setw(23) << left << List[stud[i].specialst] << " "
			<< "| " << setw(19) << right << stud[i].math_grade << " "
			<< "| " << setw(15) << right << stud[i].physics_grade << " ";
		switch (stud[i].specialst)
		{
		case computer_science:
			cout << "| " << setw(22) << setprecision(2) << fixed << right
				<< stud[i].programing_grade << " |" << setw(29) << right << " |" << setw(32) << right << " |" << endl;
			break;
		case informatics:
			cout << "| " << setw(24) << setprecision(2) << fixed << right
				<< " |" << setw(27) << right << stud[i].chisel_metod_grade << " |" << setw(32) << right << " |" << endl;
			break;
		default:
			cout << "| " << setw(24) << setprecision(2) << fixed << right
				<< " |" << setw(29) << right << " |" << setw(30) << right << stud[i].pedagogic_grade << " |" << endl;
			break;
		}
	}
	cout << "======================================================================================================================================================================================="
		<< endl;
	cout << endl;
}

void Sort(Student* stud, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((stud[i1].specialst > stud[i1 + 1].specialst)
				||
				(stud[i1].specialst == stud[i1 + 1].specialst &&
					stud[i1].math_grade < stud[i1 + 1].math_grade)
				|| 
				(stud[i1].specialst == stud[i1 + 1].specialst &&
					stud[i1].math_grade == stud[i1 + 1].math_grade&&
					stud[i1].prizv > stud[i1 + 1].prizv))
			{
				tmp = stud[i1];
				stud[i1] = stud[i1 + 1];
				stud[i1 + 1] = tmp;
			}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string List[] = {
	"���������� �����",
	"�����������",
	"���������� �� ��������",
	"Գ���� �� �����������",
	"������� ��������"
	};

	int N;
	cout << "������ N: "; cin >> N;
	if (cin.fail())
	{
		do
		{
			cin.clear();
			cin.ignore(255, '\n');
			cout << "�� ����� ������ ����, ���������� �����: " << endl;
			cout << "������ N: "; cin >> N;
		} while (cin.fail());
	}

	Student* stud = new Student[N];
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - �������������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(stud, N);
			break;
		case 2:
			Print(stud, N, List);
			break;
		case 3:
			Sort(stud, N);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! ������ ����� ��������� ������ ����"<< endl;
		}
	} while (menuItem != 0);

	return 0;
}

