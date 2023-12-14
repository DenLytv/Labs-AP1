//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <sstream>
//
//struct Book {             
//    std::string title;
//    std::string ISBN;
//    std::string author;
//    size_t year;
//    size_t pagesNumber;
//};
//
//std::vector<Book> readBooksFromFile(const std::string& filename, const std::string& findStr);
//void printBooks(std::vector<Book>& books);
//
//int main() {
//    const std::string fileName = "Catalog.txt";
//    const std::string findStr = "C++";
//    std::vector<Book> books = readBooksFromFile(fileName, findStr);
//    printBooks(books);
//
//    return 0;
//}
//
//
//std::vector<Book> readBooksFromFile(const std::string &filename, const std::string &findStr) {
//    std::vector<Book> books{};
//    std::ifstream file(filename);
//
//    if (!file.is_open()) 
//    {
//        std::cerr << "Error opening file: " << filename << std::endl;
//    }
//
//    std::string line = "";
//    while (getline(file, line)) {
//        Book book;
//        std::stringstream sst(line);
//        getline(sst, book.title, '\t');
//        if (book.title.find(findStr) != std::string::npos) {
//            getline(sst, book.ISBN, '\t');
//            getline(sst, book.author, '\t');
//            sst >> book.year;
//            sst >> book.pagesNumber;
//
//            books.push_back(book);
//        }
//    }
//    file.close();
//    return books;
//}
//
//void printBooks(std::vector<Book>& books)
//{
//    if (books.size() == 0)
//    {
//        std::cout << "There is no C++ books in catalog" << std::endl;
//    }
//    size_t i = 0;
//    for (const Book& book:books)
//    {
//        std::cout << "============== Book " << ++i << " ==============" << std::endl;
//        std::cout << "ISBN: " << book.ISBN << std::endl;
//        std::cout << "Author: " << book.author << std::endl;
//        std::cout << "Title: " << book.title << std::endl;
//        std::cout << "Year: " << book.year << std::endl;
//        std::cout << "Number of pages: " << book.pagesNumber << "\n\n\n";
//    }
//}