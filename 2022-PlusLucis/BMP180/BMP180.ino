#include <Adafruit_BMP085.h>
#include <phyphoxBle.h>

Adafruit_BMP085 bmp;
float temperature;
float pressure;
  
void setup() {
  Serial.begin(115200);
  if (!bmp.begin()) {
	Serial.println("Could not find a valid BMP085 sensor, check wiring!");
	while (1) {}
  }
  PhyphoxBLE::start("BMP180");
  PhyphoxBleExperiment Wetterstation; 
  Wetterstation.setTitle("Wetterstation");
  Wetterstation.setCategory("Plus Lucis Workshop");
  Wetterstation.setDescription("Temperatur und Luftdruck werden vom BMP180 ausgelesen.");

  PhyphoxBleExperiment::View firstView;
  firstView.setLabel("Rohdaten");

  PhyphoxBleExperiment::Graph pressureGraph;      //Create graph which will plot random numbers over time
  pressureGraph.setLabel("Luftdruck");
  pressureGraph.setUnitX("s");
  pressureGraph.setUnitY("hPa");
  pressureGraph.setLabelX("t");
  pressureGraph.setLabelY("p");
  pressureGraph.setChannel(0,1);

  PhyphoxBleExperiment::Graph temperatureGraph;      //Create graph which will plot random numbers over time
  temperatureGraph.setLabel("Temperatur");
  temperatureGraph.setUnitX("s");
  temperatureGraph.setUnitY("°C");
  temperatureGraph.setLabelX("t");
  temperatureGraph.setLabelY("T");
  temperatureGraph.setChannel(0,2);

  firstView.addElement(pressureGraph);      
  firstView.addElement(temperatureGraph);   
  Wetterstation.addView(firstView);         
  PhyphoxBLE::addExperiment(Wetterstation);   

}
  
void loop() {
    temperature = bmp.readTemperature();
    pressure = 0.1*bmp.readPressure();
    Serial.print("Temperature = ");
    Serial.print(temperature);
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(pressure);
    Serial.println(" Pa");
    PhyphoxBLE::write(pressure, temperature);

    delay(100);
}
