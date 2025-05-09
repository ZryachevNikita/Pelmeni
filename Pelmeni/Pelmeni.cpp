﻿#include <iostream>
#include <cmath>

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
    double Q_pel;
    double M;
    double t;
    double af;

    std::cout << "Введите исходные данные.\r\n"
        "q[п], q[ф], q[т] - производительность каждого из приборов\r\n"
        "M - количество пельменей в день (2 смены)\r\n"
        "t - длина одной смены в часах\r\n"
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

    Q_pel = M / (2 * t);

    double Q_meat = af * Q_pel; // мясо (общее)
    n_meat = std::ceil(Q_meat / q_meat); // кол-во машин для фарша
    double Q_dough = (1.0 - af) * Q_pel; // тесто (общее)
    n_dough = std::ceil(Q_dough / q_dough); // кол-во машин для теста
    n_pel = std::ceil(Q_pel / q_pel); // пельменные автоматы

    std::cout << "Результат: \r\n"
        "линии по тесту: " << n_dough << "\r\n"
        "линии по фаршу: " << n_meat << "\r\n"
        "пельменные автоматы: " << n_pel << "\r\n";
}
