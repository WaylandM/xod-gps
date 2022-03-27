#pragma XOD require "https://github.com/mikalhart/TinyGPSPlus"

#include <TinyGPSPlus.h>

node {
    meta {
        using Type = TinyGPSPlus*;
    }

    TinyGPSPlus gps = TinyGPSPlus();

    void evaluate(Context ctx) {
        emitValue<output_GPS>(ctx, &gps);
    }
}
