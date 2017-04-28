#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_design_patterns.h"
#include "facade/bios.h"
#include "facade/bios_interface.h"

ZEND_BEGIN_ARG_INFO(bios_interface_arg_info, 0)
    ZEND_ARG_INFO(0, os)
ZEND_END_ARG_INFO()

PHP_METHOD(bios, execute)
{
    php_printf("bios execute\n");
}

PHP_METHOD(bios, launch)
{
    php_printf("bios launch\n");
}

PHP_METHOD(bios, waitForkeyPress)
{
    php_printf("waitForkeyPress\n");
}

PHP_METHOD(bios, powerDown)
{
    php_printf("powerDown\n");
}

static zend_function_entry bios_methods[] = {
    PHP_ME(bios, execute, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(bios, launch, bios_interface_arg_info, ZEND_ACC_PUBLIC)
    PHP_ME(bios, waitForkeyPress, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(bios, powerDown, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(bios)
{
    zend_class_entry bios_container_ce;
    zend_string *bios_interface_name, *bios_interface_name_tolower;

    bios_interface_name = strpprintf(0, "PHPDesign\\Facade\\BiosInterface");
    bios_interface_name_tolower = zend_string_tolower(bios_interface_name);

    if ((bios_interface_ce = zend_hash_find_ptr(CG(class_table), bios_interface_name_tolower)) == NULL) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Can not implement PHPDesign\\Facade\\BiosInterface");
        return FAILURE;
    }

    /* initial class */
    INIT_CLASS_ENTRY(bios_container_ce, "PHPDesign\\Facade\\Bios", bios_methods);
    bios_ce = zend_register_internal_class(&bios_container_ce TSRMLS_CC);
    /* implement os_interface */
    zend_class_implements(bios_ce, 1, bios_interface_ce);
    zend_string_release(bios_interface_name);
    zend_string_release(bios_interface_name_tolower);
    return SUCCESS;
}
