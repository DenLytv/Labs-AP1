//#include <iostream>
//#include "Task1.h"
//
//int main() {
//	int num0 = 0, num1 = 0;
//	count0and1(num0, num1);
//	std::cout << "Number of '0' is: " << num0 << std::endl << "Number of' '1' is: " << num1 << std::endl;
//	return 0;
//}
//
//void count0and1(int& num0, int& num1) {
//	char str[100];
//	std::cout << "Enter some text with '0' and '1': ";
//	std::cin.getline(str, sizeof(str));
//	for (char* ch = str; *ch != '\0'; ch++) {
//		if (*ch == '0')
//			++num0;
//		if (*ch == '1')
//			++num1;
//	}
//}