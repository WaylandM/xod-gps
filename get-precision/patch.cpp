#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto gps = getValue<input_DEV>(ctx);

        if (gps->hdop.isValid()){
            emitValue<output_HDOP>(ctx, gps->hdop.hdop());
            emitValue<output_Done>(ctx, 1);
        }
    }
}
