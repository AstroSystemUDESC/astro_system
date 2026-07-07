#include "../includes/menu.h"
#include "../includes/positionStar.h"
#include "../includes/moon.h"
#include "../includes/formulas.h"
#include "../includes/planets.h"

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Função auxiliar interna para validação de opções dos menus da Isabelli
int lerOpcaoMenu() {
    int valor;
    while (true) {
        if (cin >> valor) {
            return valor;
        } else {
            cout << "\n[ERRO] Opção inválida! Digite um número inteiro: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

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

void menuCalcFormulas() {
    int subOpcao = -1;
    while (subOpcao != 0) {
        cout << "\n--- SUBMENU: FÓRMULAS ASTRONÔMICAS ---\n";
        cout << "1. Gravitação Universal\n";
        cout << "2. Leis de Kepler (3ª Lei)\n";
        cout << "3. Equivalência Massa-Energia (E=mc²)\n";
        cout << "4. Lei de Hubble\n";
        cout << "5. Luminosidade\n";
        cout << "6. Lei de Stefan-Boltzmann\n";
        cout << "0. Voltar ao Menu Principal\n";
        cout << "Escolha uma opção: ";
        
        subOpcao = lerOpcaoMenu();

        switch (subOpcao) {
            case 1: calcularGravitacao(); break;
            case 2: calcularKepler(); break;
            case 3: calcularEmc2(); break;
            case 4: calcularHubble(); break;
            case 5: calcularLuminosidade(); break;
            case 6: calcularStefanBoltzmann(); break;
            case 0: break;
            default: cout << "\nOpção inválida no módulo de fórmulas!\n"; break;
        }
    }
}

void menuPlanets() {
    int escolha = -1;
    while (escolha != 0) {
        cout << "\n--- SUBMENU: INFORMAÇÕES DOS PLANETAS ---\n";
        cout << "1. Mercúrio\n2. Vênus\n3. Terra\n4. Marte\n5. Júpiter\n6. Saturno\n7. Urano\n8. Netuno\n0. Voltar ao Menu Principal\n";
        cout << "Selecione um planeta (1-8): ";
        
        escolha = lerOpcaoMenu();

        switch (escolha) {
            case 1: imprimirPlaneta("Mercúrio", "167 °C", "3.70 m/s²", "3.285e23 kg", "57.91M km", "58d 15h", "88 dias", 0, "Exosfera", "Estável", "Difícil", 0.5); break;
            case 2: imprimirPlaneta("Vênus", "464 °C", "8.87 m/s²", "4.867e24 kg", "108.2M km", "243 dias", "225 dias", 0, "96.5% CO2", "Uniforme", "Excelente", 1.5); break;
            case 3: imprimirPlaneta("Terra", "15 °C", "9.81 m/s²", "5.972e24 kg", "149.6M km", "24h 00m", "365.25 dias", 1, "78% N2", "Verão/Inverno", "Visível", 1.0); break;
            case 4: imprimirPlaneta("Marte", "-62 °C", "3.71 m/s²", "6.390e23 kg", "227.9M km", "24h 37m", "687 dias", 2, "95% CO2", "Outono", "Fácil", 1.02); break;
            case 5: imprimirPlaneta("Júpiter", "-108 °C", "24.79 m/s²", "1.898e27 kg", "778.5M km", "9h 56m", "12 anos", 95, "89.8% H2", "Pouca variação", "Excelente", 0.41); break;
            case 6: imprimirPlaneta("Saturno", "-139 °C", "10.44 m/s²", "5.683e26 kg", "1.434B km", "10h 33m", "29 anos", 146, "96.3% H2", "Primavera", "Boa", 0.44); break;
            case 7: imprimirPlaneta("Urano", "-197 °C", "8.69 m/s²", "8.681e25 kg", "2.871B km", "17h 14m", "84 anos", 28, "82.5% H2", "Extrema", "Com Binóculos", 0.71); break;
            case 8: imprimirPlaneta("Netuno", "-201 °C", "11.15 m/s²", "1.024e26 kg", "4.495B km", "16h 06m", "165 anos", 16, "80% H2", "Estações", "Via Telescópio", 0.67); break;
            case 0: break;
            default: cout << "\n[ERRO] Seleção fora do intervalo!\n"; break;
        }
    }
}

void menuMoon() {
    int action;
    calcMoonPhase();
    cout << "0 - Voltar para o menu\n";
    cin >> action;

    while (action != 0) {
        cout << "Ação não existente, por favor, digite um número correto!\n";
        cin >> action;
    }
}