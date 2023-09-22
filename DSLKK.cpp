//Khoi tao danh sach lien ket
//Duyet dslk
//Tim kiem ptu trong dslk
//Them mot ptu vao dslk: them dau, them cuoi, them sau
//Xoa mot ptu khoi dslk: xoa dau, xoa cuoi, xoa sau
//Dem xem dslk co bao nhieu node
#include <iostream>
using namespace std;
struct Node
{
	int value;
	Node* previous;
	Node* next;
};
Node* first, * last;
void init();
void process_List();
void process_List_LastToFirst();
void insert_First(int x);
void insert_Last(int x);
int insert_After(int x, int y);//them y sau Node x
int delete_First();
int delete_Last();
int delete_After(int x);
Node* search(int x);
int Demdslk();
void deleteALL();
int main()
{
	int chon, x, in = 0;
	do
	{
		system("cls");
		cout << "\n\t\t\t\t\t\t\t\t\tMENU\n"
			<< "\n\t\t\t\t\t1. Khoi tao dslk kep\n"
			<< "\n\t\t\t\t\t2. Them phan tu vao dau danh sach\n"
			<< "\n\t\t\t\t\t3. Them phan tu vao cuoi danh sach\n"
			<< "\n\t\t\t\t\t4. Them phan tu vao sau mot phan tu bat ki\n"
			<< "\n\t\t\t\t\t5. Xoa phan tu dau danh sach\n"
			<< "\n\t\t\t\t\t6. Xoa phan tu cuoi danh sach\n"
			<< "\n\t\t\t\t\t7. Xoa phan tu sau mot phan tu bat ki\n"
			<< "\n\t\t\t\t\t8. Xuat danh sach tu dau den cuoi\n"
			<< "\n\t\t\t\t\t9. Xuat danh sach tu cuoi den dau\n"
			<< "\n\t\t\t\t\t10. Tim kiem phan tu trong danh sach\n"
			<< "\n\t\t\t\t\t11. Dem so NODE trong danh sach\n"
			<< "\n\t\t\t\t\t12. Thoat\n";
		do
		{
			cout << "\nNhap lua chon: ";
			cin >> chon;
			if (chon < 1 || chon>12)
				cout << "\n\t\t\t\tLUA CHON KHONG HOP LE. VUI LONG NHAP LAI!!!\n";
		} while (chon < 1 || chon>12);
		switch (chon)
		{
		case 1:
			init();
			in = 1;
			cout << "\n\t\t\tKHOI TAO DANH SACH THANH CONG.\n";
			break;
		case 2:
			if (in)
			{
				cout << "\n\t\t\tTHEM PHAN TU VAO DAU DANH SACH\n";
				cout << "\nNhap gia tri muon them: ";
				cin >> x;
				insert_First(x);
				cout << "\n\t\t\t\t\t\tTHEM THANH CONG\n";
			}
			else
			{
				cout << "\n\t\t\t\t\tCHUA KHOI TAO DANH SACH LIEN KET. VUI LONG KHOI TAO DSLK!!!\n";
			}
			break;
		case 3:
			if (in)
			{
				cout << "\n\t\t\tTHEM PHAN TU VAO CUOI DANH SACH\n";
				cout << "\nNhap gia tri muon them: ";
				cin >> x;
				insert_Last(x);
				cout << "\n\t\t\t\t\t\tTHEM THANH CONG\n";
			}
			else
			{
				cout << "\n\t\t\t\t\tCHUA KHOI TAO DANH SACH LIEN KET. VUI LONG KHOI TAO DSLK!!!\n";
			}
			break;
		case 4:
			if (in)
			{
				cout << "\n\t\t\tTHEM PHAN TU VAO SAU MOT PHAN TU BAT KI\n";
				cout << "\nNhap gia tri muon them: ";
				int y;
				cin >> y;
				cout << "\nNhap vi tri muon them: ";
				cin >> x;
				int b = insert_After(x, y);
				if (b == 1)
					cout << "\n\t\t\t\t\tTHEM THANH CONG\n";
				else
					cout << "\n\t\t\t\t\tTHEM KHONG THANH CONG\n";
			}
			else
			{
				cout << "\n\t\t\t\t\tCHUA KHOI TAO DANH SACH LIEN KET. VUI LONG KHOI TAO DSLK!!!\n";
			}
			break;
		case 5:
			if (in)
			{
				cout << "\n\t\t\t\t\tXOA PHAN TU DAU DANH SACH\n";
				int temp = delete_First();
				if (temp == 1)
					cout << "\n\t\t\t\t\t\tXOA THANH CONG\n";
				else
					cout << "\n\t\t\t\t\t\tXOA KHONG THANH CONG\n";
			}
			else
			{
				cout << "\n\t\t\t\t\tCHUA KHOI TAO DANH SACH LIEN KET. VUI LONG KHOI TAO DSLK!!!\n";
			}
			break;
		case 6:
			if (in)
			{
				cout << "\n\t\t\t\t\tXOA PHAN TU CUOI DANH SACH\n";
				int temp = delete_Last();
				if (temp == 1)
					cout << "\n\t\t\t\t\t\tXOA THANH CONG\n";
				else
					cout << "\n\t\t\t\t\t\tXOA KHONG THANH CONG\n";
			}
			else
			{
				cout << "\n\t\t\t\t\tCHUA KHOI TAO DANH SACH LIEN KET. VUI LONG KHOI TAO DSLK!!!\n";
			}
			break;
		case 7:
			if (in)
			{
				cout << "\n\t\t\tXOA PHAN TU VAO SAU MOT PHAN TU BAT KI\n";
				cout << "\nNhap vi tri muon xoa: ";
				cin >> x;
				if (delete_After(x) == 1)
					cout << "\n\t\t\t\t\tXOA THANH CONG\n";
				else
					cout << "\n\t\t\t\t\tXOA KHONG THANH CONG\n";
			}
			else
			{
				cout << "\n\t\t\t\t\tCHUA KHOI TAO DANH SACH LIEN KET. VUI LONG KHOI TAO DSLK!!!\n";
			}
			break;
		case 8:
			if (in)
			{
				cout << "\n\t\t\t\t\t\tXUAT DANH DACH TU DAU TOI CUOI\n";
				cout << "\n\t\t\t\tDANH SACH DUOC LUU TRU\n";
				process_List();
			}
			else
			{
				cout << "\n\t\t\t\t\tCHUA KHOI TAO DANH SACH LIEN KET. VUI LONG KHOI TAO DSLK!!!\n";
			}
			break;
		case 9:
			if (in)
			{
				cout << "\n\t\t\t\t\t\tXUAT DANH DACH TU CUOI TOI DAU\n";
				cout << "\n\t\t\t\tDANH SACH DUOC LUU TRU\n";
				process_List_LastToFirst();
			}
			else
			{
				cout << "\n\t\t\t\t\tCHUA KHOI TAO DANH SACH LIEN KET. VUI LONG KHOI TAO DSLK!!!\n";
			}
			break;
		case 10:
			if (in)
			{
				cout << "\n\t\t\t\t\tTIM KIEM PHAN TU\n";
				cout << "\nNhap phan tu can tim kiem: ";
				cin >> x;
				if (search(x) != NULL)
					cout << x << " co ton tai trong dslk\n";
				else
					cout << x << " khong ton tai trong dslk\n";
			}
			else
			{
				cout << "\n\t\t\t\t\tCHUA KHOI TAO DANH SACH LIEN KET. VUI LONG KHOI TAO DSLK!!!\n";
			}
			break;
		case 11:
			if (in)
			{
				cout << "\n\t\t\t\t\t\tDEM SO NODE TRONG DSLK\n";
				int tam = Demdslk();
				cout << "\n\t\t\tDSLK co " << tam << " NODE\n";
			}
			else
			{
				cout << "\n\t\t\t\t\tCHUA KHOI TAO DANH SACH LIEN KET. VUI LONG KHOI TAO DSLK!!!\n";
			}
			break;
		case 12:
			if (in)
			{
				deleteALL();
			}
			cout << "\n\t\t\t\t\tCAM ON DA SU DUNG DICH VU\n";
			return 0;
		}
		system("pause");
	} while (1);
	return 0;
}
void init()//ham khoi tao gia tri NULL cho dslk
{
	first = NULL;
	last = NULL;
}
void process_List()
{
	if (first == NULL)
	{
		cout << "\n\t\t\t\tDANH SACH RONG\n";
	}
	else
	{
		Node* p = first;
		while (p != NULL)
		{
			cout << p->value << "\t";
			p = p->next;
		}
		cout << endl;
	}
}
void process_List_LastToFirst()
{
	if (last == NULL)
		cout << "\n\t\t\t\t\t\tDANH SACH RONG\n";
	else
	{
		Node* p = last;
		while (last != NULL)
		{
			cout << p->value << "\t";
			p = p->previous;
		}
		cout << endl;
	}
}
void insert_First(int x)
{
	Node* p = new Node;
	p->value = x;
	p->previous = NULL;//truong hop binh thuong, truong hop neu nhu dslk ch co phan tu nao?
	p->next = first;
	if (first == NULL)//DSLK chua co phan tu nao
		last = p;//cap nhat phan tu cuoi, luc nay phan tu cuoi cung la phan tu dau
	else
		first->previous = p;
	first = p;
}
void insert_Last(int x)
{
	Node* p = new Node;
	p->value = x;
	p->next = NULL;
	p->previous = last;
	if (last != NULL)
		last->next = p;
	else
		first = p;
	last = p;
}
int insert_After(int x, int y)//them y sau Node x
{
	Node* p = new Node;
	Node* q = first;
	while (q != NULL && q->value != x)
	{
		q = q->next;
	}
	if (q != NULL)
	{
		p->previous = q;
		if (q->next != NULL)//trường hợp thêm 1 phần tử vào sau phần tử cuối
		{
			q->next->previous = p;
		}
		p->next = q->next;
		q->next = p;
		p->value = y;
		return 1;
	}
	return -1;
}
int delete_First()
{
	if (first != NULL)
	{
		Node* p = first;
		first = first->next;
		if (first != NULL)
			first->previous = NULL;
		else
			last = NULL;
		delete p;
		return 1;//xoa thanh cong
	}
	return -1;//xoa khong thanh cong
}
int delete_Last()
{
	if (last != NULL)
	{
		Node* p = last;
		last = last->previous;
		if (last == NULL)
			first = NULL;
		else
			last->next = NULL;
		delete p;
		return 1;
	}
	return -1;
}
int delete_After(int x)
{
	if (first != NULL)
	{
		Node* p = first;
		while (p != NULL & p->value != x)
			p = p->next;
		if (p != NULL)
		{
			Node* q = p->next;
			if (q == NULL)
				return -1;
			q->next->previous = p;
			p->next = q->next;
			delete q;
		}
		return 1;
	}
	return -1;
}
Node* search(int x)
{
	Node* p = first;
	while (p != NULL && p->value != x)
	{
		p = p->next;
	}
	return p;
}
int Demdslk()
{
	int count = 0;
	Node* p = first;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}
void deleteALL()
{
	while (first != NULL)
	{
		delete_First();
	}
}