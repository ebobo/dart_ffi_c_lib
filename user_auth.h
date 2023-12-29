#ifndef USER_AUTH_H
#define USER_AUTH_H

#include <stdbool.h>

// Function declaration
bool am4_access_control_prompt_needed(int argc, char ** argv);
char * am4_access_control_get_current_user(void);
bool am4_access_control_verify_password(char * user, char * password);
bool am4_access_control_approve_new_current_user(char * user);
int am4_access_control_process_timeout(void);
int am4_access_control_process_cancel(void);

// User management
bool am4_access_control_user_have_admin_rights(char * user);
char * am4_access_control_get_database_file(void);
// Will return empty string "" if password complexity is not met
char * am4_access_control_compute_passwordhash(char * username, char * password);
bool am4_access_control_verify_database_file(char * tmpfilename);

#endif // USER_AUTH_H