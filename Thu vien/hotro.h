﻿#pragma once
#include "ctdl.h"
#include "lib.h"

TREE TIM_KIEM_DG_MA(TREE& t, int ma_doc_gia);
void SX_THELOAI_DS(LIST_DS& l);
int SoluongDG(TREE t);
int Kiem_tra_phim(char c);
int tinh_so_ngay(Date n1);
int TIM_KIEM_DS_THEO_MA(LIST_DS l, string ma);
void control_cursor(bool x);

enum TRANGTHAI { UP, DOWN, LEFT, RIGHT, ENTER, ESC };
// hàm có chức năng bắt phim vừa nhập để điều khiển menu
TRANGTHAI key(char c)
{
	if (c == -32)
		c = _getch();

	if (c == 72)
		return UP;
	if (c == 80)
		return DOWN;
	if (c == 77)
		return RIGHT;
	if (c == 75)
		return LEFT;
	if (c == 27)
		return ESC;
	if (c == 13)
		return ENTER;
}
void chuan_hoa_chu(string& str)
{
	// xử lí khoảng trắng đầu

	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0);
	}
	// xử lí khoảng trắng cuối
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + str.length() - 1);
	}
	// xử lí khoảng trắng giữa
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
	// chuan hóa kí tự chữ cái đầu viết hoa sau 
	if (str[0] >= 97 && str[0] <= 122)
	{
		str[0] -= 32;
	}
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			i++;
			if (str[i] >= 97 && str[i] <= 122)
			{
				str[i] -= 32;
			}
		}
		else
		{
			if (str[i] >= 65 && str[i] <= 90)
			{
				str[i] += 32;
			}
		}
	}
}

void Box_BaoLoi()
{
	int tungdo = 45;
	TextColor(14);
	gotoXY(86, tungdo - 1);
	cout << "THONG BAO";
	TextColor(76);
	gotoXY(boxx, tungdo); cout << char(201);
	for (int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(187);
	gotoXY(boxx, tungdo + 1); cout << char(186);
	gotoXY(boxx + boxs + 1, tungdo + 1); cout << char(186);
	gotoXY(boxx, tungdo + 2); cout << char(186);
	gotoXY(boxx + boxs + 1, tungdo + 2); cout << char(186);
	gotoXY(boxx, tungdo + 3); cout << char(186);
	gotoXY(boxx + boxs + 1, tungdo + 3); cout << char(186);
	gotoXY(boxx, tungdo + 4); cout << char(186);
	gotoXY(boxx + boxs + 1, tungdo + 4); cout << char(186);
	gotoXY(boxx + 1, tungdo + 5);
	for (int i = 1; i <= boxs; i++) cout << char(205);
	gotoXY(boxx, tungdo + 5); cout << char(200);
	gotoXY(boxx + boxs + 1, tungdo + 5); cout << char(188);
	TextColor(7);
}
void xoa_hienthi_box_baoloi()
{
	int tungdo = 45;
	gotoXY(86, tungdo - 1);
	cout << "               ";
	TextColor(4);
	gotoXY(boxx, tungdo); cout << " ";
	for (int i = 1; i < boxs + 1; i++) cout << " ";
	cout << " ";
	gotoXY(boxx, tungdo + 1); cout << " ";
	gotoXY(boxx + boxs + 1, tungdo + 1); cout << " ";
	gotoXY(boxx, tungdo + 2);  cout << " ";
	gotoXY(boxx + boxs + 1, tungdo + 2); cout << " ";
	gotoXY(boxx, tungdo + 3);  cout << " ";
	gotoXY(boxx + boxs + 1, tungdo + 3); cout << " ";
	gotoXY(boxx, tungdo + 4); cout << " ";
	gotoXY(boxx + boxs + 1, tungdo + 4); cout << " ";
	gotoXY(boxx + 1, tungdo + 5);
	for (int i = 1; i <= boxs; i++) cout << " ";
	gotoXY(boxx, tungdo + 5); cout << " ";
	gotoXY(boxx + boxs + 1, tungdo + 5); cout << " ";
	TextColor(7);
}
void BaoLoi(string s) {
	control_cursor(false);
	int n = s.length();
	int x = whereX(), y = whereY();
	Box_BaoLoi();
	TextColor(15);
	gotoXY(boxx + 28, boxy + 42);
	cout << s;
	Sleep(1200);
	while (_kbhit()) // không nhận phím  khi đang ngủ
		_getch();

	for (int i = 0; i < n; i++)
	{
		gotoXY(boxx + 28 + i, boxy + 42);
		cout << " ";
	}
	xoa_hienthi_box_baoloi();
	gotoXY(x, y);
	TextColor(7);
	control_cursor(true);
}
void ButtonPrev()
{
	gotoXY(100, 42); cout << "<-";
}
void ButtonNext()
{
	gotoXY(110, 42); cout << "->";
}

// tách mã sách chỉ lấy mã đầu sách
string tach_ma_sach(string a)
{
	string temp;
	int n = a.length();
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == '-')
			dem = i;
	}
	temp = a.substr(0, dem);

	return temp;
}

