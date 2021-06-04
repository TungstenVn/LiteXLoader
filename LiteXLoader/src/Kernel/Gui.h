#include "Global.h"
#include <string>
#include <vector>

int Raw_SendSimpleForm(Player* player,const std::string &title,
    const std::string &content,const std::string &buttons);

int Raw_SendModalForm(Player* player,const std::string &title,
    const std::string &content,const std::string &button1,const std::string &button2);

int Raw_SendCustomForm(Player* player,const std::string &data);

bool Raw_CancelForm(int formId);