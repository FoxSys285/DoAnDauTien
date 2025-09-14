// File lưu struct HocPhan và Cây

#ifndef BSTree_h
#define BSTree_h

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<queue>	
#include<stack>

using namespace std;

struct HocPhan {
	char MaHP[11];
	char TenHP[41];
	char LoaiHP[11];
	/*
	Có 2 loại:
		+ Tự chọn
		+ Bắt buộc
	*/
	int SoTC;
	char HeDaoTao[21];
	/*
	Có 2 hệ đào tạo:
		+ Đại học chính quy
		+ Đại học tại chức
	*/
};

typedef HocPhan ItemType;

struct BSTNode {
	ItemType Info;
	BSTNode* Left;
	BSTNode* Right;
};

struct BSTree
{
	BSTNode* Root;
};

#endif
