#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto gps = getValue<input_DEV>(ctx);

        emitValue<output_nChar>(ctx, gps->charsProcessed());
        emitValue<output_nSent>(ctx, gps->sentencesWithFix());
        emitValue<output_passChk>(ctx, gps->passedChecksum());
        emitValue<output_failChk>(ctx, gps->failedChecksum());
        emitValue<output_Done>(ctx, 1);

    }
}
