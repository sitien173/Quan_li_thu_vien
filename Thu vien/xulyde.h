﻿#pragma once 
#include "ctdl.h"
#include "hotro.h"
#include "doc_ghi_file.h"
//=============================================Khoi tao===============================
void khoi_tao_muontra(LIST_MT& l)
{
	l.pHead = l.pTail = NULL;
}
void khoi_tao_cay(TREE& t)
{
	t = NULL;
}
void khoi_tao_dau_sach(LIST_DS& l)
{
	l.sl = 0;
}
void khoi_tao_sach(LIST_DMS& l)
{
	l.pHead = l.pTail = NULL;
}

// ======================================Doc gia========================================================

int nhap_doc_gia(docgia& x);// nhập thành công rt 1 <> esc rt -2
int them_doc_gia_vao_ds(TREE& t); // Thêm độc giả vào danh sách thêm thành công rt 1 < > return -2
void them_node_vao_cay(TREE& t, docgia x);
void Xuat_Thong_Tin_Doc_Gia(docgia a, int tungdo);// Xuất thông tin của 1 độc giả
void xuat_ds_thong_tin_doc_gia(TREE t, int& i);//duyet theo LNR in ra ma the tang dan
void chuyen_cay_sang_mang(TREE t, docgia * arr, int& i);// duyệt cây copy dữ liệu vào mảng
void sap_xep_doc_gia_theo_ten(docgia* arr, int n);// sắp xếp độc giả theo tên + họ tăng dần
void tim_kiem_pt_the_mang(TREE& p, TREE& q);//Phần tử p đang được thế mạng cho phần tử q
void xoa_theo_ma_doc_gia(TREE& t, int x);// hàm có chức năng xóa 1 độc giả bất kì theo mã độc giả
TREE tim_kiem_docgia_ma(TREE& t, int ma_doc_gia);// tìm kiếm độc giả trong danh sách với mã độc giả
void tim_kiem_ds_doc_gia_ten(TREE t, string ch1, int& tungdo);// tìm kiếm tên độc giả
int sua_thong_tin_doc_gia(TREE& t, int ma_doc_gia);// hiệu chỉnh thông tin độc giả thành công rt 1 <> ESC rt -2
int SoluongDG(TREE t);// đếm số đọc giả trong cây

//========================================== Đau Sach ==================================================

int nhap_DauSach(LIST_DS& l, dausach& data);// thêm đầu sách nếu thêm thành công rt 1 <> ESC rt -2
void xuat_dau_sach(dausach& a, int tungdo);// in ra 1 đầu sách
void them_vao_ds_dausach(LIST_DS& l, dausach data);// Thêm đầu sách vào danh sách đầu sách để quản lí
void them_vao_ds_dausach(LIST_DS& l, dausach data);// Thêm đầu sách vào danh sách đầu sách để quản lí
void sap_xep_theo_theloai_dausach(LIST_DS& l);// sắp xếp đầu sách theo thể loại
void xuat_ds_dausach(LIST_DS& l);// in danh sach theo the loai
int tim_kiem_dau_sach_theo_ten(LIST_DS l, string temp);// tim kiếm đầu sách theo tên đầu sách nếu có xuất ra đầu sách <> -1;
int tim_kiem_dau_sach_theo_ma(LIST_DS l, string ma);// tìm kiếm đầu sách theo mã đầu sách nêu có trả về vị trí <> -1
int sua_dau_sach(LIST_DS& l);// sửa đầu sách theo mã đầu sách. Nếu sửa thành công return 1 <> -1 ;ESC return -2
int xoa_dau_sach(LIST_DS& l, string ma_dau_sach);// xóa đầu sách thành công return 1 <> return -1

//=========================================Danh muc sach===============================================
NODE_DMS* tao_node_sach(danhmucsach& x);// tạo 1 node mới 
int them_sach(LIST_DS& l);// Thêm sách nếu thêm thành công rt 1 <> -1 ; ESC rt -2;
void them_sach_vao_ds(LIST_DMS& l, NODE_DMS* p);// thêm sách vào danh sách sách để quản lí
void xuat_sach1(string ten_sach, danhmucsach a, int tungdo);// xuất 1 cuốn sách
void xuat_ds_sach1(LIST_DS l);// xuất các sách có trong danh sách sách
int tim_kiem_sach_ten(LIST_DS l, string ten_sach);// tim kiem sach theo ten sach nếu thấy in ra. nếu không trả về -1
NODE_DMS* tim_kiem_sach(LIST_DS l, string ma_sach);// tìm kiếm sách theo mã sách nếu có trả về  vị trí node trong ds <>  NULL
int xoa_sach(LIST_DS& l, string ma_sach);// xóa sách theo mã đầu sách. Xóa thành công rt 1 <> -1
int hieu_chinh_sach(danhmucsach& a, string ma_sach);// hiệu chỉnh sách theo mã sách . hiệu chỉnh thành công rt 1 <> -1 ; ESC rt -2

//==========================================Muon tra===================================================

NODE_MT* tao_node_muontra(muontra x);// tạo 1 node mượn trả 
void them_phieu_muon(muontra& x);// lập phiếu mượn sách
void xuat_thong_tin_phieu_muontra(muontra a, string ten_sach, int tungdo);// in thong tin của 1 phiếu mượn trả
void them_vao_ds_muontra(LIST_MT& l, NODE_MT* p);// thêm phiếu vào danh sách để quản lí
int xuat_sach_dang_muon(TREE t, LIST_DS l);// hàm có chức năng xuất các sách đang mượn của 1 độc giả nếu có sách mượn rt 1 <> 0
int tim_kiem_doc_gia_qua_han(LIST_QUAHAN& l, int ma_doc_gia);// kiểm tra độc giả quá hạn trong danh sách quá hạn nếu số ngày quá hạn > 7 tra ve so ngay quahan <> 0
int dem_sach_docgia_muon(TREE t);// đếm số sách độc giả đang mượn dùng để kiểm tra điều kiện mượn sách 
int muonsach(TREE& t, LIST_DS& l);// mượn thành công tr 1 <> -1 ; esc rt -2
int trasach(TREE& t, LIST_DS& l);// trả sách thành công tr 1 <> -1 ; ESC rt -2

