#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_design_patterns.h"
#include "facade/linux_os.h"
#include "facade/os_interface.h"

PHP_METHOD(linux_os, halt)
{
    php_printf("linux system halting....");
}

PHP_METHOD(linux_os, getName)
{
    zend_string *linux_name;
    linux_name = strpprintf(0, "Linux");
    RETURN_STR(linux_name);
}

static zend_function_entry linux_os_methods[] = {
    PHP_ME(linux_os, halt, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(linux_os, getName, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(linux_os)
{
    zend_class_entry linux_os_container_ce;
    zend_sting *os_interface_name, *os_interface_tolower;

    os_interface_name = strpprintf(0, "PHPDesign\\Facade\\OsInterface");
    os_interface_tolower = zend_string_tolower(os_interface_name);

    if ((os_interface_ce = zend_hash_find_ptr(CG(class_table), os_interface_tolower)) == NULL) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Can not implement PHPDesign\\Facade\\OsInterface");
        return FAILURE;
    }

    /* initial class */
    INIT_CLASS_ENTRY(linux_os_container_ce, "PHPDesign\\Facade\\Linux", linux_os_methods);
    linux_os_ce = zend_register_class_internal(&linux_os_container_ce TSRMLS_CC);

    /* implement os_interface */
    zend_class_implements(linux_os_ce, 1, os_interface_ce);
    zend_string_release(os_interface_name);
    zend_string_release(os_interface_tolower);
    return SUCCESS;
}
