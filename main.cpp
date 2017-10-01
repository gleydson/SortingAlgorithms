#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <SFML/Graphics.hpp>

#include "sortview.h"
#include "player.h"

using namespace std;

static SortView sview;

void bubble_sort(std::vector<int> &vet) {
    int tam = vet.size();
    int flag = 0;
    for (int i = 0; i < tam; i++) {
        for (int j = flag; j < tam; j++) {
            sview.show(vet, {i, j}, "gb");
            if (vet[j] < vet[i]) {
                sview.show(vet, {i, j}, "rb");
                std::swap(vet[i], vet[j]);
                sview.show(vet, {i, j}, "cb");
            }
        }
        flag++;
    }
}

/*
void bucket_sort(std::vector<int> &vet) {}
void insertion_sort(std::vector<int> &vet) {}
void merge_sort(std::vector<int> &vet) {}
*/

void quick_sort(std::vector<int> &vet, int first, int final) {
    int i, j, pivot, center;
    i = first;
    j = final;
    center = (first + final) / 2;
    pivot = vet[center];
    sview.show(vet, {i, j, center}, "gbr");
    while(i < j) {
        while(vet[i] < pivot) {
            i++;
            sview.show(vet, {i, j, center}, "gbr");
        }
        while(vet[j] > pivot) {
            j--;
            sview.show(vet, {i, j, center}, "gbr");
        }
        if (i <= j) {
            sview.show(vet, {i, j, center}, "gbr");
            std::swap(vet[i], vet[j]);
            i++;
            j--;
        }
    }
    if (j > first)
        quick_sort(vet, first, j);
    if(i < final)
        quick_sort(vet, i, final);
}

void minimum_sort(std::vector<int> &vet){
    int tam = vet.size();
    for(int i = 0; i < tam - 1; i++){
        for(int j = i + 1; j < tam; j++){
            sview.show(vet, {i, j}, "gb");
            if(vet[j] < vet[i]){
                sview.show(vet, {i, j}, "rb");
                std::swap(vet[i], vet[j]);
                sview.show(vet, {i, j}, "cb");
            }
        }
    }
}

std::vector<int> init_vet(int qtd, int min, int max){
    std::vector<int> vet;
    vet.reserve(qtd);
    for(int i = 0; i < qtd; i++){
        vet.push_back(rand() % (max - min + 1) + min);
    }
    return vet;
}

int main_sorts(){
    srand(time(NULL));
    my_player->autoplay = true;
    //sview.set_dot_view();
    sview.set_bar_view();
    sview.set_thickness(8);

    std::vector<int> vet = init_vet(70, 50, 300);

    int tam = vet.size();
    //minimum_sort(vet);
    //bubble_sort(vet);
    quick_sort(vet, 0, tam - 1);

    my_player->wait();
    return 0;
}


int main(){
    main_sorts();
}
