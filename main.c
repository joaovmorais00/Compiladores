#include "lexico.h"


int main(int argc, char *argv[]){
    int linha=0, coluna=0, auxCol=0, tabelaPos=0, tabelaLinhas[100], tabelaColunas[100];
    char tabelaTokens[100][100], tabelaTipos[100][100];
    char stringAux[100];
    FILE *arquivo;
    arquivo = fopen(argv[1], "r");

    if(arquivo==NULL){
        printf("\nNao foi possivel abrir o arquivo\n");
    }
    else{
        char ch[2];
        ch[1]='\0';
        while(1){
            ch[0]=fgetc(arquivo);
            printf("\nch: %c\n", ch[0]);
            if(ch[0]==EOF) break;

            if(ch[0]=='\n'){
                coluna=0;
                linha++;
            }

            if(verificaLetra(ch)!=0){
                while (verificaAlphaNumerico(ch)!=0){
                    stringAux[auxCol] = ch[0];
                    auxCol++;
                    ch[0]=fgetc(arquivo);
                }
                stringAux[auxCol] = '\0';
                tabelaColunas[tabelaPos] = coluna+1;

                tabelaLinhas[tabelaPos] = linha+1;
                strcpy(tabelaTokens[tabelaPos], stringAux);
                if (verificaPalavraReservada(stringAux)==1){
                    strcpy(tabelaTipos[tabelaPos], "PALAVRA RESERVADA");
                }
                
                tabelaPos++;
                coluna = coluna + auxCol;
                printf("Coluna: %d, %d aux\n", coluna, auxCol);
                auxCol=0;
  
            }

             

            if(verificaOpAritmetico(ch)!=0){
                tabelaColunas[tabelaPos] = coluna+1;
                tabelaLinhas[tabelaPos] = linha+1;
                strcpy(tabelaTokens[tabelaPos], ch);
                strcpy(tabelaTipos[tabelaPos], "OPERADOR ARITMETICO");
                tabelaPos++;
                coluna++;
            }

            else if(verificaOpLogico(ch)!=0){
                tabelaColunas[tabelaPos] = coluna+1;
                tabelaLinhas[tabelaPos] = linha+1;
                strcpy(tabelaTokens[tabelaPos], ch);
                strcpy(tabelaTipos[tabelaPos], "OPERADOR LOGICO");
                tabelaPos++;
                coluna++;
            }

            else if(verificaSeparador(ch)!=0){
                tabelaColunas[tabelaPos] = coluna+1;
                tabelaLinhas[tabelaPos] = linha+1;
                strcpy(tabelaTokens[tabelaPos], ch);
                strcpy(tabelaTipos[tabelaPos], "SEPARADOR");
                tabelaPos++;
                coluna++;
            }

        }
        fclose(arquivo);
    }

    printf("\n\n|\tLinha\t|\tColuna\t|\tToken\t|\tTipo\t|\n");
    for (int i = 0; i < tabelaPos; i++){
        printf("\n\n|\t%d\t|\t%d\t|\t%s\t|\t%s\t|\n", tabelaLinhas[i], tabelaColunas[i], tabelaTokens[i], tabelaTipos[i]);

    }
    
    return 0; 
}