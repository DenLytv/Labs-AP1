#include <iostream>
#include "Task1.h"

int main() {
	std::cout << "Number of '0' is: " << count0and1().first << std::endl;
	std::cout << "Number of' '1' is: " << count0and1().second << std::endl;
	return 0;
}

std::pair<size_t, size_t> count0and1() {
	char str[100];
	size_t count0 = 0, count1 = 0;
	std::cout << "Enter some text with '0' and '1': ";
	std::cin.getline(str, sizeof(str));
	for (char* ch = str; *ch != '\0'; ch++) {
		if (*ch == '0')
			++count0;
		if (*ch == '1')
			++count1;
	}
	return { count0,count1 };
}