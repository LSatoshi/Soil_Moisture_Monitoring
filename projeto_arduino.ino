#define pino_sinal_analogico A0
#define pino_led_a 4
#define pino_led_b 6
#define pino_led_c 7
#define pino_buzzer 8
//#define frequency 294
 
int valor_analogico;


void setup() {
  Serial.begin(9600);
  pinMode(pino_sinal_analogico, INPUT);
  pinMode(pino_led_a, OUTPUT);
  pinMode(pino_led_b, OUTPUT);
  pinMode(pino_led_c, OUTPUT);
  pinMode(pino_buzzer, OUTPUT);
}
 
void loop() {
  //Le o valor do pino A0 do sensor
  valor_analogico = analogRead(pino_sinal_analogico);
 
  //Mostra o valor da porta analogica no serial monitor
  Serial.print("Porta analogica: ");
  Serial.print(valor_analogico);

  
  //Solo umido, acende todos leds
  if (valor_analogico >= 0 && valor_analogico < 600) {
    Serial.println(" Status: Solo umido");
    apagaleds();
    digitalWrite(pino_led_a, HIGH);
    digitalWrite(pino_led_b, HIGH);
    digitalWrite(pino_led_c, HIGH);
  }
 
  //Solo com umidade moderada, acende 2 leds
  if (valor_analogico > 600 && valor_analogico < 800) {
    Serial.println(" Status: Umidade moderada");
    apagaleds();
    digitalWrite(pino_led_b, HIGH);
    digitalWrite(pino_led_c, HIGH);
  }
 
  //Solo seco, acende 1 led
  if (valor_analogico > 800 && valor_analogico < 1000) {
    Serial.println(" Status: Solo seco");
    apagaleds();
    digitalWrite(pino_led_c, HIGH);
  }

  //completamente seco, aciona buzzer
  if (valor_analogico >= 1000) {
    Serial.println(" Status: Solo muito seco");
    apagaleds();
    digitalWrite(pino_buzzer, HIGH);
    delay(100);
    digitalWrite(pino_buzzer, LOW);
    delay(1000);
  }
  delay(100);
}
 
void apagaleds() {
  digitalWrite(pino_led_a, LOW);
  digitalWrite(pino_led_b, LOW);
  digitalWrite(pino_led_c, LOW);
  digitalWrite(pino_buzzer, LOW);
}
