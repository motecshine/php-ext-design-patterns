#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_design_patterns.h"
#include "facade/os_interface.h"

static zend_function_entry bios_interface_methods[] = {
    PHP_ABSTRACT_ME(os_interface, halt, NULL)
    PHP_ABSTRACT_ME(os_interface, getName, NULL)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(os_interface)
{
    zend_class_entry os_interface_container_ce;
    INIT_CLASS_ENTRY(os_interface_container_ce TSRMLS_CC, "PHPDesign\\Facade\\OsInterface", os_interface_methods);
    zend_register_internal_interface(&os_interface_container_ce TSRMLS_CC);
    return SUCCESS;
}
