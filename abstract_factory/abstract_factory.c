#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_design_patterns.h"
#include "abstract_factory/abstract_factory.h"

static zend_function_entry abstract_factory_methods[] = {
    PHP_ABSTRACT_ME(abstract_factory, CreateButton, NULL)
    PHP_ABSTRACT_ME(abstract_factory, CreateBorder, NULL)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(abstract_factory)
{
    zend_class_entry abstract_factory_container_ce;
    INIT_CLASS_ENTRY(abstract_factory_container_ce, "PHPDesign\\AbstractFactory", abstract_factory_methods);
    zend_register_internal_interface(&abstract_factory_container_ce);
    return SUCCESS;
}

