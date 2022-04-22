#pragma XOD dirtieness disable
#pragma XOD require "https://github.com/mikalhart/TinyGPSPlus"
#include <TinyGPSPlus.h>

node {
    void evaluate(Context ctx) {
        double lat1 = getValue<input_Lat1>(ctx);
        double long1 = getValue<input_Long1>(ctx);
        double lat2 = getValue<input_Lat2>(ctx);
        double long2 = getValue<input_Long2>(ctx);
        //distanceBetween is a static method, so we don't need an instance of the class TinyGPSPlus
        emitValue<output_Dist>(ctx, TinyGPSPlus::distanceBetween(lat1, long1, lat2, long2));
    }
}
