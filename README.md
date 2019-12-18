# Unified (Linux) Package Manager: UPM

The aim of this proect is to write a package manager for linux that can work on any distro basing upon the existing and default package manager....

SO: emerge, for gentoo...
apt for debian....
yum/dnf for fedora...

and so on.

the command passed to "this", has to be translated into the native installer command.

so for example "lui install apache" becomes (on mint) apt install apache.

since the search command will issue the default PM search command, the difference in the packages name is irrelevant.

some command will work on every distro, some will not, and for some will will be a workaround.

every help is granted and willed.

anyone can or may partecipate in this project.

YOU are welcome.

Please don't fork it, collaborate.

Ask for permission, and i'll give it to you.

Thank you.

---------------------------------------------------------------------

Implemented:

Commands:
search
install
sync
upgrade
upgradable
remove / uninstall
clean
download

APT:
search
install
sync
upgrade
upgradable
remove / uninstall
clean
download

Portage:
search
install
sync
upgrade
upgradable
remove / uninstall
clean
download

DNF:
to be done.
