#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//structure defination
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

// int adaptWeight(int currentResponse, int previousResponse, int weight)
// {
//     // Adjust weight based on change in response
//     if (currentResponse != previousResponse)
//     {
//         weight += 1; // Increase weight by 1 for adaptive scoring
//     }
//     return weight;
// }

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
    printf("Enter your first name : ");
    scanf("%s", name);
    sprintf(filename, "%s.html", name);
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
    fprintf(file, "<h2 style=\"text-align: center;\">CAREWELL HOSPITAL</h2>\n");
    fprintf(file, "<h4 style=\"text-align: center;\">Lokanthali, Bhaktapur</h4>\n");
    fprintf(file, "<hr>\n");
    fprintf(file, "<h4 style=\"text-align: center;\">****REPORT CARD****</h4>\n\n");
    fprintf(file, "<ul><ul><ul><ul>\n");
    fprintf(file, "<p>TEST PERFORMED : <b>OCD</b> (Obsessive Compulsive Disorder)</p>\n");
    fprintf(file, "<p>DATE : %s</p>\n", __DATE__);
    fprintf(file, "<p>TIME : %s</p>\n", __TIME__);

    printf("\nLets start-- \n\n");
    //questions 
    Question questions[] = {
        {"Q1) I often have repetitive and intrusive thoughts that I find difficult to control.", 2},
        {"Q2) I feel a strong urge to perform certain actions or rituals repeatedly.", 3},
        {"Q3) I have difficulties in making decisions due to excessive doubts and concerns.", 2},
        {"Q4) I spend a lot of time checking or ensuring things are done correctly or perfectly.", 3},
        {"Q5) I have a fear of contamination or getting sick and engage in excessive cleaning or washing.", 3},
        {"Q6) I experience distress when things are not arranged symmetrically or in a specific order.", 2},
        {"Q7) I find it hard to discard or throw away items that may seem useless or have no value.", 2},
        {"Q8) I feel a need to confess or seek reassurance excessively about my thoughts or actions.", 3},
        {"Q9) I have difficulties completing tasks due to repeating or redoing them multiple times.", 2},
        {"Q10) I experience intrusive, unwanted thoughts or mental images that go against my values.", 2}};
    

    int numQuestions = sizeof(questions) / sizeof(questions[0]);

    int totalScore = 0;
    int previousResponse = -1; // Initialize previous response with an invalid value

    fprintf(file, "<h4>NAME : %s</h4>\n", name);
    int i;
    for ( i = 0; i < numQuestions; i++)
    {
        int currentResponse = askQuestion(questions[i]);

        // questions[i].weight = adaptWeight(currentResponse, previousResponse, questions[i].weight);

        totalScore += currentResponse * questions[i].weight;

        previousResponse = currentResponse;

        // Write question and response to the file
//        fprintf(file, "<p>%s</p>\n", questions[i].question);
//        fprintf(file, "<p>Response: %d</p>\n", currentResponse);
    }
    printf("Score level: \n 0-24 --Zero to No OCD \n 24-48 --Mild Symptoms of OCD \n 48-72 --Moderate Symptoms of OCD \n 72-96 --Severe Symptoms of OCD \n >96 --Extreme Symptoms of OCD \n\n");
    printf("Your score =  %d\n\n", totalScore);
    // Write the score level and total score to the file
    fprintf(file, "<h4>Score level :</h4>\n");
    fprintf(file,"<ul>\n");
    fprintf(file, "<li>00-24 -- Zero to No OCD</li>\n<br>");
    fprintf(file, "<li>24-48 -- Mild Symptoms of OCD</li>\n<br>");
    fprintf(file, "<li>48-72 -- Moderate Symptoms of OCD</li>\n<br>");
    fprintf(file, "<li>72-96 -- Severe Symptoms of OCD</li>\n<br>");
    fprintf(file, "<li> > 96 -- Extreme Symptoms of OCD</li>\n<br>");
    fprintf(file,"</ul>\n");
    fprintf(file, "<h4>Your score: %d</h4>\n", totalScore);
        
     if (totalScore > 24 && totalScore < 48)
    {
        printf("You may be experiencing mild symptoms of OCD.\n\n");
        printf("\tConsult to a Doctor\n\n");
        printf("Some advices : \n\n");
        printf("1. Psychoeducation: Learn about OCD, its causes, and treatment options to gain a better understanding of the condition.\n\n");
        printf("2.Practice exposure and response prevention (ERP): Gradually expose yourself to triggering situations or thoughts while refraining from engaging in compulsive behaviors.\n\n");
        printf("3.Seek therapy: Consider engaging in cognitive-behavioral therapy (CBT) or other evidence-based therapies to address OCD symptoms.\n\n");
        fprintf(file, "<p>You may be experiencing mild symptoms of OCD.</p>\n");
        fprintf(file, "<p>Consult a Doctor</p>\n");
        fprintf(file, "<p>Some advice:</p>\n");
        fprintf(file, "<ol>\n");
        fprintf(file, "<li>Psychoeducation: Learn about OCD, its causes, and treatment options to gain a better understanding of the condition.</li>\n");
        fprintf(file, "<li>Practice exposure and response prevention (ERP): Gradually expose yourself to triggering situations or thoughts while refraining from engaging in compulsive behaviors.</li>\n");
        fprintf(file, "<li>Seek therapy: Consider engaging in cognitive-behavioral therapy (CBT) or other evidence-based therapies to address OCD symptoms.</li>\n");
        fprintf(file, "</ol>\n");
    }
    else if (totalScore > 48 && totalScore < 72)
    {
        printf("You may be experiencing Moderate symptoms of OCD.\n\n");
        printf("\tConsult to a Doctor\n\n");
        printf("Some advices : \n\n");
        printf("1. Medication evaluation: Discuss with a healthcare professional the potential benefits of medication as part of your treatment plan.\n\n");
        printf("2.Stress management techniques: Explore stress reduction techniques such as deep breathing exercises, relaxation exercises, or meditation. \n\n");
        printf("3. Maintain a healthy lifestyle: Ensure regular exercise, sufficient sleep, and a balanced diet to support overall well-being.\n");
        fprintf(file, "<p>You may be experiencing moderate symptoms of OCD.</p>\n");
        fprintf(file, "<p>Consult a Doctor</p>\n");
        fprintf(file, "<p>Some advice:</p>\n");
        fprintf(file, "<ol>\n");
        fprintf(file, "<li>Medication evaluation: Discuss with a healthcare professional the potential benefits of medication as part of your treatment plan.</li>\n");
        fprintf(file, "<li>Stress management techniques: Explore stress reduction techniques such as deep breathing exercises, relaxation exercises, or meditation.</li>\n");
        fprintf(file, "<li>Maintain a healthy lifestyle: Ensure regular exercise, sufficient sleep, and a balanced diet to support overall well-being.</li>\n");
        fprintf(file, "</ol>\n");
    }
    else if (totalScore > 72 && totalScore < 96)
    {
        printf("You may be experiencing Severe symptoms of OCD.\n\n");
        printf("\tConsult to a Doctor\n\n");
        printf("Some advices : \n\n");
        printf("1.Comprehensive treatment: Seek professional help from experienced mental health specialists who specialize in treating severe OCD.\n");
        printf("2.Intensive therapy: Consider participating in intensive outpatient programs or residential treatment centers that offer focused and immersive OCD treatment. \n");
        printf("3.Involve family and loved ones: Educate and involve family members in treatment to provide support and help with managing OCD symptoms\n");
        fprintf(file, "<p>You may be experiencing severe symptoms of OCD.</p>\n");
        fprintf(file, "<p>Consult a Doctor</p>\n");
        fprintf(file, "<p>Some advice:</p>\n");
        fprintf(file, "<ol>\n");
        fprintf(file, "<li>Comprehensive treatment: Seek professional help from experienced mental health specialists who specialize in treating severe OCD.</li>\n");
        fprintf(file, "<li>Intensive therapy: Consider participating in intensive outpatient programs or residential treatment centers that offer focused and immersive OCD treatment.</li>\n");
        fprintf(file, "<li>Involve family and loved ones: Educate and involve family members in treatment to provide support and help with managing OCD symptoms.</li>\n");
        fprintf(file, "</ol>\n");
    }
    else if (totalScore > 96)
    {
        printf("You may be experiencing Extreme symptoms of OCD.\n\n");
        printf("\tConsult to a Doctor\n\n");
        printf("Some advices : \n\n");
        printf("1.Seek specialized care: Consult with experts in OCD treatment, such as OCD specialists or renowned treatment centers, who have experience in treating severe and complex cases.\n");
        printf("2.Consider hospitalization: In some cases, hospitalization might be necessary to ensure safety, provide intensive treatment, and stabilize symptoms.\n");
        printf("3.Explore alternative treatment options: Investigate innovative treatments like deep brain stimulation (DBS) or transcranial magnetic stimulation (TMS), which may be considered in extreme cases.\n");
        fprintf(file, "<p>You may be experiencing extreme symptoms of OCD.</p>\n");
        fprintf(file, "<p>Consult a Doctor</p>\n");
        fprintf(file, "<p>Some advice:</p>\n");
        fprintf(file, "<ol>\n");
        fprintf(file, "<li>Seek specialized care: Consult with experts in OCD treatment, such as OCD specialists or renowned treatment centers, who have experience in treating severe and complex cases.</li>\n");
        fprintf(file, "<li>Consider hospitalization: In some cases, hospitalization might be necessary to ensure safety, provide intensive treatment, and stabilize symptoms.</li>\n");
        fprintf(file, "<li>Explore alternative treatment options: Investigate innovative treatments like deep brain stimulation (DBS) or transcranial magnetic stimulation (TMS), which may be considered in extreme cases.</li>\n");
        fprintf(file, "</ol>\n");
    }
    else
    {
        printf("\t\tYou do not seem to display significant symptoms of OCD.\n\n");
        printf("Some advices : \n\n");
        printf("1.Maintain awareness: Stay vigilant about any emerging symptoms and changes in thoughts or behaviors.\n");
        printf("2.Practice self-care: Engage in activities that promote relaxation, stress reduction, and overall well-being. \n");
        printf("3.Develop healthy strategies to manage stress and anxiety, such as exercise, mindfulness, or hobbies\n");
        fprintf(file, "<p>You do not seem to display significant symptoms of OCD.</p>\n");
        fprintf(file, "<p>Some advice:</p>\n");
        fprintf(file, "<ol>\n");
        fprintf(file, "<li>Maintain awareness: Stay vigilant about any emerging symptoms and changes in thoughts or behaviors.</li>\n");
        fprintf(file, "<li>Practice self-care: Engage in activities that promote relaxation, stress reduction, and overall well-being.</li>\n");
        fprintf(file, "<li>Develop healthy strategies to manage stress and anxiety, such as exercise, mindfulness, or hobbies.</li>\n");
        fprintf(file, "</ol>\n");
    }

    fprintf(file, "<p>**Note that these recommendations should be customized to fit each person's requirements and circumstances. \nBased on a comprehensive evaluation, a licensed mental health professional can offer tailored recommendations and advice.**</p>\n");

    fprintf(file, "<p text-align: center>Have a good day!</p>\n");
    fprintf(file, "</body>\n</html>");

    // Close the file
    fclose(file);


    return 0;
}

