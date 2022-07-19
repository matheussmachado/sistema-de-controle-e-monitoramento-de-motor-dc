Essa é a camada da plataforma, onde será composta por drivers que irão responder a chamadas de 
alto nível realizadas por abstrações de dispositivos no sistema. Drivers são programas que
viabilizam a comunicação entre o sistema e o dispositivo. 

Na prática, os drivers serão adaptadores que permitirão a comunicação entre a aplicação e o
contexto externo do hardware (plataforma). Portanto, um driver provê poderes para as 
abstrações de dispositivos utilizados na aplicação.

O arquivo drivers_setup.h expõe todos os setups de drivers de todos os dispositivos (de modo
geral) que a aplicação necessita. Portanto, essas funções precisam ser implementadas em cada
arquivo .c no diretório da plataforma em questão.

É importante que na troca de plataforma, nesse diretório apenas o arquivo drivers_setup.h 
permaneça.