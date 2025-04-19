#include "temp_api.h"

void AddRecord(struct temp_sensor* info, uint32_t number, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int16_t temp)
{ 
	info[number].year   = year;
	info[number].month  = month;
	info[number].day    = day;
	info[number].hour   = hour;
	info[number].minute = minute;
	info[number].temp   = temp;
}

float Average_Year_temp(struct temp_sensor* info, uint32_t data_size, uint16_t year)
{
	uint32_t i, n = 0;
	float temp_average, temp_summa = 0;

	for(i=0; i<data_size; i++)
	{
		if(info[i].year == year)
		{
			temp_summa = temp_summa + info[i].temp;
			n++;
		}
			
	}
	
	if (temp_summa == 0) return temp_average = 0;
	else return temp_average = temp_summa / (n);
}

int8_t Min_Year_temp(struct temp_sensor* info, uint32_t data_size, uint16_t year)
{
	int8_t min_temp;
	uint32_t i; 
		
	for(i=0; i<data_size; i++)
	{
		if(info[i].year == year)
		{
			min_temp = info[i].temp;
			break;
		}
			
	}
	
	for(i=0; i<data_size; i++)
	{
		if(info[i].year == year)
		{
			if(info[i].temp < min_temp)
			{
				min_temp = info[i].temp;
			}
		}
			
	}
	
	return min_temp;
}

int8_t Max_Year_temp(struct temp_sensor* info, uint32_t data_size, uint16_t year)
{
	int8_t max_temp;
	uint32_t i; 
		
	for(i=0; i<data_size; i++)
	{
		if(info[i].year == year)
		{
			max_temp = info[i].temp;
			break;
		}
			
	}
	
	for(i=0; i<data_size; i++)
	{
		if(info[i].year == year)
		{
			if(info[i].temp > max_temp)
			{
				max_temp = info[i].temp;
			}
		}
			
	}
	
	return max_temp;
}

float Average_Month_temp(struct temp_sensor* info, uint32_t data_size, uint16_t year, uint8_t month)
{
	uint32_t i, n = 0;
	float temp_average, temp_summa = 0;

	for(i=0; i<data_size; i++)
	{
		if ((info[i].year == year) && (info[i].month == month))
		{
			temp_summa = temp_summa + info[i].temp;
			n++;
		}
			
	}
	if (temp_summa == 0) return temp_average = 0;
	else return temp_average = temp_summa / (n);
}

int8_t Min_Month_temp(struct temp_sensor* info, uint32_t data_size, uint16_t year, uint8_t month)
{
	int8_t min_temp;
	uint32_t i; 
		
	for(i=0; i<data_size; i++)
	{
		if((info[i].year == year) && (info[i].month == month))
		{
			min_temp = info[i].temp;
			break;
		}
			
	}
	
	for(i=0; i<data_size; i++)
	{
		if((info[i].year == year) && (info[i].month == month))
		{
			if(info[i].temp < min_temp)
			{
				min_temp = info[i].temp;
			}
		}
			
	}
	
	return min_temp;
}

int8_t Max_Month_temp(struct temp_sensor* info, uint32_t data_size, uint16_t year, uint8_t month)
{
	int8_t max_temp;
	uint32_t i; 
		
	for(i=0; i<data_size; i++)
	{
		if((info[i].year == year) && (info[i].month == month))
		{
			max_temp = info[i].temp;
			break;
		}
			
	}
	
	for(i=0; i<data_size; i++)
	{
		if((info[i].year == year) && (info[i].month == month))
		{
			if(info[i].temp > max_temp)
			{
				max_temp = info[i].temp;
			}
		}
			
	}
	
	return max_temp;
}