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
    
    
    // bound to the option only
    A:
	scanf("%d", &response);
    if (response >  4|| response < 0){
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
	//for holding and clearing screen
	system("pause");
	system("cls");
	
    
    // Generate unique filename using timestamp
    time_t current_time = time(NULL);
    char filename[100];
    char name[100];
    printf("Enter your name : ");
    scanf("%s",name);
    strcpy(filename,name);
    sprintf(filename, "%s.doc", filename);
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
    
    fprintf(file,"\n\n\t\t\t\t\tCAREWELL HOSPITAL\n\n");
    fprintf(file,"\t\t\t\t\t    lokanthali,\n");
    fprintf(file,"\t\t\t\t\t    bhaktapur\n");
    fprintf(file,"________________________________________________________________________\n\n");
    fprintf(file,"\n\t\t\t\t\t*****REPORT CARD***** \n\n");
    fprintf(file,"\n\nTEST PERFORMED: OCD (Obsessive Compulsive Disorder)");
    fprintf(file,"\n\nDATE: %s", __DATE__);
    fprintf(file,"\n\nTIME: %s\n\n", __TIME__);
    
    printf("\nLets start-- \n\n");
    
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
    
    	fprintf(file,"NAME: %s \n \n",name);
    	
    for (int i = 0; i < numQuestions; i++)
    {
        int currentResponse = askQuestion(questions[i]);
        
        questions[i].weight = adaptWeight(currentResponse, previousResponse, questions[i].weight);
        
        totalScore += currentResponse * questions[i].weight;
        
        previousResponse = currentResponse;
        
        //report generation
	
//       fprintf(file, "%s \n Weight = %d, Your Response = %d, Question score = %d\n", questions[i].question, questions[i].weight, currentResponse, currentResponse * questions[i].weight);
 //    fprintf(file, "------------------------------------------------------\n");
    }
	
	printf("Score level: \n 0-24 --Zero to No OCD \n 24-48 --Mild Symptoms of OCD \n 48-72 --Moderate Symptoms of OCD \n 72-96 --Severe Symptoms of OCD \n >96 --Extreme Symptoms of OCD \n\n");
	fprintf(file, "Score level: \n 0-24 --Zero to No OCD \n 24-48 --Mild Symptoms of OCD \n 48-72 --Moderate Symptoms of OCD \n 72-96 --Severe Symptoms of OCD \n >96 --Extreme Symptoms of OCD \n\n");

	
	printf("Your score =  %d\n\n", totalScore);
	fprintf(file,"Your score = %d\n\n",totalScore);

if (totalScore > 24 && totalScore < 48)
    {
        printf("You may be experiencing mild symptoms of OCD.\n\n");
        printf("\tConsult to a Doctor\n\n");
        printf("Some advices : \n\n");
        printf("1. Psychoeducation: Learn about OCD, its causes, and treatment options to gain a better understanding of the condition.\n\n");
        printf("2.Practice exposure and response prevention (ERP): Gradually expose yourself to triggering situations or thoughts while refraining from engaging in compulsive behaviors.\n\n");
        printf("3.Seek therapy: Consider engaging in cognitive-behavioral therapy (CBT) or other evidence-based therapies to address OCD symptoms.\n\n");
        fprintf(file,"\t\tYou may be experiencing mild symptoms of OCD.\n\n");
        fprintf(file,"\t\tConsult to a Doctor\n\n");
        fprintf(file,"Some advices: \n\n");
        fprintf(file,"1.Psychoeducation: Learn about OCD, its causes, and treatment options to gain a better understanding of the condition.\n\n");
        fprintf(file,"2.Practice exposure and response prevention (ERP): Gradually expose yourself to triggering situations or thoughts while refraining from engaging in compulsive behaviors. \n\n");
        fprintf(file,"3. Seek therapy: Consider engaging in cognitive-behavioral therapy (CBT) or other evidence-based therapies to address OCD symptoms.\n\n\n");
        
    }
    else if(totalScore > 48 && totalScore <72){
    	printf("You may be experiencing Moderate symptoms of OCD.\n\n");
        printf("\tConsult to a Doctor\n\n");
        printf("Some advices : \n\n");
        printf("1. Medication evaluation: Discuss with a healthcare professional the potential benefits of medication as part of your treatment plan.\n\n");
        printf("2.Stress management techniques: Explore stress reduction techniques such as deep breathing exercises, relaxation exercises, or meditation. \n\n");
        printf("3. Maintain a healthy lifestyle: Ensure regular exercise, sufficient sleep, and a balanced diet to support overall well-being.\n");
        fprintf(file,"\t\tYou may be experiencing Moderate symptoms of OCD.\n\n");
        fprintf(file,"\t\tConsult to a Doctor\n\n");
        fprintf(file,"Some advices: \n\n");
        fprintf(file,"1.Medication evaluation: Discuss with a healthcare professional the potential benefits of medication as part of your treatment plan.\n\n");
        fprintf(file,"2. Stress management techniques: Explore stress reduction techniques such as deep breathing exercises, relaxation exercises, or meditation. \n\n");
        fprintf(file,"3.Maintain a healthy lifestyle: Ensure regular exercise, sufficient sleep, and a balanced diet to support overall well-being.\n\n\n");
        
    	
	}
else if(totalScore > 72 && totalScore < 96){
    	printf("You may be experiencing Severe symptoms of OCD.\n\n");
        printf("\tConsult to a Doctor\n\n");
        printf("Some advices : \n\n");
        printf("1.Comprehensive treatment: Seek professional help from experienced mental health specialists who specialize in treating severe OCD.\n");
        printf("2.Intensive therapy: Consider participating in intensive outpatient programs or residential treatment centers that offer focused and immersive OCD treatment. \n");
        printf("3.Involve family and loved ones: Educate and involve family members in treatment to provide support and help with managing OCD symptoms\n");
        fprintf(file,"\t\tYou may be experiencing Severe symptoms of OCD.\n\n");
        fprintf(file,"\t\tConsult to a Doctor\n\n");
        fprintf(file,"Some advices: \n\n");
        fprintf(file,"1.Comprehensive treatment: Seek professional help from experienced mental health specialists who specialize in treating severe OCD.\n\n");
        fprintf(file,"2.Intensive therapy: Consider participating in intensive outpatient programs or residential treatment centers that offer focused and immersive OCD treatment.\n\n");
        fprintf(file,"3.Involve family and loved ones: Educate and involve family members in treatment to provide support and help with managing OCD symptoms\n\n\n");
        
    	
	}
    else if(totalScore>96)
    {
        printf("You may be experiencing Extreme symptoms of OCD.\n\n");
        printf("\tConsult to a Doctor\n\n");
        printf("Some advices : \n\n");
        printf("1.Seek specialized care: Consult with experts in OCD treatment, such as OCD specialists or renowned treatment centers, who have experience in treating severe and complex cases.\n");
        printf("2.Consider hospitalization: In some cases, hospitalization might be necessary to ensure safety, provide intensive treatment, and stabilize symptoms.\n");
        printf("3.Explore alternative treatment options: Investigate innovative treatments like deep brain stimulation (DBS) or transcranial magnetic stimulation (TMS), which may be considered in extreme cases.\n");
        fprintf(file,"\t\tYou may be experiencing Extreme symptoms of OCD.\n\n");
        fprintf(file,"\t\tConsult to a Doctor\n\n");
        fprintf(file,"Some advices: \n\n");
        fprintf(file,"1.Seek specialized care: Consult with experts in OCD treatment, such as OCD specialists or renowned treatment centers, who have experience in treating severe and complex cases.\n");
        fprintf(file,"2.Consider hospitalization: In some cases, hospitalization might be necessary to ensure safety, provide intensive treatment, and stabilize symptoms. \n");
        fprintf(file,"3.Explore alternative treatment options: Investigate innovative treatments like deep brain stimulation (DBS) or transcranial magnetic stimulation (TMS), which may be considered in extreme cases.\n\n\n");;
       
    }
    else{
    	printf("\t\tYou do not seem to display significant symptoms of OCD.\n\n");
        fprintf(file,"\t\tYou do not seem to display significant symptoms of OCD.\n\n");
         printf("Some advices : \n\n");
        printf("1.Maintain awareness: Stay vigilant about any emerging symptoms and changes in thoughts or behaviors.\n");
        printf("2.Practice self-care: Engage in activities that promote relaxation, stress reduction, and overall well-being. \n");
        printf("3.Develop healthy strategies to manage stress and anxiety, such as exercise, mindfulness, or hobbies\n");
        fprintf(file,"\t\tYYou do not seem to display significant symptoms of OCD.\n\n");
        fprintf(file,"Some advices: \n\n");
        fprintf(file,"1.Maintain awareness: Stay vigilant about any emerging symptoms and changes in thoughts or behaviors.\n");
        fprintf(file,"2.Practice self-care: Engage in activities that promote relaxation, stress reduction, and overall well-being. \n");
        fprintf(file,"3.Develop healthy strategies to manage stress and anxiety, such as exercise, mindfulness, or hobbies\n");
	}
	printf("\n\n**Note that these recommendations should be customized to fit each person's requirements and circumstances. \nBased on a comprehensive evaluation, a licensed mental health professional can offer tailored recommendations and advice.**\n");
fprintf(file,"Note : **Note that these recommendations should be customized to fit each person's requirements and circumstances. \n\nBased on a comprehensive evaluation, a licensed mental health professional can offer tailored recommendations and advice.**\n");
    printf("\n\n\t\t\t\tHave a good day");
    fprintf(file,"\n\n\t\t\t\tHave a good day");
	
    // Close the file
    fclose(file);

    return 0;
}
