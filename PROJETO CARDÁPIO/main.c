#include <windows.h>
#include <stdio.h>
#include <string.h>

//INTERFACE

void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void tabela()
{
    system ("cls");

    Caixa  (0,1,82,1,1);
    gotoxy (1,2);
    printf ("=======================| \033[35mLanchonete UNIFIPMoc - Cardapio\033[0m |========================");
    Caixa (0,4,35,10,0);
    Caixa (37,4,45,10,0);
    gotoxy (1,5);
    printf ("\033[36mItem:       Lanches:       Valor:\033[0m");
    gotoxy (38,5);
    printf ("\033[36mItem:       Bebidas:                 Valor:\033[0m");
    gotoxy (1,6);
    printf (" \033[36m1-\033[0m         X-Burger    \033[35m   R$20,00\033[0m");
    gotoxy (38,6);
    printf (" \033[36m10-\033[0m        Suco de Laranja 500ml    \033[35mR$8,00\033[0m\n");
    gotoxy (38,7);
    printf (" \033[36m11-\033[0m        Suco de Uva 500ml        \033[35mR$8,00\033[0m\n");
    gotoxy (38,8);
    printf (" \033[36m12-\033[0m        Coca-cola 1L             \033[35mR$10,00\033[0m\n");
    gotoxy (38,9);
    printf (" \033[36m13-\033[0m        Pepsi 1L                 \033[35mR$10,00\033[0m\n");
    gotoxy (38,10);
    printf (" \033[36m14-\033[0m        Sem bebida               \033[35mR$0,00\033[0m\n");
    gotoxy (1,7);
    printf (" \033[36m2-\033[0m         X-Egg       \033[35m   R$22,00\033[0m");
    gotoxy (1,8);
    printf (" \033[36m3-\033[0m         X-Bacon     \033[35m   R$25,00\033[0m");
    gotoxy (1,9);
    printf (" \033[36m4-\033[0m         X-Tudo      \033[35m   R$30,00\033[0m");
    gotoxy (1,10);
    printf ("\ \033[36m5-\033[0m         X-Frango    \033[35m   R$22,00\033[0m \n");
    gotoxy (1,11);
    printf (" \033[36m6-\033[0m         X-Pernil    \033[35m   R$25,00\033[0m \n");
    gotoxy (1,12);
    printf (" \033[36m7-\033[0m         X-Black     \033[35m   R$25,00\033[0m \n");
    gotoxy (1,13);
    printf (" \033[36m8-\033[0m         X-Calabresa \033[35m   R$22,00\033[0m \n");
    gotoxy (1,14);
    printf (" \033[36m9-\033[0m         Sem lanche  \033[35m   R$0,00\033[0m \n");
    gotoxy (0,16);
}
void Caixa(int x, int y, int Largura, int Altura, int Tipo)
{
    int i, j;
    unsigned char C[][6] = {{218, 196, 191, 179, 192, 217},
        {201, 205, 187, 186, 200, 188}
    };
    gotoxy(x, y);
    printf("%c", C[Tipo][0]);
    for(i = 0; i < Largura; i++)
        printf("%c", C[Tipo][1]);
    printf("%c", C[Tipo][2]);
    for(j = 0; j < Altura; j++)
    {
        gotoxy(x, y + j + 1);
        printf("%c", C[Tipo][3]);
        for(i = 0; i < Largura; i++) printf(" ");
        printf("%c", C[Tipo][3]);
    }
    gotoxy(x, y + j + 1);
    printf("%c", C[Tipo][4]);
    for(i = 0; i < Largura; i++)
        printf("%c", C[Tipo][1]);
    printf("%c", C[Tipo][5]);
}
int main  ()
{
    int codigoLanche, codigoBebida, quantidadeL, quantidadeB, lancheT, bebidaT;
    float pagamento, saldoInsufi, troco, pedido;
    char continuar, limpar [2];
    char alterar[100][100];
    int countalterar = 0;
    char nome[100];
    float pedidoT = 0;
    int totalL[100];
    int countL = 0;
    int totalB[100];
    int countB = 0;
    int quat_pedidos = 0;
    int totalBq[100];
    int countBq = 0;
    int totalLq[100];
    int countLq = 0;
    int verifica = 1;
    int verifica1= 1;

    do
    {
        tabela();
        printf ("\033[36mNome do cliente: \033[0m");
        scanf("%99[^\n]",nome);
        fflush (stdin);
        gotoxy (0,17);

        do
        {
            printf ("\033[36mLanche e quantidade (Ex: 1 2): \033[0m");
            scanf ("%d %d", &codigoLanche, &quantidadeL);

            if (codigoLanche == 1)
            {
                float valorLanche = 20;
                lancheT = valorLanche * quantidadeL;
            }
            else if (codigoLanche == 2)
            {
                float valorLanche = 22;
                lancheT = valorLanche * quantidadeL;
            }
            else if (codigoLanche == 3)
            {
                float valorLanche = 25;
                lancheT = valorLanche * quantidadeL;
            }
            else if (codigoLanche == 4)
            {
                float valorLanche = 30;
                lancheT = valorLanche * quantidadeL;
            }
            else if (codigoLanche == 5)
            {
                float valorLanche = 22;
                lancheT = valorLanche * quantidadeL;
            }
            else if (codigoLanche == 6)
            {
                float valorLanche = 25;
                lancheT = valorLanche * quantidadeL;
            }
            else if (codigoLanche == 7)
            {
                float valorLanche = 25;
                lancheT = valorLanche * quantidadeL;
            }
            else if (codigoLanche == 8)
            {
                float valorLanche = 22;
                lancheT = valorLanche * quantidadeL;
            }
            else if (codigoLanche == 9)
            {
                float valorLanche = 0;
                lancheT = valorLanche * quantidadeL;
            }
            else
            {
                printf ("\033[31mCodigo do item ou quantidade invalida!\n");
                verifica = 0;
                verifica1 = 0;
            }
            if(verifica1 == 1)
            {
                printf ("\033[36mBebida e quantidade (Ex: 1 2): \033[0m");
                scanf ("%d %d", &codigoBebida, &quantidadeB);
                fflush (stdin);

                if (codigoBebida == 10)
                {
                    float valorBebida = 8;
                    bebidaT = valorBebida * quantidadeB;
                }
                else if (codigoBebida == 11)
                {
                    float valorBebida = 8;
                    bebidaT = valorBebida * quantidadeB;
                }
                else if (codigoBebida == 12)
                {
                    float valorBebida = 10;
                    bebidaT = valorBebida * quantidadeB;
                }
                else if (codigoBebida == 13)
                {
                    float valorBebida = 10;
                    bebidaT = valorBebida * quantidadeB;
                }
                else if (codigoBebida == 14)
                {
                    float valorBebida = 0;
                    bebidaT = valorBebida * quantidadeB;
                }

                else
                {
                    printf ("\033[31mCodigo do item ou quantidade invalida!\n");
                    verifica = 0;
                }
            }
            if(verifica ==1)
            {
                pedidoT = pedidoT + lancheT + bebidaT;
                totalB[countB] = codigoBebida;
                countB++;
                totalL[countL] = codigoLanche;
                totalBq[countBq] = quantidadeB;
                totalLq[countLq] = quantidadeL;
                countLq++;
                countBq++;
                countL++;
                quat_pedidos++;
                printf ("\033[36mALteracoes no pedido: \033[0m");
                gets(alterar[countalterar]);
                countalterar++;
                printf("\033[33mDeseja adicionar outro pedido? (S/N): \033[0m");
                scanf(" %c", &continuar);
            }
            else {
                verifica1 = 1;
                verifica = 1;
                printf("\033[33mTentar novamente? (S/N): \033[0m");
                scanf(" %c", &continuar);
                if(continuar == 'N' || continuar == 'n')
                {
                    system("cls");
                    printf("\033[31mPedido cancelado!\033[0m\n");
                    exit(0);
                }
                else{
                    tabela();
                    printf ("\033[36mNome do cliente: %s\033[0m\n",nome);
                    gotoxy (0,17);
                }
            }
        }while (continuar == 'S' || continuar == 's');

        for(int i =0; i<countL; i++)
        {
            printf("%d\n",totalL[i]);
        }
        do
        {
            system ("cls");
            const char* cardapioLanches[][2] =
            {
                {"X-Burger", "R$20,00"},
                {"X-Egg", "R$22,00"},
                {"X-Bacon", "R$25,00"},
                {"X-Tudo", "R$30,00"},
                {"X-Frango", "R$22,00"},
                {"X-Pernil", "R$25,00"},
                {"X-Black", "R$25,00"},
                {"X-Calabresa", "R$22,00"},
                {"Sem lanche", "R$0,00"}
            };
            const char* cardapioBebidas[][2] =
            {
                {"Suco de Laranja 500ml", "R$8,00"},
                {"Suco de Uva 500ml", "R$8,00"},
                {"Coca-cola 1L", "R$10,00"},
                {"Pepsi 1L", "R$10,00"},
                {"Sem bebida", "R$0,00"}
            };

            //DETALHES FINAIS DO PEDIDO / PAGAMENTO

            pedido = lancheT + bebidaT;
            system ("cls");
            Caixa  (0,1,80,1,1);
            gotoxy (1,2);
            printf ("\033[35m=============================| Detalhes do pedido |=============================\033[0m\n\n\n");
            Caixa (0,4,80,20,0);
            gotoxy (1,5);
            printf ("\033[36mNome do cliente:\033[0m %s", nome);
            gotoxy (1,6);
            printf ("\033[36mValor total do pedido:\033[0m %.2f\n", pedidoT);
            int x = 8;
            int v = 0;
            for (int i = 0; i < quat_pedidos; ++i)
            {
                gotoxy (1, x-1);
                printf("\033[36mLanche escolhido: \033[0m%s | \033[36mQuantidade: \033[0m%d | \033[36mValor:\033[0m %s\n", cardapioLanches[totalL[v] - 1][0], totalLq[v], cardapioLanches[totalL[v] - 1][1]);
                printf("\n");
                gotoxy (1, x);
                printf("\033[36mBebida escolhida: \033[0m%s | \033[36mQuantidade: \033[0m%d | \033[36mValor:\033[0m %s\n", cardapioBebidas[totalB[v] - 10][0], totalBq[v], cardapioBebidas[totalB[v] - 10][1]);
                gotoxy (1, x+1);
                printf ("\033[36mAlteracoes no pedido:\033[0m %s\n",alterar[i]);
                x+=3;
                v++;
            }
            gotoxy (0,26);
            printf ("\033[33mValor do pagamento realizado pelo cliente (Ex: R$32.50): R$");
            scanf ("%f", &pagamento);

            if (pagamento < pedidoT)
            {
                saldoInsufi = pedidoT - pagamento;
                printf ("\033[31mValor insuficiente para realizar o pagamento! Falta R$%.2f\033[0m", saldoInsufi);
                printf("\n\033[33mTentar novamente? (S/N): \033[0m");
                scanf(" %c", &continuar);
            }
            else
            {
                continuar = 'N';
            }
        }
        while (continuar == 'S' || continuar == 's');

        if (pagamento >= pedidoT)
        {
            system ("cls");
            troco = pagamento - pedidoT;
            printf ("\033[32mPEDIDO REALIZADO COM SUCESSO!!!\n\n");
            printf ("Troco para repassar ao cliente: R$%.2f", troco);
        }
        printf("\033[31m\nNovo pedido (S/N)? ");
        scanf("%s", &limpar);
        system ("cls");
        if ((strcmp(limpar, "S") == 0) || (strcmp(limpar, "s") == 0))
        {
            printf ("\033[33mLimpando.\033[0m");
            sleep (1);
            printf ("\033[33m.\033[0m");
            sleep (1);
            printf ("\033[33m.\033[0m");
            sleep (1);
        }
        else
        {
            system ("cls");
            printf("\033[32mConcluido!\033[0m\n");
        }
        pedidoT = 0;
        countL = 0;
        countB = 0;
        quat_pedidos = 0;
        countBq = 0;
        countLq = 0;
        getchar ();
        countalterar = 0;

    }
    while ((strcmp(limpar, "S") == 0) || (strcmp(limpar, "s") == 0));
    return 0;
}
