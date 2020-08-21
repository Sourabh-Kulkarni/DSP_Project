
#include<stdio.h>
#include<math.h>
#include<omp.h>
#include<time.h>
#include<sched.h>
struct complex
{
double a;
double b;
// both are used a+jb
};

struct real
{
 double p;
              
};

#define cpu sched_getcpu()
#define pi 3.141592
#define MAX 50000
#define K omp_get_thread_num()
#define T omp_get_num_threads()
//***************** Real No operations *************************888888

// Addition

 struct real addr(struct real *x, struct real *y)
{
     struct real z;
     z.p=x->p + y->p;
     return (z);
      
}
// Subtraction
 struct real subr(struct real *x, struct real *y)
{
     struct real z;
     z.p=x->p - y->p;
     return (z);
      
}

// Multiplication




 struct real mulr(struct real *x, struct real *y)
{
     struct real z;
     z.p=x->p * y->p;
     return (z);
      
}
// Multiply And aCcumulate 

 struct real macr(struct real *x, struct real *y , struct real *w)
{
     struct real z;
     z.p=x->p * y->p + w->p;
     return (z); 
}



// ******************** Complex No operations **********************


// Addition
struct complex addc (struct complex *x,struct complex *y)
{
 struct complex z;   

  z.a=x->a + y->a;
  z.b=x->b + y->b;
  return(z);

 }

//Complx No Subtracn
struct complex subc (struct complex *x,struct complex *y)
{
 struct complex z;   

  z.a=x->a - y->a;
  z.b=x->b - y->b;
  return(z);

 }

//Complex number multiplication
struct complex mulc (struct complex *x,struct complex *y)
{
 struct complex z;   
 
  z.a=(x->a)*(y->a)-(x->b)*(y->b);
  z.b=(x->a)*(y->b)+(x->b)*(y->a);
  return(z);

 }

// Sin() and cos() calculations 

struct complex sin_cos (double angle)
{
   struct complex z;
      z.a=cos(angle);
      z.b=sin(angle);
   return(z); 
    
}  
// *************************** Mixed mode operations *****************


struct complex calc_exp(struct real *x, double angle)
{
    struct complex z;
     z.a= (x->p)*cos(angle);
     z.b= (x->p)*sin(angle);
      return (z);

} 

struct real calc_real(struct complex *x)
{

 struct real y;
        
   y.p=sqrt((x->a)*(x->a) + (x->b)*(x->b));

   return (y);

}



//******************************* Interface operations ********************** 
void printcmp(struct complex *z)
{
    printf("%f + j%f \n",z->a,z->b);
}

struct complex rec()
{ 
    struct complex p; 
    scanf("%lf",&p.a);
    scanf("%lf",&p.b);
    return(p);

}

struct real read_sys()
{
   struct real a;
     scanf("%lf",&a.p);
    return (a);

}

struct  real get_fast(double i)
{
   struct real x;
   x.p=i;
    return (x);   
}

struct complex get(double h)
{
       struct complex p;
        p.a=h;
        p.b=h;
       return(p);
}

void printreal(struct real *y)
{

    printf("%lf\n",y->p);

}




