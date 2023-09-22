#include <iostream>
#include <cstdlib>
const int MAXSZ = 100;
using namespace std;
void KhoiTaoMang(int a[], int& n)
{
	cout << "\nNhap so luong phan tu cua mang: ";
	do {
		cin >> n;
		if (n <= 0 || n > 100)
			cout << "\nNhap lai: ";
	} while (n <= 0 || n > 100);
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 26;//rand()%(max - min + 1)+ min
	}
}
void XuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
			cout << "; ";
		cout << a[i];
	}
	cout << endl;
}
void HoanDoi(int& x, int& y)
{
	int tam = x;
	x = y;
	y = tam;
}
//sap xep tang dan theo pp chon lua truc tiep
void selectionSort(int a[], int n)
{
	int min_pos;
	for (int i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min_pos])
				min_pos = j;
		if (min_pos != i)
			HoanDoi(a[i], a[min_pos]);
	}
}
//sap xep tang dan theo pp hoan doi truc tiep
void interchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				HoanDoi(a[i], a[j]);
	}
}
//sap xep tang dan bang pp chen truc tiep
//sap xep tang dan bang pp noi bot
//tim kiem tuan tu tren danh sach da co thu tu
//tim kiem nhi phan tren danh sach da co thu tu
int main()
{
	srand(time(NULL));
	int a[MAXSZ], n, in = 0, chon;
	do {
		system("cls");
		cout << "\n\t============MENU============\n"
			<< "\n\t1. Khoi tao mang.\n"
			<< "\n\t2. Xuat mang.\n"
			<< "\n\t3. Sap xep mang tang dan bang selectionSort.\n"
			<< "\n\t4. Sap xep mang tang dan bang interchangeSort.\n"
			<< "\n\t5. Thoat.\nBan chon: ";
		do {
			cin >> chon;
			if (chon < 1 || chon>5)
				cout << "\nNhap lai: ";
		} while (chon < 1 || chon>5);
		switch (chon)
		{
		case 1:
			KhoiTaoMang(a, n);
			in = 1;
			cout << "\n\t\t\tKHOI TAO MANG THANH CONG\n";
			break;
		case 2:
			if (in)
			{
				cout << "\nMang dang luu tru\n";
				XuatMang(a, n);
			}
			else
				cout << "\n\t\t\tCHUA KHOI TAO MANG\n";
			break;
		case 3:
			if(in)
			{
				selectionSort(a, n);
			}
			else
			cout << "\n\t\t\tCHUA KHOI TAO MANG\n";
			break;
		case 4:
			if(in)
			{
				interchangeSort(a, n);
			}
			else
			cout << "\n\t\t\tCHUA KHOI TAO MANG\n";
			break;
		case 5:
			return 0;
		}
		system("pause");
	} while (1);
	return 0;
}