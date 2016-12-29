#include "application.h"

typedef struct {
  float temp_C;
  float mV;
} thermo_lookup_entry_t;

#include "type_k.cpp"

typedef enum {
    TYPE_K
} thermoType_t;

class ReclaimerLabs_Thermocouple {
    public:
        ReclaimerLabs_Thermocouple(thermoType_t);
        static int32_t calc_temp(thermoType_t thermoType, float voltage_mV, float cold_junc_C, float *hot_junc_C);
    
    private:
};
