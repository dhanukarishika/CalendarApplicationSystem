#include <stdio.h>

// Function to determine if a year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;  // Leap year
    }
    return 0;  // Not a leap year
}

// Function to determine the number of days in a given month
int daysInMonth(int month, int year) {
    switch (month) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;  // Adjust for leap year
        default:
            return 31;
    }
}

// Function to calculate the day of the week for the first day of the given month
int calculateFirstDay(int month, int year) {
    int dayOfWeek = 1;  // Assume January 1, 1900, was a Monday
    for (int y = 1900; y < year; ++y) {
        for (int m = 1; m <= 12; ++m) {
            dayOfWeek = (dayOfWeek + daysInMonth(m, y)) % 7;
        }
    }

    // Adjust the day of the week for the first day of the given month
    for (int m = 1; m < month; ++m) {
        dayOfWeek = (dayOfWeek + daysInMonth(m, year)) % 7;
    }

    return dayOfWeek;
}

// Function to display the calendar for a given month and year
void displayCalendar(int month, int year) {
    // Display the header
    printf("\n-----------------------------\n");
    printf("       Calendar %d-%02d\n", year, month);
    printf("-----------------------------\n");
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");

    // Calculate the day of the week for the first day of the month
    int dayOfWeek = calculateFirstDay(month, year);

    // Display the calendar
    for (int i = 0; i < dayOfWeek; ++i) {
        printf("    ");  // Adjust spacing for alignment
    }

    int daysInThisMonth = daysInMonth(month, year);
    for (int day = 1; day <= daysInThisMonth; ++day) {
        printf("%4d", day);
        if ((dayOfWeek + day) % 7 == 0 || day == daysInThisMonth) {
            printf("\n");
        }
    }
}

int main() {
    int month, year;
    // Get user input for month and year
    printf("Enter the month (1-12): ");
    scanf("%d", &month);
    printf("Enter the year: ");
    scanf("%d", &year);
    // Validate input
    if (month < 1 || month > 12 || year < 1900) {
        printf("Invalid input. Please enter a valid month (1-12) and year (>= 1900).\n");
        return 1;  // Exit with an error code
    }
    // Display the calendar
    displayCalendar(month, year);
    return 0;
}
