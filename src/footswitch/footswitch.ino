uint8_t buf[8] = {0};

const int LEFT_CTRL = 0xE0;
const int LEFT_ALT  = 0xE2;
const int KEYCODE_B = 0x05;


const int pedalPin1 = 1;
const int pedalPin2 = 2;
const int ledPin1 = 3;

int pedalState1 = 0;
int pedalState2 = 0;

int pedalState2Before = 1;

int DBG_MODE = 0;


void setup()
{
  Serial.begin(9600);
//  pinMode(pedalPin1, INPUT);
  pinMode(pedalPin2, INPUT);
  pinMode(ledPin1, OUTPUT);
  
}

void loop()
{
  
//  pedalState1 = digitalRead(pedalPin1);
  pedalState2 = digitalRead(pedalPin2);
  
  if(pedalState2 == pedalState2Before) {
    return;
  }
  
  if(pedalState2Before > 0) releaseKey();
  
  pedalState2Before = pedalState2;  
    
  if((pedalState2 == HIGH)) {
    if(DBG_MODE) {
      Serial.print("pedal[0][1]==[");
      Serial.print(pedalState1);
      Serial.print("][");
      Serial.print(pedalState2);      
      Serial.println("]");      
    }
      if(pedalState1 == HIGH) {
        input(LEFT_ALT);
      } else if(pedalState2 == HIGH) {
        input(LEFT_CTRL);
      }
      digitalWrite(ledPin1, HIGH);
  } else {
    digitalWrite(ledPin1, LOW);
  }
}

void input(int keycode) {
  buf[2] =  keycode;
  if(DBG_MODE) {
    Serial.print("input:");
    for(int i=0; i<8; i++) {
      Serial.print(buf[i]);
      Serial.print(",");
    }    
    Serial.println("");
  }
  
  Serial.write(buf, 8);
  delay(30);
  //releaseKey();
}

void releaseKey()
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);
  delay(30);
  if(DBG_MODE) {
    Serial.print("release:");
    for(int i=0; i<8; i++) {
      Serial.print(buf[i]
      );
      Serial.print(",");
    }
    Serial.println("");  
  }
}
