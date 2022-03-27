#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto gps = getValue<input_GPS>(ctx);
        auto uart = getValue<input_UART>(ctx);
        auto wait = getValue<input_Wait>(ctx);

        // Ensure that gps instance is being fed. See smartDelay in:
        // https://github.com/mikalhart/TinyGPSPlus/blob/master/examples/FullExample/FullExample.ino
        uint8_t byte = 0x00;
        uint32_t start = millis(); 
        
        do {
            while (uart->available()) {
                uart->readByte(&byte);
                gps->encode(byte);
            }
        } while (millis() - start < wait);
        
        emitValue<output_Done>(ctx, 1);
    }
}
