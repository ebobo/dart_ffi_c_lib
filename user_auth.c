#include <string.h>
#include <stdbool.h>


bool am4_access_control_prompt_needed(int argc, char ** argv) {
    // Implement logic
    if (argc % 2 == 0) {
        return true;
    } else {
      return false;   
    }
    return true;
}

char * am4_access_control_get_current_user(void) {
    // Implement logic
    return "petter";
}

bool am4_access_control_verify_password(char * user, char * password) {
    // Implement logic
    if (strcmp(user, "petter") == 0 && strcmp(password, "hvaforno") == 0) {
        return true;
    } else if (strcmp(user, "espen") == 0 && strcmp(password, "hvaforno") != 0) {
        return false;
    }
    return false;
}

bool am4_access_control_approve_new_current_user(char * user) {
    // Implement logic
    return true;
}

int am4_access_control_process_timeout(void) {
    // Implement logic
    return -1;
}

int am4_access_control_process_cancel(void) {
    // Implement logic
    return -1;
}