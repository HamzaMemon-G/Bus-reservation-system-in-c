#include <stdio.h>
#include <string.h>
#include <conio.h>

struct Bus
{
    char number[10];
    char route[20];
    char dep_time[10];
    char arr_time[10];
    int seats[30];
};

struct Bus buses[10];

void display_buses()
{
    printf("Bus Number\tRoute\t\tDeparture Time\t Arrival Time\t\t\t\t          Seats Available\n\n");
    for (int i = 0; i < 10; i++)
    {
        printf("   %s\t    %s\t    %s\t    %s\t", buses[i].number, buses[i].route, buses[i].dep_time, buses[i].arr_time);
        for (int j = 0; j < 30; j++)
        {
            if (buses[i].seats[j] == 0)
            {
                printf("%d ", j + 1);
            }
        }
        printf("\n");
    }
}

void check_seat_availability(char bus_num[])
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(buses[i].number, bus_num) == 0)
        {
            printf("Available seats on bus %s ", bus_num);
            for (int j = 0; j < 30; j++)
            {
                if (buses[i].seats[j] == 0)
                {
                    printf("%d ", j + 1);
                }
            }
            printf("\n");
            return;
        }
    }
    printf("Bus not found!\n");
}

void reserve_seat(char bus_num[], int seat_num)
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(buses[i].number, bus_num) == 0)
        {
            if (buses[i].seats[seat_num - 1] == 0)
            {
                buses[i].seats[seat_num - 1] = 1;
                printf("Seat %d reserved on bus %s", seat_num, bus_num);
            }
            else
            {
                printf("Seat %d is already reserved!\n", seat_num);
            }
            return;
        }
    }
    printf("Bus not found!\n");
}
int main()
{
    login();

    // Initialize buses
    strcpy(buses[0].number, "B001");
    strcpy(buses[0].route, "Panvel to Mumbra");
    strcpy(buses[0].dep_time, "07:30");
    strcpy(buses[0].arr_time, "08:30");
    memset(buses[0].seats, 0, sizeof(buses[0].seats));

    strcpy(buses[1].number, "B002");
    strcpy(buses[1].route, "Mumbra to Panvel");
    strcpy(buses[1].dep_time, "07:30");
    strcpy(buses[1].arr_time, "08:30");
    memset(buses[1].seats, 0, sizeof(buses[1].seats));

    strcpy(buses[2].number, "B003");
    strcpy(buses[2].route, "Panvel to Kalyan");
    strcpy(buses[2].dep_time, "09:00");
    strcpy(buses[2].arr_time, "12:00");
    memset(buses[2].seats, 0, sizeof(buses[2].seats));

    strcpy(buses[3].number, "B004");
    strcpy(buses[3].route, "Thane to Panvel");
    strcpy(buses[3].dep_time, "09:00");
    strcpy(buses[3].arr_time, "12:00");
    memset(buses[3].seats, 0, sizeof(buses[3].seats));

    strcpy(buses[4].number, "B005");
    strcpy(buses[4].route, "Thane to Rabodi");
    strcpy(buses[4].dep_time, "09:00");
    strcpy(buses[4].arr_time, "12:00");
    memset(buses[4].seats, 0, sizeof(buses[4].seats));

    strcpy(buses[5].number, "B006");
    strcpy(buses[5].route, "Thane to Borivali");
    strcpy(buses[5].dep_time, "09:00");
    strcpy(buses[5].arr_time, "12:00");
    memset(buses[5].seats, 0, sizeof(buses[5].seats));

    strcpy(buses[6].number, "B007");
    strcpy(buses[6].route, "Andheri to Kalwa");
    strcpy(buses[6].dep_time, "09:00");
    strcpy(buses[6].arr_time, "12:00");
    memset(buses[6].seats, 0, sizeof(buses[6].seats));

    strcpy(buses[7].number, "B008");
    strcpy(buses[7].route, "Hiranandani to RBI");
    strcpy(buses[7].dep_time, "09:00");
    strcpy(buses[7].arr_time, "12:00");
    memset(buses[7].seats, 0, sizeof(buses[7].seats));

    strcpy(buses[8].number, "B009");
    strcpy(buses[8].route, "Thane to Mira Road");
    strcpy(buses[8].dep_time, "09:00");
    strcpy(buses[8].arr_time, "12:00");
    memset(buses[8].seats, 0, sizeof(buses[8].seats));

    strcpy(buses[9].number, "B010");
    strcpy(buses[9].route, "Thane to Majiwada");
    strcpy(buses[9].dep_time, "09:00");
    strcpy(buses[9].arr_time, "12:00");
    memset(buses[9].seats, 0, sizeof(buses[9].seats));

    // Display menu
    int choice;
    char bus_num[10];
    int seat_num;
    do
    {
        printf("\n\t\t\tBUS RESERVATION SYSTEM\t\t\t\n\n");
        printf("\tMENU\n");
        printf("\t1. Display all buses\n");
        printf("\t2. Check seat availability\n");
        printf("\t3. Reserve a seat\n");
        printf("\t4. Quit\n");
        printf("\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display_buses();
            break;
        case 2:
            printf("Enter bus number: ");
            scanf("%s", bus_num);
            check_seat_availability(bus_num);
            break;
        case 3:
            printf("Enter bus number: ");
            scanf("%s", bus_num);
            printf("Enter seat number: ");
            scanf("%d", &seat_num);
            reserve_seat(bus_num, seat_num);
            break;
        case 4:
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
void login()
{
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "user";
    char pass[10] = "pass";
    do
    {
        system("cls");

        printf("\n  \t\t\t  LOGIN FORM  \t\t\t  \n");
        printf(" \n                       ENTER USERNAME:-");
        scanf("%s", &uname);
        printf(" \n                       ENTER PASSWORD:-");
        while (i < 10)
        {
            pword[i] = getch();
            c = pword[i];
            if (c == 13)
                break;
            else
                printf("*");
            i++;
        }
        pword[i] = '\0';
        i = 0;
        if (strcmp(uname, "Hamza") == 0 && strcmp(pword, "Pass") == 0)
        {
            printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\t\tPress any key to continue...");
            getch();
            break;
        }
        else
        {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
            a++;

            getch();
        }
    } while (a <= 2);
    if (a > 2)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!");

        getch();
    }
    system("cls");
}