#include <iostream>

#ifdef _WIN32
#  define WIN32_LEAN_AND_MEAN
#  include <locale.h>
#endif

int main(int argc, char **argv)
{
#ifdef _WIN32
    setlocale(LC_ALL, "Rus");
#endif

    std::cout << "Введите исходные данные\n ";
}
