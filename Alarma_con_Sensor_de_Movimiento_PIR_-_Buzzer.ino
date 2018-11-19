/* 
Programa: Alarma con Sensor de Movimiento PIR - Buzzer
Autor:	Humberto Higinio
Web: www.humbertohiginio.com
Canal de Youtube: https://www.youtube.com/user/HHSolis
Video Exclusivo para mi canal de Youtube
Todos los Derechos Reservados - 2015
Código de Dominio Público
 */

int ct = 15;    //calibration time
int pirPin = 2;    //PIR sensor's output
int ledPin = 13;
int buzzerPin = 10;
 
void setup(){
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(pirPin, LOW);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
   
  Serial.println("Espere, ahora calibrando el sensor....");
    for(int i = 0; i <= ct; i++){
      Serial.print(((i*100)/ct));
      Serial.print("% ");
      Serial.println("COMPLETADO.....");
      delay(1000);
      }
    Serial.println("Calibracion Completada Satisfactoriamente.");
    Serial.println("** SENSOR ACTIVO **");
    delay(50);
  }
 
void loop(){
     if(digitalRead(pirPin) == HIGH)
     {
       digitalWrite(ledPin, HIGH);
       digitalWrite(buzzerPin, HIGH);
       Serial.println("------------------------");
       Serial.println("** MOVIMIENTO DETECTADO **");
       Serial.println("------------------------");
       Serial.println("");
       delay(1000);   
   }
    
     else
     {
       digitalWrite(ledPin, LOW); 
       digitalWrite(buzzerPin, LOW); 
     }
    
}


