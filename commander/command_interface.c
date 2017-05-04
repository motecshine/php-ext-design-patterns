#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
/* include global headers*/
#include "php_design_patterns.h"
#include "commander/command_interface.h"

zend_function_entry command_interface_methods[] = {
    PHP_ABSTRACT_ME(command_interface, execute, NULL)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(command_interface)
{
    zend_class_entry command_interface_container_ce;
    INIT_CLASS_ENTRY(command_interface_container_ce, "PHPDesign\\Commander\\CommandInterface", command_interface_methods);
    zend_register_internal_interface(&command_interface_container_ce);
    return SUCCESS;
}