// ham chuyen doi so sang chuoi 
string so_sang_chuoi(int number)
{
	return to_string(number);
}

// ham chuyen doi chuỗi sang số nếu chuyển hết rt giá trị <> -1
int chuoi_sang_so(string x)
{
	string temp = x;
	int n = atoi(temp.c_str());
	if (n != 0)
		return n;
	return -1;
}

// ************************NHAP***************************
// hàm kiểm tra dữ liệu của chuỗi nhập vào phải là các kí tự số hoặc kí tự chữ cái đsung true <> false
bool Kiem_Tra_Du_Lieu(char c)
{
	if ((c >= 48 && c <= 57) || c == 8) // nếu là số thì rt true <> false;
	{
		return true;
	}
	return false;
}
bool Kiem_Tra_Ki_Tu_So(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}
int Kiem_tra_phim(char c)
{
	int arr[32] = { 72,75,77,80,81,73,44,46,59,39,47,93,91,92,61,82,83,79,71,-122,-123,68,67,66,65
	,64,63,62,61,60,59,96 };
	if (Kiem_Tra_Ki_Tu_So(c) == true) // so
		return 2;
	// nhấn shift + key
	if (GetKeyState(VK_SHIFT) & 0x8000)
		return 1;
	for (int i = 0; i < 32; i++)
		if (c == arr[i])
			return 1;

	return 0;
} 
// Nhập số nguyên chỉ nhận 0 và 1 <> ESC RT -1
int nhap_so_nguyen1(int& n) {
	string str=so_sang_chuoi(n);
	int length = str.length();
	bool kt = false;
	char c;
	do
	{
		c = _getch();
		if (c == 0 || c == -32)
			c = _getch();
		while (int(c) != 13)
		{
			if (c == 27)
			{
				control_cursor(false);
				return -1;
			}
			if (int(c) == 8) // nếu ấn phím Backspace thì xóa 1 kí tự ở cuối
			{

				if (length > 0) // nếu như độ dài biến con trỏ dịch bằng 0 thì ko cho xóa tiếp
				{
					cout << "\b \b"; // khi bấm phím Backspace thì sẽ xóa từng kí tự của chuỗi kí tự hiện tại
					length--;
				}
				if (str.length() != 0) // xóa kí tự cuối trong chuỗi string 
				{
					str.erase(str.begin() + (str.length() - 1));
				}
			}
			else
			{
				cout << c;
				length++; // cập nhật vụ trí con trỏ chỉ vị
				str.push_back(c);
			}
			c = _getch();
		}
		if (c == 13)
		{
			int dem = 1;
			int dem1 = 0;
			for (int i = 0; i < length; i++)
			{
				if ((int)str[i] == 32)
					dem++;
				else
					dem1++;
			}
			if (length == 0 || (dem >= 2 && dem1 == 0))
			{
				BaoLoi("KHONG DUOC DE TRONG");
				continue;
			}
			int i = atoi(str.c_str());
			if (i == 0 || i == 1)
			{
				kt = true;
				n = i;
			}
			else
			{
				BaoLoi("TRANG THAI CHI NHAN 1 HOAC 0");
				while (length > 0)
				{
					cout << "\b \b";
					str.pop_back();
					length--;
				}
			}
			
		}
	} while (kt==false);
}
int nhap_so_nguyen(int& n) // Hàm nhập dữ liệu toàn số .
{
	control_cursor(true);
	string str = "";
	str = so_sang_chuoi(n);
	// nếu nhập kí tự enter thì chuỗi hiểu đó là kí tự kết thúc chuỗi <=> length = 0, ko tính là 1 kí tự
	bool KT = false;
	int length = str.length()-1; // biến cho con trỏ dịch đến cuối
	if (str == "0") str = "";
	char c;
	do
	{
		c = _getch();
		if (c == 0 || c == -32)
			c = _getch();
		while (int(c) != 13)
		{
			if (c == 27)
			{
				control_cursor(false);
				return -1;
			}
			if (Kiem_Tra_Du_Lieu(c) == false) // nếu nhập kí tự là chữ
			{
				BaoLoi("CHI DUOC NHAP SO");
				c = _getch();
				continue;
			}
			if (int(c) == 8) // nếu ấn phím Backspace thì xóa 1 kí tự ở cuối
			{

				if (length > 0) // nếu như độ dài biến con trỏ dịch bằng 0 thì ko cho xóa tiếp
				{
					cout << "\b \b"; // khi bấm phím Backspace thì sẽ xóa từng kí tự của chuỗi kí tự hiện tại
					length--;
				}
				if (str.length() != 0) // xóa kí tự cuối trong chuỗi string 
				{
					str.erase(str.begin() + (str.length() - 1));
				}
			}
			else
			{
				cout << c;
				length++; // cập nhật vụ trí con trỏ chỉ vị
				str.push_back(c);
			}
			c = _getch();
		}
		if (c == 13)
		{
			int dem = 1;
			int dem1 = 0;
			for (int i = 0; i < length; i++)
			{
				if ((int)str[i] == 32)
					dem++;
				else
					dem1++;
			}
			if (length == 0 || (dem >= 2 && dem1 == 0) )
			{
				BaoLoi("KHONG DUOC DE TRONG");
				KT = false;
			}
			else
			{
				if (chuoi_sang_so(str) <= 0)
				{
					BaoLoi("SO NHAP VAO PHAI LON > 0");
					continue;
				}
				chuan_hoa_chu(str);
				KT = true;
			}
		}
	} while (KT == false);
	cout << endl;
	n = atoi(str.c_str()); // chuyen doi chuoi sang so
	control_cursor(false);
}
//flag =0 nhap toan ki tu, flag=1 nhap ki tu va so, flag =2 nhap gioitinh,flag=3 nhap ki tu la so
int nhap_ki_tu(string& str, int flag)
{
	control_cursor(true);
	// nếu nhập kí tự enter thì chuỗi hiểu đó là kí tự kết thúc chuỗi <=> length = 0, ko tính là 1 kí tự
	bool KT = false;;
	int length = str.length(); // biến cho con trỏ dịch đến cuối
	char c;
	do
	{
		c = _getch();
		if (c == 0 || c == -32)
		{
			c = _getch();
		}
		while (int(c) != 13)
		{
			if (c == 27)
			{
				control_cursor(false);
				return -1;
			}
			int k = Kiem_tra_phim(c);
			if (k == 1) // phím chức năng
			{
				BaoLoi("PHIM NHAP KHONG HOP LE");
				break;
			}
			if (flag == 3)
			{
				if (Kiem_Tra_Du_Lieu(c) == false) // nếu nhập kí tự là chữ
				{
					BaoLoi("CHI DUOC NHAP SO");
					break;
				}
			}
			if (k == 2 && (flag == 0 || flag == 2)) // nếu nhập kí tự là số
			{
				BaoLoi("KHONG DUOC NHAP SO");
				break;
			}


			if (int(c) == 8) // nếu ấn phím Backspace thì xóa 1 kí tự ở cuối
			{

				if (length > 0) // nếu như độ dài biến con trỏ dịch bằng 0 thì ko cho xóa tiếp
				{
					cout << "\b \b"; // khi bấm phím Backspace thì sẽ xóa từng kí tự của chuỗi kí tự hiện tại
					length--;
				}
				if (str.length() != 0) // xóa kí tự cuối trong chuỗi string 
				{
					str.erase(str.begin() + (str.length() - 1));
				}
			}
			else
			{
				TextColor(15);
				cout << c;
				length++; // cập nhật vụ trí con trỏ chỉ vị
				str.push_back(c);
			}
			break;
		}
		if (c == 13)
		{
			int dem = 1;
			int dem1 = 0;
			for (int i = 0; i < length; i++)
			{
				if ((int)str[i] == 32)
					dem++;
				else
					dem1++;
			}
			if (length == 0 || (dem >= 2 && dem1 == 0))
			{
				BaoLoi("KHONG DUOC DE TRONG");
				KT = false;
			}
			else if (flag == 0 || flag == 1)
				KT = true;
			else if (flag == 2)// flag=2 nhap gioi tinh
			{
				if (dem1 != 0)
				{
					chuan_hoa_chu(str);
					if (str == "Nam" || str == "Nu")
						KT = true;
					else
					{
						BaoLoi("GIOI TINH CHI NAM HOAC NU");
						while (length > 0)
						{
							cout << "\b \b";
							str.pop_back();
							length--;
						}
						KT = false;
					}
				}
			}
			else
				KT = true;

		}
	} while (KT == false);
	cout << endl;
	chuan_hoa_chu(str);
	control_cursor(false);
}





