#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double f(double x) {
    // Пример функции, которую мы будем дифференцировать
    return sin(x);
}

double numerical_derivative(double (*f)(double), double x, double h) {
    // Разностная формула второго порядка для вычисления производной
    return (f(x + h) - f(x - h)) / (2.0 * h);
}

int main() {
    double a = 0.0;  // Начало интервала
    double b = 3.14159;  // Конец интервала
    int num_steps = 1000;  // Количество шагов
    double h = (b - a) / num_steps;  // Размер шага

    // Последовательное вычисление
    double start_time = omp_get_wtime();
    for (int i = 0; i < num_steps; ++i) {
        double x = a + i * h;
        double derivative = numerical_derivative(f, x, h);
        // Здесь можно что-то делать с результатом, например, записать в массив
    }
    double end_time = omp_get_wtime();
    printf("Sequential execution time: %f seconds\n", end_time - start_time);

    // Параллельное вычисление
    int num_threads;
#pragma omp parallel
    {
#pragma omp single
        {
            num_threads = omp_get_num_threads();
        }
    }

    start_time = omp_get_wtime();
#pragma omp parallel for
    for (int i = 0; i < num_steps; ++i) {
        double x = a + i * h;
        double derivative = numerical_derivative(f, x, h);
        // Здесь можно что-то делать с результатом, например, записать в массив
    }
    end_time = omp_get_wtime();
    printf("Parallel execution time with %d threads: %f seconds\n", num_threads, end_time - start_time);

    return 0;
}
