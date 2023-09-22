#include <iostream>
const int MAX = 100;
using namespace std;
void input_13_Tien_N2_IM_Bai_1(int a[], int& n)
{
	cout << "\nNhao vao so luong phan tu cua danh sach: ";
	cin >> n;
	cout << "\nNhap vao cac phan tu cua danh sach\n";
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}
void output_13_Tien_N2_IM_Bai_1(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
}
void insertion_13_Tien_N2_IM_Bai_1(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int x = a[i];//phan tu muon chen vao doan con
		int pos = i - 1;
		/*Di chyen cac phan tu co gia tri lon hon gia tri key ve sau 1 vi tri
		so voi gia tri ban dau cua no*/
		while (pos >= 0 && a[pos] > x)
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}
void hoanVi_13_Tien_N2_IM_Bai_1(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}
void Selection_13_Tien_N2_IM_Bai_1(int a[], int n)
{
	//Di chuyen ranh gioi cua mang da sap xep va chua sap xep
	for (int k = 0; k < n - 1; k++)
	{
		//tim phan tu nho nhat trong mang chua sap xep
		int vt_min = k;
		for (int i = k + 1; i < n; i++)
			if (a[i] < a[vt_min])
				vt_min = i;
		//doi cho phan tu nho nhat voi phan tu dau tien
		hoanVi_13_Tien_N2_IM_Bai_1(a[vt_min], a[k]);
	}
}
//sap xep bang thuat toan sap xep noi bot
void bubleSort_13_Tien_N2_IM_Bai_1(int a[], int n)
{
	//lap qua mang tu phan tu dau tien den phan tu cuoi
	for (int i = 0; i < n - 1; i++)
	{
		//lap qua mang tu phan tu cuoi den phan tu sau phan tu i
		for (int j = n - 1; j > i; j--)
		{
			//neu phan tu truoc lon hon phan tu sau thi doi cho
			if (a[j - 1] > a[j])
				hoanVi_13_Tien_N2_IM_Bai_1(a[j], a[j - 1]);
		}
	}
}
//sap xep bang thuat toan doi cho truc tiep
void InterchangeSort_13_Tien_N2_IM_Bai_1(int a[], int n)
{
	//lap qua mang tu phan tu dau tien den phan tu gan cuoi
	for (int i = 0; i < n - 1; i++)
	{
		//lap qua mang tu phan tu sau i den phan tu cuoi cung
		for (int j = i + 1; j < n; j++)
			//neu phan tu i lon hon phan tu j thi doi cho
			if (a[i] > a[j])
				hoanVi_13_Tien_N2_IM_Bai_1(a[i], a[j]);
	}
}
//sap xep bang thuat toan sap xep nhanh
void QuickSort_13_Tien_N2_IM_Bai_1(int a[], int left, int right)
{
	//chon phan tu giua mang lam phan tu chot
	int x = a[(left + right) / 2];
	//i va j la chi so cua hai dau mang
	int i = left;
	int j = right;
	//lap den khi i va j bang nhau
	while (i <= j)
	{
		//Tim phan tu ben trai lon hon hoac bang chot
		while (a[i] < x)
			i++;
		//Tim phan tu ben phai nho hon hoac bang chot
		while (a[j] > x)
			j--;
		//Neu i va j chua gap nhau
		if (i <= j)
		{
			//doi cho hai phan tu
			hoanVi_13_Tien_N2_IM_Bai_1(a[i], a[j]);
			i++;//tang i
			j--;//giam j
		}
	}
	//neu phan tu ben trai cua chot con nhieu hon mot phan tu
	if (left < j)
		//goi de qui cho phan con lai
		QuickSort_13_Tien_N2_IM_Bai_1(a, left, j);
	//Neu phan ben phai cua chot con nhieu hon mot phan tu
	if (i < right)
		//goi de qui cho phan con lai
		QuickSort_13_Tien_N2_IM_Bai_1(a, i, right);
}

void shift_13_Tien_N2_IM_Bai_1(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j >= n)//neu vi tri j khong ton tai trong danh sach dang xet thi thoat kho chuong trinh
		return;
	if (j + 1 < n)//neu ton tai vi tri j+1 trong danh sach dang xet thi thoat khoi chuong tirnh
		if (a[j] < a[j + 1])//neu vi tri j khong ton tai phan tu a[j]<a[j+1]
			j++;
	if (a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift_13_Tien_N2_IM_Bai_1(a, j, n);
	}
}
void HeapSort_13_Tien_N2_IM_Bai_1(int a[], int n)
{
	int i = n / 2;
	while (i >= 0)//tao heap ban dau
	{
		shift_13_Tien_N2_IM_Bai_1(a, i, n - 1);
		i--;
	}
	int right = n - 1;
	while (right > 0)
	{
		if (a[0] > a[right])
		{
			hoanVi_13_Tien_N2_IM_Bai_1(a[0], a[right]);//hoan vi phan tu a[0] cho phan tu cuoi Heap dang xet
		}
		right--;//gioi han lai phan tu cuoi dang xet
		if (right > 0)//kiem tra dang xet con nhieu hon mot phan tu
			shift_13_Tien_N2_IM_Bai_1(a, 0, right);//tao heap lai tai vi tri 0
	}
}
int main()
{
	int a[MAX], n;
	input_13_Tien_N2_IM_Bai_1(a, n);
	cout << "\nMANG HIEN TAI LA:\t";
	output_13_Tien_N2_IM_Bai_1(a, n);
	cout << "\nXep thu tu danh sach bang INSERTION SORT\n";
	insertion_13_Tien_N2_IM_Bai_1(a, n);
	output_13_Tien_N2_IM_Bai_1(a, n);
	cout << "\nXep thu tu danh sach bang SELECTION SORT\n";
	Selection_13_Tien_N2_IM_Bai_1(a, n);
	output_13_Tien_N2_IM_Bai_1(a, n);
	cout << "\nXep thu tu danh sach bang BUBLE SORT\n";
	bubleSort_13_Tien_N2_IM_Bai_1(a, n);
	output_13_Tien_N2_IM_Bai_1(a, n);
	cout << "\nXep thu tu danh sach bang INTERCHANGE SORT\n";
	InterchangeSort_13_Tien_N2_IM_Bai_1(a, n);
	output_13_Tien_N2_IM_Bai_1(a, n);
	cout << "\nXep thu tu danh sach bang QUICK SORT\n";
	QuickSort_13_Tien_N2_IM_Bai_1(a, 0, n - 1);
	output_13_Tien_N2_IM_Bai_1(a, n);
	cout << "\nXep thu tu danh sach bang HEAP SORT\n";
	HeapSort_13_Tien_N2_IM_Bai_1(a, n);
	output_13_Tien_N2_IM_Bai_1(a, n);
	return 0;
}