#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
/* include global headers*/
#include "php_design_patterns.h"
#include "adapter/book_interface.h"
#include "adapter/ebook_adapter.h"

ZEND_BEGIN_ARG_INFO(ebook_adapter_arg_info, 0)
    ZEND_ARG_INFO(0, ebook_object)
ZEND_END_ARG_INFO()
