#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct
{
    char question[200];
    int weight;
} Question;

int askQuestion(Question q)
{
    int response;
    printf("------------------------------------------------------\n");
    printf("%s\n", q.question);
    printf("0) NEVER \t 1) SOMETIMES \t 2) OFTEN \t 3) VERY OFTEN \t 4) ALWAYS\n");
    printf("Enter your response (0-4): ");
    A:
    scanf("%d", &response);
    if (response >  4 || response < 0){
        printf("invalid input , please choose from the above option \n ");
        goto A;
    }
    printf("------------------------------------------------------\n\n");
    system("cls");
    return response;
}

int adaptWeight(int currentResponse, int previousResponse, int weight)
{
    // Adjust weight based on change in response
    if (currentResponse != previousResponse)
    {
        weight += 1; // Increase weight by 1 for adaptive scoring
    }
    return weight;
}

int main()
{
    printf("\n\n\t\t\t\t\t\t-----WELCOME TO THE TEST-----\n\n");
    printf("\n\t\t\t\t\t\t\t***DISCLAIMER***\n\n\n\t\t\t\t\t*This quiz is NOT a diagnostic tool* \n\n \t\t\t\t\tMental health disorders can only be diagnosed by licensed health care professionals.\n\n\n");
    printf("\n\t\t\t\t\tWhat Does This Test Consist Of?\n\n");
    printf("\t\t\t\t\t-> Ten questions that relate to common thoughts and behaviors experienced by those \n\n\t\t\t\t\tdiagnosed with obsessive compulsive disorder (OCD).\n\n");
    system("pause");
    system("cls");
    
    // Generate unique filename using timestamp
    time_t current_time = time(NULL);
    char filename[100];
    char name[100];
    printf("Enter your name : ");
    scanf("%s",name);
    strcpy(filename,name);
    sprintf(filename, "%s.html", filename);
    printf("\nLets start-- \n\n");
    system("pause");
    printf("\nLets start-- \n\n");
    system("cls");

    // Open the file in write mode
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Write the HTML content to the file
    fprintf(file, "<!DOCTYPE html>\n");
    fprintf(file, "<html>\n<head>\n<title>%s - OCD Test Report</title>\n</head>\n<body>\n", name);

    fprintf(file, "<h1 style=\"text-align: center;\">CAREWELL HOSPITAL</h1>\n");
    fprintf(file, "<p style=\"text-align: center;\">lokanthali, bhaktapur</p>\n");
    fprintf(file, "<hr>\n");
    fprintf(file, "<h2 style=\"text-align: center;\">REPORT CARD</h2>\n");

    fprintf(file, "<p>TEST PERFORMED: OCD (Obsessive Compulsive Disorder)</p>\n");
    fprintf(file, "<p>DATE: %s</p>\n", __DATE__);
    fprintf(file, "<p>TIME: %s</p>\n", __TIME__);

    printf("\nLets start-- \n\n");
    
    Question questions[] = {
        {"Q1) I often have repetitive and intrusive thoughts that I find difficult to control.", 2},
        {"Q2) I feel a strong urge to perform certain actions or rituals repeatedly.", 3},
        // ... (Rest of the questions)
    };

    int numQuestions = sizeof(questions) / sizeof(questions[0]);

    int totalScore = 0;
    int previousResponse = -1; // Initialize previous response with an invalid value

    fprintf(file, "<h3>NAME: %s</h3>\n", name);

    for (int i = 0; i < numQuestions; i++)
    {
        int currentResponse = askQuestion(questions[i]);

        questions[i].weight = adaptWeight(currentResponse, previousResponse, questions[i].weight);

        totalScore += currentResponse * questions[i].weight;

        previousResponse = currentResponse;

        // Write question and response to the file
        fprintf(file, "<p>%s</p>\n", questions[i].question);
        fprintf(file, "<p>Response: %d</p>\n", currentResponse);

        // ...
    }

    // Write the score level and total score to the file
    fprintf(file, "<p>Score level:</p>\n");
    fprintf(file, "<p>0-24: Zero to No OCD</p>\n");
    fprintf(file, "<p>24-48: Mild Symptoms of OCD</p>\n");
    // ... (Rest of the score levels)
    fprintf(file, "<p>Your score: %d</p>\n", totalScore);

    // ... (Rest of the advice and closing tags)
    fprintf(file, "</body>\n</html>");

    printf("Your score =  %d\n\n", totalScore);
    
    printf("\n\n**Note that these recommendations should be customized to fit each person's requirements and circumstances. \nBased on a comprehensive evaluation, a licensed mental health professional can offer tailored recommendations and advice.**\n");

    // Close the file
    fclose(file);

    return 0;
}
