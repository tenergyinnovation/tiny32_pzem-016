/***********************************************************************
 * Project      :     tiny32_pzem016_searchAddress
 * Description  :     Search Address for PZEM-016 Modbus RTU power meter module
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

void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** tiny32_pzem016_searchAddress ****\r\n");
  mcu.buzzer_beep(2); //buzzer 2 beeps
  mcu.Relay(1);
  vTaskDelay(3000);
}

void loop()
{

  int8_t _id;
  
  _id = mcu.PZEM_016_SearchAddress();

  /* check result status */
  if(_id != -1)
  {
    Serial.printf("\r\nInfo: Address => %d\r\n",_id);
  }
  else
  {
    Serial.printf("\r\nError: Can't search address\r\n");
  }

  while(1);

}