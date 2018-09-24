#include <iostream>
#include <ctime>
#include <cstdlib> //rand
#include "libs/ed_sort.h"

using namespace std;

//cores rgbcymkw
//red, green, blue, cyan, yellow, magenta, black, white

void minimum_sort(vector<int> &vet)
{
    for (int i = 0; i < (int)vet.size() - 1; i++)
    {
        for (int j = i + 1; j < (int)vet.size(); j++)
        {
            view_show(vet, {i, j}, "gy");
            if (vet[j] < vet[i])
            {
                std::swap(vet[i], vet[j]);
                view_show(vet, {i, j}, "yg");
            }
        }
    }
}

void bubble_sort(std::vector<int> &vet)
{
    int tam = vet.size();
    int flag = 0;
    for (int i = 0; i < tam; i++)
    {
        for (int j = flag; j < tam; j++)
        {
            view_show(vet, {i, j}, "gb");
            if (vet[j] < vet[i])
            {
                view_show(vet, {i, j}, "rb");
                std::swap(vet[i], vet[j]);
                view_show(vet, {i, j}, "cb");
            }
        }
        flag++;
    }
}

void quick_sort(std::vector<int> &vet, int first, int final)
{
    int i, j, pivot, center;
    i = first;
    j = final;
    center = (first + final) / 2;
    pivot = vet[center];
    view_show(vet, {i, j, center}, "gbr");
    while (i < j)
    {
        while (vet[i] < pivot)
        {
            i++;
            view_show(vet, {i, j, center}, "gbr");
        }
        while (vet[j] > pivot)
        {
            j--;
            view_show(vet, {i, j, center}, "gbr");
        }
        if (i <= j)
        {
            view_show(vet, {i, j, center}, "gbr");
            std::swap(vet[i], vet[j]);
            i++;
            j--;
        }
    }
    if (j > first)
        quick_sort(vet, first, j);
    if (i < final)
        quick_sort(vet, i, final);
}

int main()
{
    srand(time(NULL));
    const int qtd = 70;
    vector<int> vet(qtd, 0);

    int min = 10;
    int max = 400;

    for (int i = 0; i < qtd; i++)
        vet[i] = (rand() % (max - min + 1) + min);

    view_set_bar();
    view_set_faixa(0, qtd - 1);

    //minimum_sort(vet);
    quick_sort(vet, 0, vet.size());
    //bubble_sort(vet);

    view_lock();
    return 0;
}