// ========================tạo mã độc giả không trùng================
// tạo 100000 mã độc giả 
void tao_ma_doc_gia()
{
	int* arr = new int[MAX_MATHE + 1];
	int i = 1;
	for (i; i <= 100000; i++)
	{
		arr[i] = i;
	}
	for (i = 1; i <= 100000; i += 2)
	{
		int j = rand() % 100000 + 1;
		swap(arr[i], arr[j]);
	}
	ofstream fileout("MADOCGIA.txt");
	for (i = 1; i <= 100000; i++)
	{
		fileout << arr[i] << endl;
	}
	delete[] arr;
	fileout.close();
}


// =============================== giải phóng==================
void giaiphong_cay(TREE& t)
{
	if (t != NULL)
	{
		if (t->data.tongsosach > 0)
		{
			NODE_MT* p = t->data.mt.pHead;
			NODE_MT* q = NULL;
			while (p != NULL)
			{
				t->data.mt.pHead = p->pNext;
				if (p != t->data.mt.pTail)
				{
					p = p->pNext;
					q = p->pPrev;
					delete q;
				}
				else // p là node cuối mt
				{
					delete p;
					break;
				}
			}
			t->data.mt.pTail = NULL;
		}
		giaiphong_cay(t->pLeft);
		giaiphong_cay(t->pRight);
		delete t;
		t = NULL;
	}
}
void giaiphong_dausach(LIST_DS& l)
{
	for (int i = 0; i < l.sl; i++)
	{
		NODE_DMS* p = NULL;
		if (l.ds_dausach[i]->soluongsach > 0)
		{
			while (l.ds_dausach[i]->dms.pHead != NULL)
			{
				p = l.ds_dausach[i]->dms.pHead;
				l.ds_dausach[i]->dms.pHead = l.ds_dausach[i]->dms.pHead->pNext;
				delete p;
			}
			l.ds_dausach[i]->dms.pTail = NULL;
		}
		delete l.ds_dausach[i];
		l.sl--;
	}
}

