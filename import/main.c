#include <stdio.h>
#include "FMI3.h"

#define MODEL_IDENTIFIER BouncingBall
#define PLATFORM_BINARY  "E:/WS/fmi-import-export-tutorial-2025/Reference-FMUs-0.0.39/3.0/BouncingBall/binaries/x86_64-windows/BouncingBall.dll"
#define INSTANTIATION_TOKEN "{1AE5E10D-9521-4DE3-80B9-D0EAAA7D5AF1}"
#define OUTPUT_FILE "BouncingBall_out.csv"
#define LOG_FILE "BouncingBall_log.csv"

#define CALL(f) do { status = f; if (status > FMIOK) goto TERMINATE; } while (0)

typedef enum {
    vr_time, vr_h, vr_der_h, vr_v, vr_der_v, vr_g, vr_e, vr_v_min
} ValueReference;

static FMIStatus status = FMIOK;
static FILE *logFile = NULL;
static FILE *outputFile = NULL;
static FMIInstance *S = NULL;

static void logMessage(FMIInstance *instance, FMIStatus status, const char *category, const char *message) {

        switch (status) {
        case FMIOK:
            printf("[OK] ");
            break;
        case FMIWarning:
            printf("[Warning] ");
            break;
        case FMIDiscard:
            printf("[Discard] ");
            break;
        case FMIError:
            printf("[Error] ");
            break;
        case FMIFatal:
            printf("[Fatal] ");
            break;
        case FMIPending:
            printf("[Pending] ");
            break;
    }

    puts(message);
}

static void logFunctionCall(FMIInstance *instance, FMIStatus status, const char *message) {

    if (!logFile) {
        return;
    }

    fputs(message, logFile);

    switch (status) {
    case FMIOK:
        fputs(" -> OK\n", logFile);
        break;
    case FMIWarning:
        fputs(" -> Warning\n", logFile);
        break;
    case FMIDiscard:
        fputs(" -> Discard\n", logFile);
        break;
    case FMIError:
        fputs(" -> Error\n", logFile);
        break;
    case FMIFatal:
        fputs(" -> Fatal\n", logFile);
        break;
    case FMIPending:
        fputs(" -> Pending\n", logFile);
        break;
    default:
        fprintf(logFile, " -> Unknown status (%d)\n", status);
        break;
    }
}

static FILE* createOutputFile(const char* filename) {

    FILE* file = fopen(filename, "w");

    if (file) {
        fputs("time,h,v\n", file);
    }

    return file;
}

static FMIStatus setUp() {

    outputFile = createOutputFile(OUTPUT_FILE);

    if (!outputFile) {
        printf("Failed to open %s.\n", OUTPUT_FILE);
        return FMIError;
    }

    logFile = fopen(LOG_FILE, "w");

    if (!logFile) {
        printf("Failed to open %s.\n", LOG_FILE);
        return FMIError;
    }

    S = FMICreateInstance("instance1", logMessage, logFunctionCall);

    if (!S) {
        printf("Failed to create FMU instance.\n");
        return FMIError;
    }

    return FMILoadPlatformBinary(S, PLATFORM_BINARY);
}

static FMIStatus tearDown() {

    if (S) {

        if (status < FMIError) {

            FMIStatus terminateStatus = FMI3Terminate(S);
            
            if (terminateStatus > status) {
                status = terminateStatus;
            }
        }

        if (status < FMIFatal) {
            FMI3FreeInstance(S);
        }

        FMIFreeInstance(S);

        S = NULL;
    }

    if (outputFile) {
        fclose(outputFile);
    }

    if (logFile) {
        fclose(logFile);
    }

    return status;
}

FMIStatus recordVariables(FMIInstance* S, double time, FILE* outputFile) {

    const fmi3ValueReference valueReferences[2] = { vr_h, vr_v };
    fmi3Float64 values[2] = { 0 };
    FMIStatus status = FMI3GetFloat64(S, valueReferences, 2, values, 2);

    fprintf(outputFile, "%g,%g,%g\n", time, values[0], values[1]);

    return status;
}

int main(int argc, const char* argv[]) {

    const fmi3Float64 startTime = 0.0;    
    const fmi3Float64 stopTime = 3.0;
    const fmi3Float64 h = 1e-3;

    CALL(setUp());

    CALL(FMI3InstantiateCoSimulation(S,
        INSTANTIATION_TOKEN, // instantiationToken
        NULL,                // resourcePath
        fmi3False,           // visible
        fmi3False,           // loggingOn
        fmi3False,           // eventModeUsed
        fmi3False,           // earlyReturnAllowed
        NULL,                // requiredIntermediateVariables
        0,                   // nRequiredIntermediateVariables
        NULL                 // intermediateUpdate
    ));

    // TODO: apply start values

    CALL(FMI3EnterInitializationMode(S, fmi3False, 0.0, startTime, fmi3True, stopTime));

    CALL(FMI3ExitInitializationMode(S));

    for (uint64_t step = 0;; step++) {

        const fmi3Float64 time = step * h;

        CALL(recordVariables(S, time, outputFile));

        // TODO: apply inputs

        if (time >= stopTime) {
            break;
        }

        fmi3Boolean eventEncountered;
        fmi3Boolean terminateSimulation;
        fmi3Boolean earlyReturn;
        fmi3Float64 lastSuccessfulTime;

        CALL(FMI3DoStep(S, time, h, fmi3True, &eventEncountered, &terminateSimulation, &earlyReturn, &lastSuccessfulTime));

        if (terminateSimulation) {
            printf("The FMU requested to terminate the simulation.");
            break;
        }
    }

TERMINATE:
    return tearDown();
}
