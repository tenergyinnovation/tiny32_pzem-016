/***********************************************************************
 * Project      :     tiny32_pzem016_setAddress
 * Description  :     Set Address to PZEM-016 Modbus RTU power meter module
 * Hardware     :     tiny32         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14/04/2022
 * Revision     :     1.0
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-380-3299
 ***********************************************************************/
#include <Arduino.h>
#include <tiny32.h>

tiny32 mcu; //define object

uint8_t id = 1; //current address of PZEM-016, You can change here if it differance
uint8_t new_id = 2; //new address of PZEM-016, You can change here if it differance


void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** tiny32_pzem016_setAddress ****\r\n");
  mcu.buzzer_beep(2); //buzzer 2 beeps
}

void loop()
{

  int8_t _response_id;
  _response_id = mcu.PZEM_016_SetAddress(id,new_id);

  /* check status */
  if(_response_id != -1)
  {
    Serial.printf("Info: Success to new address : %d\r\n",_response_id);
  }
  else
  {
    Serial.printf("Error: can't change address\r\n");
  }

  vTaskDelay(5000);

}