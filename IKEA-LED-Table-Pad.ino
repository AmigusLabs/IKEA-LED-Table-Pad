/* IKEA LED Table pad using Funduino Joystick Shield V1.A
*/

int up_button = 2;
int down_button = 4;
int left_button = 5;
int right_button = 3;
int start_button = 6;
int select_button = 7;
int joystick_button = 8;
int joystick_axis_x = A0;
int joystick_axis_y = A1;
int buttons[] = {up_button, down_button, left_button, right_button, start_button, select_button, joystick_button};

int up_idx = 0;
int down_idx = 1;
int left_idx = 2;
int right_idx = 3;
int start_idx = 4;
int select_idx = 5;
int joystick_idx = 6;

int lastState[] = {1, 1, 1, 1, 1, 1, 1};
int buttonValue[] = {(byte)236, (byte)237, (byte)238, (byte)239, (byte)224, (byte)225, (byte)0};


void setup() {
  for (int i; i < 7; i++)
  {
    pinMode(buttons[i], INPUT);
    digitalWrite(buttons[i], HIGH);
  }
  Serial.begin(38400);
}

void loop() {

  for (int i = 0; i < 7; i++) {
    int currentValue = digitalRead(buttons[i]);
    if (lastState[i] && !currentValue) {
      lastState[i] = 1;
      Serial.write(buttonValue[i]);
    }
    lastState[i] = currentValue;
  }
  /*
    Serial.print("UP = "),Serial.print(digitalRead(up_button)),Serial.print("\t");
    Serial.print("DOWN = "),Serial.print(digitalRead(down_button)),Serial.print("\t");
    Serial.print("LEFT = "),Serial.print(digitalRead(left_button)),Serial.print("\t");
    Serial.print("RIGHT = "),Serial.print(digitalRead(right_button)),Serial.print("\t");
    Serial.print("START = "),Serial.print(digitalRead(start_button)),Serial.print("\t");
    Serial.print("SELECT = "),Serial.print(digitalRead(select_button)),Serial.print("\t");
    Serial.print("ANALOG = "),Serial.print(digitalRead(joystick_button)),Serial.print("\t");
    Serial.print("X = "),Serial.print(map(analogRead(joystick_axis_x), 0, 1000, -1, 1));Serial.print("\t");
    Serial.print("Y = "),Serial.print(map(analogRead(joystick_axis_y), 0, 1000, -1, 1));Serial.print("\n");
    Serial.print("X = "),Serial.print(analogRead(joystick_axis_x));Serial.print("\t");
    Serial.print("Y = "),Serial.print(analogRead(joystick_axis_y));Serial.print("\n");
  */
  delay(5);
}


