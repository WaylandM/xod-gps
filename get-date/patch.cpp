#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto gps = getValue<input_GPS>(ctx);

        if (gps->date.isValid()){
            emitValue<output_Day>(ctx, gps->date.day());
            emitValue<output_Month>(ctx, gps->date.month());
            emitValue<output_Year>(ctx, gps->date.year());
            emitValue<output_Done>(ctx, 1);
        }
    }
}
