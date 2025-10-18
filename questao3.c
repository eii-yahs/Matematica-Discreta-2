#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Teste de primalidade simples por tentativa, suficiente para valores pequenos.
int primo(int n){
    if(n < 2){
        return 0;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

// Fatoracao prima por tentativa, mostrando cada divisor encontrado.
void divisaoprima(int div[], int k){
    int j = 0;
    int aux = k;
    printf("===================================\n");
    printf("PASSO 1: Fatoracao prima de %d\n", k);
    printf("===================================\n");
    for(int n = 2; n <= k; n++){
        if(primo(n)){
            while(aux % n == 0 && aux > 1){
                div[j++] = n;
                printf("  1.%d) Divisor primo encontrado: %d, novo valor de aux: %d\n", j, n, aux/n);
                aux /= n;
            }
        }
    }
    if(j == 0) {
        printf("  Nenhum divisor primo encontrado (numero e primo ou menor que 2)\n");
    }
}

// Mostra os fatores primos e seus expoentes.
void expoente(int div[], int e[]){
    printf("\n===================================\n");
    printf("PASSO 2: Primos divisores de N com expoentes\n");
    printf("===================================\n  ");
    int i = 0, passo = 1;
    while(div[i] != 0){
        int p = div[i];
        int count = 0;
        while(div[i] == p){
            count++;
            i++;
        }
        printf("%d.%d) %d^%d\n  ", 2, passo++, p, count);
    }
}

int main(){
    printf("\nPedro Augusto Ribeiro Faitarone Bessa - 241040323\n");
    printf("Yasmim de Souza Santos - 241040860\n\n");

    // PASSO 0: Leitura do numero
    printf("===================================\n");
    printf("PASSO 0: Leitura do numero\n");
    printf("===================================\n");
    int k;
    printf("  0.1) Insira um numero inteiro N: ");
    scanf("%d", &k);
    printf("\n");

    int div[100000] = {0};
    divisaoprima(div, k);

    int exp[101] = {0};
    expoente(div, exp);

    // PASSO 3: Soma dos divisores primos
    printf("\n===================================\n");
    printf("PASSO 3: Soma dos divisores primos\n");
    printf("===================================\n");
    int soma = 0, q = 0, passo = 1;
    for(int i = 0; div[i] != 0; i++){
        soma += div[i];
        q++;
        printf("  3.%d) Somando divisor primo: %d, soma parcial: %d\n", passo++, div[i], soma);
    }

    // PASSO 4: Resultado da soma
    printf("\n===================================\n");
    printf("PASSO 4: Resultado da soma dos divisores primos\n");
    printf("===================================\n");
    printf("  4.1) Soma dos divisores primos de N: %d\n\n", soma);

    // PASSO 5: Calculo da razao de eficiencia
    printf("===================================\n");
    printf("PASSO 5: Calculo da razao de eficiencia\n");
    printf("===================================\n");
    if(q > 0){
        float razao = (float)soma / q;
        printf("  5.1) Calculando razao de eficiencia: %.2f = %d / %d\n", razao, soma, q);
        printf("  5.2) Razao de eficiencia: %.2f\n\n", razao);
    } else {
        printf("  5.1) O numero nao possui divisores primos.\n\n");
    }

    return 0;
}

