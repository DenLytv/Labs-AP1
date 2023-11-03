#include <iostream>
#include <string>

std::pair <std::string, size_t> task(std::string myname);
std::string input();
bool check(std::string fullName);

int main() {

    std::string fullName = input();

    std::cout << "Name: " << task(fullName).first << std::endl;
    std::cout << "Number of letters in third word : " << task(fullName).second << std::endl;

    return 0;
}

std::pair <std::string, size_t> task(std::string fullName) {
    int found1 = fullName.find_first_of(" ") + 1;
    int found2 = fullName.find_last_of(" ");

    int lettersCounter = 0;
    for (size_t i = found2 + 1, l = fullName.length(); i < l; i++)
    {
        if (isalpha(fullName[i]))
            ++lettersCounter;
    }

    return { fullName.substr(found1, found2 - found1), lettersCounter };
}

std::string input() {
    std::string fullName = "";
    do
    {
        std::cout << "Please enter your full name(ex. Lytvynenko Denys Olexandrovych): ";
        getline(std::cin, fullName);
    } while (!check(fullName));
    return fullName;
}

bool check(std::string fullName) {
    size_t spacesCounter = 0;
    for (size_t i = 0, l = fullName.length(); i < l; i++)
    {
        if (isspace(fullName[i]))
            ++spacesCounter;
    }
    if (spacesCounter == 2)
    {
        int found1 = fullName.find_first_of(" ") + 1;
        int found2 = fullName.find_last_of(" ") + 1;
        if (isupper(fullName[0]) && isupper(fullName[found1]) && isupper(fullName[found2]))
            return true;
        else {
            std::cout << "Error full name\n";
            return false;
        }
    }
    else {
        std::cout << "Error full name\n";
        return false;
    }
}