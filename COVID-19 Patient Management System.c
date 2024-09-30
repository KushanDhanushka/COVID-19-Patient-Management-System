/*
Mini Project (C Programming)
Project Title: COVID-19 Patient Management System

By DHANUSHKA H.K.K
-------------------------------------------------
KEY FEATURES:

1. You can add patients infinitely.
2. Included with 4 options.
3. 7 different kind data is collected for each patient.
5. Support to new NIC numbers introduced in the recent past with 12 integers as well as earlier issued NIC numbers in Sri Lanka.

-------------------------------------------------

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct{ // Define the structure we using to handle patient data.
    long long NIC; // patient's NIC -- long long format is used for if there is newly created NIC after born 2000 people.
    char fullName [50]; // Patient's name -- assumed it longs less than 50 characters.
    int age; // Patient's age
    char address [100]; // Address of where patient lives -- assumed it longs less than 100 characters.
    char gender [10]; // patient's gender
    char teleno [20]; // Contact number of patient's guardian
    char admissionDate [20]; // Admitted date of the patient to our hospital
}patient_details; // Define the name for the this structure type


// 1.Function for add new patient's information into the array

patient_details * add_Patient (patient_details *detail_arr, int size){

    char gen; // character for easiness of inputting gender details.

    printf("\nEnter the NIC of the patient without 'V': "); // patient's NIC
    scanf("%lld",&detail_arr[size].NIC); 

    printf("Enter Full name : ");  //Patient's name
    scanf("\n"); // to collect string data
    scanf("%[^\n]%*c",detail_arr[size].fullName);

    printf("Enter Age (in numbers only) : "); // Patient's age
    scanf("%d",&detail_arr[size].age);

    printf("Enter the address where the patient currently lives : ");  //Patient's address
    scanf("\n"); // to collect string data
    scanf("%[^\n]%*c",detail_arr[size].address);

    printf("Enter Gender(m = Male , f = Female): "); // patient's gender
    scanf("\n");
    scanf("%c",&gen); // for easiness of inputting, we use single character input

    if(gen =='f'){
        strcpy(detail_arr[size].gender,"Female");
    }else if(gen == 'm'){
        strcpy(detail_arr[size].gender,"Male");
    }

    printf("Enter a telephone number of the guardian of the patient : "); // Telephone number of the Patient's guardian
    scanf("\n");
    scanf("%[^\n]%*c",detail_arr[size].teleno);

    printf("Enter the Admission Date : "); // Admitted date of the patient to our hospital 
    scanf("\n");
    scanf("%[^\n]%*c",detail_arr[size].admissionDate);

    printf("\n");

    return detail_arr;
}

// 2. Function to show information of a patient when his/her NIC number is given.

void print_pat(patient_details *detail_arr , int size){
    long long id; // to take required NIC
    int count=0; // to print error

    printf("\nEnter the NIC of the patient to be printed (without 'V'): ");
    scanf("%lld",&id);

    for (int i =0; i<size; i++){
        if(id == detail_arr[i].NIC){ // for accessing the index of input NIC.

            if (id<1000000000){ // for old type NICs
                printf("\n\nNIC of the patient : %lldV\n",detail_arr[i].NIC);
            }else{ // for new type NICs
                printf("\n\nNIC of the patient : %lld\n",detail_arr[i].NIC);
            }

            printf("Full name of the patient : %s\n",detail_arr[i].fullName);

            printf("Age of the patient : %d\n",detail_arr[i].age);

            printf("Address of the patient : %s\n", detail_arr[i].address);

            printf("Gender of the patient : %s\n",detail_arr[i].gender);

            printf("Telephone number of the guardian of the patient : %s\n", detail_arr[i].teleno);

            printf("Admission date of the patient : %s\n", detail_arr[i].admissionDate);

        }else{
            ++count; // count up if there is no such NIC.
        }
    }

    if (count == (size)){ // if there is no such NIC entered inside the list.
        printf("\nInserted NIC %lld is not in the Patients List!. Try again with the correct NIC.\n",id); // error message
    }
}

// 3.Function to show information of all patients added to the list.

void print_All(patient_details *detail_arr , int size){
    if (size==0){
        printf("\nThere is no any Patient Record in this programme !.\n"); // notification for empty list 
    }else{
        for(int i=0; i<size;i++){ // iterate through all NICs

            printf("\nPatient No.%d\n",(i+1)); // Patient number -- according to added manner.

            if (detail_arr[i].NIC < 1000000000){ // old type NICs
                printf("NIC of the patient : %lldV\n",detail_arr[i].NIC);
            }else{ // new type NICs
                printf("NIC of the patient : %lld\n",detail_arr[i].NIC);
            }

            printf("Full name of the patient : %s\n",detail_arr[i].fullName);

            printf("Age of the patient : %d\n",detail_arr[i].age);

            printf("Address of the patient : %s\n", detail_arr[i].address);

            printf("Gender of the patient : %s\n",detail_arr[i].gender);

            printf("Telephone number of the guardian of the patient : %s\n", detail_arr[i].teleno);

            printf("Admission date of the patient : %s\n", detail_arr[i].admissionDate);
        }
    }
}

// 4. Function to delet information of a patient when his/her NIC number is given.

patient_details* del_Patient(patient_details *detail_arr , int size, int indexTodel){

    for (int j =0; j<size;j++){
        if (j < indexTodel){ // indexes of patients before that patient need to be deleted.
            detail_arr[j]=detail_arr[j]; // keep them as it is
        }else if(j == indexTodel){ // indexes of the patient which need to be deleted.
            continue; // skip it
        }else if(j > indexTodel){ // indexes of patients after that patient need to be deleted.
            detail_arr[j-1] = detail_arr[j]; // bring them one index earlier.
        }
    }
    if (size!=1){
        detail_arr = realloc(detail_arr, (size-1) * sizeof(patient_details)); // reduce the size of the array by 1.
    }else{
        detail_arr = realloc(detail_arr, (size) * sizeof(patient_details)); // keep size at 1 for re-adding data.
    }
    return detail_arr;
}



// ^^ THE MAIN FUNCTION ^^

void main(){

    int close=0; // to while-do iteration
    int size=0; // index of the patient

    patient_details *detail_arr; // initializing and creating a dynamic array to store patient data.
    detail_arr = malloc((size+1)* sizeof(patient_details));

    while(close==0){

        int opt; // option number
        printf("\n*****************************************************\n\n>> COVID-19 PATIENT MANANGEMENT SYSTEM <<\n\n*****************************************************\n\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n0 - Quit\n1 - Add a new Patient Record\n2 - Print a Patient Record\n3 - Print All Patient Records\n4 - Delet a Patient Record\n\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\nNow Enter Your Option here (0-4): ");
        scanf("%d",&opt); // take the option

        if(opt==0){ // for quit the programme
            close = 1;

        }else if (opt==1){ // to add new patient
            add_Patient(detail_arr,size);
            size++; // increment of the index by 1
            detail_arr = realloc(detail_arr, (size+1) * sizeof(patient_details)); // increase the size of the array by 1.

        }else if(opt==2){ // to print details of a patient for given NIC.
            print_pat(detail_arr,size);

        }else if(opt==3){ // to print details of all patients from the array.
            print_All(detail_arr,size);

        }else if(opt==4){ // to delete details of a patient for given NIC.

            long long id; // inputted NIC
            int indexToDelete; // index related to the patient to be deleted.
            int count=0; // for error message

            printf("\nEnter the NIC of the patient to be deleted (without 'V'): ");
            scanf("%lld",&id);
    
            for (int i = 0; i<size; i++){
                if(id == detail_arr[i].NIC){ // if there is such NIC that entered.
                    indexToDelete = i;
                }else if (id != detail_arr[i].NIC){ //if there is no such NIC that entered.
                    ++count;
                }
            }

            if(count == (size)){ // error message !
                printf("\nInserted NIC %lld is not in the Patients List!. Try again with the correct NIC.\n",id);

            }else{
                del_Patient(detail_arr,size,indexToDelete);
                size--; // reduce the index 
                printf("\nPatient Record of NIC %lld has been deleted sucsessfully!.\n",id);
            }

        }else{// option input error handling.
            printf("\nThe option you entered is not valid; Please enter a option from 0-4.\n");
        }
    }
}