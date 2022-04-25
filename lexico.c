#include "lexico.h"

int verificaOpLogico(char *string){
    regex_t reg;
	printf("%s", string);
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
	
	//printf("^[\\+\\/\\*%%=]$|^\\+\\+$|^\\-\\-$|^\\>\\>$|^\\<\\<$");
	printf("%s", string);
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

int verificaSeparador(char * string){
	regex_t reg;

	//printf("%s",string);
	printf( "^[\\[\\]\\(\\)\\{\\},;\n\t]$");
	if (regcomp(&reg , "^[\\(\\)\\{\\},;\n\t]$|^\\[$^\\]$", REG_EXTENDED|REG_NOSUB) != 0) {
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