// =========================================== Qua Han ================================
void ds_quahan(TREE t, LIST_QUAHAN& l);// in ra danh sách các độc giả quá hạn

// =================== 10 sách có lượt mượn nhiều nhất ====================
void top10sach(LIST_DS l);

// ========================================== Độc Giả==========================================

// nhập thành công rt 1 <> esc rt -2
int nhap_doc_gia(docgia& x)
{
	cout << "Ma the: " << x.mathe << endl;
	cout << "Nhap ho doc gia: ";
	x.ho = nhap_ki_tu();
	if (x.ho == "-1") // ESC
		return -2;
	cout << "Nhap ten doc gia: ";
	x.ten = nhap_ki_tu();
	if (x.ten == "-1") // ESC
		return -2;
	cout << "Nhap gioi tinh doc gia: ";
	x.phai = nhap_gioitinh();
	if (x.phai == "-1") // ESC
		return -2;
	x.trangthaithe = 1; // trạng thái lúc thêm độc giả auto =1. có thể mượn sách
	cout << "Trang thai the: " << x.trangthaithe << endl;
	x.tongsosach = 0;
	return 1;
}
// Thêm độc giả vào danh sách thêm thành công rt 1 <> -1 ESC rt -2
int them_doc_gia_vao_ds(TREE& t)
{
	docgia x;
	ifstream filein("MADOCGIA.txt");
	ofstream filetemp("Temp.txt");
	filein >> x.mathe;
	int i = nhap_doc_gia(x);
	if ( i== -2) // ESC
			return -2;
	else
	{
		them_node_vao_cay(t, x);
		int temp;
		while (filein >> temp)
		{
			if (temp != x.mathe)
				filetemp << temp << endl;
		}
		filein.close();
		filetemp.close();
		remove("MADOCGIA.txt");
		rename("Temp.txt", "MADOCGIA.txt");
		return 1;
	}
	
}

// them 1 node vao cay theo ma doc gia 
void them_node_vao_cay(TREE& t,docgia x)
{
	if (t == NULL)
	{
		t = new NODE_DG;
		if (t == NULL) return;
		t->data = x;
		t->pLeft = t->pRight = NULL;
	}
	else
	{
		if (x.mathe < t->data.mathe)
			them_node_vao_cay(t->pLeft, x);
		else if (x.mathe > t->data.mathe)
			them_node_vao_cay(t->pRight, x);
	}
}

// Xuất thông tin của 1 độc giả
void Xuat_Thong_Tin_Doc_Gia(docgia a, int tungdo)
{
	int x = whereX();
	int y = whereY();
		gotoXY(45, 0);
		cout << "Ma Doc Gia";
		gotoXY(65, 0);
		cout << "Ho va Ten";
		gotoXY(90, 0);
		cout << "Phai";
		gotoXY(100, 0);
		cout << "Trang Thai The";
		gotoXY(45, tungdo);
		cout << a.mathe;
		gotoXY(65, tungdo);
		cout << a.ho << " " << a.ten;
		gotoXY(90, tungdo);
		cout << a.phai;
		gotoXY(107, tungdo);
		cout << a.trangthaithe;
	gotoXY(x, y);
}

//duyet theo LNR in ra ma the tang dan
void xuat_ds_thong_tin_doc_gia(TREE t, int& i)
{
	TREE Stack[STACKSIZE];
	int top = -1;
	do
	{
		while (t != NULL)
		{
			Stack[++top] = t; // push vào Stack
			t = t->pLeft;
		}
		if (top != -1)
		{
			t = Stack[top--]; // pop Stack
			if (i <= 40)
			{
				Xuat_Thong_Tin_Doc_Gia(t->data, ++i);
			}
			else
			{
				ButtonNext();
				char c = _getch();
				if (c == -32)
					c = _getch();
				if (c == 27) // ESC
				{
					xoa_hienthi_buttonNext();
					return;
				}
				else if (c == 77)
				{
					i = 0;
					xoa_hien_thi_doc_gia();
					Xuat_Thong_Tin_Doc_Gia(t->data, ++i);
				}
			}
			t = t->pRight;
		}
		else
			break;
	} while (1);
	TextColor(7);
}

// duyệt cây copy dữ liệu vào mảng
void chuyen_cay_sang_mang(TREE t, docgia* arr, int& i)
{
	if (t != NULL)
	{
		arr[i++] = t->data;
		chuyen_cay_sang_mang(t->pLeft, arr, i);
		chuyen_cay_sang_mang(t->pRight, arr, i);
	}// nếu cây rỗng thoát hàm
	else
		return;
}

// sắp xếp độc giả theo tên + họ tăng dần
void sap_xep_doc_gia_theo_ten(docgia* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{  // kiểm tra tên 2 đg
			if (arr[i].ten > arr[j].ten)
			{
				// hoán đổi vị trí
				hoandoi(arr[i], arr[j]);
			} // ngược lại
			else if(arr[i].ten == arr[j].ten)
			{ // kiểm tra họ 2 đg
				if (arr[i].ho < arr[j].ho)
				{ // hoán đổi vị trí
					hoandoi(arr[i], arr[j]);
				}
			}
		}
	}
}

//Phần tử p đang được thế mạng cho phần tử q
void tim_kiem_pt_the_mang(TREE& p, TREE& q)
{
	// duyệt đến phần tử trái nhất của cây
	if (q->pLeft != NULL)
	{
		tim_kiem_pt_the_mang(p, q->pLeft);
	}
	// đã tìm được phần tử thế mạng
	else
	{
		p->data = q->data;
		p = q;
		q = q->pRight;
	}
}

