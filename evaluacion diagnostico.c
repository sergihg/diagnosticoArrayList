#include <stdio.h>
#include <stdlib.h>

int menu();
void addAtTail(int **array, int *size, int *maxSize, int dato);
void addAtFront(int **array, int *size, int *maxSize, int dato);
void getSize(int *size, int *maxSize);
int getAt(int *array, int size, int index);
void imprimir(int *array, int size);

int main()
{
    int option,*array,size,maxSize,dato,index;
    size=0;
    printf("Tamano inicial: ");
    scanf("%d",&maxSize);
    array=(int*)malloc(maxSize*sizeof(int));
    do{
        option= menu();
        switch (option)
        {
        case 1:
            printf("dato a insertar: ");
            scanf("%d",&dato);
            addAtTail(&array,&size,&maxSize,dato);
            break;
        case 2:
            printf("dato a insertar: ");
            scanf("%d",&dato);
            addAtFront(&array,&size,&maxSize,dato);
            break;
        case 3:
            getSize(&size,&maxSize);
            break;
        case 4:
            free(array);
            size=0;
            break;
        case 5:
            printf("posicion: ");
            scanf("%d",&index);
            dato=getAt(array,size,index);
            printf("dato: %d\n",dato);
            break;
        case 6:
            imprimir(array,size);
            break;
        }
    }while(option < 7);
    free(array);
}
int menu()
{
    int option;
    printf("1)addAtTail\n");
    printf("2)addAtFront\n");
    printf("3)size\n");
    printf("4)removeAll\n");
    printf("5)getAt\n");
    printf("6)Imprimir\n");
    scanf("%d",&option);
    return option;
}

void addAtTail(int **array, int *size, int *maxSize, int dato)
{   
    if(*array!=NULL)
    {
        if((*size)==(*maxSize))
        {   (*maxSize)+=5;
            *array=(int *)realloc(array,sizeof(int)*(*maxSize));
            *(*array+(*size))=dato;
            (*size)++;
        }else
        {
            *(*array+(*size))=dato;
            (*size)++;
        }
    }
}

void addAtFront(int **array, int *size, int *maxSize, int dato)
{   
    int* tmp;
    int i;
    if(*array!=NULL)
    {
        if((*size)==(*maxSize))
        {   (*maxSize)+=5;
            tmp=(int*)malloc(sizeof(int)*(*maxSize));
            tmp[0]=dato;
            for(i=1;i<=(*size);i++)
            {
                tmp[i]=*(*array+(i-1));
            }
            free(*array);
            (*array)=tmp;
            (*size)++;
        }else
        {
            tmp=(int*)malloc(sizeof(int)*(*maxSize));
            (*tmp)=dato;
            for(i=1;i<=(*size);i++)
            {
                tmp[i]=*(*array+(i-1));
            }
            free(*array);
            (*array)=tmp;
            (*size)++;
        }
    }
}

void getSize(int *size, int *maxSize)
{
    printf("size: %d\n",*size);
    printf("maxSize: %d\n",*maxSize);
}

int getAt(int *array, int size, int index)
{
    int data;
    if( index < size )
    {data=array[index];
    return data;}
    else{
        printf("no existe la posicion\n");
    }
}

void imprimir(int *array, int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d  ", *(array+i));
    }
    printf("\n");
}
