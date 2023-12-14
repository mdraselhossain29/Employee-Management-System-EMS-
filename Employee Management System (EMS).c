#define _WIN32_WINNT 0x0500
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#define Employee struct emp

// Md. Rasel Hossain
/*void add(FILE *fp);             // to add to list
FILE *del(FILE *fp);            // to delete from list
void modify(FILE *fp);          // to modify a record
void displayList(FILE *fp);     // display whole list
void searchRecord(FILE *fp);    // find a particular record
void printChar(char ch, int n); // printing a character ch n times
void printHead();
*/
// Md. Rasel Hossain
int MaximizeOutputWindow(void);
int SetConsoleSize(void);
void about();
void logo();
void welcome();
void printChar(char ch, int n);
void printHead();
void add(FILE *fp);
FILE *del(FILE *fp);
void modify(FILE *fp);
void displayList(FILE *fp);
void searchRecord(FILE *fp);
void maleemp(FILE *fp);
void femaleemp(FILE *fp);
void frmdhaka(FILE *fp);
void frmors(FILE *fp);
void displaybasic(FILE *fp);
void basiccontact(FILE *fp);
void mainbr(FILE *fp);
void otherbr(FILE *fp);

struct emp
{
    int id;
    char name[100];
    char desgn[10];
    float sal;
    char jdate[8];
    char gender[10];
    char branch[50];
    char psaddr[200];
    char prtaddr[200];
    char phone[15];
    char mail[20];
};
// Md. Rasel Hossain

int main()
{
    FILE *fp;
    Employee e;
    int option;
    char another;

    MaximizeOutputWindow();
    SetConsoleSize();
    system("COLOR 02"); // color

    if ((fp = fopen("employeeInfo.txt", "rb+")) == NULL) // Md. Rasel Hossain
    {
        if ((fp = fopen("employeeInfo.txt", "wb+")) == NULL)
        {
            printf("can't open file");
            return 0;
        }
    }
    char username[20], password[20]; // Md. Rasel Hossain
    printHead();
    welcome();
login:
    system("cls");
    system("COLOR 5E"); // color
    printHead();
    printf("\n\n\n");
    printf("\n\t\t\t\t\t\t\t\t            Welcome to\n");
    printf("\n\t\t\t\t\t\t\t      Employee Managment System (EMS) Portal\n");
    printf("\n\t\t\t\t\t\t\t      Please, Enter Your Login Infomation...");
    printf("\n\t\t\t\t\t\t\t                    ----------");
    printf("\n\n");
    printf("\n\n\t\t\t\t\t\t\t\t           Username: ");
    scanf("%s", username);
    printf("\n\t\t\t\t\t\t\t\t           Password: ");
    int i;
    i = 0;
    do
    {
        password[i] = getch();
        if (password[i] == 13) // Md. Rasel Hossain
        {
            break;
        }
        else if (password[i] == 8 && i > 0)
        {
            printf("%c%c%c", 8, 32, 8);
            i--;
        }
        else
        {
            printf("*");
            i++;
        }
    } while (password[i] != 13);
    password[i] = '\0';

    if (((strcasecmp(username, "admin")) == 0) && ((strcasecmp(password, "pass") == 0)))
    {
        while (1)
        {
        menu:
            system("cls");
            system("COLOR 3E"); // color
            printHead();
            printf("\n\n");
            printf("\n\t\t\t\t\t\t\t\t\t     Main Menu\n");
            printf("\t\t\t\t\t\t\t\t\t  ---------------\n");
            printf("\n"); // Md. Rasel Hossain

            printf("\n\t\t\t\t\t\t\t\t01. Add Employee");
            printf("\n\t\t\t\t\t\t\t\t02. Delete Employee");
            printf("\n\t\t\t\t\t\t\t\t03. Modify Employee");
            printf("\n\t\t\t\t\t\t\t\t04. Display Employee List");
            printf("\n\t\t\t\t\t\t\t\t05. Search Record");
            printf("\n\t\t\t\t\t\t\t\t06. Display Basic Info");
            printf("\n\t\t\t\t\t\t\t\t07. Display Basic Contact Info");
            printf("\n\t\t\t\t\t\t\t\t08. List of Male Employee");
            printf("\n\t\t\t\t\t\t\t\t09. List of Female Employee");
            printf("\n\t\t\t\t\t\t\t\t10. List of Employee from Dhaka");
            printf("\n\t\t\t\t\t\t\t\t11. List of Employee from Others District");
            printf("\n\t\t\t\t\t\t\t\t12. List of Employee of Main Branch");
            printf("\n\t\t\t\t\t\t\t\t13. List of Employee of Others Branch");
            printf("\n\t\t\t\t\t\t\t\t14. About");
            printf("\n\t\t\t\t\t\t\t\t00. EXIT");

            printf("\n\n\n\t\t\t\t\t\t\t\t\tEnter Your Option :--> ");
            scanf("%d", &option);
            // Md. Rasel Hossain
            switch (option)
            {
            case 0:
                exit(0);
                break;
            case 1:
                add(fp);
                break;
            case 2:
                fp = del(fp);
                break;
            case 3:
                modify(fp);
                break;
            case 4:
                displayList(fp);
                break;
            case 5:
                searchRecord(fp);
                break;
            case 6:
                displaybasic(fp);
                break; // Md. Rasel Hossain
            case 7:
                basiccontact(fp);
                break;
            case 8:
                maleemp(fp);
                break;
            case 9:
                femaleemp(fp);
                break;
            case 10:
                frmdhaka(fp);
                break;
            case 11:
                frmors(fp);
                break;
            case 12:
                mainbr(fp);
                break;
            case 13:
                otherbr(fp);
                break;
            case 14:
                about();
                break;
            default:
                printf("\n\t\tYou Pressed wrong key");
                printf("\n\t\tTry Again.............");
                getch();
                goto menu;

            } // Md. Rasel Hossain
        }
    }
    else
    {
        printf("\n\n\n\n\t\t\t\t\t\t\t\t            Login Failed!");
        printf("\n\t\t\t\t\t\t\t\t        Please, Try Again...");
        getch();
        goto login;
    }

    return 1;
}

