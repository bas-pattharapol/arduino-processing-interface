int St_Sw_Mode = 0;
int St_Sw_On_Off = 0;
int St_Sw_100 =0;

const int inj =  42;
const int scv =  7;
const int fan =  4;
const int motor =  3;
const int val_1 =  43;
const int val_2 =  44;

unsigned long previousMillis = 0;  
const long interval = 1000; 

unsigned long previousMillis_1 = 0;  
const long interval_1 = 200;  
 
int st =0;
int mode=0;

int Pressure = 0;
int RPM = 0;
int Tmp = 0;
int Oil = 0;
int Inject = 0;
int Return = 0;

int Current = 0;
int Currrnt_Piezo = 0;

int test_se = 0;

int modeS=0;

int ooooo = 0;
bool stop = false;

char  val;

int St_scv_1 = 0;
int St_delay_1 =0;
int St_Micro_delay_1 =0;

int St_scv_2 = 0;
int St_delay_2 =0;
int St_Micro_delay_2 =0;

int St_scv_3 = 0;
int St_delay_3 =0;
int St_Micro_delay_3 =0;

int St_scv_4 = 0;
int St_delay_4 =0;
int St_Micro_delay_4 =0;

int St_scv_5 = 0;
int St_delay_5 =0;
int St_Micro_delay_5 =0;
int hTime_1 = 0;
int hTime_2 = 0;
int hTime_3 = 0;
int hTime_4 = 0;
int hTime_5 = 0;

int st_fan =0;

void setup() {
  Serial.begin(115200);
  pinMode(motor, OUTPUT);  
  pinMode(inj , OUTPUT);      
  pinMode(scv , OUTPUT);
//  pinMode(Output_100,OUTPUT);  
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  delay(1000);

}
int j =0;
void aa(){
      unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    /*Tmp = map(analogRead(A1),0,1024,80,20);
    Pressure = map(analogRead(A2),0,1024,0,200);
    RPM = map(analogRead(A3),0,1024,1000,600);*/
    j++;
    if( j>=10){
      j =0;
      
    }
    Tmp = 1+j;
    RPM = 200+j;
    Pressure = 5+j;
    Oil = 14+j;
    Inject = 20+j;
    Return = 30+j;
    Current = 40+j;
    Currrnt_Piezo = 50+j;

    Serial.println(Pressure + String(",") + RPM + String(",") + Tmp + String(",") + Oil + String(",") + Inject + String(",") + Return + String(",") + Current + String(",") + Currrnt_Piezo);
  

    previousMillis = currentMillis;

  }
}
int i = 10;

void aa1(){
     unsigned long currentMillis = millis();

  if (currentMillis - previousMillis_1 >= interval_1) {
    i = i +10;
    if(i >=100){
      i =0;
    }
   Serial.println(i);
    previousMillis_1 = currentMillis;

  }
}

