# projeto-mqtt-ErickBarbosa
Repositorio entregavel da AULA 96/99

*Objetivo*

O objetivo do projeto é fazer uma ferramenta de alerta e se monitorando utilizando um Arduino uno e um sensor Magnético 
para o seu próprio monitoramento da porta de RACK de rede é possível claramente desta maneira tendo um retorno remoto no estado da
Porta que pode estar aberto ou fechado. Essa informação é enviada pela internet o protocolo Mqtt (Message Queing Telemetry Transport)
para um outro servidor hospedado na AWS (Amazon web Service)
que automaticamente transmite mensagem no aplicativo para smartphone Mqtt dash 

E no Arduino temos bibliotecas que são trechos de softwere utilizados para as funções específicas que no caso são 
"UIPEthernet
"PubsubClient

*Materiais usados no projeto*

Arduino uno

Módulo Ethernet

Sensor magnético 

*Circuito* 

  Pinos ENC28j60
      Csp.               
      Si
      So
      Sck
      Vcc
      Gnd

   Pinos Arduino 
       10
       11
       12
       13
       3.3 v
       Gnd
