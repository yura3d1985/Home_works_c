#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
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

typedef struct stack
{
	struct temp_sensor data;
	struct stack *next;
}	temp_stack;

temp_stack* push(temp_stack*, struct temp_sensor);
temp_stack* pop(temp_stack *p);

uint32_t Create_Table_from_File(temp_stack**, char[]);
void Print_Table(const temp_stack*);

float Average_Year_temp(const temp_stack*, uint16_t);
int8_t   Min_Year_temp(const temp_stack*, uint16_t);
int8_t   Max_Year_temp(const temp_stack*, uint16_t);

float Average_Month_temp(const temp_stack*, uint16_t, uint8_t);
int8_t   Min_Month_temp(const temp_stack*, uint16_t, uint8_t);
int8_t   Max_Month_temp(const temp_stack*, uint16_t, uint8_t);