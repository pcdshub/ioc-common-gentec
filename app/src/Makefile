TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build an ioc application
# Use PROD_IOC_RTEMS for RTEMS only
# Use PROD_IOC_Linux for Linux only
PROD_IOC = gentec

# gentec.dbd will be created and installed
DBD += gentec.dbd

# gentec.dbd will be made up from these files:
gentec_DBD += base.dbd
gentec_DBD += iocAdmin.dbd
gentec_DBD += autosaveSupport.dbd
gentec_DBD += asyn.dbd
gentec_DBD += asynRecord.dbd
gentec_DBD += stream.dbd
gentec_DBD += drvAsynIPPort.dbd

# <name>_registerRecordDeviceDriver.cpp will be created from <name>.dbd
gentec_SRCS += gentec_registerRecordDeviceDriver.cpp
gentec_SRCS_DEFAULT += gentecMain.cpp

gentec_LIBS += devIocStats
gentec_LIBS += autosave
gentec_LIBS += stream
gentec_LIBS += asyn
gentec_LIBS += pcre
gentec_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

