/***********************************************************************
 * Project      :     tiny32_pzem016_getParam
 * Description  :     Get each parameter from PZEM-016 Modbus RTU power meter module
 * Hardware     :     tiny32         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Revision     :     1.2
 * Rev1.0       :     Original
 * Rev1.1       :     Add Relay On, Show Library version  
 * Rev1.2       :     Add PZEM_016_begin
 * Rev1.3       :     Add tiny32_v3
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-380-3299
 ***********************************************************************/
#include <Arduino.h>
//#include <tiny32.h> //for tiny32 original board
#include <tiny32_v3.h> //for tiny32 v3


tiny32 mcu; //define object

uint8_t id = 1; //Address if PZEM-016, You can change here if it differance

float volt, amp, power, freq, pf;
uint16_t energy;


void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** tiny32_pzem016_getParam ****\r\n");
  mcu.PZEM_016_begin(RXD2,TXD2);
  mcu.Relay(1);
  vTaskDelay(3000);
  mcu.buzzer_beep(2); //buzzer 2 beeps
  mcu.library_version();
}

void loop()
{

    /* Read voltage parameter */
    volt = mcu.PZEM_016_Volt(id);
    if(volt != -1)
    {
      Serial.printf("Info: volt = %.2fV\r\n",volt);
    }
    else
    {
      Serial.printf("Error: can't read volt!!\r\n");
    }

    /* Read current parameter */
    amp = mcu.PZEM_016_Amp(id);
     if(amp != -1)
     {
       Serial.printf("Info: current = %.2fA\r\n",amp);
     }
    else
    {
      Serial.printf("Error: can't read current!!\r\n");
    }


    /* Read power parameter */
    power = mcu.PZEM_016_Power(id);
    if(volt != -1)
    {
      Serial.printf("Info: Power = %.1fW\r\n",power);
    }
    else
    {
      Serial.printf("Error: can't read power!!\r\n");
    }

    /* Read energy parameter */
    energy = mcu.PZEM_016_Energy(id);
    if(volt != -1)
    {
      Serial.printf("Info: energy = %dWh\r\n",energy);
    }
    else
    {
      Serial.printf("Error: can't read engergy!!\r\n");
    }

    /* Read frequency parameter */
    freq = mcu.PZEM_016_Freq(id);
    if(volt != -1)
    {
      Serial.printf("Info: frequency = %0.1fHz\r\n",freq);
    }
    else
    {
      Serial.printf("Error: can't read frequency!!\r\n");
    }

    /* Read power factor parameter */
    pf = mcu.PZEM_016_PF(id);
    if(volt != -1)
    {
      Serial.printf("Info: pf = %.2f\r\n",pf);
    }
    else
    {
      Serial.printf("Error: can't read power factor!!\r\n");
    }

    Serial.println("********************************\r\n");
  
    vTaskDelay(5000);

}