#include <stdio.h>
#include<stdlib.h>

typedef struct {
    char question[200];
    int weight;
} Question;

int askQuestion(Question q) {
   
    data = fopen("Input.txt","w");
    int response;
    printf("------------------------------------------------------\n");
    printf("%s\n", q.question);
    printf("1) NEVER \t 2) SOMETIMES \t 3) OFTEN \t 4) VERY OFTEN \t 5) ALWAYS ");
    printf("\nEnter your response (1-5): ");
    scanf("%d", &response);
    
    printf("------------------------------------------------------\n");
    return response;
}

int adaptWeight(int currentResponse, int previousResponse, int weight) {
    // Adjust weight based on change in response
    if (currentResponse != previousResponse) {
        weight += 1; // Increase weight by 1 for adaptive scoring
    }
    return weight;
}

int main() {

     printf("\t-----WELCOME TO THE TEST-----");
    printf("\n\n");
    printf("\n\t\t***DISCLAIMER***");
    printf("\n\n\t\t*This quiz is NOT a diagnostic tool* \nMental health disorders can only be diagnosed by licensed health care professionals.\n\n\n");
    printf("\n\t\tWhat Does This Test Consist Of?\n");
    printf("-> Eight questions that relate to common thoughts and behaviors experienced by those \n\tdiagnosed with obsessive compulsive disorder (OCD).\n\n");
   FILE *data;
    Question questions[] = {
        {"Q) I often have repetitive and intrusive thoughts that I find difficult to control.", 2},
        {"Q) I feel a strong urge to perform certain actions or rituals repeatedly.", 3},
        {"Q) I have difficulties in making decisions due to excessive doubts and concerns.", 2},
        {"Q) I spend a lot of time checking or ensuring things are done correctly or perfectly.", 3},
        {"Q) I have a fear of contamination or getting sick and engage in excessive cleaning or washing.", 3},
        {"Q) I experience distress when things are not arranged symmetrically or in a specific order.", 2},
        {"Q) I find it hard to discard or throw away items that may seem useless or have no value.", 2},
        {"Q) I feel a need to confess or seek reassurance excessively about my thoughts or actions.", 3},
        {"Q)I have difficulties completing tasks due to repeating or redoing them multiple times.", 2},
        {"Q) I experience intrusive, unwanted thoughts or mental images that go against my values.", 2}
    };

    int numQuestions = sizeof(questions) / sizeof(questions[0]);

    int totalScore = 0;
    int previousResponse = -1; // Initialize previous response with an invalid value
    for (int i = 0; i < numQuestions; i++) {
        int currentResponse = askQuestion(questions[i]);
        questions[i].weight = adaptWeight(currentResponse, previousResponse, questions[i].weight);
        totalScore += currentResponse * questions[i].weight;
        fprintf(data,"%s %d %d\n",q.question,q.weight,response);
        previousResponse = currentResponse;
    }

    if (totalScore > 10) {
        printf("You may be experiencing symptoms of OCD.\n");
    } else {
        printf("You do not seem to display significant symptoms of OCD.\n");
    }

    return 0;
}
