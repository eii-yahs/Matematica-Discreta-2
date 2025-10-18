#include <stdio.h>
#include <stdlib.h>

// Função para calcular o MDC usando Algoritmo de Euclides
int calcularMdc(int a, int b, int passo) {
    int resto;
    int iteracao = 1;
    printf("\n      --- PASSO %d: Calculo do MDC(%d, %d) ---\n", passo, a, b);
    while (b != 0) {
        resto = a % b;
        printf("        %d.%d) a = %d, b = %d, resto = %d\n", passo, iteracao, a, b, resto);
        a = b;
        b = resto;
        iteracao++;
    }
    printf("        %d.%d) MDC final = %d\n", passo, iteracao, a);
    return a;
}

// Função para calcular valor absoluto
int valorAbsoluto(int x) {
    return (x < 0) ? -x : x;
}

// Fatoracao de um numero usando Pollard Rho
int fatorarPollardRho(int n, int passo) {
    int x = 2, y = 2, d = 1;
    int iteracao = 1;
    printf("\n===================================\n");
    printf("PASSO %d: Fatoracao de %d\n", passo, n);
    printf("===================================\n");

    while (d == 1) {
        x = (x * x + 1) % n;
        y = (y * y + 1) % n;
        y = (y * y + 1) % n;
        d = calcularMdc(valorAbsoluto(x - y), n, passo * 10 + iteracao);
        printf("  %d.%d) Iteracao: x = %d, y = %d, mdc = %d\n", passo, iteracao, x, y, d);
        iteracao++;
    }

    if (d == n) {
        printf("  %d.%d) Nao foi possivel encontrar fator nao trivial.\n", passo, iteracao);
        return -1;
    } else {
        printf("  %d.%d) Fator encontrado: %d\n", passo, iteracao, d);
        return d;
    }
}

// Algoritmo Estendido de Euclides para inverso modular=============================
int inversoModular(int e, int phi, int passo) {
    int t = 0, novoT = 1;
    int r = phi, novoR = e;
    int quociente, temp, iteracao = 1;

    printf("\n===================================\n");
    printf("PASSO %d: Inverso Modular\n", passo);
    printf("===================================\n");

    while (novoR != 0) {
        quociente = r / novoR;
        temp = novoT; novoT = t - quociente * novoT; t = temp;
        temp = novoR; novoR = r - quociente * novoR; r = temp;

        printf("  %d.%d) q = %d, t = %d, novoT = %d, r = %d, novoR = %d\n", passo, iteracao, quociente, t, novoT, r, novoR);
        iteracao++;
    }

    if (r > 1) {
        printf("  %d.%d) Erro: %d nao possui inverso modular.\n", passo, iteracao, e);
        return -1;
    }

    if (t < 0)
        t += phi;

    printf("  %d.%d) Inverso modular encontrado: %d\n", passo, iteracao, t);
    return t;
}
// Exponenciacao modular detalhada (base^expoente mod modulo)
long long exponenciacaoModular(long long base, long long expoente, long long modulo, int passo, int subpasso) {
    long long resultado = 1;
    int iteracao = 1;

    printf("\n      --- PASSO %d.%d: Exponenciacao Modular ---\n", passo, subpasso);
    printf("      Calculando (%lld^%lld) mod %lld\n", base, expoente, modulo);

    while (expoente > 0) {
        if (expoente % 2 == 1) {
            resultado = (resultado * base) % modulo;
            printf("        %d.%d.%d) Expoente impar, resultado = %lld\n", passo, subpasso, iteracao, resultado);
        }
        base = (base * base) % modulo;
        expoente = expoente / 2;
        printf("        %d.%d.%d) Atualizando base = %lld, expoente restante = %lld\n", passo, subpasso, iteracao, base, expoente);
        iteracao++;
    }

    printf("      %d.%d.%d) Resultado final: %lld\n", passo, subpasso, iteracao, resultado);
    return resultado;
}

// Conversao de letras para numeros (A=11, B=12, ..., ' '=00)
int letraParaCodigo(char c) {
    if (c == ' ')
        return 0;
    else
        return (c - 'A' + 11);
}

// Conversao de numeros para letras
char codigoParaLetra(int codigo) {
    if (codigo == 0)
        return ' ';
    else
        return (codigo - 11 + 'A');
}

