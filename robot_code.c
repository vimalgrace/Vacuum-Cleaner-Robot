
int M1_a = 2;
int M1_b = 4;
int M1_en = 3;

int M2_a = 5;
int M2_b = 7;
int M2_en = 6;

int IR_L = 8;
int IR_R = 9;
int IR_F = 10;

int sp  = 190;

bool bluetooth_control = false;
bool automatic_control = false;

int A_D = 1000;


#define T_left A0
#define E_left A1

#define T_right A2
#define E_right A3

#define T_front A4
#define E_front A5


long duration = 0,distance = 0;

int safeDistance = 30;

int front = 0,left = 0,right = 0;

int IR_Left = 1,IR_Right = 1,IR_Front = 1;

int getDistance(int,int);

bool t = true;

void setup() {
  Serial.begin(9600);
  pinMode(M1_a,OUTPUT);
  pinMode(M1_b,OUTPUT);
  pinMode(M2_a,OUTPUT);
  pinMode(M2_b,OUTPUT);

  pinMode(T_left,OUTPUT);
  pinMode(E_left,INPUT);

  pinMode(T_right,OUTPUT);
  pinMode(E_right,INPUT);

  pinMode(T_front,OUTPUT);
  pinMode(E_front,INPUT);

  

}

void forward(int sp){
  analogWrite(M1_en,sp);
  analogWrite(M2_en,sp);
  digitalWrite(M1_a,HIGH);
  digitalWrite(M2_a,HIGH);
  
  digitalWrite(M1_b,LOW);
  digitalWrite(M2_b,LOW);
}

void backward(int sp){
  analogWrite(M1_en,sp);
  analogWrite(M2_en,sp);
  digitalWrite(M1_a,LOW);
  digitalWrite(M2_a,LOW);
  
  digitalWrite(M1_b,HIGH);
  digitalWrite(M2_b,HIGH);
}

void rightward(int sp1,int sp2){
  analogWrite(M1_en,sp1);
  analogWrite(M2_en,sp2);

  digitalWrite(M1_a,HIGH);
  digitalWrite(M2_a,LOW);
  
  digitalWrite(M1_b,LOW);
  digitalWrite(M2_b,HIGH);
}

void leftward(int sp1,int sp2){
  analogWrite(M1_en,sp1);
  analogWrite(M2_en,sp2);

  digitalWrite(M1_a,LOW);
  digitalWrite(M2_a,HIGH);
  
  digitalWrite(M1_b,HIGH);
  digitalWrite(M2_b,LOW);
}

void stop_motor(){
  analogWrite(M1_en,0);
  analogWrite(M2_en,0);
  digitalWrite(M1_a,LOW);
  digitalWrite(M2_a,LOW);
  
  digitalWrite(M1_b,LOW);
  digitalWrite(M2_b,LOW);
}

int getDistance(int trigPin,int echoPin){
  distance = 0;
  duration = 0;
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  
  distance = (duration * 0.034)/2;
//  Serial.print("Inside distance : ");
//  Serial.println(distance);

  return distance;
  
}

void off_once(){

   analogWrite(M1_en,0);
   analogWrite(M2_en,0);
  
   digitalWrite(M1_a,LOW);
   digitalWrite(M2_a,LOW);
          
   digitalWrite(M1_b,LOW);
   digitalWrite(M2_b,LOW);
}
 
  


