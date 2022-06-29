# 1 "C:/PROGRA~1/Razorcat/TESSY_4.3/Examples/ISVALU~1/is_val_in_range.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "C:/PROGRA~1/Razorcat/TESSY_4.3/Examples/ISVALU~1/is_val_in_range.c"






struct range {int range_start; int range_len;};

typedef int value;

typedef enum {no, yes} result;
# 23 "C:/PROGRA~1/Razorcat/TESSY_4.3/Examples/ISVALU~1/is_val_in_range.c"
result is_value_in_range (struct range r1, value v1)
{
 if (v1 < r1.range_start)
  return no;

 if (v1 > (r1.range_start + r1.range_len))
  return no;

 return yes;

}
