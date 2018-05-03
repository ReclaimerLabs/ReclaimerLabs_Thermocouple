#ifdef ARDUINO
    #include <Arduino.h>
#else
    #include <application.h>
#endif
#include "ReclaimerLabs_Thermocouple.h"

#include "type_k.h"
#include "type_s.h"
#include "type_b.h"
#include "type_e.h"
#include "type_j.h"
#include "type_n.h"
#include "type_r.h"
#include "type_t.h"

int32_t ReclaimerLabs_Thermocouple::calc_temp(thermoType_t thermoType, double voltage_mV, double cold_junc_C, double *hot_junc_C) {
    const thermo_lookup_entry_t  *thermo_lookup_table;
          uint32_t                thermo_lookup_size;

    switch (thermoType) {
        case (TYPE_K):
            thermo_lookup_table = thermo_lookup_type_k;
            thermo_lookup_size  = TYPE_K_LOOKUP_SIZE;
            break;
        case (TYPE_S):
            thermo_lookup_table = thermo_lookup_type_s;
            thermo_lookup_size  = TYPE_S_LOOKUP_SIZE;
            break;
        case (TYPE_B):
            thermo_lookup_table = thermo_lookup_type_b;
            thermo_lookup_size  = TYPE_B_LOOKUP_SIZE;
            break;
        case (TYPE_E):
            thermo_lookup_table = thermo_lookup_type_e;
            thermo_lookup_size  = TYPE_E_LOOKUP_SIZE;
            break;
        case (TYPE_J):
            thermo_lookup_table = thermo_lookup_type_j;
            thermo_lookup_size  = TYPE_J_LOOKUP_SIZE;
            break;
        case (TYPE_N):
            thermo_lookup_table = thermo_lookup_type_n;
            thermo_lookup_size  = TYPE_N_LOOKUP_SIZE;
            break;
        case (TYPE_R):
            thermo_lookup_table = thermo_lookup_type_r;
            thermo_lookup_size  = TYPE_R_LOOKUP_SIZE;
            break;
        case (TYPE_T):
            thermo_lookup_table = thermo_lookup_type_t;
            thermo_lookup_size  = TYPE_T_LOOKUP_SIZE;
            break;
        default:
            return -1;
            break;
    }

    // check if the data is out of range
    if ( (cold_junc_C < thermo_lookup_table[0].temp_C) ||
         (cold_junc_C > thermo_lookup_table[thermo_lookup_size-1].temp_C) ) {
        *hot_junc_C = 0;
        return -2;
    }
    
    // convert cold junction temperature to "voltage"
    // linear search, which could be sped up with binary search for large tables
    uint32_t i=1;
    double total_mV;
    while ( i<(thermo_lookup_size-1)) {
        if ( cold_junc_C <= thermo_lookup_table[i].temp_C ) {
            break;
        }
        i++;
    }

    total_mV = thermo_lookup_table[i-1].mV + 
          ( thermo_lookup_table[i].mV     - thermo_lookup_table[i-1].mV ) *
        ( ( cold_junc_C                   - thermo_lookup_table[i-1].temp_C ) / 
          ( thermo_lookup_table[i].temp_C - thermo_lookup_table[i-1].temp_C )  );
    
    // sum the cold junction "voltage" and thermocouple voltage
    total_mV += voltage_mV;
    
    // check if the new voltage is out of range
    if ( (total_mV < thermo_lookup_table[0].mV) ||
         (total_mV > thermo_lookup_table[thermo_lookup_size-1].mV) ) {
        *hot_junc_C = 0;
        return -3;
    }

    // convert new voltage into temperature
    // linear search, which could be sped up with binary search for large tables
    i=1;
    while ( i<(thermo_lookup_size-1) ) {
        if ( total_mV <= thermo_lookup_table[i].mV ) {
            break;
        }
        i++;
    }
    *hot_junc_C = thermo_lookup_table[i-1].temp_C + 
          ( thermo_lookup_table[i].temp_C - thermo_lookup_table[i-1].temp_C ) *
        ( ( total_mV                      - thermo_lookup_table[i-1].mV ) / 
          ( thermo_lookup_table[i].mV     - thermo_lookup_table[i-1].mV )  );
    
    return 0;
}
