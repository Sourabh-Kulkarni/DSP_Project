#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>
#include<time.h>
#include "dsp.h"

struct complex mac_idft(struct complex*,int ,int);
// main starts

int main(int argc,char *argv[])
{ 
  struct complex y[MAX];
  struct real y1[MAX];
  struct complex x[MAX];
   double h=0;
//  struct timeval  sd,ed;
//   long mt;
   int  k,i,N;
//   int threads;
   int limit;
  // int m;
 //  long sen,usen;
  double start,stop,str,stp; 
    if(argc>0)
   {
      N=atoi(argv[1]);
 //     threads=atoi(argv[2]);
 //   omp_set_num_threads(threads);
      if(N==1)
      { 
          
          printf("enter limit:");
	  scanf("%d",&limit);
          for(i=0;i<limit;i++)
          {
             x[i]=get(h); 
              h++;   
          }
          N=limit;
      }
          
    else
     {     
       for(i=0;i<N;i++)
       {
             x[i]=rec();
       }

      }
     
         
         start=omp_get_wtime();
     
          for(k=0;k<N;k++)
         {
            y[k]=mac_idft(&x[0],k,N);
         }

         for(k=0;k<N;k++)
         {
              y1[k]=calc_real(&y[k]); 
         }
                
          stop=omp_get_wtime();
  
   // printf("\n The iDFT is \n");
   // printf("for seq..\n");
   // printf("complex values\n");
   // for(k=0;k<N;k++)
   // {
   //    printcmp(&y[k]);
   // }
   // printf("absolute values\n");
   // for(k=0;k<N;k++)
   // {
   //    printreal(&y1[k]);
   // }
 


    printf("Overall Computation time\n");
     printf("this is for seq:\n");
     printf("start=%lf\n",start);
     printf("stop=%lf\n",stop);
     printf("%lf\n",(double)(stop-start));

 




    

    return 0;
  }
  else
  {
     return 1;
  }
 
  
}

// main ends

//******** definition of functions ***********

// They will form basis for everything 
//Multiply and accumulate
struct complex mac_idft (struct complex *x,int k,int N)
{

 struct complex r[MAX];
 struct complex u[MAX];
 struct complex sum;
 double angle;
 int n;
 
  printf("thread %d\tcpu:%d\n",K,cpu);
 sum.a=0;
 sum.b=0;
 
    for(n=0;n<N;n++)
      {
             angle=(double)(2*pi*k*n)/N;
             r[n]=sin_cos(angle);
             u[n]=mulc(x,&r[n]); 
             sum=addc(&sum,&u[n]);
             x++;        
      }

       sum.a=sum.a/N;
       sum.b=sum.b/N;
       return(sum);

            

}



 

