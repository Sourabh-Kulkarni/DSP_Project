#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>
#include<time.h>
#include "dsp.h"

struct complex mac_dft(struct real*,int ,int);
// main starts

int main(int argc,char *argv[])
{ 
  struct complex y[MAX],y1[MAX];
  struct real x[MAX];
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
 //    threads=atoi(argv[2]);
  //  omp_set_num_threads(threads);
      if(N==1)
      { 
          
          printf("enter limit:");
	  scanf("%d",&limit);
          for(i=0;i<limit;i++)
          {
             x[i]=get_fast(h); 
              h++;   
          }
          N=limit;
      }
          
    else
     {     
       for(i=0;i<N;i++)
       {
             x[i]=read_sys();
       }

      }
     
         
         start=omp_get_wtime();
     
          for(k=0;k<N;k++)
         {
            y[k]=mac_dft(&x[0],k,N);
         }
      

       
                 
          stop=omp_get_wtime();
  
    printf("\n The DFT is \n");
 //printf("for seq..\n");

 //   for(k=0;k<N;k++)
 //   {

 //      printcmp(&y[k]);
 //   }
 

  
     printf("Overall Computation time\n");
     printf("this is for sequentia:\n");
     printf("start=%lf\n",start);
     printf("stop=%lf\n",stop);
     printf("%lf\n",(double)(stop-start));

 /*     printf("Overall Computation time\n");
     printf("this is for sequential:\n");
     
     printf("start=%ld\n",str);
     printf("stop=%ld\n",stp);
     printf("%lf\n",(double)(stp-str)/CLOCKS_PER_SEC); */ 
     




    

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
struct complex mac_dft (struct real *x,int k,int N)
{

 struct complex r[MAX];
 //struct complex u[MAX];
 struct complex sum;
 double angle;
 int n;
 
 // printf("thread %d\tcpu:%d\n",K,cpu);
 sum.a=0;
 sum.b=0;
 
    for(n=0;n<N;n++)
      {
             angle=(double)(-2*pi*k*n)/N;
             r[n]=calc_exp(x,angle);
             sum=addc(&sum,&r[n]);
             x++;        
      }

 return (sum);

}



 


