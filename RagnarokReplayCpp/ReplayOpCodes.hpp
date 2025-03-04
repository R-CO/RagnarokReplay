/**
 * Author: R-CO
 * E-mail: daniel1820kobe@gmail.com
 **/
#ifndef RAGNAROKREPLAY_RAGNAROKREPLAYCPP_REPLAYOPCODES_H
#define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_REPLAYOPCODES_H

#include <cstdint>

namespace RagnarokReplay {
enum class ReplayOpCodes : int16_t {
  ZC_ROOM_NEWENTRY = 201,
  ZC_STORE_ENTRY = 202,
  ZC_BUYING_STORE_ENTRY = 204,
  ZC_NOTIFY_MOVEENTRY8 = 208,
  ZC_NOTIFY_STANDENTRY7 = 210,
  ZC_NOTIFY_MOVEENTRY11 = 214,
  ZC_NOTIFY_STANDENTRY11 = 217,

  Begin_950 = 950,
  End_950 = 951,
  Region = 961,
  Service = 962,
  Sex = 963,
  Charactername = 964,
  Mapname = 965,
  Maptype = 966,
  PosX = 967,
  PosY = 968,
  Direction = 969,
  Length = 970,

  Begin_1000 = 1000,
  End_1000 = 1001,
  Aid = 1010,
  Gid = 1011,
  Job = 1014,
  Exp = 1015,
  Level = 1016,
  JobPoint = 1017,
  NextExp = 1018,
  JobLevel = 1019,
  SkillPoint = 1020,
  Str = 1024,
  Agi = 1025,
  Vit = 1026,
  Int = 1027,
  Dex = 1028,
  Luk = 1029,
  PlusStr = 1030,
  PlusAgi = 1031,
  PlusVit = 1032,
  PlusInt = 1033,
  PlusDex = 1034,
  PlusLuk = 1035,
  ASPD = 1036,
  AttackPower = 1037,
  MDefPower = 1038,
  PlusASPD = 1039,
  ItemDefPower = 1040,
  PlusDefPower = 1041,
  RefiningPower = 1042,
  MaxMattPower = 1043,
  MinMattPower = 1044,
  PlusMDefPower = 1045,
  HitSuccessValue = 1046,
  AvoidSuccessValue = 1047,
  CriticalSuccessValue = 1048,
  PlusAvoidSuccessValue = 1049,
  EquipArrowIndex = 1050,
  Money = 1051,
  Speed = 1052,
  Honor = 1053,
  JobExp = 1055,
  Virtue = 1056,
  Head = 1060,
  Shield = 1062,
  BodyPalette = 1063,
  HeadPalette = 1064,
  Accessory = 1065,
  Accessory2 = 1066,
  Accessory3 = 1067,
  EffectState = 1070,
  RobePalette = 1071,
  CartCurCount = 1086,
  CartMaxCount = 1087,
  CartCurWeight = 1088,
  CartMaxWeight = 1089,

  Begin_2000 = 2000,
  End_2000 = 2001,
  BonusStr = 2010,
  BonusAgi = 2011,
  BonusVit = 2012,
  BonusInt = 2013,
  BonusDex = 2014,
  BonusLuk = 2015,

  CurWeight = 2017,
  MaxWeight = 2018,
  Hp = 2029,
  MaxHp = 2030,
  Sp = 2031,
  MaxSp = 2032,

  Begin_3500 = 3500,
  End_3500 = 3501,
  QuestInfo = 3510,

  Begin_4000 = 4000,
  End_4000 = 4001,
  GroupName = 4014,
  GroupInfo = 4015,
  FriendInfo = 4016,

  Begin_4500 = 4500,
  End_4500 = 4501,
  InventoryItems = 4510,
  EquippedItems = 4601,
  EquippedShadowItems = 4603,
  CartItems = 4516,

  Begin_5000 = 5000,
  End_5000 = 5001,

  Begin_5300,
  PetGid = 5301,
  PetIsNameModified = 5302,
  PetName = 5303,
  PetAccessory = 5304,
  PetJob = 5305,
  PetLevel = 5306,
  PetFullness = 5307,
  PetRelation = 5308,
  PetEggIndex = 5309,
  PetOldFullness = 5310,
  End_5300,

  Begin_5500 = 5500,
  End_5500 = 5501,

  Begin_6500 = 6500,
  End_6500 = 6501,

  Begin_7000 = 7000,
  End_7000 = 7001,

  Begin_8000 = 8000,
  End_8000 = 8001,

  Begin_13000 = 13000,
  End_13000 = 13001,

  Begin_14000 = 14000,
  End_14000 = 14001,

  Begin_15000 = 15000,
  End_15000 = 15001,

  Begin_17000 = 17000,
  End_17000 = 17001,

  Begin_19000 = 19000,
  End_19000 = 19001,
  EfstInfo = 19011,

  Begin_20000 = 20000,
  End_20000 = 20001,

  Begin_25000 = 25000,
  End_25000 = 25001,

  Begin_26000 = 26000,
  End_26000 = 26001
};  // end of enum class ReplayOpCodes
}  // end of namespace RagnarokReplay

#endif  // end of define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_REPLAYOPCODES_H
