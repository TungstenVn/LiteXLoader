#include "Global.h"


/////////////////// Built in UnlockCmd ///////////////////

THook(void, "?registerCommand@CommandRegistry@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEBDW4CommandPermissionLevel@@UCommandFlag@@3@Z",
    void* a1, void* a2, void* a3, char a4, short a5, short a6)
{
    return original(a1, a2, a3, a4, a5 |= 0x80, a6);
}

THook(bool, "?isExpansionAllowed@CommandSelectorBase@@AEBA_NAEBVCommandOrigin@@@Z",
    CommandSelectorBase* _this, CommandOrigin* a2)
{
    return true;
}