// hàm có chức năng xóa 1 độc giả bất kì theo mã độc giả
void xoa_theo_ma_doc_gia(TREE& t, int x)
{
	if (t != NULL)
	{
		// duyệt cây để tìm phần tử cần xóa
		if (t->data.mathe < x)
		{
			xoa_theo_ma_doc_gia(t->pRight, x);
		}
		else if (t->data.mathe > x)
		{
			xoa_theo_ma_doc_gia(t->pLeft, x);
		}
		// đã tìm được mã độc giả
		else
		{
			if (t->data.tongsosach > 0)
			{
				for (NODE_MT* p = t->data.mt.pHead; p != NULL; p = p->pNext)
				{
					if (p->data.trangthai == 0) // độc giả đang mượn sách
					{
						BaoLoi("DOC GIA DANG CON SACH MUON.KHONG THE XOA");
						return;
					}
				}
			}
			NODE_DG* p = t;
			// xóa node có 1 con hoặc không có con nào
			if (t->pLeft == NULL) // cây con phải
			{
				t = t->pRight;
			}
			else if (t->pRight == NULL) // cây con trái
			{
				t = t->pLeft;
			}
			// xóa node có 2 con.Trái nhất của cây con phải
			else
			{
				// trái nhất của cây con phải
				tim_kiem_pt_the_mang(p, t->pRight);
			}
			delete p;
			BaoLoi("Xoa Thanh Cong");
		}

	}
}

// tìm kiếm độc giả trong danh sách với mã độc giả
TREE tim_kiem_docgia_ma(TREE& t, int ma_doc_gia)
{
	if (t)
	{
		if (t->data.mathe == ma_doc_gia)
			return t;
		else if (t->data.mathe < ma_doc_gia)
			return tim_kiem_docgia_ma(t->pRight, ma_doc_gia);
		else
			return tim_kiem_docgia_ma(t->pLeft, ma_doc_gia);
	}
	return NULL;
}

// tìm kiếm tên độc giả
void tim_kiem_ds_doc_gia_ten(TREE t, string ch1, int& tungdo)
{
	if (t != NULL)
	{
		// ch1 là chuỗi con của tên độc giả
		if (t->data.ten.find(ch1) != string::npos)
		{
			TextColor(15);
			if(tungdo==1)
			xoa_hien_thi_doc_gia();
			Xuat_Thong_Tin_Doc_Gia(t->data, tungdo);
			tungdo++;
		}
		tim_kiem_ds_doc_gia_ten(t->pLeft, ch1, tungdo);
		tim_kiem_ds_doc_gia_ten(t->pRight, ch1, tungdo);
	}
	
	TextColor(7);
	return;
}

// hiệu chỉnh thông tin độc giả thành công rt 1 <> ESC rt -2
int sua_thong_tin_doc_gia(TREE& t, int ma_doc_gia)
{
	xoa_hien_thi_doc_gia();
	TREE p = tim_kiem_docgia_ma(t, ma_doc_gia);
	if (p == NULL)
	{
		BaoLoi("Ma Doc Gia Khong Ton Tai");
		return 0;
	}
	else
	{
		docgia x;
		int tungdo = 1;
		Xuat_Thong_Tin_Doc_Gia(p->data,tungdo);
		TextColor(15);
		cout << "Ma the: " << p->data.mathe << endl;
		cout << "Ho: ";
		x.ho = nhap_ki_tu();
		if (x.ho == "-1") // ESC
			return -2;
		cout << "Ten: ";
		x.ten = nhap_ki_tu();
		if (x.ten == "-1") // ESC
			return -2;
		cout << "Phai: ";
		x.phai = nhap_gioitinh();
		if (x.phai == "-1") // ESC
			return -2;
		cout << "Trang thai the: ";
		x.trangthaithe = nhap_so_nguyen();
		if (x.trangthaithe == -1) // ESC
			return -2;
		p->data.ho = x.ho;
		p->data.ten = x.ten;
		p->data.phai = x.phai;
		p->data.trangthaithe = x.trangthaithe;
		TextColor(7);
	}
	return 1;
}

// đếm số đọc giả trong cây
int SoluongDG(TREE t)
{
	int n = 0;
	TREE Stack[STACKSIZE];
	int top = -1;
	do
	{
		while (t != NULL)
		{
			Stack[++top] = t;
			t = t->pLeft;
		}
		if (top != -1)
		{
			t = Stack[top--];
			n++;
			t = t->pRight;
		}
		else break;
	} while (1);
	return n;
}

// =========================================Dau sach==============================================

// thêm đầu sách nếu thêm thành công rt 1 <> ESC rt -2
int nhap_DauSach(LIST_DS& l, dausach& data)
{
	while (1)
	{
		cout << "Ma ISBN : ";
		data.ISBN = nhap_ki_tu1();
		if (data.ISBN == "-1") // ESC
			return -2;
		if (tim_kiem_dau_sach_theo_ma(l, data.ISBN) != -1)
		{
			BaoLoi("Ma ISBN bi trung vui long nhap lai");
			continue;
		}
		cout << "Ten Sach: ";
		data.tensach = nhap_ki_tu1();
		if (data.tensach == "-1") // ESC
			return -2;
		cout << "So Trang: ";
		data.sotrang = nhap_so_nguyen();
		if (data.sotrang == -1) // ESC
			return -2;
		cout << "Tac Gia: ";
		data.tacgia = nhap_ki_tu();
		if (data.tacgia == "-1") // ESC
			return -2;
		cout << "Nam Xuat Ban: ";
		data.namxuatban = nhap_so_nguyen();
		if (data.namxuatban == -1) // ESC
			return -2;
		cout << "The Loai: ";
		data.theloai = nhap_ki_tu();
		if (data.theloai == "-1") // ESC
			return -2;
		data.soluongmuon = 0;
		data.soluongsach = 0;
		return 1;
	}
}

