#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct peca{
    char cor[20];
    int tipo;
    float peso;
    float tamanho;
    char borda[10];
    struct peca *prox;
}peca;

int tam = 0;

//Criação da função de cadastrar peças:
void cadastro(){
    //Definição do tipo da peça:
    peca *nova = (peca *)malloc(sizeof(peca));
    if (nova == NULL){
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
    
    
    char escolha_char[20];

    printf("Qual o tipo da peça?\n [1] - Peça T\n [2] - Peça S1\n [3] - Peça S2\n [4] - Peça I\n [5] - Peça L1\n [6] - Peça L2\n [7] - Peça Q\n");
    scanf("%d", &nova ->tipo);
    printf("\033[1;35m_______________________\033[0m\n");

    //Definição da cor da peça:
    printf("Qual a cor da peça:\n-\033[1;35m[Roxa]\033[0m\n- \033[1;33m[Amarela]\033[0m\n- \033[1;32m[Verde]\033[0m\n- \033[1;34m[Azul]\033[0m\n- \033[38;5;214m[Laranja]\033[0m\n- \033[38;5;94m[Marrom]\033[0m\n- \033[1;31m[Vermelho]\033[0m\n");
    scanf(" %[^\n]", escolha_char);
    strcpy(nova->cor, escolha_char); 
    printf("\033[1;35m_______________________\033[0m\n");

    //Pergunta se a peça possui borda:
    printf("A peça possui borda[S/N]?\n");
    scanf(" %[^\n]", escolha_char);
    strcpy(nova->borda, escolha_char);
    printf("\033[1;35m_______________________\033[0m\n");

    //Pergunta o tamanho da peça:
    printf("Qual o tamanho da peça?[m]\n");
    scanf("%f", &nova->tamanho);
    printf("\033[1;35m_______________________\033[0m\n");

    //Pergunta o peso da peça:
    printf("Qual o peso da peso:[Kg]\n");
    scanf("%f", &nova ->peso);

    tam++;
}


void listar_pecas(){

}



void reorganizar_pecas(){

}


int main(){
    //Representação do menu de usuário:
    int opcao;
    do{

    printf("\033[1;31mMenu:\033[0m\n");
    printf("\033[1;35m_______________________\033[0m\n");
    printf("\033[1;31m1 - Cadastrar peça\033[0m\n");

    printf("\033[1;35m_______________________\033[0m\n");
    printf("\033[1;31m2 - Listar peças\033[0m\n");

    printf("\033[1;35m_______________________\033[0m\n");
    printf("\033[1;31m3 - Reorganizar peças\033[0m\n");
    
    printf("\033[1;35m_______________________\033[0m\n");
    printf("\033[1;31m0 - Sair\033[0m\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    } while (opcao != 0);
    
    
    cadastro();

    return 0;
}