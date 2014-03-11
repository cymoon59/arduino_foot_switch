uint8_t buf[8] = {0};

const int LEFT_CTRL = 0xE0;
const int LEFT_ALT  = 0xE2;
const int KEYCODE_A = 0x04;
const int KEYCODE_B = 0x05;


const int pedalPin1 = 2;
const int pedalPin2 = 3;
const int ledPin1 = 4;

int lastPedalEvent1 = 0;
int lastPedalEvent2 = 0;

int DBG_MODE = 0;


void setup()
{
  Serial.begin(9600);
  pinMode(pedalPin1, INPUT);
  pinMode(pedalPin2, INPUT);
  pinMode(ledPin1, OUTPUT);
  
}

void loop()
{
  int pedalEvent1 = digitalRead(pedalPin1);
  int pedalEvent2 = digitalRead(pedalPin2);

  if((lastPedalEvent1 == pedalEvent1) && (lastPedalEvent2 == pedalEvent2)) {
    return;
  }
  
  if((pedalEvent1 == HIGH) || (pedalEvent2 == HIGH)) {
    if(pedalEvent1 == HIGH) input(KEYCODE_A);
    if(pedalEvent2 == HIGH) input(KEYCODE_B);
    lastPedalEvent1 = pedalEvent1;
    lastPedalEvent2 = pedalEvent2;
    digitalWrite(ledPin1, HIGH);
  } else {
    releaseKey();
    lastPedalEvent1 = pedalEvent1;
    lastPedalEvent2 = pedalEvent2;    
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
