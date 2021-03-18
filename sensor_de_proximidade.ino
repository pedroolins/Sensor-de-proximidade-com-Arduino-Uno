//Projeto sensor de proximidade com display de sete segmentos e sensor ultrassônico
//Autor:Pedro Lins
//-------------------------------------------------------------------------------------------------------
#include <NewPing.h> //Incluindo a biblioteca para o sensor ultrassônico
// aqui vamos definir as portas para os segmentos do nosso display 
#define pino_a 2 //definindo o pino onde estará setado o segmento A do display
#define pino_b 3 //definindo o pino onde estará setado o segmento B do display
#define pino_c 4 //definindo o pino onde estará setado o segmento C do display
#define pino_d 5 //definindo o pino onde estará setado o segmento D do display
#define pino_e 6 //definindo o pino onde estará setado o segmento E do display
#define pino_f 7 //definindo o pino onde estará setado o segmento F do display
#define pino_g 8 //definindo o pino onde estará setado o segmento G do display
//-------------------------------------------------------------------------------------------------------
#define comum_1 9 //definindo o pino comum ao primeiro display da esquerda para a direita 
#define comum_2 10 //definindo o pino comum ao segundo display da esquerda para a direita
//agora vamos definir os pinos do sensor ultrassônico o echo e o triger 
#define echo 11
#define trigger 12
//agora vamos definir uma distância maxima para o sensor ultrassônico medir
#define max_distancia 99 //no meu caso irei colocar 99cm
//Criando variáveis para armazenar o valor da distância medida pelo sensor ultrassônico
String distancia;//variável que irá armazenar o valorda distância em string 
int numero_1;//criando variável para armazenar o primeiro número da string da variável (distancia) logo depois de ser transformada em int
int numero_2;//criando variável para armazenar o segundo número da string da variável (distancia) logo depois de ser transformada em int
//agora vamos instanciar o objeto do tipo NewPing chamado sensor e passar os parâmetros dos pinos trigger e echo, além da distância max que você quer definir
NewPing sensor(trigger,echo,max_distancia);

void setup() {
  for (int i = 2; i < 11; i++){// configura todos os pinos como output sem gastar muitas linha de código, utilizando o laço for
    pinMode(i,OUTPUT);
  }
  //setou a porta comum ao digito em high ela fica apagada e em low ela fica acesa
  digitalWrite(comum_1,HIGH);//para o arduino inicializar o primeiro display deligado
  digitalWrite(comum_2,HIGH);//para o arduino inicializar o primeiro display deligado
  // já nos segmentos é ao contrário quando estiver em HIGH os segmentos são ligados e em LOW não
  for(int i = 2; i < 9; i++) {// para inicializar tos os segmentos desligados
    digitalWrite(i,LOW); 
  }
}

void loop() {
  distancia = String(sensor.ping_cm());// variável que irá armazenar o valor em cm que o sensor está captando 
  numero_1 = distancia[0] - '0';//transformar o primeiro número que está em char para int e armazena na variável numero_1
  numero_2 = distancia[1] - '0';//transformar o segundo número que está em char para int e armazena na variável numero_2
  digitalWrite(comum_1,LOW);//aqui ativamos os primeiro display
  //o primeiro switch serve para identificarmos o valor armazenado na variável numero_1 e ligar os segmentos correspondentes a ele
  switch (numero_1) {
    case 0:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_d,HIGH);
      digitalWrite(pino_e,HIGH);
      digitalWrite(pino_f,HIGH);
      break;      
      
    case 1:
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,HIGH);
      break;
      
    case 2:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_g,HIGH);
      digitalWrite(pino_d,HIGH);
      digitalWrite(pino_e,HIGH);
      break;

    case 3:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_d,HIGH);
      digitalWrite(pino_g,HIGH);
      digitalWrite(comum_1,HIGH);
      break;
    
    case 4:
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_g,HIGH);
      digitalWrite(pino_f,HIGH);
      digitalWrite(comum_1,HIGH);
      break;
    
    case 5:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_g,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_d,HIGH);
      digitalWrite(pino_f,HIGH);
      digitalWrite(comum_1,HIGH);
      break;
    
    case 6:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_g,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_d,HIGH);
      digitalWrite(pino_e,HIGH);
      digitalWrite(pino_f,HIGH);
      digitalWrite(comum_1,HIGH);
      break;
    
    case 7:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(comum_1,HIGH);
      break;
    
    case 8:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_d,HIGH);
      digitalWrite(pino_e,HIGH);
      digitalWrite(pino_f,HIGH);
      digitalWrite(pino_g,HIGH);
      digitalWrite(comum_1,HIGH);
      break;
            
    case 9:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_d,HIGH);
      digitalWrite(pino_f,HIGH);
      digitalWrite(pino_g,HIGH);
      digitalWrite(comum_1,HIGH);
      break;

    default:
      digitalWrite(pino_g,HIGH);
      break;
  }
  for(int i = 2; i < 9; i++) {//deligando os segmentos que foram acesos
  digitalWrite(i,LOW); 
  }
  digitalWrite(comum_1,HIGH);//deligando o primeiro display de sete segmentos
  digitalWrite(comum_2,LOW);//ligando o segundo display de sete segmentos
  //o segundo switch serve para identificarmos o valor armazenado na variável numero_2 e ligar os segmentos correspondentes a ele
  switch (numero_2) {
    case 0:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_d,HIGH);
      digitalWrite(pino_e,HIGH);
      digitalWrite(pino_f,HIGH);
      digitalWrite(comum_2,HIGH);
      break;
      
    case 1:
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(comum_2,HIGH);
      break;
      
    case 2:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_g,HIGH);
      digitalWrite(pino_d,HIGH);
      digitalWrite(pino_e,HIGH);
      digitalWrite(comum_2,HIGH);
      break;

    case 3:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_d,HIGH);
      digitalWrite(pino_g,HIGH);
      digitalWrite(comum_2,HIGH);
      break;
      
    case 4:
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_g,HIGH);
      digitalWrite(pino_f,HIGH);
      digitalWrite(comum_2,HIGH);
      break;
      
    case 5:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_g,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_d,HIGH);
      digitalWrite(pino_f,HIGH);
      digitalWrite(comum_2,HIGH);
      break;
      
    case 6:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_g,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_d,HIGH);
      digitalWrite(pino_e,HIGH);
      digitalWrite(pino_f,HIGH);
      digitalWrite(comum_2,HIGH);
      break;
      
    case 7:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(comum_2,HIGH);
      break;
      
    case 8:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_d,HIGH);
      digitalWrite(pino_e,HIGH);
      digitalWrite(pino_f,HIGH);
      digitalWrite(pino_g,HIGH);
      digitalWrite(comum_2,HIGH);
      break;
              
    case 9:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_d,HIGH);
      digitalWrite(pino_f,HIGH);
      digitalWrite(pino_g,HIGH);
      digitalWrite(comum_2,HIGH);
      break;
      
  }
  //desliga os segmentos do segundo display
  for (int i = 2; i < 9; i++){
    digitalWrite(i,LOW);
  }
  digitalWrite(comum_2,HIGH);//desliga o segundo display de sete segmentos 
}
