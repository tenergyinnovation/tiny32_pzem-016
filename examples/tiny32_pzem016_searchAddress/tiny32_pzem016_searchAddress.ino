/***********************************************************************
 * Project      :     tiny32_pzem016_searchAddress
 * Description  :     Search Address for PZEM-016 Modbus RTU power meter module
 * Hardware     :     tiny32         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Revision     :     1.1
 * Rev1.0       :     Original
 * Rev1.1       :     Add Relay On, Show Library version  
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
  mcu.Relay(1);
  vTaskDelay(3000);
  mcu.buzzer_beep(2); //buzzer 2 beeps
  mcu.library_version();
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