#include <iostream>
using namespace std;
struct Node
{
	int infor;
	Node* link;
};
Node* first;
/* Khai bao
Khoi tao
Them dau ds
Them cuoi danh sach
Tim kiem
Xuat*/
void init();
void insertFirst(int x);
void insertLast(int x);
Node* search(int x);
void processList();
int insert(int x, int y);//thêm x sau y
int insert_no_search(int x, int y);//thêm x sau y nhưng không sử dụng hàm search
int deleteFirst();
int deleteLast();
int deleteAfter(int x);
int main()
{
	int x;
	bool in = false;
	do 
	{
		system("cls");
		cout << "\n\t\t\t\t\tMENU\n"
			<< "\n\t\t\t1. Khoi tao danh sach lien ket.\n"
			<< "\n\t\t\t2. Them phan tu vao dau danh sach.\n"
			<< "\n\t\t\t3. Them phan tu vao cuoi danh sach.\n"
			<< "\n\t\t\t4. Tim kiem phan tu.\n"
			<< "\n\t\t\t5. Xuat danh sach hien tai.\n"
			<< "\n\t\t\t6. Them phan tu sau 1 phan tu\n"
			<<"\n\t\t\t7. Xoa phan thu dau\n"
			<<"\n\t\t\t8. Xoa phan tu cuoi\n"
			<<"\n\t\t\t9. Xoa sau 1 phan tu\n"
			<< "\n\t\t\t10. Thoat chuong trinh\n"
			<< "\nNhap lua chon: ";
		int choose;
		do
		{
			cin >> choose;
			if (choose < 1 || choose>10)
				cout << "\n\t\tLUA CHON KHONG HOP LE. NHAP LAI.\n";
		} while (choose < 1 || choose>10);
		switch (choose)
		{
		case 1:
			cout << "\n\t\tBAN DANG KHOI TAO DANH SACH LIEN KET\n";
			init();
			in = true;
			break;
		case 2:
			if (in)
			{
				cout << "\n\t\tBAN DANG THUC HIEN CHUC NANG THEM PT VAO DAU DANH SACH\n";
				cout << "\nNhap gia tri muon them: ";
				cin >> x;
				insertFirst(x);
				cout << "\n\t\t\t\tTHEM THANH CONG\n";
			}
			else
				cout << "\n\t\tCHUA KHOI TAO DANH SACH LIEN KET!!!\n";
			break;
		case 3:
			if (in)
			{
				cout << "\n\t\tBAN DANG THUC HIEN CHUC NANG THEM PT VAO CUOI DANH SACH\n";
				cout << "\nNhap gia tri muon them: ";
				cin >> x;
				insertLast(x);
				cout << "\n\t\t\t\tTHEM THANH CONG\n";
			}
			else
				cout << "\n\t\tCHUA KHOI TAO DANH SACH LIEN KET!!!\n";
			break;
		case 4:
			if (in)
			{
				cout << "\n\t\tBAN DANG THUC HIEN CHUC NANG TIM KIEM PHAN TU TRONG DANH SACH\n";
				cout << "\nNhap gia tri muon tim kiem: ";
				cin >> x;
				if (search(x) == NULL)
					cout << x << " khong ton tai trong danh sach lien ket\n";
				else
					cout << x << " ton tai tong danh sach lien ket\n";
			}
			else
				cout << "\n\t\tCHUA KHOI TAO DANH SACH LIEN KET!!!\n";
			break;
		case 5:
			if (in)
			{
				cout << "\n\t\t\tBAN DANG THUC HIEN CHUC NANG XUAT DANH SACH LIEN KET\n"
					<< "\n\t\t\t\t\t\tDANH SACH HIEN TAI\n";
				processList();
			}
			else
				cout << "\n\t\tCHUA KHOI TAO DANH SACH LIEN KET!!!\n";
			break;
		case 6:
			if (in)
			{
				cout << "\n\t\tBAN DANG THUC HIEN CHUC NANG THEM 1 PHAN TU SAU 1 PHAN TU\n";
				int y;
				cout << "\nNhap gia tri can them: ";
				cin >> y;
				cout << "\nNhap vi tri them: ";
				cin >> x;
				int tam = insert_no_search(x, y);
				if (tam == 1)
					cout << "\nThem thanh cong\n";
				else
					cout << "\nThem khong thanh cong\n";
			}
			else
				cout << "\n\t\tCHUA KHOI TAO DANH SACH LIEN KET!!!\n";
			break;
		case  7:
			if (in)
			{
				cout << "\n\t\tBAN DANG THUC HIEN CHUAC NANG XOA NODE DAU DANH SACH\n";
				if (deleteFirst() == 1)
					cout << "\n\t\t\t\t\tXOA THANH CONG\n";
				else
					cout << "\n\t\t\t\t\tXOA KHONG THANH CONG\n";
			}
			else
				cout << "\n\t\tCHUA KHOI TAO DANH SACH LIEN KET!!!\n";
			break;
		case 8:
			if (in)
			{
				if (deleteLast() == 1)
					cout << "\n\t\t\t\t\tXOA THANH CONG\n";
				else
					cout << "\n\t\t\t\t\tXOA KHONG THANH CONG\n";
			}
			
			else
				cout << "\n\t\tCHUA KHOI TAO DANH SACH LIEN KET!!!\n";
			break;
		case 9:
			if (in)
			{
				cout << "\nNHap vi tri can xoa: ";
				cin >> x;
				if (deleteAfter(x) == 1)
					cout << "\n\t\t\t\t\tXOA THANH CONG\n";
				else
					cout << "\n\t\t\t\t\tXOA KHONG THANH CONG\n";
			}
			else
				cout << "\n\t\tCHUA KHOI TAO DANH SACH LIEN KET!!!\n";
			break;
		case 10:
			cout << "\n\t\tKET THUC CHUONG TRINH. CAM ON DA SU DUNG.\n";
			return 0;
		}
		system("pause");
	} while (1);
	return 0;
}
void init()
{
	first = NULL;
}
void insertFirst(int x)
{
	Node* p = new Node;
	p->infor = x;
	p->link = first;
	first = p;
}
void insertLast(int x)
{
	Node* p = new Node;
	p->infor = x;
	p->link = NULL;
	if (first == NULL)
		first = p;
	else
	{
		Node* q = first;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
}
Node* search(int x)
{
	Node* p = first;
	while (p != NULL && p->infor != x)
		p = p->link;
	return p;
}
void processList()
{
	Node* p = first;
	while (p != NULL)
	{
		cout << p->infor << "\t";
		p = p->link;
	}
}
int insert(int x, int y)
{
	Node* p = search(x);
	if (p != NULL)//tìm thấy có x trong dslk
	{
		Node* q = new Node;
		q->infor = y;
		q->link = p->link;
		p->link = q;
		return 1;//thêm thành công
	}
	return 0;//thêm không thành công
}
int insert_no_search(int x, int y)
{
	Node* q = first;
	if (first != NULL)
	{
		Node* p = new Node;
		while (q != NULL && q->infor != x)
		{
			q = q->link;
		}
		if (q != NULL)
		{
			p->infor = y;
			p->link = q->link;
			q->link = p;
			return 1;//thêm thành công
		}
		return  -1;//thêm không thành công
	}
}
int deleteFirst()
{
	Node* p = first;
	if (p != NULL)
	{
		first = first->link;
		delete p;
		return 1;//xoa thanh cong
	}
	return -1;//xoa khong thanh cong
}
//int deleteLast()
//{
//	if (first != NULL)
//	{
//		Node* p = first;
//		Node* q = NULL;
//		while (p->link != NULL)//danh sách có ít nhất 1 node
//		{
//			q = p;
//			p = p->link;
//		}
//		if (p != first)//danh sách có ít nhất 2 node
//		{
//			q->link = NULL;
//		}
//		else
//		{
//			first = NULL;
//		}	
//		delete p;
//		return 1;//xoá thành công
//	}
//	return -1;//xoá không thành công
//}
int deleteLast() {
	if (first == NULL) return 0;

	Node* curr = first;
	Node* prev = NULL;

	while (curr->link != NULL) {
		if (curr->infor % 2 == 0) prev = curr;
		curr = curr->link;
	}

	if (curr->infor % 2 == 0) {
		if (prev == NULL) {
			first = first->link;
		}
		else {
			prev->link = curr->link;
		}
		delete curr;
		return 1;
	}
}
int deleteAfter(int x)
{
	if (first != NULL)
	{
		Node* p = first;
		while (p != NULL && p->infor != x)
		{
			p = p->link;
		}
		Node* q = p->link;
		if (q == NULL)
		{
			return -1;
		}
		if (p != NULL)//thử trường hợp p == null
		{
			p->link = q->link;
			delete q;
			return 1;
		}
	}
	return -1;
}