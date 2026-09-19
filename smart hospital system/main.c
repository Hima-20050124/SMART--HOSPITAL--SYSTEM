#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int specialtyID;
    char specialtyName[30];
    double baseConsultationFee;
    int consultationTime;
    int dailyPatientcap;
    }specialty;


   const specialty specialties[4] = {

                {1,"General Practice(OPD)",1500.00,15,30},
                {2,"Paediatrics",2500.00,20,20},
                {3,"Cardiology",4500.00,30,12},
                {4,"Neurology",5000.00,30,10}

                };


    typedef struct {
    int wardID;
    char wardName[25];
    double dailyBedRate;
    int totalBedCapacity;
    }Ward;

    const Ward wards[4] = {

                {1,"General ward",3000.00,20},
                {2,"Paediatric Ward",6000.00,10},
                {3,"Surgical Ward",12000.00,10},
                {4,"ICU (Intensive Care Unit)",25000.00,05}


              };


     int bedOccupancy[4][20];

     struct Patient{
    char name[50];
    int id;
    int age;
    int triageLevel;
    int specialtyID;
    int wardID;
    int isAdmitted;
    int daysAdmitted;
    int bedNumber;
    double finalBill;
    };

    struct Patient patients[100];

    int count = 0;


     void initializeData()
{
    for(int i=0 ; i<4 ;i++)
    {
        for(int j=0 ; j<20 ; j++)
        {
            bedOccupancy[i][j] = 0;
        }
    }
}


int allocateBed(int wardID)
{
    int wardIndex = wardID - 1;
    int i;

    if (wardIndex < 0 || wardIndex >= 4)
    {
        return -1;
    }

    for (i = 0; i < wards[wardIndex].totalBedCapacity; i++)
    {
        if (bedOccupancy[wardIndex][i] == 0)
        {
            bedOccupancy[wardIndex][i] = 1;

            return i + 1;
        }
    }

    return -1;
}





void registerPatient()
{
     int bedNumber;

    printf("Patient Registration");

    printf("Enter Patient name :  \n");
     scanf(" %[^\n]",patients[count].name);

    printf("Enter Patient ID :  \n");
     scanf("%d",&patients[count].id);

    printf("Enter Patient Age  :  \n");
     scanf("%d",&patients[count].age);

    printf("Enter Triage Level(1=Normal,2=Urgent,3=Critical) :  \n");
     scanf("%d",&patients[count].triageLevel);

    printf("Enter Specialty ID:  \n");
     scanf("%d",&patients[count].specialtyID);

    printf("Is admitted to the Ward ?(1=Yes,0=NO)  :  \n");
     scanf("%d",&patients[count].isAdmitted);

    if (patients[count].isAdmitted == 1)
    {
        printf("Enter the ward ID : \n");
         scanf("%d",&patients[count].wardID);

        printf("Days Admitted(integer) : \n");
         scanf("%d",&patients[count].daysAdmitted);

         bedNumber = allocateBed(patients[count].wardID);

          if (bedNumber != -1)
        {
            patients[count].bedNumber = bedNumber;

            printf("\nBed allocated successfully!\n");
            printf("Bed Number: %d\n", bedNumber);
        }
        else
        {
            printf("\nNo available beds in this ward.\n");

            patients[count].isAdmitted = 0;
            patients[count].wardID = 0;
            patients[count].daysAdmitted = 0;
            patients[count].bedNumber = 0;
        }


    }

    else
    {
       patients[count].wardID = 0;
        patients[count].daysAdmitted = 0;
    }


}



int main()
{
    initializeData();

    printf("\t--- WELCOME TO SMART-HOSPITAL-SYSTEM ---\n\n");

    registerPatient();

    count++;


    return 0;
}
