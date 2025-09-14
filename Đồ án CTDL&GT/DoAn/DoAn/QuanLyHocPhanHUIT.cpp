#include "BSTree.h"
#include "ChuanHoaChuoi.h"

void initBSTree(BSTree& root) {
	root.Root = NULL;
}

BSTNode* createBSTNode(ItemType x) {
	BSTNode* p = new BSTNode;
	p->Info = x;
	p->Right = NULL;
	p->Left = NULL;
	return p;
}

int insertBSTNode(BSTNode*& root, BSTNode* p) {
	if (p == NULL) {
		return 0;
	}
	if (root == NULL) {
		root = p;
		return 1;
	}
	int soSanh = strcmp(p->Info.MaHP, root->Info.MaHP);

	if (soSanh == 0) {
		return 0;
	}
	else if (soSanh < 0) {
		insertBSTNode(root->Left, p);
	}

	else
		insertBSTNode(root->Right, p);
}

void showBSTNode(BSTNode* p) {
	printf("|%-14s|%-35s|%-15s|%-13d|%-21s|\n", p->Info.MaHP, p->Info.TenHP, p->Info.LoaiHP, p->Info.SoTC, p->Info.HeDaoTao);
}

//////////////////  CÁC HÀM CHÍNH  /////////////////////

void nhapThongTinHP(BSTNode* root, ItemType& x);
// Tạo cây chứa thông tin bằng cách nhập từ bàn phím (Mục 2) (Trần Nguyễn Vỹ Kha)
/////////////////////////////////////////////////////////////////////////////////////////////
void createBSTree_ByHand(BSTree& bst) {
	ItemType x;
	int n;
	printf("Nhap so luong hoc phan: ");
	scanf("%d", &n);
	while (getchar() != '\n');

	for (int i = 0;i < n;i++) {
		printf("\n----------------Nhap hoc phan thu %d----------------\n", i + 1);
		nhapThongTinHP(bst.Root, x);
		chuanHoa(x.TenHP);
		chuanHoa(x.LoaiHP);
		chuanHoa(x.HeDaoTao);
		insertBSTNode(bst.Root, createBSTNode(x));
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////


// Tạo cây chứa thông tin bằng cách đọc file (Mục 2) (Trần Nguyễn Vỹ Kha)
/////////////////////////////////////////////////////////////////////////////////////////////
int createBSTree_FromTextFile(BSTree& bst, char inputFileName[]) {
	FILE* fi = fopen(inputFileName, "r");
	if (fi == NULL) {
		return 0;
	}

	int n;
	fscanf(fi, "%d\n", &n);
	int i = 0;

	while (i < n) {
		ItemType x;
		fscanf(fi, "%[^,],%[^,],%[^,],%d,%[^\n]\n", x.MaHP, x.TenHP, x.LoaiHP, &x.SoTC, x.HeDaoTao);

		BSTNode* p = createBSTNode(x);
		int kq = insertBSTNode(bst.Root, p);
		if (kq == 1) i++;
	}
	fclose(fi);
	return 1;
}
/////////////////////////////////////////////////////////////////////////////////////////////


// Duyệt cây theo 6 cách (Xem sách) (Mục 3) (Đào Sỹ Luận)
/////////////////////////////////////////////////////////////////////////////////////////////
//Duyệt cây Gốc->Trái->Phải
void traverse_NLR(BSTNode* root) {
	if (!root) {
		return;
	}
	showBSTNode(root);//Xử lý nút hiên tại
	traverse_NLR(root->Left);//Duyệt cây trái
	traverse_NLR(root->Right);//Duyệt cây phải
}

//Duyệt cây Trái->Gốc->Phải
void traverse_LNR(BSTNode* root) {
	if (!root) {
		return;
	}
	traverse_LNR(root->Left);//Duyệt cây trái
	showBSTNode(root);//Xử lý nút hiên tại
	traverse_LNR(root->Right);//Duyệt cây phải
}

//Duyệt cây Trái->Phải->Gốc
void traverse_LRN(BSTNode* root) {
	if (!root) {
		return;
	}
	traverse_LRN(root->Left);//Duyệt cây trái
	traverse_LRN(root->Right);//Duyệt cây phải
	showBSTNode(root);//Xử lý nút hiên tại
}

//Duyệt cây Gốc->Phải->Trái
void traverse_NRL(BSTNode* root) {
	if (!root) {
		return;
	}
	showBSTNode(root);//Xử lý nút hiên tại
	traverse_NRL(root->Right);//Duyệt cây phải
	traverse_NRL(root->Left);//Duyệt cây trái
}

//Duyệt cây Phải->Gốc->Trái
void traverse_RNL(BSTNode* root) {
	if (!root) {
		return;
	}
	traverse_RNL(root->Right);//Duyệt cây phải
	showBSTNode(root);//Xử lý nút hiên tại
	traverse_RNL(root->Left);//Duyệt cây trái
}

//Duyệt cây Phải->Trái->Gốc
void traverse_RLN(BSTNode* root) {
	if (!root) {
		return;
	}
	traverse_RLN(root->Right);//Duyệt cây phải
	traverse_RLN(root->Left);//Duyệt cây trái
	showBSTNode(root);//Xử lý nút hiên tại
}
/////////////////////////////////////////////////////////////////////////////////////////////


// Duyệt cây theo chiều sâu (Mục 4) (Nguyễn Thành Nam)
/////////////////////////////////////////////////////////////////////////////////////////////
/*
	Có 3 kiểu duyệt:
		- Pre-order  (NLR) (*)
		- In-order   (LNR)
		- Post-order (LRN)
*/
/*
	Sử dụng stack để duyệt
*/
void Traversal_depth(BSTNode* root) {
	if (!root) return;
	stack<BSTNode*> st;

	st.push(root);
	while (!st.empty()) {

		BSTNode* p = st.top();
		st.pop();

		showBSTNode(p);
		if (p->Left != NULL)
			st.push(p->Left);
		if (p->Right != NULL)
			st.push(p->Right);
	}
}

// Duyệt cây theo chiều rộng (Mục 4) (Nguyễn Thành Nam)
/*
	Ý tưởng:
		- Sử dụng queue để giải quyết thuật toán.
		- Đưa root vào hàng đợi.
		- Nếu hàng đợi không rỗng thì:
			+ Lấy nút đầu ra khỏi queue.
			+ In thông tin nút vừa lấy.
			+ Nếu nút có con trái/ phải thì đưa vào queue.
		- Lặp lại cho đến khi hàng đợi rỗng.
*/
void Traversal_width(BSTNode* root) {
	if (!root) return;

	queue<BSTNode*> q;
	q.push(root);

	while (!q.empty()) {

		BSTNode* p = q.front();
		q.pop();

		showBSTNode(p);

		// Nếu tmp có con trái thì thêm vào hàng đợi q
		if (p->Left != NULL) {
			q.push(p->Left);
		}
		// Nếu tmp có con phải thì thêm vào hàng đợi q
		if (p->Right != NULL) {
			q.push(p->Right);
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////


// Xóa một học phần theo mã học phần (Tham khảo trong sách) (Mục 5) (Nguyễn Thành Nam)
/////////////////////////////////////////////////////////////////////////////////////////////

// Hàm tìm nút thế mạng
BSTNode* findBSTNodeReplace(BSTNode*& p) {
	BSTNode* f = p;
	BSTNode* q = p->Right;
	while (q->Left != NULL) {
		f = q;
		q = q->Left;
	}
	p->Info = q->Info;
	if (f == p)
		f->Right = q->Right;
	else
		f->Left = q->Right;
	return q;
}

// Hàm xóa một học phần theo mã HP
int deleteBSTNode_MaHP(BSTNode*& root, char MaHP[]) {
	if (root == NULL) //Cây rỗng
		return 0;
	if (strcmpi(root->Info.MaHP, MaHP) > 0)
		return deleteBSTNode_MaHP(root->Left, MaHP);
	else if (strcmpi(root->Info.MaHP, MaHP) < 0)
		return deleteBSTNode_MaHP(root->Right, MaHP);
	else {
		BSTNode* p = root;
		if (root->Left == NULL) {
			root = root->Right;
			delete p;
		}
		else if (root->Right == NULL) {
			root = root->Left;
			delete p;
		}
		else {
			BSTNode* q = findBSTNodeReplace(p);
			delete q;
		}
	}
	return 1;
}
/////////////////////////////////////////////////////////////////////////////////////////////

int kiemTraTrung(BSTNode* root, char maHP[]) {
	if (root == NULL)
		return 1;
	if (strcmp(root->Info.MaHP, maHP) > 0)
		return kiemTraTrung(root->Left, maHP);
	else if (strcmp(root->Info.MaHP, maHP) < 0)
		return kiemTraTrung(root->Right, maHP);
	else if (strcmp(root->Info.MaHP, maHP) == 0)
		return 0;
	return 1;
}

// Thêm 1 học phần x vào cây (Mục 6) (Nguyễn Thành Nam)
/////////////////////////////////////////////////////////////////////////////////////////////
void nhapThongTinHP(BSTNode* root, ItemType& x) {

	printf("Nhap ma hoc phan: ");
	fgets(x.MaHP, 15, stdin);
	x.MaHP[strcspn(x.MaHP, "\n")] = '\0';
	if (kiemTraTrung(root, x.MaHP) == 0) {
		printf("Da co ma hoc phan nay\n");
		return;
	}
	// Cách xóa bộ đệm chuẩn

	printf("Nhap ten hoc phan: ");
	fgets(x.TenHP, 41, stdin);
	x.TenHP[strcspn(x.TenHP, "\n")] = '\0';

	printf("Nhap loai hoc phan: ");
	fgets(x.LoaiHP, 20, stdin);
	x.LoaiHP[strcspn(x.LoaiHP, "\n")] = '\0';

	printf("Nhap so tin chi: ");
	scanf("%d", &x.SoTC);
	while (getchar() != '\n');	// Xóa dấu '\n'

	printf("Nhap he dao tao: ");
	fgets(x.HeDaoTao, 30, stdin);
	x.HeDaoTao[strcspn(x.HeDaoTao, "\n")] = '\0';
}
/////////////////////////////////////////////////////////////////////////////////////////////


// Tìm học phần có tên học phần là X (Mục 7) (Nguyễn Thành Nam)
/////////////////////////////////////////////////////////////////////////////////////////////
BSTNode* findBSTNode_TenHP(BSTNode* root, char tenHP[]) {
	if (root == NULL) return NULL;
	if (strcmpi(root->Info.TenHP, tenHP) == 0) return root;
	BSTNode* findLeft = findBSTNode_TenHP(root->Left, tenHP);
	if (findLeft != NULL) return findLeft;
	return findBSTNode_TenHP(root->Right, tenHP);
}
/////////////////////////////////////////////////////////////////////////////////////////////


// Thống kê học phần theo tín chỉ (Mục 8) (Đào Sỹ Luận)
/////////////////////////////////////////////////////////////////////////////////////////////
void Statistic(BSTNode* root, int soTC) {
	if (!root)
	{
		return;
	}

	Statistic(root->Left, soTC);

	if (root->Info.SoTC == soTC)
	{
		showBSTNode(root);
	}
	Statistic(root->Right, soTC);
}
/////////////////////////////////////////////////////////////////////////////////////////////


// Đếm số học phần theo từng loại (Mục 9) (Đào Sỹ Luận)
/////////////////////////////////////////////////////////////////////////////////////////////
int countCourseType(BSTNode* root, char loaiHP[]) {
	if (!root)
	{
		return 0;
	}
	int countL = countCourseType(root->Left, loaiHP);
	int countR = countCourseType(root->Right, loaiHP);
	if (strcmpi(root->Info.LoaiHP, loaiHP) == 0) return countL + countR + 1;
	return countL + countR;
}
/////////////////////////////////////////////////////////////////////////////////////////////


// Tính tổng số tín chỉ (Mục 10) (Đào Sỹ Luận)
/////////////////////////////////////////////////////////////////////////////////////////////
int sumTinChi(BSTNode* root) {
	if (!root)
	{
		return 0;
	}
	int sumL = sumTinChi(root->Left);
	int sumR = sumTinChi(root->Right);
	return sumL + sumR + root->Info.SoTC;
}
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
void showBSTree(BSTNode* root, int& stt) {
	if (!root) {
		return;
	}
	showBSTree(root->Left, stt);
	printf("| %02d ", ++stt);
	showBSTNode(root);
	showBSTree(root->Right, stt);
}
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
void Head() {
	printf("*--------------+-----------------------------------+---------------+-------------+---------------------*");
	printf("\n|%-14s|%-35s|%-15s|%-13s|%-21s|\n", "MA HOC PHAN", "TEN HOC PHAN", "LOAI HOC PHAN", "SO TIN CHI", "HE DAO TAO");
	printf("|--------------+-----------------------------------+---------------+-------------+---------------------|\n");
}

void Foot() {
	printf("*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
void showListHP(BSTNode* root) {
	int stt = 0;
	printf("*----+--------------+-----------------------------------+---------------+-------------+---------------------*");
	printf("\n|%-4s|%-14s|%-35s|%-15s|%-13s|%-21s|\n", "STT", "MA HOC PHAN", "TEN HOC PHAN", "LOAI HOC PHAN", "SO TIN CHI", "HE DAO TAO");
	printf("|----+--------------+-----------------------------------+---------------+-------------+---------------------|\n");
	showBSTree(root, stt);
	printf("*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////


// Các hàm mở rộng

// Lưu dữ liệu vào file (backup)
/////////////////////////////////////////////////////////////////////////////////////////////
// Đếm số học phần
int countBSTNode(BSTNode* root) {
	if (!root) return 0;
	int cntL = countBSTNode(root->Left);
	int cntR = countBSTNode(root->Right);
	return 1 + cntL + cntR;
}
// Backup
void writeData(BSTNode* root, FILE* f) {
	if (!root) return;
	writeData(root->Left, f);
	writeData(root->Right, f);
	fprintf(f,"%s,%s,%s,%d,%s\n",
		root->Info.MaHP,
		root->Info.TenHP,
		root->Info.LoaiHP,
		root->Info.SoTC,
		root->Info.HeDaoTao);
}
int saveData(BSTNode* root, char tenFile[]) {
	FILE* f = fopen(tenFile, "w");
	if (!f) 
		return 0;
	int n = countBSTNode(root);
	fprintf(f, "%d\n", n);
	writeData(root, f);
	fclose(f);
	return 1;
}
/////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////
//  Menu cập nhật học phần
void menuHP() {
	printf("*******************************\n");
	printf("* 0. Thoat chuong trinh       *\n");
	printf("* 1. Ma hoc phan              *\n");
	printf("* 2. Ten hoc phan             *\n");
	printf("* 3. Loai hoc phan            *\n");
	printf("* 4. So tin chi               *\n");
	printf("* 5. He dao tao               *\n");
	printf("* 6. Cap nhat tat ca thong tin*\n");
	printf("*******************************\n");
}

// Cập nhật học phần theo ten học phần
int updateHocPhan(BSTNode* root, BSTNode* p) {
	char x[50];
	int n;
	if (!p) return 0;
	do {
		menuHP();
		printf("Ban chon cap nhat thong tin nao: ");
		scanf("%d", &n);
		switch (n)
		{
		case 0:
			printf("Da thoat chuc nang cap nhat\n");
			return 1;
		case 1:
		{
			printf("Nhap ma hoc phan moi: ");
			while (getchar() != '\n');
			fgets(p->Info.MaHP, 41, stdin);
			p->Info.MaHP[strcspn(p->Info.MaHP, "\n")] = '\0';
			printf("Cap nhat thanh cong\n");
			break;
		}
		case 2:
		{
			printf("Nhap ten hoc phan moi: ");
			while (getchar() != '\n');
			fgets(p->Info.TenHP, 41, stdin);
			p->Info.TenHP[strcspn(p->Info.TenHP, "\n")] = '\0';
			printf("Cap nhat thanh cong\n");
			break;
		}
		case 3:
		{
			printf("Nhap loai hoc phan moi: ");
			while (getchar() != '\n');
			fgets(p->Info.LoaiHP, 41, stdin);
			p->Info.LoaiHP[strcspn(p->Info.LoaiHP, "\n")] = '\0';
			printf("Cap nhat thanh cong\n");
			break;
		}
		case 4:
		{
			printf("Nhap so tin chi moi: ");
			scanf("%d", &p->Info.SoTC);
			printf("Cap nhat thanh cong\n");
			break;
		}
		case 5:
		{
			printf("Nhap he dao tao moi: ");
			while (getchar() != '\n');
			fgets(p->Info.HeDaoTao, 41, stdin);
			p->Info.HeDaoTao[strcspn(p->Info.HeDaoTao, "\n")] = '\0';
			printf("Cap nhat thanh cong\n");
			break;
		}
		case 6:
		{
			printf("Nhap ma hoc phan moi: ");
			while (getchar() != '\n');
			fgets(p->Info.MaHP, 41, stdin);
			p->Info.MaHP[strcspn(p->Info.MaHP, "\n")] = '\0';

			printf("Nhap ten hoc phan moi: ");
			while (getchar() != '\n');
			fgets(p->Info.TenHP, 41, stdin);
			p->Info.TenHP[strcspn(p->Info.TenHP, "\n")] = '\0';

			printf("Nhap loai hoc phan moi: ");
			while (getchar() != '\n');
			fgets(p->Info.LoaiHP, 41, stdin);
			p->Info.LoaiHP[strcspn(p->Info.LoaiHP, "\n")] = '\0';

			printf("Nhap so tin chi moi: ");
			scanf("%d", &p->Info.SoTC);

			printf("Nhap he dao tao moi: ");
			while (getchar() != '\n');
			fgets(p->Info.HeDaoTao, 41, stdin);
			p->Info.HeDaoTao[strcspn(p->Info.HeDaoTao, "\n")] = '\0';

			printf("Cap nhat thanh cong\n");
			break;
		}
		default:
			printf("Khong co thong tin nay\n");
			break;
		}
	} while (true);
	return 1;
}


/////////////////////////////////////////////////////////////////////////////////////////////