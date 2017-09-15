#include <iostream>
using namespace std;

int giaiThua(int n) {
	if(n == 0)
		return 1;
	return giaiThua(n-1);
}

int toHop(int k, int n) {
	return (giaiThua(n) / (giaiThua(k) * giaiThua(n-k)));
}

int main() {
	int n, k, th;
	
	cout << "Enter the number n: ";
	cin >> n;
	
	cout << "Enter the number k: ";
	cin >> k;
	
	th = toHop(k, n);
	
	cout << "\n" << th;
	
	return 0;
}
