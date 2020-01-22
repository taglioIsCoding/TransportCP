//sensore ad ultrasuoni test copenaghen

const int alim =  11;
const int trigger = 12;
const int receiver = 13;

void setup() 
{
 pinMode(trigger,OUTPUT);
 pinMode(receiver,INPUT);
 pinMode(alim,OUTPUT);
 Serial.begin(9600);
 Serial.print("sono un sensore ciao: ");
}

void loop() 
{
 digitalWrite(alim,HIGH);
 digitalWrite(trigger,LOW); //inizializzo a 0 il trigger
 digitalWrite(trigger,HIGH); //impulso di 10 microsecondi su trigger
 delayMicroseconds(10); //delay di 10 microsecondi
 digitalWrite(trigger,LOW); //trigger torna a 0
 long durata = pulseIn(receiver,HIGH); //ricezione segnale
 long distanza = 0.034 * durata / 2; // calcolo distanza dall'oggetto
 Serial.print("distanza: "); //stampa seriale della distanza
 
//se durata supera i 38ms è fuori portata
 if(distanza > 500) 
 {Serial.println("Fuori portata :(");}
  else
 {Serial.print(distanza); Serial.println("cm ");}
 delay(3000);
}
