#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with the I2C address (usually 0x27) and dimensions
LiquidCrystal_I2C lcd(0x27, 16, 2); // 16 columns, 2 rows

// Define the pin for the turbidity sensor
const int turbiditySensorPin = A0;

void setup() {
  // Initialize the LCD
  lcd.begin(16, 2); // Specify the dimensions of the LCD
  lcd.backlight();
  
  // Initialize the serial communication for debugging
  Serial.begin(9600);

  // Display a welcome message
  lcd.setCursor(0, 0);
  lcd.print("thrixxy tech");
  lcd.setCursor(0, 1);
  lcd.print("Water Turbidity");
  delay(2000); // Wait for 2 seconds
  lcd.clear();
}

void loop() {
  // Read the analog value from the turbidity sensor
  int sensorValue = analogRead(turbiditySensorPin);
  Serial.println(sensorValue);
  int turbidity = map(sensorValue, 0, 650, 100, 0);
  delay(100);
  lcd.setCursor(0, 0);
  lcd.print("Turbidity:");
  lcd.print("   ");
  lcd.setCursor(10, 0);
  lcd.print(turbidity);
  
  delay(100);
  if (turbidity < 20) {
    lcd.setCursor(0, 1);
    lcd.print(" its CLEAR ");
    Serial.print(" its CLEAR ");
  }
  if ((turbidity > 20) && (turbidity < 50)) {
    lcd.setCursor(0, 1);
    lcd.print(" its CLOUDY ");
    Serial.print(" its CLOUDY ");
  }
  if (turbidity > 50) {
    lcd.setCursor(0, 1);
    lcd.print(" its DIRTY ");
    Serial.print(" its DIRTY ");
  }

}