// in ra 1 đầu sách
void xuat_dau_sach(dausach& a, int tungdo)
{
	int x = whereX();
	int y = whereY();
	gotoXY(40, 0);
	cout << "Ma Dau Sach";
	gotoXY(55, 0);
	cout << "Ten sach";
	gotoXY(95, 0);
	cout << "So trang";
	gotoXY(105, 0);
	cout << "Tac gia";
	gotoXY(145, 0);
	cout << "Nam XB";
	gotoXY(155, 0);
	cout << "The Loai";
	gotoXY(40, tungdo);
	cout << a.ISBN;
	gotoXY(55, tungdo);
	cout << a.tensach;
	gotoXY(95, tungdo);
	cout << a.sotrang;
	gotoXY(105, tungdo);
	cout << a.tacgia;
	gotoXY(145, tungdo);
	cout << a.namxuatban;
	gotoXY(155, tungdo);
	cout << a.theloai;
	gotoXY(x, y);
}

 // Thêm đầu sách vào danh sách đầu sách để quản lí
void them_vao_ds_dausach(LIST_DS& l, dausach data)
{	  // nếu còn thêm được
		if (l.sl < MAX)
		{
			l.ds_dausach[l.sl] = new dausach;
			*l.ds_dausach[l.sl] = data;
			l.sl++;
		}
}

// sắp xếp đầu sách theo thể loại
void sap_xep_theo_theloai_dausach(LIST_DS& l)
{
	for (int i = 0; i < l.sl - 1; i++)
	{
		for (int j = i + 1; j < l.sl; j++)
		{
			if (l.ds_dausach[i]->theloai[0] > l.ds_dausach[j]->theloai[0])
			{
				if (l.ds_dausach[i]->tensach[0] > l.ds_dausach[j]->tensach[0])
				{
					swap(l.ds_dausach[i], l.ds_dausach[j]);
				}
			}
		}
	}
}

// in danh sach theo the loai
void xuat_ds_dausach(LIST_DS& l)
{
	TextColor(15);
	sap_xep_theo_theloai_dausach(l);
	for (int i = 0; i < l.sl; i++)
	{
		if (i < 40)
			xuat_dau_sach(*l.ds_dausach[i], i + 1);
		else
		{
			ButtonNext();
			char c = _getch();
			if (c == -32)
				c = _getch();
			if (c == 77)
			{
				xoa_hien_thi_dausach();
				for (int j = i,tungdo=1; tungdo < 40 && j < l.sl; j++,tungdo++)
				{
					xuat_dau_sach(*l.ds_dausach[j], tungdo);
					i = j;
				}
			}
			else
			{
				return;
			}
		}
	}
	TextColor(7);
}

// tim kiếm đầu sách theo tên đầu sách nếu có xuất ra đầu sách <> -1;
int tim_kiem_dau_sach_theo_ten(LIST_DS l, string temp)
{
	int kt = 0; // biến dùng để kiểm tra có tìm được đầu sách hay ko
	int tungdo = 0;
	xoa_hien_thi_dausach();
	for (int i = 0; i < l.sl; i++)
	{
		// nếu tìm thấy temp là chuỗi con của tên đầu sách
		if (l.ds_dausach[i]->tensach.find(temp) != string::npos)
		{
			TextColor(14);
			xuat_dau_sach(*l.ds_dausach[i],++tungdo);
			kt = 1;
			continue;
		}
	}
	TextColor(7);
	if (kt == 0)
		return -1;
}

// tìm kiếm đầu sách theo mã đầu sách nêu có trả về vị trí <> -1
int tim_kiem_dau_sach_theo_ma(LIST_DS l, string ma)
{
	for (int i = 0; i < l.sl; i++)
	{
		if (l.ds_dausach[i]->ISBN == ma)
			return i;
	}
	return -1;
}

// sửa đầu sách theo mã đầu sách. Nếu sửa thành công return 1 <> -1 ;ESC return -2
int sua_dau_sach(LIST_DS& l)
{
	string ma_dau_sach;
	do
	{
		gotoXY(1, 10);
		cout << "                             ";
		gotoXY(1, 10);
		cout << "Nhap Ma Dau Sach: ";
		ma_dau_sach = nhap_ki_tu1();
		if (ma_dau_sach == "-1") // ESC
		{
			return -2;
		}
		int i = tim_kiem_dau_sach_theo_ma(l, ma_dau_sach);
		// nếu tìm kiếm thất bại
		if (i == -1)
		{
			BaoLoi("Ma Dau Sach Khong Ton Tai");
			return -1;
		}
		cout << "Ten sach: ";
		l.ds_dausach[i]->tensach = nhap_ki_tu1();
		if (l.ds_dausach[i]->tensach == "-1") // ESC
		{
			return -2;
		}
		cout << "So trang: ";
		l.ds_dausach[i]->sotrang = nhap_so_nguyen();
		if (l.ds_dausach[i]->sotrang == -1) // ESC
		{
			return -2;
		}
		cout << "Tac gia: ";
		l.ds_dausach[i]->tacgia = nhap_ki_tu();
		if (l.ds_dausach[i]->tacgia == "-1") // ESC
		{
			return -2;
		}
		cout << "Nam xuat ban: ";
		l.ds_dausach[i]->namxuatban = nhap_so_nguyen();
		if (l.ds_dausach[i]->namxuatban == -1) // ESC
		{
			return -2;
		}
		cout << "The loai: ";
		l.ds_dausach[i]->theloai = nhap_ki_tu();
		if (l.ds_dausach[i]->theloai == "-1") // ESC
		{
			return -2;
		}
		BaoLoi("Sua thanh cong.");
		return 1;
	} while (1);
}

// xóa đầu sách thành công return 1 <> return -1
int xoa_dau_sach(LIST_DS& l, string ma_dau_sach)
{
	int i = tim_kiem_dau_sach_theo_ma(l, ma_dau_sach);
	if (i == -1)
	{
		return -1;
	}
	delete l.ds_dausach[i];
	for (; i < l.sl; i++)
	{
		l.ds_dausach[i] = l.ds_dausach[i + 1];
	}l.sl--;

	return 1;
}


