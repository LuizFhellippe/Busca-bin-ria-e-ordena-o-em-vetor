#include <stdio.h>

int vet[100], i, j;

void StartList(){
    for(i = 0; i < 100; i++){
        vet[i] = 0;
    }
}

void Ordena(){
    int aux;
    for(i = 0; vet[i]; i++){
        for(j = 0; vet[j]; j++){
            if(vet[j] > vet[i]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;    
            }
        }
    }
}

void Inserir(int number){
    i = 0;
    while(vet[i]){
        i++;
    }
    vet[i] = number;
}

void Listar(){
    Ordena();
    for(i = 0; vet[i]; i++){
        printf("#%d = %d\n", i + 1, vet[i]);
    }
}

int Buscar(int vet[], int number, int inicio, int fim){
    Ordena();
    int meio;
    if(inicio <= fim){
        meio = (inicio + fim) / 2;
        if(number == vet[meio]){
            return meio;
        }else{
            if(number < vet[meio]){
                return Buscar(vet, number, inicio, meio - 1);
            }else{
                return Buscar(vet, number, inicio, meio + 1);
            }
        }
        return -1;
    }
}

int main(){
    StartList();
    int choose, inputNumber, searchNumber;
    do{
        printf("1 - Inserir\n2 - Buscar\n3 - Listar\n0 - Sair\n");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                printf("Digite o numero para inserir: ");
                scanf("%d", &inputNumber);
                Inserir(inputNumber);
                break;
            case 2:
                printf("Digite o numero que deseja buscar: ");
                scanf("%d", &inputNumber);
                searchNumber = Buscar(vet, inputNumber, 0, 99);
                if(searchNumber >= 0){
                    printf("Numero %d encontrado na posicao %d\n", inputNumber, searchNumber + 1);
                }else{
                    printf("Numero nao encontrado\n");
                }
                break;
            case 3:
            Listar();
                break;
        }
    }while(choose != 0);
    return 0;
}