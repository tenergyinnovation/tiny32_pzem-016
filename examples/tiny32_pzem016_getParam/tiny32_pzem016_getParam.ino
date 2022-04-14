/***********************************************************************
 * Project      :     Example_pzem016_getParam
 * Description  :     Get each parameter from PZEM-016 Modbus RTU power meter module
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

uint8_t id = 1; //Address if PZEM-016, You can change here if it differance

float volt, amp, power, freq, pf;
uint16_t energy;


void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** Example_pzem016_getParam ****\r\n");
  mcu.buzzer_beep(2); //buzzer 2 beeps
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