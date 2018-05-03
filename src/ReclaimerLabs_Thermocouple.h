#ifndef RECLAIMERLABS_THERMOCOUPLE_H
#define RECLAIMERLABS_THERMOCOUPLE_H

#ifdef ARDUINO
	#include <Arduino.h>
#else
	#include <application.h>
#endif

typedef struct {
  double temp_C;
  double mV;
} thermo_lookup_entry_t;

typedef enum {
    TYPE_K = 0,
    TYPE_S, 
    TYPE_B, 
    TYPE_E, 
    TYPE_J, 
    TYPE_N, 
    TYPE_R, 
    TYPE_T
} thermoType_t;

class ReclaimerLabs_Thermocouple {
    public:
        ReclaimerLabs_Thermocouple(thermoType_t);
        static int32_t calc_temp(thermoType_t thermoType, double voltage_mV, double cold_junc_C, double *hot_junc_C);
    
    private:
};

#endif /* RECLAIMERLABS_THERMOCOUPLE_H */