//====Welcome Screen=====
void welcome()
{
    logo();
    // printf("\n\n\n\n\n\t\t[ [ [ WELCOME TO OUR EMPLOYEE MANAGEMENT SYSTEM ] ] ]\n\n\n\n\n\n\n\t");
    printf("\n\n\t\t\t\t\t\t\t\tEnter any keys to continue...");
    getch();
}

//----printing character ch at n times ------

void printChar(char ch, int n)
{
    while (n--) // Md. Rasel Hossain
    {
        putchar(ch);
    }
}

//-----Printing Head Line of the program -----

void printHead()
{
    system("cls");
    printf("\n\n\n");
    printf("\n\t\t\t\t\t\t==================================================================");
    printf("\n\t\t\t\t\t\t==================================================================");
    printf("\n\t\t\t\t\t\t================ EMPLOYEE MANAGEMENT SYSTEM (EMS) ================");
    printf("\n\t\t\t\t\t\t==================================================================");
    printf("\n\t\t\t\t\t\t==================================================================");

}
// Md. Rasel Hossain

// ==========ADDING NEW RECORD==========================

void add(FILE *fp)
{
    char another = 'y';
    Employee e;

    fseek(fp, 0, SEEK_END);
    while (another == 'y' || another == 'Y')
    {
        system("CLS");
        printHead();

        printf("\n\n\t\t\t\t\t\t\t\t\t  Add Employee\n");
        printf("\t\t\t\t\t\t\t\t        ----------------\n");
        printf("\n\t\t\t\t\t\t\t\tEnter ID Number: ");
        scanf("%d", &e.id);
        // Md. Rasel Hossain
        printf("\n\t\t\t\t\t\t\t\tEnter Full Name of Employee: ");
        fflush(stdin);
        fgets(e.name, 100, stdin); // fgets takes an extra \n character as input
        e.name[strlen(e.name) - 1] = '\0';

        printf("\n\t\t\t\t\t\t\t\tEnter Designation: ");
        fflush(stdin);
        fgets(e.desgn, 30, stdin); // fgets takes an extra \n character as input
        e.desgn[strlen(e.desgn) - 1] = '\0';

        printf("\n\t\t\t\t\t\t\t\tEnter Gender: ");
        fflush(stdin);
        fgets(e.gender, 10, stdin); // fgets takes an extra \n character as input
        e.gender[strlen(e.gender) - 1] = '\0';

        printf("\n\t\t\t\t\t\t\t\tEnter Branch: ");
        fflush(stdin);
        fgets(e.branch, 50, stdin);
        e.branch[strlen(e.branch) - 1] = '\0';

        printf("\n\t\t\t\t\t\t\t\tEnter Salary: ");
        scanf("%f", &e.sal);

        printf("\n\t\t\t\t\t\t\t\tEnter Present Address: ");
        fflush(stdin);
        fgets(e.psaddr, 200, stdin);
        e.psaddr[strlen(e.psaddr) - 1] = '\0';

        printf("\n\t\t\t\t\t\t\t\tEnter Permanant Address: ");
        fflush(stdin); // Md. Rasel Hossain
        fgets(e.prtaddr, 200, stdin);
        e.prtaddr[strlen(e.prtaddr) - 1] = '\0';

        printf("\n\t\t\t\t\t\t\t\tEnter Phone: ");
        fflush(stdin);
        fgets(e.phone, 50, stdin);
        e.phone[strlen(e.phone) - 1] = '\0';

        printf("\n\t\t\t\t\t\t\t\tEnter E-mail Address: ");
        fflush(stdin);
        fgets(e.mail, 30, stdin);
        e.mail[strlen(e.mail) - 1] = '\0';

        fwrite(&e, sizeof(e), 1, fp);

        printf("\n\n\t\t\t\t\t\t\t\tWant to enter another employee info (Y/N) ");
        fflush(stdin);
        another = getchar();
    } // Md. Rasel Hossain
}

