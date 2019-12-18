

int apt_search(char* packages_list);
int apt_install(char* packages_list);
int apt_autoremove();
int apt_remove(char* packages_list);
int apt_update();
int apt_upgradable();
int apt_upgrade();
int apt_upgrade_packages(char* packages_list);
int apt_remove(char* packages_list);
int apt_download(char* package);