// hoán đổi vị trí 2 độc giả
void hoandoi(docgia& a, docgia& b)
{
	docgia temp = a;
	a = b;
	b = temp;
}

// lấy thời gian thực hệ thống
void thoi_gian_thuc(Date& x)
{
	time_t t = time(NULL);
	tm* now = localtime(&t);
	x.ngay = now->tm_mday;
	x.thang = now->tm_mon + 1;
	x.nam = now->tm_year + 1900;
}
// tính ngày chênh lệch giữa 2 mốc thời gian
int tinh_so_ngay(Date n1)
{
	Date n2;
	thoi_gian_thuc(n2);
	int sum = 0;
	while (n2.nam >= n1.nam)
	{
		if (n1.nam == n2.nam && n2.thang == n1.thang)
		{
			sum += n2.ngay - n1.ngay;
			break;
		}
		else
		{
			// các tháng 4 6 9 11 có 30 ngày
			if (n1.thang == 4 || n1.thang == 6 || n1.thang == 9 || n1.thang == 11)
			{
				sum += 30 - n1.ngay;
			}
			if (n1.thang == 1 || n1.thang == 3 || n1.thang == 5 || n1.thang == 7 || n1.thang == 8 || n1.thang == 10 || n1.thang == 12)
			{
				sum += 31 - n1.ngay;
			}
			if (n1.thang == 2)
			{
				if (n1.nam % 4 == 0 && n1.nam % 100 != 0 || n1.nam % 400 == 0)
				{
					sum += 29 - n1.ngay;
				}
				else
					sum += 28 - n1.ngay;
			}
			n1.thang++; n1.ngay = 0;
			if (n1.thang == 13)
			{
				// tăng năm lên 1
				n1.nam++;
				n1.thang = 1;
			}
		}
	}
	return sum;
}

void xoa_hienthi_buttonNext()
{
	int x = whereX();
	int y = whereY();
	gotoXY(110, 42); cout << "       ";
	gotoXY(x, y);
}
void XOA_HIEN_THI()
{
	int x = whereX();
	int y = whereY();
	for (int i = 0; i <= 40; i++) {
		ClearLine(40, i);
	}
	gotoXY(x, y);
}


