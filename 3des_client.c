#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>
#include "3des.h"
double time_elapsed(struct timespec *start, struct timespec *end);
int main(int argc, const char * argv[]) {

    int i;
    struct timespec start1;
    struct timespec end1;
    struct timespec start2;
    struct timespec end2;

    //uint64_t input = 0x9474B73827373BCA7D;
    //printf("%d\n",sizeof(input) );
    uint64_t key1 = 0x9837239487;
    uint64_t key2 = 0x5812938832;
    uint64_t key3 = 0x3719827398;

    uint64_t result1,result2,result3,d_result1,d_result2,d_result3;

    int n;
    //n=5;
    scanf("%d",&n);
    uint64_t *plain_text_input = (uint64_t*)malloc(sizeof(uint64_t)*n);
    for(i=0;i<n;i++)
    {
    	scanf("%" PRIx64,&plain_text_input[i]);
    }


    printf("\t\tTRIPLE DES IMPLEMENTATION\n");
    printf("\t\t-------------------------\n");
    printf("\n");
    printf("\tNOTE:\n\tThe Plain Text, Cipher Text and the Keys are represented as \n\t64bit hexadecimal values which can hold upto 16 digits\n\n");
    printf("\t\tKEYS\n");
    printf("\t\t----\n");
    printf("\t\tKey1 : %"PRIx64"\n",key1);
    printf("\t\tKey2 : %"PRIx64"\n",key2);
    printf("\t\tKey3 : %"PRIx64"\n",key3);

    printf("\n----------------------------------------------------------------------------\n");



    for(i=0;i<n;i++)
    {
        
        printf("\n");
        printf("\t\tPLAIN TEXT TO CIPHER TEXT CONVERSION\n");
        printf("\t\t------------------------------------\n");
        printf("Case %d : \n",i+1);
        printf("Plain Text : %"PRIx64"\n",plain_text_input[i]);
        clock_gettime(CLOCK_REALTIME, &start1); 
        result1 = des(plain_text_input[i], key1, 'e');
        clock_gettime(CLOCK_REALTIME, &end2); 
        printf("STAGE1 : Encryption of plain text with Key1 :\nResult-> ");
        printf ("%"PRIx64"\n", result1);
        //printf("%Time taken for encryption : %lf\n", time_elapsed(&start1,&end1));
        
        //clock_gettime(CLOCK_REALTIME, &start2); 
        result2 = des(result1, key2, 'd');
        //clock_gettime(CLOCK_REALTIME, &end2); 
        printf("STAGE2 : Decryption of result of STAGE1 with Key2 :\nResult-> ");
        printf ("%"PRIx64"\n", result2);


        result3 =des(result2,key3,'e');
        clock_gettime(CLOCK_REALTIME, &end1); 
        printf("STAGE3 : Encryption of result of STAGE2 with Key3 :\nResult-> ");
        printf ("%"PRIx64"\n", result3);
        printf("Time taken for DES encryption : %lf sec\n",time_elapsed(&start1,&end2));
        printf("Time taken for 3DES encryption : %lf sec\n", time_elapsed(&start1,&end1));


        printf ("\nCipher Text : %"PRIx64"\n\n", result3);
        //printf("----------------------------------------------------------------------------\n");
        printf("\t\tCIPHER TEXT TO PLAIN TEXT CONVERSION\n");
        printf("\t\t------------------------------------\n");

        printf ("\nCipher Text : %"PRIx64"\n\n", result3);
        clock_gettime(CLOCK_REALTIME, &start2); 

        d_result1 = des(result3,key3,'d');
        clock_gettime(CLOCK_REALTIME,&end1);
        printf("STAGE1 : Decryption of cipher text with Key3 : \nResult-> ");
        printf ("%"PRIx64"\n", d_result1);


        d_result2 = des(d_result1,key2,'e');
        printf("STAGE2 : Encryption of result of STAGE 1 with Key2 : \nResult-> ");
        printf ("%"PRIx64"\n", d_result2);

        d_result3 = des(d_result2,key1,'d');
        clock_gettime(CLOCK_REALTIME, &end2); 

        printf("STAGE3 : Decryption of result of STAGE2 with Key1 : \nResult-> ");
        printf ("%"PRIx64"\n", d_result3);
        printf("Time taken for DES decryption : %lf sec\n",time_elapsed(&start2,&end1));
        printf("Time taken for 3DES decryption : %lf sec\n", time_elapsed(&start2,&end2));

        printf ("\nPlain Text : %"PRIx64"\n\n", d_result3);
        
        printf("----------------------------------------------------------------------------\n");




    }




    
    exit(0);
    
}

double time_elapsed(struct timespec *start, struct timespec *end) {
    double t;
    t = (end->tv_sec - start->tv_sec); 
    t += (end->tv_nsec - start->tv_nsec) * 0.000000001; 
    return t;
}