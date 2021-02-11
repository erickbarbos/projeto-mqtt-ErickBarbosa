#include <PubSubClient.h>
#include <UIPEthernet.h>
#include <utility/logging.h>
#include <SPI.h>

//Variavel utilizada para enviar as mensagens utilizando o cliente MQTT
boolean mensagem;

int pino2 = 2 ; // Cria uma variável para o Pino 2
bool estado_sensor; // Cria uma variável para armazenar o estado do sensor

//Define o endereço MAC que sera utilizado
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

//Inicia o cliente Ethernet
EthernetClient client;

//Inicia o client MQTT
PubSubClient mqttClient(client);

void setup() {

    //Inicia o computador Ethernet e solicita um IP para po servidor do DHCP
    Ethernet.begin(mac);

    //Inicia o monitor Serial 
    Serial.begin(9600);

    //Define o IP e Porta TCP do Broker MQTT que vamos utilizar
    mqttClient.setServer("100.26.99.63",1883);

    //Exibe no Monitor Serial as informaçoes sobre o IP do Arduino
    Serial.print("O IP do Arduino e: ");
    Serial.println(Ethernet.localIP());

    //Exibe no Monitor Serial as informaçoes sobre a Mascara de Rede do Arduino
    Serial.print("A Mascara de Rede do Arduino e: ");
    Serial.println(Ethernet.subnetMask());

    //Exibe no Monitor Serial as informaçoes sobre o Gateway do Arduino
    Serial.print("O Gatewal do Arduino e: ");
    Serial.println(Ethernet.gatewayIP());

    pinMode (pino2, INPUT_PULLUP); // Coloca o Pino 2 como Entrada
}
void loop () 
{
   //Define o nome do client MQTT e efetua a conexao com o servidor.
   mqttClient.connect("erickbarbosa");

  estado_sensor = digitalRead (pino2); // Efetua a leitura do Pino 2 e armazena o valor discriminado na variável

   if(estado_sensor == 0) {

      Serial.println("FECHADO");
      mensagem = mqttClient.publish("rack", "FECHADO");
   }else{
    
      Serial.println("ABERTO");
      mensagem = mqttClient.publish("rack", "ABERTO");
    }

   Serial.println(mensagem);

   mqttClient.loop();  
  
  }
