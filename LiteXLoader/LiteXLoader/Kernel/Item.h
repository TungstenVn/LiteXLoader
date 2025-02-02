#include <string>
#include <vector>

class Actor;
class ItemStack;
class Tag;
class FloatVec4;

ItemStack* Raw_NewItem();
ItemStack* Raw_NewItem(std::string type, int count);
ItemStack* Raw_NewItem(Tag* tag);
ItemStack* Raw_CloneItem(ItemStack* item);
Actor* Raw_SpawnItemByItemStack(ItemStack* item, const FloatVec4& pos);

std::string Raw_GetItemName(ItemStack* item);
std::string Raw_GetCustomName(ItemStack* item);
std::string Raw_GetItemTypeName(ItemStack* item);
int Raw_GetItemId(ItemStack* item);
int Raw_GetItemAux(ItemStack* item);
int Raw_GetCount(ItemStack* item);

bool Raw_SetItem(ItemStack* oldItem, ItemStack* newItem);
bool Raw_IsNull(ItemStack* item);
bool Raw_SetNull(ItemStack* item);
bool Raw_SetLore(ItemStack* item, std::vector<std::string> lores);