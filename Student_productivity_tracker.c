#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "productivity.txt"
#define DAYS 7

char *dayNames[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

// Function to log daily study hours
void logHours() {
    FILE *fp;
    char day[20];
    float hours;
    int choice;

    fp = fopen(FILENAME, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n--- Log Study Hours ---\n");
    printf("Select Day:\n");
    for (int i = 0; i < DAYS; i++) {
        printf("%d. %s\n", i + 1, dayNames[i]);
    }
    printf("Enter choice (1-7): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 7) {
        printf("Invalid choice!\n");
        fclose(fp);
        return;
    }

    printf("Enter study hours for %s: ", dayNames[choice - 1]);
    scanf("%f", &hours);

    fprintf(fp, "%s:%.2f\n", dayNames[choice - 1], hours);
    printf("Hours logged successfully for %s!\n", dayNames[choice - 1]);

    fclose(fp);
}

// Function to generate weekly report
void weeklyReport() {
    FILE *fp;
    char line[100];
    char day[20];
    float hours;
    float total = 0, average;
    int count = 0;
    float maxHours = 0, minHours = 999;
    char bestDay[20], worstDay[20];

    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("No data found. Please log some study hours first.\n");
        return;
    }

    printf("\n=============================\n");
    printf("     WEEKLY STUDY REPORT     \n");
    printf("=============================\n");
    printf("%-15s %s\n", "Day", "Hours Studied");
    printf("-----------------------------\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        // Remove newline
        line[strcspn(line, "\n")] = 0;

        // Parse day and hours
        char *token = strtok(line, ":");
        if (token == NULL) continue;
        strcpy(day, token);

        token = strtok(NULL, ":");
        if (token == NULL) continue;
        hours = atof(token);

        printf("%-15s %.2f hrs\n", day, hours);

        total += hours;
        count++;

        if (hours > maxHours) {
            maxHours = hours;
            strcpy(bestDay, day);
        }
        if (hours < minHours) {
            minHours = hours;
            strcpy(worstDay, day);
        }
    }

    fclose(fp);

    if (count == 0) {
        printf("No records found!\n");
        return;
    }

    average = total / count;

    printf("-----------------------------\n");
    printf("Total Study Hours : %.2f hrs\n", total);
    printf("Average Per Day   : %.2f hrs\n", average);
    printf("Most Productive   : %s (%.2f hrs)\n", bestDay, maxHours);
    printf("Least Productive  : %s (%.2f hrs)\n", worstDay, minHours);
    printf("=============================\n");

    // Performance feedback
    printf("\n--- Feedback ---\n");
    if (average >= 6) {
        printf("Outstanding! You are studying excellently this week!\n");
    } else if (average >= 4) {
        printf("Good job! You are maintaining a solid study routine.\n");
    } else if (average >= 2) {
        printf("Average performance. Try to increase your daily study hours.\n");
    } else {
        printf("You need to study more. Set a daily goal and stick to it!\n");
    }
}

// Function to view all logged data
void viewLogs() {
    FILE *fp;
    char line[100];

    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("No logs found. Start by logging your study hours.\n");
        return;
    }

    printf("\n--- All Study Logs ---\n");
    printf("%-15s %s\n", "Day", "Hours");
    printf("----------------------\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        char *token = strtok(line, ":");
        char day[20];
        float hours;

        if (token == NULL) continue;
        strcpy(day, token);

        token = strtok(NULL, ":");
        if (token == NULL) continue;
        hours = atof(token);

        printf("%-15s %.2f hrs\n", day, hours);
    }

    fclose(fp);
}

// Function to clear all logs
void clearLogs() {
    char confirm;
    printf("Are you sure you want to clear all logs? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        FILE *fp = fopen(FILENAME, "w");
        if (fp != NULL) {
            fclose(fp);
            printf("All logs cleared successfully!\n");
        }
    } else {
        printf("Action cancelled.\n");
    }
}

// Main menu
int main() {
    int choice;

    printf("\n=============================\n");
    printf("  Student Productivity Tracker\n");
    printf("=============================\n");

    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Log Daily Study Hours\n");
        printf("2. View Weekly Report\n");
        printf("3. View All Logs\n");
        printf("4. Clear All Logs\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                logHours();
                break;
            case 2:
                weeklyReport();
                break;
            case 3:
                viewLogs();
                break;
            case 4:
                clearLogs();
                break;
            case 5:
                printf("\nThank you for using Student Productivity Tracker. Keep studying!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
