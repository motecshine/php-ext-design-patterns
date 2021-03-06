#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_design_patterns.h"
#include "abstractFactory/abstract_factory.h"
#include "abstractFactory/mac_factory.h"
static zend_class_entry *mac_factory_ce;

PHP_METHOD(mac_factory, CreateButton)
{
    php_printf("MacFactory: CreateButton\n");
}

PHP_METHOD(mac_factory, CreateBorder)
{
    php_printf("MacFactory: CreateBorder\n");
}

static zend_function_entry mac_factory_methods[] = {
    PHP_ME(mac_factory, CreateBorder, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(mac_factory, CreateButton, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(mac_factory)
{
    zend_string *abstract_factory_interface_name, *abstract_factory_interface_name_tolower;
    zend_class_entry mac_factory_container_ce;
    abstract_factory_interface_name = strpprintf(0, "PHPDesign\\AbstractFactory");
    abstract_factory_interface_name_tolower = zend_string_tolower(abstract_factory_interface_name);
    INIT_CLASS_ENTRY(mac_factory_container_ce, "PHPDesign\\MacFactory", mac_factory_methods);
    mac_factory_ce = zend_register_internal_class(&mac_factory_container_ce TSRMLS_CC);
    if ((abstract_factory_ce = zend_hash_find_ptr(CG(class_table), abstract_factory_interface_name_tolower)) != NULL) {
        zend_class_implements(mac_factory_ce TSRMLS_CC, 1, abstract_factory_ce);
    }
    zend_string_release(abstract_factory_interface_name);
    zend_string_release(abstract_factory_interface_name_tolower);
    return SUCCESS;
}
