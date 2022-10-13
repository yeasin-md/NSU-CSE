#include <stdio.h>

int main()
{
    ////////////====== scenario_1 :: Marks=====///////////
    int mark;
    printf("What's your mark in Maths? \n");
    scanf("%d", &mark);
    if (mark >= 33 && mark <= 59)
    {
        printf("Owh you are pass, try for A+");
    }
    else if (mark >= 60 && mark <= 69)
    {
        printf("You obtained A-");
    }
    else if (mark >= 70 && mark <= 79)
    {
        printf("You just missed A+, btw A is good!");
    }
    else if (mark >= 80 && mark <= 100)
    {
        printf("Congrats for getting A+ !");
    }

    ///////=====Scenario-2 :: GPA Result========////////
    float gpa;
    printf("\nWhat's your GPA btw?\n");
    scanf("%f", &gpa);
    if (gpa == 0)
    {
        printf("Sorry for result");
    }
    else if (gpa >= 3 && gpa < 4)
    {
        printf("%0.2f is a good result", gpa);
    }
    else if (gpa >= 4 && gpa <= 5)
    {
        printf("%0.2f is an excellent result", gpa);
    }

    ///////=====Scenario-3 :: Age========////////
    int age;
    printf("\nWhat's your age?\n");
    scanf("%d", &age);

    if (age >= 0 && age < 5)
    {
        printf("Infant");
    }
    else if (age > 5 && age <= 12)
    {
        printf("Childhood");
    }
    else if (age > 12 && age < 20)
    {
        printf("Teenage");
    }
    else if (age > 20)
    {
        printf("Adult");
    }

    ///////=====Scenario-4 :: BMI========////////
    float weight, height;
    printf("\nWhat's your weight in kg?");
    scanf("%f", &weight);
    printf("What's your height in foot?");
    scanf("%f", &height);
    float bmi = weight / ((height * 0.3048) * (height * 0.3048));

    if (bmi <= 18)
    {
        printf("Your BMI: %.2f is UnderWeight", bmi);
    }
    else if (bmi > 18 && bmi <= 25)
    {
        printf("Your BMI: %.2f is Normal", bmi);
    }
    else if (bmi > 25 && bmi <= 30)
    {
        printf("Your BMI: %.2f, You are getting fat. Go for exercises.", bmi);
    }
    else if (bmi > 30)
    {
        printf("Your BMI: %.2f, Obesity", bmi);
    }

    return 0;
}