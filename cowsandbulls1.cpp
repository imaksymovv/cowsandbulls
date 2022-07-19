#include <iostream>

int main() {
	srand(time(NULL));
	int a[4];
	for (int i = 0; i < 4; ++i) {
	a: a[i] = 1 + rand() % 9;
		for (int j = 0; j < i; j++)
			if (a[j] == a[i]) goto a; //сделано, что бы числа не повторялись
	}
	/*for (int i = 0; i < 4; ++i) {
		std::cout << a[i]; // увидеть что загадал компьютер, для быстрого прохождения
	} std::cout << "\n";*/
	int b[4];
	int c = 0;
	int d = 0;
	std::cout << "the computer guessed the number, try to guess it" << std::endl;
	do {
		for (int i = 0; i < 4; ++i) {
			std::cin >> b[i];
			if (b[i] == a[i]) {
				c = c + 1;
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (b[i] == a[j]) {
					d = d + 1;
				}
			}
		}
		if (c != 4) {
			std::cout << c << " bulls" << std::endl;
			std::cout << d << " cows" << std::endl;
			c = 0;
			d = 0;
		}
	} while (c != 4);
	std::cout << "you did it! now it's computer turn to guess, enter your number" << std::endl;
	int ur[4];
	for (int i = 0; i < 4; ++i) {
		std::cin >> ur[i];
	}
	int c1 = 0;
	int d1 = 0;
	int a1[4];
	int result[4];
	int counter = 0;
	do {
		b: for (int i = 0; i < 4; ++i) {
			a1[i] = rand() % 9;
			counter++;
		}
		if (a1[3] == ur[3]) {
			result[3] = a1[3];
			c1 = 1;
		}
		else goto b;

		c: for (int i = 0; i < 3; ++i) {
			a1[i] = rand() % 9;
			counter++;
		}
		if (a1[2] == ur[2]) {
			result[2] = a1[2];
			c1 = 2;
		}
		else goto c;

		d: for (int i = 0; i < 2; ++i) {
			a1[i] = rand() % 9;
			counter++;
		}
		if (a1[1] == ur[1]) {
			result[1] = a1[1];
			c1 = 3;
		}
		else goto d;

		f: for (int i = 0; i < 1; ++i) {
			a1[i] = rand() % 9;
			counter++;
		}
		if (a1[0] == ur[0]) {
			result[0] = a1[0];
			c1 = 4;
		}
		else goto f;
	} while (c1 != 4);
	std::cout << "computer guessed ur number! it is:" << std::endl;
	for (int i = 0; i < 4; ++i) {
		std::cout << result[i];
	} std::cout << "\n";
	std::cout << counter << " turns used to guess" << std::endl;
	return 0;
}