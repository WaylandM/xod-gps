#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto gps = getValue<input_DEV>(ctx);

        if (gps->speed.isValid()){
            emitValue<output_knots>(ctx, gps->speed.knots());
            emitValue<output_Done>(ctx, 1);
        }
    }
}
