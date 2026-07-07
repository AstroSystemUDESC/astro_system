#include "../includes/planets.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void imprimirPlaneta(string nome, string temp, string grav, string massa, 
                     string dist, string dia, string ano, int luas, 
                     string comp, string estacao, string visivel, double fatorFuso) {
    
    cout << "\n========================================\n";
    cout << "DADOS TÉCNICOS DO PLANETA\n";
    cout << "========================================\n";
    cout << "Nome:                 " << nome << "\n";
    cout << "Temperatura Média:    " << temp << "\n";
    cout << "Gravidade:            " << grav << "\n";
    cout << "Massa:                " << massa << "\n";
    cout << "Distância do Sol:     " << dist << "\n";
    cout << "Duração do Dia:       " << dia << "\n";
    cout << "Duração do Ano:       " << ano << "\n";
    cout << "Quantidade de Luas:   " << luas << "\n";
    cout << "Composição Atmosfera: " << comp << "\n";
    cout << "Estação Atual:        " << estacao << "\n";
    cout << "Visibilidade:         " << visivel << "\n";

    time_t t = time(nullptr);
    tm* lt = localtime(&t);
    int horaSimulada = static_cast<int>((lt->tm_hour + lt->tm_min / 60.0) * fatorFuso) % 24;
    if (horaSimulada < 0) horaSimulada += 24;

    cout << "Hora Local Planetária: " << setfill('0') << setw(2) << horaSimulada 
         << ":" << setfill('0') << setw(2) << lt->tm_min << " (Fuso Planetário)\n";
    cout << "========================================\n";
}