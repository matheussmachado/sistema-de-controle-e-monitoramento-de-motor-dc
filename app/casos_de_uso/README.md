Essa camada será utilizada como API do sistema para o contexto externo, ou seja, será utilizada como porta de entrada pelo programa principal a fim de operar o sistema.

Casos de uso são cenários potenciais a qual o sistema recebe uma requisição do mundo externo (no caso o hardware) e responde a isso interna e/ou externamente. Ou seja, são comportamentos do sistema em resposta a eventos de contextos externos.

A intenção é controlar dispositivos e não os drivers. Portanto, a operação na camada de casos de uso é interagir com a abstração de dispositivo, que possui instruções de alto nível e que por sua vez são implementados por um driver. Sendo assim, o código de alto nível da aplicação pode ser escrito independentemente da plataforma que será utilizada no projeto.