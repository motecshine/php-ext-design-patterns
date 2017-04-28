#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

ZEND_BEGIN_ARG_INFO(bios_interface_arg_info, 0)
    ZEND_ARG_INFO(0, os)
ZEND_END_ARG_INFO()

/* include global headers*/
#include "php_design_patterns.h"
#include "facade/bios_interface.h"

static zend_function_entry bios_interface_methods[] = {
    PHP_ABSTRACT_ME(bios_interface, execute, NULL)
    PHP_ABSTRACT_ME(bios_interface, waitForkeyPress, NULL)
    PHP_ABSTRACT_ME(bios_interface, launch, bios_interface_arg_info)
    PHP_ABSTRACT_ME(bios_interface, powerDown, NULL)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(bios_interface)
{
    zend_class_entry bios_interface_container_ce;
    INIT_CLASS_ENTRY(bios_interface_container_ce TSRMLS_CC, "PHPDesign\\Facade\\BiosInterface", bios_interface_methods);
    zend_register_internal_interface(&bios_interface_container_ce TSRMLS_CC);
    return SUCCESS;
}
