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

    double q_pel, q_meat, q_dough; // пельмени, фарш, тесто
    long M;
    double t;
    double af;

    std::cout << "Введите исходные данные.\r\n"
        "q[п], q[ф], q[т] - мощность каждого из приборов\r\n"
        "M - количество пельменей в день (2 смены)\r\n"
        "t - длина одной смены в секундах\r\n"
        "af - концентрация фарша в пельмене\r\n";

    std::cout << "q[п] = "; std::cin >> q_pel;
    std::cout << "q[ф] = "; std::cin >> q_meat;
    std::cout << "q[т] = "; std::cin >> q_dough;
    std::cout << "M = "; std::cin >> M;
    std::cout << "t = "; std::cin >> t;
    std::cout << "af = "; std::cin >> af;

    // Нужно вычислить количество:
    int n_pel; // пельменных автоматов
    int n_meat; // линий по фаршу
    int n_dough; // линий по тесту

    double Q_meat = af * M; // мясо (общее)
    n_meat = Q_meat / q_meat; // кол-во машин для фарша (TODO: ceil to integer)
    double Q_dough = (1.0 - af) * M; // тесто (общее)
    n_dough = Q_dough / q_dough; // кол-во машин для теста
}
