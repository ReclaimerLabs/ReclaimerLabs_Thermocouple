#include "ReclaimerLabs_Thermocouple.h"

#define TYPE_R_LOOKUP_SIZE 182
thermo_lookup_entry_t thermo_lookup_type_r[TYPE_R_LOOKUP_SIZE] = {
{ .temp_C=  -50, .mV= -0.226 },
{ .temp_C=  -40, .mV= -0.188 },
{ .temp_C=  -30, .mV= -0.145 },
{ .temp_C=  -20, .mV= -0.100 },
{ .temp_C=  -10, .mV= -0.051 },
{ .temp_C=    0, .mV=  0.000 },
{ .temp_C=   10, .mV=  0.054 },
{ .temp_C=   20, .mV=  0.111 },
{ .temp_C=   30, .mV=  0.171 },
{ .temp_C=   40, .mV=  0.232 },
{ .temp_C=   50, .mV=  0.296 },
{ .temp_C=   60, .mV=  0.363 },
{ .temp_C=   70, .mV=  0.431 },
{ .temp_C=   80, .mV=  0.501 },
{ .temp_C=   90, .mV=  0.573 },
{ .temp_C=  100, .mV=  0.647 },
{ .temp_C=  110, .mV=  0.723 },
{ .temp_C=  120, .mV=  0.800 },
{ .temp_C=  130, .mV=  0.879 },
{ .temp_C=  140, .mV=  0.959 },
{ .temp_C=  150, .mV=  1.041 },
{ .temp_C=  160, .mV=  1.124 },
{ .temp_C=  170, .mV=  1.208 },
{ .temp_C=  180, .mV=  1.294 },
{ .temp_C=  190, .mV=  1.381 },
{ .temp_C=  200, .mV=  1.469 },
{ .temp_C=  210, .mV=  1.558 },
{ .temp_C=  220, .mV=  1.648 },
{ .temp_C=  230, .mV=  1.739 },
{ .temp_C=  240, .mV=  1.831 },
{ .temp_C=  250, .mV=  1.923 },
{ .temp_C=  260, .mV=  2.017 },
{ .temp_C=  270, .mV=  2.112 },
{ .temp_C=  280, .mV=  2.207 },
{ .temp_C=  290, .mV=  2.304 },
{ .temp_C=  300, .mV=  2.401 },
{ .temp_C=  310, .mV=  2.498 },
{ .temp_C=  320, .mV=  2.597 },
{ .temp_C=  330, .mV=  2.696 },
{ .temp_C=  340, .mV=  2.796 },
{ .temp_C=  350, .mV=  2.896 },
{ .temp_C=  360, .mV=  2.997 },
{ .temp_C=  370, .mV=  3.099 },
{ .temp_C=  380, .mV=  3.201 },
{ .temp_C=  390, .mV=  3.304 },
{ .temp_C=  400, .mV=  3.408 },
{ .temp_C=  410, .mV=  3.512 },
{ .temp_C=  420, .mV=  3.616 },
{ .temp_C=  430, .mV=  3.721 },
{ .temp_C=  440, .mV=  3.827 },
{ .temp_C=  450, .mV=  3.933 },
{ .temp_C=  460, .mV=  4.040 },
{ .temp_C=  470, .mV=  4.147 },
{ .temp_C=  480, .mV=  4.255 },
{ .temp_C=  490, .mV=  4.363 },
{ .temp_C=  500, .mV=  4.471 },
{ .temp_C=  510, .mV=  4.580 },
{ .temp_C=  520, .mV=  4.690 },
{ .temp_C=  530, .mV=  4.800 },
{ .temp_C=  540, .mV=  4.910 },
{ .temp_C=  550, .mV=  5.021 },
{ .temp_C=  560, .mV=  5.133 },
{ .temp_C=  570, .mV=  5.245 },
{ .temp_C=  580, .mV=  5.357 },
{ .temp_C=  590, .mV=  5.470 },
{ .temp_C=  600, .mV=  5.583 },
{ .temp_C=  610, .mV=  5.697 },
{ .temp_C=  620, .mV=  5.812 },
{ .temp_C=  630, .mV=  5.926 },
{ .temp_C=  640, .mV=  6.041 },
{ .temp_C=  650, .mV=  6.157 },
{ .temp_C=  660, .mV=  6.273 },
{ .temp_C=  670, .mV=  6.390 },
{ .temp_C=  680, .mV=  6.507 },
{ .temp_C=  690, .mV=  6.625 },
{ .temp_C=  700, .mV=  6.743 },
{ .temp_C=  710, .mV=  6.861 },
{ .temp_C=  720, .mV=  6.980 },
{ .temp_C=  730, .mV=  7.100 },
{ .temp_C=  740, .mV=  7.220 },
{ .temp_C=  750, .mV=  7.340 },
{ .temp_C=  760, .mV=  7.461 },
{ .temp_C=  770, .mV=  7.583 },
{ .temp_C=  780, .mV=  7.705 },
{ .temp_C=  790, .mV=  7.827 },
{ .temp_C=  800, .mV=  7.950 },
{ .temp_C=  810, .mV=  8.073 },
{ .temp_C=  820, .mV=  8.197 },
{ .temp_C=  830, .mV=  8.321 },
{ .temp_C=  840, .mV=  8.446 },
{ .temp_C=  850, .mV=  8.571 },
{ .temp_C=  860, .mV=  8.697 },
{ .temp_C=  870, .mV=  8.823 },
{ .temp_C=  880, .mV=  8.950 },
{ .temp_C=  890, .mV=  9.077 },
{ .temp_C=  900, .mV=  9.205 },
{ .temp_C=  910, .mV=  9.333 },
{ .temp_C=  920, .mV=  9.461 },
{ .temp_C=  930, .mV=  9.590 },
{ .temp_C=  940, .mV=  9.720 },
{ .temp_C=  950, .mV=  9.850 },
{ .temp_C=  960, .mV=  9.980 },
{ .temp_C=  970, .mV= 10.111 },
{ .temp_C=  980, .mV= 10.242 },
{ .temp_C=  990, .mV= 10.374 },
{ .temp_C= 1000, .mV= 10.506 },
{ .temp_C= 1010, .mV= 10.638 },
{ .temp_C= 1020, .mV= 10.771 },
{ .temp_C= 1030, .mV= 10.905 },
{ .temp_C= 1040, .mV= 11.039 },
{ .temp_C= 1050, .mV= 11.173 },
{ .temp_C= 1060, .mV= 11.307 },
{ .temp_C= 1070, .mV= 11.442 },
{ .temp_C= 1080, .mV= 11.578 },
{ .temp_C= 1090, .mV= 11.714 },
{ .temp_C= 1100, .mV= 11.850 },
{ .temp_C= 1110, .mV= 11.986 },
{ .temp_C= 1120, .mV= 12.123 },
{ .temp_C= 1130, .mV= 12.260 },
{ .temp_C= 1140, .mV= 12.397 },
{ .temp_C= 1150, .mV= 12.535 },
{ .temp_C= 1160, .mV= 12.673 },
{ .temp_C= 1170, .mV= 12.812 },
{ .temp_C= 1180, .mV= 12.950 },
{ .temp_C= 1190, .mV= 13.089 },
{ .temp_C= 1200, .mV= 13.228 },
{ .temp_C= 1210, .mV= 13.367 },
{ .temp_C= 1220, .mV= 13.507 },
{ .temp_C= 1230, .mV= 13.646 },
{ .temp_C= 1240, .mV= 13.786 },
{ .temp_C= 1250, .mV= 13.926 },
{ .temp_C= 1260, .mV= 14.066 },
{ .temp_C= 1270, .mV= 14.207 },
{ .temp_C= 1280, .mV= 14.347 },
{ .temp_C= 1290, .mV= 14.488 },
{ .temp_C= 1300, .mV= 14.629 },
{ .temp_C= 1310, .mV= 14.770 },
{ .temp_C= 1320, .mV= 14.911 },
{ .temp_C= 1330, .mV= 15.052 },
{ .temp_C= 1340, .mV= 15.193 },
{ .temp_C= 1350, .mV= 15.334 },
{ .temp_C= 1360, .mV= 15.475 },
{ .temp_C= 1370, .mV= 15.616 },
{ .temp_C= 1380, .mV= 15.758 },
{ .temp_C= 1390, .mV= 15.899 },
{ .temp_C= 1400, .mV= 16.040 },
{ .temp_C= 1410, .mV= 16.181 },
{ .temp_C= 1420, .mV= 16.323 },
{ .temp_C= 1430, .mV= 16.464 },
{ .temp_C= 1440, .mV= 16.605 },
{ .temp_C= 1450, .mV= 16.746 },
{ .temp_C= 1460, .mV= 16.887 },
{ .temp_C= 1470, .mV= 17.028 },
{ .temp_C= 1480, .mV= 17.169 },
{ .temp_C= 1490, .mV= 17.310 },
{ .temp_C= 1500, .mV= 17.451 },
{ .temp_C= 1510, .mV= 17.591 },
{ .temp_C= 1520, .mV= 17.732 },
{ .temp_C= 1530, .mV= 17.872 },
{ .temp_C= 1540, .mV= 18.012 },
{ .temp_C= 1550, .mV= 18.152 },
{ .temp_C= 1560, .mV= 18.292 },
{ .temp_C= 1570, .mV= 18.431 },
{ .temp_C= 1580, .mV= 18.571 },
{ .temp_C= 1590, .mV= 18.710 },
{ .temp_C= 1600, .mV= 18.849 },
{ .temp_C= 1610, .mV= 18.988 },
{ .temp_C= 1620, .mV= 19.126 },
{ .temp_C= 1630, .mV= 19.264 },
{ .temp_C= 1640, .mV= 19.402 },
{ .temp_C= 1650, .mV= 19.540 },
{ .temp_C= 1660, .mV= 19.677 },
{ .temp_C= 1670, .mV= 19.814 },
{ .temp_C= 1680, .mV= 19.951 },
{ .temp_C= 1690, .mV= 20.087 },
{ .temp_C= 1700, .mV= 20.222 },
{ .temp_C= 1710, .mV= 20.356 },
{ .temp_C= 1720, .mV= 20.488 },
{ .temp_C= 1730, .mV= 20.620 },
{ .temp_C= 1740, .mV= 20.749 },
{ .temp_C= 1750, .mV= 20.877 },
{ .temp_C= 1760, .mV= 21.003 }
};