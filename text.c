#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int cnt = 0;
int fib(int n) {
	
	cnt++;
	if(n == 0) 
		return 1;
	else if (n == 1) 
        return 2;
	else 
	return fib(n - 1) + fib(n - 2);
}
int main() {
	int cnt = 0;
	fib(8);
	printf("%d\n", cnt);
	system("pause");
	return 0;
}
#if 0
void test(int arr[3][4][5]) {
	//arr ������ int(*)[4],��ʵ����ʽת����ָ�� int(*)[5],ָ�����Ͳ�ͬ.
	//���ڸ���ά����,ֻ�е�һ��[]�ܹ�ʡ��,��д�Ͷ�д��.
}
//void test(int arr[]) {
//	printf("hello");
//}һά���鴫��
//void test(int arr[20]) {
//	printf("hello");
// }
//void test2(int* arr[10]) {
//
//}
//ʹ�ø�����ʱ,ע�ⲻҪֱ�ӱȽ������������Ƿ����
//�������ڴ��еĴ洢�Ĺ���Ƚϼ�1.�ֽ���2.ԭ�벹��
//	unsigned char i = 0; 
int main(){
	int arr[3][4][5] = { 0 };
	test(arr);
	//int arr[10] = { 1,2,3 };
	//int* arr2[20] = { 0 };
	//test2(arr);
	//for (int i = 0; i <= 255; i++) {
	//printf("HELLO world\n");
	//}
	
	//char a[1000];
	//int i;
	//for (i = 0; i < 1000; i++) {
	//	a[i] = -1 - i;
	//}
	//printf("%d\n", strlen(a));
	//unsigned int i;
	//for(i = 9; i >= 0; i--) {
	//	printf("%u\n", i);
	//}
	//int a = -20;
	//unsigned int b = 10;
	// int c = a + b;
	// printf("%d\n", c);
	//char a = 127;
	//printf("%u\n", a);
	system("pause");
	return 0;
}

//char �����,int Ҳ�����,ֻҪ����������,�������;

void printLine(int starCount, int spaceCount) {
	for (int i = 0; i < spaceCount; i++) {
		printf(" ");
	}
	for (int i = 0; i < starCount; i++) {
		printf("*");
	}
	printf("\n");
}
void printLingXing() {
	for (int row = 1; row <= 6; row++) {
		printLine(2 * row - 1, 7 - row);
		//��ӡ������;
	}
	printLine(13, 0);//2.��ӡ�м����;
	//3.����ӡ������,���ǰ������ǵĴ�ӡ����,��������
	for (int row = 6; row >= 1; row--) {
		printLine(2 * row - 1, 7 - row);
	}
}
//int iswhatbit(int num){
//	//1.������Ǽ�λ��
//	int count = 0;
//	while (num != 0) {
//		num /= 10;
//		count++;
//	}
//	return count;
//}
//int isShuiXian(int num) {
//	int oldNum = num;
//	int n = iswhatbit(num);
//	//��¼�����numֵ;
//	int sum = 0;
//	while (num != 0) {
//		int tmp = num % 10;
//		num /= 10;
//		sum +=(int)pow(tmp, n);
//	}
//	if (sum == oldNum) {
//		return 1;
//	}
//	return 0;
//}
//void func() {
	//int sum = 0;
	//int cur = 0;
	//for (int i = 1; i <= 5;i++){
	//	cur = cur * 10 + 2;
	//	sum += cur;
	//}
	//printf("%d\n", sum);
//}
int main() {
	printLingXing();
	/*int i = 1;
	for(; i < 100000; i++) {
		if (isShuiXian(i)) {
			printf("%d\n", i);
		}
	}*/
	//func();
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d\n", a, b, c);
//	//char a = -128;
//	//printf("%u\n", a);
	system("pause");
	return 0;
}
#endif