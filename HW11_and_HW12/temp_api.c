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

uint32_t Create_Table_from_File(struct temp_sensor* temp_data, char file_name[])
{
	int16_t year;
	int8_t month, day, hour, minute, temp; 
	
	int i = 0, n = 0;
	uint32_t line_number = 1;
	signed char c_tmp, str_tmp[25] = {0};
	
	FILE *input_data;
	input_data = fopen(file_name, "r");

	
	
	if (input_data == NULL)
	{
		printf("open file error: file not found or name is incorrect\n");
		return 0;
	}

	
	do {
		if(((c_tmp = fgetc(input_data)) != '\n') && (c_tmp != EOF))
		{
			str_tmp[i] = c_tmp;
			i++;
		}
		else 
		{	
			n = sscanf(str_tmp, "%" SCNd16 ";" 
								"%" SCNd8  ";" 
								"%" SCNd8  ";" 
								"%" SCNd8  ";" 
								"%" SCNd8  ";" 
								"%" SCNd8, &year, &month, &day, &hour, &minute, &temp);

			if ((n<6) || (year   < 0)		|| (year   > 10000) 
					  || (month  < 0)		|| (month  > 12) 
					  || (day    < 0)		|| (day    > 31) 
					  || (hour   < 0)		|| (hour   > 24) 
					  || (minute < 0)		|| (minute > 60) 
					  || (temp   < -99)		|| (temp   > 99))
			{
				printf("ERROR FORMAT in line %d\t\t", line_number);
				printf("[%s]",str_tmp);
				printf("\t\tcorrect FORMAT [xxxx;xx;xx;xx;xx;+/-xx] 'x' - positive digits only\n");
				i = 0;
				memset(str_tmp, 0, sizeof(str_tmp));
			}
			else
			{
				AddRecord(temp_data, line_number-1, year, month, day, hour, minute, temp);	
				line_number++;
				i = 0;
				memset(str_tmp, 0, sizeof(str_tmp));
			}
		}
	} while (c_tmp != EOF);
	
	fclose (input_data);

	return line_number;
}

void Print_Table(struct temp_sensor* info, uint32_t struct_size)
{
	uint32_t i;
	for(i = 0; i< struct_size -1; i++)
	{
		printf("Date: " "%04" SCNd16"." "%02" SCNd8"." "%02" SCNd8"." "%02" SCNd8"." "%02" SCNd8" T = " "%+" SCNd8 "\n", 
			info[i].year, 
			info[i].month,
			info[i].day,
			info[i].hour, 
			info[i].minute, 
			info[i].temp);
	}
}

void DelRecord_by_Date(struct temp_sensor* info, uint32_t *struct_size, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute)
{
	uint32_t i, j = 0;
	struct temp_sensor tmp[*struct_size];
	    
	for(i = 0; i < *struct_size - 1; i++)
	{ 
		if ((info[i].year == year) 
		 && (info[i].month == month)
		 && (info[i].day == day)
		 && (info[i].hour == hour)
		 && (info[i].minute == minute))	continue;	
		else 
		{ 
			tmp[j] = info[i];
			j++;
		} 
	}

	if (j == *struct_size - 1)	{printf("Data not found in Table\n");}
	else
	{
		memset(info, 0, sizeof(info));
		for(i = 0; i < j; i++)
		{ 
			info[i] = tmp[i];
		}
		*struct_size = j + 1;
	} 
}

void DelRecord_by_Index(struct temp_sensor* info, uint32_t *struct_size, uint32_t del_index)
{
	uint32_t i, j = 0;
	struct temp_sensor tmp[*struct_size];
	    
	for(i = 0; i < *struct_size - 1; i++)
	{ 
		if ( i == del_index-1)	continue;	
		else 
		{ 
			tmp[j] = info[i];
			j++;
		} 
	}

	if (j == *struct_size - 1)	{printf("Index not found in Table\n");}
	else
	{
		memset(info, 0, sizeof(info));
		for(i = 0; i < j; i++)
		{ 
			info[i] = tmp[i];
		}
		*struct_size = j + 1;
	} 
}

void SortTable_by_Date(struct temp_sensor* info, uint32_t struct_size)
{
	#define cgangeIJ { tmp=info[i]; info[i]=info[j]; info[j]=tmp; }
	
	uint32_t i, j;
	struct temp_sensor tmp;
    
	for(i=0; i<struct_size-1; i++)
	for(j=i+1; j<struct_size-1; j++) if (info[i].year > info[j].year)		cgangeIJ 

	for(i=0; i<struct_size-1; i++)
	for(j=i+1; j<struct_size-1; j++) if ((info[i].year == info[j].year) 
										&& (info[i].month > info[j].month))		cgangeIJ
	
	for(i=0; i<struct_size-1; i++)
	for(j=i+1; j<struct_size-1; j++) if ((info[i].year == info[j].year) 
										&& (info[i].month == info[j].month)
										&& (info[i].day > info[j].day)) 		cgangeIJ
	
	for(i=0; i<struct_size-1; i++)
	for(j=i+1; j<struct_size-1; j++) if ((info[i].year == info[j].year) 
										&& (info[i].month == info[j].month)
										&& (info[i].day == info[j].day)
										&& (info[i].hour > info[j].hour)) 		cgangeIJ
	
	for(i=0; i<struct_size-1; i++)
	for(j=i+1; j<struct_size-1; j++) if ((info[i].year == info[j].year) 
										&& (info[i].month == info[j].month)
										&& (info[i].day == info[j].day)
										&& (info[i].hour == info[j].hour)
										&& (info[i].minute > info[j].minute)) 	cgangeIJ
}

void SortTable_by_Temp(struct temp_sensor* info, uint32_t struct_size)
{
	#define cgangeIJ { tmp=info[i]; info[i]=info[j]; info[j]=tmp; }
	
	uint32_t i, j;
	struct temp_sensor tmp;
    
	for(i=0; i<struct_size-1; i++)
	for(j=i+1; j<struct_size-1; j++) if (info[i].temp > info[j].temp)		cgangeIJ 
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
	
	if (n == 0) return temp_average = 100;

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

	if (n == 0) return temp_average = 100;
	
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