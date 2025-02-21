#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


typedef struct{
    char cidade[4][50];
    int populacao[4];
    float area[4];
    float pib[4];
    int turisticos[4];
    float percapta[4];
    float densidade[4];
    float total[4];
    
}Estado;//struct de dados para adicionar os dados de cada cidade

Estado estado[8];//cria 8 structs "Estado"
char *nome_estado[8] = {"A", "B", "C", "D", "E", "F", "G", "H"};//criei um array para exibir os nomes dos estados em menus e outras interações

void limparBuffer() {                                      // Função para limpar o buffer do stdin depois de cada coleta de dados
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void separar_menu(){//função para separar as atividades do menu
    printf("\n------------------------------------------------------\n");
}

void cadastrar_cidades(){//função de cadastro de cidades
    int x = 0;//uso "x" para controlar meus loops, sempre atribuindo "1" a ele para cortar o loop e passar para o próximo, mas antes voltando ele para "0", senão ele skippa o próximo loop
    int n_estado;//variavel para coletar a escolha do estado no menu
    int y;//uso exclusivamente para resumir "n_estado" e coloca-lo para zero based "-1" para poder usar de referencia
    
    
    do
    {
        printf("\nDe que estado deseja cadastrar as cidades? \n");
        for (int i = 0; i < 8; i++)
        {
            printf("%d- %s\n", i + 1, nome_estado[i]);//exibe os estados de A-H
        }
        printf("Escolha: ");
        scanf("%d", &n_estado);//coleta a escolha
        limparBuffer();
        n_estado <= 8 && n_estado >=0 ? x = 1 : printf("\nOpções inválidas");//verifica se a escolha acima foi válida

    } while (x < 1);//loop que exibe os estados disponíveis para cadastro, coleta a entrada, e verifica se ela é válida, se sim, prossegue, se não, repete o loop
    
    x = 0;//retorna "x" para "0" para não entrar em conflito no proximo loop
    y = n_estado - 1;//uso do "y" sendo feito para resumir e transitar para zero based o "n_estado"
    
    for(int i = 0; i < 4; i++){//loop para cadastro das 4 cidades do estado escolhido ("y = qual estado foi escolhido", "i = qual cidade está sendo cadastrada")
        printf("\nCidade %d: ", i + 1);
        fgets(estado[y].cidade[i], 50, stdin);//usa-se fgets para ler strings com espaços
        estado[y].cidade[i][strlen(estado[y].cidade[i]) - 1] = '\0';//retira o \n do final da string
        limparBuffer();

        printf("\nPopulação: ");
        scanf("%d", &estado[y].populacao[i]);

        printf("\nÁrea: ");
        scanf("%f", &estado[y].area[i]);

        printf("\nPIB: ");
        scanf("%f", &estado[y].pib[i]);

        printf("\nQuantidade de pontos turísticos: ");
        scanf("%d",&estado[y].turisticos[i]);


        estado[y].percapta[i] = estado[y].pib[i] / estado[y].populacao[i];//calculo dos atributos especiais
        estado[y].densidade[i] = estado[y].populacao[i] / estado[y].area[i];
        estado[y].total[i] = estado[y].populacao[i] + estado[y].area[i] + estado[y].pib[i] + estado[y].turisticos[i];

        separar_menu();
    }


}

void exibir_cidades(){//função de exibição de dados, boa parte é semelhante a função de cadastro, então vou poupar explicações
    int x = 0;//novamente, os mesmos principios das variáveis
    int n_estado;
    int y;

    do
    {
        printf("\nDe que estado deseja exibir as cidades? \n");
        for (int i = 0; i < 8; i++)
        {
            printf("%d- %s\n", i + 1, nome_estado[i]);
        }
        printf("Escolha: ");
        scanf("%d", &n_estado);
        limparBuffer();
        n_estado <= 8 && n_estado >=0 ? x = 1 : printf("\nOpções inválidas");

    } while (x < 1);

    y = n_estado - 1;
    x = 0;

    for(int i = 0; i < 4; i++){
        separar_menu();
        
        printf("\nCidade %d", i+1);
        printf("\nNome: %s", estado[y].cidade[i]);
        printf("\nPopulação: %d pessoas", estado[y].populacao[i]);
        printf("\nÁrea: %.2fm²", estado[y].area[i]);
        printf("\nPIB: R$%.2f", estado[y].pib[i]);
        printf("\nPontos turísticos: %d pontos turísticos", estado[y].turisticos[i]);
        printf("\nPIB percapta: R$%.2f", estado[y].percapta[i]);
        printf("\nDensidade: %.2f pessoas por m²", estado[y].densidade[i]);
        printf("\nTotal de pontos: %.2f pontos", estado[y].total[i]);
        
    }

    
}

void comparar_cidades(){
    int x, y1, y2, n_estado;//"x" segue com a mesma função, controlar loops; "y1" vou usar para o estado 1, pois ja usei y mais vezes para essa finalidade, "y2" respectivamente para o estado 2
    int c1, c2;//"n_estado" vai fazer o mesmo papel de só coletar depois ser usado para transferir e converter para zero based; "c1" e "c2" vão ser os indices das cidades escolhidas

    do
    {
        printf("\nQual o estado da primeira cidade? \n");
        for (int i = 0; i < 8; i++)
        {
            printf("%d- %s\n", i + 1, nome_estado[i]);
        }
        printf("Escolha: ");
        scanf("%d", &n_estado);
        limparBuffer();
        n_estado <= 8 && n_estado >=0 ? x = 1 : printf("\nOpções inválidas");

    } while (x < 1);//loop para escolher o primeiro estado("n_estado" vai virar "y1"), possuindo validação de escolha

    y1 = n_estado - 1;//como dito acima
    x = 0;//correção para seguir as interações com os próximos loops
    n_estado = 0;//só para desencargo de consciencia, zerei o n_estado para usa-lo novamente

    do
    {
        printf("\nQual a primeira cidade?");
        for (int i = 0; i < 4; i++){
            printf("\n%d- %s",i +1, estado[y1].cidade[i]);
        }
        printf("\nEscolha: ");
        scanf("%d", &c1);

        c1 <= 4 && c1 >= 0 ? x = 1 : printf("\nOpções inválidas");

    } while (x < 1);//loop para escolher a primeira cidade("c1"), essa ja atribui direto a variavel certa

    separar_menu();

    do
    {
        printf("\nQual o estado da segunda cidade? \n");
        for (int i = 0; i < 8; i++)
        {
            printf("%d- %s\n", i + 1, nome_estado[i]);
        }
        printf("Escolha: ");
        scanf("%d", &n_estado);
        limparBuffer();
        n_estado <= 8 && n_estado >=0 ? x = 1 : printf("\nOpções inválidas");

    } while (x < 1);//mesmo loop para escolher estado

    y2 = n_estado - 1;
    x = 0;
    n_estado = 0;

    do
    {
        printf("\nQual a segunda cidade?");
        for (int i = 0; i < 4; i++){
            printf("\n%d- %s",i + 1, estado[y2].cidade[i]);
        }
        printf("\nEscolha: ");
        scanf("%d", &c2);

        c1 <= 4 && c1 >= 0 ? x = 1 : printf("\nOpções inválidas");

    } while (x < 1);//mesmo loop de escolha de cidade


    c1--;//decremento para mudar para zero based
    c2--;


    estado[y1].total[c1] > estado[y2].total[c2]                 ?   printf("Cidade com mais pontos: %s\n", estado[y1].cidade[c1]) : printf("Cidade com a maior quantidade ou igual de pontos: %s\n", estado[y2].cidade[c2]);
    estado[y1].densidade[c1] > estado[y2].densidade[c2]         ?   printf("Cidade com maior densidade: %s\n", estado[y1].cidade[c1]) : printf("Cidade com a maior quantidade ou igual de densidade: %s\n", estado[y2].cidade[c2]);
    estado[y1].percapta[c1] > estado[y2].percapta[c2]           ?   printf("Cidade com maior PIB per capita: %s\n", estado[y1].cidade[c1]) : printf("Cidade com a maior quantidade ou igual de PIB per capita: %s\n", estado[y2].cidade[c2]);
    estado[y1].area[c1] > estado[y2].area[c2]                   ?   printf("Cidade com maior área: %s\n", estado[y1].cidade[c1]) : printf("Cidade com a maior quantidade ou igual de área: %s\n", estado[y2].cidade[c2]);
    estado[y1].populacao[c1] > estado[y2].populacao[c2]         ?   printf("Cidade com maior população: %s\n", estado[y1].cidade[c1]) : printf("Cidade com a maior quantidade ou igual de população: %s\n", estado[y2].cidade[c2]);
    estado[y1].pib[c1] > estado[y2].pib[c2]                     ?   printf("Cidade com maior PIB: %s\n", estado[y1].cidade[c1]) : printf("Cidade com a maior quantidade ou igual de PIB: %s\n", estado[y2].cidade[c2]);
    estado[y1].turisticos[c1] > estado[y2].turisticos[c2]       ?   printf("Cidade com mais pontos turísticos: %s\n", estado[y1].cidade[c1]) : printf("Cidade com a maior quantidade ou igual de pontos turísticos: %s\n", estado[y2].cidade[c2]);
    //comparações feitas, se é maior ou se é igual ou menor
}


int main(){

    setlocale(LC_ALL, "Portuguese");//indica a linguagem do teclado local, para poder usar caracteres da lingua portuguesa
    int escolha_menu, sair_menu;//uma vai ser base para o switch do menu, e outra vai fazer o papel que "x" fez nas funções, cancelar o loop
    sair_menu = 0;//atribuo "0" para inicializar o loop

    do
    {
       separar_menu();
       printf("Menu:\n");
       printf("\n1- Cadastrar Cidades");
       printf("\n2- Exibir Cidades");
       printf("\n3- Comparar Cidades");
       printf("\n4- Sair");

       printf("\nEscolha uma opção(1-4): ");
       scanf("%d", &escolha_menu);
       separar_menu();

       switch (escolha_menu)
       {
        case 1:
            cadastrar_cidades();
        break;

        case 2:
            exibir_cidades();
        break;

        case 3:
            comparar_cidades();
        break;

        case 4:
            sair_menu = 1;
        break;

        default:
            printf("\nopção inválida\n");
            separar_menu();
        break;

       }
    } while (sair_menu < 1);//loop do menu principal, sempre que terminar uma tarefa, vai retornar para o menu
    



    return 0;
}
