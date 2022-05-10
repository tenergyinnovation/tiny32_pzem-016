/***********************************************************************
 * Project      :     tiny32_pzem016_resetEnergy
 * Description  :     Reset Engergy value to PZEM-016 Modbus RTU power meter module
 * Hardware     :     tiny32         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14/04/2022
 * Revision     :     1.2
 * Rev1.0       :     Original
 * Rev1.1       :     Add Relay On, Show Library version  
 * Rev1.2       :     Add PZEM_016_begin
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-380-3299
 ***********************************************************************/
#include <Arduino.h>
#include <tiny32.h>

tiny32 mcu; //define object

uint8_t id = 1; //Address if PZEM-016, You can change here if it differance

void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** tiny32_pzem016_resetEnergy ****\r\n");
  mcu.PZEM_016_begin(RXD3,TXD3);
  mcu.Relay(1);
  vTaskDelay(3000);
  mcu.buzzer_beep(2); //buzzer 2 beeps
  mcu.library_version();
}

void loop()
{

  if(mcu.PZEM_016_ResetEnergy(id)) //function return: true=success, false=unsuccess
  {
    Serial.printf("Info: Success reset engergy :)\r\n");
  }
  else
  {
    Serial.printf("Error: Can't reset engergy :)\r\n");
  }

  vTaskDelay(5000);

}