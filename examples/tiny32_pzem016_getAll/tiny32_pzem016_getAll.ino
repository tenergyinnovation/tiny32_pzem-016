/***********************************************************************
 * Project      :     tiny32_pzem016_getAll
 * Description  :     Get All parameter with 1 command from PZEM-016 Modbus RTU power meter module
 * Hardware     :     tiny32         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14/04/2022
 * Revision     :     1.3
 * Rev1.0       :     Original
 * Rev1.1       :     Add Relay On, Show Library version  
 * Rev1.2       :     Add PZEM_016_begin
 * Rev1.3       :     Add tiny32_v3
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-308-3299
 ***********************************************************************/
#include <Arduino.h>
//#include <tiny32.h> //for tiny32 original board
#include <tiny32_v3.h> //for tiny32 v3

tiny32_v3 mcu; //define object

uint8_t id = 1; //Address if PZEM-016, You can change here if it differance

float volt, amp, power, freq, pf;
uint32_t energy;


void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** tiny32_pzem016_getAll ****\r\n");
  mcu.PZEM_016_begin(RXD2,TXD2);
  mcu.Relay(1);
  vTaskDelay(3000);
  mcu.buzzer_beep(2); //buzzer 2 beeps
  mcu.library_version();
}

void loop()
{
  
  //Get parameter from PZEM-016
  if(mcu.PZEM_016(id, volt, amp, power, energy,  freq, pf)) //function return: true=success, false=unsuccess
  {
    Serial.printf("Info: volt = %.2fV\r\n",volt);
    Serial.printf("Info: current = %.2fA\r\n",amp);
    Serial.printf("Info: Power = %.1fW\r\n",power);
    Serial.printf("Info: energy = %dWh\r\n",energy);
    Serial.printf("Info: frequency = %0.1fHz\r\n",freq);
    Serial.printf("Info: pf = %.2f\r\n",pf);
    Serial.println("********************************\r\n");
  }
  else  //can't get data from PZEM-016
  {
    Serial.printf("Error: Can't get data from PZEM-016!!\r\n");
  }

  vTaskDelay(5000);

}
