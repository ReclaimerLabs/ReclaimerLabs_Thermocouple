#include "ReclaimerLabs_Thermocouple.h"

#define TYPE_T_LOOKUP_SIZE 68
thermo_lookup_entry_t thermo_lookup_type_t[TYPE_T_LOOKUP_SIZE] = {
{ .temp_C= -270, .mV= -6.258 },
{ .temp_C= -260, .mV= -6.232 },
{ .temp_C= -250, .mV= -6.180 },
{ .temp_C= -240, .mV= -6.105 },
{ .temp_C= -230, .mV= -6.007 },
{ .temp_C= -220, .mV= -5.888 },
{ .temp_C= -210, .mV= -5.753 },
{ .temp_C= -200, .mV= -5.603 },
{ .temp_C= -190, .mV= -5.439 },
{ .temp_C= -180, .mV= -5.261 },
{ .temp_C= -170, .mV= -5.070 },
{ .temp_C= -160, .mV= -4.865 },
{ .temp_C= -150, .mV= -4.648 },
{ .temp_C= -140, .mV= -4.419 },
{ .temp_C= -130, .mV= -4.177 },
{ .temp_C= -120, .mV= -3.923 },
{ .temp_C= -110, .mV= -3.657 },
{ .temp_C= -100, .mV= -3.379 },
{ .temp_C=  -90, .mV= -3.089 },
{ .temp_C=  -80, .mV= -2.788 },
{ .temp_C=  -70, .mV= -2.476 },
{ .temp_C=  -60, .mV= -2.153 },
{ .temp_C=  -50, .mV= -1.819 },
{ .temp_C=  -40, .mV= -1.475 },
{ .temp_C=  -30, .mV= -1.121 },
{ .temp_C=  -20, .mV= -0.757 },
{ .temp_C=  -10, .mV= -0.383 },
{ .temp_C=    0, .mV=  0.000 },
{ .temp_C=   10, .mV=  0.391 },
{ .temp_C=   20, .mV=  0.790 },
{ .temp_C=   30, .mV=  1.196 },
{ .temp_C=   40, .mV=  1.612 },
{ .temp_C=   50, .mV=  2.036 },
{ .temp_C=   60, .mV=  2.468 },
{ .temp_C=   70, .mV=  2.909 },
{ .temp_C=   80, .mV=  3.358 },
{ .temp_C=   90, .mV=  3.814 },
{ .temp_C=  100, .mV=  4.279 },
{ .temp_C=  110, .mV=  4.750 },
{ .temp_C=  120, .mV=  5.228 },
{ .temp_C=  130, .mV=  5.714 },
{ .temp_C=  140, .mV=  6.206 },
{ .temp_C=  150, .mV=  6.704 },
{ .temp_C=  160, .mV=  7.209 },
{ .temp_C=  170, .mV=  7.720 },
{ .temp_C=  180, .mV=  8.237 },
{ .temp_C=  190, .mV=  8.759 },
{ .temp_C=  200, .mV=  9.288 },
{ .temp_C=  210, .mV=  9.822 },
{ .temp_C=  220, .mV= 10.362 },
{ .temp_C=  230, .mV= 10.907 },
{ .temp_C=  240, .mV= 11.458 },
{ .temp_C=  250, .mV= 12.013 },
{ .temp_C=  260, .mV= 12.574 },
{ .temp_C=  270, .mV= 13.139 },
{ .temp_C=  280, .mV= 13.709 },
{ .temp_C=  290, .mV= 14.283 },
{ .temp_C=  300, .mV= 14.862 },
{ .temp_C=  310, .mV= 15.445 },
{ .temp_C=  320, .mV= 16.032 },
{ .temp_C=  330, .mV= 16.624 },
{ .temp_C=  340, .mV= 17.219 },
{ .temp_C=  350, .mV= 17.819 },
{ .temp_C=  360, .mV= 18.422 },
{ .temp_C=  370, .mV= 19.030 },
{ .temp_C=  380, .mV= 19.641 },
{ .temp_C=  390, .mV= 20.255 },
{ .temp_C=  400, .mV= 20.872 }
};