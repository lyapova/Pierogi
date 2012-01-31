#include "pirkeysetmetadata.h"

#include <iostream>

PIRKeysetMetaData::PIRKeysetMetaData(
  const char *r,
  PIRMakeName m,
  unsigned int i)
  : keysetName(r),
    make(m),
    id(i)
{
}

bool PIRKeysetMetaData::hasKey(
  PIRKeyName name)
{
  return (keys.find(name) != keys.end());
}


void PIRKeysetMetaData::moveProtocolToThread(
  QThread &thread)
{
  threadableProtocol->moveToThread(&thread);
}


void PIRKeysetMetaData::populateDeviceTypes(
  PIRKeysetWidgetItem *kwi)
{
  PIRDeviceTypeCollection::const_iterator i = deviceTypes.begin();
  while (i != deviceTypes.end())
  {
    kwi->addDeviceType(*i);
    ++i;
  }
}


unsigned int PIRKeysetMetaData::getID()
{
  return id;
}


void PIRKeysetMetaData::addControlledDevice(
  PIRMakeName make,
  const char *model,
  PIRDeviceTypeName type)
{
  controlledDevices.push_back(DeviceInfo(make, model, type));

  deviceTypes.insert(type);
}


void PIRKeysetMetaData::addKey(
  const char *name,
  PIRKeyName key,
  unsigned long data,
  unsigned int size)
{
  // Don't have a system for the unmapped keys yet!
  if (key != Unmapped_Key)
  {
    keys[key] = name;

    threadableProtocol->addKey(key, data, size);
  }
}


void PIRKeysetMetaData::addSIRC12Key(
  const char *name,
  PIRKeyName key,
  unsigned int addressData,
  unsigned int commandData)
{
  if (key != Unmapped_Key)
  {
    keys[key] = name;

    threadableProtocol->addSIRCKey(key, addressData, 5, commandData);
  }
}


void PIRKeysetMetaData::addSIRC15Key(
  const char *name,
  PIRKeyName key,
  unsigned int addressData,
  unsigned int commandData)
{
  if (key != Unmapped_Key)
  {
    keys[key] = name;
    threadableProtocol->addSIRCKey(key, addressData, 8, commandData);
  }
}


void PIRKeysetMetaData::addSIRC20Key(
  const char *name,
  PIRKeyName key,
  unsigned int secondaryAddressData,
  unsigned int primaryAddressData,
  unsigned int commandData)
{
  if (key != Unmapped_Key)
  {
    keys[key] = name;
    threadableProtocol->addSIRC20Key(
      key, secondaryAddressData, primaryAddressData, commandData);
  }
}


void PIRKeysetMetaData::addSharpKey(
  const char *name,
  PIRKeyName key,
  unsigned int addressData,
  unsigned int commandData)
{
  if (key != Unmapped_Key)
  {
    keys[key] = name;
    threadableProtocol->addSharpKey(key, addressData, commandData);
  }
}


void PIRKeysetMetaData::setPreData(
  unsigned long data,
  unsigned int bits)
{
  threadableProtocol->setPreData(data, bits);
}


void PIRKeysetMetaData::setPostData(
  unsigned long data,
  unsigned int bits)
{
  threadableProtocol->setPostData(data, bits);
}


PIRMakeName PIRKeysetMetaData::getMake()
{
  return make;
}

const char *PIRKeysetMetaData::getKeysetName()
{
  return keysetName;
}


void PIRKeysetMetaData::setKeysetName(
  const char *n)
{
  keysetName = n;
}
