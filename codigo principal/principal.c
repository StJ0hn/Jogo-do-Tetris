#include "pecas.h"

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

        switch (opcao){
        case 1:
            cadastro();
            break;
        case 2:
            listar_pecas();
            break;
        case 3:
            reorganizar_pecas();
            break;
        case 0:
            printf("Programa encerrado com sucesso\n");
            break;
        default:
        printf("Opção não encontrada, tente novamente.\n");
            break;
        }
    } while (opcao != 0);
    
    return 0;
}