void ButtonEnter(int hoanhdo, int tungdo)
{
	int x = whereX();
	int y = whereY();
	gotoXY(hoanhdo, tungdo); TextColor(76); cout << "        ";
	gotoXY(hoanhdo, tungdo + 1); TextColor(78); cout << "  CHON  ";
	gotoXY(hoanhdo, tungdo + 2); TextColor(76); cout << "        ";
	gotoXY(hoanhdo, tungdo + 3); TextColor(79); cout << "  Enter ";
	gotoXY(x, y);
}
void ButtonESC(int hoanhdo, int tungdo)
{
	int x = whereX(), y = whereY();
	gotoXY(hoanhdo, tungdo); TextColor(76); cout << "        ";
	gotoXY(hoanhdo, tungdo + 1); TextColor(78); cout << "  THOAT ";
	gotoXY(hoanhdo, tungdo + 2); TextColor(76); cout << "        ";
	gotoXY(hoanhdo, tungdo + 3); TextColor(79); cout << "   ESC  ";
	gotoXY(x, y);
}
void xoa_hien_thi_1_Button(int hoanhdo, int tungdo)
{
	int x = whereX(), y = whereY();
	gotoXY(hoanhdo, tungdo); TextColor(7); cout << "        ";
	gotoXY(hoanhdo, tungdo + 1); TextColor(7); cout << "        ";
	gotoXY(hoanhdo, tungdo + 2); TextColor(7); cout << "        ";
	gotoXY(hoanhdo, tungdo + 3); TextColor(7); cout << "        ";
	gotoXY(x, y);
}

