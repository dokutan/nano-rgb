//nano-rgb serial-in
//reads the color values over serial

//channel 1 pins
int ch1_r = 6, ch1_g = 5, ch1_b = 3;
//channel 2 pins
int ch2_r = 11, ch2_g = 10, ch2_b = 9;
//pushbutton pins
int sw1 = 2, sw2 = 4, sw3 = 7, sw4 = 8;

void setup() {
  
  //set pinmodes
  pinMode(ch1_r, OUTPUT);
  pinMode(ch1_g, OUTPUT);
  pinMode(ch1_b, OUTPUT);
  
  pinMode(ch2_r, OUTPUT);
  pinMode(ch2_g, OUTPUT);
  pinMode(ch2_b, OUTPUT);
  
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode(sw4, INPUT_PULLUP);

  //turn all leds on
  analogWrite(ch1_r, 255);
  analogWrite(ch1_g, 255);
  analogWrite(ch1_b, 255);
  
  analogWrite(ch2_r, 255);
  analogWrite(ch2_g, 255);
  analogWrite(ch2_b, 255);

  Serial.begin(9600);
  
}

char buffer[4];

void loop() {
  delay(1);
  if( Serial.available() >= 4 ){
    Serial.readBytes( buffer, 4 );
    //if( buffer[0] == '1' ){
      analogWrite(ch1_r, buffer[1]);
      analogWrite(ch1_g, buffer[2]);
      analogWrite(ch1_b, buffer[3]);
    //}
  }
}
