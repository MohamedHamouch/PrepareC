#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaring global variable
int studentnumber=0; //counts total number of students

//Defining student type structure/variables
typedef struct{

    int day;
    int month;
    int year;

}Date;
typedef struct{

    char lastname[30];
    char firstname[30];
    int id;
    Date birthday;
    int department;
    float note;

}Student ;

//Declaring functions(definition bellow main).
void add_student(Student student []);
void display_student(Student student[]);
int search_id(Student student[], int n);
void edit_student(Student student[]);
void delete_student(Student student[]);
float average_uni(Student student[]);
float average_dep(Student student[]);
int ndep_student(Student student[], int dep);
void set_note(Student student[]);
int succes_studet(Student student[], int dep);
void search_name(Student student[]);
void dep_student(Student student[]);


//Main function.
int main()
{
    int choice;
    Student student [50];

    //Entering the student management system
    do{
        //Menu
        printf("\n|||=-=-=-=-=-=-=-=-=-= MENU =-=-=-=-=-=-=-=-=-=|||\n");
        printf("-To add new students..................... choose 1.\n");
        printf("-To edit or delete a student............. choose 2.\n");
        printf("-To display a list of all students....... choose 3.\n");
        printf("-To calculate the general note........... choose 4.\n");
        printf("-For statistics menu..................... choose 5.\n");
        printf("-To search for a specific student........ choose 6.\n");
        printf("-To sort the students.................... choose 7.\n");
        printf("-To end the system ...................... choose 0.\n");

        //Decision making
        printf("-what's your choice: ");
        scanf("%d",&choice);

        //Choice execution
        switch(choice){
            //Ending the system
            case 0:
                printf("Ending the programm Goodbye.");
                break;

            //Add new students
            case 1:
                add_student(student);
                break;

            //Edit or Delete
            case 2:
                printf("To edit a student informations type 1.\n");
                printf("To edit a student informations type 2.\n");
                int ed;
                do{
                scanf("%d",&ed);
                if(ed==1){
                    edit_student(student);
                }else if(ed==2){
                    delete_student(student);
                }else {
                    printf("Invalid entry, please try again 1-To edit 2-To delete");
                    }
                }while(ed!=1 && ed!=2);
                break;

            //Display all
            case 3:
                display_student(student);
                break;

            //Calculate the general note
            case 4:
                printf("For the general note of the university type 1");
                printf("For the general note of a department type 2");
                int ud;
                do{
                    scanf("%d",&ud);
                    if(ud==1){
                        average_uni(student);
                    }else if(ud==2){
                        average_dep(student);
                    }else {
                    printf("Invalid entry, please try again 1-For university's average 2-For a department average");
                    }
                }while(ud!=1 && ud!=2);

                break;

            //Show statistics
            case 5:

                break;

            //Search for specific student
            case 6:

                break;

            //Sort students
            case 7:

                break;

            //Other choices
            default:
                printf("Invalid selection, please try again. \n");
                break;
            }

        }while(choice != 0);

    return 0;//end of main
}

//Defining functions
//1.Add students
void add_student(Student student []){

    int n;
    printf("How many students you want to add? : ");
    scanf("%d",&n);

    for(int i=studentnumber ; i<studentnumber+n ; i++){
        int day,month,year;
        printf("****************\n");
        student[i].id = i+1;
        printf("Enter the informations.\n");
        printf("the ID=%d is automatically assigned to this student\n",i+1);
        printf("The first name :");
        scanf("%s",student[i].firstname);
        printf("The last name :");
        scanf("%s",student[i].lastname);
        printf("The Birthday (DD-MM-YYYY format): ");
        do{
            scanf("%d-%d-%d",&day,&month,&year);
            if(month>12 || month<1 || day>31 || day<1 || year>2007){
                printf("Invalid, Please Enter a correct date(DD-MM-YYYY format): ");}
        }while(month>12 || month<1 || day>31 || day<1 || year>2008 || year<1989);
        student[i].birthday.day = day;
        student[i].birthday.month = month;
        student[i].birthday.year = year;
        printf("Choose from the available Departments :\n");
        printf("1-Science\t2-Economics\t3-Law\t4-Arts : ");
        do{
            scanf("%d",&student[i].department);
            if(student[i].department<1 || student[i].department>4){
                printf("Invalid choice, please select a department from the list: ");
            }
        }while(student[i].department<1 || student[i].department>4);
        printf("The note of the student :");
        do{
            scanf("%f",&student[i].note);
            if(student[i].note >20 || student[i].note<0){
                printf("Invalid entry, please enter a note between 0 and 20: ");}
        }while(student[i].note >20 || student[i].note<0);
    }
    studentnumber+=n;
}