//===================DELETING A RECORD FROM LIST ============
FILE *del(FILE *fp)
{
    printHead();
    printf("\n\n\t\t\t\t\t\t\t\t\t  Delete Employee\n");
    printf("\t\t\t\t\t\t\t\t        ------------------\n");
    Employee e;
    int flag = 0, tempid, siz = sizeof(e);
    FILE *ft;

    if ((ft = fopen("temp.txt", "wb+")) == NULL) // Md. Rasel Hossain
    {
        printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
        system("pause");
        return fp;
    }

    printf("\n\n\t\t\t\t\t\t\t Enter ID number of Employee to Delete the Record");
    printf("\n\n\t\t\t\t\t\t\t ID No. : ");
    scanf("%d", &tempid);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    { // Md. Rasel Hossain
        if (e.id == tempid)
        {
            flag = 1;
            printf("\n\tRecord Deleted for");
            printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t", e.name, e.branch, e.id);
            continue;
        }

        fwrite(&e, siz, 1, ft);
    }

    fclose(fp);
    fclose(ft);

    remove("employeeInfo.txt");
    rename("temp.txt", "employeeInfo.txt");

    if ((fp = fopen("employeeInfo.txt", "rb+")) == NULL) // Md. Rasel Hossain
    {
        printf("ERROR");
        return NULL;
    }

    if (flag == 0)
        printf("\n\n\n\n\t\t\t\t\t\t\t\t     ERROR RECORD NOT FOUND!\n\t");

    printf("\n\n\t");
    printf("\n\n\t\t\t\t\t\t\t\t   Enter any keys to continue...");
    getch();
    return fp;
}

// Md. Rasel Hossain
//===========MODIFY A RECORD ===========================