void xoa_hien_thi_button()
{
	int x = whereX(), y = whereY();
	TextColor(7);

	gotoXY(boxx + boxs - 5, boxy + 15);  cout << "        ";
	gotoXY(boxx + boxs - 5, boxy + 16);  cout << "        ";
	gotoXY(boxx + boxs - 5, boxy + 17);  cout << "        ";
	gotoXY(boxx + boxs - 5, boxy + 18);  cout << "        ";

	gotoXY(boxx + boxs - 45, boxy + 15);  cout << "        ";
	gotoXY(boxx + boxs - 45, boxy + 16);  cout << "        ";
	gotoXY(boxx + boxs - 45, boxy + 17);  cout << "        ";
	gotoXY(boxx + boxs - 45, boxy + 18);  cout << "        ";

	gotoXY(boxx, boxy + 15);  cout << "        ";
	gotoXY(boxx, boxy + 16);  cout << "        ";
	gotoXY(boxx, boxy + 17);  cout << "        ";
	gotoXY(boxx, boxy + 18);  cout << "        ";
	gotoXY(x, y);
}
void huong_dan_su_dung()
{
	ifstream fo("input1.txt");
	string s;
	int i = 0;
	int j = 1;
	int x = 80;
	while (!fo.eof())
	{
		getline(fo, s);
		i = rand() % 15 + 1;
		gotoXY(x, j++);
		TextColor(i);
		cout << s;
	}
	fo.close();

	gotoXY(94, 20);
	TextColor(15);
	cout << "HUONG DAN SU DUNG";
	gotoXY(82, 24);
	cout << char(24);
	gotoXY(82, 26);
	cout << char(25);
	gotoXY(80, 25);
	cout << char(27);
	gotoXY(84, 25);
	cout << char(26);
	gotoXY(86, 25);
	TextColor(14);
	cout << "Su Dung 4 Phim Mui Ten De Di Chuyen";

	gotoXY(78, 28); TextColor(76); cout << "        ";
	gotoXY(78, 29); TextColor(78); cout << "  CHON  ";
	gotoXY(78, 30); TextColor(76); cout << "        ";
	gotoXY(78, 31); TextColor(79); cout << "  Enter ";
	gotoXY(87, 30); TextColor(14); cout << "Bam Phim Enter De Chon Thao Tac";

	gotoXY(78, 34); TextColor(76); cout << "        ";
	gotoXY(78, 35); TextColor(78); cout << "  THOAT ";
	gotoXY(78, 36); TextColor(76); cout << "        ";
	gotoXY(78, 37); TextColor(79); cout << "   ESC  ";
	gotoXY(87, 36); TextColor(14); cout << "Bam Phim ESC De Quay Lai Hoac Thoat";
	gotoXY(0, 0);
}
void xoa_hien_thi_huong_dan()
{
	int x = whereX();
	int y = whereY();
	TextColor(7);
	for (int i = 1; i <= 40; i++)
	{
		gotoXY(60, i); cout << "                                                                      ";
	}
	xoa_hien_thi_1_Button(78, 28);
	xoa_hien_thi_1_Button(78, 34);
	gotoXY(x, y);
}
void Box_NhapDG()
{
	ButtonEnter(boxx + boxs - 5, boxy + 15);
	ButtonESC(boxx, boxy + 15);
	TextColor(15);
	gotoXY(boxx, boxy); cout << char(201);
	for (int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(187);
	gotoXY(boxx, boxy + 1); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 1); cout << char(186);
	gotoXY(boxx, boxy + 2); cout << char(186) << " Ma DG: ";
	gotoXY(boxx + boxs + 1, boxy + 2); cout << char(186);
	gotoXY(boxx, boxy + 3); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 3); cout << char(186);
	gotoXY(boxx, boxy + 4); cout << char(186) << " Nhap Ho: ";
	gotoXY(boxx + boxs + 1, boxy + 4); cout << char(186);
	gotoXY(boxx, boxy + 5); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 5); cout << char(186);
	gotoXY(boxx, boxy + 6); cout << char(186) << " Nhap Ten: ";
	gotoXY(boxx + boxs + 1, boxy + 6); cout << char(186);
	gotoXY(boxx, boxy + 7); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 7); cout << char(186);
	gotoXY(boxx, boxy + 8); cout << char(186) << " Nhap Phai: ";
	gotoXY(boxx + boxs + 1, boxy + 8); cout << char(186);
	gotoXY(boxx, boxy + 9); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 9); cout << char(186);
	gotoXY(boxx, boxy + 10); cout << char(186) << " Trang thai the: ";
	gotoXY(boxx + boxs + 1, boxy + 10); cout << char(186);
	gotoXY(boxx, boxy + 11); cout << char(200);
	for (int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(188);
}
void xoa_hien_thi_Box_NhapDG()
{
	int x = whereX(), y = whereY();
	TextColor(15);
	gotoXY(boxx, boxy); cout << " ";
	for (int i = 1; i < boxs + 1; i++) cout << " ";
	cout << " ";
	gotoXY(boxx, boxy + 1); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 1); cout << " ";
	gotoXY(boxx, boxy + 2); cout << "                                      ";
	gotoXY(boxx + boxs + 1, boxy + 2); cout << " ";
	gotoXY(boxx, boxy + 3); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 3); cout << " ";
	gotoXY(boxx, boxy + 4); cout << "                                      ";
	gotoXY(boxx + boxs + 1, boxy + 4); cout << " ";
	gotoXY(boxx, boxy + 5); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 5); cout << " ";
	gotoXY(boxx, boxy + 6); cout << "                                      ";
	gotoXY(boxx + boxs + 1, boxy + 6); cout << " ";
	gotoXY(boxx, boxy + 7); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 7); cout << " ";
	gotoXY(boxx, boxy + 8); cout << "                                      ";
	gotoXY(boxx + boxs + 1, boxy + 8); cout << " ";
	gotoXY(boxx, boxy + 9); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 9); cout << " ";
	gotoXY(boxx, boxy + 10); cout << "                                      ";
	gotoXY(boxx + boxs + 1, boxy + 10); cout << " ";
	gotoXY(boxx, boxy + 11); cout << " ";
	for (int i = 1; i < boxs + 1; i++) cout << " ";
	cout << " ";
	gotoXY(x, y);
}
void Box_NhapDS()
{
	ButtonEnter(boxx + boxs - 5, boxy + 15);
	ButtonESC(boxx, boxy + 15);
	TextColor(15);
	gotoXY(boxx, boxy); cout << char(201);
	for (int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(187);
	gotoXY(boxx, boxy + 1); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 1); cout << char(186);
	gotoXY(boxx, boxy + 2); cout << char(186) << " ISBN: ";
	gotoXY(boxx + boxs + 1, boxy + 2); cout << char(186);
	gotoXY(boxx, boxy + 3); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 3); cout << char(186);
	gotoXY(boxx, boxy + 4); cout << char(186) << " Ten Sach: ";
	gotoXY(boxx + boxs + 1, boxy + 4); cout << char(186);
	gotoXY(boxx, boxy + 5); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 5); cout << char(186);
	gotoXY(boxx, boxy + 6); cout << char(186) << " So Trang: ";
	gotoXY(boxx + boxs + 1, boxy + 6); cout << char(186);
	gotoXY(boxx, boxy + 7); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 7); cout << char(186);
	gotoXY(boxx, boxy + 8); cout << char(186) << " Tac Gia: ";
	gotoXY(boxx + boxs + 1, boxy + 8); cout << char(186);
	gotoXY(boxx, boxy + 9); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 9); cout << char(186);
	gotoXY(boxx, boxy + 10); cout << char(186) << " Nam XB: ";
	gotoXY(boxx + boxs + 1, boxy + 10); cout << char(186);
	gotoXY(boxx, boxy + 11); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 11); cout << char(186);
	gotoXY(boxx, boxy + 12); cout << char(186) << " The Loai: ";
	gotoXY(boxx + boxs + 1, boxy + 12); cout << char(186);
	gotoXY(boxx, boxy + 13); cout << char(200);
	for (int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(188);
}
void xoa_hien_thi_Box_NhapDS()
{
	int x = whereX(), y = whereY();
	TextColor(15);
	gotoXY(boxx, boxy); cout << " ";
	for (int i = 1; i < boxs + 1; i++) cout << " ";
	cout << " ";
	gotoXY(boxx, boxy + 1); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 1); cout << " ";
	gotoXY(boxx, boxy + 2); cout << "                                            ";
	gotoXY(boxx + boxs + 1, boxy + 2); cout << " ";
	gotoXY(boxx, boxy + 3); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 3); cout << " ";
	gotoXY(boxx, boxy + 4); cout << "                                            ";
	gotoXY(boxx + boxs + 1, boxy + 4); cout << " ";
	gotoXY(boxx, boxy + 5); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 5); cout << " ";
	gotoXY(boxx, boxy + 6); cout << "                                            ";
	gotoXY(boxx + boxs + 1, boxy + 6); cout << " ";
	gotoXY(boxx, boxy + 7); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 7); cout << " ";
	gotoXY(boxx, boxy + 8); cout << "                                            ";
	gotoXY(boxx + boxs + 1, boxy + 8); cout << " ";
	gotoXY(boxx, boxy + 9); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 9); cout << " ";
	gotoXY(boxx, boxy + 10); cout << "                                            ";
	gotoXY(boxx + boxs + 1, boxy + 10); cout << " ";
	gotoXY(boxx, boxy + 11); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 11); cout << " ";
	gotoXY(boxx, boxy + 12); cout << "                                            ";
	gotoXY(boxx + boxs + 1, boxy + 12); cout << " ";
	gotoXY(boxx, boxy + 13); cout << " ";
	for (int i = 1; i < boxs + 1; i++) cout << " ";
	cout << " ";
	gotoXY(x, y);
}
void Box_NhapSach()
{
	int boxtemp = boxs - 40;
	ButtonEnter(boxx + boxtemp - 5, boxy + 15);
	ButtonESC(boxx, boxy + 15);
	TextColor(15);
	gotoXY(boxx, boxy); cout << char(201);
	for (int i = 1; i < boxtemp + 1; i++) cout << char(205);
	cout << char(187);
	gotoXY(boxx, boxy + 1); cout << char(186);
	gotoXY(boxx + boxtemp + 1, boxy + 1); cout << char(186);
	gotoXY(boxx, boxy + 2); cout << char(186) << " MA SACH: ";
	gotoXY(boxx + boxtemp + 1, boxy + 2); cout << char(186);
	gotoXY(boxx, boxy + 3); cout << char(186);
	gotoXY(boxx + boxtemp + 1, boxy + 3); cout << char(186);
	gotoXY(boxx, boxy + 4); cout << char(186) << " VI TRI: ";
	gotoXY(boxx + boxtemp + 1, boxy + 4); cout << char(186);
	gotoXY(boxx, boxy + 5); cout << char(186);
	gotoXY(boxx + boxtemp + 1, boxy + 5); cout << char(186);
	gotoXY(boxx, boxy + 6); cout << char(200);
	for (int i = 1; i < boxtemp + 1; i++) cout << char(205);
	cout << char(188);
}
void xoa_hien_thi_Box_NhapSach()
{
	int x = whereX(), y = whereY();
	int boxtemp = boxs - 40;
	xoa_hien_thi_1_Button(boxx + boxtemp - 5, boxy + 15);
	xoa_hien_thi_1_Button(boxx, boxy + 15);
	TextColor(15);
	gotoXY(boxx, boxy); cout << " ";
	for (int i = 1; i < boxtemp + 1; i++) cout << " ";
	cout << " ";
	gotoXY(boxx, boxy + 1); cout << " ";
	gotoXY(boxx + boxtemp + 1, boxy + 1); cout << " ";
	gotoXY(boxx, boxy + 2); cout << "            ";
	gotoXY(boxx + boxtemp + 1, boxy + 2); cout << " ";
	gotoXY(boxx, boxy + 3); cout << " ";
	gotoXY(boxx + boxtemp + 1, boxy + 3); cout << " ";
	gotoXY(boxx, boxy + 4); cout << "          ";
	gotoXY(boxx + boxtemp + 1, boxy + 4); cout << " ";
	gotoXY(boxx, boxy + 5); cout << " ";
	gotoXY(boxx + boxtemp + 1, boxy + 5); cout << " ";
	gotoXY(boxx, boxy + 6); cout << " ";
	for (int i = 1; i < boxtemp + 1; i++) cout << " ";
	cout << " ";
	gotoXY(x, y);
}