//2.Manipulate
//2.1 Search by id
int search_id(Student student[], int n){
     for(int i=0 ; i<studentnumber ; i++){
        if(student[i].id == n){
            return i;//returns the iteration if found
        }
    }
    //returns -1 if not found
    return -1;
}

//2.2.Edit
void edit_student(Student student[]){

    int n,pos;
    printf("=================================\n");
    printf("Enter the ID of the student you're looking to midify");
    scanf("%d",&n);
    pos=search_id(student, n);
    if(pos==-1){
        printf("Id not found\n");
        return;
    }else{
        int day,month,year;
        printf("Enter the les informations.\n");
        printf("The first name :");
        scanf("%s",student[pos].firstname);
        printf("The last name :");
        scanf("%s",student[pos].lastname);
        printf("The Birthday (DD-MM-YYYY format): ");
        do{
            scanf("%d-%d-%d",&day,&month,&year);
            if(month>12 || month<1 || day>31 || day<1 || year>2007){
                printf("Invalid, Please Enter a correct date(DD-MM-YYYY format): ");}
        }while(month>12 || month<1 || day>31 || day<1 || year>2008 || year<1989);
        student[pos].birthday.day = day;
        student[pos].birthday.month = month;
        student[pos].birthday.year = year;
        printf("Choose from the available Departments :\n");
        printf("1-Science\t2-Economics\t3-Law\t4-Arts : ");
        do{
            scanf("%d",&student[pos].department);
            if(student[pos].department<1 || student[pos].department>4){
                printf("Invalid choice, please select a department from the list: ");
            }
        }while(student[pos].department<1 || student[pos].department>4);
        printf("The note of the student :");
        do{
            scanf("%f",&student[pos].note);
            if(student[pos].note >20 || student[pos].note<0){
                printf("Invalid entry, please enter a note between 0 and 20: ");}
        }while(student[pos].note >20 || student[pos].note<0);
        printf("-Student added successfully.");

    }
}

//2.3.Delete
void delete_student(Student student[]){

    int n,pos;
    printf("=================================\n");
    printf("Enter the ID of the student you're looking to delete");
    scanf("%d",&n);
    pos=search_id(student, n);
    if(pos==-1){
        printf("Id not found\n");
        return;
    }else{
          for(int i=pos; i<studentnumber; i++){
                student[i]=student[i+1];}
    }
    printf("The student was deleted succesfully");
    studentnumber--;
}

//3.Display all students
void display_student(Student student[]){
     if(studentnumber==0){
        printf("No student registered yet\n");
    }else{
        printf("----The list of all registered students----\n");
        for(int i=0 ; i<studentnumber ;i++){
            printf("=================================\n");
            printf("-Student with Id = %d \n",student[i].id);
            printf("-First name: %s\n",student[i].firstname);
            printf("-Last name %s: \n",student[i].lastname);
            printf("-Birthday: %02d-%02d-%4d\n",student[i].birthday.day,student[i].birthday.month,student[i].birthday.year);
            printf("-Department: %d\n",student[i].department);
            printf("-General note: %02.2f\n",student[i].note);
        }
    }
}

//4.Calculate the average note
//4.1.average note for university
float average_uni(Student student[]){
    float total=0;
    for(int i=0; i<studentnumber ;i++){
            total+=student[i].note;
    }
    total/=studentnumber;
    printf("The average note for all students of the university : %02.2f",total);
return total;
}

//4.2.average note for specific department
float average_dep(Student student[]){
    float total=0;
    int dep,s=0;
    //1-Science\t2-Economics\t3-Law\t4-Arts :
    printf("Type the correspondent number: \n");
    printf("1-For the average note of Science department \n");
    printf("2-For the average note of Economics department \n");
    printf("3-For the average note of Law department \n");
    printf("4-For the average note of Arts department \n");
    do{
        scanf("%d",&dep);
        if(dep<1 || dep>4)
            printf("Invalid insertion, please enter a number between 1-4:\n");
    }while(dep<1 || dep>4);
    for(int i=0;i<studentnumber;i++){
        if(student[i].department==dep){
            total+=student[i].note;
            s++;
        }
    }
    total/=s;
    printf("The average note for the selected deparment : %02.2f",total);
 return total;
}
//5.Statistics
//5.1.Students of every department
int ndep_student(Student student[], int dep){

    int total=0;
    //1-Science\t2-Economics\t3-Law\t4-Arts :

    for(int i=0;i<studentnumber;i++){
        if(student[i].department==dep){
            total++;
        }
    }
    if(dep==1){
        printf("The total number of students in Science department is %d:",total);}
    if(dep==2){
        printf("The total number of students in Economics department is %d:",total);}
    if(dep==3){
        printf("The total number of students in Law department is %d:",total);}
    if(dep==4){
        printf("The total number of students in Arts department is %d:",total);}


    return total;
}

