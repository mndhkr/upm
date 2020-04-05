#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// RECON
#include "get_system_name.h"

// SYSTEMS
#include "Systems/APT.h"
#include "Systems/Portage.h"

// THIS
#include "Commands/help.h"

// RETURN VALUES
#include "defines.h"

// TYPES
#include "types.h"


int main(int argc, char** argv) {

    if(argc == 1) {
        printf("\nNo command given.\nUsage: \n");
        pm_help_command();
        return NO_COMMAND_GIVEN;
    }


    string system_name = get_system_name();

    string command = argv[1];

    Options options = get_options(argv, argc);

    string packages = merge(argv, 2, argc);

    if(strcmp(command, "help") == 0) {
        pm_help_command();
        return 0;
    }

    if(strcmp(system_name, "linuxmint") == 0 || strcmp(system_name, "ubuntu") == 0) {
        if(strcmp(command, "search") == 0) {
            apt_search(packages);
        }
        if(strcmp(command, "install") == 0) {
            apt_install(packages);
        }
        if(strcmp(command, "clean") == 0) {
            apt_autoremove();
        }
        if(strcmp(command, "uninstall") == 0 || strcmp(command, "remove") == 0) {
            apt_remove(packages);
        }
        if(strcmp(command, "sync") == 0) {
            apt_update();
        }
        if(strcmp(command, "update") == 0) {
            apt_upgrade_packages(packages);
        }
        if(strcmp(command, "upgradable") == 0) {
            apt_upgradable();
        }
        if(strcmp(command, "upgrade") == 0) {
            apt_upgrade();
        }
        if(strcmp(command, "download") == 0) {
            apt_download(packages);
        }
    }


    if(strcmp(system_name, "gentoo") == 0) {
        if(strcmp(command, "search") == 0) {
            emerge_search(packages, 0);
        }
        if(strcmp(command, "install") == 0) {
            emerge_install(packages, options);
        }
        if(strcmp(command, "clean") == 0) {
            emerge_depclean();
        }
        if(strcmp(command, "uninstall") == 0 || strcmp(command, "remove") == 0) {
            emerge_unmerge(packages);
        }
        if(strcmp(command, "sync") == 0) {
            emerge_sync(options);
        }
        if(strcmp(command, "update") == 0) {
            emerge_update_packages(packages, options);
        }
        if(strcmp(command, "upgradable") == 0) {
            emerge_list_updatable();
        }
        if(strcmp(command, "upgrade") == 0) {
            emerge_update();
        }
        if(strcmp(command, "download") == 0) {
            emerge_download(packages);
        }
    }


    return 0;
}
