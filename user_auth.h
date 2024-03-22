#ifndef USER_AUTH_H
#define USER_AUTH_H

#include <stdbool.h>

// Api for user authentication and user management

// Function declaration for user authentication
bool am4_access_control_prompt_needed(int argc, char ** argv);
const char * am4_access_control_get_current_user(void);

bool am4_access_control_verify_password(const char * username, const char * password);

bool am4_access_control_approve_new_current_user(const char * username);

int am4_access_control_process_timeout(void);
int am4_access_control_process_cancel(void);

// User management

bool am4_access_control_user_have_admin_rights(const char * username);
/**
 * \brief Get the path to the database file.
 *
 * The user database is stored in a Yaml file, which the user mangement app can write. To see an example
 * of the file format, ask to see the file tests/systemconfig.yaml.
 *
 * \return The string to the database file (for user management).
 */
char * am4_access_control_get_database_file(void);
// Will return empty string "" if password complexity is not met

char * am4_access_control_compute_passwordhash(const char * password);
/**
 * \brief Store the user database file to neighboring systems.
 *
 * \important If some AM4 machines in the system is unreachable the distribution will fail. But the
 * return value will still be true (as the distribution was attempted).
 * \return True if the new file is semantically correct and distribution has started, otherwise false.
 */
bool am4_access_control_store_database_file(const char * tmpfilename);
/**
 * \brief Store the user database file to neighboring systems.
 *
 * \important If some AM4 machines in the system is unreachable the distribution will fail. But the
 * return value will still be true (as the distribution was attempted).
 * \return True if the new file is semantically correct and distribution has started, otherwise false.
 */
const char *  am4_access_control_distribute_database_file();

/**
 * \brief Get the system hostname (used for access management).
 *
 * \return Output string from system host command.
 */
const char * am4_access_control_get_hostname(void);

// check if password is complex enough
bool isPasswordComplexEnough(const char *password);


#endif // USER_AUTH_H