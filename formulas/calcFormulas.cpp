#include "../includes/formulas.h"
#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

const double G = 6.67430e-11;
const double C_LUZ = 299792458.0;
const double SIGMA = 5.670374419e-8;
const double PI = 3.141592653589793;

double lerNumero(const string& mensagem) {
    double valor;
    while (true) {
        cout << mensagem;
        if (cin >> valor) {
            return valor;
        } else {
            cout << "\n[ERRO] Entrada inválida! Digite um número válido.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void calcularGravitacao() {
    cout << "\n========================================\n";
    cout << "ASTRO SYSTEM MODULE: UNIVERSAL GRAVITATION\n";
    cout << "========================================\n";
    double m1 = lerNumero("Digite a massa do planeta (kg): ");
    double m2 = lerNumero("Digite a massa da Lua/satélite (kg): ");
    double d = lerNumero("Digite a distância (m): ");

    if (d <= 0) {
        cout << "\n[ERRO] A distância deve ser maior que zero!\n";
        return;
    }
    double forca = G * (m1 * m2) / pow(d, 2);
    cout << "\n[SAÍDA]\nForça gravitacional: " << scientific << setprecision(2) << forca << " N\n";
}

void calcularKepler() {
    cout << "\n========================================\n";
    cout << "ASTRO SYSTEM MODULE: KEPLER'S 3rd LAW\n";
    cout << "========================================\n";
    double a = lerNumero("Digite o semi-eixo maior da órbita (m): ");
    double M = lerNumero("Digite a massa do corpo central (kg): ");

    if (a <= 0 || M <= 0) {
        cout << "\n[ERRO] Os valores devem ser maiores que zero!\n";
        return;
    }
    double periodo = sqrt((4.0 * PI * PI * pow(a, 3)) / (G * M));
    cout << "\n[SAÍDA]\nPeríodo Orbital (T): " << scientific << setprecision(2) << periodo << " s\n";
    cout << "Em dias terrestres: " << fixed << setprecision(2) << (periodo / 86400.0) << " dias\n";
}

void calcularEmc2() {
    cout << "\n========================================\n";
    cout << "ASTRO SYSTEM MODULE: MASS-ENERGY (E=mc²)\n";
    cout << "========================================\n";
    double m = lerNumero("Digite a massa (kg): ");

    if (m < 0) {
        cout << "\n[ERRO] A massa não pode ser negativa!\n";
        return;
    }
    double energia = m * pow(C_LUZ, 2);
    cout << "\n[SAÍDA]\nEnergia Equivalente (E): " << scientific << setprecision(2) << energia << " J\n";
}

void calcularHubble() {
    cout << "\n========================================\n";
    cout << "ASTRO SYSTEM MODULE: HUBBLE'S LAW\n";
    cout << "========================================\n";
    double d = lerNumero("Digite a distância da galáxia (Mpc): ");
    double H0 = lerNumero("Digite a Constante de Hubble H0 (Padrão ~70): ");

    double v = H0 * d;
    cout << "\n[SAÍDA]\nVelocidade de recessão (v): " << fixed << setprecision(2) << v << " km/s\n";
}

void calcularLuminosidade() {
    cout << "\n========================================\n";
    cout << "ASTRO SYSTEM MODULE: LUMINOSITY\n";
    cout << "========================================\n";
    double d = lerNumero("Digite a distância da estrela (m): ");
    double F = lerNumero("Digite o fluxo bolométrico (W/m²): ");

    if (d <= 0 || F < 0) {
        cout << "\n[ERRO] Valores inválidos!\n";
        return;
    }
    double L = 4.0 * PI * pow(d, 2) * F;
    cout << "\n[SAÍDA]\nLuminosidade Estelar Total (L): " << scientific << setprecision(2) << L << " W\n";
}

void calcularStefanBoltzmann() {
    cout << "\n========================================\n";
    cout << "ASTRO SYSTEM MODULE: STEFAN-BOLTZMANN\n";
    cout << "========================================\n";
    double R = lerNumero("Digite o raio da estrela (m): ");
    double T = lerNumero("Digite a temperatura efetiva (K): ");

    if (R <= 0 || T < 0) {
        cout << "\n[ERRO] Valores inválidos!\n";
        return;
    }
    double potencia = (4.0 * PI * pow(R, 2)) * SIGMA * pow(T, 4);
    cout << "\n[SAÍDA]\nPotência Total Irradiada (P): " << scientific << setprecision(2) << potencia << " W\n";
}