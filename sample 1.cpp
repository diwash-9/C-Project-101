#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    printf("1) NEVER \t 2) SOMETIMES \t 3) OFTEN \t 4) VERY OFTEN \t 5) ALWAYS\n");
    printf("Enter your response (1-5): ");
    
    // bound to the option only
    A:
	scanf("%d", &response);
    if (response > 5 || response < 1){
    	printf("invalid input , please choose from the above option \n ");
    	goto A;
	}

    printf("------------------------------------------------------\n\n");
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
	char name[30];
	char gender[10];
	int age;

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
    printf("enter the file name : ");
    scanf("%s",filename);
    sprintf(filename, "%s.doc", filename);

    // Open the file in write mode
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return 1;
    }
    
    fprintf(file,"\n\n\t\t\t\t*****REPORT CARD***** \n\n");
    fprintf(file,"\n\ntest performed = OCD (obsessive compulsive disorder)");
    fprintf(file,"\n\nDATE: %s", __DATE__);
    fprintf(file,"\n\nTIME: %s\n\n", __TIME__);
    
    printf("\nlets start-- \n\n");
    
    Question questions[] = {
        {"Q) I often have repetitive and intrusive thoughts that I find difficult to control.", 2},
        {"Q) I feel a strong urge to perform certain actions or rituals repeatedly.", 3},
        {"Q) I have difficulties in making decisions due to excessive doubts and concerns.", 2},
        {"Q) I spend a lot of time checking or ensuring things are done correctly or perfectly.", 3},
        {"Q) I have a fear of contamination or getting sick and engage in excessive cleaning or washing.", 3},
        {"Q) I experience distress when things are not arranged symmetrically or in a specific order.", 2},
        {"Q) I find it hard to discard or throw away items that may seem useless or have no value.", 2},
        {"Q) I feel a need to confess or seek reassurance excessively about my thoughts or actions.", 3},
        {"Q) I have difficulties completing tasks due to repeating or redoing them multiple times.", 2},
        {"Q) I experience intrusive, unwanted thoughts or mental images that go against my values.", 2}};

    int numQuestions = sizeof(questions) / sizeof(questions[0]);

    int totalScore = 0;
    int previousResponse = -1; // Initialize previous response with an invalid value
    
    	fprintf(file,"NAME = %s \n \n",filename);
    	
    for (int i = 0; i < numQuestions; i++)
    {
        int currentResponse = askQuestion(questions[i]);
        
        questions[i].weight = adaptWeight(currentResponse, previousResponse, questions[i].weight);
        
        totalScore += currentResponse * questions[i].weight;
        
        previousResponse = currentResponse;
        
        //report generation
	
//        fprintf(file, "%s \n Weight = %d, Your Response = %d, Question score = %d\n", questions[i].question, questions[i].weight, currentResponse, currentResponse * questions[i].weight);
//        fprintf(file, "------------------------------------------------------\n");
    }
	
	printf("score level: \n 0-15 --normal \n greater than 15 --abnoraml \n\n ");
	fprintf(file,"\t\tscore level: \n \t\t0-9 --normal \n\t\t> 15 --abnormal \n\n ");
	
	printf("your score =  \n\n");
	fprintf(file,"your score =  \n\n");
    if (totalScore > 15)
    {
        printf("You may be experiencing symptoms of OCD.\n\n");
        printf("\tConsult to a Doctor\n\n");
        printf("Some advices : \n\n");
        printf("1.Be Open About OCD\n");
        printf("2.Talk to someone you trust about your OCD \n");
        printf("3.Exposure and response prevention (ERP) therapy\n");
        fprintf(file,"\t\tYou may be experiencing symptoms of OCD.\n\n");
        fprintf(file,"\t\tConsult to a Doctor\n\n");
        fprintf(file,"Some advices : \n\n");
        fprintf(file,"1.Be Open About OCD\n");
        fprintf(file,"2.Talk to someone you trust about your OCD \n");
        fprintf(file,"3.Exposure and response prevention (ERP) therapy\n\n\n");
        
    }
    else
    {
        printf("\t\tYou do not seem to display significant symptoms of OCD.\n\n");
        fprintf(file,"\t\tYou do not seem to display significant symptoms of OCD.\n\n");
       
    }
    printf("\n\n\t\t\t\tHave a good day");
    fprintf(file,"\n\n\t\t\t\tHave a good day");
	
    // Close the file
    fclose(file);

    return 0;
}