void modify(FILE *fp)
{
    printHead();
    printf("\n\t\t\t\t\t\t\t\t\tModify Employee\n");
    printf("\t\t\t\t\t\t\t\t      --------------------\n");
    Employee e;
    int i, flag = 0, tempid, siz = sizeof(e);
    float sal;

    printf("\n\n\t\t\t\t\t\t\tEnter ID Number of Employee to Modify the Record : ");
    scanf("%d", &tempid);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        if (e.id == tempid)
        {
            flag = 1; // Md. Rasel Hossain
            break;
        }
    }

    if (flag == 1)
    {
        fseek(fp, -siz, SEEK_CUR);
        printf("\n\t\t\t\t\t\t\t                    Record Found!\n");
        printf("\n\t\t\t\t\t\t\t            Enter New Data for the Record\n");
        printf("\t\t\t\t\t\t\t\t -----------------------------------\n");

        printf("\n\t\t\t\t\t\t\tEnter ID number: ");
        scanf("%d", &e.id);

        printf("\n\t\t\t\t\t\t\tEnter Full Name of Employee: ");
        fflush(stdin);
        fgets(e.name, 100, stdin);         // fgets takes an extra \n character as input
        e.name[strlen(e.name) - 1] = '\0'; // Md. Rasel Hossain

        printf("\n\t\t\t\t\t\t\tEnter Designation: ");
        fflush(stdin);
        fgets(e.desgn, 30, stdin); // fgets takes an extra \n character as input
        e.desgn[strlen(e.desgn) - 1] = '\0';

        printf("\n\t\t\t\t\t\t\tEnter Gender: ");
        fflush(stdin);
        fgets(e.gender, 10, stdin); // fgets takes an extra \n character as input
        e.gender[strlen(e.gender) - 1] = '\0';

        printf("\n\t\t\t\t\t\t\tEnter Branch: ");
        fflush(stdin);
        fgets(e.branch, 50, stdin); // Md. Rasel Hossain
        e.branch[strlen(e.branch) - 1] = '\0';

        printf("\n\t\t\t\t\t\t\tEnter Salary: ");
        scanf("%f", &e.sal);

        printf("\n\t\t\t\t\t\t\tEnter Present Address: ");
        fflush(stdin);
        fgets(e.psaddr, 200, stdin);
        e.psaddr[strlen(e.psaddr) - 1] = '\0';

        printf("\n\t\t\t\t\t\t\tEnter Permanant Address: ");
        fflush(stdin);
        fgets(e.prtaddr, 200, stdin); // Md. Rasel Hossain
        e.prtaddr[strlen(e.prtaddr) - 1] = '\0';

        printf("\n\t\t\t\t\t\t\tEnter Phone: ");
        fflush(stdin);
        fgets(e.phone, 50, stdin);
        e.phone[strlen(e.phone) - 1] = '\0';

        printf("\n\t\t\t\t\t\t\tEnter E-mail: ");
        fflush(stdin);
        fgets(e.mail, 30, stdin);
        e.mail[strlen(e.mail) - 1] = '\0';

        fwrite(&e, sizeof(e), 1, fp); // Md. Rasel Hossain
    }

    else
        printf("\n\n\t\t\t\t\t\t\t\t      ERROR, RECORD NOT FOUND!");

    printf("\n\n\t");
    printf("\n\n\t\t\t\t\t\t\t\t   Enter any keys to continue...");
    getch();
}

//====================DISPLAY THE LIST =================
void displayList(FILE *fp)
{
    printHead();
    printf("\n\t\t\t\t\t\t\t\t\t List of Employees\n");
    printf("\t\t\t\t\t\t\t\t      -----------------------\n");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\tID : %d\n", e.id); // Md. Rasel Hossain
        printf("\n\n\t\t\t\t\t\t\t\t\tNAME : %s", e.name);
        printf("\n\n\t\t\t\t\t\t\t\t\tDESIGNATION : %s", e.desgn);
        printf("\n\n\t\t\t\t\t\t\t\t\tGENDER : %s", e.gender);
        printf("\n\n\t\t\t\t\t\t\t\t\tBRANCH : %s", e.branch);
        printf("\n\n\t\t\t\t\t\t\t\t\tSALARY : %.2f", e.sal);
        printf("\n\n\t\t\t\t\t\t\t\t\tPRESENT ADDRESS : %s", e.psaddr);
        printf("\n\n\t\t\t\t\t\t\t\t\tPERMANANT ADDRESS : %s", e.prtaddr);
        printf("\n\n\t\t\t\t\t\t\t\t\tPHONE : %s", e.phone);
        printf("\n\n\t\t\t\t\t\t\t\t\tE-MAIL : %s\n\t", e.mail);
        printf("\n\n\t\t\t\t\t\t\t     ===============================================");
    }
    printf("\n\n\n\t");
    printf("\n\n\t\t\t\t\t\t\t     Enter any keys to continue...");
    getch();
}

