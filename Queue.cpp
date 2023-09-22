#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
const int MAX = 100;
void init(int a[], int& front, int& rear) {
	rear = -1;
	front = -1;
}
bool isEmpty(int front, int rear) {
	return front == -1;
}
bool isFull(int front, int rear) {
	return rear - front == MAX - 1;
}
bool push(int a[], int& front, int& rear, int x) {
	if (isFull(front, rear))
		return 0;
	if (isEmpty(front, rear))
		front = 0;
	if (rear == MAX - 1) {
		rear = -1;
	}
	a[++rear] = x;
	return 1;
}
bool pop(int a[], int& front, int& rear, int& x) {
	if (isEmpty(front, rear))
		return 0;
	x = a[++front];
	if (front == rear)
		front = rear = -1;
	return 1;
}
void output(int a[], int front, int rear) {
	cout << "Cac ptu trong hang doi la:";
	for (int i = front; i <= rear; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}
bool readFile(int a[], int& front, int& rear) {
	int n, x;
	ifstream file("Text.txt");
	if (file.is_open()) {
		file >> n;
		cin.ignore();
		for (int i = 0; i < n; i++) {
			file >> x;
			push(a, front, rear, x);
		}
		file.close();
		cout << "\nF=" << front << endl;
		cout << "\nR=" << rear << endl;
		for (int i = front; i <= rear; i++)
		{
			cout << "\na[" << i << "]= " << a[i] << "\t";
		}
		return 1;
	}
	return 0;
}
void random() {
	int n, x;
	ofstream file("Text.txt");
	cout << "Nhap so phan tu:";
	cin >> n;
	if (file.is_open()) {
		file << n;
		file << endl;
		for (int i = 0; i < n; i++) {
			x = rand() % 11;
			file << x << " ";
		}
		file.close();
	}
}
int main() {
	int a[MAX], chon, front, rear;
	int x;
	init(a, front, rear);
	while (true) {
		do {
			cout << "==============MENU==============\n"
				<< "1.Khoi tao hang doi\n"
				<< "2.Them 1 ptu vao hang doi\n"
				<< "3.Lay 1 ptu ra khoi hang doi\n"
				<< "4.In cac ptu\n"
				<< "5.Kiem tra hang doi rong\n"
				<< "6.Doc file \n"
				<< "7.Rand file\n"
				<< "8.Thoat\n"
				<< "================================\n"
				<< "Moi chon:>";
			cin >> chon;
			if (chon < 1 || chon>8) {
				cout << "Nhap sai vui long nhap lai";
				system("pause");
				system("cls");
			}
		} while (chon < 1 || chon>8);
		switch (chon) {
		case 1:
			init(a, front, rear);
			cout << "Khoi tao thanh cong\n";
			system("pause");
			system("cls");
			break;

		case 2:
			cout << "Nhap so can them:";
			cin >> x;
			(!push(a, front, rear, x)) ? cout << "Hang doi bi day!Vui long xoa bot de co the them\n" : cout << "Them thanh cong\n";
			system("pause");
			system("cls");
			break;
		case 3:

			(!pop(a, front, rear, x)) ? cout << "Hang doi rong!\n" : cout << "Xoa thanh cong\n";
			system("pause");
			system("cls");
			break;
		case 4:
			if (isEmpty(front, rear)) {
				cout << "Hang doi rong\n";
				return 0;
			}
			output(a, front, rear);
			system("pause");
			system("cls");
			break;
		case 5:
			if (isEmpty(front, rear)) {
				cout << "Hang doi rong!\n";
				system("pause");
				system("cls");
			}
			else {
				cout << "Hang doi khong rong\n";
				system("pause");
				system("cls");
			}
			break;
		case 6:
			(readFile(a, front, rear)) ? cout << "Doc file thanh cong\n" : cout << "Doc file khong thanh cong\n";
			system("pause");
			system("cls");
			break;
		case 7:
			random();
			cout << "Random thanh cong\n";
			system("pause");
			system("cls");
			break;
		case 8:
			cout << "Cam on da su dung!";
			return 0;
		}

	}
	return 0;
}