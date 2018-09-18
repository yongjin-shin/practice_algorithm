#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int cnt = 0;
	int input = -10000;
	int sum = 0;
	int digit = 0;
	int remained = 0;
	int init = 0;

	cin >> input;

	init = input;

	while(1){
		cnt += 1;
		sum = 0;
		remained = input;

		for(int i = 1; i>=0; i--){
			digit = floor(remained/pow(10,i));
			remained = remained - digit*pow(10,i);
			sum += digit;
		}

		int sum_last = sum - (floor(sum/10)*10);
		if(input<10){
			input = input*10 + sum_last;
		}else{
				input = digit*10 + sum_last;
		}
		
		if(input == init){
			break;
		}
	}

	cout << cnt;
	return 0;
}