void automatic(){
  
  front = getDistance(T_front,E_front);
//  Serial.print("Front Distance : ");
//  Serial.println(front);

    
  left = getDistance(T_left,E_left);
//  Serial.print("Left Distance : ");
//  Serial.println(left);

  right = getDistance(T_right,E_right);
//  Serial.print("Right Distance : ");
//  Serial.println(right);

  
  
  IR_Left = digitalRead(IR_L);
  IR_Right = digitalRead(IR_R);
  IR_Front = digitalRead(IR_F);

  if(IR_Left == 1 && IR_Right == 1 && IR_Front == 1){
    stop_motor();
    delay(3000);
  }
  
  if(((front > safeDistance) && (left > safeDistance) && (right > safeDistance) && t)|| ((front > safeDistance) && (left < safeDistance) && (right < safeDistance) && t)){
    if(IR_Front == 0){
       forward(sp);
    }

    else{
      backward(sp);
      delay(500);
      stop_motor();
      t = false;
    }
    
  }

  if((front > safeDistance) && (left > safeDistance) && (right > safeDistance) && !t){
    if(IR_Right == 0){
      rightward(sp,sp);
      delay(A_D);
    }

    else if(IR_Left == 0){
      leftward(sp,sp);
      delay(A_D);
      
    }

    

    else{
      stop_motor();
      delay(3000);
    }

    t = true;
  }

  if(((front < safeDistance) && (left < safeDistance) && (right > safeDistance)) || ((front > safeDistance) && (left < safeDistance) && (right > safeDistance))){
    if(IR_Right == 0){
       rightward(sp,sp);
       delay(A_D);
    }

    else{

      if(IR_Left == 0){
        stop_motor();
        
      }

      else{
        backward(sp);
        delay(500);
        stop_motor();
      }
      
      
    }

    t = true;
   
  }

  if(((front < safeDistance) && (right < safeDistance) && (left > safeDistance)) || ((front > safeDistance) && (left > safeDistance) && (right < safeDistance))){

    if(IR_Left == 0){
      leftward(sp,sp);
      delay(A_D);
    }

    else{

      if(IR_Right == 0){
        stop_motor();
      }

      else{
          backward(sp);
          delay(500);
          stop_motor();
      }
      
    }

    t = true;
    
  }

  if(((front <= safeDistance) && (left > safeDistance) && (right > safeDistance))){
    if(IR_Right == 0){
      rightward(sp,sp);
      delay(A_D);
    }

    else if(IR_Left == 0){
      leftward(sp,sp);
      delay(A_D);
    }

    else{
      backward(sp);
      delay(500);
      stop_motor();
    }

    t = true;
  }


  if(((front < safeDistance) && (left < safeDistance) && (right < safeDistance))){
    stop_motor();
    delay(2000);
    t = true;
  }

  



}
char n = '0';

void loop() {
  if(Serial.available() > 0){

    n = Serial.read();
    Serial.print("Command : ");
    Serial.println(n);

    switch(n){
      case 'O':
        bluetooth_control = true;
        automatic_control = false;
        off_once();
        Serial.println("Bluetooth Mode on...");
        

        break;

      case 'o':
        bluetooth_control = false;
        off_once();
        Serial.println("Bluetooth Mode off...");
        break;

      case 'A':
        automatic_control = true;
        bluetooth_control = false;
        off_once();
        delay(3000);
        Serial.println("Auto Mode on...");
        break;

      case 'a':
        automatic_control = false;
        Serial.println("Auto Mode off...");
        off_once();
        break;
        

      case 'U':
        if((sp + 10) > 255){
            sp = 255;
          }

        else{
            sp = sp + 10;
        }

        Serial.print("Motor Speed : ");
        Serial.println(sp);
        break;

      case 'D':
        if((sp - 10) < 0){
            sp = 0;
          }

        else{
              sp = sp - 10;
            }

        Serial.print("Motor Speed : ");
        Serial.println(sp);
        break;

      case 'T':
        safeDistance = safeDistance + 1;
        if(safeDistance >= 100){
          safeDistance = 100;
        }

        Serial.print("Safe Distance : ");
        Serial.println(safeDistance);
        break;

      case 'W':
        safeDistance = safeDistance - 1;
        if(safeDistance <= 2){
          safeDistance = 3;
        }

        Serial.print("Safe Distance : ");
        Serial.println(safeDistance);
        break;

      default:
        break;
          
            
    }
  }
   

  

   if(bluetooth_control){ 

    switch(n){

      case 'F':
        forward(sp);
        break;

      case 'B':
        backward(sp);
        break;

      case 'L':
        leftward(sp,sp);
        break;

      case 'R':
        rightward(sp,sp);
        break;
        
      default:
        stop_motor();
        break;
        

       
        
    }
    }
  

    else if(automatic_control){
//      Serial.println("Automatic");
      automatic();
    }
    
  }
  
