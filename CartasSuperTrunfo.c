#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
//incluindo bibliotecas necessárias para o funcionamento do programa


/* Definindo a estrutura de todos os estados, possuindo nome, cidades, e para cada cidade, populacao, area, pib e pontos turisticos.
    Além disso, possui seus valores percapta, densidade e total de pontos(soma de seus outros atributos)
*/
typedef struct {
    char nome[50];
    char cidade[4][50];
    int populacao[4];
    float area[4];
    float pib[4];
    int turisticos[4];
    float percapta[4];
    float densidade[4];
    float total[4];
} Estados; 

Estados estado[8];//cria 8 estados do tipo Estados

int main() {
    setlocale(LC_ALL, "Portuguese");
    strcpy(estado[0].nome, "A");//strcpy adiciona a variavel estado[0].nome o valor "A"
    strcpy(estado[1].nome, "B");//strcpy adiciona a variavel estado[1].nome o valor "B"
    strcpy(estado[2].nome, "C");//strcpy adiciona a variavel estado[2].nome o valor "C"
    strcpy(estado[3].nome, "D");//strcpy adiciona a variavel estado[3].nome o valor "D"
    strcpy(estado[4].nome, "E");//strcpy adiciona a variavel estado[4].nome o valor "E"
    strcpy(estado[5].nome, "F");//strcpy adiciona a variavel estado[5].nome o valor "F"
    strcpy(estado[6].nome, "G");//strcpy adiciona a variavel estado[6].nome o valor "G"
    strcpy(estado[7].nome, "H");//strcpy adiciona a variavel estado[7].nome o valor "H"
    //strcpy significa "string copy" e é uma função que atribui um valor a uma string ou vetor de caracteres

    printf("Digite os dados das cidades do estado A: \n");
    for ( int i = 0; i < 4; i++){
        printf("Cidade %d", i+1);
        printf("\nNome: ");
        fgets(estado[0].cidade[i], 50, stdin);//usa-se fgets para ler strings com espaços
        estado[0].cidade[i][strlen(estado[0].cidade[i]) - 1] = '\0';//retira o \n do final da string
        printf("População: ");
        scanf("%d", &estado[0].populacao[i]);
        printf("Área: ");
        scanf("%f", &estado[0].area[i]);
        printf("PIB: ");
        scanf("%f", &estado[0].pib[i]);
        printf("Pontos turísticos: ");
        scanf("%d", &estado[0].turisticos[i]);
        estado[0].percapta[i] = estado[0].pib[i] / estado[0].populacao[i];
        estado[0].densidade[i] = estado[0].populacao[i] / estado[0].area[i];
        estado[0].total[i] = estado[0].populacao[i] + estado[0].area[i] + estado[0].pib[i] + estado[0].turisticos[i];
        /*ja adicionei dentro do loop os valores de percapta, densidade e total de pontos, sempre que
        terminar de adicionar os dados de uma cidade, ele calcula esses valores e ja adiciona a cidade referente*/


        int c;
        while ((c = getchar()) != '\n' && c != EOF);//limpa o buffer do stdin, necessário para evitar erros de leitura de dados no fgets
        //cria um loop para adicionar os dados das cidades do estado A, enquanto o contador i for menor que 4 (4 cidades, 0 a 3) ele repete o processo
        //para economizar linhas de código, o processo é o mesmo para todos os estados, só mudando o índice do estado(estado[0], estado[1], estado[2], etc) e o nome do estado(A, B, C, etc)    
    }
    
    /*
    como eu me adiantei em algumas matérias(curiosidade de programar kkk), ja tentei fazer de formas mais complexas, porém me perdia sempre que tentava
    me aprofundar demais em muitas coisas novas e acabei fazendo de uma forma mais simples,
    fora que não é o objetivo do exercicio fazer de tal forma, por isso o codigo está mais simples
    */

   for (int i = 0; i < 4; i++) {
       printf("\nCidade %d", i+1);
       printf("\nNome: %s", estado[0].cidade[i]);
       printf("\nPopulação: %d pessoas", estado[0].populacao[i]);
       printf("\nÁrea: %.2fm²", estado[0].area[i]);
       printf("\nPIB: R$%.2f", estado[0].pib[i]);
       printf("\nPontos turísticos: %d pontos turísticos", estado[0].turisticos[i]);
       printf("\nPIB percapta: R$%.2f", estado[0].percapta[i]);
       printf("\nDensidade: %.2f pessoas por m²", estado[0].densidade[i]);
       printf("\nTotal de pontos: %.2f pontos", estado[0].total[i]);
       //exibe os dados das cidades do estado[0](A) com um loop, exibindo desde de .cidade[0] até cidade[3]
   }


    /*Já foi feito o cadastro do estado A por completo, se fosse feito conforme a atividade, seria feito para todos os estados, como
    ja explicado, criando novos loops semelhantes, tanto de entrada e de exibição de dados, só mudando o [x] de cada estado, agora 
    mesmo sendo adiantado na matéria, acho mais organizado o uso de menus interativos, resumidos, pelo fato de economizar linhas de codigo,
    mas bem explicados*/

    printf("\n\n");

    printf("De qual estado deseja comparar as cidades? (A-H): ");
    printf("\n");
    printf("1- A\n 0- Sair\n");
    //printf("2- B\n 3- C\n 4- D\n 5- E\n 6- F\n 7- G\n 8- H\n");
    /*Menu para escolher o estado, claro que do B ao H não irá funcionar nesse codigo ainda, mas fica o modelo*/
    
    int escolha;
    scanf("%d", &escolha);
    switch (escolha)
    {
    case 1:
        printf("Escolha a primeira cidade para comparar (1 a 4): ");
        int cidade1, cidade2;
        scanf("%d", &cidade1);
        printf("Escolha a segunda cidade para comparar (1 a 4): ");
        scanf("%d", &cidade2);
        
        //le os valores das cidades a serem comparadas
        cidade1--;//ajusta o indice para zero-based(decrementa, pois os arrays se iniciam em [0]) para comparar com o array
        cidade2--;//ajusta o indice para zero-based(decrementa, pois os arrays se iniciam em [0]) para comparar com o array

        printf("\nComparando cidades:\n");
        printf("Cidade 1 foi escolhida: %s\n", estado[0].cidade[cidade1]);
        printf("Cidade 2 foi escolhida: %s\n", estado[0].cidade[cidade2]);
        printf("\n");
        printf("Diferença de pontos: %.2f pontos \n", estado[0].total[cidade1] - estado[0].total[cidade2]);
        printf("Diferença de densidade: %.2f pessoas por m²\n", estado[0].densidade[cidade1] - estado[0].densidade[cidade2]);
        printf("Diferença de PIB per capita: R$%.2f\n", estado[0].percapta[cidade1] - estado[0].percapta[cidade2]);
        printf("Diferença de área: %.2fm²\n", estado[0].area[cidade1] - estado[0].area[cidade2]);
        printf("Diferença de população: %d pessoas\n", estado[0].populacao[cidade1] - estado[0].populacao[cidade2]);
        printf("Diferença de pontos turísticos: %d pontos turísticos\n", estado[0].turisticos[cidade1] - estado[0].turisticos[cidade2]);
        //exibe as diferenças entre as cidades escolhidas
        printf("\n");
        estado[0].total[cidade1] > estado[0].total[cidade2] ? printf("Cidade com mais pontos: %s\n", estado[0].cidade[cidade1]) : printf("Cidade com a maior quantidade ou igual de pontos: %s\n", estado[0].cidade[cidade2]);
        estado[0].densidade[cidade1] > estado[0].densidade[cidade2] ? printf("Cidade com maior densidade: %s\n", estado[0].cidade[cidade1]) : printf("Cidade com a maior quantidade ou igual de densidade: %s\n", estado[0].cidade[cidade2]);
        estado[0].percapta[cidade1] > estado[0].percapta[cidade2] ? printf("Cidade com maior PIB per capita: %s\n", estado[0].cidade[cidade1]) : printf("Cidade com a maior quantidade ou igual de PIB per capita: %s\n", estado[0].cidade[cidade2]);
        estado[0].area[cidade1] > estado[0].area[cidade2] ? printf("Cidade com maior área: %s\n", estado[0].cidade[cidade1]) : printf("Cidade com a maior quantidade ou igual de área: %s\n", estado[0].cidade[cidade2]);
        estado[0].populacao[cidade1] > estado[0].populacao[cidade2] ? printf("Cidade com maior população: %s\n", estado[0].cidade[cidade1]) : printf("Cidade com a maior quantidade ou igual de população: %s\n", estado[0].cidade[cidade2]);
        estado[0].turisticos[cidade1] > estado[0].turisticos[cidade2] ? printf("Cidade com mais pontos turísticos: %s\n", estado[0].cidade[cidade1]) : printf("Cidade com a maior quantidade ou igual de pontos turísticos: %s\n", estado[0].cidade[cidade2]);
        /*outra vez usando uma matéria adiantada, mas infelizmente foi o que veio na cabeça quando pensei o que seria mais simples, e mais eficiente em
        deixar no codigo que seja simples, mas não fuja do pedido(nem imagino o que pode ser mais complicado ainda kkk)*/
        break;
    /* Exemplo de case 2 adiante até case 8, em cada um, mudando o estado[x] para o estado referente
    case 2:
        printf("Escolha a primeira cidade para comparar (1 a 4): ");
        int cidade1, cidade2;
        scanf("%d", &cidade1);
        printf("Escolha a segunda cidade para comparar (1 a 4): ");
        scanf("%d", &cidade2);
        //le os valores das cidades a serem comparadas
        cidade1--;//ajusta o indice para zero-based(decrementa, pois os arrays se iniciam em [1]) para comparar com o array
        cidade2--;//ajusta o indice para zero-based(decrementa, pois os arrays se iniciam em [1]) para comparar com o array

        printf("\nComparando cidades:\n");
        printf("Cidade 1 foi escolhida: %s\n", estado[1].cidade[cidade1]);
        printf("Cidade 2 foi escolhida: %s\n", estado[1].cidade[cidade2]);
        printf("\n");
        printf("Diferença de pontos: %.2f pontos\n", estado[1].total[cidade1] - estado[1].total[cidade2]);
        printf("Diferença de densidade: %.2f pessoas por m²\n", estado[1].densidade[cidade1] - estado[1].densidade[cidade2]);
        printf("Diferença de PIB per capita: R$%.2f\n", estado[1].percapta[cidade1] - estado[1].percapta[cidade2]);
        printf("Diferença de área: %.2fm²\n", estado[1].area[cidade1] - estado[1].area[cidade2]);
        printf("Diferença de população: %d pessoas\n", estado[1].populacao[cidade1] - estado[1].populacao[cidade2]);
        printf("Diferença de pontos turísticos: %d pontos turísticos\n", estado[1].turisticos[cidade1] - estado[1].turisticos[cidade2]);
        //exibe as diferenças entre as cidades escolhidas
        printf("\n");
        estado[1].total[cidade1] > estado[1].total[cidade2] ? printf("Cidade com mais pontos: %s\n", estado[1].cidade[cidade1]) : printf("Cidade com mais pontos: %s\n", estado[1].cidade[cidade2]);
        estado[1].densidade[cidade1] > estado[1].densidade[cidade2] ? printf("Cidade com maior densidade: %s\n", estado[1].cidade[cidade1]) : printf("Cidade com maior densidade: %s\n", estado[1].cidade[cidade2]);
        estado[1].percapta[cidade1] > estado[1].percapta[cidade2] ? printf("Cidade com maior PIB per capita: %s\n", estado[1].cidade[cidade1]) : printf("Cidade com maior PIB per capita: %s\n", estado[1].cidade[cidade2]);
        estado[1].area[cidade1] > estado[1].area[cidade2] ? printf("Cidade com maior área: %s\n", estado[1].cidade[cidade1]) : printf("Cidade com maior área: %s\n", estado[1].cidade[cidade2]);
        estado[1].populacao[cidade1] > estado[1].populacao[cidade2] ? printf("Cidade com maior população: %s\n", estado[1].cidade[cidade1]) : printf("Cidade com maior população: %s\n", estado[1].cidade[cidade2]);
        estado[1].turisticos[cidade1] > estado[1].turisticos[cidade2] ? printf("Cidade com mais pontos turísticos: %s\n", estado[1].cidade[cidade1]) : printf("Cidade com mais pontos turísticos: %s\n", estado[1].cidade[cidade2]);
        /*outra vez usando uma matéria adiantada, mas infelizmente foi o que veio na cabeça quando pensei o que seria mais simples, e mais eficiente em
        deixar no codigo que seja simples, mas não fuja do pedido(nem imagino o que pode ser mais complicado ainda kkk)
        break
    
    */
    default:
        printf("opção inválida");
        //caso a opção do switch seja diferente de todas acima
        break;
    }
    return 0;
}