// =========================================Danh muc sach=====================================
// tạo 1 node mới 
NODE_DMS* tao_node_sach(danhmucsach& x)
{
	node_danhmucsach* p = new node_danhmucsach;
	if (p == NULL)
	{
		BaoLoi("Khong du bo nho cap phat");
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
// Thêm sách nếu thêm thành công rt 1 <> -1 ; ESC rt -2;
int them_sach(LIST_DS& l)
{
	string ma_dau_sach;
	cout << "\nNhap Ma Dau Sach: ";
	ma_dau_sach = nhap_ki_tu1();
	if (ma_dau_sach == "-1") // ESC
		return -2;
	int i = tim_kiem_dau_sach_theo_ma(l, ma_dau_sach);
	if (i == -1) // Khong tim thay
	{
		BaoLoi("Ma Dau Sach Khong Ton Tai");
		return -1;
	}
	int n;
	cout << "So Luong Sach Can Them : ";
	n = nhap_so_nguyen();
	if (n == -1) // ESC
		return -2;
	string temp;
	cout << "Them Vao Vi Tri: ";
	temp = nhap_ki_tu1();
	if (temp == "-1") // ESC
		return -2;
	danhmucsach x;
	// lược bỏ phần mã đầu sách
	int q = 0;
	if (l.ds_dausach[i]->dms.pTail != NULL)
	{
		string str;
		size_t pos = l.ds_dausach[i]->dms.pTail->data.masach.find("-"); // lấy vị trí của kí tự - trong chuỗi
		str = l.ds_dausach[i]->dms.pTail->data.masach.substr(pos+1); //  lấy chuỗi con của l.ds_dausach[i]->dms.pTail->data.masach bắt đầu sau kí tự -
		q = chuoi_sang_so(str);
	}
	for (int j = 0; j < n; j++)
	{
		if (q == 0)
			x.masach = l.ds_dausach[i]->ISBN + "-" + so_sang_chuoi(j + 1);
		else
			x.masach = l.ds_dausach[i]->ISBN + "-" + so_sang_chuoi(q+j + 1);
		x.vitri = temp;
		x.trangthai = 0; // mặc định sách có thể mượn được
		them_sach_vao_ds(l.ds_dausach[i]->dms, tao_node_sach(x));
		l.ds_dausach[i]->soluongsach++;
	}
	return 1;
}

// thêm sách vào danh sách sách để quản lí
void them_sach_vao_ds(LIST_DMS& l, NODE_DMS* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

// xuất 1 cuốn sách
void xuat_sach1(string ten_sach, danhmucsach a, int tungdo)
{
	int x = whereX();
	int y = whereY();
	gotoXY(45, 0);
	cout << "Ma Sach";
	gotoXY(65, 0);
	cout << "Ten Sach";
	gotoXY(95, 0);
	cout << "Trang Thai";
	gotoXY(110, 0);
	cout << "Vi Tri";
	gotoXY(45, tungdo);
	cout << a.masach;
	gotoXY(65, tungdo);
	cout << ten_sach;
	gotoXY(95, tungdo);
	cout << a.trangthai;
	gotoXY(110, tungdo);
	cout << a.vitri;
	gotoXY(x, y);
}

// xuất các sách có trong danh sách sách
void xuat_ds_sach1(LIST_DS l)
{
	for (int i = 0; i < l.sl; i++)
	{
		int j = 1; // tung độ xuất sách
		xoa_hien_thi_sach();
		for (NODE_DMS* p = l.ds_dausach[i]->dms.pHead; p != NULL; )
		{
			if (j < 40)
			{
				Sleep(500);
				xuat_sach1(l.ds_dausach[i]->tensach, p->data, j++);
				if (p != l.ds_dausach[i]->dms.pTail)
					p = p->pNext;
				else // nếu p là node cuối thoát vòng lặp tăng i lên 1
				{
					ButtonNext();
					char c = _getch();
					if (c == -32)
						c = _getch();
					if (c == 77)
						break;
					else
					{
						return;
					}
				}
			}
			else if (j >=40 )
			{
				do
				{
					//xuat_sach1(l.ds_dausach[i]->tensach, p->data, j++);
					ButtonNext();
					char c = _getch();
					if (c == -32)
						c = _getch();
					if (c == 77)
					{
						xoa_hien_thi_sach();
						for (j = 0; j < 40; j++)
						{
							Sleep(500);
							xuat_sach1(l.ds_dausach[i]->tensach, p->data, j + 1);
							if (p != l.ds_dausach[i]->dms.pTail)
								p = p->pNext;
							else
								return;
						}
						break;
					}
					return ;
				} while (1);
			}
		}
	}
}

// tim kiem sach theo ten sach nếu thấy in ra. nếu không trả về -1 , ESC rt -2
int tim_kiem_sach_ten(LIST_DS l, string ten_sach)
{
	int kt = 0; // biến dùng để kiểm tra có tìm thấy hay ko. Nếu thấy tăng kt lên <> =0
	int tungdo = 0;
	xoa_hien_thi_sach();
	for (int i = 0; i < l.sl; i++)
	{
		if (l.ds_dausach[i]->tensach.find(ten_sach) != string::npos)
		{
			kt++; // tăng kt để biết đã tìm thấy
			TextColor(15);
			for (NODE_DMS* p = l.ds_dausach[i]->dms.pHead; p != NULL;)
			{
				if (tungdo < 40)
				{
						xuat_sach1(l.ds_dausach[i]->tensach, p->data, ++tungdo);
					// p chưa là node cuối
					if (p != l.ds_dausach[i]->dms.pTail)
							p = p->pNext;
					else // nếu p là node cuối thoát vòng lặp tăng i lên 1
					{
						xuat_sach1(l.ds_dausach[i]->tensach, p->data, ++tungdo);
						p = p->pNext;
							ButtonNext();
							char c = _getch();
							if (c == -32)
								c = _getch();
							if (c == 77)
								break;
							if (c == 27)
								return -2;
					}
				}
				else if (tungdo >= 40)
				{
						ButtonNext();
						char c = _getch();
						if (c == -32)
							c = _getch();
						if (c == 77)
						{
							xoa_hien_thi_sach();
							for (tungdo = 0; tungdo < 40; tungdo++)
							{
								xuat_sach1(l.ds_dausach[i]->tensach, p->data, tungdo + 1);
								if (p != l.ds_dausach[i]->dms.pTail)
									p = p->pNext;
								else
								{
									xuat_sach1(l.ds_dausach[i]->tensach, p->data, tungdo + 1);
									p = p->pNext;
									break;
								}
							}
						}
						else if(c==27)
						return -2;
				}
			}
		}
	}
	TextColor(7);
	if (kt == 0)
		return -1;
}

// tìm kiếm sách theo mã sách nếu có trả về  vị trí node trong ds <>  NULL
NODE_DMS* tim_kiem_sach(LIST_DS l, string ma_sach)
{
	for (int i = 0; i < l.sl; i++)
	{
		for (NODE_DMS* p = l.ds_dausach[i]->dms.pHead; p != NULL; p = p->pNext)
		{
			if (p->data.masach == ma_sach)
				return p;
		}
	}
	return NULL;
}

// xóa sách theo mã đầu sách. Xóa thành công rt 1 <> -1
int xoa_sach(LIST_DS& l, string ma_sach)
{
	for (int i = 0; i < l.sl; i++)
	{
		NODE_DMS* p = l.ds_dausach[i]->dms.pHead;
		if (l.ds_dausach[i]->dms.pHead == NULL)
		{
			if (i == l.sl - 1)
			{
				BaoLoi("Danh Sach Rong");
				return -1;
			}
			continue;
		}
		NODE_DMS* q = NULL; // con trỏ q chạy song song với p và đứng trước p
		while (p != NULL)
		{
			if (p->data.masach == ma_sach)
				break;
			q = p;
			p = p->pNext;
		}
		if (p == NULL)
		{
			if (i == l.sl - 1)
			{
				BaoLoi("Ma Sach Khong Ton Tai");
				return -1;
			}
			continue;
		}
		// xoa node dau
		else if (q == NULL)
		{
			l.ds_dausach[i]->dms.pHead = p->pNext;
			if (l.ds_dausach[i]->dms.pHead == NULL)
				l.ds_dausach[i]->dms.pTail = NULL;
	
			delete p;
			l.ds_dausach[i]->soluongsach--;
			return 1;
		}
		// xóa node p sau q
		else
		{
			q->pNext = p->pNext;
			if (p = l.ds_dausach[i]->dms.pTail)
				l.ds_dausach[i]->dms.pTail = q;
			delete p;
			l.ds_dausach[i]->soluongsach--;
			return 1;
		}
	}
	return -1;
}

// hiệu chỉnh sách theo mã sách . hiệu chỉnh thành công rt 1 <> -1 ; ESC rt -2
int hieu_chinh_sach(danhmucsach& a, string ma_sach)
{
		TextColor(15);
		cout << "Ma sach: " << a.masach<< endl;
		cout << "Trang thai: ";
		a.trangthai = nhap_so_nguyen();
		if (a.trangthai == -1) // ESC
			return -2;
		cout << "Vi tri: ";
		a.vitri = nhap_ki_tu1();
		if (a.vitri == "-1") // ESC
			return -2;
		TextColor(7);
		return 1;
}

// =========================================== Muon Tra=====================================
// tạo 1 node mượn trả 
NODE_MT* tao_node_muontra(muontra x)
{
	NODE_MT* p = new NODE_MT;
	if (p == NULL)
	{
		cout << "Khong du bo nho cap phat" << endl;
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	p->pPrev = NULL;
	return p;
}

// lập phiếu mượn sách
void them_phieu_muon(muontra& x)
{
	// phiếu mượn trả chỉ cần nhập mã sách . ngày mượn sẽ được cập nhật từ hệ thống thời gian thực, trạng thái sẽ mặc định = 0 nghĩa là sách đó đang mượn
	thoi_gian_thuc(x.ngaymuon);
	cout << "Ngay muon:" << x.ngaymuon.ngay << "/" << x.ngaymuon.thang << "/" << x.ngaymuon.nam << endl;
	x.ngaytra.ngay = 0;
	x.ngaytra.thang = 0;
	x.ngaytra.nam = 0;
	x.trangthai = 0; // trạng thái mặc định =0 độc giả đang mượn cuốn sách
	cout << "Trang thai: " << x.trangthai << endl;
}

// in thong tin của 1 phiếu mượn trả
void xuat_thong_tin_phieu_muontra(muontra a, string ten_sach, int tungdo)
{
	int x = whereX();
	int y = whereY();
	gotoXY(45, 0);
	cout << "Ma Sach";
	gotoXY(65, 0);
	cout << "Ten Sach";
	gotoXY(85, 0);
	cout << "Ngay Muon";
	gotoXY(100, 0);
	cout << "Ngay Tra";
	gotoXY(120, 0);
	cout << "Trang Thai";
	gotoXY(45, tungdo);
	cout << a.masach;
	gotoXY(65, tungdo);
	cout << ten_sach;
	gotoXY(85, tungdo);
	cout << a.ngaymuon.ngay << "/" << a.ngaymuon.thang << "/" << a.ngaymuon.nam;
	gotoXY(100, tungdo);
	cout << a.ngaytra.ngay << "/" << a.ngaytra.thang << "/" << a.ngaytra.nam;
	gotoXY(120, tungdo);
	cout << a.trangthai;
	gotoXY(x, y);

}

// thêm phiếu vào danh sách để quản lí
void them_vao_ds_muontra(LIST_MT& l, NODE_MT* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		p->pPrev = l.pTail;
		l.pTail = p;
	}
}

// hàm có chức năng xuất các sách đang mượn của 1 độc giả nếu có sách mượn rt 1 <> 0
int xuat_sach_dang_muon(TREE t, LIST_DS l)
{
	int kt = 0; // kiểm tra nếu độc giả có sách đang mượn thì tăng. nếu không có sách đang mượn =0
	int tungdo = 0;
	for (NODE_MT* p = t->data.mt.pHead; p != NULL; p = p->pNext)
	{
		for (int i = 0; i < l.sl; i++)
		{
			for (NODE_DMS* k = l.ds_dausach[i]->dms.pHead; k != NULL; k = k->pNext)
			{
				if (p->data.masach == k->data.masach && p->data.trangthai == 0)
				{
					kt++;
					xuat_thong_tin_phieu_muontra(p->data, l.ds_dausach[i]->tensach, ++tungdo);
				}
			}
		}
	}
	if (kt == 0) // độc giả không mượn sách
	{
		return 0;
	}
	return 1;
}

// kiểm tra độc giả quá hạn trong danh sách quá hạn nếu số ngày quá hạn > 7 tra ve so ngay quahan <> 0
int tim_kiem_doc_gia_qua_han(LIST_QUAHAN& l, int ma_doc_gia)
{
	for (int i = 0; i < l.sl; i++)
	{
		if (l.ds_quahan[i].ma_doc_gia == ma_doc_gia)
		{
			return l.ds_quahan->so_ngay_quahan;
		}
	}
	return 0;
}

// đếm số sách độc giả đang mượn dùng để kiểm tra điều kiện mượn sách 
int dem_sach_docgia_muon(TREE t)
{
	int so_sach_muon = 0;
	for (NODE_MT* p = t->data.mt.pHead; p != NULL; p = p->pNext)
	{
		if (p->data.trangthai == 0) // sách chưa trả
			so_sach_muon++;
	}
	return so_sach_muon;
}

// mượn thành công tr 1 <> -1 ; esc rt -2
int muonsach(TREE& t, LIST_DS& l)
{
	int tungdo=0;
	TREE p = NULL;// lưu  độc giả tìm được
	int ma_doc_gia;
	do
	{
		xuat_ds_thong_tin_doc_gia(t, tungdo);
		tungdo = 0;
		gotoXY(1, 10);
		cout << "                            ";
		gotoXY(1, 10);
		cout << "Nhap Ma DG: ";
		ma_doc_gia = nhap_so_nguyen();
		if (ma_doc_gia == -1) // ESC
		{
			return -2;
		}
		 p = tim_kiem_docgia_ma(t, ma_doc_gia);
		if (p == NULL)
		{
			BaoLoi("Ma doc gia khong ton tai.");
			continue;
		}
		xoa_hien_thi_doc_gia();
		// kiểm tra số lượng sách độc giả đã mượn nếu > 3 không mượn được
		int dem = dem_sach_docgia_muon(p);
		if (dem >= 3)
		{
			BaoLoi("Doc gia da muon qua 3 cuon.Khong the muon them");
			continue;
		}
		int so_ngay_qua_han=0;
		for (NODE_MT* q = p->data.mt.pHead; q != NULL; q = q->pNext)
		{
			if (q->data.trangthai == 0) // độc giả có sách mượn
			{
				so_ngay_qua_han = tinh_so_ngay(q->data.ngaymuon);
				if (so_ngay_qua_han > 7)
				{
					BaoLoi("DOC GIA DA MUON SACH QUA HAN (>7 ngay)");
					break;
				}
			}
		}
		if (so_ngay_qua_han < 7) // thoát vòng lặp
			break;
		else // nếu độc giả mượn sách quá hạn lặp lại
			continue;
	} while (1);
	string ten_sach;
	do {
		xuat_ds_dausach(l);
		gotoXY(1, 10);
		cout << "                              ";
		gotoXY(1, 10);
		cout << "Nhap Ten Sach: ";
		ten_sach = nhap_ki_tu1();
		if (ten_sach == "-1") // ESC
		{
			return -2;
		}
		xoa_hien_thi_dausach();
		int j = tim_kiem_dau_sach_theo_ten(l, ten_sach);
		// Không tìm thấy tên sách
		if (j == -1)
		{
			BaoLoi("Ten Sach Khong Tim Thay");
			continue;
		}
		break;
	} while (1);
		string ma;
		int i = -1; // lưu vị trí của mã sách nhập vào 
		do
		{
			gotoXY(1, 10);
			cout << "                                              ";
			gotoXY(1, 10);
			cout << "Nhap Ma Dau Sach Can Muon: ";
			ma = nhap_ki_tu1();
			if (ma == "-1") // ESC
			{
				return -2;
			}
			i = tim_kiem_dau_sach_theo_ma(l, ma);
			if (i == -1)
			{
				BaoLoi("Ma dau sach khong dung.Vui long nhap lai.");
				continue;
			}
			else
				break;
		} while (1);
		xoa_hien_thi_dausach();
		NODE_DMS* k = NULL; // lưu vị trí node trả về trong tim_kiem_sach
		string ma_sach=" ";
		for (k = l.ds_dausach[i]->dms.pHead; k != NULL; k = k->pNext)
		{
			if (k->data.trangthai == 0) // nếu sách còn mượn được
			{
				ma_sach = k->data.masach;
				k->data.trangthai = 1; // cap nhat sach da muon
				break;
			}
		}
		if (ma_sach == " ")
		{
			BaoLoi("Het Sach");
			return -1;
		}
		// thêm vào danh sách mượn trả
		muontra x;
		x.masach = ma_sach;
		l.ds_dausach[i]->soluongmuon++; // tăng số lượng mượn cuốn sách
		p->data.tongsosach++;
		them_phieu_muon(x);
		them_vao_ds_muontra(p->data.mt, tao_node_muontra(x));
		return 1;
}

// trả sách thành công tr 1 <> -1 ; ESC rt -2
int trasach(TREE& t, LIST_DS& l)
{
	int tungdo = 0;
	xuat_ds_thong_tin_doc_gia(t, tungdo);
	tungdo = 0;
	int ma;
	TREE p = NULL;
	do
	{
		gotoXY(1, 10);
		cout << "                             ";
		gotoXY(1, 10);
		cout << "Nhap ma doc gia: ";
		ma = nhap_so_nguyen();
		p= tim_kiem_docgia_ma(t, ma);
		xoa_hien_thi_doc_gia();
		if (ma == -1) // ESC
			return -2;

		if (p == NULL)
		{
			BaoLoi("Ma doc gia khong ton tai.");
			continue;
		}
		else
		{
			TextColor(15);
			if (xuat_sach_dang_muon(p, l) == 0) // độc giả không có sách mượn
			{
				BaoLoi("Doc Gia Khong Co Sach Muon");
				return -1;
			}
			string ma_sach;
			TextColor(7);
			do
			{
				gotoXY(1, 10);
				cout << "                                  ";
				gotoXY(1, 10);
				cout << "Nhap ma sach can tra: ";
				ma_sach = nhap_ki_tu1();
				if (ma_sach == "-1") // ESC
					return -2;

				NODE_DMS* k = tim_kiem_sach(l, ma_sach); // lưu vị trí của sách trả về trong danh sách qua mã sách
				if (k == NULL)
				{
					BaoLoi("Ma sach khong ton tai");
					continue;
				}
				else
				{
					Date n1;
					for (NODE_MT* q = p->data.mt.pHead; q != NULL; q = q->pNext)
					{
						if (q->data.masach == ma_sach)
						{
							k->data.trangthai = 0;// cập nhật lại sách cho mượn được 
							q->data.trangthai = 1; // cập nhật lại đọc giả đã trả sách
							thoi_gian_thuc(n1); // lấy thời gian hệ thống
							q->data.ngaytra.ngay = n1.ngay;
							q->data.ngaytra.thang = n1.thang;
							q->data.ngaytra.nam = n1.nam;
						}
					}
				}
				break;
			} while (1);
			break;
		}
	} while (1);

	return 1;
}
// ========================================= Qua Han =============================

// in ra danh sách các độc giả quá hạn
void ds_quahan(TREE t, LIST_QUAHAN& l)
{
	int x = whereX();
	int y = whereY();
	int n = 0;
	TREE Stack[STACKSIZE];
	int top = -1;
	Date n1;
	do
	{
		while (t != NULL)
		{
			Stack[++top] = t;
			t = t->pLeft;
		}
		if (top != -1)
		{
			t = Stack[top--];
			for (NODE_MT* p = t->data.mt.pHead; p != NULL; p = p->pNext)
			{
				n++;
				l.ds_quahan[n - 1].ma_doc_gia = t->data.mathe;
				thoi_gian_thuc(n1);
				if (p->data.trangthai == 0)
				{
					l.ds_quahan[n - 1].so_ngay_quahan = tinh_so_ngay(p->data.ngaymuon);
				}
				else
				l.ds_quahan[n - 1].so_ngay_quahan = 0;
				l.ds_quahan[n - 1].ma_sach = p->data.masach;
				l.ds_quahan[n - 1].ho = t->data.ho;
				l.ds_quahan[n - 1].ten = t->data.ten;
				l.ds_quahan[n - 1].phai = t->data.phai;
			}
			t = t->pRight;
		}
		else
			break;
	} while (1);
	l.sl = n;
	quahan temp;
	// sap xep giam dan ds qua han
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (l.ds_quahan[i].so_ngay_quahan < l.ds_quahan[j].so_ngay_quahan)
			{
				temp = l.ds_quahan[i];
				l.ds_quahan[i] = l.ds_quahan[j];
				l.ds_quahan[j] = temp;
			}
		}
	}
	// xuat ds qua han theo thu tu giam dan
	for (int k = 0; k < l.sl; k++)
	{
		if (l.ds_quahan[k].so_ngay_quahan > 7)
		{
			gotoXY(45, 0);
			cout << "Ma doc gia";
			gotoXY(65, 0);
			cout << "Ho va ten";
			gotoXY(95, 0);
			cout << "Phai";
			gotoXY(100, 0);
			cout << "Ma sach";
			gotoXY(120, 0);
			cout << "So ngay qua han";
			gotoXY(45, k + 1);
			cout << l.ds_quahan[k].ma_doc_gia;
			gotoXY(65, k + 1);
			cout << l.ds_quahan[k].ho << " " << l.ds_quahan[k].ten;
			gotoXY(95, k + 1);
			cout << l.ds_quahan[k].phai;
			gotoXY(100, k + 1);
			cout << l.ds_quahan[k].ma_sach;
			gotoXY(120, k + 1);
			cout << l.ds_quahan[k].so_ngay_quahan;
			gotoXY(x, y);
		}
	}
}

// =================== 10 sách có lượt mượn nhiều nhất ====================
void top10sach(LIST_DS l)
{
	dausach* temp = NULL;
	// sắp xếp theo thứ tự giảm dần top 10 sách
	for (int i = 0; i < l.sl - 1; i++)
	{
		for (int j = i + 1; j < l.sl; j++)
		{
			if (l.ds_dausach[i]->soluongmuon < l.ds_dausach[j]->soluongmuon)
			{
				temp = l.ds_dausach[i];
				l.ds_dausach[i] = l.ds_dausach[j];
				l.ds_dausach[j] = temp;
			}

		}
	}
	TextColor(15);
	for (int k = 0; k < l.sl && k < 10; k++)
	{
		xuat_dau_sach(*l.ds_dausach[k],k+1);
	}
	TextColor(7);
}