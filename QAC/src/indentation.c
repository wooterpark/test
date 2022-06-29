/********************************************************************************************

INDENTATION

********************************************************************************************/

#pragma PRQA_MESSAGES_OFF 0780
#pragma PRQA_MESSAGES_OFF 2000
#pragma PRQA_MESSAGES_OFF 2016
#pragma PRQA_MESSAGES_OFF 2213
#pragma PRQA_MESSAGES_OFF 2982
#pragma PRQA_MESSAGES_OFF 2983
#pragma PRQA_MESSAGES_OFF 2984
#pragma PRQA_MESSAGES_OFF 2986
#pragma PRQA_MESSAGES_OFF 3198
#pragma PRQA_MESSAGES_OFF 3199
#pragma PRQA_MESSAGES_OFF 3204
#pragma PRQA_MESSAGES_OFF 3205
#pragma PRQA_MESSAGES_OFF 3227
#pragma PRQA_MESSAGES_OFF 3352
#pragma PRQA_MESSAGES_OFF 3408


/********************************************************************************************
:2200  Indentation of this line is to the left of the line above.
:2201  This indentation is not consistent with previous indentation in this file.
:2205  More than one declaration or statement on the same line.
:2211  '%s' is not aligned with the previously declared identifier.
:2216  More than one structure or union member declared on the same line.
********************************************************************************************/
void foo1(int x)
{
        int ax;                         /* 2215 */
        int  bx;                        /* 2211 */
        struct st {int a; int b;};      /* 2216 */
        int r = 0;
        int  s = 1;                     /* 2211 */

        if (x > 0)
        {
                ++r;
                 r = r + s;             /* 2201 */
r += x;                                 /* 2200 2201 */
                ++r; s = 0;             /* 2205 */
                ++r;

/********************************************************************************************
:2210  Tab character encountered at the beginning of a line.

Message 2210 will only be generated when a tab character
is encountered in the code and if the tabstop option has
been set to zero. (Analyser Personality | Style)
Tab characters are often removed or inserted automatically
by editors.
The following line is intended to have a tab character
preceding the "s". Note that some editors convert spaces to
tabs or tabs to spaces.
********************************************************************************************/
	        s = 1;                  /* 2210 2201 */
        }

/********************************************************************************************
:2204  '%s' is not aligned to match its controlling 'switch' statement.
********************************************************************************************/
        switch (x)
        {
                case 1:                 /* 2204 */
                ++r;
                break;

        default:
                break;
        }
}