//5.2.Students above specific average
void set_note(Student student[]){
    float step;
    printf("Enter note value to display a list students with higher note");
    do{
        scanf("%f",&step);
        if(step<0 || step>20)
            printf("Please enter a valid note(between 0-20) :");
    }while(step<0 || step>20);

    printf("---the list of all students with note>=%2.2f ---\n",step);
    for(int i=0; i<studentnumber ; i++){
        if(student[i].note >= step){
            printf("=================================\n");
            printf("-Student with Id = %d \n",student[i].id);
            printf("-First name: %s\n",student[i].firstname);
            printf("-Last name %s: \n",student[i].lastname);
            printf("-Birthday: %02d-%02d-%4d\n",student[i].birthday.day,student[i].birthday.month,student[i].birthday.year);
            printf("-Department: %d\n",student[i].department);
            printf("-General note: %02.2f\n",student[i].note);
        }
    }
}

//5.3.List three students with highest notes

//5.4.Number of successful students
int succes_studet(Student student[], int dep){
    int total = 0;
     for(int i=0; i<studentnumber ; i++){
        if(student[i].department==dep && student[i].note >= 10){
            total++;
        }
    }

    //1-Science 2-Economics\ 3-Law 4-Arts :
    if(dep==1){
        printf("The number of successful students in Science department is %d:",total);}
    if(dep==2){
        printf("The number of successful students in Economics department is %d:",total);}
    if(dep==3){
        printf("The number of successful students in Law department is %d:",total);}
    if(dep==4){
        printf("The number of successful students in Arts department is %d:",total);}

    return total;
}

//6.Search
//6.1.Search student per last name
void search_name(Student student[]){

    char test[30],nbr=0;
    printf("Enter the last name of the student you are looking for :");
    scanf("%s",test);
    for(int i=0; i<studentnumber ;i++){
        if(strcmp(student[i].lastname,test)==0){
            nbr++;
        }
        }
    printf("There are %d students with the last name %s \n",nbr,test);
    for(int i=0; i<studentnumber ;i++){
        if(strcmp(student[i].lastname,test)==0){
            printf("=================================\n");
            printf("-Student with Id = %d \n",student[i].id);
            printf("-First name: %s\n",student[i].firstname);
            printf("-Last name %s: \n",student[i].lastname);
            printf("-Birthday: %02d-%02d-%4d\n",student[i].birthday.day,student[i].birthday.month,student[i].birthday.year);
            printf("-Department: %d\n",student[i].department);
            printf("-General note: %02.2f\n",student[i].note);
        }
    }
}

//6.2.List of students in a specific department.
void dep_student(Student student[]){

    int dep;

    printf("Enter what department's students you want to list :\n");
    printf("Type the correspondent number: \n");
    printf("1-For students in Science department \n");
    printf("2-For students in Economics department \n");
    printf("3-For students in Law department \n");
    printf("4-For students in Arts department \n");
    //1-Science 2-Economics 3-Law 4-Arts :
    do{
        scanf("%d",&dep);
        if(dep<1 || dep>4)
            printf("Invalid insertion, please enter a number between 1-4:\n");
    }while(dep<1 || dep>4);
     if(dep==1){
        printf("The list of students in Science department:");}
    if(dep==2){
        printf("The list of students in Economics department:");}
    if(dep==3){
        printf("The list of students in Law department:");}
    if(dep==4){
        printf("The list of students in Arts department:");}

    for(int i=0;i<studentnumber;i++){
        if(student[i].department==dep){
            printf("=================================\n");
            printf("-Student with Id = %d \n",student[i].id);
            printf("-First name: %s\n",student[i].firstname);
            printf("-Last name %s: \n",student[i].lastname);
            printf("-Birthday: %02d-%02d-%4d\n",student[i].birthday.day,student[i].birthday.month,student[i].birthday.year);
            printf("-Department: %d\n",student[i].department);
            printf("-General note: %02.2f\n",student[i].note);
        }
    }
}

//7.Sorting
//7.2.Alphabetic sort

