#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto gps = getValue<input_GPS>(ctx);

        if (gps->location.isValid()){
            emitValue<output_Lat>(ctx, gps->location.lat());
            emitValue<output_Long>(ctx, gps->location.lng());
            emitValue<output_Done>(ctx, 1);
        }
    }
}
