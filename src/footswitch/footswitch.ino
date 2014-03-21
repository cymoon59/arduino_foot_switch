uint8_t buf[8] = {0};

const int LEFT_CTRL = 0xE0;
const int LEFT_ALT  = 0xE2;
const int KEYCODE_A = 0x04;
const int KEYCODE_B = 0x05;

const int KEYCODE_F8 = 0x41;
const int KEYCODE_F9 = 0x42;

const int KEYCODE_SPACE = 0x2c;
const int KEYCODE_PAGEUP = 0x4B;
const int KEYCODE_PAGEDOWN = 0x4E;

const int pedalPin1 = 2;
const int pedalPin2 = 3;
const int ledRedPin = 4;
const int ledGreenPin = 5;
const int ledBluePin = 6;
const int modeButtonPin = 7;

const int MODE_EMACS = 0;
const int MODE_INTELLIJ = 1;
const int MODE_INTERNET = 2;

int lastPedalEvent1 = 0;
int lastPedalEvent2 = 0;
int lastModeEvent = 1;

int mode = 3;

int DBG_MODE = 0;


void setup()
{
  Serial.begin(9600);
  pinMode(pedalPin1, INPUT);
  pinMode(pedalPin2, INPUT);
  pinMode(ledRedPin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledBluePin, OUTPUT);
  pinMode(modeButtonPin, INPUT);
  
}

void loop()
{
  int pedalEvent1 = digitalRead(pedalPin1);
  int pedalEvent2 = digitalRead(pedalPin2);

  int modeButtonEvent = digitalRead(modeButtonPin);
  
  
  if(lastModeEvent != modeButtonEvent) {
    if(modeButtonEvent == HIGH) {
      mode = (mode+1)%3;
      if(DBG_MODE) {
        Serial.print("mode:");
        Serial.println(mode);
      }
    switch(mode) {
      case MODE_EMACS:
        setColor(50, 0, 0);
      break;
      case MODE_INTELLIJ:
        setColor(0, 50, 0);
      break;
      case MODE_INTERNET:
        setColor(0, 0, 50);
      break;
    }
      delay(50);
    }
    lastModeEvent = modeButtonEvent;
  }
  
  if((lastPedalEvent1 == pedalEvent1) && (lastPedalEvent2 == pedalEvent2)) {
    return;
  }
  
  if((pedalEvent1 == HIGH) || (pedalEvent2 == HIGH)) {
    if(pedalEvent1 == HIGH) {
      input(getLeftInput());
      if(mode != MODE_EMACS) {
        releaseKey();
      }
    }
    if(pedalEvent2 == HIGH) {
      input(getRightInput());
      if(mode != MODE_EMACS) {
        releaseKey();
      }
    }
    lastPedalEvent1 = pedalEvent1;
    lastPedalEvent2 = pedalEvent2;
    setColor(50, 50, 0);
  } else {
    releaseKey();
    lastPedalEvent1 = pedalEvent1;
    lastPedalEvent2 = pedalEvent2;    
    setColor(0, 0, 0);
  }
}

void setColor(int red, int green, int blue)
{
  analogWrite(ledRedPin, red);
  analogWrite(ledGreenPin, green);
  analogWrite(ledBluePin, blue); 
}

int getLeftInput() {
  int keycode = LEFT_CTRL;
  switch(mode) {
    case MODE_EMACS:
      keycode = LEFT_CTRL;
    break;
    case MODE_INTELLIJ:
      keycode = KEYCODE_F8;
    break;
    case MODE_INTERNET:
      keycode = KEYCODE_PAGEUP;
    break;
  }
  return keycode;
}

int getRightInput() {
  int keycode = LEFT_ALT;
  switch(mode) {
    case MODE_EMACS:
      keycode = LEFT_ALT;
    break;
    case MODE_INTELLIJ:
      keycode = KEYCODE_F9;
    break;
    case MODE_INTERNET:
      keycode = KEYCODE_PAGEDOWN;
    break;
  }
  return keycode;
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
