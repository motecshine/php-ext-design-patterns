#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_design_patterns.h"
#include "bridge/formatter_interface.h"

ZEND_BEGIN_ARG_INFO(formatter_interface_arg_info, 0)
    ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

static zend_function_entry formatter_interface_methods[] = {
    PHP_ABSTRACT_ME(formatter_interface, format, formatter_interface_arg_info)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(formatter_interface)
{
    zend_class_entry formatter_interface_container_ce;
    INIT_CLASS_ENTRY(formatter_interface_container_ce, "PHPDesign\\FormatterInterface", formatter_interface_methods);
    zend_register_internal_interface(&formatter_interface_container_ce);
    return SUCCESS;
}
