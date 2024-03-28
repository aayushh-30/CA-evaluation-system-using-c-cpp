#include <stdio.h>
#include <string.h>
#include <time.h>

static int z;
static int y;
static int l = 1;
int login(void) {
  struct credentials {
    int registration_no;
    char password[20];
  };

  struct credentials users[10];     //BOTH THE ID ARE LINKED
  users[0].registration_no = 112233;
  strcpy(users[0].password, "AYUSH");
  users[1].registration_no = 445566;
  strcpy(users[1].password, "KANHA");

  struct credentials staff[10];
  staff[0].registration_no = 123456;   // THIS ID IS LINKED WITH THE RECORDS
  strcpy(staff[0].password, "HAPPY");
  staff[1].registration_no = 12730;
  strcpy(staff[1].password, "HELLO");
  staff[2].registration_no = 1112255;
  strcpy(staff[2].password, "KAN");

valid_option:
  printf("I AM A : \n1.STUDENT\n2.TEACHER\n\n");
  int mem;
  scanf("%d", &mem);
  int regi_no;
  char pass[20];

  if (mem == 1 || mem == 2) {
    printf("ENTER ID : ");
    scanf("%d", &regi_no);
    printf("ENTER PASSWORD : ");
    scanf("%s", pass);
    if (mem == 1) {
      for (int i = 0; i < 100; i++) {
        if (regi_no == users[i].registration_no &&    // ID AND PASSWORD CHECKING
            strcmp(pass, users[i].password) == 0) {
          printf("LOGIN SUCCESSFUL");
          y = i + 1;
          z = 1;
          break;
        } else
          printf("USER NOT FOUND\nPLEASE ENTER VALID CREDENTIALS\n");
        goto valid_option;
      }

    }

    else if (mem == 2) {
      for (int i = 0; i < 300; i++) {
        if (regi_no == staff[i].registration_no &&
            strcmp(pass, staff[i].password) == 0) {
          printf("LOGIN SUCCESSFUL");
          z=2;
          l = l + i;
          break;
         } else
          printf("\nUSER NOT FOUND\nPLEASE ENTER VALID CREDENTIALS\n\n");
        goto valid_option;
      }
    }
  }

  else {
    printf("ENTER VALID OPTION\n");
    goto valid_option;
  }

  return 0;
}

void student_module() {
  printf("\n-:HELLO DEAR STUDENT:-");
alex:
  printf("\nCHOOSE AN OPTION : \n1.VIEW MARKS\n2.UPCOMING "
         "TESTS\n3.SCRUTINY\n4.FEEDBACK\n5.EXIT\n");
  int opt;
  scanf("%d", &opt);
  if (opt == 1) {
    FILE *fp1;
    fp1 = fopen("marks.txt", "r");
    switch (y) {
    case 1:
      printf("ROLL NO 1\n NAME : AYUSH KUMAR KARMI\n");
      printf("SUBJECT\tCODE\tMARKS_OBTAINED\tMAX_MARK\n");
      printf("MATH\tMTH101\t\t45\t\t\t50\n");
      printf("PHYSICS\tPHY201\t\t45\t\t\t50\n");
      printf("CHEMISTRY\tCHE301\t\t45\t\t50\n");
      goto alex;
      break;

    case 2:
      printf("ROLL NO 2\n NAME : KANHA KUMAR KARMI\n");
      printf("SUBJECT\tCODE\tMARKS_OBTAINED\tMAX_MARK\n");
      printf("MATH\tMTH101\t43\t50\n");
      printf("PHYSICS\tPHY201\t45\t50\n");
      printf("CHEMISTRY\tCHE301\t49\t50\n");
      goto alex;
      break;

    case 3:
      printf("ROLL NO 3\n NAME : aj\n");
      printf("SUBJECT\tCODE\tMARKS_OBTAINED\tMAX_MARK\n");
      printf("MATH\tMTH101\t40\t50\n");
      printf("PHYSICS\tPHY201\t35\t50\n");
      printf("CHEMISTRY\tCHE301\t45\t50\n");
      goto alex;
      break;
    }

  } else if (opt == 2) {
    FILE *fp2;
    char ch;
    fp2 = fopen("tests.txt", "r");
    while ((ch = fgetc(fp2)) != EOF)
      printf("%c", ch);
    fclose(fp2);
    goto alex;

  } else if (opt == 3) {
  j:
    printf("SELECT SUBJECT : \n1.MATH\n2.PHYSICS\n3.CHEMISTRY");
    int m;
    scanf("%d", &m);
    if (m == 1 || m == 2 || m == 3)
      printf("YOUR SCRUTINY REQUEST HAS BEEN PLACED SUCCESSFULLY.\nPLEASE "
             "CONTACT YOUR RESPECTIVE SUBJECT TEACHER\n");
    goto alex;
  }
    else if(opt==5){
      printf("THANKS FOR USING OUR SOFTWARE\nVISIT AGAIN\n\n");
    }
  else {
    printf("INVALID INPUT\n");
    
  }
}
// TEACHER MODULE

