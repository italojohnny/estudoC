#define LED 13
int valor = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  valor = analogRead(A0);
  if(valor > (1023/2)) {
    Serial.print("Maior = ");
    Serial.println(valor);
    digitalWrite(LED, LOW);
  } else {
    Serial.print("Menor = ");    
    Serial.println(valor);
    Serial.println("Me alimente!");
    digitalWrite(LED, HIGH);
  }
}
