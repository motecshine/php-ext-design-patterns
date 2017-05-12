#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_design_patterns.h"
#include "adapter/ebook_interface.h"
#include "adapter/kindle.h"

static zend_class_entry *kindle_ce;

PHP_METHOD(kindle, pressNext)
{
    zend_long pageNum;
    kindle_ce = Z_OBJCE_P(getThis());
    pageNum = ++Z_LVAL_P(zend_read_property(kindle_ce, getThis(), ZEND_STRL("pageNum"), 0, 0 TSRMLS_CC));
    zend_update_property_long(kindle_ce, getThis(), ZEND_STRL("pageNum"), pageNum TSRMLS_CC);
}

PHP_METHOD(kindle, unlock)
{

}

PHP_METHOD(kindle, getPage)
{
    zend_long pageNum, pageNumTotal;
    zval retval;
    array_init(&retval);
    pageNum = Z_LVAL_P(zend_read_property(kindle_ce, getThis(), ZEND_STRL("pageNum"), 0, 0 TSRMLS_CC));
    pageNumTotal = Z_LVAL_P(zend_read_property(kindle_ce, getThis(), ZEND_STRL("pageNumTotal"), 0, 0 TSRMLS_CC));
    add_index_long(&retval, 0, pageNum);
    add_next_index_long(&retval, pageNumTotal);
    RETURN_ZVAL(&retval, 0, 1);
}

static zend_function_entry kindle_methods[] = {
    PHP_ME(kindle, pressNext,   NULL,  ZEND_ACC_PUBLIC)
    PHP_ME(kindle, unlock,      NULL,  ZEND_ACC_PUBLIC)
    PHP_ME(kindle, getPage,     NULL,  ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(kindle)
{
    zend_string *ebook_interface_name, *ebook_interface_name_tolower;
    zend_class_entry kindle_container_ce;

    ebook_interface_name = strpprintf(0, "PHPDesign\\EBookInterface");
    ebook_interface_name_tolower = zend_string_tolower(ebook_interface_name);
    INIT_CLASS_ENTRY(kindle_container_ce, "PHPDesign\\Kindle", kindle_methods);
    kindle_ce = zend_register_internal_class(&kindle_container_ce TSRMLS_CC);

    if ((ebook_interface_ce = zend_hash_find_ptr(CG(class_table), ebook_interface_name_tolower)) == NULL) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Can note implement ebook interface");
        return FAILURE;
    }

    /* declare book class member */
    zend_declare_property_long(kindle_ce, ZEND_STRL("pageNum"), 0, ZEND_ACC_PRIVATE);
    zend_declare_property_long(kindle_ce, ZEND_STRL("pageNumTotal"), 100, ZEND_ACC_PRIVATE);
    zend_class_implements(kindle_ce, 1, ebook_interface_ce);
    zend_string_release(ebook_interface_name);
    zend_string_release(ebook_interface_name_tolower);
    return SUCCESS;
}

