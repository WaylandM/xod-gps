#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto gps = getValue<input_GPS>(ctx);

        if (gps->time.isValid()){
            emitValue<output_Hour>(ctx, gps->time.hour());
            emitValue<output_Min>(ctx, gps->time.minute());
            emitValue<output_Sec>(ctx, gps->time.second());
            emitValue<output_Done>(ctx, 1);
        }
    }
}