int Dem_Sach_CON_MUON_DUOC(LIST_DS l, string ISBN)
{
	int i = TIM_KIEM_DS_THEO_MA(l, ISBN);
	if (l.ds_dausach[i]->soluongsach == 0) return 0;
	int n = 0;
	if (i != -1)
	{
		for (node_danhmucsach* p = l.ds_dausach[i]->dms.pHead; p != NULL; p = p->pNext)
			if (p->data.trangthai == 0)
				n++;
	}
	return n;
}

// Boxx + 20 Boxy =15
void Box_NHAP(string x)
{
	int tungdo = 15;
	int boxtemp = 50;
	TextColor(252);
	gotoXY(boxx + 20, tungdo); cout << char(201);
	for (int i = 1; i < boxtemp + 1; i++) cout << char(205);
	cout << char(187);
	TextColor(252);
	gotoXY(boxx + 20, tungdo + 1); cout << "                                                    ";
	gotoXY(boxx + 20, tungdo + 1); cout << char(186);
	gotoXY(boxx + 20 + boxtemp + 1, tungdo + 1);  cout << char(186);
	gotoXY(boxx + 20, tungdo + 2); cout << "                                                    ";
	gotoXY(boxx + 20, tungdo + 2); cout << char(186); TextColor(249); cout << x << ": ";
	int x1 = whereX(), y1 = whereY();
	TextColor(252);
	gotoXY(boxx + 20 + boxtemp + 1, tungdo + 2); cout << char(186);
	gotoXY(boxx + 20, tungdo + 3); cout << "                                                    ";
	gotoXY(boxx + 20, tungdo + 3); cout << char(186);
	gotoXY(boxx + 20 + boxtemp + 1, tungdo + 3); cout << char(186);
	gotoXY(boxx + 20, tungdo + 4); cout << char(200);
	for (int i = 1; i < boxtemp + 1; i++) cout << char(205);
	cout << char(188);
	TextColor(15);
	gotoXY(x1, y1);
}
void Xoa_hien_thi_Box_NHAP()
{
	int x = whereX();
	int y = whereY();
	int tungdo = 15;
	int boxtemp = 50;
	TextColor(7);
	gotoXY(boxx + 20, tungdo); cout << " ";
	for (int i = 1; i < boxtemp + 1; i++) cout << " ";
	cout << " ";
	TextColor(7);
	gotoXY(boxx + 20, tungdo + 1); cout << "                                                    ";
	gotoXY(boxx + 20, tungdo + 1); cout << " ";
	gotoXY(boxx + 20 + boxtemp + 1, tungdo + 1);  cout << " ";
	gotoXY(boxx + 20, tungdo + 2); cout << "                                                    ";
	gotoXY(boxx + 20, tungdo + 2); cout << "                                                    ";
	gotoXY(boxx + 20 + boxtemp + 1, tungdo + 2); cout << " ";
	gotoXY(boxx + 20, tungdo + 3); cout << "                                                    ";
	gotoXY(boxx + 20, tungdo + 3); cout << " ";
	gotoXY(boxx + 20 + boxtemp + 1, tungdo + 3); cout << " ";
	gotoXY(boxx + 20, tungdo + 4); cout << " ";
	for (int i = 1; i < boxtemp + 1; i++) cout << " ";
	cout << " ";
	gotoXY(x, y);
}
// rt true nếu độc giả đang mượn cuốn sách có đầu sách tương tự <> false
bool KT_SACH_DG_MUON(TREE p, string ma_sach)
{
	string s = tach_ma_sach(ma_sach);
	string temp;
	if (p->data.tongsosach > 0)
	{
		for (NODE_MT* q = p->data.mt.pHead; q != NULL; q = q->pNext)
		{
			if (q->data.trangthai == 0) // đang mượn sách
			{
				temp = tach_ma_sach(q->data.masach);
				if (temp == s) // đang mượn cuốn sách có đầu sách tương tự
					return true;
			}
		}
	}
	return false;
}