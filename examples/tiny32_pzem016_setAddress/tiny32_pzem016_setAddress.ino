/***********************************************************************
 * Project      :     tiny32_pzem016_setAddress
 * Description  :     Set Address to PZEM-016 Modbus RTU power meter module
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

uint8_t id = 1; //current address of PZEM-016, You can change here if it differance
uint8_t new_id = 2; //new address of PZEM-016, You can change here if it differance


void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** tiny32_pzem016_setAddress ****\r\n");
  mcu.PZEM_016_begin(RXD2,TXD2);
  mcu.Relay(1);
  vTaskDelay(3000);
  mcu.buzzer_beep(2); //buzzer 2 beeps
  mcu.library_version();
  Serial.print("Please press SW1 or SW2: ");
}

void loop()
{

  if (mcu.Sw1() || mcu.Sw2())
  {
    mcu.buzzer_beep(1);
    Serial.println("OK");
    while (mcu.Sw1() || mcu.Sw2());
    Serial.printf("Info: Old ID: %d\r\n", id);
    Serial.printf("Info: New ID: %d\r\n", new_id);

    int8_t _response_id;
    _response_id = mcu.PZEM_016_SetAddress(id,new_id);

    /* check status */
    if (_response_id != -1)
    {
      Serial.printf("Info: Success to new address : %d\r\n", _response_id);
    }
    else
    {
      Serial.printf("Error: can't change address\r\n");
    }

    while (1);
  }

}