//================SEARCH EMPLOYEE==
void searchRecord(FILE *fp) // Md. Rasel Hossain
{
    int tempid, flag, siz, i;
    Employee e;
    char another = 'y';

    siz = sizeof(e);

    while (another == 'y' || another == 'Y')
    {
        system("CLS");
        printHead();
        printf("\n\t\t\t\t\t\t\t\t\tSearch Employee\n");
        printf("\t\t\t\t\t\t\t\t     ---------------------\n");
        printf("\n\n\t\t\t\t\t\t       Enter ID Number of Employee to search the record : ");
        scanf("%d", &tempid);

        rewind(fp); // Md. Rasel Hossain

        while ((fread(&e, siz, 1, fp)) == 1)
        {
            if (e.id == tempid)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            printf("\n\t\t\t\t\t\t\t\tNAME : %s", e.name);
            printf("\n\n\t\t\t\t\t\t\t\tID : %d", e.id);
            printf("\n\n\t\t\t\t\t\t\t\tDESIGNATION : %s", e.desgn);
            printf("\n\n\t\t\t\t\t\t\t\tBRANCH : %s", e.branch); // Md. Rasel Hossain
            printf("\n\n\t\t\t\t\t\t\t\tSALARY: %.2f", e.sal);
            printf("\n\n\t\t\t\t\t\t\t\tPRESENT ADDRESS : %s", e.psaddr);
            printf("\n\n\t\t\t\t\t\t\t\tPERMANANT ADDRESS : %s", e.prtaddr);
            printf("\n\n\t\t\t\t\t\t\t\tPHONE : %s", e.phone);
            printf("\n\n\t\t\t\t\t\t\t\tE-MAIL : %s\n\t", e.mail);

            printf("\n\n\t\t\t\t\t\t\t\t========================");

        }
        else
            printf("\n\n\t\t\t\t\t\t\t\t      ERROR, RECORD NOT FOUND!");

        printf("\n\n\t\t\t\t\t\t\tWant to enter another search (Y/N)");
        fflush(stdin); // Md. Rasel Hossain
        another = getchar();
    }
}

//========================LIST OF MALE EMPLOYEE==
void maleemp(FILE *fp)
{
    printHead();
    printf("\n\t\t\t\t\t\t\t\t      List of Male Employee\n");
    printf("\t\t\t\t\t\t\t\t    -------------------------\n");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp); // Md. Rasel Hossain

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        if ((strcmp(e.gender, "Male") == 0) || (strcmp(e.gender, "male") == 0))
        {
            // Md. Rasel Hossain
            printf("\n\n\t\t\t\t\t\t\t\t      ID : %d", e.id);
            printf("\n\n\t\t\t\t\t\t\t\t      NAME : %s", e.name);
            printf("\n\n\t\t\t\t\t\t\t\t      DESIGNATION : %s", e.desgn);
            printf("\n\n\t\t\t\t\t\t\t\t      PHONE : %s\n\t", e.phone);
            printf("\n\t\t\t\t\t\t\t      ======================================");
        }
    }

    printf("\n\t");
    printf("\n\n\t\t\t\t\t\t\t           Enter any keys to continue...");
    getch();
}

//========================LIST OF FEMALE EMPLOYEE==

