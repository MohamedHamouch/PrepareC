#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Declaring global variable
int studentnumber=0; //counts total number of students
int idcount=0;
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
void top_student(Student student[]);
void search_name(Student student[]);
void dep_student(Student student[]);
void name_sort(Student student[]);
void note_sort(Student student[]);
void status_sorting(Student student[]);
void initial(Student student[]);

//Main function.
int main()
{
    int choice;
    Student student [50];

    do{

        printf("\n|||=-=-=-=-=-=-=-=-=-= MENU =-=-=-=-=-=-=-=-=-=|||\n");
        printf("-To add new students..................... choose 1.\n");
        printf("-To edit or delete a student............. choose 2.\n");
        printf("-To display a list of all students....... choose 3.\n");
        printf("-To calculate the general note........... choose 4.\n");
        printf("-To get statistics menu.................. choose 5.\n");
        printf("-To search for a specific student........ choose 6.\n");
        printf("-To sort the students.................... choose 7.\n");
        printf("-To insert existing data (10 students)... choose 8.\n");
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
                printf("Type a corresponded number:\n");
                printf("1-To edit a student informations.\n");
                printf("2-To delete a student.\n");
                int ed;
                do{
                scanf("%d",&ed);
                if(ed==1){
                    edit_student(student);
                }else if(ed==2){
                    delete_student(student);
                }else {
                    printf("Invalid entry, please try again 1-To edit 2-To delete.");
                    }
                }while(ed!=1 && ed!=2);
                break;

            //Display all
            case 3:
                display_student(student);
                break;

            //Calculate the general note
            case 4:
                printf("Type a corresponded number: \n");
                printf("1-For the general note of the university.\n");
                printf("2-For the general note of the departments.\n");
                int ud;
                do{
                    scanf("%d",&ud);
                    if(ud==1){
                        average_uni(student);
                    }else if(ud==2){
                        average_dep(student);
                    }else {
                    printf("Invalid entry, please try again.");
                    }
                }while(ud!=1 && ud!=2);

                break;

            //Show statistics
            case 5:
                printf("Type a corresponded number: \n");
                printf("1-For the number of students registered in the university. \n");
                printf("2-For the number of students registered by department. \n");
                printf("3-To list students with note above certain bar.\n");
                printf("4-For the number of successful students in every department.\n");
                printf("5-To list the TOP 3 students.\n");
                    int st;
                 do{
                     scanf("%d",&st);

                    switch(st){

                    case 1:
                            printf("==> There are %d registered students in the university.\n", studentnumber);
                        break;

                    case 2: ndep_student(student, 1);
                            ndep_student(student, 2);
                            ndep_student(student, 3);
                            ndep_student(student, 4);
                        break;
                    case 3:
                        set_note(student);
                        break;

                    case 4:succes_studet(student, 1);
                        succes_studet(student, 2);
                        succes_studet(student, 3);
                        succes_studet(student, 4);
                        break;
                    case 5:top_student(student);
                        break;

                    default: printf("Invalid entry, please try again :");
                        break;

                    }
                }while(st<1 || st>5);
                break;

            //Search for specific student
            case 6:
                printf("Type a corresponded number \n");
                printf("1-To search for a student by Last name. \n");
                printf("2-To list students registered in certain department. \n");
                int sr;
                 do{
                    scanf("%d",&sr);
                   switch(sr){

                    case 1:search_name(student);
                        break;

                    case 2:dep_student(student);
                        break;

                    default: printf("Invalid entry, please try again.");
                   }

                }while(sr!=1 && sr!=2);
                break;

            //Sort students
            case 7:
                printf("Type a corresponded number:\n");
                printf("1-To sort students by name. \n");
                printf("2-To sort students by general note.\n");
                printf("3-To sort students by their success status.\n");
                int ss;
                do{
                    scanf("%d",&ss);
                   switch(ss){

                    case 1:name_sort(student);
                        break;

                    case 2:note_sort(student);
                        break;

                    case 3:status_sorting(student);
                        break;
                    default: printf("Invalid entry, please try again.");
                    break;
                   }
                }while(ss!=1 && ss!=2 &&ss!=3);
                break;

                case 8: initial(student);
                printf("10 students were added automatically.");
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
    printf("Enter the informations.\n");
    for(int i=studentnumber ; i<studentnumber+n ; i++){
        int day,month,year;
        printf("*****************************\n");
        student[i].id = idcount+1;
        idcount++;
        printf("ID=%d (automatically assigned)\n",idcount);
        printf("The last name :");
        scanf("%s",student[i].lastname);
        printf("The first name :");
        scanf("%s",student[i].firstname);
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
        do{
            printf("1-Science 2-Economics 3-Law 4-Arts : ");
            scanf("%d",&student[i].department);
            if(student[i].department<1 || student[i].department>4){
                printf("Invalid choice, please select a department (1 to 4): \n");
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
    printf("Enter the ID of the student you're looking to modify :");
    scanf("%d",&n);
    pos=search_id(student, n);
    if(pos==-1){
        printf("Id not found.\n");
        return;
    }else{
        int day,month,year;
        printf("Enter the new informations.\n");
        printf("The last name :");
        scanf("%s",student[pos].lastname);
        printf("The first name :");
        scanf("%s",student[pos].firstname);
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
        printf("1-Science 2-Economics 3-Law 4-Arts : ");
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
        printf("-Student updated successfully.");

    }
}

//2.3.Delete
void delete_student(Student student[]){

    int n,pos;
    printf("=================================\n");
    printf("Enter the ID of the student you're looking to delete: ");
    scanf("%d",&n);
    pos=search_id(student, n);
    if(pos==-1){
        printf("Id not found\n");
        return;
    }else{
          for(int i=pos; i<studentnumber; i++){
                student[i]=student[i+1];}
    }
    printf("The student deleted successfully");
    studentnumber--;
}

//3.Display all students
void display_student(Student student[]){
     if(studentnumber==0){
        printf("No student registered yet\n");
    }else{
        printf("--The list of all registered students--\n");
        for(int i=0 ; i<studentnumber ;i++){
            printf("=================================\n");
            printf("-Id = %d \n",student[i].id);
            printf("-Last name: %s \n",student[i].lastname);
            printf("-First name: %s\n",student[i].firstname);
            printf("-Birthday: %02d-%02d-%4d\n",student[i].birthday.day,student[i].birthday.month,student[i].birthday.year);
            //1-Science 2-Economics 3-Law 4-Arts :
            printf("-Department: ");
            if(student[i].department==1){printf("Science\n");}
            if(student[i].department==2){printf("Economics\n");}
            if(student[i].department==3){printf("Law\n");}
            if(student[i].department==4){printf("Arts\n");}
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
    printf("==> The average note for all students of the university : %02.2f",total);
return total;
}

//4.2.average note for specific department
float average_dep(Student student[]){
    float total=0;
    int dep,s=0;
    //1-Science\t2-Economics\t3-Law\t4-Arts :
    printf("Type the correspondent number: \n");
    printf("1-For the average note of Science department. \n");
    printf("2-For the average note of Economics department. \n");
    printf("3-For the average note of Law department. \n");
    printf("4-For the average note of Arts department. \n");
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
    printf("==> The average note for the selected deparment : %02.2f",total);
 return total;
}
//5.Statistics
//5.1.Students of every department
int ndep_student(Student student[], int dep){

    int total=0;
    //1-Science 2-Economics 3-Law 4-Arts :

    for(int i=0;i<studentnumber;i++){
        if(student[i].department==dep){
            total++;
        }
    }
    if(dep==1){
        printf("==> The total number of students in Science department is: %d\n",total);}
    if(dep==2){
        printf("==> The total number of students in Economics department is: %d\n",total);}
    if(dep==3){
        printf("==> The total number of students in Law department is: %d\n",total);}
    if(dep==4){
        printf("==> The total number of students in Arts department is: %d\n",total);}

    return total;
}

//5.2.Students above specific average
void set_note(Student student[]){
    float step;
    printf("Enter note value to display all students with higher note:");
    do{
        scanf("%f",&step);
        if(step<0 || step>20)
            printf("Please enter a valid note(between 0-20) :");
    }while(step<0 || step>20);

    printf("---the list of all students with note>=%2.2f ---\n",step);
    for(int i=0; i<studentnumber ; i++){
        if(student[i].note >= step){
            printf("=================================\n");
            printf("-Id = %d \n",student[i].id);
            printf("-Last name: %s \n",student[i].lastname);
            printf("-First name: %s\n",student[i].firstname);
            printf("-Birthday: %02d-%02d-%4d\n",student[i].birthday.day,student[i].birthday.month,student[i].birthday.year);
              //1-Science 2-Economics 3-Law 4-Arts :
            printf("-Department: ");
            if(student[i].department==1){printf("Science\n");}
            if(student[i].department==2){printf("Economics\n");}
            if(student[i].department==3){printf("Law\n");}
            if(student[i].department==4){printf("Arts\n");}
            printf("-General note: %02.2f\n",student[i].note);
        }
    }
}

//5.3.Number of successful students
int succes_studet(Student student[], int dep){
    int total = 0;
     for(int i=0; i<studentnumber ; i++){
        if(student[i].department==dep && student[i].note >= 10){
            total++;
        }
    }

    //1-Science 2-Economics 3-Law 4-Arts :
    if(dep==1){
        printf("==> The number of successful students in Science department is: %d\n",total);}
    if(dep==2){
        printf("==> The number of successful students in Economics department is: %d\n",total);}
    if(dep==3){
        printf("==> The number of successful students in Law department is: %d\n",total);}
    if(dep==4){
        printf("==> The number of successful students in Arts department is: %d\n",total);}

    return total;
}

//5.4.List 3 students with highest notes
void top_student(Student student[]){

    Student temp;
    Student s[50];

    for(int k=0;k<studentnumber;k++){
            s[k]=student[k];
    }
    for(int i=0;i<studentnumber-1;i++){
        for(int j=0;j<studentnumber-i-1;j++){
            if(s[j].note<s[j+1].note){
                    temp=s[j];
                    s[j]=s[j+1];
                    s[j+1]=temp;
            }
        }
    }

    int c=3;
    if(studentnumber<3){
            c=studentnumber;
    }
    printf("--- The students with highest notes ---\n");
    for(int i=0;i<c;i++){
        printf("=================================\n");
        printf("-Id = %d \n",s[i].id);
        printf("-Last name: %s \n",s[i].lastname);
        printf("-First name: %s\n",s[i].firstname);
        printf("-Birthday: %02d-%02d-%4d\n",s[i].birthday.day,s[i].birthday.month,s[i].birthday.year);
        //1-Science 2-Economics 3-Law 4-Arts :
        printf("-Department: ");
        if(s[i].department==1){printf("Science\n");}
        if(s[i].department==2){printf("Economics\n");}
        if(s[i].department==3){printf("Law\n");}
        if(s[i].department==4){printf("Arts\n");}
        printf("-General note: %02.2f\n",s[i].note);
    }
}

//6.Search
//6.1.Search student per last name
void search_name(Student student[]){

    char test[30],nbr=0;
    printf("Enter the last name of the student you are looking for :");
    scanf("%s",test);
    for(int i=0; i<studentnumber ;i++){
        if(strcasecmp(student[i].lastname,test)==0){
            nbr++;
        }
        }
    printf("==> There are %d students with the last name %s . \n",nbr,test);
    for(int i=0; i<studentnumber ;i++){
        if(strcasecmp(student[i].lastname,test)==0){
            printf("=================================\n");
            printf("-Id = %d \n",student[i].id);
            printf("-Last name: %s \n",student[i].lastname);
            printf("-First name: %s\n",student[i].firstname);
            printf("-Birthday: %02d-%02d-%4d\n",student[i].birthday.day,student[i].birthday.month,student[i].birthday.year);
             //1-Science 2-Economics 3-Law 4-Arts :
            printf("-Department: ");
            if(student[i].department==1){printf("Science\n");}
            if(student[i].department==2){printf("Economics\n");}
            if(student[i].department==3){printf("Law\n");}
            if(student[i].department==4){printf("Arts\n");}
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
    if(ndep_student(student,dep)==0){
        printf("==> The department is empty.\n");
        return;
    }
    if(dep==1){
        printf("==> The list of students in Science department:\n");}
    if(dep==2){
        printf("==> The list of students in Economics department:\n");}
    if(dep==3){
        printf("==> The list of students in Law department:\n");}
    if(dep==4){
        printf("==> The list of students in Arts department:\n");}

    for(int i=0;i<studentnumber;i++){
        if(student[i].department==dep){
            printf("=================================\n");
            printf("-Id = %d \n",student[i].id);
            printf("-Last name: %s \n",student[i].lastname);
            printf("-First name: %s\n",student[i].firstname);
            printf("-Birthday: %02d-%02d-%4d\n",student[i].birthday.day,student[i].birthday.month,student[i].birthday.year);
             //1-Science 2-Economics 3-Law 4-Arts :
            printf("-Department: ");
            if(student[i].department==1){printf("Science\n");}
            if(student[i].department==2){printf("Economics\n");}
            if(student[i].department==3){printf("Law\n");}
            if(student[i].department==4){printf("Arts\n");}
            printf("-General note: %02.2f\n",student[i].note);
        }
    }
}

//7.Sorting
//7.1.Alphabetic sort
void name_sort(Student student[]){

    Student temp;
    Student s[50];

    for(int k=0;k<studentnumber;k++){
            s[k]=student[k];
    }
    for(int i=0;i<studentnumber-1;i++){
        for(int j=0;j<studentnumber-i-1;j++){
            if(strcasecmp(s[j].lastname,s[j+1].lastname)>0){
                    temp=s[j];
                    s[j]=s[j+1];
                    s[j+1]=temp;
            }
        }
    }
        printf("Type the correspondent number: \n");
        printf("1-For Ascending order  (A to Z). \n");
        printf("2-For Descending order (Z to A). \n");
        int c;
        do{
        scanf("%d",&c);
        if(c!=1 && c!=2){
        printf("Invalid insertion, please try again: ");}
        }while(c!=1 && c!=2);

        if(c==1){
            for(int i=0;i<studentnumber;i++){
            printf("=================================\n");
            printf("-Id = %d \n",s[i].id);
            printf("-Last name: %s \n",s[i].lastname);
            printf("-First name: %s\n",s[i].firstname);
            printf("-Birthday: %02d-%02d-%4d\n",s[i].birthday.day,s[i].birthday.month,s[i].birthday.year);
             //1-Science 2-Economics 3-Law 4-Arts :
            printf("-Department: ");
            if(s[i].department==1){printf("Science\n");}
            if(s[i].department==2){printf("Economics\n");}
            if(s[i].department==3){printf("Law\n");}
            if(s[i].department==4){printf("Arts\n");}
            printf("-General note: %02.2f\n",s[i].note);
            }
        }
            if(c==2){
            for(int i=studentnumber-1;i>=0;i--){
            printf("=================================\n");
            printf("-Id = %d \n",s[i].id);
            printf("-Last name: %s \n",s[i].lastname);
            printf("-First name: %s\n",s[i].firstname);
            printf("-Birthday: %02d-%02d-%4d\n",s[i].birthday.day,s[i].birthday.month,s[i].birthday.year);
            //1-Science 2-Economics 3-Law 4-Arts :
            printf("-Department: ");
            if(s[i].department==1){printf("Science\n");}
            if(s[i].department==2){printf("Economics\n");}
            if(s[i].department==3){printf("Law\n");}
            if(s[i].department==4){printf("Arts\n");}
            printf("-General note: %02.2f\n",s[i].note);
            }
        }
}

//7.2.Note sorting
void note_sort(Student student[]){
    Student temp;
    Student s[50];

    for(int k=0;k<studentnumber;k++){
            s[k]=student[k];
    }
    for(int i=0;i<studentnumber-1;i++){
        for(int j=0;j<studentnumber-i-1;j++){
            if(s[j].note>s[j+1].note){
                    temp=s[j];
                    s[j]=s[j+1];
                    s[j+1]=temp;
            }
        }
    }
        printf("Type the correspondent number: \n");
        printf("1-For Ascending order (lowest to Highest). \n");
        printf("2-For Descending order (Highest to Lowest). \n");
        int c;
        do{
        scanf("%d",&c);
        if(c!=1 && c!=2){
        printf("Invalid insertion, please try again: \n");}
        }while(c!=1 && c!=2);
        printf("--- The sorted list by note ---\n");

        if(c==1){
            for(int i=0;i<studentnumber;i++){
            printf("=================================\n");
            printf("-Id = %d \n",s[i].id);
            printf("-Last name: %s \n",s[i].lastname);
            printf("-First name: %s\n",s[i].firstname);
            printf("-Birthday: %02d-%02d-%4d\n",s[i].birthday.day,s[i].birthday.month,s[i].birthday.year);
             //1-Science 2-Economics 3-Law 4-Arts :
            printf("-Department: ");
            if(s[i].department==1){printf("Science\n");}
            if(s[i].department==2){printf("Economics\n");}
            if(s[i].department==3){printf("Law\n");}
            if(s[i].department==4){printf("Arts\n");}
            printf("-General note: %02.2f\n",s[i].note);
            }
        }
        if(c==2){
            for(int i=studentnumber-1;i>=0;i--){
            printf("=================================\n");
            printf("-Id = %d \n",s[i].id);
            printf("-Last name: %s \n",s[i].lastname);
            printf("-First name: %s\n",s[i].firstname);
            printf("-Birthday: %02d-%02d-%4d\n",s[i].birthday.day,s[i].birthday.month,s[i].birthday.year);
              //1-Science 2-Economics 3-Law 4-Arts :
            printf("-Department: ");
            if(s[i].department==1){printf("Science\n");}
            if(s[i].department==2){printf("Economics\n");}
            if(s[i].department==3){printf("Law\n");}
            if(s[i].department==4){printf("Arts\n");}
            printf("-General note: %02.2f\n",s[i].note);
            }
        }
}

//7.3.Status sorting
void status_sorting(Student student[]){
    Student temp;
    Student s[50];

    for(int k=0;k<studentnumber;k++){
            s[k]=student[k];
    }
    for(int i=0;i<studentnumber-1;i++){
        for(int j=0;j<studentnumber-i-1;j++){
            if(s[j].note<s[j+1].note){
                    temp=s[j];
                    s[j]=s[j+1];
                    s[j+1]=temp;
            }
        }
    }
    printf("-- The sorted list of successful students --\n");
    for(int i=0;i<studentnumber;i++){
        if(s[i].note<10){
            break;
        }
        printf("=================================\n");
        printf("-Id = %d \n",s[i].id);
        printf("-Last name: %s \n",s[i].lastname);
        printf("-First name: %s\n",s[i].firstname);
        printf("-Birthday: %02d-%02d-%4d\n",s[i].birthday.day,s[i].birthday.month,s[i].birthday.year);
        //1-Science 2-Economics 3-Law 4-Arts :
        printf("-Department: ");
        if(s[i].department==1){printf("Science\n");}
        if(s[i].department==2){printf("Economics\n");}
        if(s[i].department==3){printf("Law\n");}
        if(s[i].department==4){printf("Arts\n");}
        printf("-General note: %02.2f\n",s[i].note);
    }
}

//automatically  adding students
void initial(Student student[]){

        //1st
        student[studentnumber].id = idcount+1;
        strcpy(student[studentnumber].lastname, "idrissi");
        strcpy(student[studentnumber].firstname, "hamid");
        student[studentnumber].note = 15.0;
        student[studentnumber].department=3;
        student[studentnumber].birthday.year = 2001;
        student[studentnumber].birthday.month = 4;
        student[studentnumber].birthday.day = 18;
        studentnumber++;
        idcount++;

        //2end
        student[studentnumber].id = idcount+1;
        strcpy(student[studentnumber].lastname, "benali");
        strcpy(student[studentnumber].firstname, "fatima");
        student[studentnumber].note = 18.0;
        student[studentnumber].department=1;
        student[studentnumber].birthday.year = 1997;
        student[studentnumber].birthday.month = 6;
        student[studentnumber].birthday.day = 23;
        studentnumber++;
        idcount++;

        //3rd
        student[studentnumber].id = idcount+1;
        strcpy(student[studentnumber].lastname, "zouhiri");
        strcpy(student[studentnumber].firstname, "youssef");
        student[studentnumber].note = 9.5;
        student[studentnumber].department=2;
        student[studentnumber].birthday.year = 2000;
        student[studentnumber].birthday.month = 3;
        student[studentnumber].birthday.day = 7;
        studentnumber++;
        idcount++;

        //4th
        student[studentnumber].id = idcount+1;
        strcpy(student[studentnumber].lastname, "ghazali");
        strcpy(student[studentnumber].firstname, "maryem");
        student[studentnumber].note = 4.0;
        student[studentnumber].department=4;
        student[studentnumber].birthday.year = 2005;
        student[studentnumber].birthday.month = 9;
        student[studentnumber].birthday.day = 29;
        studentnumber++;
        idcount++;

        //5th
        student[studentnumber].id = idcount+1;
        strcpy(student[studentnumber].lastname, "gassi");
        strcpy(student[studentnumber].firstname, "mouad");
        student[studentnumber].note = 13.5;
        student[studentnumber].department=4;
        student[studentnumber].birthday.year = 1990;
        student[studentnumber].birthday.month = 10;
        student[studentnumber].birthday.day = 15;
        studentnumber++;
        idcount++;

        //6th
        student[studentnumber].id = idcount+1;
        strcpy(student[studentnumber].lastname, "eddouch");
        strcpy(student[studentnumber].firstname, "ismail");
        student[studentnumber].note = 17.25;
        student[studentnumber].department=2;
        student[studentnumber].birthday.year = 2005;
        student[studentnumber].birthday.month = 9;
        student[studentnumber].birthday.day = 3;
        studentnumber++;
        idcount++;

        //7th
        student[studentnumber].id = idcount+1;
        strcpy(student[studentnumber].lastname, "hamouch");
        strcpy(student[studentnumber].firstname, "mohamed");
        student[studentnumber].note = 11.00;
        student[studentnumber].department=3;
        student[studentnumber].birthday.year = 2000;
        student[studentnumber].birthday.month = 7;
        student[studentnumber].birthday.day = 5;
        studentnumber++;
        idcount++;

        //8th
        student[studentnumber].id = idcount+1;
        strcpy(student[studentnumber].lastname, "reguig");
        strcpy(student[studentnumber].firstname, "hamza");
        student[studentnumber].note = 7.75;
        student[studentnumber].department=1;
        student[studentnumber].birthday.year = 2005;
        student[studentnumber].birthday.month = 8;
        student[studentnumber].birthday.day = 22;
        studentnumber++;
        idcount++;

        //9th
        student[studentnumber].id = idcount+1;
        strcpy(student[studentnumber].lastname, "dahir");
        strcpy(student[studentnumber].firstname, "zahra");
        student[studentnumber].note = 14.75;
        student[studentnumber].department=4;
        student[studentnumber].birthday.year = 1992;
        student[studentnumber].birthday.month = 11;
        student[studentnumber].birthday.day = 20;
        studentnumber++;
        idcount++;

        //10th
        student[studentnumber].id = idcount+1;
        strcpy(student[studentnumber].lastname, "moumen");
        strcpy(student[studentnumber].firstname, "ilyas");
        student[studentnumber].note = 10.00;
        student[studentnumber].department=3;
        student[studentnumber].birthday.year = 1997;
        student[studentnumber].birthday.month = 2;
        student[studentnumber].birthday.day = 11;
        studentnumber++;
        idcount++;


}
