//
// Created by tk on 7/5/26.
//

#include "../includes/menu.h"
#include "../includes/positionStar.h"

#include <iostream>
#include <string>

using namespace std;

void menuPositionStar() {
    int star;

    while (true) {
        cout << "Qual estrela você deseja localizar?\n";
        for (int i = 0; i < stars.size(); i++) {
            cout << i + 1 << " - " << stars[i].name << "\n";
        }
        cout << "0 - Voltar para o menu\n";
        cin >> star;

        while (star < 0 || star > stars.size()) {
            cout << "Estrela inválida, digite um número válido!\n";
            cin >> star;
        }
        if (star == 0) {
            break;
        }
        calculatePositionStar(star - 1);
        int nextStep;
        cout << "E agora, o que você deseja fazer?\n";
        cout << "1 - Ver a localização de uma próxima estrela\n";
        cout << "0 - Voltar para o menu\n";
        cin >> nextStep;

        while (nextStep != 0 && nextStep != 1) {
            cout << "Ação inválida, por favor, digite ou 0 ou 1!\n";
            cin >> nextStep;
        }
        if (nextStep == 0) {
            break;
        }
    }
}
