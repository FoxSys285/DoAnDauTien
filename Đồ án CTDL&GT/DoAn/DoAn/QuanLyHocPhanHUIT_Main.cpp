#include "BSTree_Function.h"
#include "ChuanHoaChuoi.h"

void menu_DuyetCay() {
	printf("*****************************\n");
	printf("* 0. Thoat chuong trinh     *\n");
	printf("* 1. Duyet theo LNR         *\n");
	printf("* 2. Duyet theo LRN         *\n");
	printf("* 3. Duyet theo NLR         *\n");
	printf("* 4. Duyet theo NRL         *\n");
	printf("* 5. Duyet theo RLN         *\n");
	printf("* 6. Duyet theo RNL         *\n");
	printf("*****************************\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
void menu() {
	printf("\n**********************************************************************\n");
	printf("*                                  MENU                              *\n");
	printf("**********************************************************************\n");
	printf("*  0. Thoat chuong trinh                                             *\n");//
	printf("*  1. Tao cay bang cach nhap tu ban phim                             *\n");//
	printf("*  2. Tao cay bang cach doc tu File                                  *\n");//
	printf("*  3. Xuat danh sach hoc phan                                        *\n");
	printf("*  4. Duyet cay theo 6 cach                                          *\n");//
	printf("*  5. Duyet cay theo chieu rong va chieu sau                         *\n");//
	printf("*  6. Xoa 1 hoc phan co ma hoc phan X khoi cay Binary Search Tree    *\n");//
	printf("*  7. Them 1 hoc phan X vao cay Binary Search Tree                   *\n");//
	printf("*  8. Tim hoc phan co ten X trong cay Binary Search Tree             *\n");//
	printf("*  9. Thong ke hoc phan theo so tin chi                              *\n");//
	printf("* 10. Dem so luong hoc phan theo tung loai                           *\n");//
	printf("* 11. Tinh tong so tin chi cac hoc phan                              *\n");//
	// Các hàm mở rộng
	printf("* 12. Luu du lieu tat ca hoc phan vao file                           *\n");
	printf("* 13. Cap nhat thong tin hoc phan theo ten hoc phan                  *\n");
	printf("**********************************************************************\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////


void process() {
	int n;

	BSTree bst;
	initBSTree(bst);

	char tenFile[] = "dsHocPhan.txt";
	char a[41];

	ItemType x;

	do {
		menu();
		printf("Ban chon chuc nang nao: ");
		scanf("%d", &n);

		switch (n)
		{
		case 0:
		{
			printf("Thoat chuong trinh\n");
			return;
		}
		case 1:
		{
			createBSTree_ByHand(bst);
			showListHP(bst.Root);
			break;
		}
		case 2:
		{
			if (createBSTree_FromTextFile(bst, tenFile) == 0)
				printf("Loi mo File\n");
			else {
				printf("Doc File thanh cong\n");
				showListHP(bst.Root);
			}
			break;
		}
		case 3:
		{
			if (!bst.Root)
				printf("Cay rong\n");
			else
				showListHP(bst.Root);
			break;
		}
		case 4:
		{
			if (!bst.Root) {
				printf("Cay rong\n");
				break;
			}
			int m;
			int exit = 0;
			do {
				menu_DuyetCay();
				printf("Ban chon cach duyet cay nao: ");
				scanf("%d", &m);
				switch (m)
				{
				case 0:
					exit = 1;
					break;
				case 1:
					printf("*------------------------------------------DUYET CAY THEO LNR------------------------------------------*\n");
					Head();
					traverse_LNR(bst.Root);
					Foot();
					break;
				case 2:
					printf("*------------------------------------------DUYET CAY THEO LRN------------------------------------------*\n");
					Head();
					traverse_LRN(bst.Root);
					Foot();
					break;
				case 3:
					printf("*------------------------------------------DUYET CAY THEO NLR------------------------------------------*\n");
					Head();
					traverse_NLR(bst.Root);
					Foot();
					break;
				case 4:
					printf("*------------------------------------------DUYET CAY THEO NRL------------------------------------------*\n");
					Head();
					traverse_NRL(bst.Root);
					Foot();
					break;
				case 5:
					printf("*------------------------------------------DUYET CAY THEO RLN------------------------------------------*\n");
					Head();
					traverse_RLN(bst.Root);
					Foot();
					break;
				case 6:
					printf("*------------------------------------------DUYET CAY THEO RNL------------------------------------------*\n");
					Head();
					traverse_RNL(bst.Root);
					Foot();
					break;
				default:
					printf("Khong co cach duyet cay nay\n");
					break;
				}
			} while (exit == 0);
			break;
		}
		case 5:
		{
			if (!bst.Root) printf("Cay rong\n");
			else {
				printf("*---------------------------------------DUYET CAY THEO CHIEU RONG--------------------------------------*\n");
				Head();
				Traversal_depth(bst.Root);
				Foot();
				printf("\n");
				printf("*----------------------------------------DUYET CAY THEO CHIEU SAU--------------------------------------*\n");
				Head();
				Traversal_width(bst.Root);
				Foot();
			}
			break;
		}
		case 6:
		{
			if (!bst.Root) {
				printf("Cay rong\n");
				break;
			}
			while (getchar() != '\n');
			printf("Nhap ma hoc phan can xoa: ");
			fgets(a, 20, stdin);
			a[strcspn(a, "\n")] = '\0';
			int kq = deleteBSTNode_MaHP(bst.Root, a);
			if (kq == 1) {
				printf("Da xoa hoc phan co ma %s thanh cong.\n", a);
				printf("Danh sach sau khi xoa ma hoc phan %s\n", a);
				showListHP(bst.Root);
			}
			else
				printf("Khong tim thay hoc phan co ma %s.\n", a);
			break;
		}
		case 7:
		{
			while (getchar() != '\n');
			nhapThongTinHP(bst.Root, x);
			chuanHoa(x.TenHP);
			chuanHoa(x.LoaiHP);
			chuanHoa(x.HeDaoTao);
			if (insertBSTNode(bst.Root, createBSTNode(x))) {
				printf("Them hoc phan thanh cong\n");
				showListHP(bst.Root);
			}
			else {
				printf("Them hoc phan khong thanh cong\n");
			}
			break;
		}
		case 8:
		{
			if (!bst.Root) {
				printf("Cay rong\n");
				break;
			}
			while (getchar() != '\n');
			printf("Nhap ten hoc phan can tim kiem: ");
			fgets(a, 41, stdin);
			a[strcspn(a, "\n")] = '\0';
			BSTNode* p = findBSTNode_TenHP(bst.Root, a);
			if (p == NULL) printf("Khong tim thay hoc phan nay\n");
			else {
				printf("Da tim thay hoc phan nay\n");
				Head();
				showBSTNode(p);
				Foot();
			}
			break;
		}
		case 9:
		{
			if (!bst.Root) {
				printf("Cay rong\n");
				break;
			}
			int soTC;
			printf("Nhap so tin chi can thong ke: ");
			scanf("%d", &soTC);
			Head();
			Statistic(bst.Root, soTC);
			Foot();
			break;
		}
		case 10:
		{
			while (getchar() != '\n');
			printf("Nhap loai hoc phan: ");
			fgets(a, 41, stdin);
			a[strcspn(a, "\n")] = '\0';
			int cnt = countCourseType(bst.Root, a);
			printf("So hoc phan theo loai %s la: %d\n", a, cnt);
			break;
		}
		case 11:
		{
			int sum = sumTinChi(bst.Root);
			printf("Tong so tin chi cac hoc phan la: %d\n", sum);
			break;
		}
		case 12:
		{
			// Nếu cây rỗng thì không lưu tránh mất các dữ liệu cũ
			if (!bst.Root) {
				printf("Cay rong khong the luu du lieu\n");
			}
			else {
				if (saveData(bst.Root, tenFile) == 0) {
					printf("Loi mo File\n");
					printf("Luu du lieu khong thanh cong\n");
				}
				else {
					printf("Luu du lieu vao File thanh cong\n");
				}
			}
			break;
		}
		case 13:
		{
			if (!bst.Root) {
				printf("Cay rong\n");
				break;
			}
			printf("Nhap ten hoc phan can cap nhat: ");
			while (getchar() != '\n');
			fgets(a, 41, stdin);
			a[strcspn(a, "\n")] = '\0';

			BSTNode* p = findBSTNode_TenHP(bst.Root, a);

			if (updateHocPhan(bst.Root, p) == 1) {
				printf("Hoc phan sau khi cap nhat:\n\n");
				Head();
				showBSTNode(p);
				Foot();
			}
			else printf("Khong tim thay hoc phan ten: %s\n", a);

			break;
		}
		default:
			printf("Khong co chuc nang nay\n");
			break;
		}
	} while (true);
}

void main() {
	process();
	getch();
}