int main() {
    printf("\nPedro Augusto Ribeiro Faitarone Bessa - 241040323\nYasmim de Souza Santos - 241040860\n");

    int n1, n2, p, q, n, phi, e = 2, d;
    char mensagem[100];
    long long cifrado[100];
    int i;

    printf("\n===================================\n");
    printf("PASSO 0: Leitura dos numeros\n");
    printf("===================================\n");

    printf("  0.1) Digite o primeiro numero composto (N1 entre 100 e 9999): ");
    scanf("%d", &n1);
    printf("  0.2) Digite o segundo numero composto (N2 entre 100 e 9999): ");
    scanf("%d", &n2);


    // Passo 1: Fatoracao Pollard Rho

    p = fatorarPollardRho(n1, 1);
    q = fatorarPollardRho(n2, 2);

    if (p == -1 || q == -1) {
        printf("Erro: Nao foi possivel fatorar um dos numeros.\n");
        return 1;
    }

    printf("\n===================================\n");
    printf("PASSO 3: Fatores encontrados\n");
    printf("===================================\n");
    printf("  3.1) p = %d\n", p);
    printf("  3.2) q = %d\n", q);

    // Passo 4: Geracao das chaves RSA
    n = p * q;
    phi = (p - 1) * (q - 1);

    printf("\n===================================\n");
    printf("PASSO 4: Geracao das chaves RSA\n");
    printf("===================================\n");

    printf("  4.1) n = p * q = %d * %d = %d\n", p, q, n);
    printf("  4.2) Totiente de Euler phi = (%d - 1) * (%d - 1) = %d\n", p, q, phi);

    printf("  4.3) Escolhendo o menor e tal que mdc(e, phi) = 1\n");
    while (calcularMdc(e, phi, 4) != 1) {
        e++;
    }
    printf("  4.5) Valor escolhido para e: %d\n", e);

    d = inversoModular(e, phi, 5);

    printf("\n===================================\n");
    printf("PASSO 6: Chaves geradas\n");
    printf("===================================\n");
    printf("  6.1) Chave publica: (n = %d, e = %d)\n", n, e);
    printf("  6.2) Chave privada: (n = %d, d = %d)\n", n, d);

    // Passo 7: Leitura da mensagem
    printf("\n===================================\n");
    printf("PASSO 7: Leitura da mensagem\n");
    printf("===================================\n");
    printf("  7.1) Digite a mensagem (letras maiusculas e espacos): ");
    scanf(" %[^\n]", mensagem);

    // Passo 8: Conversao da mensagem em numeros
    printf("\n===================================\n");
    printf("PASSO 8: Conversao para numeros\n");
    printf("===================================\n");
    for (i = 0; mensagem[i] != '\0'; i++) {
        int codigo = letraParaCodigo(mensagem[i]);
        printf("  8.%d) Caractere '%c' -> Codigo %02d\n", i+1, mensagem[i], codigo);
    }

    // Passo 9: Criptografando mensagem
    printf("\n===================================\n");
    printf("PASSO 9: Criptografando mensagem\n");
    printf("===================================\n");
    for (i = 0; mensagem[i] != '\0'; i++) {
        int codigo = letraParaCodigo(mensagem[i]);
        cifrado[i] = exponenciacaoModular(codigo, e, n, 9, i+1);
        printf("    9.%d.2) Resultado criptografado: %lld\n", i+1, cifrado[i]);
    }

    printf("\n===================================\n");
    printf("PASSO 10: Mensagem criptografada final\n");
    printf("===================================\n");
    for (i = 0; mensagem[i] != '\0'; i++) {
        printf("%lld ", cifrado[i]);
    }
    printf("\n");

    // Passo 11: Descriptografando mensagem
    printf("\n===================================\n");
    printf("PASSO 11: Descriptografando mensagem\n");
    printf("===================================\n");
    char mensagemDecifrada[100];
    for (i = 0; mensagem[i] != '\0'; i++) {
        long long decodificado = exponenciacaoModular(cifrado[i], d, n, 11, i+1);
        mensagemDecifrada[i] = codigoParaLetra(decodificado);
        printf("    11.%d) Reconversao numerica -> Letra: '%c'\n", i+1, mensagemDecifrada[i]);
    }
    mensagemDecifrada[i] = '\0';


    // Resultados finais
    printf("\n===================================\n");
    printf("PASSO 12: Resultados finais\n");
    printf("===================================\n");
    printf("  12.1) Mensagem criptografada: ");
    for (i = 0; mensagem[i] != '\0'; i++) printf("%lld ", cifrado[i]);
    printf("\n  12.2) Mensagem decriptografada: %s\n\n", mensagemDecifrada);

    return 0;
}
