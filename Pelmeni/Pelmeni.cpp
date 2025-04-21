#include <iostream>
#include <locale.h>

int main()
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
