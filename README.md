# Projeto Matemática Discreta 2 - 25/2

## :pencil: Autores

- Pedro Augusto Ribeiro Faitarone Bessa — 241040323
- Yasmim de Souza Santos — 241040860

## :book: Descrição do Projeto

Este repositório contém as soluções para a atividade avaliativa da disciplina Matemática Discreta 2, ofertada no segundo semestre de 2025 na Universidade de Brasília, Campus Gama. O projeto exige implementações em C de algoritmos de criptografia, aritmética modular, sincronização de ciclos e análise de divisores.

## :gear: Estrutura do Repositório

- **Questão 01:** Implementação do sistema RSA com fatoração ρ de Pollard e aplicação de teoremas modulares.
- **Questão 02:** Sincronização de chaves periódicas, inspirada no problema das cigarras periódicas.
- **Questão 03:** Cálculo da razão de eficiência de um número, utilizando funções aritméticas.
- **Questão 04:** Resolução de divisão modular e análise de congruências, com aplicação dos teoremas de Fermat e Euler.
  - :warning: Respostas da Questão 4.1 estão descritas no código por meio de comentários e da 4.2 estão na README.

## :white_check_mark: Respostas da Questão 4.2 — Verdadeiro ou Falso
- O algoritmo de Euclides estendido é utilizado para calcular o inverso modular de um número.  
  **Verdadeiro.** Por exemplo, para encontrar o inverso de 3 módulo 11, resolvemos 3 * x ≡ 1 (mod 11). O Euclides estendido encontra x = 4, pois 3 * 4 = 12 e 12 % 11 = 1.

- Se mdc(G, Zn) ≠ 1, o programa ainda consegue encontrar o inverso de G em Zn.  
  **Falso.** Por exemplo, para G = 6 e Zn = 9, mdc(6, 9) = 3. Não existe x tal que 6 * x ≡ 1 (mod 9), pois 6 e 9 não são coprimos.

- A operação (H * inverso) % Zn representa a divisão modular de H por G.  
  **Verdadeiro.** Se H = 7, G = 3, Zn = 11, o inverso de 3 módulo 11 é 4. Então, 7 * 4 = 28, e 28 % 11 = 6. Assim, 7 dividido por 3 módulo 11 é 6.

- Se n1 for primo, o código aplica o Pequeno Teorema de Fermat para simplificar o cálculo de a^x mod n1.  
  **Verdadeiro.** Por exemplo, para a = 2, x = 10, n1 = 13 (primo), 2^12 ≡ 1 (mod 13). Então, 2^10 mod 13 pode ser simplificado usando propriedades do teorema.

- A função powMod implementa o cálculo de potência modular utilizando multiplicações diretas sem otimização.  
  **Falso.** O cálculo eficiente usa exponenciação rápida. Por exemplo, para calcular 2^10 mod 13, em vez de multiplicar 2 dez vezes, o algoritmo usa quadrados sucessivos, reduzindo o número de operações.

- Quando o resultado do inverso é negativo, o código ajusta o valor somando o módulo m0.  
  **Verdadeiro.** Se o inverso de 3 módulo 11 fosse -7, ajustamos para -7 + 11 = 4, pois 4 está no intervalo de 0 a 10.

- O cálculo de φ(n1) (função totiente de Euler) é utilizado apenas quando n1 não é primo.  
  **Verdadeiro.** Se n1 = 15, φ(15) = 8. O Teorema de Euler diz que a^8 ≡ 1 (mod 15) se a e 15 são coprimos, e isso é usado para simplificar cálculos de potência modular quando n1 não é primo.