void loop() {
  aa();
  if (Serial.available() > 0) { 
     char  ll = Serial.read();
     aa();
   if(ll == '1'){
    
   }
   if(ll == '2'){
    
   }
   if(ll == '3'){
    
   }
   if(ll == '4'){
    
   }
   if(ll == '5'){
    
   }
   if(ll == '6'){ // st
        ll = Serial.read();
        digitalWrite(13,HIGH);
        aa();
        
        digitalWrite(inj,HIGH);
        delayMicroseconds(St_Micro_delay_1);
        digitalWrite(inj,LOW);
        delay(St_delay_1);
        analogWrite(scv,St_scv_1);

        for(st_fan = 10; st_fan <=80 ; st_fan = st_fan + 10){
          analogWrite(motor,st_fan);
          delay(50);
        }
        analogWrite(motor,90);

        for(;ll !='7' || ll !='8' || ll !='9';){
          aa();
          analogWrite(motor,90);
          digitalWrite(inj,HIGH);
          delayMicroseconds(St_Micro_delay_1);
          digitalWrite(inj,LOW);
          delay(St_delay_1);
          analogWrite(scv,St_scv_1);
          ll = Serial.read();

          if(ll == '7'){
            analogWrite(motor,0);
            Serial.println(1000);
            stop = true;
            for(int j = 0 ; j <= 50 ; j++){
              digitalWrite(inj,HIGH);
              delayMicroseconds(St_Micro_delay_1);
              digitalWrite(inj,LOW);
              delay(St_delay_1);
              analogWrite(scv,St_scv_1);
            }
              digitalWrite(inj,LOW);
              analogWrite(scv,0); 
          break;
          
          }

          if(ll == '8'){
            st = 1;
            mode = 1;
            break;
          }
        }

       
   }
//************************************************************
   if(st == 1 && mode ==1){
      digitalWrite(22,HIGH);
      digitalWrite(23,LOW);
      digitalWrite(24,LOW);
      digitalWrite(25,LOW);
      digitalWrite(26,LOW);
      stop = false;
       for(int h = 0 ; h <30000 ; h = h+hTime_1){
        aa();
         if(h >= 100 && h <=200){
          Serial.println(5);
         }
         if(h >= 3000 && h <=3100){
          Serial.println(13);
         }
         if(h >= 6000 && h <=6100){
          Serial.println(29);
         }
         if(h >= 9000 && h <=9100){
          Serial.println(41);
         }
         if(h >= 12000 && h <=12100){
          Serial.println(52);
         }
         if(h >= 15000 && h <=15100){
          Serial.println(59);
         }
         if(h >= 18000 && h <=18100){
          Serial.println(65);
         }
          if(h >= 21000 && h <=21100){
          Serial.println(70);
         }
         if(h >= 24000 && h <=23100){
          Serial.println(78);
         }
         if(h >= 27000 && h <=27100){
          Serial.println(85);
         }
         if(h >= 29000 && h <=29100){
          Serial.println(95);
         }
         ll = Serial.read();
         digitalWrite(inj,HIGH);
         delayMicroseconds(St_Micro_delay_1);
         digitalWrite(inj,LOW);
         delay(St_delay_1);
         analogWrite(scv,St_scv_1);
         analogWrite(motor,90);
         
         if(ll == '7'){
            analogWrite(motor,0);
            Serial.println(0);
            stop = true;
            for(int j = 0 ; j <= 50 ; j++){
              digitalWrite(inj,HIGH);
              delayMicroseconds(St_Micro_delay_1);
              digitalWrite(inj,LOW);
              delay(St_delay_1);
              analogWrite(scv,St_scv_1);
            }
              digitalWrite(inj,LOW);
              analogWrite(scv,0); 
          break;
          
         }
       }

        if(stop){
          st = 0;
          mode = 0;
          Serial.println(1000);
        }else{
          Serial.println(100);
          st = 1;
          mode = 2;
          analogWrite(motor,0);
            for(int j = 0 ; j <= 50 ; j++){
              digitalWrite(inj,HIGH);
              delayMicroseconds(St_Micro_delay_1);
              digitalWrite(inj,LOW);
              delay(St_delay_1);
              analogWrite(scv,St_scv_1);
            }
              digitalWrite(inj,LOW);
              analogWrite(scv,0); 
          
        }
        digitalWrite(22,LOW);
        digitalWrite(23,LOW);
        digitalWrite(24,LOW);
        digitalWrite(25,LOW);
        digitalWrite(26,LOW);
        delay(3000);
      
   }

   if(st == 1 && mode == 2){
    Serial.println(5 + String(",") + 5);
      digitalWrite(22,LOW);
      digitalWrite(23,HIGH);
      digitalWrite(24,LOW);
      digitalWrite(25,LOW);
      digitalWrite(26,LOW);
      stop = false;

        digitalWrite(inj,HIGH);
        delayMicroseconds(St_Micro_delay_2);
        digitalWrite(inj,LOW);
        delay(St_delay_2);
        analogWrite(scv,St_scv_2);

        for(st_fan = 10; st_fan <=80 ; st_fan = st_fan + 10){
          analogWrite(motor,st_fan);
          delay(50);
        }
        analogWrite(motor,90);

      for(int h = 0 ; h <30000 ; h = h+hTime_2){
        aa();
         if(h >= 100 && h <=200){
          Serial.println(5);
         }
         if(h >= 3000 && h <=3100){
          Serial.println(13);
         }
         if(h >= 6000 && h <=6100){
          Serial.println(29);
         }
         if(h >= 9000 && h <=9100){
          Serial.println(41);
         }
         if(h >= 12000 && h <=12100){
          Serial.println(52);
         }
         if(h >= 15000 && h <=15100){
          Serial.println(59);
         }
         if(h >= 18000 && h <=18100){
          Serial.println(65);
         }
          if(h >= 21000 && h <=21100){
          Serial.println(70);
         }
         if(h >= 24000 && h <=23100){
          Serial.println(78);
         }
         if(h >= 27000 && h <=27100){
          Serial.println(85);
         }
         if(h >= 29000 && h <=29100){
          Serial.println(95);
         }
         ll = Serial.read();
         digitalWrite(inj,HIGH);
         delayMicroseconds(St_Micro_delay_2);
         digitalWrite(inj,LOW);
         delay(St_delay_2);
         analogWrite(scv,St_scv_2);
         analogWrite(motor,90);
         
         if(ll == '7'){
            analogWrite(motor,0);
            Serial.println(0);
            stop = true;
            for(int j = 0 ; j <= 50 ; j++){
              digitalWrite(inj,HIGH);
              delayMicroseconds(St_Micro_delay_2);
              digitalWrite(inj,LOW);
              delay(St_delay_2);
              analogWrite(scv,St_scv_2);
            }
              digitalWrite(inj,LOW);
              analogWrite(scv,0); 
          break;
          
         }
       }

        if(stop){
          st = 0;
          mode = 0;
          Serial.println(1000);
        }else{
          Serial.println(100);
          st = 1;
          mode = 3;
          analogWrite(motor,0);
            for(int j = 0 ; j <= 50 ; j++){
              digitalWrite(inj,HIGH);
              delayMicroseconds(St_Micro_delay_2);
              digitalWrite(inj,LOW);
              delay(St_delay_2);
              analogWrite(scv,St_scv_2);
            }
              digitalWrite(inj,LOW);
              analogWrite(scv,0); 
          
        }
        digitalWrite(22,LOW);
        digitalWrite(23,LOW);
        digitalWrite(24,LOW);
        digitalWrite(25,LOW);
        digitalWrite(26,LOW);
        delay(3000);
      
   }

   if(st == 1 && mode == 3){
    Serial.println(5 + String(",") + 5);
      digitalWrite(22,LOW);
      digitalWrite(23,LOW);
      digitalWrite(24,HIGH);
      digitalWrite(25,LOW);
      digitalWrite(26,LOW);
      stop = false;

        digitalWrite(inj,HIGH);
        delayMicroseconds(St_Micro_delay_3);
        digitalWrite(inj,LOW);
        delay(St_delay_3);
        analogWrite(scv,St_scv_3);

        for(st_fan = 10; st_fan <=80 ; st_fan = st_fan + 10){
          analogWrite(motor,st_fan);
          delay(50);
        }
        analogWrite(motor,90);

      for(int h = 0 ; h <30000 ; h = h+hTime_3){
        aa();
         if(h >= 100 && h <=200){
          Serial.println(5);
         }
         if(h >= 3000 && h <=3100){
          Serial.println(13);
         }
         if(h >= 6000 && h <=6100){
          Serial.println(29);
         }
         if(h >= 9000 && h <=9100){
          Serial.println(41);
         }
         if(h >= 12000 && h <=12100){
          Serial.println(52);
         }
         if(h >= 15000 && h <=15100){
          Serial.println(59);
         }
         if(h >= 18000 && h <=18100){
          Serial.println(65);
         }
          if(h >= 21000 && h <=21100){
          Serial.println(70);
         }
         if(h >= 24000 && h <=23100){
          Serial.println(78);
         }
         if(h >= 27000 && h <=27100){
          Serial.println(85);
         }
         if(h >= 29000 && h <=29100){
          Serial.println(95);
         }
         ll = Serial.read();
         digitalWrite(inj,HIGH);
         delayMicroseconds(St_Micro_delay_3);
         digitalWrite(inj,LOW);
         delay(St_delay_3);
         analogWrite(scv,St_scv_3);
         analogWrite(motor,90);
         
         if(ll == '7'){
            analogWrite(motor,0);
            Serial.println(0);
            stop = true;
            for(int j = 0 ; j <= 50 ; j++){
              digitalWrite(inj,HIGH);
              delayMicroseconds(St_Micro_delay_3);
              digitalWrite(inj,LOW);
              delay(St_delay_3);
              analogWrite(scv,St_scv_3);
            }
              digitalWrite(inj,LOW);
              analogWrite(scv,0); 
          break;
          
         }
       }

        if(stop){
          st = 0;
          mode = 0;
          Serial.println(1000);
        }else{
          Serial.println(100);
          st = 1;
          mode = 4;
          analogWrite(motor,0);
            for(int j = 0 ; j <= 50 ; j++){
              digitalWrite(inj,HIGH);
              delayMicroseconds(St_Micro_delay_3);
              digitalWrite(inj,LOW);
              delay(St_delay_3);
              analogWrite(scv,St_scv_3);
            }
              digitalWrite(inj,LOW);
              analogWrite(scv,0); 
          
        }
        digitalWrite(22,LOW);
        digitalWrite(23,LOW);
        digitalWrite(24,LOW);
        digitalWrite(25,LOW);
        digitalWrite(26,LOW);
        delay(3000);
      
   }

    if(st == 1 && mode == 4){
    Serial.println(5 + String(",") + 5);
      digitalWrite(22,LOW);
      digitalWrite(23,LOW);
      digitalWrite(24,LOW);
      digitalWrite(25,HIGH);
      digitalWrite(26,LOW);
      stop = false;

        digitalWrite(inj,HIGH);
        delayMicroseconds(St_Micro_delay_4);
        digitalWrite(inj,LOW);
        delay(St_delay_4);
        analogWrite(scv,St_scv_4);

        for(st_fan = 10; st_fan <=80 ; st_fan = st_fan + 10){
          analogWrite(motor,st_fan);
          delay(50);
        }
        analogWrite(motor,90);

      for(int h = 0 ; h <30000 ; h = h+hTime_4){
        aa();
         if(h >= 100 && h <=200){
          Serial.println(5);
         }
         if(h >= 3000 && h <=3100){
          Serial.println(13);
         }
         if(h >= 6000 && h <=6100){
          Serial.println(29);
         }
         if(h >= 9000 && h <=9100){
          Serial.println(41);
         }
         if(h >= 12000 && h <=12100){
          Serial.println(52);
         }
         if(h >= 15000 && h <=15100){
          Serial.println(59);
         }
         if(h >= 18000 && h <=18100){
          Serial.println(65);
         }
          if(h >= 21000 && h <=21100){
          Serial.println(70);
         }
         if(h >= 24000 && h <=23100){
          Serial.println(78);
         }
         if(h >= 27000 && h <=27100){
          Serial.println(85);
         }
         if(h >= 29000 && h <=29100){
          Serial.println(95);
         }
         ll = Serial.read();
         digitalWrite(inj,HIGH);
         delayMicroseconds(St_Micro_delay_4);
         digitalWrite(inj,LOW);
         delay(St_delay_4);
         analogWrite(scv,St_scv_4);
         analogWrite(motor,90);
         
         if(ll == '7'){
            analogWrite(motor,0);
            Serial.println(0);
            stop = true;
            for(int j = 0 ; j <= 50 ; j++){
              digitalWrite(inj,HIGH);
              delayMicroseconds(St_Micro_delay_4);
              digitalWrite(inj,LOW);
              delay(St_delay_4);
              analogWrite(scv,St_scv_4);
            }
              digitalWrite(inj,LOW);
              analogWrite(scv,0); 
          break;
          
         }
       }

        if(stop){
          st = 0;
          mode = 0;
          Serial.println(1000);
        }else{
          Serial.println(100);
          st = 1;
          mode = 5;
          analogWrite(motor,0);
            for(int j = 0 ; j <= 50 ; j++){
              digitalWrite(inj,HIGH);
              delayMicroseconds(St_Micro_delay_4);
              digitalWrite(inj,LOW);
              delay(St_delay_4);
              analogWrite(scv,St_scv_4);
            }
              digitalWrite(inj,LOW);
              analogWrite(scv,0); 
          
        }
        digitalWrite(22,LOW);
        digitalWrite(23,LOW);
        digitalWrite(24,LOW);
        digitalWrite(25,LOW);
        digitalWrite(26,LOW);
        delay(3000);
      
   }

   if(st == 1 && mode == 5){
    Serial.println(5 + String(",") + 5);
      digitalWrite(22,LOW);
      digitalWrite(23,LOW);
      digitalWrite(24,LOW);
      digitalWrite(25,LOW);
      digitalWrite(26,HIGH);
      stop = false;

        digitalWrite(inj,HIGH);
        delayMicroseconds(St_Micro_delay_5);
        digitalWrite(inj,LOW);
        delay(St_delay_5);
        analogWrite(scv,St_scv_5);

        for(st_fan = 10; st_fan <=80 ; st_fan = st_fan + 10){
          analogWrite(motor,st_fan);
          delay(50);
        }
        analogWrite(motor,90);

      for(int h = 0 ; h <30000 ; h = h+hTime_5){
        aa();
         if(h >= 100 && h <=200){
          Serial.println(5);
         }
         if(h >= 3000 && h <=3100){
          Serial.println(13);
         }
         if(h >= 6000 && h <=6100){
          Serial.println(29);
         }
         if(h >= 9000 && h <=9100){
          Serial.println(41);
         }
         if(h >= 12000 && h <=12100){
          Serial.println(52);
         }
         if(h >= 15000 && h <=15100){
          Serial.println(59);
         }
         if(h >= 18000 && h <=18100){
          Serial.println(65);
         }
          if(h >= 21000 && h <=21100){
          Serial.println(70);
         }
         if(h >= 24000 && h <=23100){
          Serial.println(78);
         }
         if(h >= 27000 && h <=27100){
          Serial.println(85);
         }
         if(h >= 29000 && h <=29100){
          Serial.println(95);
         }
         ll = Serial.read();
         digitalWrite(inj,HIGH);
         delayMicroseconds(St_Micro_delay_5);
         digitalWrite(inj,LOW);
         delay(St_delay_5);
         analogWrite(scv,St_scv_5);
         analogWrite(motor,90);
         
         if(ll == '7'){
            analogWrite(motor,0);
            Serial.println(0);
            stop = true;
            for(int j = 0 ; j <= 50 ; j++){
              digitalWrite(inj,HIGH);
              delayMicroseconds(St_Micro_delay_5);
              digitalWrite(inj,LOW);
              delay(St_delay_5);
              analogWrite(scv,St_scv_5);
            }
              digitalWrite(inj,LOW);
              analogWrite(scv,0); 
          break;
          
         }
       }

        if(stop){
          st = 0;
          mode = 0;
          Serial.println(1000);
        }else{
          Serial.println(100);
          st = 0;
          mode = 0;
          analogWrite(motor,0);
            for(int j = 0 ; j <= 50 ; j++){
              digitalWrite(inj,HIGH);
              delayMicroseconds(St_Micro_delay_5);
              digitalWrite(inj,LOW);
              delay(St_delay_5);
              analogWrite(scv,St_scv_5);
            }
              digitalWrite(inj,LOW);
              analogWrite(scv,0); 
          
        }
        digitalWrite(22,LOW);
        digitalWrite(23,LOW);
        digitalWrite(24,LOW);
        digitalWrite(25,LOW);
        digitalWrite(26,LOW);
        st = 0;
        mode = 0;
        Serial.println(1000);
        delay(3000);
        
      
   }
  //************************************************************* 
   if(ll == 'A'){
    digitalWrite(13,HIGH);
    St_scv_1 = 1+40;
    St_delay_1 = 30;
    St_Micro_delay_1 = 2000;

    St_scv_2 = 37;
    St_delay_2 = 35;
    St_Micro_delay_2 = 2200;

    St_scv_3 = 37;
    St_delay_3 = 25;
    St_Micro_delay_3 =2200;

    St_scv_4 = 35;
    St_delay_4 =35;
    St_Micro_delay_4 =2200;

    St_scv_5 = 33;
    St_delay_5 =45;
    St_Micro_delay_5 =2200;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'B'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;
    
    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
    
   }
   if(ll == 'C'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'D'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;
    
    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'E'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'F'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'G'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'H'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'I'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'J'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'K'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'L'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'M'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'N'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'O'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'P'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'Q'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'R'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'S'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'T'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'U'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'V'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'W'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'X'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'Y'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'Z'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'a'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'b'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;
    
    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'c'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'd'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'e'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'f'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'g'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'h'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'i'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'j'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'k'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'l'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'm'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;
    
    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'n'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'o'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'p'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'q'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 'r'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
   if(ll == 's'){
    St_scv_1 = 0;
    St_delay_1 =0;
    St_Micro_delay_1 =0;

    St_scv_2 = 0;
    St_delay_2 =0;
    St_Micro_delay_2 =0;

    St_scv_3 = 0;
    St_delay_3 =0;
    St_Micro_delay_3 =0;

    St_scv_4 = 0;
    St_delay_4 =0;
    St_Micro_delay_4 =0;

    St_scv_5 = 0;
    St_delay_5 =0;
    St_Micro_delay_5 =0;

    hTime_1 = 31;
    hTime_2 = 41;
    hTime_3 = 31;
    hTime_4 = 41;
    hTime_5 = 41;
   }
  }
}
