#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

int mdcComPassos(int a, int b) {
    int resto;
    while (b != 0) {
        resto = a % b;
        printf("Algoritmo de Euclides: %d mod %d = %d\n", a, b, resto);
        a = b;
        b = resto;
    }
    return a;
}

int inversoModular(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    int A = a, B = m;

    while (m != 0) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    printf("\nSubstituindo, temos que o inverso de %d em %d é %d.\n\n", A, B, x1); // Substituindo, temos que o inverso de 3 em 11 é 4.
    return x1;
}

int powMod(int base, int exp, int mod) {
    long long res = 1;
    long long b = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * b) % mod;
        b = (b * b) % mod;
        exp >>= 1;
    }
    return (int)res;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    printf("\nPedro Augusto Ribeiro Faitarone Bessa - 241040323\nYasmim de Souza Santos - 241040860\n\n");

    int H, G, Zn, x, n1;

    printf("Insira H: "); // H = 7
    scanf("%d", &H);
    printf("Insira G: "); // G = 3
    scanf("%d", &G);
    printf("Insira Zn: "); // Zn = 11
    scanf("%d", &Zn);
    printf("Insira x: "); // x = 10
    scanf("%d", &x);
    printf("Insira n1: "); // n1 = 13
    scanf("%d", &n1);
    printf("\n");

    int inverso = inversoModular(G, Zn);
    int a = (H * inverso) % Zn;

    printf("Fazendo a multiplicação modular: %d * %d mod %d = %d\n", H, inverso, Zn, a); // Fazendo a multiplicação modular: 7 * 4 mod 11 = 6
    printf("Sendo %d o inverso de %d.\n", inverso, G); // Sendo 4 o inverso de 3.

    int resultado = powMod(a, x, n1);
    printf("Valor final da congruência: %d\n", resultado); // Valor final da congruência: 4

    return 0;
}

