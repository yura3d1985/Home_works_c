#include <unistd.h>
#include "temp_api.h"

#define SIZE 1000000

int main(int argc, char *argv[])
{
	temp_stack *temp_data = NULL;

	int8_t month_aim, temp_min, temp_max;
	int32_t data_size;

	int month_statistics = -1;
	int year_statistics = -1;
	int count = 0;
		 
	float month_average;
	float year_average;
	float year_average_tmp = 0;

	char file_name[100];

// -------------------- обработка параметров командной строки -------------------- начало
	int result = 0;

	if (argc == 1)
	{
		printf("\n");
		printf("-------------------------------------------------------\n");
		printf("no parameters, for more information write parameter -h\n");
		printf("-------------------------------------------------------\n");
		printf("\n");
		return 0;
	}
	
	while ((result = getopt(argc,argv,"hf:m:")) != -1)
	{
		if (result == 'h')
		{
			printf("\n");
			printf("-------------------------------------------------------\n");
			printf("'-h' for help\n");
			printf("'-f file name' file with input temperature data\n");
			printf("'-m xx' statistic for xx mounth\n");
			printf("-------------------------------------------------------\n");
			printf("\n");
			if (argc == 2) return 0;
			else continue;
			
		}
		if (result == 'f')
		{
			sscanf(optarg,"%s", &file_name);
			year_statistics = 1;
			continue;
		}
		if (result == 'm')
		{
			if (year_statistics == -1)
			{
				printf("\n");
				printf("-------------------------------------------------------\n");
				printf("'-f file name' file with temperature data not specify\n");
				printf("-------------------------------------------------------\n");
				printf("\n");
				return 0;
			}
			else
			{
				sscanf(optarg, "%" SCNu8 , &month_aim);
				month_statistics = 1;
				continue;
			}
			
		}
		if (result == '?')
		{
			printf("\n");
			printf("-------------------------------------------------------\n");
			printf("input parameters error found! \n");
			printf("-------------------------------------------------------\n");
			printf("\n");
			return 0;
		}
	};
// -------------------- обработка параметров командной строки -------------------- конец

printf("-------------------------------------------------------\n");
data_size = Create_Table_from_File(&temp_data, file_name);

printf("number of elements in table = %d\n", data_size-1);

uint16_t year_aim = temp_data->data.year; // если по ТЗ в файле данные только за один год

if (month_statistics == -1)
{
	printf("-------------------------------------------------------\n");
	printf("#\tYears\tMonth\tAverage T\tMin T\tMax T\n");
	for (month_aim = 1; month_aim <= 12; month_aim = month_aim + 1)
	{
		month_average = Average_Month_temp(temp_data, year_aim, month_aim);
		if (month_average == 100) 
		{
			printf("%" SCNd8"\t\t", month_aim);
			printf("No DATA for this month\n");
			continue;
		}
		else 
		{
			year_average_tmp = year_average_tmp + month_average;
			count++;
		}
		temp_min = Min_Month_temp(temp_data, year_aim, month_aim);
		temp_max = Max_Month_temp(temp_data, year_aim, month_aim);
		printf("%" SCNd8"\t", month_aim);
		printf("%" SCNd16"\t" "%" SCNd8"\t" "%+2.2f\t\t" "%+" SCNd8"\t" "%+" SCNd8 "\n", year_aim, month_aim, month_average, temp_min, temp_max);
	}	
	printf("-------------------------------------------------------\n");
	year_average = year_average_tmp / count;
	temp_min = Min_Year_temp(temp_data, year_aim);
	temp_max = Max_Year_temp(temp_data, year_aim);
	printf("Year statistic:   Avarage T = %+2.2f   " "Min T = %+" SCNd8"   " "Max T = %+" SCNd8 "\n",year_average, temp_min, temp_max);
	printf("-------------------------------------------------------\n");
}
else
{
	month_average = Average_Month_temp(temp_data, year_aim, month_aim);
	temp_min = Min_Month_temp(temp_data, year_aim, month_aim);
	temp_max = Max_Month_temp(temp_data, year_aim, month_aim);

	if (month_average == 100) 
	{
		printf("-------------------------------------------------------\n");
		printf("No DATA for this month\n");
		printf("-------------------------------------------------------\n");
		printf("\n");
		while(temp_data) temp_data = pop(temp_data); // удаление стека
		return 0;
	}
	printf("-------------------------------------------------------\n");
	printf("#\tYears\tMonth\tAverage T\tMin T\tMax T\n");
	printf("1\t");
	printf("%" SCNd16"\t" "%" SCNd8"\t" "%+2.2f\t\t" "%+" SCNd8"\t" "%+" SCNd8 "\n", year_aim, month_aim, month_average, temp_min, temp_max);
	printf("-------------------------------------------------------\n");
}
	printf("\n");

	while(temp_data) temp_data = pop(temp_data); // удаление стека

	return 0;
}