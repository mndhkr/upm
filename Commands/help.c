#include "help.h"

#include <stdio.h>

void pm_help_command() {
    putchar('\n');
    printf("help\t\tPrint this help and exits.");
    putchar('\n');
    printf("install\t\tInstalls a package or a list of packages (space separated).");
    putchar('\n');
    printf("search\t\tSearches for a package (or a list of them) in the registered repositories.");
    putchar('\n');
    printf("clean\t\tCleans the system from useless packages.");
    putchar('\n');
    printf("remove\t\tRemoves the package (or list of packages) specified.");
    putchar('\n');
    printf("uninstall\tEquivalent to \"remove\".");
    putchar('\n');
    printf("sync\t\tSyncronizes local cache with the remote repositories.");
    putchar('\n');
    printf("upgradable\tShows the list of upgradable packages.");
    putchar('\n');
    printf("update\t\tUpdates the specified packages (where possible).");
    putchar('\n');
    printf("upgrade\t\tUpgrades all the packages installed on the system.");
    putchar('\n');
    printf("download\tDownloads a package or a list of packages without installing it/them.");
    putchar('\n');

    putchar('\n');
    fflush(stdout);
}