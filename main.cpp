#include <iostream>
#include "includes/positionStar.h"
#include "includes/menu.h"

using namespace std;

int main() {
    int action;

    populateStarsVector();

    while (true) {
        cout << "\nBem-vindo ao Astro System, o que você quer descobrir hoje?\n";
        cout << "------------------\n";
        cout << "1 - Posição de uma estrela no céu.\n";
        cout << "2 - Cálculo de fórmulas astronomicas\n";
        cout << "3 - Informações sobre planetas\n";
        cout << "4 - Informações sobre a Lua\n";
        cout << "0 - Sair\n";
        cin >> action;

        while (action < 0 || action > 4) {
            cout << "Ação inválida, por favor, digite um número entre 0 e 4: ";
            cin >> action;
        }

        if (action == 0) {
            break;
        }
        if (action == 1) {
            menuPositionStar();
        }
        if (action == 2) {
            menuCalcFormulas();
        }
        if (action == 3) {
            menuPlanets();
        }
        if (action == 4) {
            menuMoon();
        }
    }
    return 0;
}