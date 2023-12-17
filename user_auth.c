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
    return 0;
}

int am4_access_control_process_cancel(void) {
    // Implement logic
    return 0;
}


// Function to determine user level based on username and password
int get_user_level(const char* username, const char* password) {
    // Example hardcoded users
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        return 3; // Admin level
    } else if (strcmp(username, "operator") == 0 && strcmp(password, "op123") == 0) {
        return 2; // Operational user
    } else if (strcmp(username, "observer") == 0 && strcmp(password, "obs123") == 0) {
        return 1; // Observation user
    }

    return 0; // User not found or wrong credentials
}