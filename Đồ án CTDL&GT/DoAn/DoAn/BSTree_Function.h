#ifndef BSTree_Funtion_h
#define BSTree_Funtion_h

#include "BSTree.h"

void initBSTree(BSTree& root);	// Khởi tạo cây
BSTNode* createBSTNode(ItemType x);	// Tạo nút có giá trị X
int insertBSTNode(BSTNode*& root, BSTNode* p);	// Hàm chèn nút vào cây(Chèn theo mã học phần)
void showBSTNode(BSTNode* p);	// Hàm xuất thông tin của một học phần

void Head();	// Header 
void Foot();	// Footer

int kiemTraTrung(BSTNode* root, char maHP[]);
void nhapThongTinHP(BSTNode* root, ItemType& x);	// Hàm nhập thông tin một học phần
void createBSTree_ByHand(BSTree& bst);	// Hàm tạo cây bằng cách nhập từ bàn phím
int createBSTree_FromTextFile(BSTree& bst, char inputFileName[]);	// Hàm tạo cách bằng cách đọc file

// Các hàm duyệt cây
void traverse_NLR(BSTNode* root);	//Duyệt cây Gốc->Trái->Phải
void traverse_LNR(BSTNode* root);	//Duyệt cây Trái->Gốc->Phải
void traverse_LRN(BSTNode* root);	//Duyệt cây Trái->Phải->Gốc
void traverse_NRL(BSTNode* root);	//Duyệt cây Gốc->Phải->Trái
void traverse_RNL(BSTNode* root);	//Duyệt cây Phải->Gốc->Trái
void traverse_RLN(BSTNode* root);	//Duyệt cây Phải->Trái->Gốc

void Traversal_depth(BSTNode* root);	// Duyệt cây theo chiều sâu
void Traversal_width(BSTNode* root);	// Duyệt cây theo chiều rộng

BSTNode* findBSTNodeReplace(BSTNode*& p);	// Hàm tìm nút thế mạng
int deleteBSTNode_MaHP(BSTNode*& root, char MaHP[]);	// Hàm xóa nút của cây theo mã học phần

BSTNode* findBSTNode_TenHP(BSTNode* root, char tenHP[]);	// Hàm tìm nút theo tên học phần

void Statistic(BSTNode* root, int soTC);	// Hàm thống kê theo số tín chỉ
int countCourseType(BSTNode* root, char loaiHP[]);	// Hàm đếm số lượng học phần theo loại học phần
int sumTinChi(BSTNode* root);	// Hàm tính tổng các tín chỉ

void showBSTree(BSTNode* root, int& stt);	// Hàm xuất thông tin của cây
void showListHP(BSTNode* root);		// Hàm xuất danh sách học phần

int countBSTNode(BSTNode* root);	// Hàm đếm số học phần
void writeData(BSTNode* root, FILE* f);	// Hàm viết dữ liệu học phần vào file 
int saveData(BSTNode* root, char tenFile[]);	// Hàm lưu tất cả học phần vào file

int updateHocPhan(BSTNode* root, BSTNode* p);	// Cập nhật thông tin học phần
#endif