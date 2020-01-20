
int btn = 7;
int btnState = 0;
int music = 8;
int tracker = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(btn, INPUT_PULLUP);
  pinMode(music, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  btnState = digitalRead(btn);
  digitalWrite(music,HIGH);  
  
  if(btnState == LOW){
    if(tracker == 1){
      delay(30000);
      digitalWrite(music, LOW);
      delay(200000);      
    }
    else{
      tracker++;
      delay(30000);
    }
  }
}
