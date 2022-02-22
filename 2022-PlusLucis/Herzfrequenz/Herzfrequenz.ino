#include <phyphoxBle.h>

int ADC_GPIO = 2;    // ESP32
//int ADC_GPIO = A0;  // Arduino Nano 33 BLE

void setup() {

  
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  PhyphoxBLE::start("Workshop");

  PhyphoxBleExperiment Voltmeter;

  Voltmeter.setTitle("Workshop");
  Voltmeter.setCategory("Arduino Experiments");
  Voltmeter.setDescription("This experiment will plot the measured voltage over time.");

  //View
  PhyphoxBleExperiment::View firstView;
  firstView.setLabel("Rawdata"); //Create a "view"

  //Graph
  PhyphoxBleExperiment::Graph firstGraph;      //Create graph which will plot random numbers over time
  firstGraph.setLabel("Voltmeter");
  firstGraph.setUnitX("s");
  firstGraph.setUnitY("V");
  firstGraph.setLabelX("time");
  firstGraph.setLabelY("Voltage");

  /* Assign Channels, so which data is plotted on x or y axis
     first parameter represents x-axis, second y-axis
     Channel 0 means a timestamp is created after the BLE package arrives in phyphox
     Channel 1 to N corresponding to the N-parameter which is written in server.write()
  */

  firstGraph.setChannel(0, 1);

  firstView.addElement(firstGraph);            //attach graph to view
  Voltmeter.addView(firstView);                //Attach view to experiment
  PhyphoxBLE::addExperiment(Voltmeter);        //Attach experiment to server

}

void loop() {
  // put your main code here, to run repeatedly:


  float voltage = 0;
  float startTime = millis();
  int counter =0;

  while( millis()<startTime+30 ){
    voltage = voltage + 3.3 * analogRead(ADC_GPIO)/4095;
    counter+=1;
    }

  voltage = voltage/counter;
 
  PhyphoxBLE::write(voltage);

  Serial.print("Voltage = ");
  Serial.println(voltage);

//  delay(20);
}