void femaleemp(FILE *fp)
{
    printHead();
    printf("\n\t\t\t\t\t\t\t\t      List of Female Employee\n");
    printf("\t\t\t\t\t\t\t\t    ---------------------------\n");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        if ((strcmp(e.gender, "Female") == 0) || (strcmp(e.gender, "female") == 0))
        {
            printf("\n\n\t\t\t\t\t\t\t\t      ID : %d", e.id);
            printf("\n\n\t\t\t\t\t\t\t\t      NAME : %s", e.name);
            printf("\n\n\t\t\t\t\t\t\t\t      DESIGNATION : %s", e.desgn);
            printf("\n\n\t\t\t\t\t\t\t\t      PHONE : %s\n\t", e.phone);
            printf("\n\t\t\t\t\t\t\t      ======================================");
        }
    }
    printf("\n\t");
    printf("\n\n\t\t\t\t\t\t\t           Enter any keys to continue...");
    getch();
}

//========================LIST OF EMPLOYEE FROM DHAKA====

void frmdhaka(FILE *fp)
{
    printHead();
    printf("\n\t\t\t\t\t\t\t\t    List of Employee from Dhaka\n"); // Md. Rasel Hossain
    printf("\t\t\t\t\t\t\t\t  -------------------------------\n");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        if ((strstr(e.prtaddr, "Dhaka") == 0) || (strstr(e.prtaddr, "dhaka") == 0) || (strstr(e.prtaddr, "DHAKA") == 0))
        {
            printf("\n\n\t\t\t\t\t\t\t\t      ID : %d", e.id);
            printf("\n\n\t\t\t\t\t\t\t\t      NAME : %s", e.name);
            printf("\n\n\t\t\t\t\t\t\t\t      DESIGNATION : %s", e.desgn);
            printf("\n\n\t\t\t\t\t\t\t\t      PHONE : %s", e.phone);
            printf("\n\n\t\t\t\t\t\t\t\t      E-MAIL : %s\n\t", e.mail);
            printf("\n\t\t\t\t\t\t\t      ======================================");
        }
    } // Md. Rasel Hossain
    printf("\n\t");
    printf("\n\n\t\t\t\t\t\t\t           Enter any keys to continue...");
    getch();
}

//========================LIST OF EMPLOYEE FROM ORS DIST====

void frmors(FILE *fp)
{
    printHead();
    printf("\n\t\t\t\t\t\t\t       List of Employee from Others District\n");
    printf("\t\t\t\t\t\t\t     -----------------------------------------\n");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        if ((strstr(e.prtaddr, "Dhaka") == 1) && (strstr(e.prtaddr, "dhaka") == 1) && (strstr(e.prtaddr, "DHAKA") == 1))
        {
            printf("\n\n\t\t\t\t\t\t\t\t      ID : %d", e.id);
            printf("\n\n\t\t\t\t\t\t\t\t      NAME : %s", e.name);
            printf("\n\n\t\t\t\t\t\t\t\t      DESIGNATION : %s", e.desgn);
            printf("\n\n\t\t\t\t\t\t\t\t      PHONE : %s", e.phone);
            printf("\n\n\t\t\t\t\t\t\t\t      E-MAIL : %s\n\t", e.mail);
            printf("\n\t\t\t\t\t\t\t      ======================================");
        }
    }
    printf("\n\t");
    printf("\n\n\t\t\t\t\t\t\t           Enter any keys to continue...");
    getch();
}

//==============DISPLAY BASIC INFO LIST==

