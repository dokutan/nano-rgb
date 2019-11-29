//nano-rgb example

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
  
}

//rgb values
int r = 255, g = 255, b = 255;

void loop() {
  
  //set rgb values
  if( digitalRead(sw1) == LOW ){
    switch(r){
      case 255: r = 0; break;
      case 0: r = 128; break;
      case 128: r = 255; break;
      default: break;
    }
    delay(300);
  }
  if( digitalRead(sw2) == LOW ){
    switch(g){
      case 255: g = 0; break;
      case 0: g = 128; break;
      case 128: g = 255; break;
      default: break;
    }
    delay(300);
  }
  if( digitalRead(sw3) == LOW ){
    switch(b){
      case 255: b = 0; break;
      case 0: b = 128; break;
      case 128: b = 255; break;
      default: break;
    }
    delay(300);
  }
  
  //write values
  analogWrite(ch1_r, r);
  analogWrite(ch1_g, g);
  analogWrite(ch1_b, b);
  
  analogWrite(ch2_r, r);
  analogWrite(ch2_g, g);
  analogWrite(ch2_b, b);
  
}
