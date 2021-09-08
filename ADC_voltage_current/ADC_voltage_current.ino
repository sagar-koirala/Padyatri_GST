#define charge_volt_pin A0
#define charge_current_pin  A2
#define load_current_pin A1

int raw_charge_volt =0;
int raw_charge_current =0;
int raw_load_current =0;

float charge_volt = 0;
int charge_current = 0;
int load_current = 0;

void setup() {
  pinMode(charge_volt_pin, INPUT);
  pinMode(charge_current_pin, INPUT);
  pinMode(load_current_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  raw_charge_volt = analogRead(charge_volt_pin);
  raw_charge_current = analogRead(charge_current_pin);
  raw_load_current = analogRead(load_current_pin);
  charge_volt = map(raw_charge_volt,0,1023,0,420)/100.0;
  charge_current = map(raw_charge_current,0,1023,0,5000);
  load_current = map(raw_load_current,0,1023,0,5000);
  
  Serial.println("                   ----Raw readings----  |  ----Real values----");
  Serial.print("Charge_volt_pin:            ");
  Serial.print(raw_charge_volt);
  Serial.print("                      ");
  Serial.print(charge_volt);
  Serial.println("V");
  
  Serial.print("Charge_current_pin:         ");
  Serial.print(raw_charge_current);
  Serial.print("                       ");
  Serial.print(charge_current);
  Serial.println("mA");

  Serial.print("Load_current_pin:           ");
  Serial.print(raw_load_current);  
  Serial.print("                       ");
  Serial.print(load_current);
  Serial.println("mA");

  Serial.println();

  delay(100);
}
