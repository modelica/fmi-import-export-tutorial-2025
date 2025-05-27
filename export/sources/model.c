/* Generated with FMPy 0.3.26 */

#include <string.h>
#include "fmi3Functions.h"


#define INSTANTIATION_TOKEN "d83d8f15-5304-4681-9307-cd686d28246c"

typedef enum {

    vr_time,
    vr_p0,
    vr_p1,
    vr_p2,
    vr_p3,
    vr_p4,
    vr_u0,
    vr_u1,
    vr_u2,
    vr_u3,
    vr_u4,
    vr_y0,
    vr_y1,
    vr_y2,
    vr_y3,
    vr_y4,
    vr_x0,
    vr_x1,
    vr_x2,
    vr_x3,
    vr_x4,

} ValueReference;

typedef struct {

    fmi3Float64 time;
    fmi3Float64 p0;
    fmi3Float64 p1;
    fmi3Float64 p2;
    fmi3Float64 p3;
    fmi3Float64 p4;
    fmi3Float64 u0;
    fmi3Float64 u1;
    fmi3Float64 u2;
    fmi3Float64 u3;
    fmi3Float64 u4;
    fmi3Float64 y0;
    fmi3Float64 y1;
    fmi3Float64 y2;
    fmi3Float64 y3;
    fmi3Float64 y4;
    fmi3Float64 x0;
    fmi3Float64 x1;
    fmi3Float64 x2;
    fmi3Float64 x3;
    fmi3Float64 x4;

    fmi3InstanceEnvironment instanceEnvironment;
    fmi3LogMessageCallback logMessage;

} Model;

static void reset(Model* instance) {

    instance->time = 0;
    instance->p0 = 0;
    instance->p1 = 0;
    instance->p2 = 0;
    instance->p3 = 0;
    instance->p4 = 0;
    instance->u0 = 0;
    instance->u1 = 0;
    instance->u2 = 0;
    instance->u3 = 0;
    instance->u4 = 0;
    instance->y0 = 0;
    instance->y1 = 0;
    instance->y2 = 0;
    instance->y3 = 0;
    instance->y4 = 0;
    instance->x0 = 0;
    instance->x1 = 0;
    instance->x2 = 0;
    instance->x3 = 0;
    instance->x4 = 0;

}

#define BEGIN_FUNCTION() \
    fmi3Status status = fmi3OK; \
    Model* model = (Model*)instance; \
    if (!model) { \
        status = fmi3Error; \
        goto TERMINATE; \
    }

#define END_FUNCTION() \
TERMINATE: \
    return status;

#define LOG_CATEGORY_ERROR "logStatusError"