void displaybasic(FILE *fp)
{
    printHead(); // Md. Rasel Hossain
    printf("\n\t\t\t\t\t\t\t             Display Basic Information\n");
    printf("\t\t\t\t\t\t\t\t  -------------------------------\n");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        printf("\n\n\t\t\t\t\t\t\t\t      ID : %d", e.id);
        printf("\n\n\t\t\t\t\t\t\t\t      NAME : %s", e.name);
        printf("\n\n\t\t\t\t\t\t\t\t      DESIGNATION : %s", e.desgn);
        printf("\n\n\t\t\t\t\t\t\t\t      GENDER : %s", e.gender);
        printf("\n\n\t\t\t\t\t\t\t\t      BRANCH : %s", e.branch);
        printf("\n\n\t\t\t\t\t\t\t\t      PHONE : %s", e.phone);
        printf("\n\n\t\t\t\t\t\t\t\t      E-MAIL : %s\n\t", e.mail);
        printf("\n\t\t\t\t\t\t\t      ======================================");
    }
    printf("\n\t");
    printf("\n\n\t\t\t\t\t\t\t           Enter any keys to continue...");
    getch();
}

//========BASIC CONTACT INFO LIST====

void basiccontact(FILE *fp)
{
    printHead();
    printf("\n\t\t\t\t\t\t\t\t     Basic Contact Information\n");
    printf("\t\t\t\t\t\t\t\t-------------------------------\n");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\tID : %d", e.id);
        printf("\n\n\t\t\t\t\t\t\t\t\tNAME : %s", e.name);
        printf("\n\n\t\t\t\t\t\t\t\t\tDESIGNATION : %s", e.desgn);
        printf("\n\n\t\t\t\t\t\t\t\t\tPHONE : %s", e.phone);
        printf("\n\n\t\t\t\t\t\t\t\t\tE-MAIL : %s\n\t", e.mail);
        printf("\n\t\t\t\t\t\t\t      ======================================");
    }
    printf("\n\t");
    printf("\n\n\t\t\t\t\t\t\t\tEnter any keys to continue...");
    getch();
}

//========================LIST OF EMPLOYEE OF MAIN BRANCH====

void mainbr(FILE *fp)
{
    printHead();
    printf("\n\t\t\t\t\t\t\t          List of Employee of Main Branch\n");
    printf("\t\t\t\t\t\t\t        -----------------------------------\n");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1) // Md. Rasel Hossain
    {
        if ((strcmp(e.branch, "Main") == 0) || (strcmp(e.prtaddr, "main") == 0) || (strcmp(e.prtaddr, "MAIN") == 0))
        {
            printf("\n\n\t\t\t\t\t\t\t\t\tID : %d", e.id);
            printf("\n\n\t\t\t\t\t\t\t\t\tNAME : %s", e.name);
            printf("\n\n\t\t\t\t\t\t\t\t\tDESIGNATION : %s", e.desgn); // Md. Rasel Hossain
            printf("\n\n\t\t\t\t\t\t\t\t\tPHONE : %s", e.phone);
            printf("\n\n\t\t\t\t\t\t\t\t\tE-MAIL : %s\n\t", e.mail);
            printf("\n\n\t\t\t\t\t\t\t\t========================");
        }
    }
    printf("\n\t");
    printf("\n\n\t\t\t\t\t\t\t\tEnter any keys to continue...");
    getch();
}

//========================LIST OF EMPLOYEE OF OTHRES BRANCH====

void otherbr(FILE *fp)
{
    printHead();
    printf("\n\t\t\t\t\t\t\t\t List of Employee of Other Branch\n"); // Md. Rasel Hossain
    printf("\t\t\t\t\t\t\t      --------------------------------------\n");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        if ((strcmp(e.branch, "Main") != 0) && (strcmp(e.prtaddr, "main") != 0) && (strcmp(e.prtaddr, "MAIN") != 0))
        {
            printf("\n\n\t\t\t\t\t\t\t\t      ID : %d", e.id);
            printf("\n\n\t\t\t\t\t\t\t\t      NAME : %s", e.name); // Md. Rasel Hossain
            printf("\n\n\t\t\t\t\t\t\t\t      DESIGNATION : %s", e.desgn);
            printf("\n\n\t\t\t\t\t\t\t\t      PHONE : %s", e.phone);
            printf("\n\n\t\t\t\t\t\t\t\t      E-MAIL : %s\n\t", e.mail);
            printf("\n\n\t\t\t\t\t\t\t\t========================");
        }
    }
    printf("\n\t");
    printf("\n\n\t\t\t\t\t\t\t\tEnter any keys to continue...");
    getch();
}
// Md. Rasel Hossain

