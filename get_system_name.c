
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// local includes
#include "defines.h"
#include "get_system_name.h"


string get_system_name() {
	
	// INIT
	FILE* etc_os_release;
	string grepped_ID_line_from_etc;

	grepped_ID_line_from_etc = calloc(512, sizeof(char));

	// RECON
	etc_os_release = popen("grep -e \"^ID=\" /etc/os-release", "r");
	if (etc_os_release == NULL) {
		perror("get_system_name couldn't call `grep`");
		exit(CANT_CALL_GREP_WITH_POPEN);
	}

	// READ
	fscanf(etc_os_release, "%s\n", grepped_ID_line_from_etc);

	// END RECON
	pclose(etc_os_release);

	// PREPARE FOR RETURN
	string system_id = calloc(strlen(grepped_ID_line_from_etc) + 1 , sizeof(char));
	strcpy(system_id, grepped_ID_line_from_etc);

	// FREEING MEMORY
	free(grepped_ID_line_from_etc);

	// RETURN
	return system_id + 3;
}

/*
int main() {
    fprintf(stdout, "%s\n", get_system_name());
    return 0;
}

*/


