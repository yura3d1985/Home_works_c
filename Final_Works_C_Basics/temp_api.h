#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

struct temp_sensor 
{
	uint16_t  year;
	 uint8_t  month;
	 uint8_t  day;
	 uint8_t  hour;
	 uint8_t  minute;
	 int16_t  temp;
};

void AddRecord(struct temp_sensor*, uint32_t, uint16_t, uint8_t, uint8_t, uint8_t, uint8_t, int16_t);

float Average_Year_temp(struct temp_sensor*, uint32_t, uint16_t);
int8_t   Min_Year_temp(struct temp_sensor*, uint32_t, uint16_t);
int8_t   Max_Year_temp(struct temp_sensor*, uint32_t, uint16_t);

float Average_Month_temp(struct temp_sensor*, uint32_t, uint16_t, uint8_t);
int8_t   Min_Month_temp(struct temp_sensor*, uint32_t, uint16_t, uint8_t);
int8_t   Max_Month_temp(struct temp_sensor*, uint32_t, uint16_t, uint8_t);