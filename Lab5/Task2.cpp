#include <iostream>
#include <string>

int letterCount(std::string S);
std::string input(int num);

int main()
{
    std::string s1 = input(1);
    std::string s2 = input(2);
    std::cout << "The number of consonants surrounded by numbers in S1: " << letterCount(s1) << std::endl;
    std::cout << "The number of consonants surrounded by numbers in S2: " << letterCount(s2) << std::endl;
    return 0;
}

int letterCount(std::string s) {
    size_t counter = 0;
    for (size_t i = 1, l = s.length() - 1; i < l; i++)
    {
        if (isalpha(s[i]))
            if ((tolower(s[i]) != 'a') && (tolower(s[i]) != 'e') && (tolower(s[i]) != 'y') && (tolower(s[i]) != 'u')
                && (tolower(s[i]) != 'i') && (tolower(s[i]) != 'o'))
                if (isdigit(s[i - 1]) && isdigit(s[i + 1]))
                    ++counter;
    }
    return counter;
}

std::string input(int num) {
    std::string s = "";
    do
    {
        std::cout << "Please enter string " << num << " (up to 100 characters) : \n";
        std::getline(std::cin, s);
    } while (s.length() > 100 || s.length() == 0);
    return s;
}