void teacher_module(void) {
  struct student {
    int roll;
    char name[40];
    int marks;
  } std;

  printf("\nHELLO DEAR TEACHER\n");
  switch (l) {
    int opt;
  g:

  case 1:
    printf("NAME : RAVI RAJ SINGH \n SUB : MATH \nID : 1254\n");
    printf("1: Create student record\n");
    printf("2: Display student record\n");
    printf("3: Assign Test\n");
    printf("4: Modify student record\n");
    printf("5: EXIT\n");

    scanf("%d", &opt);

    if (opt == 1) {
      FILE *fp3;
      fp3 = fopen("student_records.txt", "a+");
      printf("NAME : ");
      scanf("%s", std.name);
      printf("ROLL NO:");
      scanf("%d", &std.roll);
      printf("MARKS : ");
      scanf("%d", &std.marks);
      fprintf(fp3, "NAME : %s\tROLL : %d\tMARKS : %d\n", std.name, std.roll,
              std.marks);
      printf("NEW RECORD SUCCESSFULLY ADDED\n\n");
      fclose(fp3);
      opt--;
      goto g;
    }
    if (opt == 2) {
      FILE *fp2;
      char ch;
      fp2 = fopen("student_records.txt", "a+");
      while ((ch = fgetc(fp2)) != EOF)
        printf("%c", ch);
      fclose(fp2);
      opt = opt - 2;
      goto g;
    }
    if (opt == 3) {
      struct d_o_e {
        int day;
        int month;
        int year;
        char sub[20];
      } s1;
      FILE *fp3;
      fp3 = fopen("tests.txt", "w+");
      printf("ENTER DAY: ");
      scanf("%d", &s1.day);
      printf("ENTER MONTH: ");
      scanf("%d", &s1.month);
      printf("ENTER YEAR: ");
      scanf("%d", &s1.year);
      printf("ENTER TOPICS: ");
      scanf("%s", s1.sub);
      fprintf(fp3,
              "ON %d-%d-%d Your %s TEST WILL BE CONDUCTED\nNEW TEST "
              "SUCCESSFULLY CREATED\n",
              s1.day, s1.month, s1.year, s1.sub);
      fclose(fp3);
    }
    break;
  case 2:
    printf("NAME : KAVI RAJ  \n SUB : PHY \nID : 1254\n");
    printf("1: Create student record\n");
    printf("2: Display student record\n");
    printf("3: Assign Test\n");
    printf("4: Modify student record\n");
    printf("5: EXIT\n");

    scanf("%d", &opt);

    if (opt == 1) {
      FILE *fp3;
      fp3 = fopen("student_records(PHYSICS).txt", "a+");
      printf("NAME : ");
      scanf("%s", std.name);
      printf("ROLL NO:");
      scanf("%d", &std.roll);
      printf("MARKS : ");
      scanf("%d", &std.marks);
      fprintf(fp3, "NAME : %s\tROLL : %d\tMARKS : %d\n", std.name, std.roll,
              std.marks);
      fclose(fp3);
      opt--;
      goto g;
    }
    if (opt == 2) {
      FILE *fp2;
      char ch;
      fp2 = fopen("student_records(PHYSICS).txt", "a+");
      while ((ch = fgetc(fp2)) != EOF)
        printf("%c\n", ch);
      fclose(fp2);
      opt = opt - 2;
      goto g;
    }
    if (opt == 3) {
      struct d_o_e {
        int day;
        int month;
        int year;
        char sub[20];
      } s1;
      FILE *fp3;
      fp3 = fopen("tests.txt", "w+");
      printf("ENTER DAY: ");
      scanf("%d", &s1.day);
      printf("ENTER MONTH: ");
      scanf("%d", &s1.month);
      printf("ENTER YEAR: ");
      scanf("%d", &s1.year);
      printf("ENTER TOPICS: ");
      scanf("%s", s1.sub);
      fprintf(fp3, "ON %d-%d-%d Your %s TEST WILL BE CONDUCTED", s1.day,
              s1.month, s1.year, s1.sub);
      fclose(fp3);
    }
    break;
  case 3:
    printf("NAME : K.RAJU  \n SUB : CHEM \nID : 1254\n");
    lo:
    printf("1: Create student record\n");
    printf("2: Display student record\n");
    printf("3: Assign Test\n");
    printf("4: Modify student record\n");
    printf("5: EXIT\n");

    scanf("%d", &opt);

    if (opt == 1) {
      FILE *fp3;
      fp3 = fopen("student_records(CHEMISTRY).txt", "a+");
      printf("NAME : ");
      scanf("%s", std.name);
      printf("ROLL NO:");
      scanf("%d", &std.roll);
      printf("MARKS : ");
      scanf("%d", &std.marks);
      fprintf(fp3, "NAME : %s\tROLL : %d\tMARKS : %d\n", std.name, std.roll,
              std.marks);
      printf("\nSTUDENT RECORD CREATED SUCCESSFULLY!\n");
      fclose(fp3);
      opt--;
      goto lo;
    }
    if (opt == 2) {
      FILE *fp2;
      char ch;
      fp2 = fopen("student_records(CHEMISTRY).txt", "a+");
      while ((ch = fgetc(fp2)) != EOF)
        printf("%c", ch);
      fclose(fp2);
      opt = opt - 2;
      goto lo;
    }
    if (opt == 3) {
      struct d_o_e {
        int day;
        int month;
        int year;
        char sub[20];
      } s1;
      FILE *fp3;
      fp3 = fopen("tests.txt", "w+");
      printf("ENTER DAY: ");
      scanf("%d", &s1.day);
      printf("ENTER MONTH: ");
      scanf("%d", &s1.month);
      printf("ENTER YEAR: ");
      scanf("%d", &s1.year);
      printf("ENTER TOPICS: ");
      scanf("%s", s1.sub);
      fprintf(fp3, "ON %d-%d-%d Your %s TEST WILL BE CONDUCTED", s1.day,
              s1.month, s1.year, s1.sub);
      fclose(fp3);
      opt = opt - 3;
      goto lo;
    }
    break;
  }
}

int main() {

  printf("HELLO USER\nWELCOME TO THE TEST EVOLUTION SYSTEM\nby-AK\n");
  time_t t = time(NULL);
  struct tm *current_time = localtime(&t);
  char date_time[100];

  strftime(date_time, sizeof(date_time), "%d-%m-%Y %H:%M:%S", current_time);
  printf("%s\n\n", date_time);

  // LOGIN FUNCTION CALL
  login();
  if (z == 1) {
    student_module();

  } else if(z==2) {
    teacher_module();
  }

  return 0;
}
