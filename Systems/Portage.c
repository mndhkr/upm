

#include <stdio.h>
#include <stdlib.h>
#include "Portage.h"
#include "../types.h"


int eix_is_present() {
    FILE* eix_path = popen("which eix", "r");
    if (eix_path == NULL) {
        return 0;
    } else {
        return 1;
    }
}

// TODO: Aggiungere la ricerca per descrizione
int emerge_search(char* packages_list, int desc) {
    int res = -1;
    if(eix_is_present()) {
        string command = calloc(5000, sizeof(char));
        sprintf(command, "eix %s", packages_list);
        res = system(command);
        free(command);
    } else {
        string command = calloc(5000, sizeof(char));
        sprintf(command, "emerge -s %s", packages_list);
        res = system(command);
        free(command);
    }
    return res;
}

int emerge_install(char* packages_list, Options options) {
    int res;
    string command = calloc(5000, sizeof(char));
    char switches[100] = "";
    sprintf(switches, "%s %s", options.verbose?"--verbose":"", options.quiet?"--quiet":"");
    sprintf(command, "emerge --ask %s %s", switches, packages_list);
    res = system(command);
    free(command);
    return res;
}

int emerge_depclean() {
    int res;
    res = system("emerge --depclean --ask");
    return res;
}

int emerge_unmerge(char* packages_list) {
    int res;
    string command = calloc(10000, sizeof(char));
    sprintf(command, "emerge --unmerge --ask %s", packages_list);
    res = system(command);
    free(command);
    return res;
}

int emerge_sync(Options options) {
    int res = -1;
    if(eix_is_present()) {
        res = system("eix-sync");
    } else {
        string command = calloc(100, sizeof(char));
        sprintf(command, "emerge --sync%s", options.quiet?" --quiet":"");
        res = system(command);
        free(command);
    }
    return res;
}


int emerge_update_packages(char* packages_list, Options options) {
    int res;
    string command = calloc(10000, sizeof(char));
    char switches[100] = "";
    sprintf(switches, "%s %s", options.verbose?"--verbose":"", options.quiet?"--quiet":"");
    sprintf(command, "emerge --update --ask %s %s", switches, packages_list);
    res = system(command);
    free(command);
    return res;
}

int emerge_list_updatable(Options options) {
    int res;
    char switches[50] = "";
    sprintf(switches, "%s", options.verbose?"--verbose":"");
    char command[200] = "";
    sprintf(command, "emerge --update --pretend --newuse --deep %s system", switches);
    system(command);
    sprintf(command, "emerge --update --pretend --newuse --deep %s world", switches);
    system(command);
    return res = 1;
}

int emerge_update_system(Options options) {
    int res;
    char switches[50] = "";
    sprintf(switches, "%s %s", options.verbose?"--verbose":"", options.quiet?"--quiet":"");
    char command[200] = "";
    sprintf(command, "emerge --update --pretend --newuse --deep %s system", switches);
    res = system(command);
    return res;
}

int emerge_update_world(Options options) {
    int res;
    char switches[50] = "";
    sprintf(switches, "%s %s", options.verbose?"--verbose":"", options.quiet?"--quiet":"");
    char command[200] = "";
    sprintf(command, "emerge --update --pretend --newuse --deep %s world", switches);
    res = system(command);
    return res;
}

int emerge_update(Options options) {
    int res = -1;
    emerge_update_system(options);
    emerge_update_world(options);
    res = 1;
    return res;
}

int emerge_download(char* packages_list) {
    int res;
    string command = calloc(10000, sizeof(char));
    sprintf(command, "emerge --fetchonly --ask %s", packages_list);
    res = system(command);
    free(command);
    return res;
}
