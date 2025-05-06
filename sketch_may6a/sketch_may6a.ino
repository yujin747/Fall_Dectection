const int led = 9; // Led positive terminal to the digital pin 9.              
const  int sensor = 5; // signal pin of sensor to digital pin 5.               
const  int state = LOW;            
const int val = 0;                 

void  setup() { 
  pinMode(led, OUTPUT); // Led is determined as an output here.    
  pinMode(sensor, INPUT); // PIR motion sensor is determined is an input here.  
  Serial.begin(9600);      
}

void loop(){
  val = digitalRead(sensor);   
  if  (val == HIGH) {           
    digitalWrite(led, HIGH);   
    delay(500);  // Delay of led is 500             
    
    if (state == LOW) {
      Serial.println("  Motion detected "); 
      state = HIGH;       
    }
  } 
  else {
      digitalWrite(led, LOW);
      delay(500);             
      
      if  (state == HIGH){
        Serial.println("The action/ motion has stopped");
        state = LOW;       
    }
  }
}
