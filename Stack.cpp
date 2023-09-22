#include <iostream>
using namespace std;
const int MAX = 50;
void init(int a[], int& sp);
int Push(int a[], int& sp, int x);
int Pop(int a[], int& sp, int& x);
int isEmpty(int a[], int sp);
int isFull(int a[], int sp);
int changeDecToBin(int a[], int& sp, int x);
void outPut(int a[], int sp);
int main()
{
	int a[MAX], sp, x, in = 0, temp;
	do
	{
		system("cls");
		cout << "\n\t\t\t\t\t\t\tMENU\n"
			<< "\n\t\t\t\t1. Khoi tao stack\n"
			<< "\n\t\t\t\t2. Them mot phan tu vao stack\n"
			<< "\n\t\t\t\t3. Lay mot phan tu ra khoi danh sach\n"
			<< "\n\t\t\t\t4. Kiem tra danh sach rong\n"
			<< "\n\t\t\t\t5. Kiem tra danh sach day\n"
			<< "\n\t\t\t\t6. Xuat stack tu dinh\n"
			<< "\n\t\t\t\t7. Chuyen doi nhap phan sang nhi phan\n"
			<< "\n\t\t\t\t8. Thoat\n";
		cout << "\nBan chon: ";
		int chon;
		cin >> chon;
		switch (chon)
		{
		case 1:
			init(a, sp);
			in = 1;
			cout << "\n\t\t\t\t\tKHOI TAO THANH CONG\n";
			break;
		case 2:
			if (in)
			{
				cout << "\nNhap phan tu muon them: ";
				cin >> x;
				if (!Push(a, sp, x))
					cout << "\n\t\t\t\tTHEM KHONG THANH CONG\n";
				else
					cout << "\n\t\t\t\tTHEM THANH CONG\n";
			}
			else
				cout << "\n\t\t\t\tCHUA KHOI TAO DANH SACH\n";
			break;
		case 3:
			if (in)
			{
				if (!Pop(a, sp, x))
					cout << "\n\t\t\t\tLAY KHONG THANH CONG\n";
				else
					cout << "\nPhan tu vua duoc lay ra la: " << x << endl;
			}
			else
				cout << "\n\t\t\t\tCHUA KHOI TAO DANH SACH\n";
			break;
		case 4:
			if (in)
			{
				if (!isEmpty(a, sp))
					cout << "\n\t\t\t\tDANH SACH KHONG RONG\n";
				else
					cout << "\n\t\t\t\tDANH SACH RONG\n";
			}
			else
				cout << "\n\t\t\t\tCHUA KHOI TAO DANH SACH\n";
			break;
		case 5:
			if (in)
			{
				if (!isFull(a, sp))
					cout << "\n\t\t\t\tDANH SACH CHUA DAY\n";
				else
					cout << "\n\t\t\t\tDANH SACH DAY\n";
			}
			else
				cout << "\n\t\t\t\tCHUA KHOI TAO DANH SACH\n";
			break;
		case 6:
			if (in)
			{
				cout << "\n\t\t\t\tDANH SACH DANG LUU TRU\n";
				outPut(a, sp);
			}
			else
				cout << "\n\t\t\t\tCHUA KHOI TAO DANH SACH\n";
			break;
		case 7:
			cout << "\nNhap so muon chuyen: ";
			cin >> x;
			temp = changeDecToBin(a, sp, x);
			if (temp == INT_MIN)
				cout << "\n\t\t\t\tCHUYEN KHONG THANH CONG\n";
			else
				cout << "\nHE BIN CUA " << x << " LA: " << temp << endl;
			break;
		case 8:
			cout << "\n\t\t\t\tCAM ON DA SU DUNG. HEN GAP LAI.";
			return 0;
		}
		system("pause");
		//return 0;
	} while (1);
}
void init(int a[], int& sp)
{
	sp = -1;
}
int Push(int a[], int& sp, int x)
{
	if (sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
int Pop(int a[], int& sp, int& x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
int isEmpty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}
int isFull(int a[], int sp)
{
	if (sp == MAX - 1)
		return 1;
	return 0;
}
int changeDecToBin(int a[], int& sp, int x)
{
	init(a, sp);
	while (x != 0)
	{
		if (!Push(a, sp, x % 2))
			return INT_MIN;
		x = x / 2;
	}
	int np = 0;
	int so;
	while (sp != -1)
	{
		if (!Pop(a, sp, so))
			return INT_MIN;
		np = np * 10 + so;
	}
	return np;
}
void outPut(int a[], int sp)
{
	for (int i = sp; i >= 0; i--)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}