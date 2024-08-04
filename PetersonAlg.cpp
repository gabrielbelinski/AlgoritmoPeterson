#include <iostream>
#include <unistd.h>

int vez; // Identifica qual processo está na vez
bool processos[2] = {false, false}; 
// Se os processos estão prontos para entrar na RC (Região Crítica), será definido o valor true, por padrão os valores são false

void entraRegiao(int processo){
    int outroProcesso = 1 - processo; // Identifica a posição do outro processo no vetor
    processos[processo] = true; // Se true, identifica que o processo na dada posição tem interesse em acessar a RC
    vez = processo; // Define qual processo está na vez
    while((vez == processo) && processos[outroProcesso] == true); // Loop persiste até que o processo requisitante saia da RC
}

void saiRegiao(int processo){
    processos[processo] = false; // Interrompe o loop, permitindo que o outro processo entre na região critica
}

void processo1() {
    for(int i = 0; i < 3; i++) {
        std::cout << "Processo 1 entrou na regiao critica" << std::endl;
        entraRegiao(0);
        std::cout << "Processo 1 esta na regiao critica" << std::endl;
        saiRegiao(0);
        std::cout << "Processo 1 saiu da regiao critica" << std::endl;
        usleep(100000); 
        std::cout << std::endl;
    }
}

void processo2() {
    for(int i = 0; i < 3; i++) {
        std::cout << "Processo 2 entrou na regiao critica" << std::endl;
        entraRegiao(1);
        std::cout << "Processo 2 esta na regiao critica" << std::endl;
        saiRegiao(1);
        std::cout << "Processo 2 saiu da regiao critica" << std::endl;
        usleep(100000); 
        std::cout << std::endl;
    }
}

int main(){

    processo1();
    std::cout << std::endl << std::endl;
    processo2();

    return 0;
}