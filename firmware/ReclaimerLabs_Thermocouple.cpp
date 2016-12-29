#include "application.h"
#include "ReclaimerLabs_Thermocouple.h"

#include "type_k.cpp"

int32_t ReclaimerLabs_Thermocouple::calc_temp(thermoType_t thermoType, float voltage_mV, float cold_junc_C, float *hot_junc_C) {
    const thermo_lookup_entry_t  *thermo_lookup_table;
          uint32_t                thermo_lookup_size;

    switch (thermoType) {
        case (TYPE_K):
            thermo_lookup_table = thermo_lookup_type_k;
            thermo_lookup_size  = TYPE_K_LOOKUP_SIZE;
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
    float total_mV;
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
