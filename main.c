#include <stdio.h>
#include <stdlib.h>

 struct conta_info{
        int numeroConta;
        char nomeCliente[30];
        float saldo;
    };
     struct conta_info contaList[9];

int cadastro(  struct conta_info contaList[9], int contaCount, size_t contaListSize){
    int k, i,j=0, addedContas=0, initNumberOfContas=contaCount, finalNumberOfContas;
    if(contaCount==9){
        printf("Banco de dados cheio\n");
    }else{
    for(i=contaCount;i<=contaListSize; i++){
        printf("# da conta: ");
        scanf("%d", &contaList[i].numeroConta);
        printf("Nome do Cliente da conta: ");
        scanf("%s", contaList[i].nomeCliente);
        printf("Saldo da conta: ");
        scanf("%f", &contaList[i].saldo);
        printf("\n\n");
        printf("adicionar uma nova conta(yes=1;no=2) : ");
        scanf("%d",&j);
        if(j==2){
            contaCount++;
            addedContas++;
            i=contaListSize;
        printf("-----------\n");
        }else{
            contaCount++;
            addedContas++;
        printf("-----------\n");
        }
        if(addedContas==10){
            printf("database full\n");
            printf("-----------\n");
        }
    }

    if(addedContas==1){
        finalNumberOfContas=initNumberOfContas;
    }else{
        finalNumberOfContas=addedContas-1;
    }
    printf("cadastro feito do usuario:\n ");

    for(k=initNumberOfContas;k<=finalNumberOfContas; k++){
        printf("numero: %d\n ",contaList[k].numeroConta );
        printf("nome: %s \n",contaList[k].nomeCliente );
        printf("saldo: %f \n",contaList[k].saldo );
    }

    }

printf("-----------\n");
return addedContas;

}

void showAll(struct conta_info contaList[9], int contaCount){
    int i;
    if(contaCount==0){
        printf("Sem contas\n");
    }else{
        printf("Contas cadastradas: \n-------------------------\n");
          for(i=0;i<contaCount;i++ ){
            printf("numero: %d\n ",contaList[i].numeroConta );
            printf("nome: %s \n",contaList[i].nomeCliente );
            printf("saldo: %f \n",contaList[i].saldo );
            printf("-------------------------\n");
        }
    }

}

int deleteConta(struct conta_info contaList[9], int contaCount, size_t contaListSize ){
    int numeroContaApagada,pos, i;
    printf("Qual conta quer apagar?, ingresse o numero da conta: ");
    scanf("%d",&numeroContaApagada );
    for(i=0;i<=contaCount-1; i++){
        if(contaList[i].numeroConta==numeroContaApagada){
            pos=i+1;
        }
    }

    if(pos== contaCount+1|| pos<0){
        printf("Invalid position! Please enter position between 1 to %d", contaListSize);
    }else{
        for(i=pos-1; i<=contaCount-1; i++)
        {
            contaList[i] = contaList[i + 1];
        }
        printf("conta eliminada\n");
    }
    return contaCount-1;
}


int deleteContaMenor(struct conta_info contaList[9], int contaCount, size_t contaListSize ){
int i, menor=0, pos;

for(i=0;i<=contaCount-1; i++){
        if(menor==0){
            menor= contaList[i].saldo;
        }else if(contaList[i].saldo< menor){
            menor= contaList[i].saldo;
            pos=i;
        }
    }
    for(i=pos; i<=contaCount-1; i++)
        {
            contaList[i] = contaList[i + 1];
        }
        printf("conta eliminada com menor saldo\n");
    return contaCount-1;
}



int main()
{
    size_t contaListSize= sizeof(contaList)/sizeof(contaList[0]);
    int j=0;
    int contaCount=0;
    while(j!=5){
        printf(" 1. Cadastro de Conta.\n");
        printf(" 2. Mostrar conta de um cliente.\n");
        printf(" 3. Excluir  a conta.\n");
        printf(" 4. Excluir  a conta com menor saldo.\n");
        printf(" 5. Sair. \n");
        printf("-------------------------\n");
        scanf("%d", &j);
        switch (j){
            case 1:
                contaCount+=cadastro(contaList, contaCount,contaListSize);
            break;
            case 2:
                showAll(contaList, contaCount);
            break;
            case 3:
                showAll(contaList, contaCount);
                contaCount=deleteConta(contaList, contaCount,contaListSize);
            break;
            case 4:
                contaCount=deleteContaMenor(contaList, contaCount,contaListSize);
            break;
            case 5:
                j=4;
            break;
            default:
                printf("number invalid");
            break;
        }
    }

}
