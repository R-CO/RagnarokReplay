# Analysis Note

## Container Type

notes about contanier type

### PacketStream

Use enum class RagnarokReplay::ChunkHeaderType to classify the meaning of each chunk(packet?). \
e.g.

```cpp=
if (chunk.header == RagnarokReplay::ChunkHeaderType::HEADER_ZC_SKILLINFO_LIST) {
  // do something
}
```

1. HEADER_ZC_SKILLINFO_LIST (271U) => replay owner's skill information list.

### ReplayData

Use enum class RagnarokReplay::ReplayOpCodes to classify the meaning of each chunk(entry?).
Range: 950~970 (to be confirmed)
e.g.

```cpp=
if (chunk.id == RagnarokReplay::ReplayOpCodes::Charactername) {
  // do something
}
```

1. Sex (963) => 0(female), 1(male)
2. Charactername (964) => replay owner's name, BIG-5 encoding
3. Mapname (965) => current map name

### Items

Use enum class RagnarokReplay::ReplayOpCodes to classify the meaning of each chunk(entry?).
Range: 4500~4516 (to be confirmed)
e.g.

```cpp=
if (chunk.id == RagnarokReplay::ReplayOpCodes::EquippedItems) {
  // do something
}
```

### Session

Use enum class RagnarokReplay::ReplayOpCodes to classify the meaning of each chunk(entry?).
Range: 1000~1089 (to be confirmed)
e.g.

```cpp=
if (chunk.id == RagnarokReplay::ReplayOpCodes::EquippedItems) {
  // do something
}
```