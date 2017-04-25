#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
/* include global headers*/
#include "php_design_patterns.h"
#include "adapter/service.h"
#include "adapter/hello_world_service.h"

PHP_METHOD(hello_world_service, get)
{

}

zend_function_entry hello_world_service_methods[] = {
    PHP_METHOD(hello_world_service, get, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(hello_world_service)
{
    zend_class_entry hello_world_service_container_ce;
    zend_string *service_name, *service_name_tolower;
    service_name = strpprintf(0, "PHPDesign\\Service");
    service_name_tolower = zend_string_tolower(service_name);
    INIT_CLASS_ENTRY(hello_world_service_container_ce, "PHPDesign\\HelloWorldService");
    hello_world_service_ce = zend_register_internal_class(&hello_world_service_container_ce TSRMLS_CC);
    if ((service_ce = zend_hash_find_ptr(CG(class_table), service_name_tolower)) == NULL) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Can not extends PHPDesign\\Service class");
        return FAILURE;
    }
    zend_class_implements(hello_world_service_ce TSRMLS_CC, 1, service_ce);
    zend_string_release(service_name);
    zend_string_release(service_name_tolower);
    return SUCCESS;
}
