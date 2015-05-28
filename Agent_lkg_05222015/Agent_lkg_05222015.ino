#include "Buzzer.h"
#include "Depth.h"
#include "Power.h"
#include "Sonar.h"
#include "SparkFunIMU.h"
#include "Thruster.h"
#include "Raspberry.h"
#include <Servo.h>
#include <string.h>

/*---------------------Status Word-----------------------*/
char Data_Raspberry[Raspberry_Data_Width];
char Data_Sonar[Sonar_Data_Width];
char x[8], y[8], z[8];
int TH[4] = {1500, 1500, 1500 ,1500};
int cmd = 0


/*---------------------Status Word-----------------------*/
int Th_PWR = 0;

/*---------------------Status Command-----------------------*/
char Ready[] = "Ready";
char Th_Set[] = "Th_Set";
int resetPin = 12;

void setup()
{
  digitalWrite(resetPin, HIGH);
  pinMode(resetPin, OUTPUT);
  Raspberry_Init();
  Buzzer_Init();
  Power_Init();
  SparkFun_IMU_Init();
  Sonar_Init();
//  Thruster_Init();
}

void loop() {
  
  
  strcpy(Data_Raspberry, "");// clear command
  Raspberry_RX(Data_Raspberry);
  
  cmd = toInt(Data_Raspberry);
  switch(cmd) {
        case 1: //IMU
         IMU_Data(IMU)
         Serial.println(IMU)
         break;
        
        case 2: //PwrOn
         if(Th_PWR == 0) { Th_PWR = Thruster_PWR(Thruster_ON); Thruster_Init(); Buzzer_3x500ms(); }
         Raspberry_TX(Ready);
         Thruster_Stop(); 
       
        break;
        
        case 3: //PwrOff
          
            Th_PWR = Thruster_PWR(Thruster_OFF);
          
        Raspberry_TX("Pwr_Off");
        
        break;
        
        case 4: //Idle 
          Thruster_Stop(); 
          
         
        
        break;
        
        case 5:  //Hover
          TH[0] = IDLE; TH[1] = Thruster2; TH[2] = IDLE; TH[3] = IDLE; 
          
        
        break;
        case 6: //Motion
          TH[0] = IDLE; TH[1] = IDLE; TH[2] = Thruster3; TH[3] = IDLE;
          
        
        break;
        case 7: //Right
          TH[0] = IDLE; TH[1] = IDLE; TH[2] = IDLE; TH[3] = Thruster4; 
          
        
        break; 
        case 8:  //Left
          TH[0] = Thruster1; TH[1] = Thruster2; TH[2] = IDLE; TH[3] = IDLE; 
          
         
        break;
        case 9: //Rise
          TH[0] = Reverse1; TH[1] = Reverse2; TH[2] = IDLE; TH[3] = IDLE; 
          
        break;
        case 10:  //Dive
          TH[0] = IDLE; TH[1] = IDLE; TH[2] = IDLE; TH[3] = IDLE;
          
        break;
        // Thruster_Setting(Data_Raspberry, TH);
        
        case 11: //Fwd
        
        TH[0] = IDLE; TH[1] = IDLE; TH[2] = IDLE; TH[3] = IDLE;
        
        break;
        
        case 12: //Back
        
        TH[0] = IDLE; TH[1] = IDLE; TH[2] = IDLE; TH[3] = IDLE;
        
        break;
        
        case 13: //Reset
        Raspberry_TX(Reset);
        digitalWrite (resetPin LOW);
        break;
        }


                   
     


