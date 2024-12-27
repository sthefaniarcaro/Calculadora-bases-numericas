#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define MAX 20

/*  COMPILADOR: VSCODE
    SISTEMA OPERACIONAL: WINDOWS 10
    */

// função menu
int funcao_menu()
{
    int op;
    printf("\t\t# CALCULADORA DE CONVERSAO DE BASES NUMERICAS #\n\n");
    printf("\t\t0 - Sair do programa.\n");
    printf("\t\t1 - Converter numero decimal.\n");
    printf("\t\t2 - Converter numero binario.\n");
    printf("\t\t3 - Converter numero octal.\n");
    printf("\t\t4 - Converter numero hexadecimal.\n");
    do
    {
        printf("\n\t\tDigite a opcao desejada:");
        scanf("%d", &op);
    } while (op < 0 && op > 4);
    return op;
}

// converte de binario para decimal
int binario_decimal(char num[])
{
    int decimal = 0;
    int tamanho = strlen(num) - 1;
    for (int i = 0; i <= tamanho; i++)
    {
        if (num[i] == '1')
            decimal += pow(2, tamanho - i);
        else if (num[i] != '0')
        {
            printf("\n\t\tDados invalidos! '%s' possui caracteres nao binarios.\n", num);
            return -1;
        }
    }
    return decimal;
}

// converte octal para decimal
int octal_decimal(char num[])
{
    int decimal = 0, octal = 1; // octal = potencia de 8
    int tamanho = strlen(num) - 1;

    for (int i = tamanho; i >= 0; i--)
    {
        if (num[i] >= '0' && num[i] <= '7')
        {
            decimal += (num[i] - '0') * octal;
        }
        else
        {
            return -1;
        }
        octal *= 8;
    }

    return decimal;
}
// converte de hexadecimal para decimal
int hexa_decimal(char hex[])
{
    int decimal, potencia;
    int tamanho = strlen(hex) - 1;

    decimal = potencia = 0;

    for (int i = tamanho; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            decimal += (hex[i] - '0') * pow(16, potencia);
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            decimal += (hex[i] - 'A' + 10) * pow(16, potencia);
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            decimal += (hex[i] - 'a' + 10) * pow(16, potencia);
        }
        else
        {
            return -1;
        }
        potencia++;
    }

    return decimal;
}

// converte de decimal para binario
void decimal_bin(int decimal)
{
    int binario[32];
    int i = 0;

    if (decimal == 0)
    {
        binario[i] = '0';
        i++;
    }
    else
    {

        while (decimal > 0)
        {
            binario[i] = decimal % 2;
            decimal /= 2;
            i++;
        }

        printf("\t\tNumero em binario:");
        for (int j = i - 1; j >= 0; j--)
        {
            printf("%d", binario[j]);
        }
        printf("\n");
    }
}
// converte de decimal para octal
void decimal_octal(int decimal)
{
    int i = 0;
    char octal[MAX];

    if (decimal == 0)
    {
        octal[i] = '0';
        i++;
    }
    else
    {
        while (decimal > 0)
        {
            octal[i] = (decimal % 8) + '0';
            decimal /= 8;
            i++;
        }
    }
    octal[i] = '\0';

    int j, k;
    for (j = 0, k = i - 1; j < k; j++, k--)
    {
        char temp = octal[j];
        octal[j] = octal[k];
        octal[k] = temp;
    }
    printf("\n\t\tNumero em octal: %s\n", octal);
}

// converte de decimal para hexadecimal
void decimal_hexa(int decimal)
{
    int i = 0, resto, j, k;
    char hexadecimal[MAX];
    if (decimal == 0)
    {
        hexadecimal[i] = '0';
        i++;
    }
    else
    {
        while (decimal > 0)
        {
            resto = decimal % 16;
            if (resto < 10)
            {
                hexadecimal[i] = resto + '0';
            }
            else
            {
                hexadecimal[i] = resto - 10 + 'A';
            }
            decimal /= 16;
            i++;
        }
    }
    hexadecimal[i] = '\0';

    for (j = 0, k = i - 1; j < k; j++, k--)
    {
        char temp = hexadecimal[j];
        hexadecimal[j] = hexadecimal[k];
        hexadecimal[k] = temp;
    }
    printf("\n\t\tNumero em hexadecimal: %s\n", hexadecimal);
}

