#include <epicsExport.h>
#include <epicsTypes.h>
#include <aSubRecord.h>
#include <registryFunction.h>
#include <string.h>
#include <stdio.h>

/*
record(aSub, "RECORDNAME") {
     field(DESC, "Translate Gentec Scales")
     field(INAM, "gentecNameInit")
     field(SNAM, "gentecNameProc")
     field(INPA, "LONGIN_RECORD")
     field(FTA,  "LONG")
     field(VALA, "STRINGOUT_RECORD")
     field(FTVA, "STRING")
}
*/

static char *gentecScaleNames[] = {
    "1p",
    "3p",
    "10p",
    "30p",
    "100p",
    "300p",
    "1n",
    "3n",
    "10n",
    "30n",
    "100n",
    "300n",
    "1u",
    "3u",
    "10u",
    "30u",
    "100u",
    "300u",
    "1m",
    "3m",
    "10m",
    "30m",
    "100m",
    "300m",
    "1",
    "3",
    "10",
    "30",
    "100",
    "300",
    "1k",
    "3k",
    "10k",
    "30k",
    "100k",
    "300k",
    "1meg",
    "3meg",
    "10meg",
    "30meg",
    "100meg",
    "300meg",
};

long gentecNameInit(struct aSubRecord *psub)
{
    psub->dpvt = 0;
    return 0;
}

long gentecNameProc(struct aSubRecord *psub)
{
    epicsInt32 id  = *((epicsInt32 *) (psub->a));
    char *name     = ((char *) (psub->vala));

    if (id < 0 || id >= sizeof(gentecScaleNames) / sizeof(char *))
        strcpy(name, "UNKNOWN");
    else
        strcpy(name, gentecScaleNames[id]);
    printf("%d --> %s\n", id, name);
    return 0;
}

/*
record(aSub, "RECORDNAME") {
     field(DESC, "Translate Gentec Scale Vals")
     field(INAM, "gentecScaleInit")
     field(SNAM, "gentecScaleProc")
     field(INPA, "LONGIN_RECORD")
     field(FTA,  "LONG")
     field(VALA, "AO_RECORD")
     field(FTVA, "STRING")
}
*/

static double gentecScaleValues[] = {
    0.000000000001,
    0.000000000003,
    0.000000000010,
    0.000000000030,
    0.000000000100,
    0.000000000300,
    0.000000001000,
    0.000000003000,
    0.000000010000,
    0.000000030000,
    0.000000100000,
    0.000000300000,
    0.000001000000,
    0.000003000000,
    0.000010000000,
    0.000030000000,
    0.000100000000,
    0.000300000000,
    0.001000000000,
    0.003000000000,
    0.010000000000,
    0.030000000000,
    0.100000000000,
    0.300000000000,
    1.000000000000,
    3.000000000000,
    10.000000000000,
    30.000000000000,
    100.000000000000,
    300.000000000000,
    1000.000000000000,
    3000.000000000000,
    10000.000000000000,
    30000.000000000000,
    100000.000000000000,
    300000.000000000000,
    1000000.000000000000,
    3000000.000000000000,
    10000000.000000000000,
    30000000.000000000000,
    100000000.000000000000,
    300000000.000000000000,
};

long gentecValInit(struct aSubRecord *psub)
{
    psub->dpvt = 0;
    return 0;
}

long gentecValProc(struct aSubRecord *psub)
{
    epicsInt32 id  = *((epicsInt32 *) (psub->a));
    double *value     = ((double *) (psub->vala));

    if (id < 0 || id >= sizeof(gentecScaleValues) / sizeof(double))
    *value = -1;
    else
    *value = gentecScaleValues[id];
    printf("%d --> %f\n", id, *value);
    return 0;
}

epicsRegisterFunction(gentecNameInit);
epicsRegisterFunction(gentecNameProc);
epicsRegisterFunction(gentecValInit);
epicsRegisterFunction(gentecValProc);
