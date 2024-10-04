// Digital Clock
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void fill_time(char *, int);
void fill_date(char *);
void clear_screen();

int input_format();

int main()
{

    int format = input_format();
    char time[50], date[50];

    while (1)
    {
        fill_time(time, format);
        fill_date(date);
        clear_screen();

        printf("Current Time: %s\n", time);
        printf("Date: %s", date);
        sleep(1);
    }

    return 0;
}

void fill_time(char *buffer, int format)
{

    time_t row_time;
    struct tm *current_time;

    time(&row_time);
    current_time = localtime(&row_time);
    if (format == 1)
    {
        strftime(buffer, 50, "%H:%M:%S", current_time);
    }
    else
    {
        strftime(buffer, 50, "%I:%M:%S %p", current_time);
    }
}

int input_format()
{
    int format;
    printf("\nChoose the time format: \n");
    printf("1. 24 Hour format\n");
    printf("2. 12 Hour format (default)\n");
    printf("Make a choice (1/2): ");
    scanf("%d", &format);
    return format;
}

void fill_date(char *buffer)
{
    time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);
    strftime(buffer, 50, "%A %B %d %Y", current_time);
}

void clear_screen() {
    #ifdef _WIN32
      system("cls");
    #else
      system("clear");
    #endif
}