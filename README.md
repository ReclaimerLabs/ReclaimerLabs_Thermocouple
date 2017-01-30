# Introduction

This library provides a function that takes in a differential thermocouple voltage, thermocouple type, and cold junction temperature to calculate a hot junction temperature. It uses a lookup table generated from the [**NIST standards**](https://srdata.nist.gov/its90/download/download.html). The calculation method is done as described in section 3 of [**App Note SBAA189**](http://www.ti.com/lit/an/sbaa189/sbaa189.pdf) from TI. 

Check out the other github repos for more information on a library to talk to the [**ADS1118 ADC**](https://github.com/ReclaimerLabs/ReclaimerLabs_ADS1118) and a [**board**](https://github.com/ReclaimerLabs/Remote-Thermal-Monitor) that connects it to a Particle Photon. 

# Example Usage

The function is implemented a static method, so you do not need to create a ReclaimerLabs_Thermocouple object. You can simply call ReclaimerLabs_Thermocouple::calc_temp(). 

For example, TYPE_K is the thermocouple type. diff_volt_mV is the differential voltage in millivolts. cold_junc_C is a float holding the cold junction temperature in degrees Celsius. If return_val is 0, then hot_junc_C will hold the hot junction temperature in degrees Celsius. 

```
    float hot_junc_C;
    int32_t return_val;
    return_val = ReclaimerLabs_Thermocouple::calc_temp(TYPE_K, diff_volt_mV, cold_junc_C, &hot_junc_C);
```

# Questions and Comments

If you have questions or comments, you can email me directly at jason@reclaimerlabs.com. 
