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


void displayBedOccupancy()
{
    int i, j;

    printf("--- BED OCCUPANCY ---\n");

    for (i = 0; i < 4; i++)
    {
        printf("\nWard %d - %s\n",
               wards[i].wardID,
               wards[i].wardName);

        for (j = 0; j < wards[i].totalBedCapacity; j++)
        {
            if (bedOccupancy[i][j] == 0)
            {
                printf("Bed %d : Available\n", j + 1);
            }
            else
            {
                printf("Bed %d : Occupied\n", j + 1);
            }
        }
    }
}






int main()
{
    initializeData();

    printf("\t--- WELCOME TO SMART-HOSPITAL-SYSTEM ---\n\n");

     displayBedOccupancy();

    return 0;
}
