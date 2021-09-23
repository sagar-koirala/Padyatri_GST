#define battery_temp_pin  A3
#define an_read_pin A5

int raw_battery_temp =0;
int raw_an_read =0;

float battery_temp;
float an_read;

void setup() {
  pinMode(battery_temp_pin,INPUT);
  pinMode(an_read_pin,INPUT);
  Serial.begin(9600);
}

void loop() {
  raw_battery_temp = analogRead(battery_temp_pin);
  raw_an_read = analogRead(an_read_pin);
  battery_temp = map(raw_battery_temp,0,1023,0,100);
  an_read = map(raw_an_read,0,1023,0,255);

  Serial.println("                   ----Raw readings----  |  ----Real values----");
  Serial.print("Battery_temp_pin:          ");
  Serial.print(raw_battery_temp);
  Serial.print("                       ");
  Serial.print(battery_temp);
  Serial.println("*C");

  Serial.print("Analog_read_pin:           ");
  Serial.print(raw_an_read);
  Serial.print("                       ");
  Serial.print(an_read);
  Serial.println("");

  Serial.println();

  delay(100);
}
