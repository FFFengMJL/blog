#include<iostream>
using namespace std;

int main()
{
	int total = 0;
	int num = 0;
	int quo = 0;
	int rem = 0;
	for (int i = 100; i >= 0; --i) {
		for (int j = 0; j <= (100 - i) / 2; j++) {
			if ((100 - i - j * 2) % 5 == 0) {
				cout << i << '*' << 1 << '+' << j << '*' << 2 << '+' << (100 - i - j * 2) / 5 << '*' << 5 << '=' << 100 << endl;
				total++;
			}
			// for(int k=0; k<(100-i-2*j)/5; ++k){
			// 	if (i+2*j+5*k == 100) {
			// 	cout << i << '*' << 1 << '+' << j << '*' << 2 << '+' << k << '*' << 5 << '=' << 100 << endl;
			// 	++total;
			// 	}		
			// }
		}
	}
	cout << "Total: " << total << endl;

	return 0;
}
