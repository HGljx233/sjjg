#include"Bintree.h"
void main() {
	BinTreeNode* p, * pr;
	char* str = "ABC##DE##F##G#H##";
	char* VLR = "ABCDEFGH";
	char* LVR = "CBEDFAGH";
	char* LRV = "CEFDBHGA";
	int n = strlen(VLR);
	BinTree bt;
	bt = BinTreeCreate_LVR_LRV(LVR,LRV,n);
	for (int i = 0; i < n; i++) {
		printf("%d ", bt[i]);
	}
}
//#include"Heap.h"
//void main() {
//	int ar[] = { 27,15,19,18,28,34,65,49,25,37 };
//	int n = sizeof(ar) / sizeof(ar[0]);
//	Heap hp;
//	HeapCreate(&hp, ar, n);
//	HeapShow(&hp);
//}
//void main() {
//	int ar[] = { 27,15,19,18,28,34,65,49,25,37 };
//	int n = sizeof(ar) / sizeof(ar[0]);
//	Heap hp;
//	HeapInit(&hp, 10);
//	for (int i = 0; i < n; i++) {
//		HeapInsert(&hp, ar[i]);
//	}
//	HeapShow(&hp);
//	HeapRemove(&hp);
//	HeapShow(&hp);
//	printf("%d",HeapTop(&hp));
//	HeapDestroy(&hp);
//}
//#include"bintree.h"
//void main() {
//	BinTree bt;
//	BinTreeInit(&bt);
//	BinTreeCreate_1(&bt);
//	printf("%d", Size(&bt));
//
//}