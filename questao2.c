#include <stdio.h>

// Algoritmo de Euclides recursivo para MDC, pois é eficiente e simples de implementar.
int mdc_entre_dois(int a, int b) {
    if (b == 0)
        return a;
    return mdc_entre_dois(b, a % b);
}

// Calcula o MDC de um vetor de inteiros, mostrando o passo a passo.
int mdc_entre_varios(int numeros[], int quantidade){
    int resultado = numeros[0];
    printf("===================================\n");
    printf("PASSO 1: Calculo do MDC entre varios numeros\n");
    printf("===================================\n");
    for(int i = 1; i < quantidade; i++){
        int anterior = resultado;
        resultado = mdc_entre_dois(resultado, numeros[i]);
        printf("  1.%d) MDC(%d, %d) = %d\n", i, anterior, numeros[i], resultado);
    }
    printf("  MDC final entre todos: %d\n\n", resultado);
    return resultado;
}

// Calcula o MMC de dois numeros usando a relacao MMC(a, b) = (a * b) / MDC(a, b)
int mmc_entre_dois(int a, int b) {
    return (a / mdc_entre_dois(a, b)) * b;
}

// Calcula o MMC de um vetor de inteiros, mostrando o passo a passo.
int mmc_entre_varios(int numeros[], int quantidade) {
    int resultado = numeros[0];
    printf("===================================\n");
    printf("PASSO 2: Calculo do MMC entre varios numeros\n");
    printf("===================================\n");
    for (int i = 1; i < quantidade; i++) {
        int anterior = resultado;
        resultado = mmc_entre_dois(resultado, numeros[i]);
        printf("  2.%d) MMC(%d, %d) = %d\n", i, anterior, numeros[i], resultado);
    }
    printf("  MMC final entre todos: %d\n\n", resultado);
    return resultado;
}

int main(){
    printf("\nPedro Augusto Ribeiro Faitarone Bessa - 241040323\n");
    printf("Yasmim de Souza Santos - 241040860\n\n");

    // PASSO 0: Leitura dos dados
    printf("===================================\n");
    printf("PASSO 0: Leitura dos dados\n");
    printf("===================================\n");

    int n;
    printf("  0.1) Insira o numero de chaves: ");
    scanf("%d", &n);

    int c[n];
    printf("  0.2) Insira o ciclo de cada chave:\n");
    for(int i = 0; i < n; i++){
        printf("       Chave %d: ", i + 1);
        scanf("%d", &c[i]);
    }
    printf("\n");

    // PASSO 1: Calculo do MDC
    int mdc_final = mdc_entre_varios(c, n);

    // PASSO 2: Calculo do MMC
    int mmc_final = mmc_entre_varios(c, n);

    // PASSO 3: Analise do resultado
    printf("===================================\n");
    printf("PASSO 3: Analise do resultado\n");
    printf("===================================\n");
    printf("  3.1) MDC final entre todos: %d\n", mdc_final);
    printf("  3.2) MMC final entre todos: %d\n", mmc_final);

    if(mmc_final <= 50 && mmc_final >= 1){
        printf("  3.3) O primeiro ano em que todas as chaves podem ser utilizadas e: %d\n\n", mmc_final);
    }
    else{
        printf("  3.3) Nao foi possivel encontrar um ano em comum para que todas as chaves fossem utilizadas\n\n");
    }

    return 0;
}
