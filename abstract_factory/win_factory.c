#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_design_patterns.h"
#include "abstract_factory/abstract_factory.h"

zend_class_entry *win_factory_ce;

PHP_METHOD(win_factory, CreateButton)
{
     php_printf("WINFactory: CreateButton\n");
}

PHP_METHOD(win_factory, CreateBorder)
{
    php_printf("WINFactory: CreateBorder\n");
}

static zend_function_entry win_factory_methods[] = {
    PHP_ME(win_factory, CreateBorder, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(win_factory, CreateButton, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(win_factory)
{
    zend_string *abstract_factory_interface_name;
    zend_string *abstract_factory_interface_name_tolower;
    zend_class_entry win_factory_container_ce;
    abstract_factory_interface_name = strpprintf(0, "PHPDesign\\AbstractFactory");
    abstract_factory_interface_name_tolower = zend_string_tolower(abstract_factory_interface_name);
    INIT_CLASS_ENTRY(win_factory_container_ce, "PHPDesign\\WinFactory", win_factory_methods);
    win_factory_ce = zend_register_internal_class(&win_factory_container_ce TSRMLS_CC);
    zend_class_implements(win_factory_ce TSRMLS_CC, 1, zend_hash_find_ptr(EG(class_table), abstract_factory_interface_name_tolower));
    zend_string_release(abstract_factory_interface_name);
    zend_string_release(abstract_factory_interface_name_tolower);
    return SUCCESS;
}
