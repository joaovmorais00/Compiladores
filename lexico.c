#include "lexico.h"

//VERIFICAÇÕES

int verificaOpLogico(char *string){
    regex_t reg;
	
    if (regcomp(&reg , "^[><!&|]$|^>=$|^<=$|^==$|^!=$|^&&$|^\\|\\|$", REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}

	if(regexec(&reg, string, 0, NULL, 0)==0){
		printf("Validou\n");
		return 1;
	}else{
		return 0;
	}
}

int verificaOpAritmetico(char *string){
	regex_t reg;
	
    if (regcomp(&reg , "^[\\+\\/\\*%%=]$|^\\+\\+$|^\\-\\-$|^\\>\\>$|^\\<\\<$", REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}

	if(regexec(&reg, string, 0, NULL, 0)==0){
		printf("Validou\n");
		return 1;
	}else{
		return 0;
	}
}

int verificaSeparador(char *string){
	regex_t reg;
	if (regcomp(&reg , "^[\\(\\)\\{\\},;]$|^\\[$^\\]$", REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}

	if(regexec(&reg, string, 0, NULL, 0)==0){
		printf("Validou\n");
		return 1;
	}else{
		return 0;
	}
}

int verificaPalavraReservada(char *string){
	regex_t reg;

	if (regcomp(&reg , "^int$|^float$|^char$|^if$|^else$|^for$|^while$|^print$|^read$|^return$", REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}

	if(regexec(&reg, string, 0, NULL, 0)==0){
		printf("Palavra reservada\n");
		return 1;
	}else{
		return 0;
	}
}

int verificaLetra(char *string){
	regex_t reg;

	if (regcomp(&reg , "^[a-z]$", REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}

	if(regexec(&reg, string, 0, NULL, 0)==0){
		printf("Entrou");
		printf("\nLetra\n");
		return 1;
	}else{
		return 0;
	}
}

int verificaEspaco(char *string){
	regex_t reg;
	if (regcomp(&reg , "^\\s$", REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}

	if(regexec(&reg, string, 0, NULL, 0)==0){
		printf("Espaco\n");
		return 1;
	}else{
		return 0;
	}
}

int verificaAlphaNumerico(char *string){
	regex_t reg;

	if (regcomp(&reg , "^[a-z0-9_]$", REG_EXTENDED|REG_NOSUB) != 0) {
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}

	if(regexec(&reg, string, 0, NULL, 0)==0){
		printf("Entrou");
		printf("\nLetra\n");
		return 1;
	}else{
		return 0;
	}
}


