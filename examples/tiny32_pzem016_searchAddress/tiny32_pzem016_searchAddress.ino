/***********************************************************************
 * Project      :     tiny32_pzem016_searchAddress
 * Description  :     Search Address for PZEM-016 Modbus RTU power meter module
 * Hardware     :     tiny32         
 * Author       :     Tenergy Innovation Co., Ltd.
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


tiny32 mcu; //define object

void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** tiny32_pzem016_searchAddress ****\r\n");
  mcu.PZEM_016_begin(RXD2,TXD2);
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