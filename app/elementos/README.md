Essa camada, como o nome já sugere, diz respeito aos Elementos da Aplicação. Esses elementos 
podem ser abstrações de dispositivos físicos ou puramente virtuais. 

Sobr os elementos de dispositivo, são compostos por um arquivo .h e um .c. 

No arquivo .h:

É exposto uma (ou mais) instância(s) de um dado dispositivo através de uma struct contendo 
como membros os ponteiros de funções que modelam o comportamento físico deste dispositivo a
ser utilizado pelos Casos de Uso, a qual o dispositivo está envolvido. Nesse mesmo arquivo 
está exposto a interface de driver a ser utilizado por esse dispositivo e uma função para 
atribuir esse driver específico ao dispositivo específico, e que deve ser chamada pela camada 
de drivers na parte da implementação da plataforma. O conjunto de todas essas interfaces de 
drivers é o que chamamos de HAL (Hardware Abstraction Layer).

No arquivo .c:

Está encapsulado toda a construção desse elemento bem como os possíveis atributos e funções
privadas (se for o caso), e a conexão com o driver para o devido funcionamento desse elemento.