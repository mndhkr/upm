
#include "../utilities.h"

int emerge_search(char* packages_list, int desc);
int emerge_install(char* packages_list, Options options);
int emerge_depclean();
int emerge_unmerge(char* packages_list);
int emerge_sync(Options options);
int emerge_update_packages(char* packages_list, Options options);
int emerge_list_updatable();
int emerge_update();
int emerge_download(char* packages_list);