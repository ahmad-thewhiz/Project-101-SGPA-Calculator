#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

void textfile_writer(int no, int ron[], float g_a[], float g_b[], float g_c[], float gpa[], float avg1, float avg2, float avg3);

float mean_marks(float arr[], int n) {
float suma=0.0;
int i;
for(i=0;i<n;i++) 
    suma+=arr[i];
return suma/n;
}

float standard_deviation(float arr[], int n, float mean) {
    float dv[n];
    int i;
    float sumdv=0.0,standdv=0.0;    
    for(i=0;i<n;i++) 
        dv[i]=pow((arr[i]-mean),2);
    for(i=0;i<n;i++)
        sumdv+=dv[i];
    standdv=sqrt(sumdv/n-1);
return standdv;
}

float relative_grader(float no, float dev, float mean) {
        if(no>=(mean+1.5*dev)) {
        return 10.0;
        }
        else if(no<(mean+1.5*dev)&&no>=(mean+1.0*dev)) {
        return 9.0;
        }
        else if(no<(mean+1.0*dev)&&no>=(mean+0.5*dev)) {
        return 8.0;
        }
        else if((no<(mean+0.5*dev))&&no>=(mean+0*dev)) {
        return 7.0;
        }
        else if((no<(mean+0*dev))&&no>=(mean-0.5*dev)) {
        return 6.0;
        }
        else if((no<(mean-0.5*dev))&&no>=(mean-1*dev)) {
        return 5.0;
        }
        else if((no<(mean-1*dev))&&no>=(mean-1.5*dev)) {
        return 4.0;
        }
        else {
        return 0.0;
        }
}

float sgpa_calculator(float g1, float g2, float g3, float c1, float c2, float c3) {
    float result;
    result = (g1*c1+g2*c2+g3*c3)/(c1+c2+c3);
    return result;
}

//This problem is designed and developed as a part of CSE 108L Project by the members of Group-1.

int main() {

int c1,c2,c3;
int n,i;

printf("Enter Credits of courses 1,2 and 3\n");
scanf("%d %d %d",&c1,&c2,&c3);
printf("Enter number of students\n");
scanf("%d",&n);
int rn[n];
float a[n];
float b[n];
float c[n];
printf("Enter Roll number and marks in 3 subjects\n");
for(i=0;i<n;i++) {
    scanf("%d %f %f %f",&rn[i],&a[i],&b[i],&c[i]);
}

float mean1=0.0,mean2=0.0,mean3=0.0;
mean1=mean_marks(a,n);
mean2=mean_marks(b,n);
mean3=mean_marks(c,n);

float dev1=0.0,dev2=0.0,dev3=0.0;
dev1=standard_deviation(a,n,mean1);
dev2=standard_deviation(b,n,mean2);
dev3=standard_deviation(c,n,mean3);

float gr_a[n];
float gr_b[n];
float gr_c[n];
for(i=0;i<n;i++) {
    gr_a[i]=relative_grader(a[i],dev1,mean1);
    gr_b[i]=relative_grader(b[i],dev2,mean2);
    gr_c[i]=relative_grader(c[i],dev3,mean3);
}

float sgpa[n];
for(i=0;i<n;i++) {
    sgpa[i]=sgpa_calculator(gr_a[i],gr_b[i],gr_c[i],c1,c2,c3);
}

printf("*******************************************************************************\n");
printf("*                 SGPA Reckoner for Educational Institutions                 *\n");
printf("*                                                                             *\n");
printf("*        Roll No.       Grade 1       Grade 2       Grade 3       SGPA        *\n");
printf("*                                                                             *\n");
printf("*_____________________________________________________________________________*\n");
for(i=0;i<n;i++) {
printf("         %d               %.0f            %.0f             %.0f           %.3f       \n",rn[i],gr_a[i],gr_b[i],gr_c[i],sgpa[i]);
printf("*_____________________________________________________________________________*\n");
}
printf("*                                                                             *\n");
printf("* Class Strength:  %d                                                         *\n",n);
printf("*                                                                             *\n");
printf("* Class Average:   Subject 1 = %.2f    Subject 2 = %.2f    Subject 3 = %.2f  *\n",mean1,mean2,mean3);
printf("*                                                                             *\n");
printf("*******************************************************************************\n");

textfile_writer(n,rn,gr_a,gr_b,gr_c,sgpa,mean1,mean2,mean3);

printf("Thank you!\n");

return 0;
}

void textfile_writer(int no, int ron[], float g_a[], float g_b[], float g_c[], float gpa[], float avg1, float avg2, float avg3) {
FILE *fptr;
fptr=fopen("SGPA List.txt","w");
if(fptr==NULL) {
    printf("Error!\n");
    exit(1);
}
fprintf(fptr,"*******************************************************************************\n");
fprintf(fptr,"*                 SGPA Reckoner for Educational Institutions                 *\n");
fprintf(fptr,"*                                                                             *\n");
fprintf(fptr,"*        Roll No.       Grade 1       Grade 2       Grade 3       SGPA        *\n");
fprintf(fptr,"*                                                                             *\n");
fprintf(fptr,"*_____________________________________________________________________________*\n");
for(int i=0;i<no;i++) {
fprintf(fptr,"         %d               %.0f            %.0f             %.0f           %.3f       \n",ron[i],g_a[i],g_b[i],g_c[i],gpa[i]);
fprintf(fptr,"*_____________________________________________________________________________*\n");
}
fprintf(fptr,"*                                                                             *\n");
fprintf(fptr,"* Class Strength:  %d                                                         *\n",no);
fprintf(fptr,"*                                                                             *\n");
fprintf(fptr,"* Class Average:   Subject 1 = %.2f    Subject 2 = %.2f    Subject 3 = %.2f  *\n",avg1,avg2,avg3);
fprintf(fptr,"*                                                                             *\n");
fprintf(fptr,"*******************************************************************************\n");
fclose(fptr);
printf("The result list is successfully saved in the storage as 'SGPA List.txt'\n"); 
}