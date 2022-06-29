/******************************************************************

ORDER OF EVALUATION

******************************************************************/
#pragma PRQA_MESSAGES_OFF 0506
#pragma PRQA_MESSAGES_OFF 0510
#pragma PRQA_MESSAGES_OFF 0584
#pragma PRQA_MESSAGES_OFF 0585
#pragma PRQA_MESSAGES_OFF 2814
#pragma PRQA_MESSAGES_OFF 2824
#pragma PRQA_MESSAGES_OFF 2834
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2983
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 2986
#pragma PRQA_MESSAGES_OFF 3103
#pragma PRQA_MESSAGES_OFF 3120
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3408
#pragma PRQA_MESSAGES_OFF 3415
#pragma PRQA_MESSAGES_OFF 3416
#pragma PRQA_MESSAGES_OFF 3440
#pragma PRQA_MESSAGES_OFF 3446
#pragma PRQA_MESSAGES_OFF 3447
#pragma PRQA_MESSAGES_OFF 3492
#pragma PRQA_MESSAGES_OFF 3602
#pragma PRQA_MESSAGES_OFF 3671
#pragma PRQA_MESSAGES_OFF 3673
#pragma PRQA_MESSAGES_OFF 3684



extern int f1(int *pi);
extern int f2(int *pi);
extern int f3(const int *pi);


struct st
{
    int n;
    int (*pf)(struct st **ps);
};




extern void orederofeval(int x, int y, int buf[], int max, struct st *ps)
{

/**********************************************************************
:0400  [U] '%s' is modified more than once between sequence points - evaluation order undefined.
***********************************************************************/
    x = y + (x++);                      /* 0400 */


    /* In the following statement, there is a sequence point after the
       evaluation of the first operand of the ternary operator, so "x"
       is known to be incremented before the assignment occurs. The
       code may be silly, but it is not undefined */

    x = ((++x) > max) ? 0 : 1;

    /* But in these cases the order of the increment and assignment are not defined */

    x = (x > max) ? (++x) : 0;          /* 0400 */
    x = (y > max) ? (++x) : 0;          /* 0400 */




/**********************************************************************
:0401  [U] '%s' may be modified more than once between sequence points - evaluation order undefined.

This message is generated in situations where it is not certain that
an object is modified more than once but the passing of a pointer to
that object suggests it may be


***********************************************************************/

    y = f1(&x) + (x++);                 /* 0401 */
    y = f1(&x) + f2(&x);                /* 0401 */

    /* In these statements, any modification to the value of x by the function
       f1 is known to occur before the assignment and therefore, although
       "x" may be modified more than once, the order of evaluation is not undefined */
    x = f1(&x);

    x = (y > max) ? f1(&x) : 0;

    /* The prototype of f3 declares a "pointer to const int" parameter and
       so there is no possibility of x being modified more than once */
    y = f3(&x) + (x++);



/**********************************************************************
:0402  [U] '%s' is modified and accessed between sequence points - evaluation order undefined.
***********************************************************************/

    y = (x + 6) / (x++);                /*0402 */

    y = buf[x] + (x++);                 /*0402 */

    y = (x > max) ? (x++) : 0;


/**********************************************************************
:0403  [U] '%s' may be modified and accessed between sequence points - evaluation order undefined.
***********************************************************************/

    y = f1(&x) + x;                    /* 0403 */
    y = buf[x] + f1(&x);               /* 0403 */

    /* The prototype of f3 declares a "pointer to const int" parameter and
       so there is no possibility of x being modified */
    y = f3(&x) + x;
    y = buf[x] + f3(&x);

    /* In the following example the evaluation of the function pointer
       is known to occur before the execution of the function so
       their is no undefined behviour */
    y = ps->pf(&ps);

}
