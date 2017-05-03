#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
/* include global headers*/
#include "php_design_patterns.h"
#include "comnabder/command_interface.h"
#include "commander/undoable_command_interface.h"

zend_function_entry ud_command_interface_methods[] = {
    PHP_ABSTRACT_ME(ud_command_interface, execute, NULL, ZEND_ACC_PUBLIC);
    PHP_FE_END;
};

PHP_DESIGN_STARTUP_FUNCTION(ud_command_interface)
{
    zend_class_entry ud_command_interface_container_ce;
    zend_sting * command_interface_name, * command_interface_name_tolower;
    command_interface_name = strpprintf(0, "PHPDesign\\Commander\\CommandInterface");
    command_interface_name_tolower = zend_string_tolower(command_interface_name);
    INIT_CLASS_ENTRY(ud_command_interface_container_ce, "PHPDesign\\Command\\CommandInterface", ud_command_interface_methods);
    ud_command_interface_ce = zend_register_internal_interface(&command_interface_container_ce);
    /* get command_interface_ce */
    if ((command_interface_ce = zend_hash_find_ptr(CG(class_table), command_interface_name_tolower)) == NULL) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Can not Find PHPDesign\\Commander\\CommandInterface");
        return FAILURE;
    }
    /* extend command_interface */
    zend_register_internal_class_ex(ud_command_interface_ce, command_interface_ce);
    /* release zend string */
    zend_string_release(command_interface_name);
    zend_string_release(command_interface_name_tolower);
    return SUCCESS;
}
