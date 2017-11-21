// This reads the Copernicus on Teensy Serial Port 1, and writes to the 
// default Serial port (Arduino IDE Serial Monitor), and Open Log. 

int line_count=0; // This counts the ascii 10s (newline) and is reset after we reach the number of NMEA setances per GPS fix.
void setup() {
  
Serial.begin(57600);   //USB Monitor
        
Serial1.begin(57600);  //GPS
        
Serial2.begin(57600);  //OpenLog 

}

void loop() {
  int counter = 1;
  if (Serial1.available()) { //gps stuff 1 if 
   char gps_byte =Serial1.read();
   Serial.print(gps_byte);
   Serial2.print(gps_byte);
   if (gps_byte == 10){ // gps_byte = 10 if 
     line_count++;  
       if (line_count == 2){ // line_count = 2 if 
        Serial.println("");
        Serial2.println("");
        line_count =0;
        
        //This where we have the GPS lines, so we can poll the other sensors. 

        
        
    } // end of line_count = 2 

   } // end of gps_byte = 10 
 
  } // end of GPS stuff if

counter ++; 
  
} //END OF MAIN LOOP
