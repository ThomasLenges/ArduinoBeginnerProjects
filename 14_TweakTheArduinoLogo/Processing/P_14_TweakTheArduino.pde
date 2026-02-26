import processing.serial.*;
Serial myPort; // Library object

PImage logo; // Image instance
int bgcolor = 0;

String url = "https://picsum.photos/id/1025/400/300.jpg";

void setup(){
  colorMode(HSB, 255); // Each HSB channel ranges [0;255]
  
  logo = loadImage(url);
  if (logo == null) {
    println("Image inaccessible: " + url);
    exit();
  }
  
  surface.setSize(logo.width, logo.height);
 
  println("Availbale serial ports: ");
  println(Serial.list()); // Get list of PC serials ports
  
  myPort = new Serial(this, Serial.list()[0], 9600); // Change depending of printed list for Arduino board
}

// Analogous to Arduino loop()
void draw(){
  // Check in serial buffer
  if(myPort.available() > 0){
    bgcolor = myPort.read();
    println(bgcolor);
  }
  
  // Sets window color (takes HUE channels as inputs)
  background(bgcolor, bgcolor, bgcolor); 
  
  // Draws image and at what coordinates
  image(logo, bgcolor, 0);
}
