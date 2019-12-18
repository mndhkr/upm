
#include "DNF.h"

int dnf_search(char* packages_list);
int dnf_install(char* packages_list);
int dnf_autoremove();
int dnf_remove(char* packages_list);
int dnf_update();
//int dnf_upgradable();
int dnf_upgrade();
int dnf_upgrade(char* packages_list);
int dnf_download();
