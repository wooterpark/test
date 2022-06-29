#pragma PRQA_MESSAGES_OFF 3103,3112,3210,3227,3408,3422,3447
/**********************************************************************
INTER-FUNCTION DATAFLOW - -po df::inter=1
=========================================
:2831 Definite: Division by zero
**********************************************************************/

int foo_1 (void);
void foo_2 (int * p);
void foo_3 (int * p);

void foo_4 (int i)
{
    1 / i;                        /* 2831 2834 */
}

void p1 (void)
{
    1 / foo_1 ();                 /* 2831 */
}

void p2 (void)
{
    int i;
    
    foo_2 (&i);
    1 / i;                        /* 2831 */
}


int foo_1 (void)
{
    return 0;
}

void foo_2 (int * p)
{
    *p = 0;                       /* 2814 */
}

void p4 (void)
{
    foo_4 (0);
}
