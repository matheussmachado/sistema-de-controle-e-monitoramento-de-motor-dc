// EXEMPLO DE PROGRAMA

// (SUGESTÃO) ESSE ARQUIVO COSTUMA TER O BOILERPLATE DA IDE ADOTADA, POR ISSO
// A SEPARAÇÃO DE SETUP E PROGRAMA EM ARQUIVOS DISTINTOS


#include "plataforma/atmega328p/setup.h"
#include "plataforma/atmega328p/programa.h"

int main(void) {	
	setup_plataforma();

	while (1) {
		executar_programa();
	}
	return 0;
}