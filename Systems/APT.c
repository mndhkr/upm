
#include <stdlib.h>
#include <stdio.h>

#include "APT.h"


int apt_search(char* packages_list)
{
    char command[5000] = "";
    sprintf(command, "apt search %s", packages_list);
    fprintf(stderr, "debug: Systems/APT.c: apt_search: going to execute the command \"%s\"\n", command);
    int res = system(command);
    return res;
}

int apt_install(char* packages_list)
{
    char command[5000] = "";
    sprintf(command, "apt install %s", packages_list);
    fprintf(stderr, "debug: Systems/APT.c: apt_install: going to execute the command \"%s\"\n", command);
    int res = system(command);
    return res;
}

int apt_autoremove()
{
    char command[100] = "apt autoremove";
    fprintf(stderr, "debug: Systems/APT.c: apt_autoremove: going to execute the command \"%s\"\n", command);
    int res = system(command);
    return res;
}

int apt_remove(char* packages_list)
{
    char command[5000] = "";
    sprintf(command, "apt remove %s", packages_list);
    fprintf(stderr, "debug: Systems/APT.c: apt_remove: going to execute the command \"%s\"\n", command);
    int res = system(command);
    return res;
}

int apt_update()
{
    char command[100] = "apt update";
    fprintf(stderr, "debug: Systems/APT.c: apt_update: going to execute the command \"%s\"\n", command);
    int res = system(command);
    return res;
}

int apt_upgradable()
{
    char command[100] = "apt list --upgradable";
    fprintf(stderr, "debug: Systems/APT.c: apt_upgradable: going to execute the command \"%s\"\n", command);
    int res = system(command);
    return res;
}

int apt_upgrade()
{
    char command[100] = "apt upgrade";
    fprintf(stderr, "debug: Systems/APT.c: apt_upgrade: going to execute the command \"%s\"\n", command);
    int res = system(command);
    return res;
}

int apt_upgrade_packages(char* packages_list) {
    char command[5000] = "";
    sprintf(command, "apt upgrade %s", packages_list);
    fprintf(stderr, "debug: Systems/APT.c: apt_upgrade_packages: going to execute the command \"%s\"\n", command);
    int res = system(command);
    return res;
}

int apt_download(char* package)
{
    char command[5000] = "";
    sprintf(command, "apt download %s", package);
    fprintf(stderr, "debug: Systems/APT.c: apt_download: going to execute the command \"%s\"\n", command);
    int res = system(command);
    return res;
}