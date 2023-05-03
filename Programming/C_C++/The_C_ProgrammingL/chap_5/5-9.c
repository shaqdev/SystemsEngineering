
#include <stdio.h>

int calender_map[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
                {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

// 2023 05 10 - ??
int day_of_year(int year, int month, int day) {
    int leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    int DOY = 0;
    for (int i = 1; i < month; i++) {
        day += *(*(calender_map + leap) + i);
    }
    return day;
}

// 2023 and 10 - month and day?
void month_day(int year, int day, int *m, int *d) {
    int leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    int i;
    for (i = 1; day > *(*(calender_map+leap) + i); i++) {
        day -= *(*(calender_map+leap) + i);
    }
    *m = i;
    *d = day;
}

// 

int main(int argc, char *argv[]) {
    // day of the year
    int in_year = 2023, in_month = 5, in_day = 10;
    int DOY = day_of_year(in_year, in_month, in_day);
    printf("Day of the year: %d\n", DOY);

    // month and day
    int out_month, out_day;
    month_day(in_year, in_day, &out_month, &out_day);
    printf("Month and Day: %d & %d\n", out_month, out_day);
    
}