int SetConsoleSize(void)
{

    system("mode CON: COLS=220");

    return 0;
}

int MaximizeOutputWindow(void)
{

    HWND ConsoleWindow;

    ConsoleWindow = GetConsoleWindow();

    ShowWindow(ConsoleWindow, SW_MAXIMIZE);

    return 0;
}

void about()
{
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t\t\t    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t\t\t\t\t    ::          Project Details & About Programmer          ::\n");
    printf("\t\t\t\t\t\t    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\n");
    printf("\t\t    :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\t    ::                                  Project Name : Employee Management System (EMS)                                ::\n");
    printf("\t\t    ::                                ---------------------------------------------------                              ::\n");
    printf("\t\t    ::                                                                                                                 ::\n");
    printf("\t\t    ::                                             ----------------------                                              ::\n");
    printf("\t\t    ::                                                  Submitted By                                                   ::\n");
    printf("\t\t    ::                                             ----------------------                                              ::\n");
    printf("\t\t    ::                                        Name : Md. Rasel Hossain                                                 ::\n");
    printf("\t\t    ::                                   ID Number : 0242220005341013                                                  ::\n");
    printf("\t\t    ::                                       Batch : 39th                                                              ::\n");
    printf("\t\t    ::                                     Section : A                                                                 ::\n");
    printf("\t\t    ::                                  Department : Software Engineering - SWE                                        ::\n");
    printf("\t\t    ::                                   Institute : Daffodil International University                                 ::\n");
    printf("\t\t    ::                                                                                                                 ::\n");
    printf("\t\t    ::                                             ----------------------                                              ::\n");
    printf("\t\t    ::                                                  Submitted To                                                   ::\n");
    printf("\t\t    ::                                             ----------------------                                              ::\n");
    printf("\t\t    ::                                                 Md. Shohel Arman                                                ::\n");
    printf("\t\t    ::                                               Assistant Professor                                               ::\n");
    printf("\t\t    ::                                    Department of Software Engineering - SWE                                     ::\n");
    printf("\t\t    ::                                        Daffodil International University                                        ::\n");
    printf("\t\t    ::                                                                                                                 ::\n");
    printf("\t\t    ::                                             ----------------------                                              ::\n");
    printf("\t\t    ::                                                 Submission Date                                                 ::\n");
    printf("\t\t    ::                                             ----------------------                                              ::\n");
    printf("\t\t    ::                                                15 December, 2023                                                ::\n");
    printf("\t\t    ::                                                                                                                 ::\n");
    printf("\t\t    ::                           Copyright | 2023 - Md. Rasel Hossain. All Right Reserved.                             ::\n");
    printf("\t\t    :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\n\n\t\t\t\t\t\t\t\tEnter any keys to continue...");
    getch();
}

void logo()
{
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t     ____ _  _ ___  _    ____ _   _ ____ ____\n");
    printf("\t\t\t\t\t\t\t     |___ |\\/| |__] |    |  |  \\_/  |___ |___\n");
    printf("\t\t\t\t\t\t\t     |___ |  | |    |___ |__|   |   |___ |___\n");
    printf("\t\t\t\t\t\t\t _  _ ____ _  _ ____ ____ ____ _  _ ____ _  _ ___\n");
    printf("\t\t\t\t\t\t\t |\\/| |__| |\\ | |__| | __ |___ |\\/| |___ |\\ |  |\n");
    printf("\t\t\t\t\t\t\t |  | |  | | \\| |  | |__] |___ |  | |___ | \\|  | \n");
    printf("\t\t\t\t\t\t\t          ____ _   _ ____ ___ ____ _  _\n");
    printf("\t\t\t\t\t\t\t          [__   \\_/  [__   |  |___ |\\/|\n");
    printf("\t\t\t\t\t\t\t          ___]   |   ___]  |  |___ |  |\n");
    printf("\n\n\n");
}
