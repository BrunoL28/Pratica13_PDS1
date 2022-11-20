#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define BUFFER_TAM 5

int main(){
	char *texto = NULL;
	char *textoaux;
	char caractere;
	int count_buffer = 0, count_total = 0;
	char buffer[BUFFER_TAM];
	while(1){
			caractere = getche();
			if(caractere == '\r'){
				caractere = '\n';
				printf("\n");
			}
			if(count_buffer < BUFFER_TAM){
				buffer[count_buffer] = caractere;
				count_buffer++;
			}
			if(count_buffer == BUFFER_TAM || caractere == '#'){
				textoaux = (char*)malloc((count_total + count_buffer)*sizeof(char));
				for(int i = 0; i < count_total; i++){
					textoaux[i] = texto[i];
				}
				for(int i = 0; i < count_buffer; i++){
					textoaux[count_total + i] = buffer[i];
				}
				if(texto != NULL){
					free(texto);
				}
				texto = textoaux;
				count_total += count_buffer;
				count_buffer = 0;
			}
		if(caractere == '#'){
			break;
		}
		}
		texto[count_total - 1] = '\0';
		printf("\n\nTexto digitado\n%s", texto);
		free(texto);
	return 0;
}