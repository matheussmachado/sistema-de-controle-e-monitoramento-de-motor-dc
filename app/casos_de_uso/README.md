Casos de Uso são cenários potenciais a qual o sistema recebe uma requisição do mundo externo 
(no caso o hardware) e responde a isso interna e/ou externamente. Ou seja, são comportamentos 
do sistema em resposta a eventos de contextos externos.

Essa camada será utilizada como API da Aplicação para o contexto externo, ou seja, irá expôr 
todas as funcionalidades da Aplicação que serão chamadas pela camada de Implementação.

A intenção é controlar dispositivos e não os drivers. Portanto, a operação na camada de Casos 
de Uso é interagir com Elementos que possui instruções de alto nível, sejam eles virtuais ou 
abstração de dispositivo que por sua vez são implementados por um driver. Sendo assim, o 
código de alto nível da Aplicação pode ser escrito independentemente da plataforma que será 
utilizada no projeto.

No arquivo .h:

Está exposto todos as funções de Casos de Uso que serão chamadas pela Implementação.

No arquivo .c:

Está construído toda a lógica necessária para um Caso de Uso da aplicação funcionar,
desenvolvida em alto nível.