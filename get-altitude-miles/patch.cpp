#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto gps = getValue<input_GPS>(ctx);

        if (gps->altitude.isValid()){
            emitValue<output_Alt>(ctx, gps->altitude.miles());
            emitValue<output_Done>(ctx, 1);
        }
    }
}
