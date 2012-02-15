#ifndef PIRKEYSETMETADATA_H
#define PIRKEYSETMETADATA_H

#include "pirkeynames.h"
#include "pirmakenames.h"
#include "pirdevicetypenames.h"

#include <map>
#include <list>

class QThread;

class PIRKeysetWidgetItem;
class PIRProtocol;

typedef std::map<PIRKeyName, const char *> KeyCollection;

class DeviceInfo
{
public:
  DeviceInfo(
    PIRMakeName ma,
    const char *mo,
    PIRDeviceTypeName t)
  : make(ma),
    model(mo),
    type(t)
  {}

  PIRMakeName make;
  const char *model;
  PIRDeviceTypeName type;
};

typedef std::list<DeviceInfo> DeviceCollection;

class PIRKeysetMetaData
{
public:
  PIRKeysetMetaData(
    const char *keysetName,
    PIRMakeName make,
    unsigned int index);

  bool hasKey(
    PIRKeyName name) const;

  unsigned int getID() const;

  PIRMakeName getMake() const;

  const char *getKeysetName() const;

  void moveProtocolToThread(
    QThread *thread);

  void populateDeviceTypes(
    PIRKeysetWidgetItem *kwi) const;

protected:
  void addControlledDevice(
    PIRMakeName make,
    const char *model,
    PIRDeviceTypeName type);

  void addDeviceType(
    PIRDeviceTypeName n);

  void addKey(
    const char *name,
    PIRKeyName key,
    unsigned long data,
    unsigned int size);

  // Special helper methods for SIRC keys:
  void addSIRC12Key(
    const char *name,
    PIRKeyName key,
    unsigned int addressData,
    unsigned int commandData);

  void addSIRC15Key(
    const char *name,
    PIRKeyName key,
    unsigned int addressData,
    unsigned int commandData);

  void addSIRC20Key(
    const char *name,
    PIRKeyName key,
    unsigned int secondaryAddressData,
    unsigned int primaryAddressData,
    unsigned int commandData);

  // Helper method for Sharp keys:
  void addSharpKey(
    const char *name,
    PIRKeyName key,
    unsigned int addressData,
    unsigned int commandData);

  void addNECKey(
    const char *name,
    PIRKeyName key,
    unsigned int addressData,
    unsigned int commandData);

  void addPioneerKey(
    const char *name,
    PIRKeyName key,
    unsigned int addressOne,
    unsigned int commandOne,
    unsigned int addressTwo,
    unsigned int commandTwo);

/*
  void addRCAKey(
    const char *name,
    PIRKeyName key,
    unsigned int addressData,
    unsigned int commandData);
*/

  void addKaseikyoKey(
    const char *name,
    PIRKeyName key,
    unsigned int addressData,
    unsigned int commandData);

  void addDishKey(
    const char *name,
    PIRKeyName key,
    unsigned int firstCommand,
    unsigned int secondCommand);

  void setPreData(
    unsigned long data,
    unsigned int bits);

  void setPostData(
    unsigned long data,
    unsigned int bits);

  KeyCollection keys;

  DeviceCollection controlledDevices;

  PIRProtocol *threadableProtocol;

  void setKeysetName(
    const char *name);

private:
  const char *keysetName;
  PIRMakeName make;
  PIRDeviceTypeCollection deviceTypes;

  unsigned int id;
};


#endif // PIRKEYSETMETADATA_H
