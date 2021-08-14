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
	//arr 类型是 int(*)[4],而实参隐式转换的指针 int(*)[5],指针类型不同.
	//对于更高维数组,只有第一个[]能够省略,能写就都写上.
}
//void test(int arr[]) {
//	printf("hello");
//}一维数组传参
//void test(int arr[20]) {
//	printf("hello");
// }
//void test2(int* arr[10]) {
//
//}
//使用浮点数时,注意不要直接比较两个浮点数是否相等
//整数在内存中的存储的规则比较简单1.字节序2.原码补码
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

//char 会溢出,int 也会溢出,只要类型有上限,都会溢出;

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
		//打印上三角;
	}
	printLine(13, 0);//2.打印中间的线;
	//3.最后打印下三角,就是把上三角的打印过程,给反过来
	for (int row = 6; row >= 1; row--) {
		printLine(2 * row - 1, 7 - row);
	}
}
//int iswhatbit(int num){
//	//1.求出这是几位数
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
//	//记录最初的num值;
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