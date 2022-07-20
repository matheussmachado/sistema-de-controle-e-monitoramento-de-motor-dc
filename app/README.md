Aqui é a raíz da aplicação, onde atualmente fica o arquivo main.c da plataforma atual e os
diretórios das camadas de Casos de Uso, Elementos e Plataforma (atual). Leia o README de cada
um desses diretórios.

A Aplicação é composto essencialmente pelos Casos de Uso, os Elementos e as interfaces de
drivers de dispositivos utilizados por elementos de dispositivos físicos.

A implementação basicamente está sendo representada pelo arquivo main que gerência o setup da
plataforma, bem como as chamadas aos Casos de Uso da Aplicação. Também é representada pela 
pasta dentro da pasta plataforma, onde estão sendo implementados os drivers dos dispositivos.

Vale afirmar que: a Aplicação define como é feita a Implementação que a executa na Plataforma 
e como devem ser escrito os drivers de dispositivo utilizados na Aplicação.

Nesse ponto é importante destacar a regra de dependência que rege a comunicação do sistema:

Implementação --> Casos de Uso --> Elementos --> Interface de Driver <-- Driver --> Plataforma

Essa relação pode ser verificada a partir do arquivo main, descendo o nível das funções de 
cada camada.

OBS: É ÓBVIO MAS VALE RESSALTAR QUE AO REIMPLEMENTAR A APLICAÇÃO EM OUTRA PLATAFORMA, DEVE SE 
ATENTAR AOS ELEMENTOS QUE NÃO POSSUEM DRIVERS INICIALIZADOS, POIS COMO SUAS FUNÇÕES NÃO ESTÃO 
DEFINIDAS ENTÃO AS CHAMADAS DESSAS FUNÇÕES NOS CÓDIGOS CONTIDOS NOS CASOS DE USO PODERÃO 
CAUSAR COMPORTAMENTOS INESPERADOS. A SUGESTÃO É QUE AO IMPLEMENTAR AOS POUCOS, QUE SEJA 
COMENTADA AS LINHAS DO ELEMENTO QUE AINDA NÃO TENHA O DRIVER IMPLEMENTADO OU FAZER UM DRIVER
FAKE DE MODO TEMPORÁRIO (ESTA ÚLTIMA OPÇÃO NÃO É INTERESSANTE).