#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <string>
#define N 4

int **reverseColumns(int** arr);
int files(int**& arr, std::string num);

int main()
{
    srand(static_cast<unsigned>(time(NULL)));
    int **ptr = new int* [N];
    for (size_t i = 0; i < N; i++)
    {
        ptr[i] = new int[N];
    }

    if (files(ptr, "1") == 1) return 1;
    ptr = reverseColumns(ptr);
    if (files(ptr, "2") == 1) return 1;

    for (size_t i = 0; i < N; i++)
    {
        delete[] ptr[i];
        ptr[i] = nullptr;
    }

    delete[] ptr;
    ptr = nullptr;

    return 0;
}

int** reverseColumns(int** arr)
{
    int **temp = new int* [N];
    int tmp;
    for (size_t i = 0; i < N; i++)
    {
        temp[i] = new int[N];
        for (size_t j = 0; j < N; j++)
        {
            tmp = arr[i][j];
            temp[i][j] = arr[i][N - (j + 1)];
            temp[i][N - (j + 1)] = tmp;
        }
    }
    return temp;
}

int files(int**& arr, std::string num)
{
    std::ofstream F_w("..\\F" + num + ".txt");
    if (!F_w) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (num == "1")
                arr[i][j] = rand() % 201 - 100;
            F_w << std::setw(8) << arr[i][j];
        }
        F_w << std::endl;
    }
    F_w.close();

    std::ifstream F_r("..\\F" + num + ".txt");
    if (!F_r) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            F_r >> arr[i][j];
            std::cout << std::setw(8) << arr[i][j];
        }
        std::cout << std::endl;
    }
    F_r.close();
    std::cout << std::endl;

    return 0;
}