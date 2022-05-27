#pragma XOD dirtieness disable
#pragma XOD require "https://github.com/mikalhart/TinyGPSPlus"
#include <TinyGPSPlus.h>

node {
    CStringView view = CStringView(view);
    char cString[4];
    
    void evaluate(Context ctx) {
        double course = getValue<input_Course>(ctx);
        //cardinal is a static method, so we don't need an instance of the class TinyGPSPlus
        String str = TinyGPSPlus::cardinal(course);
        int strLen = str.length() + 1;
        str.toCharArray(cString, strLen);
        view=CStringView(cString);
        emitValue<output_Card>(ctx, XString(&view));
    }
}
