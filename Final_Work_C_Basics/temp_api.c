#include "temp_api.h"

temp_stack* push(temp_stack *p, struct temp_sensor data)
{
	temp_stack *p_tmp;
	p_tmp=malloc(sizeof(temp_stack));
	p_tmp->data = data;
	p_tmp->next = p;
	return p_tmp;
}

temp_stack* pop(temp_stack *p)
{
	if (p == NULL) return p;
	
	temp_stack* ptr_next = p->next;
    free(p);
 
    return ptr_next;
}

uint32_t Create_Table_from_File(temp_stack **p, char file_name[])
{
	struct temp_sensor temp_data;
	
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
				temp_data.year   = year;
				temp_data.month  = month;
				temp_data.day    = day;
				temp_data.hour   = hour;
				temp_data.minute = minute;
				temp_data.temp   = temp;
				
				*p = push(*p, temp_data); 

				line_number++;
				i = 0;
				memset(str_tmp, 0, sizeof(str_tmp));
			}
		}
	} while (c_tmp != EOF);
	
	fclose (input_data);

	return line_number;
}

void Print_Table(const temp_stack *top)
{
	const temp_stack* current = top;
	
	while (current != NULL)
	{
		printf("Date: " "%04" SCNd16"." "%02" SCNd8"." "%02" SCNd8"." "%02" SCNd8"." "%02" SCNd8" T = " "%+" SCNd8 "\n", 
			current->data.year, 
			current->data.month,
			current->data.day,
			current->data.hour, 
			current->data.minute, 
			current->data.temp);
			
			current = current->next;
	}
}

float Average_Year_temp(const temp_stack *top, uint16_t year)
{
	const temp_stack* current = top;
	
	uint32_t i, n = 0;
	float temp_average, temp_summa = 0;

	while (current != NULL)
	{
		if(current->data.year == year)
		{
			temp_summa = temp_summa + current->data.temp;
			n++;
		}
		current = current->next;
	}
	
	if (n == 0) return temp_average = 100;

	if (temp_summa == 0) return temp_average = 0;
	else return temp_average = temp_summa / (n);
}

int8_t Min_Year_temp(const temp_stack *top, uint16_t year)
{
	const temp_stack* current = top;
	
	int8_t min_temp;
	uint32_t i; 
		
	while (current != NULL)
	{
		if(current->data.year == year)
		{
			min_temp = current->data.temp;
			break;
		}
		current = current->next;
	}
	
	while (current != NULL)
	{
		if(current->data.year == year)
		{
			if(current->data.temp < min_temp)
			{
				min_temp = current->data.temp;
			}
		}
		current = current->next;
	}
	
	return min_temp;
}

int8_t Max_Year_temp(const temp_stack *top, uint16_t year)
{
	const temp_stack* current = top;
	
	int8_t max_temp;
	uint32_t i; 
		
	while (current != NULL)
	{
		if(current->data.year == year)
		{
			max_temp = current->data.temp;
			break;
		}
		current = current->next;
	}
	
	while (current != NULL)
	{
		if(current->data.year == year)
		{
			if(current->data.temp > max_temp)
			{
				max_temp = current->data.temp;
			}
		}
		current = current->next;
	}
	
	return max_temp;
}

float Average_Month_temp(const temp_stack *top, uint16_t year, uint8_t month)
{
	const temp_stack* current = top;
	
	uint32_t i, n = 0;
	float temp_average, temp_summa = 0;

	while (current != NULL)
	{
		if((current->data.year == year) && (current->data.month == month))
		{
			temp_summa = temp_summa + current->data.temp;
			n++;
		}
		current = current->next;
	}

	if (n == 0) return temp_average = 100;
	
	if (temp_summa == 0) return temp_average = 0;
	else return temp_average = temp_summa / (n);
}

int8_t Min_Month_temp(const temp_stack *top, uint16_t year, uint8_t month)
{
	const temp_stack* current = top;
	
	int8_t min_temp;
	uint32_t i; 
		
	while (current != NULL)
	{
		if((current->data.year == year) && (current->data.month == month))
		{
			min_temp = current->data.temp;
			break;
		}
		current = current->next;
	}
	
	while (current != NULL)
	{
		if((current->data.year == year) && (current->data.month == month))
		{
			if(current->data.temp < min_temp)
			{
				min_temp = current->data.temp;
			}
		}
		current = current->next;
	}
	
	return min_temp;
}

int8_t Max_Month_temp(const temp_stack *top, uint16_t year, uint8_t month)
{
	const temp_stack* current = top;

	int8_t max_temp;
	uint32_t i; 
		
	while (current != NULL)
	{
		if((current->data.year == year) && (current->data.month == month))
		{
			max_temp = current->data.temp;
			break;
		}
		current = current->next;
	}
	
	while (current != NULL)
	{
		if((current->data.year == year) && (current->data.month == month))
		{
			if(current->data.temp > max_temp)
			{
				max_temp = current->data.temp;
			}
		}
		current = current->next;
	}
	
	return max_temp;
}