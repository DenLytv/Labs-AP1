#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Task2.h"

int main() {
    std::string text = "";

    textInput(text);

    std::vector<std::string> paragraphs{};
    splitParagraphs(text, paragraphs);

    std::vector<std::string*> paragraphsPointers;
    for (std::string& p : paragraphs) {
        paragraphsPointers.push_back(&p);
    }

    sortParagraphs(paragraphsPointers);

    return 0;
}

void sortParagraphs(std::vector<std::string*>& paragraphsPointers) {
    sort(paragraphsPointers.begin(), paragraphsPointers.end(), [](std::string* a, std::string* b) {
        if ((*a).length() == (*b).length())
            return *a < *b;
        return (*a).length() < (*b).length();
        });

    std::cout << "Paragraphs sorted by length:\n";
    for (std::string* p : paragraphsPointers) {
        std::cout << *p << std::endl;
    }
}

void splitParagraphs(std::string& text, std::vector<std::string>& paragraphs)
{
    size_t start = 0;
    size_t end = text.find('\n');
    while (end != std::string::npos) {
        paragraphs.push_back(text.substr(start, end - start));
        start = end + 1;
        end = text.find('\n', start);
    }
}

void textInput(std::string& text)
{
    std::cout << "Enter the text (enter a blank line to complete the entry):\n";
    std::string paragraph = "";
    while (true) {
        std::getline(std::cin, paragraph);
        if (paragraph.empty()) {
            break;
        }
        text += paragraph + '\n';
    }
}