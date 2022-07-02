// EXEMPLO DE PROGRAMA

// (SUGESTÃO) ESSE ARQUIVO COSTUMA TER O BOILERPLATE DA IDE ADOTADA, POR ISSO
// A SEPARAÇÃO DE SETUP E PROGRAMA EM ARQUIVOS DISTINTOS

#include "app/plataforma/setup.h"
#include "app/plataforma/programa.h"

int main(void) {	
	setup_plataforma();

	while (1) {
		executar_programa();
	}
	return 0;
}