#define ERROR(message) \
    model->logMessage(model->instanceEnvironment, fmi3Error, "Error", #message); \
    status = fmi3Error; \
    goto TERMINATE;

#define UNUSED(variable) \
    (void)variable

#define NOT_IMPLEMENTED() \
    BEGIN_FUNCTION(); \
    ERROR("Function is not implemented."); \
    END_FUNCTION();

/***************************************************
Types for Common Functions
****************************************************/

/* Inquire version numbers and setting logging status */
const char* fmi3GetVersion(void) {
    return fmi3Version;
}

fmi3Status fmi3SetDebugLogging(fmi3Instance instance,
    fmi3Boolean loggingOn,
    size_t nCategories,
    const fmi3String categories[]) {
    UNUSED(loggingOn);
    UNUSED(nCategories);
    UNUSED(categories);
    NOT_IMPLEMENTED();
}

/* Creation and destruction of FMU instances and setting debug status */
fmi3Instance fmi3InstantiateModelExchange(
    fmi3String                 instanceName,
    fmi3String                 instantiationToken,
    fmi3String                 resourcePath,
    fmi3Boolean                visible,
    fmi3Boolean                loggingOn,
    fmi3InstanceEnvironment    instanceEnvironment,
    fmi3LogMessageCallback     logMessage) {

    UNUSED(instanceName);
    UNUSED(instantiationToken);
    UNUSED(resourcePath);
    UNUSED(visible);
    UNUSED(loggingOn);
    UNUSED(instanceEnvironment);

    if (logMessage) {
        logMessage(instanceEnvironment, fmi3Error, "Error", "Interface type Model Exchange is not supported.");
    }

    return NULL;
}

fmi3Instance fmi3InstantiateCoSimulation(
    fmi3String                     instanceName,
    fmi3String                     instantiationToken,
    fmi3String                     resourcePath,
    fmi3Boolean                    visible,
    fmi3Boolean                    loggingOn,
    fmi3Boolean                    eventModeUsed,
    fmi3Boolean                    earlyReturnAllowed,
    const fmi3ValueReference       requiredIntermediateVariables[],
    size_t                         nRequiredIntermediateVariables,
    fmi3InstanceEnvironment        instanceEnvironment,
    fmi3LogMessageCallback         logMessage,
    fmi3IntermediateUpdateCallback intermediateUpdate) {

    UNUSED(instanceName);
    UNUSED(resourcePath);
    UNUSED(visible);
    UNUSED(loggingOn);
    UNUSED(eventModeUsed);
    UNUSED(earlyReturnAllowed);
    UNUSED(requiredIntermediateVariables);
    UNUSED(nRequiredIntermediateVariables);
    UNUSED(intermediateUpdate);

    if (!logMessage) {
        return NULL;
    }

    if (!instantiationToken) {
        logMessage(instanceEnvironment, fmi3Error, LOG_CATEGORY_ERROR, "Argument instantiationToken must not be NULL.");
        return NULL;
    } else if (strcmp(instantiationToken, INSTANTIATION_TOKEN)) {
        logMessage(instanceEnvironment, fmi3Error, LOG_CATEGORY_ERROR, "Wrong instantiationToken.");
        return NULL;
    }

    Model* model = (Model*)calloc(1, sizeof(Model));

    if (!model) {
        return NULL;
    }

    model->instanceEnvironment = instanceEnvironment;
    model->logMessage = logMessage;

    reset(model);

    return model;
}

fmi3Instance fmi3InstantiateScheduledExecution(
    fmi3String                     instanceName,
    fmi3String                     instantiationToken,
    fmi3String                     resourcePath,
    fmi3Boolean                    visible,
    fmi3Boolean                    loggingOn,
    fmi3InstanceEnvironment        instanceEnvironment,
    fmi3LogMessageCallback         logMessage,
    fmi3ClockUpdateCallback        clockUpdate,
    fmi3LockPreemptionCallback     lockPreemption,
    fmi3UnlockPreemptionCallback   unlockPreemption) {

    UNUSED(instanceName);
    UNUSED(instantiationToken);
    UNUSED(resourcePath);
    UNUSED(visible);
    UNUSED(loggingOn);
    UNUSED(instanceEnvironment);
    UNUSED(clockUpdate);
    UNUSED(lockPreemption);
    UNUSED(unlockPreemption);

    if (logMessage) {
        logMessage(instanceEnvironment, fmi3Error, "Error", "Interface type Scheduled Execution is not supported.");
    }

    return NULL;
}

void fmi3FreeInstance(fmi3Instance instance) {
    free(instance);
}

/* Enter and exit initialization mode, enter event mode, terminate and reset */
fmi3Status fmi3EnterInitializationMode(fmi3Instance instance,
    fmi3Boolean toleranceDefined,
    fmi3Float64 tolerance,
    fmi3Float64 startTime,
    fmi3Boolean stopTimeDefined,
    fmi3Float64 stopTime) {

    UNUSED(instance);
    UNUSED(toleranceDefined);
    UNUSED(tolerance);
    UNUSED(startTime);
    UNUSED(stopTimeDefined);
    UNUSED(stopTime);

    return fmi3OK;
}

fmi3Status fmi3ExitInitializationMode(fmi3Instance instance) {
    UNUSED(instance);
    return fmi3OK;
}

fmi3Status fmi3EnterEventMode(fmi3Instance instance) {
    NOT_IMPLEMENTED();
}

fmi3Status fmi3Terminate(fmi3Instance instance) {
    UNUSED(instance);
    return fmi3OK;
}

fmi3Status fmi3Reset(fmi3Instance instance) {
    BEGIN_FUNCTION();
    reset((Model*)instance);
    END_FUNCTION();
}

/* Getting and setting variable values */

fmi3Status fmi3GetFloat32(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    fmi3Float32 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetFloat64(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    fmi3Float64 values[],
    size_t nValues) {

    BEGIN_FUNCTION();

    if (nValueReferences != nValues) {
        ERROR("Arguments nValueReferences and nValues must be equal.");
    }

    for (size_t i = 0; i < nValueReferences; i++) {
        const ValueReference valueReference = valueReferences[i];
        switch (valueReference) {
        case vr_time:
            values[i] = model->time;
            break;
        case vr_p0:
            values[i] = model->p0;
            break;
        case vr_p1:
            values[i] = model->p1;
            break;
        case vr_p2:
            values[i] = model->p2;
            break;
        case vr_p3:
            values[i] = model->p3;
            break;
        case vr_p4:
            values[i] = model->p4;
            break;
        case vr_u0:
            values[i] = model->u0;
            break;
        case vr_u1:
            values[i] = model->u1;
            break;
        case vr_u2:
            values[i] = model->u2;
            break;
        case vr_u3:
            values[i] = model->u3;
            break;
        case vr_u4:
            values[i] = model->u4;
            break;
        case vr_y0:
            values[i] = model->y0;
            break;
        case vr_y1:
            values[i] = model->y1;
            break;
        case vr_y2:
            values[i] = model->y2;
            break;
        case vr_y3:
            values[i] = model->y3;
            break;
        case vr_y4:
            values[i] = model->y4;
            break;
        case vr_x0:
            values[i] = model->x0;
            break;
        case vr_x1:
            values[i] = model->x1;
            break;
        case vr_x2:
            values[i] = model->x2;
            break;
        case vr_x3:
            values[i] = model->x3;
            break;
        case vr_x4:
            values[i] = model->x4;
            break;
        default:
            ERROR("Unknown value reference for variable type Float64.");
        }
    }

    END_FUNCTION();
}

fmi3Status fmi3GetInt8(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    fmi3Int8 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetUInt8(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    fmi3UInt8 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetInt16(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    fmi3Int16 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetUInt16(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    fmi3UInt16 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetInt32(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    fmi3Int32 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetUInt32(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    fmi3UInt32 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetInt64(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    fmi3Int64 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetUInt64(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    fmi3UInt64 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetBoolean(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    fmi3Boolean values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetString(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    fmi3String values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetBinary(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    size_t valueSizes[],
    fmi3Binary values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(valueSizes);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetClock(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    fmi3Clock values[]) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetFloat32(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3Float32 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetFloat64(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3Float64 values[],
    size_t nValues) {

    BEGIN_FUNCTION();

    if (nValueReferences != nValues) {
        ERROR("Arguments nValueReferences and nValues must be equal.");
    }

    for (size_t i = 0; i < nValueReferences; i++) {
        const ValueReference valueReference = valueReferences[i];
        const fmi3Float64 value = values[i];
        switch (valueReference) {
        case vr_time:
            model->time = value;
            break;
        case vr_p0:
            model->p0 = value;
            break;
        case vr_p1:
            model->p1 = value;
            break;
        case vr_p2:
            model->p2 = value;
            break;
        case vr_p3:
            model->p3 = value;
            break;
        case vr_p4:
            model->p4 = value;
            break;
        case vr_u0:
            model->u0 = value;
            break;
        case vr_u1:
            model->u1 = value;
            break;
        case vr_u2:
            model->u2 = value;
            break;
        case vr_u3:
            model->u3 = value;
            break;
        case vr_u4:
            model->u4 = value;
            break;
        case vr_y0:
            model->y0 = value;
            break;
        case vr_y1:
            model->y1 = value;
            break;
        case vr_y2:
            model->y2 = value;
            break;
        case vr_y3:
            model->y3 = value;
            break;
        case vr_y4:
            model->y4 = value;
            break;
        case vr_x0:
            model->x0 = value;
            break;
        case vr_x1:
            model->x1 = value;
            break;
        case vr_x2:
            model->x2 = value;
            break;
        case vr_x3:
            model->x3 = value;
            break;
        case vr_x4:
            model->x4 = value;
            break;
        default:
            ERROR("Unknown value reference for variable type Float64.");
        }
    }

    END_FUNCTION();
}

fmi3Status fmi3SetInt8(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3Int8 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetUInt8(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3UInt8 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetInt16(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3Int16 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetUInt16(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3UInt16 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetInt32(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3Int32 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetUInt32(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3UInt32 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetInt64(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3Int64 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetUInt64(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3UInt64 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetBoolean(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3Boolean values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetString(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3String values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetBinary(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const size_t valueSizes[],
    const fmi3Binary values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(valueSizes);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}


fmi3Status fmi3SetClock(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3Clock values[]) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(values);

    NOT_IMPLEMENTED();
}

/* Getting Variable Dependency Information */

fmi3Status fmi3GetNumberOfVariableDependencies(fmi3Instance instance,
    fmi3ValueReference valueReference,
    size_t* nDependencies) {

    UNUSED(valueReference);
    UNUSED(nDependencies);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetVariableDependencies(fmi3Instance instance,
    fmi3ValueReference dependent,
    size_t elementIndicesOfDependent[],
    fmi3ValueReference independents[],
    size_t elementIndicesOfIndependents[],
    fmi3DependencyKind dependencyKinds[],
    size_t nDependencies) {

    UNUSED(dependent);
    UNUSED(elementIndicesOfDependent);
    UNUSED(independents);
    UNUSED(elementIndicesOfIndependents);
    UNUSED(dependencyKinds);
    UNUSED(nDependencies);

    NOT_IMPLEMENTED();
}

/* Getting and setting the internal FMU state */

fmi3Status fmi3GetFMUState(fmi3Instance instance, fmi3FMUState* FMUState) {

    UNUSED(FMUState);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetFMUState(fmi3Instance instance, fmi3FMUState  FMUState) {

    UNUSED(FMUState);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3FreeFMUState(fmi3Instance instance, fmi3FMUState* FMUState) {

    UNUSED(FMUState);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SerializedFMUStateSize(fmi3Instance instance,
    fmi3FMUState FMUState,
    size_t* size) {

    UNUSED(FMUState);
    UNUSED(size);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SerializeFMUState(fmi3Instance instance,
    fmi3FMUState FMUState,
    fmi3Byte serializedState[],
    size_t size) {

    UNUSED(FMUState);
    UNUSED(serializedState);
    UNUSED(size);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3DeserializeFMUState(fmi3Instance instance,
    const fmi3Byte serializedState[],
    size_t size,
    fmi3FMUState* FMUState) {

    UNUSED(serializedState);
    UNUSED(size);
    UNUSED(FMUState);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetDirectionalDerivative(fmi3Instance instance,
    const fmi3ValueReference unknowns[],
    size_t nUnknowns,
    const fmi3ValueReference knowns[],
    size_t nKnowns,
    const fmi3Float64 seed[],
    size_t nSeed,
    fmi3Float64 sensitivity[],
    size_t nSensitivity) {

    UNUSED(unknowns);
    UNUSED(nUnknowns);
    UNUSED(knowns);
    UNUSED(nKnowns);
    UNUSED(seed);
    UNUSED(nSeed);
    UNUSED(sensitivity);
    UNUSED(nSensitivity);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetAdjointDerivative(fmi3Instance instance,
    const fmi3ValueReference unknowns[],
    size_t nUnknowns,
    const fmi3ValueReference knowns[],
    size_t nKnowns,
    const fmi3Float64 seed[],
    size_t nSeed,
    fmi3Float64 sensitivity[],
    size_t nSensitivity) {

    UNUSED(unknowns);
    UNUSED(nUnknowns);
    UNUSED(knowns);
    UNUSED(nKnowns);
    UNUSED(seed);
    UNUSED(nSeed);
    UNUSED(sensitivity);
    UNUSED(nSensitivity);

    NOT_IMPLEMENTED();
}

/* Entering and exiting the Configuration or Reconfiguration Mode */

fmi3Status fmi3EnterConfigurationMode(fmi3Instance instance) {
    NOT_IMPLEMENTED();
}

fmi3Status fmi3ExitConfigurationMode(fmi3Instance instance) {
    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetIntervalDecimal(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    fmi3Float64 intervals[],
    fmi3IntervalQualifier qualifiers[]) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(intervals);
    UNUSED(qualifiers);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetIntervalFraction(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    fmi3UInt64 counters[],
    fmi3UInt64 resolutions[],
    fmi3IntervalQualifier qualifiers[]) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(counters);
    UNUSED(resolutions);
    UNUSED(qualifiers);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetShiftDecimal(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    fmi3Float64 shifts[]) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(shifts);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetShiftFraction(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    fmi3UInt64 counters[],
    fmi3UInt64 resolutions[]) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(counters);
    UNUSED(resolutions);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetIntervalDecimal(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3Float64 intervals[]) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(intervals);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetIntervalFraction(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3UInt64 counters[],
    const fmi3UInt64 resolutions[]) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(counters);
    UNUSED(resolutions);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetShiftDecimal(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3Float64 shifts[]) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(shifts);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetShiftFraction(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3UInt64 counters[],
    const fmi3UInt64 resolutions[]) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(counters);
    UNUSED(resolutions);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3EvaluateDiscreteStates(fmi3Instance instance) {
    NOT_IMPLEMENTED();
}

fmi3Status fmi3UpdateDiscreteStates(fmi3Instance instance,
    fmi3Boolean* discreteStatesNeedUpdate,
    fmi3Boolean* terminateSimulation,
    fmi3Boolean* nominalsOfContinuousStatesChanged,
    fmi3Boolean* valuesOfContinuousStatesChanged,
    fmi3Boolean* nextEventTimeDefined,
    fmi3Float64* nextEventTime) {

    UNUSED(discreteStatesNeedUpdate);
    UNUSED(terminateSimulation);
    UNUSED(nominalsOfContinuousStatesChanged);
    UNUSED(valuesOfContinuousStatesChanged);
    UNUSED(nextEventTimeDefined);
    UNUSED(nextEventTime);

    NOT_IMPLEMENTED();
}

/***************************************************
Types for Functions for Model Exchange
****************************************************/

fmi3Status fmi3EnterContinuousTimeMode(fmi3Instance instance) {
    NOT_IMPLEMENTED();
}

fmi3Status fmi3CompletedIntegratorStep(fmi3Instance instance,
    fmi3Boolean  noSetFMUStatePriorToCurrentPoint,
    fmi3Boolean* enterEventMode,
    fmi3Boolean* terminateSimulation) {

    UNUSED(noSetFMUStatePriorToCurrentPoint);
    UNUSED(enterEventMode);
    UNUSED(terminateSimulation);

    NOT_IMPLEMENTED();
}

/* Providing independent variables and re-initialization of caching */

fmi3Status fmi3SetTime(fmi3Instance instance, fmi3Float64 time) {

    UNUSED(time);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3SetContinuousStates(fmi3Instance instance,
    const fmi3Float64 continuousStates[],
    size_t nContinuousStates) {

    UNUSED(continuousStates);
    UNUSED(nContinuousStates);

    NOT_IMPLEMENTED();
}

/* Evaluation of the model equations */

fmi3Status fmi3GetContinuousStateDerivatives(fmi3Instance instance,
    fmi3Float64 derivatives[],
    size_t nContinuousStates) {

    UNUSED(derivatives);
    UNUSED(nContinuousStates);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetEventIndicators(fmi3Instance instance,
    fmi3Float64 eventIndicators[],
    size_t nEventIndicators) {

    UNUSED(eventIndicators);
    UNUSED(nEventIndicators);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetContinuousStates(fmi3Instance instance,
    fmi3Float64 continuousStates[],
    size_t nContinuousStates) {

    UNUSED(continuousStates);
    UNUSED(nContinuousStates);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetNominalsOfContinuousStates(fmi3Instance instance,
    fmi3Float64 nominals[],
    size_t nContinuousStates) {

    UNUSED(nominals);
    UNUSED(nContinuousStates);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetNumberOfEventIndicators(fmi3Instance instance,
    size_t* nEventIndicators) {

    UNUSED(nEventIndicators);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetNumberOfContinuousStates(fmi3Instance instance,
    size_t* nContinuousStates) {

    UNUSED(nContinuousStates);

    NOT_IMPLEMENTED();
}

/***************************************************
Types for Functions for Co-Simulation
****************************************************/

/* Simulating the FMU */

fmi3Status fmi3EnterStepMode(fmi3Instance instance) {
    NOT_IMPLEMENTED();
}

fmi3Status fmi3GetOutputDerivatives(fmi3Instance instance,
    const fmi3ValueReference valueReferences[],
    size_t nValueReferences,
    const fmi3Int32 orders[],
    fmi3Float64 values[],
    size_t nValues) {

    UNUSED(valueReferences);
    UNUSED(nValueReferences);
    UNUSED(orders);
    UNUSED(values);
    UNUSED(nValues);

    NOT_IMPLEMENTED();
}

fmi3Status fmi3DoStep(fmi3Instance instance,
    fmi3Float64 currentCommunicationPoint,
    fmi3Float64 communicationStepSize,
    fmi3Boolean noSetFMUStatePriorToCurrentPoint,
    fmi3Boolean* eventHandlingNeeded,
    fmi3Boolean* terminateSimulation,
    fmi3Boolean* earlyReturn,
    fmi3Float64* lastSuccessfulTime) {

    UNUSED(instance);
    UNUSED(currentCommunicationPoint);
    UNUSED(communicationStepSize);
    UNUSED(noSetFMUStatePriorToCurrentPoint);
    UNUSED(eventHandlingNeeded);
    UNUSED(terminateSimulation);
    UNUSED(earlyReturn);
    UNUSED(lastSuccessfulTime);

    return fmi3OK;
}

/***************************************************
Types for Functions for Scheduled Execution
****************************************************/

fmi3Status fmi3ActivateModelPartition(fmi3Instance instance,
    fmi3ValueReference clockReference,
    fmi3Float64 activationTime) {

    UNUSED(clockReference);
    UNUSED(activationTime);

    NOT_IMPLEMENTED();
}