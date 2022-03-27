#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto gps = getValue<input_DEV>(ctx);

        if (gps->satellites.isValid()){
            emitValue<output_Count>(ctx, gps->satellites.value());
            emitValue<output_Done>(ctx, 1);
        }
    }
}
