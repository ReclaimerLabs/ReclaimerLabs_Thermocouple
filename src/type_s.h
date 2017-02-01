#include "ReclaimerLabs_Thermocouple.h"

#define TYPE_S_LOOKUP_SIZE 182
thermo_lookup_entry_t thermo_lookup_type_s[TYPE_S_LOOKUP_SIZE] = {
{ .temp_C=  -50, .mV= -0.236 },
{ .temp_C=  -40, .mV= -0.194 },
{ .temp_C=  -30, .mV= -0.150 },
{ .temp_C=  -20, .mV= -0.103 },
{ .temp_C=  -10, .mV= -0.053 },
{ .temp_C=    0, .mV=  0.000 },
{ .temp_C=   10, .mV=  0.055 },
{ .temp_C=   20, .mV=  0.113 },
{ .temp_C=   30, .mV=  0.173 },
{ .temp_C=   40, .mV=  0.235 },
{ .temp_C=   50, .mV=  0.299 },
{ .temp_C=   60, .mV=  0.365 },
{ .temp_C=   70, .mV=  0.433 },
{ .temp_C=   80, .mV=  0.502 },
{ .temp_C=   90, .mV=  0.573 },
{ .temp_C=  100, .mV=  0.646 },
{ .temp_C=  110, .mV=  0.720 },
{ .temp_C=  120, .mV=  0.795 },
{ .temp_C=  130, .mV=  0.872 },
{ .temp_C=  140, .mV=  0.950 },
{ .temp_C=  150, .mV=  1.029 },
{ .temp_C=  160, .mV=  1.110 },
{ .temp_C=  170, .mV=  1.191 },
{ .temp_C=  180, .mV=  1.273 },
{ .temp_C=  190, .mV=  1.357 },
{ .temp_C=  200, .mV=  1.441 },
{ .temp_C=  210, .mV=  1.526 },
{ .temp_C=  220, .mV=  1.612 },
{ .temp_C=  230, .mV=  1.698 },
{ .temp_C=  240, .mV=  1.786 },
{ .temp_C=  250, .mV=  1.874 },
{ .temp_C=  260, .mV=  1.962 },
{ .temp_C=  270, .mV=  2.052 },
{ .temp_C=  280, .mV=  2.141 },
{ .temp_C=  290, .mV=  2.232 },
{ .temp_C=  300, .mV=  2.323 },
{ .temp_C=  310, .mV=  2.415 },
{ .temp_C=  320, .mV=  2.507 },
{ .temp_C=  330, .mV=  2.599 },
{ .temp_C=  340, .mV=  2.692 },
{ .temp_C=  350, .mV=  2.786 },
{ .temp_C=  360, .mV=  2.880 },
{ .temp_C=  370, .mV=  2.974 },
{ .temp_C=  380, .mV=  3.069 },
{ .temp_C=  390, .mV=  3.164 },
{ .temp_C=  400, .mV=  3.259 },
{ .temp_C=  410, .mV=  3.355 },
{ .temp_C=  420, .mV=  3.451 },
{ .temp_C=  430, .mV=  3.548 },
{ .temp_C=  440, .mV=  3.645 },
{ .temp_C=  450, .mV=  3.742 },
{ .temp_C=  460, .mV=  3.840 },
{ .temp_C=  470, .mV=  3.938 },
{ .temp_C=  480, .mV=  4.036 },
{ .temp_C=  490, .mV=  4.134 },
{ .temp_C=  500, .mV=  4.233 },
{ .temp_C=  510, .mV=  4.332 },
{ .temp_C=  520, .mV=  4.432 },
{ .temp_C=  530, .mV=  4.532 },
{ .temp_C=  540, .mV=  4.632 },
{ .temp_C=  550, .mV=  4.732 },
{ .temp_C=  560, .mV=  4.833 },
{ .temp_C=  570, .mV=  4.934 },
{ .temp_C=  580, .mV=  5.035 },
{ .temp_C=  590, .mV=  5.137 },
{ .temp_C=  600, .mV=  5.239 },
{ .temp_C=  610, .mV=  5.341 },
{ .temp_C=  620, .mV=  5.443 },
{ .temp_C=  630, .mV=  5.546 },
{ .temp_C=  640, .mV=  5.649 },
{ .temp_C=  650, .mV=  5.753 },
{ .temp_C=  660, .mV=  5.857 },
{ .temp_C=  670, .mV=  5.961 },
{ .temp_C=  680, .mV=  6.065 },
{ .temp_C=  690, .mV=  6.170 },
{ .temp_C=  700, .mV=  6.275 },
{ .temp_C=  710, .mV=  6.381 },
{ .temp_C=  720, .mV=  6.486 },
{ .temp_C=  730, .mV=  6.593 },
{ .temp_C=  740, .mV=  6.699 },
{ .temp_C=  750, .mV=  6.806 },
{ .temp_C=  760, .mV=  6.913 },
{ .temp_C=  770, .mV=  7.020 },
{ .temp_C=  780, .mV=  7.128 },
{ .temp_C=  790, .mV=  7.236 },
{ .temp_C=  800, .mV=  7.345 },
{ .temp_C=  810, .mV=  7.454 },
{ .temp_C=  820, .mV=  7.563 },
{ .temp_C=  830, .mV=  7.673 },
{ .temp_C=  840, .mV=  7.783 },
{ .temp_C=  850, .mV=  7.893 },
{ .temp_C=  860, .mV=  8.003 },
{ .temp_C=  870, .mV=  8.114 },
{ .temp_C=  880, .mV=  8.226 },
{ .temp_C=  890, .mV=  8.337 },
{ .temp_C=  900, .mV=  8.449 },
{ .temp_C=  910, .mV=  8.562 },
{ .temp_C=  920, .mV=  8.674 },
{ .temp_C=  930, .mV=  8.787 },
{ .temp_C=  940, .mV=  8.900 },
{ .temp_C=  950, .mV=  9.014 },
{ .temp_C=  960, .mV=  9.128 },
{ .temp_C=  970, .mV=  9.242 },
{ .temp_C=  980, .mV=  9.357 },
{ .temp_C=  990, .mV=  9.472 },
{ .temp_C= 1000, .mV=  9.587 },
{ .temp_C= 1010, .mV=  9.703 },
{ .temp_C= 1020, .mV=  9.819 },
{ .temp_C= 1030, .mV=  9.935 },
{ .temp_C= 1040, .mV= 10.051 },
{ .temp_C= 1050, .mV= 10.168 },
{ .temp_C= 1060, .mV= 10.285 },
{ .temp_C= 1070, .mV= 10.403 },
{ .temp_C= 1080, .mV= 10.520 },
{ .temp_C= 1090, .mV= 10.638 },
{ .temp_C= 1100, .mV= 10.757 },
{ .temp_C= 1110, .mV= 10.875 },
{ .temp_C= 1120, .mV= 10.994 },
{ .temp_C= 1130, .mV= 11.113 },
{ .temp_C= 1140, .mV= 11.232 },
{ .temp_C= 1150, .mV= 11.351 },
{ .temp_C= 1160, .mV= 11.471 },
{ .temp_C= 1170, .mV= 11.590 },
{ .temp_C= 1180, .mV= 11.710 },
{ .temp_C= 1190, .mV= 11.830 },
{ .temp_C= 1200, .mV= 11.951 },
{ .temp_C= 1210, .mV= 12.071 },
{ .temp_C= 1220, .mV= 12.191 },
{ .temp_C= 1230, .mV= 12.312 },
{ .temp_C= 1240, .mV= 12.433 },
{ .temp_C= 1250, .mV= 12.554 },
{ .temp_C= 1260, .mV= 12.675 },
{ .temp_C= 1270, .mV= 12.796 },
{ .temp_C= 1280, .mV= 12.917 },
{ .temp_C= 1290, .mV= 13.038 },
{ .temp_C= 1300, .mV= 13.159 },
{ .temp_C= 1310, .mV= 13.280 },
{ .temp_C= 1320, .mV= 13.402 },
{ .temp_C= 1330, .mV= 13.523 },
{ .temp_C= 1340, .mV= 13.644 },
{ .temp_C= 1350, .mV= 13.766 },
{ .temp_C= 1360, .mV= 13.887 },
{ .temp_C= 1370, .mV= 14.009 },
{ .temp_C= 1380, .mV= 14.130 },
{ .temp_C= 1390, .mV= 14.251 },
{ .temp_C= 1400, .mV= 14.373 },
{ .temp_C= 1410, .mV= 14.494 },
{ .temp_C= 1420, .mV= 14.615 },
{ .temp_C= 1430, .mV= 14.736 },
{ .temp_C= 1440, .mV= 14.857 },
{ .temp_C= 1450, .mV= 14.978 },
{ .temp_C= 1460, .mV= 15.099 },
{ .temp_C= 1470, .mV= 15.220 },
{ .temp_C= 1480, .mV= 15.341 },
{ .temp_C= 1490, .mV= 15.461 },
{ .temp_C= 1500, .mV= 15.582 },
{ .temp_C= 1510, .mV= 15.702 },
{ .temp_C= 1520, .mV= 15.822 },
{ .temp_C= 1530, .mV= 15.942 },
{ .temp_C= 1540, .mV= 16.062 },
{ .temp_C= 1550, .mV= 16.182 },
{ .temp_C= 1560, .mV= 16.301 },
{ .temp_C= 1570, .mV= 16.420 },
{ .temp_C= 1580, .mV= 16.539 },
{ .temp_C= 1590, .mV= 16.658 },
{ .temp_C= 1600, .mV= 16.777 },
{ .temp_C= 1610, .mV= 16.895 },
{ .temp_C= 1620, .mV= 17.013 },
{ .temp_C= 1630, .mV= 17.131 },
{ .temp_C= 1640, .mV= 17.249 },
{ .temp_C= 1650, .mV= 17.366 },
{ .temp_C= 1660, .mV= 17.483 },
{ .temp_C= 1670, .mV= 17.600 },
{ .temp_C= 1680, .mV= 17.717 },
{ .temp_C= 1690, .mV= 17.832 },
{ .temp_C= 1700, .mV= 17.947 },
{ .temp_C= 1710, .mV= 18.061 },
{ .temp_C= 1720, .mV= 18.174 },
{ .temp_C= 1730, .mV= 18.285 },
{ .temp_C= 1740, .mV= 18.395 },
{ .temp_C= 1750, .mV= 18.503 },
{ .temp_C= 1760, .mV= 18.609 }
};
