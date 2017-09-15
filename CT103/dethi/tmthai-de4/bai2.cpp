#include <string.h>
#include "astacklib.h"

int CalPosFix(char a[], int n) {
	Stack S;
	MakeNull_Stack(&S);
	
	for(int i=0; i<n; i++) {
		if(a[i] >= 48 && a[i] <= 57) {
			Push(a[i]-48, &S);
			printf("\nPush: %d", a[i]-48);
		}
		else {
			ElementType tmp1, tmp2;
			tmp1 = Top(S);
			printf("\nPop: %d", tmp1);
			Pop(&S);
			tmp2 = Top(S);
			printf("\nPop: %d", tmp2);
			Pop(&S);
			switch(a[i]) {
				case '+': 
					Push(tmp1 + tmp2, &S); 
					printf("\n%d + %d = %d", tmp1, tmp2, tmp1+tmp2);
					printf("\nPush: %d", tmp1+tmp2); 
					break;
				case '-': 
					Push(tmp1 - tmp2, &S); 
					printf("\n%d - %d = %d", tmp1, tmp2, tmp1-tmp2);
					printf("\nPush: %d", tmp1-tmp2); 
					break;
				case '*': 
					Push(tmp1 * tmp2, &S); 
					printf("\n%d * %d = %d", tmp1, tmp2, tmp1*tmp2);
					printf("\nPush: %d", tmp1*tmp2); 
					break;
				case '/': 
					Push(tmp1 / tmp2, &S); 
					printf("\n%d / %d = %d", tmp1, tmp2, tmp1/tmp2);
					printf("\nPush: %d", tmp1/tmp2); 
					break;
			}
		}
	}
	
	return Top(S);
}

int CalPreFix(char a[], int n) {
	Stack S;
	MakeNull_Stack(&S);
	
	for(int i=n-1; i>= 0; i--) {
		if(a[i] >= 48 && a[i] <= 57) {
			Push(a[i]-48, &S);
			printf("\nPush: %d", a[i]-48);
		}
		else {
			int tmp1, tmp2;
			tmp1 = Top(S);
			printf("\nPop: %d", tmp1);
			Pop(&S);
			tmp2 = Top(S);
			printf("\nPop: %d", tmp2);
			Pop(&S);
			switch(a[i]) {
				case '+': 
					Push(tmp1 + tmp2, &S); 
					printf("\n%d + %d = %d", tmp1, tmp2, tmp1+tmp2);
					printf("\nPush: %d", tmp1+tmp2); 
					break;
				case '-': 
					Push(tmp1 - tmp2, &S); 
					printf("\n%d - %d = %d", tmp1, tmp2, tmp1-tmp2);
					printf("\nPush: %d", tmp1-tmp2); 
					break;
				case '*': 
					Push(tmp1 * tmp2, &S); 
					printf("\n%d * %d = %d", tmp1, tmp2, tmp1*tmp2);
					printf("\nPush: %d", tmp1*tmp2); 
					break;
				case '/': 
					Push(tmp1 / tmp2, &S); 
					printf("\n%d / %d = %d", tmp1, tmp2, tmp1/tmp2);
					printf("\nPush: %d", tmp1/tmp2); 
					break;
			}
		}
	}
	
	return Top(S);
}

int main() {
	char a[100];
	char b[100];
	
	printf("\nNhap vao bieu thu hau to: ");
	fflush(stdin);
	gets(a);
	/*
	printf("\nNhap vao bieu thuc tien to: ");
	fflush(stdin);
	gets(b);
	*/
	
	printf("\nGia tri bieu thu hau to la: %d", CalPosFix(a, strlen(a)));
	//printf("\nGia tri bieu thuc tien to la: %d", CalPreFix(b, strlen(b)));
	
	return 0;
}
