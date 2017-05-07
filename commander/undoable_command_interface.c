#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
/* include global headers*/
#include "php_design_patterns.h"
#include "commander/undoable_command_interface.h"

zend_function_entry ud_command_interface_methods[] = {
    PHP_ABSTRACT_ME(ud_command_interface, undo, NULL)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(ud_command_interface)
{
    zend_class_entry ud_command_interface_container_ce;
    INIT_CLASS_ENTRY(ud_command_interface_container_ce, "PHPDesign\\Commander\\UndoableCommandInterface", ud_command_interface_methods);
    ud_command_interface_ce = zend_register_internal_interface(&ud_command_interface_container_ce);
    return SUCCESS;
}
