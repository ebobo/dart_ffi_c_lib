#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

// user management
bool  am4_access_control_user_have_admin_rights(char * user) {
    // Implement logic
    if (strcmp(user, "petter") == 0) {
        return true;
    } else if (strcmp(user, "espen") == 0) {
        return false;
    }
    return false;
}

char * am4_access_control_get_database_file(void) {
    FILE *file;
    char *buffer;
    long fileLength;

    file = fopen("/Users/qixu/projects/flutter/flutter_ffi/c_lib/userconfig.yaml", "rb"); // Open the file in binary mode
    if (file == NULL) {
        return NULL; // File not found or unable to open
    }

    // Seek to the end of the file to determine its size
    fseek(file, 0, SEEK_END);
    fileLength = ftell(file);
    rewind(file);

    // Allocate memory for the entire content
    buffer = (char *)malloc(fileLength + 1);
    if (buffer == NULL) {
        fclose(file);
        return NULL; // Memory allocation failed
    }

    // Read the file into the buffer
    fread(buffer, 1, fileLength, file);
    buffer[fileLength] = '\0'; // Null-terminate the string

    fclose(file);
    return buffer;
}

// Will return empty string "" if password complexity is not met
char * am4_access_control_compute_passwordhash(char * username, char * password) {
    // Example implementation: concatenate username and password
    if (username == NULL || password == NULL) {
        return NULL;
    }

    size_t hashLength = strlen(username) + strlen(password) + 1;
    char *hash = malloc(hashLength);

    if (hash != NULL) {
        strcpy(hash, username);
        strcat(hash, password); // In a real scenario, use a proper hashing function
    }

    return hash;
}

bool am4_access_control_verify_database_file(char * tmpfilename) {
      if (tmpfilename == NULL) {
        return false;
    }

    FILE *file = fopen(tmpfilename, "r");
    if (file == NULL) {
        return false; // File does not exist or cannot be opened
    }

    fclose(file);
    return true;
}
