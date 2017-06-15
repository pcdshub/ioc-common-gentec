#include <epicsExport.h>
#include <epicsTypes.h>
#include <aSubRecord.h>
#include <registryFunction.h>
#include <string.h>

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

epicsRegisterFunction(gentecNameInit);
epicsRegisterFunction(gentecNameProc);