// menu para a base final
int menu_bases()
{
    int op;
    printf("\n\t\t1 - Converter para decimal.\n");
    printf("\t\t2 - Converter para binario.\n");
    printf("\t\t3 - Converter para octal.\n");
    printf("\t\t4 - Converter para hexadecimal.\n");
    do
    {
        printf("\n\t\tDigite a opcao desejada:");
        scanf("%d", &op);
    } while (op < 0 && op > 4);
    return op;
}
// converte de decimal para outras bases
void decimal_bases(int num)
{
    int menu;
    char resultado;

    menu = menu_bases();
    switch (menu)
    {
    case 1:
        printf("\n\t\tNumero em decimal: %d\n", num);
        break;
    case 2:
        decimal_bin(num);
        break;
    case 3:
        decimal_octal(num);
        break;
    case 4:
        decimal_hexa(num);
        break;
    default:
        break;
        printf("\t\tPressione qualquer tecla para prosseguir...");
        fflush(stdin);
        getchar();
    }
}

int main()
{
    int menu, num;
    long decimal;
    char numero[MAX];

    do
    {
        system("cls");
        menu = funcao_menu();
        system("cls");
        switch (menu)
        {
        case 1:
            printf("\t\t\t# CONVERSAO DE NUMERO DECIMAL #\n");
            do
            {
                printf("\n\t\tDigite um numero inteiro positivo:");
                scanf("%d", &num);
            } while (num < 0);
            decimal_bases(num);
            break;

        case 2:
            printf("\t\t\t# CONVERSAO DE NUMERO BINARIO #\n");
            printf("\n\t\tDigite um numero binario positivo:");
            fflush(stdin);
            scanf("%[^\n]s", &numero);

            for (int i = 0; i < strlen(numero); i++)
            {
                if (numero[i] != '0' && numero[i] != '1')
                {
                    printf("\n\t\tDados invalidos! Pressione qualquer tecla para prosseguir...");
                    fflush(stdin);
                    getchar();
                    continue;
                }
            }
            decimal = binario_decimal(numero);
            decimal_bases(decimal);
            break;
        case 3:
            printf("\t\t\t# CONVERSAO DE NUMERO OCTAL #\n");
            printf("\n\t\tDigite um numero octal positivo:");
            fflush(stdin);
            scanf("%[^\n]s", &numero);

            for (int i = 0; i < strlen(numero); i++)
            {
                if (numero[i] < '0' || numero[i] > '7')
                {
                    printf("\n\t\tDados invalidos! Pressione qualquer tecla para prosseguir...");
                    fflush(stdin);
                    getchar();
                    continue;
                }
            }

            decimal = octal_decimal(numero);
            decimal_bases(decimal);
            break;
        case 4:
            printf("\t\t\t# CONVERSAO DE NUMERO HEXADECIMAL #\n");
            printf("\n\t\tDigite um numero hexadecimal positivo:");
            fflush(stdin);
            scanf("%[^\n]s", &numero);

            for (int i = 0; i < strlen(numero); i++)
            {
                if ((numero[i] < '0' || numero[i] > '9') &&
                    (numero[i] < 'A' || numero[i] > 'F') &&
                    (numero[i] < 'a' || numero[i] > 'f'))
                {
                    printf("\n\t\tDados invalidos! Pressione qualquer tecla para prosseguir...");
                    fflush(stdin);
                    getchar();
                    continue;
                }
            }
            decimal = hexa_decimal(numero);
            decimal_bases(decimal);
            break;
        default:
            if (menu != 0)
                printf("\t\tDados invalidos!\n");
        }
        if (menu != 0)
        {
            printf("\n\t\tPressione qualquer tecla para prosseguir...");
            fflush(stdin);
            getchar();
        }
    } while (menu != 0);

    return 0;
}
