//#include"SeqList.h"
#include"List.h"
//void main()
//{
//	List mylist;//  ListNode *mylist;
//	InitList(&mylist);
//	CreateList(&mylist);
//	ShowList(mylist);
//}
//#if 0

int main(int argc, char* argv[])
{					
	//SeqList mylist;
	//SeqListInit(&mylist, 8);
	List mylist;
	ListInit(&mylist);
	ElemType item;
	ListNode* p = NULL;
	int c[1024];
	int pos = 0;
	int val = 0;
	int select = 1;
	while (select)
	{
		printf("********************************************\n");
		printf("* [1] push_back           [2] push_front   *\n");
		printf("* [3] show_list           [0] quit_system  *\n");
		printf("* [4] pop_back            [5] pop_front    *\n");
		printf("* [6] insert_pos          [7] insert_val   *\n");
		printf("* [8] erase_pos           [9] erase_val    *\n");
		printf("* [10] find_val           [11] find_pos    *\n");
		printf("* [12] sort               [13] reverse     *\n");
		printf("* [14] length             [15] capacity    *\n");
		printf("* [16] clear              [17] destroy     *\n");
		printf("********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据<以-1结束>:> \n");
			while (scanf("%d", &item), item != -1)
			{
				ListPushBack(&mylist,item);
			}
			break;
		case 2:
			printf("请输入要插入的数据<以-1结束>:>");
			while (scanf("%d", &item), item != -1)
			{
				ListPushFront(&mylist,item);
			}
			break;
		case 3:
			ListShow(mylist);
			break;
		case 4:
			ListPopBack(&mylist);
			break;
		case 5:
			ListPopFront(&mylist);
			break;
		//case 6:
		//	printf("请输入要插入的位置:>");
		//	scanf("%d", &pos);
		//	printf("请输入要插入的值:>");
		//	scanf("%d", &item);
		//	//SeqListInsertByPos(&mylist, pos, item);
		//	break;
		//case 7:
		//	printf("请输入要插入的值:>");
		//	scanf("%d", item);
		//	//SeqListInsertByVal(&mylist, item);
		//	break;
		//case 8:
		//	printf("请输入要删除的位置:>");
		//	scanf("%d", &pos);
		//	//SeqListEraseByPos(&mylist, pos);
		//	break;
		case 9:
			printf("请输入要删除的值:>");
			scanf("%d",&pos);
			ListErase(&mylist, pos);
			break;
		case 10:
			printf("请输入要找第几个值:>");
			scanf("%d", &item);
			ListFindByPos(mylist,item,c );
			printf("第%d个位置的数为 %d\n",item,*c);
			break;
		case 11:
			printf("请输入要找的值:>");
			scanf("%d", &pos);
			p=ListFind(mylist, pos);
			if (p = NULL) {
				printf("要查找的 %d 数据不存在.\n", pos);
			}else {
				printf(" %d数据已被查找到.\n", pos);
			}
			break;
		//case 12:
		//	//SeqListSort(&mylist);
		//	break;
		//case 13:
		//	//SeqListReverse(&mylist);
		//	break;
		case 14:
			printf("顺序表的长度为:> %d\n", ListLength(mylist));
			break;
		//case 16:
		//	//SeqListClear(&mylist);
		//	break;
		//case 17:
		//	//SeqListDestroy(&mylist);
		//	break;
		default:
		break;
		}
	}
	//SeqListDestroy(&mylist);
	printf("GoodBye.\n");
	return 0;
}