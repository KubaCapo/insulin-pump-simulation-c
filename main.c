#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct Blood {
    float glucose;
    float insulin;
};

struct Measurement {
    int glucose;
    int insulin;
};

void print_header(void) {
    printf("Insulin Pump Control System Simulation\n");
    printf("Author: Jakub Czarnowski | CS Student, UKSW Warsaw\n\n");
}

void print_description(void) {
    printf("The insulin pump activates automatically when blood glucose exceeds 126 mg/dL.\n\n");
}

float generate_random_float(float min, float max) {
    float scale = (float)rand() / (float)RAND_MAX;
    return min + scale * (max - min);
}

void activate_pump(struct Blood* blood_ptr) {
    blood_ptr->glucose = 100.0f;
    blood_ptr->insulin += 30.0f;
}

bool should_activate_pump(const struct Measurement* measurement_ptr) {
    return measurement_ptr->glucose > 126;
}

struct Measurement take_measurement(struct Blood b) {
    struct Measurement m;
    m.glucose = (int)b.glucose;
    m.insulin = (int)b.insulin;
    return m;
}

int main(void) {
    srand((unsigned int)time(NULL));
    char choice = 'y';

    print_header();
    print_description();

    while (choice == 'y' || choice == 'Y') {
        struct Blood patient_blood;
        patient_blood.glucose = generate_random_float(72.0f, 199.0f);
        patient_blood.insulin = generate_random_float(40.0f, 300.0f);

        struct Measurement initial = take_measurement(patient_blood);

        printf("Initial sensor reading:\n");
        printf("Glucose: %d [mg/dL], Insulin: %d [pmol/L]\n", initial.glucose, initial.insulin);

        if (should_activate_pump(&initial)) {
            printf("\nGlucose level exceeds safe threshold! Activating insulin pump...\n");

            activate_pump(&patient_blood);

            struct Measurement post_pump = take_measurement(patient_blood);
            printf("Post-infusion reading:\n");
            printf("Glucose: %d [mg/dL], Insulin: %d [pmol/L]\n", post_pump.glucose, post_pump.insulin);
        }
        else {
            printf("\nGlucose level within normal range. No pump action required.\n");
        }

        printf("\nEnter 'y' to run another cycle, or any other key to exit: ");
        scanf(" %c", &choice);
        printf("\n");
    }

    printf("Simulation terminated.\n");
    return 0;
}
