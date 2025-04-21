#include <iostream>
#include <locale.h>

#ifdef _WIN32
#  define WIN32_LEAN_AND_MEAN
#  include <locale.h>
#endif

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "Rus");
    Qf = af * Qp;
    nf = Qf / qf;
    Qt = (1 - af) * Qp;
    nt = Qt / qt;
    std::cout << "Количество пелменных автоматов: " << np << '\n';
    std::cout << "Количество мясорубок: " << nf << '\n';
    std::cout << "Количество тестомесителей: " << nt << '\n';
}
