#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPARTMENTS 5
#define MAX_COURSES 10
#define MAX_STUDENTS 50
#define MAX_NAME_LEN 50

typedef struct
{
    int studentID;
    char studentName[MAX_NAME_LEN];
} Student;

typedef struct
{
    int instructorID;
    char instructorName[MAX_NAME_LEN];
} Instructor;

typedef struct
{
    int courseID;
    char courseName[MAX_NAME_LEN];
    Instructor instructor;
    Student students[MAX_STUDENTS];
    int totalStudents;
} Course;

typedef struct
{
    char departmentName[MAX_NAME_LEN];
    Course courses[MAX_COURSES];
    int totalCourses;
} Department;

typedef struct
{
    Department departments[MAX_DEPARTMENTS];
    int totalDepartments;
} University;

University uni = {.totalDepartments = 0};

void addDepartment();
void addCourse();
void addInstructor();
void addStudent();
void displayDetails();
void computeEnrollment();

int main()
{
    int choice;

    while (1)
    {
        printf("\nUniversity Management System\n");
        printf("1. Add Department\n");
        printf("2. Add Course to Department\n");
        printf("3. Assign Instructor to Course\n");
        printf("4. Enroll Student in Course\n");
        printf("5. Display University Details\n");
        printf("6. Compute Total Enrollment\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            addDepartment();
            break;
        case 2:
            addCourse();
            break;
        case 3:
            addInstructor();
            break;
        case 4:
            addStudent();
            break;
        case 5:
            displayDetails();
            break;
        case 6:
            computeEnrollment();
            break;
        case 7:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void addDepartment()
{
    if (uni.totalDepartments >= MAX_DEPARTMENTS)
    {
        printf("Maximum number of departments reached.\n");
        return;
    }

    printf("Enter department name: ");
    fgets(uni.departments[uni.totalDepartments].departmentName, MAX_NAME_LEN, stdin);
    strtok(uni.departments[uni.totalDepartments].departmentName, "\n");
    
    uni.departments[uni.totalDepartments].totalCourses = 0;
    uni.totalDepartments++;

    printf("Department added successfully.\n");
}

void addCourse()
{
    if (uni.totalDepartments == 0)
    {
        printf("No departments available. Please add a department first.\n");
        return;
    }

    int deptIndex;
    printf("Select a department:\n");
    for (int i = 0; i < uni.totalDepartments; i++)
    {
        printf("%d. %s\n", i + 1, uni.departments[i].departmentName);
    }
    printf("Enter your choice: ");
    scanf("%d", &deptIndex);
    getchar();

    if (deptIndex < 1 || deptIndex > uni.totalDepartments)
    {
        printf("Invalid department choice.\n");
        return;
    }

    deptIndex--;
    if (uni.departments[deptIndex].totalCourses >= MAX_COURSES)
    {
        printf("Maximum number of courses reached for this department.\n");
        return;
    }

    int courseIndex = uni.departments[deptIndex].totalCourses;
    printf("Enter course ID: ");
    scanf("%d", &uni.departments[deptIndex].courses[courseIndex].courseID);
    getchar();
    
    printf("Enter course name: ");
    fgets(uni.departments[deptIndex].courses[courseIndex].courseName, MAX_NAME_LEN, stdin);
    strtok(uni.departments[deptIndex].courses[courseIndex].courseName, "\n");
    uni.departments[deptIndex].courses[courseIndex].totalStudents = 0;
    uni.departments[deptIndex].totalCourses++;

    printf("Course added successfully.\n");
}

void addInstructor()
{
    if (uni.totalDepartments == 0)
    {
        printf("No departments available. Please add a department first.\n");
        return;
    }

    int deptIndex, courseIndex;
    printf("Select a department:\n");
    for (int i = 0; i < uni.totalDepartments; i++)
    {
        printf("%d. %s\n", i + 1, uni.departments[i].departmentName);
    }
    printf("Enter your choice: ");
    scanf("%d", &deptIndex);
    getchar();

    if (deptIndex < 1 || deptIndex > uni.totalDepartments)
    {
        printf("Invalid department choice.\n");
        return;
    }

    deptIndex--;
    if (uni.departments[deptIndex].totalCourses == 0)
    {
        printf("No courses available in this department.\n");
        return;
    }

    printf("Select a course:\n");
    for (int i = 0; i < uni.departments[deptIndex].totalCourses; i++)
    {
        printf("%d. %s\n", i + 1, uni.departments[deptIndex].courses[i].courseName);
    }
    printf("Enter your choice: ");
    scanf("%d", &courseIndex);
    getchar();

    if (courseIndex < 1 || courseIndex > uni.departments[deptIndex].totalCourses)
    {
        printf("Invalid course choice.\n");
        return;
    }

    courseIndex--;
    printf("Enter instructor ID: ");
    scanf("%d", &uni.departments[deptIndex].courses[courseIndex].instructor.instructorID);
    getchar();
   
    printf("Enter instructor name: ");
    fgets(uni.departments[deptIndex].courses[courseIndex].instructor.instructorName, MAX_NAME_LEN, stdin);
    strtok(uni.departments[deptIndex].courses[courseIndex].instructor.instructorName, "\n");

    printf("Instructor assigned successfully.\n");
}

// Enroll a student in a course
void addStudent()
{
    if (uni.totalDepartments == 0)
    {
        printf("No departments available. Please add a department first.\n");
        return;
    }

    int deptIndex, courseIndex;
    printf("Select a department:\n");
    for (int i = 0; i < uni.totalDepartments; i++)
    {
        printf("%d. %s\n", i + 1, uni.departments[i].departmentName);
    }
    printf("Enter your choice: ");
    scanf("%d", &deptIndex);
    getchar();

    if (deptIndex < 1 || deptIndex > uni.totalDepartments)
    {
        printf("Invalid department choice.\n");
        return;
    }

    deptIndex--;
    if (uni.departments[deptIndex].totalCourses == 0)
    {
        printf("No courses available in this department.\n");
        return;
    }

    printf("Select a course:\n");
    for (int i = 0; i < uni.departments[deptIndex].totalCourses; i++)
    {
        printf("%d. %s\n", i + 1, uni.departments[deptIndex].courses[i].courseName);
    }
    printf("Enter your choice: ");
    scanf("%d", &courseIndex);
    getchar();

    if (courseIndex < 1 || courseIndex > uni.departments[deptIndex].totalCourses)
    {
        printf("Invalid course choice.\n");
        return;
    }

    courseIndex--;
    if (uni.departments[deptIndex].courses[courseIndex].totalStudents >= MAX_STUDENTS)
    {
        printf("Maximum number of students reached for this course.\n");
        return;
    }

    int studentIndex = uni.departments[deptIndex].courses[courseIndex].totalStudents;
    printf("Enter student ID: ");
    scanf("%d", &uni.departments[deptIndex].courses[courseIndex].students[studentIndex].studentID);
    getchar();
    
    printf("Enter student name: ");
    fgets(uni.departments[deptIndex].courses[courseIndex].students[studentIndex].studentName, MAX_NAME_LEN, stdin);
    strtok(uni.departments[deptIndex].courses[courseIndex].students[studentIndex].studentName, "\n");

    uni.departments[deptIndex].courses[courseIndex].totalStudents++;
    printf("Student enrolled successfully.\n");
}

void displayDetails()
{
    if (uni.totalDepartments == 0)
    {
        printf("No departments available.\n");
        return;
    }

    for (int i = 0; i < uni.totalDepartments; i++)
    {
        printf("\nDepartment: %s\n", uni.departments[i].departmentName);
        for (int j = 0; j < uni.departments[i].totalCourses; j++)
        {
            printf("  Course: %s (ID: %d)\n", uni.departments[i].courses[j].courseName,uni.departments[i].courses[j].courseID);
            printf("    Instructor: %s (ID: %d)\n", uni.departments[i].courses[j].instructor.instructorName, uni.departments[i].courses[j].instructor.instructorID);
            printf("    Students Enrolled: %d\n", uni.departments[i].courses[j].totalStudents);
            
            for (int k = 0; k < uni.departments[i].courses[j].totalStudents; k++)
            {
                printf("      %d. %s (ID: %d)\n", k + 1, uni.departments[i].courses[j].students[k].studentName, uni.departments[i].courses[j].students[k].studentID);
            }
        }
    }
}

void computeEnrollment()
{
    if (uni.totalDepartments == 0)
    {
        printf("No departments available.\n");
        return;
    }

    for (int i = 0; i < uni.totalDepartments; i++)
    {
        int totalEnrollment = 0;
        for (int j = 0; j < uni.departments[i].totalCourses; j++)
        {
            totalEnrollment += uni.departments[i].courses[j].totalStudents;
        }
        printf("Total enrollment in department '%s': %d\n", uni.departments[i].departmentName, totalEnrollment);
    }
}
