#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//incluindo bibliotecas necessárias para o funcionamento do programa

//biblioteca de variaveis 
char estado1[3], codigo1[3], nome1[30];
char estado2[3], codigo2[3], nome2[30];
unsigned long int populacao1, populacao2;
float area1, pib1;
float area2, pib2;
int turisticos1, turisticos2;
float densidade1, densidade2;
float percapta1, percapta2;
float superpoder1, superpoder2;
int escolha_comparacao;


void limparBuffer() { // Função para limpar o buffer do stdin depois de cada coleta de dados
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    setlocale(LC_ALL, "Portuguese");//define o idioma do sistema 

    printf("Cadastro de cartas Supertrunfo: \n");

//cadastro da carta 1
    printf("\nCarta 1: ");
    printf("\nEstado(a - h): ");
    scanf("%1s", estado1);
    limparBuffer();

    printf("\nCódigo da carta(1 - 4): ");
    scanf("%1s", codigo1);
    limparBuffer();

    printf("\nNome da cidade: ");
    fgets(nome1, 30, stdin);
    nome1[strlen(nome1) - 1] = '\0'; // substituí o '\n'(sempre um fgets termina lendo o \n) pelo '\0' para evitar problemas de leitura
    limparBuffer();

    printf("\nPopulação: ");
    scanf("%lu", &populacao1);
    limparBuffer();

    printf("\nÁrea: ");
    scanf("%f", &area1);
    limparBuffer();

    printf("\nPIB: ");
    scanf("%f", &pib1);
    limparBuffer();

    printf("\nPontos Turísticos: ");
    scanf("%d", &turisticos1);
    limparBuffer();

    densidade1 = populacao1 / area1;
    percapta1 = pib1 / populacao1;
    superpoder1 = (float)populacao1 + area1 + pib1 + turisticos1 + percapta1 - densidade1;
//final do cadastro da carta 1

//cadastro da carta 2
    printf("\nCarta 2: ");
    printf("\nEstado(A - H): ");
    scanf("%1s", estado2);
    limparBuffer();

    printf("\nCódigo da carta(1 - 4): ");
    scanf("%1s", codigo2);
    limparBuffer();

    printf("\nNome da cidade: ");
    fgets(nome2, 30, stdin);
    nome2[strlen(nome2) - 1] = '\0'; // substituí o '\n'(sempre um fgets termina lendo o \n) pelo '\0' para evitar problemas de leitura
    limparBuffer();

    printf("\nPopulação: ");
    scanf("%lu", &populacao2);
    limparBuffer();

    printf("\nÁrea: ");
    scanf("%f", &area2);
    limparBuffer();

    printf("\nPIB: ");
    scanf("%f", &pib2);
    limparBuffer();

    printf("\nPontos Turísticos: ");
    scanf("%d", &turisticos2);
    limparBuffer();

    densidade2 = populacao2 / area2;
    percapta2 = pib2 / populacao2;
    superpoder2 = (float)populacao2+ area2 + pib2 + turisticos2 + percapta2 - densidade2;
//final do cadastro da carta 2


// exibição:
    printf("\n---------------------------");
    printf("\nDados da Carta 1:");
    printf("\nCódigo: %s %s", estado1, codigo1);
    printf("\nNome da cidade: %s", nome1);
    printf("\nPopulação: %lu", populacao1);
    printf("\nÁrea: %.2fkm²", area1);
    printf("\nPIB: R$%.2f", pib1);
    printf("\nPontos Turísticos: %d", turisticos1);
    printf("\nDensidade populacional: %.2fhab/km²", densidade1);
    printf("\nPIB per capita: R$%.2f", percapta1);
    printf("\nSuperpoder: %.2f", superpoder1);

    printf("\n---------------------------");
    printf("\nDados da Carta 2:");
    printf("\nCódigo: %s %s", estado2, codigo2);
    printf("\nNome da cidade: %s", nome2);
    printf("\nPopulação: %lu", populacao2);
    printf("\nÁrea: %.2fkm²", area2);
    printf("\nPIB: R$%.2f", pib2);
    printf("\nPontos Turísticos: %d", turisticos2);
    printf("\nDensidade populacional: %.2fhab/km²", densidade2);
    printf("\nPIB per capita: R$%.2f", percapta2);
    printf("\nSuperpoder: %.2f", superpoder2);
    printf("\n---------------------------");
//fim da exibição

//comparação
    printf("\nComparação de cartas: ");
    printf("\nPopulação: ");
    populacao1 > populacao2 ? printf("Carta 1 venceu") : printf("Carta 2 venceu");

    printf("\nÁrea: ");
    area1 > area2 ? printf("Carta 1 venceu") : printf("Carta 2 venceu");

    printf("\nPIB: ");
    pib1 > pib2 ? printf("Carta 1 venceu") : printf("Carta 2 venceu");

    printf("\nPontos Turísticos: ");
    turisticos1 > turisticos2 ? printf("Carta 1 venceu") : printf("Carta 2 venceu");

    printf("\nDensidade: ");
    densidade1 < densidade2 ? printf("Carta 1 venceu") : printf("Carta 2 venceu");
    
    printf("\nPib per capta: ");
    percapta1 > percapta2 ? printf("Carta 1 venceu") : printf("Carta 2 venceu");

    printf("\nSuperpoder: ");
    superpoder1 > superpoder2 ? printf("Carta 1 venceu") : printf("Carta 2 venceu");
    printf("\n---------------------------");
//fim da comparação


return 0;   
}
